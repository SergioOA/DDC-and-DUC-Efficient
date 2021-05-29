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

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <complex.h>
#include <math.h>

#include "rtdal_datafile.h"
//#include "rtdal.h"

/**
 * Given a pathname for a MAT-file, rtdal_datafile_open() returns a datafile_t type,
 * a nonnegative integer for use in rtdal_datafile_write(), rtdal_datafile_read() and
 * rtdal_datafile_close().
 *
 *
 * @param name Name of the file
 * @return nonnegative integer on success, -1 on error.
 */
 FILE *rtdal_datafile_open(char * name, char *mode) {
	return fopen(name, mode);
}

/**
 * Closes a previously opened file using rtdal_datafile_open()
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @return zero on success, -1 on error.
 */
void rtdal_datafile_close(FILE *f) {
	fclose(f);
}

int rtdal_datafile_write_bin(FILE *f, void *buf, int size) {
	return fwrite(buf,1,size,f);
}

int rtdal_datafile_read_bin(FILE *f, void *buf, int size) {
	return fread(buf,1,size,f);
}

/**
 * Writes up to size real values from the buffer pointed by buf to the
 * file referred to by the file descriptor fd.
 *
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @param buf Pointer to the memory to write to the file
 * @param size Number of bytes to write
 * @return On success, the number of bytes written is returned (zero indicates
 * nothing was written). On error, -1 is returned
 */
void rtdal_datafile_write_real(FILE *f, float* buf, int size) {
	int i;

	for (i=0;i<size;i++) {
		fprintf(f,"%g\n",buf[i]);
	}
}



/**
 * Writes up to size complex values from the buffer pointed by buf to the
 * file referred to by the file descriptor fd.
 *
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @param buf Pointer to the memory to write to the file
 * @param size Number of bytes to write
 * @return On success, the number of bytes written is returned (zero indicates
 * nothing was written). On error, -1 is returned
 */
void rtdal_datafile_write_complex(FILE *f, _Complex float* buf, int size) {
	int i;

	for (i=0;i<size;i++) {
		if (__imag__ buf[i] >= 0)
			fprintf(f,"%g+%gi\n",__real__ buf[i],__imag__ buf[i]);
		else
			fprintf(f,"%g-%gi\n",__real__ buf[i],fabsf(__imag__ buf[i]));
	}
}


/**
 * Writes up to size complex short int values from the buffer pointed by buf to the
 * file referred to by the file descriptor fd.
 *
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @param buf Pointer to the memory to write to the file
 * @param size Number of bytes to write
 * @return On success, the number of bytes written is returned (zero indicates
 * nothing was written). On error, -1 is returned
 */
void rtdal_datafile_write_complex_short(FILE *f, _Complex short* buf, int size) {
	int i;

	for (i=0;i<size;i++) {
		if (__imag__ buf[i] >= 0)
			fprintf(f,"%d+%di\n",__real__ buf[i],__imag__ buf[i]);
		else
			fprintf(f,"%d-%di\n",__real__ buf[i],fabsf(__imag__ buf[i]));
	}
}



/**
 * Attemps to read up to size complex values from the the file descriptor f into
 * the buffer starting at buf.
 *
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @param buf Pointer to the memory to read to the file
 * @param size Number of bytes to read
 * @return On success, the number of bytes readed is returned (zero indicates
 * nothing was readed). On error, -1 is returned
 */
int rtdal_datafile_read_complex(FILE *f, _Complex float* buf, int size) {
	int i;

	for (i=0;i<size;i++) {
		if (EOF == fscanf(f,"%g%gi\n",&(__real__ buf[i]),&(__imag__ buf[i])))
			break;
	}
	return i;
}


/**
 * Attemps to read up to size complex short int values from the the file descriptor f into
 * the buffer starting at buf.
 *
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @param buf Pointer to the memory to write to the file
 * @param size Number of bytes to write
 * @return On success, the number of bytes written is returned (zero indicates
 * nothing was written). On error, -1 is returned
 */
int rtdal_datafile_read_complex_short(FILE *f, _Complex short* buf, int size) {
	int i;

	for (i=0;i<size;i++) {
		if (EOF == fscanf(f,"%d%di\n",&(__real__ buf[i]),&(__imag__ buf[i])))
			break;
	}
	return i;
}


/**
 * Attemps to read up to size real values from the the file descriptor f into
 * the buffer starting at buf.
 *
 * @param fd File descriptor returned by rtdal_datafile_open()
 * @param buf Pointer to the memory to write to the file
 * @param size Number of bytes to write
 * @return On success, the number of bytes written is returned (zero indicates
 * nothing was written). On error, -1 is returned
 */
int rtdal_datafile_read_real(FILE *f, float* buf, int size) {
	int i;

	for (i=0;i<size;i++) {
		if (EOF == fscanf(f,"%g\n",&buf[i]))
			break;
	}
	return i;
}

