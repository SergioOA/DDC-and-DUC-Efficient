/*
 * complexplot.h
 *
 *  Created on: Mar 22, 2013
 *      Author: odissey09
 */

#ifndef COMPLEXPLOT_H_
#define COMPLEXPLOT_H_

/*-------------------------------------------------------------------------*/
/**
  @file		complexplot.h
  @author	Xavier Arteaga
  @date		April 2013
  @version	$Revision: 0.1 $
  @brief	C interface to gnuplot for complex graphics

  This file provides an interface to graph some useful graphics for
  communications applications. From a configuration structure it plots.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/
#include "gnuplot_i.h"

/*---------------------------------------------------------------------------
                                Defines
 ---------------------------------------------------------------------------*/

/* Printing complex modes */
#define REAL			(1<<0)
#define IMAG			(1<<1)
#define REAL_IMAG		(1<<2)	// Plots real and imaginary parts
#define MAG			(1<<3)
#define ARG			(1<<4)
#define ABS_ARG			(1<<5)	// Plots absolute and argument
#define CONSTELLATION		(1<<6)
#define VECTOR			(1<<7)
#define FFT_MAG			(1<<8)
#define FFT_ARG			(1<<9)

/* Datatypes */
#define MAGNITUDE	0
#define ARGUMENT	1

/* Define Domain */
#define TIME		0
#define FREQUENCY	1

/* Define x-scale */
#define MICRO	0.000001
#define MILI	0.001
#define UNITY	1.0
#define KILO	1000.0
#define MEGA	1000000.0

/* Define argument units (Only for ABS_ARG mode) */
#define PI 3.14159265359
#define RADIANS		0
#define DEGREES		1

/* Define scale (Only for ABS_ARG mode) */
#define LINEARSCALE		0
#define LOGSCALE		1

/* Define if multiple frames such as differents FFTs */
#define SINGLE		0
#define MULTIPLE	1

/* Define FFT parameters */
#define MAXFFTORDER	16

/* Define Maximum length for the plot title */
#define MAXTITLENAME 64

/* Define Scaling options */
#define AUTOSCALE 0
#define NOAUTOSCALE 1

/* Processing types */
typedef _Complex float	complex_t;	/* 64 bit complex number (two floats, NO doubles) */
typedef double proc_t;

/*
 * Structure definition
 */
typedef struct {
	/*
	 * This parameter defines what have to be plot. The allowed modes are the following:
	 * 	REAL	-> Plot real part alone in a plot
	 * 	IMAG	-> Plot imaginary part alone in a plot
	 *	REAL_IMAG	-> Plot imaginary and real part together in the same plot
	 * 	MAG		-> Plot the magnitude of the incoming data
	 * 	ARG		-> Plot the argument of the incoming data
	 * 	ABS_ARG	-> Plot both, argument and magnitude
	 * 	CONSTELLATION	-> Plot the constellation
	 * 	VECTOR	-> Plot the vector diagram
	 * 	FFT_MAG -> Plot the FFT magnitude of the signal
	 * 	FFT_ARG -> Plot the FFT argument of the signal
	 *
	 * 	As default (0): (nothing)
	 */
	unsigned int mode;

	/*
	 * This is the pointer to the title of the plot.
	 * Be careful! Not exceed the number of characters.
	 */
	char title [MAXTITLENAME];

	/*
	 * This parameter defines the plot domain, it can be:
	 * 		TIME	-> Set x axis as seconds
	 *	FREQUENCY	-> Set x axis as Hertz
	 *
	 *	As default (0): TIME
	 */
	int domain;

	/*
	 * This parameter defines the x-axis scale, it can be:
	 * 		MICRO	-> Set the x-axis sample step as microseconds or microhertzs
	 * 		MILI	-> Set the x-axis sample step as miliseconds or milihertzs
	 * 		UNITY	-> Set the x-axis sample step as seconds or hertz
	 * 		KILO	-> Set the x-axis sample step as kiloseconds or kilohertzs
	 * 		MEGA	-> Set the x-axis sample step as megaseconds or megahertzs
	 *
	 * 		As default (0): UNITY
	 */
	double xscale;

	/*
	 * This parameter sets the sampling frequency.
	 *
	 * As default (0): 0 Hz
	 */
	double sampling_frequency;

	/*
	 * This parameter defines which is the y axis scale type.
	 * 		LINEARSCALE	-> Plots the data directly, without any operation.
	 *	 	LOGSCALE 	-> Computes the 20*log10(y). It is only valid for Magnitude plots.
	 *
	 * As default (0): LINEARSCALE
	 */
	int mag_scale;

	/*
	 * This parameter defines the unit of the argument.
	 * 		RADIANS -> Plots using radians units
	 * 		DEGREES -> Plots using degrees
	 *
	 * As default (0): RADIANS
	 */
	int arg_unit;	// Radians or degrees

	/*
	 * This parameter defines whether the input data is formed by several frames.
	 * In case of being formed by several frames, set it as multiframe. Each frame
	 * is represented in a diferent z value (3D).
	 *		SINGLE -> Only one frame in the input data
	 *		MULTIPLE -> More than one frame in the input data (In this case, set the frame_length param)
	 *
	 * As default (0): SINGLE
	 */
	int multiple_frame;	// Define if the signal is composed of multiples parts (frames)
	int frame_length;	// Define how long is every frame inside the input signal

	/*
	 * In case of FFT, it fixes the FFT order. The maximum is 16 (65536 samples).
	 */
	int FFTorder;

	/*
	 * Scaling options
	 * AUTOSCALE 	-> The plot is scaled to the window automatically
	 * NOAUTOSCALE	-> Uses the parameters xmin, xmax, ymin, ymax
	 */
	int autoscale;
	double xmax;
	double xmin;
	double ymax;
	double ymin;
} SComplexplot;

/*
 * Complexplot subroutine, for printing complex data arrays
 */
void complexplot (complex_t* tmp_c, int datalen, gnuplot_ctrl *plot, char *itfname, SComplexplot* scomplexplot);
void realimag2timelinearsingleplots(SComplexplot* scomplexplot, float samplingfsHz);
//int plotcomplexp(char *plotmode, int datalen);
int plotcomplexp(char *plotmode, complex_t* tmp_c, int datalen, gnuplot_ctrl *plot, char *itfname, SComplexplot *scomplexplot);


#endif /* COMPLEXPLOT_H_ */
