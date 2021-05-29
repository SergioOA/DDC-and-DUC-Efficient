/*
 * complexplot.h
 *
 *  Created on: Mar 22, 2013
 *      Author: odissey09
 */

#ifndef PLOTMODE_H_
#define PLOTMODE_H_

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

//int plotcomplex(char *plotmode, complex_t* tmp_c, int datalen, gnuplot_ctrl *plot, char *itfname, SComplexplot* scomplexplot);
//int plotcomplex(char *plotmode, int datalen);
//int plotcomplex(char *plotmode, complex_t* tmp_c, int datalen, gnuplot_ctrl *plot,char *itfname);
//int plotcomplex(char *plotmode, complex_t* tmp_c, int datalen, gnuplot_ctrl *plot,char *itfname);//, SComplexplot* scomplexplot);
//int plotcomplex(char *plotmode, complex_t* tmp_c, int datalen, gnuplot_ctrl *plot,char *itfname, SComplexplot* scomplexplot);
int plotcomplex(char *plotmode, complex_t* tmp_c, int datalen, gnuplot_ctrl *plot,
		char *itfname, SComplexplot* scomplexplot, int samplingfsHz, int runtimes);
#endif /* COMPLEXPLOT_H_ */
