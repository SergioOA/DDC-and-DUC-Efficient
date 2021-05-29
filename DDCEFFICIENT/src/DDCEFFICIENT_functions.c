/* 
 * Copyright (c) 2012
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

#include <unistd.h>
#include <string.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include "DDCEFFICIENT_functions.h"


int bypass_data(_Complex float *input, int inlength, _Complex float *output)
{
	for (int i = 0; i < inlength; i++) {
		__real__ output[i] = __real__ input[i];
		__imag__ output[i] = __imag__ input[i];
	}

	return inlength;
}


void separar_ramas(_Complex float *input, int inlength, float branchI[], float branchQ[])
{
	int desfase = 1;

	for (int i = 0; i < inlength; i++) {

		// Si es una muestra PAR la metemos en la rama I    0,2,4...
		if(i % 2 == 0) {

			branchI[i / 2] = __real__ input[i] * desfase;

		}

		// Si es una muestra PAR la metemos en la rama I    1,3,5...
		else {

			branchQ[(i - 1) / 2] = __real__ input[i] * desfase;
			desfase = desfase * -1;

		}

	}

}


void juntar_ramas(const float branchI[], const float branchQ[], int inlength, _Complex float *out)
{
	for (int i = 0; i < inlength; i++) {
		__real__ out[i] = branchI[i];
		__imag__ out[i] = branchQ[i];
	}
}


void leer_coeficientes_salteados(float coeffs[], int start, int jumps, int size, char *filter_path)
{
	FILE* filePointer;
	int i = 0;
	int coeffsCount = 0;
	int nextIndex = start;
	int bufferLength = 2048;
	char buffer[bufferLength];
	filePointer = fopen(filter_path, "r");
	while(fgets(buffer, bufferLength, filePointer) != NULL) 
	{
		if(i == nextIndex)
		{
			char *ptr;
			double d = strtod(buffer, &ptr);
			coeffs[coeffsCount] = d;
			coeffsCount++;
			nextIndex = nextIndex + jumps;

			if(coeffsCount == size)
				break;
		}
		i++;
	}
	fclose(filePointer);
}


int convolve_I(float ccinput[], int datalength, float filtercoeff[], int filterlength, int interpolation, int delmation, float ccoutput[]){
	int i, j, k = 0;
	static float aux[1024] = {0};
	static int n = 0, m = 0;

	for (i = 0; i < datalength * interpolation; i++) 
	{
		if(n==0){
			for (j = filterlength - 2; j >= 0; j--)
				aux[j+1]=aux[j];
			aux[0]=ccinput[i/interpolation];
		}
		
		if(m==0)
		{
			ccoutput[k] = 0.0;
			for (j = 0; j < filterlength / interpolation; j++)
				ccoutput[k] += aux[j] * filtercoeff[j*interpolation+n];
			k++;
		}

		n++;
		m++;

		if(n == interpolation) n = 0;
		if(m == delmation) m = 0;
	}

	return datalength * interpolation / delmation;
}


int convolve_Q(float ccinput[], int datalength, float filtercoeff[], int filterlength, int interpolation, int delmation, float ccoutput[]){
	int i, j, k = 0;
	static float aux[1024] = {0};
	static int n = 0, m = 0;

	for (i = 0; i < datalength * interpolation; i++) 
	{
		if(n==0){
			for (j = filterlength - 2; j >= 0; j--)
				aux[j+1]=aux[j];
			aux[0]=ccinput[i/interpolation];
		}
		
		if(m==0)
		{
			ccoutput[k] = 0.0;
			for (j = 0; j < filterlength / interpolation; j++)
				ccoutput[k] += aux[j] * filtercoeff[j*interpolation+n];
			k++;
		}

		n++;
		m++;

		if(n == interpolation) n = 0;
		if(m == delmation) m = 0;
	}

	return datalength * interpolation / delmation;
}