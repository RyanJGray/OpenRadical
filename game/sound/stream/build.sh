#!/bin/sh

/usr/local/sce/iop/gcc/bin/iop-gcc -g -I/usr/local/sce/iop/gcc/mipsel-scei-elfl/include -c entry.c command.c
#/usr/local/sce/iop/gcc/bin/iop-ld -dc -r -o stream.o entry.o command.o -l/usr/local/sce/iop/lib/libsd.ilb
#/usr/local/sce/iop/gcc/mipsel-scei-elfl/bin/iopfixup -o stream stream.o
/usr/local/sce/iop/gcc/bin/iop-gcc -g -o STREAM.IRX entry.o command.o -L/usr/local/sce/iop/lib -ilb=libsd.ilb
