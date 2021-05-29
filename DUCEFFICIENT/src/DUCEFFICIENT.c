/* 
 * Copyright (c) 2012.
 * This file is part of ALOE (http://flexnets.upc.edu/)
 * 
 * ALOE++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ALOE++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with ALOE++.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <complex.h>
#include <fftw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <phal_sw_api.h>
#include "skeleton.h"
#include "params.h"

#include "DUCEFFICIENT_interfaces.h"
#include "DUCEFFICIENT_functions.h"
#include "DUCEFFICIENT.h"

// Variables de ALOE
char mname[STR_LEN]="DDCEFFICIENT";
int run_times=1;
int block_length=32768;
char plot_modeIN[STR_LEN]="DEFAULT";
char plot_modeOUT[STR_LEN]="DEFAULT";
float samplingfreqHz=48000.0;

// Variables de la config
char polyphaseFilterPath[255] = "";
int polyphaseFilterSize = 0;
int polyphaseFilterPartitions = 0;
int polyphaseFilterPartitionSize = 0;
int polyphaseFilterFirstCoeffI = 0;
int polyphaseFilterFirstCoeffQ = 0;
int interpolationFactor = 0;
int delmationFactor = 0;
char highPassFilterPath[255] = "";
int highPassFilterSize = 0;

// Variables del module
float branchI_filter[64];
float branchQ_filter[64];
float HPF_filter[1024];

/*
 * Function documentation
 *
 * @returns 0 on success, -1 on error
 */
int initialize() {
	
	/* Checks de control */
	if (block_length < get_input_max_samples()) {
		moderror_msg("ERROR: Block length=%d > INPUT_MAX_DATA=%d\n", block_length, INPUT_MAX_DATA);
		return -1;
	}


	param_get_string("polyphaseFilterPath", &polyphaseFilterPath[0]);
	param_get_int("polyphaseFilterSize", &polyphaseFilterSize);
	param_get_int("polyphaseFilterPartitions", &polyphaseFilterPartitions);
	param_get_int("polyphaseFilterFirstCoeffI", &polyphaseFilterFirstCoeffI);
	param_get_int("polyphaseFilterFirstCoeffQ", &polyphaseFilterFirstCoeffQ);
	param_get_int("interpolationFactor", &interpolationFactor);
	param_get_int("delmationFactor", &delmationFactor);
	param_get_string("highPassFilterPath", &highPassFilterPath[0]);
	param_get_string("highPassFilterSize", &highPassFilterSize);


	polyphaseFilterPartitionSize = polyphaseFilterSize / polyphaseFilterPartitions;
	leer_coeficientes_salteados(branchI_filter, polyphaseFilterFirstCoeffI, polyphaseFilterPartitions, polyphaseFilterPartitionSize, polyphaseFilterPath);
	leer_coeficientes_salteados(branchQ_filter, polyphaseFilterFirstCoeffQ, polyphaseFilterPartitions, polyphaseFilterPartitionSize, polyphaseFilterPath);
	leer_coeficientes_salteados(HPF_filter, 0, 1, highPassFilterSize, highPassFilterPath);


	return 0;

}


/**
 * @brief Function documentation
 */
int work(input_t *inp, output_t *out) {


	// Cantidad de datos recibidos
	int rcv_samples = get_input_samples(0);
	if (rcv_samples == 0) {
		return 0;
	}
	

	// Nos aseguramos de tener suficiente espacio
	if(rcv_samples > block_length) {
		printf("[Error] %s: El block_length es menor al necesario (%d)\n", mname, rcv_samples);
		return(0);
	}


	// Interfaces
	input_t *input0 = in(inp, 0);
	output_t *output0 = out(out, 0);


	// Separamos la información en 2 ramas
	float branchI[rcv_samples / 2];
	float branchQ[rcv_samples / 2];
	separar_ramas(input0, rcv_samples, branchI, branchQ);


	// Convolucionamos usando los filtros
	float branchI_filtered[ELEMENT_COUNT(branchI) * 9];
	float branchQ_filtered[ELEMENT_COUNT(branchQ) * 9];
	int branchI_filtered_samples = convolve_I(branchI, ELEMENT_COUNT(branchI), branchI_filter, polyphaseFilterPartitionSize, interpolationFactor, delmationFactor, branchI_filtered);
	int branchQ_filtered_samples = convolve_Q(branchQ, ELEMENT_COUNT(branchQ), branchQ_filter, polyphaseFilterPartitionSize, interpolationFactor, delmationFactor, branchQ_filtered);


	// Aplicamos los desfases
	desfasar_muestras_impares(branchI_filtered, branchQ_filtered, branchI_filtered_samples);


	// Juntamos las 2 ramas
	_Complex float joined_branches[branchI_filtered_samples * 2];
	int joined_samples = juntar_ramas(branchI_filtered, branchQ_filtered, branchI_filtered_samples, joined_branches);


	// Filtramos paso alt
	int final_samples = filtrar_paso_alto(joined_branches, joined_samples, HPF_filter, highPassFilterSize, output0);


	// Enviamos las muestras
	set_output_samples(0, final_samples);
	return final_samples;

}

/** 
 * @brief Deallocates resources created during initialize().
 * @return 0 on success -1 on error
 */
int stop() {
	return 0;
}