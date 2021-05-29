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

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#define FILTERLENGTH 2048
#define ELEMENT_COUNT(X) (sizeof(X) / sizeof((X)[0]))


void leer_coeficientes_salteados(float coeffs[], int start, int jumps, int size, char *filter_path);
void separar_ramas(_Complex float *input, int inlength, float branchI[], float branchQ[]);
int convolve_I(float ccinput[], int datalength, float filtercoeff[], int filterlength, int interpolation, int delmation, float ccoutput[]);
int convolve_Q(float ccinput[], int datalength, float filtercoeff[], int filterlength, int interpolation, int delmation, float ccoutput[]);
void desfasar_muestras_impares(float branchI[], float branchQ[], int inlength);
int juntar_ramas(float branchI[], float branchQ[], int inlength, _Complex float *out);
int bypass_data(_Complex float *input, int lengths, _Complex float *output);
int filtrar_paso_alto(_Complex float *ccinput, int datalength, float filtercoeff[], int filterlength, _Complex float *ccoutput);

#endif
