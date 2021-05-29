#include <stdio.h>

FILE *rtdal_datafile_open(char * name, char *mode);
void rtdal_datafile_close(FILE *f);
int rtdal_datafile_write_bin(FILE *f, void *buf, int size);
void rtdal_datafile_write_real(FILE *f, float* buf, int size);
void rtdal_datafile_write_complex(FILE *f, _Complex float* buf, int size);
void rtdal_datafile_write_complex_short(FILE *f, _Complex short* buf, int size);

int rtdal_datafile_read_bin(FILE *f, void *buf, int size);
int rtdal_datafile_read_complex(FILE *f, _Complex float* buf, int size);
int rtdal_datafile_read_complex_short(FILE *f, _Complex short* buf, int size);
int rtdal_datafile_read_real(FILE *f, float* buf, int size);
