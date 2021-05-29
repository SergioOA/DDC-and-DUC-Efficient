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

#ifndef MODULENAME_H
#define MODULENAME_H
#ifndef ITF_TYPES_H
#include "DDCEFFICIENT_interfaces.h"
#endif

/* Constants and function prototyes directly used by the DSP modules being implemented */

#define PI		3.14159265359	/* pi approximation */
#define PIx2		6.28318530718

#define SIZE		1000000



#define INPUT_MAX_SAMPLES 	10*2048*64






/**** function prototypes ****/
int verify_control();

/* Module DSP */
int initialize();
int work(input_t *input, output_t *output);
int stop();

#endif
