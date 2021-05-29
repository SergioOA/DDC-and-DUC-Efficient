/*
 * complexplot.h
 *
 *  Created on: Mar 22, 2013
 *      Author: odissey09
 */

#ifndef GRAPHSMODE_H_
#define GRAPHSMODE_H_

/*-------------------------------------------------------------------------*/

/* Complex plot structure definition */
SComplexplot complexplot_ctrl = {
	/*
	 * MODE: This parameter defines what have to be plot. The allowed modes are the following:
	 * 			REAL+IMAG	-> Plot real part alone in a plot
	 * 			IMAG	-> Plot imaginary part alone in a plot
	 * 			REAL_IMAG	-> Plot imaginary and real part together in the same plot
	 * 			MAG		-> Plot the magnitude of the incoming data
	 * 			ARG		-> Plot the argument of the incoming data
	 * 			ABS_ARG	-> Plot both, argument and magnitude
	 * 			CONSTELLATION	-> Plot the constellation
	 * 			VECTOR	-> Plot the vector diagram
	 * 			FFT_MAG -> Plot the FFT magnitude of the signal
	 * 			FFT_ARG -> Plot the FFT argument of the signal
	 *
	 * 			As default (0): (nothing)
	 */
	.mode = REAL+IMAG,

	/*
	 * TITLE: This is the pointer to the title of the plot.
	 * Be careful! Not exceed the number of 64 characters.
	 */
	.title = "MY_TITLE",

	/*
	 * DOMAIN: This parameter defines the plot domain, it can be:
	 * 		TIME	-> Set x axis as seconds
	 *		FREQUENCY	-> Set x axis as Hertz
	 *
	 *	As default (0): TIME
	 */
	.domain = TIME,

	/*
	 * XSCALE: This parameter defines the x-axis scale, it can be:
	 * 		MICRO	-> Set the x-axis sample step as microseconds or microhertzs
	 * 		MILI	-> Set the x-axis sample step as miliseconds or milihertzs
	 * 		UNITY	-> Set the x-axis sample step as seconds or hertz
	 * 		KILO	-> Set the x-axis sample step as kiloseconds or kilohertzs
	 * 		MEGA	-> Set the x-axis sample step as megaseconds or megahertzs
	 *
	 * 		As default (0): UNITY
	 */
	.xscale = UNITY, 

	/*
	 * SAMPLING FREQUENCY: This parameter sets the sampling frequency.
	 *
	 * As default (0): 1 Hz -> Then indicate samples.
	 */
	.sampling_frequency = 1,

	/*
	 * MAG_SCALE: This parameter defines which is the y axis scale type.
	 * 		LINEARSCALE	-> Plots the data directly, without any operation.
	 *	 	LOGSCALE 	-> Computes the 20*log10(y). It is only valid for Magnitude plots.
	 *
	 * As default (0): LINEARSCALE
	 */
	.mag_scale = LINEARSCALE,

	/*
	 * ARG_UNITS: This parameter defines the unit of the argument.
	 * 		RADIANS -> Plots using radians units
	 * 		DEGREES -> Plots using degrees
	 *
	 * As default (0): RADIANS
	 */
	.arg_unit = RADIANS,	// Radians or degrees

	/*
	 * MULTIPLE FRAME: This parameter defines whether the input data is formed by several frames.
	 * In case of being formed by several frames, set it as multiframe. Each frame
	 * is represented in a diferent z value (3D).
	 *		SINGLE -> Only one frame in the input data
	 *		MULTIPLE -> More than one frame in the input data (In this case, set the frame_length param)
	 *
	 * As default (0): SINGLE
	 */
	.multiple_frame = SINGLE,	// Define if the signal is composed of multiples parts (frames)
	.frame_length = 1,	// Define how long is every frame inside the input signal

	/*
	 * In case of FFT, it fixes the FFT order. The maximum is 16 (65536 samples).
	 */
	.FFTorder = 16,

	/*
	 * Scaling options
	 * AUTOSCALE 	-> The plot is scaled to the window automatically
	 * NOAUTOSCALE	-> Uses the parameters xmin, xmax, ymin, ymax
	 */
	.autoscale = AUTOSCALE,
	.xmax = 1.0,
	.xmin = -1.0,
	.ymax = 1.0,
	.ymin = -1.0,
	

	};



#endif /* GRAPHSMODE_H_ */
