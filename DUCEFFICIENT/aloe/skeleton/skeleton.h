/* 
 * Copyright (c) 2012, Ismael Gomez-Miguelez <ismael.gomez@tsc.upc.edu>.
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

#ifndef SKELETON_H
#define SKELETON_H

#include <assert.h>
#include <stdio.h>

#ifdef _COMPILE_MEX_INCLUDE
#include "mex.h"
#endif


int get_input_samples(int idx);
void set_output_samples(int idx, int len);
int get_input_max_samples();
int get_output_max_samples();

#define in(ptr,idx) &ptr[idx*INPUT_MAX_DATA]
#define out(ptr,idx) &ptr[idx*OUTPUT_MAX_DATA]


/* Info and error messages print */
#define INFOSTR "[info at "
#define ERRSTR "[error at "
#define WHERESTR  "file %s, line %d]: "
#define WHEREARG  __FILE__, __LINE__
#ifdef _COMPILE_MEX
#define DEBUGPRINT2(out,...)       mexPrintf(__VA_ARGS__)
#elif _COMPILE_ALOE
#define DEBUGPRINT2(out,...)       Log(__VA_ARGS__)
#else
#define DEBUGPRINT2(out,...)       fprintf(out, __VA_ARGS__)
#endif
#define aerror_msg(_fmt, ...)  DEBUGPRINT2(stderr,ERRSTR WHERESTR _fmt, WHEREARG, __VA_ARGS__)
#define aerror(a)  DEBUGPRINT2(stderr, ERRSTR WHERESTR a, WHEREARG)

#define ainfo(a) DEBUGPRINT2(stdout, INFOSTR WHERESTR a, WHEREARG)
#define ainfo_msg(_fmt, ...)  DEBUGPRINT2(stdout,INFOSTR WHERESTR _fmt, WHEREARG, __VA_ARGS__)

#define modinfo ainfo
#define modinfo_msg ainfo_msg
#define moderror aerror
#define moderror_msg aerror_msg


#endif

