#https://sites.google.com/site/michaelsafyan/software-engineering/how-to-write-a-makefile
SHELL = /bin/sh
# Change cpp and linker flags here
CPPFLAGS=-D_GNU_SOURCE -D_USE_GNU -O0 -g3 -Wall -Wno-format-extra-args -std=c99 -Winline -I../src -I../standalone -I../aloe/skeleton -I../aloe/extern -I../aloe/gnuplot -I../aloe/standalone -I../src -I../interfaces -I../../typetools/include/ -I../../../sw_api/include -fPIC
LDFLAGS=-lrt -lm -lfftw3 -L../../typetools/lnx_make/lib/ -L../../../hw_api/lnx/lib -L../../../sw_api/lnx_make/lib

#Put here only the modulename.c file 
MODSRC=../src/modulename.c 
#Add here more .c files required by the module DSP function
DSPSRC=../src/modulename_functions.c

#Matlab root path
MATLAB_ROOT=/path/to/matlab
MATLAB_INC=-D_COMPILE_MEX_INCLUDE

#Comment the next line if you have matlab to avoid mexPrintf warnings
MATLAB_INC=

# DO NOT NEED TO MODIFY BELOW HERE ############################################################################33

# Name of the module 
NAME=modulename

MATLAB_INCLUDE=$(MATLAB_ROOT)/extern/include
CC=gcc
LIBNAME=lib$(NAME).a
#Common modules files: skeleton version
COMSRC=../aloe/skeleton/params.c ../aloe/extern/rtdal_datafile.c
SASRC=../aloe/standalone/test_main.c ../standalone/test_generate.c ../aloe/gnuplot/gnuplot_i.c ../aloe/gnuplot/complexplot.c ../aloe/gnuplot/plot_mode.c

SAOBJ=$(SASRC:.c=.o)
COMOBJ=$(COMSRC:.c=.o)
DSPOBJ=$(DSPSRC:.c=.o)
MODOBJ_M=$(MODSRC:.c=.om)
MODOBJ=$(MODSRC:.c=.o)

.PHONY: all clean distclean

all: $(SOURCES) $(NAME) matlab

matlab: $(MODOBJ_M) $(COMOBJ) $(DSPOBJ)
	ar rcs $(LIBNAME) $(MODOBJ_M) $(COMOBJ) $(DSPOBJ)

$(MODOBJ_M):
	$(CC) $(CPPFLAGS) -I$(MATLAB_INCLUDE) $(MATLAB_INC) -D_COMPILE_MEX -c $(MODSRC) -o $(MODOBJ_M)

$(NAME): $(MODOBJ) $(SAOBJ) $(COMOBJ) $(DSPOBJ)		 			
	$(LINK.cc) $(MODOBJ) $(COMOBJ) $(SAOBJ) $(DSPOBJ) $(LDFLAGS) -o $@	

clean:
	@- $(RM) $(LIBNAME) $(NAME)
	@- $(RM) $(MODOBJ) $(DSPOBJ) $(COMOBJ) $(MODOBJ_M) $(SAOBJ)


