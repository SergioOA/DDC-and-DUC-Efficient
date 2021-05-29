/* 
 * Copyright (c) 2012
 * This file is part of ALOE++ (http://flexnets.upc.edu/)
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


#ifndef _MOD_PARAMS_H
#define _MOD_PARAMS_H

	extern char polyphaseFilterPath[];
	extern int polyphaseFilterSize;
	extern int polyphaseFilterPartitions;
	extern int polyphaseFilterFirstCoeffI;
	extern int polyphaseFilterFirstCoeffQ;
	extern int interpolationFactor;
	extern int delmationFactor;
	extern char highPassFilterPath[];
	extern int highPassFilterSize;


	/* Número máximo de parámetros que va a buscar en el archivo params */
	#define NOF_PARAMS	10

	/* Lista de parámetros que tiene que buscar en el archivo params */
	param_t parameters[] = {
		{"polyphaseFilterPath", STRING, 1},
		{"polyphaseFilterSize", INT, 1},
		{"polyphaseFilterPartitions", INT, 1},
		{"polyphaseFilterFirstCoeffI", INT, 1},
		{"polyphaseFilterFirstCoeffQ", INT, 1},
		{"interpolationFactor", INT, 1},
		{"delmationFactor", INT, 1},
		{"highPassFilterPath", STRING, 1},
		{"highPassFilterSize", INT, 1},
		{ NULL, 0, 0 }
	};

	/* Esto es así porque sí */
	const int nof_parameters = NOF_PARAMS;


#endif