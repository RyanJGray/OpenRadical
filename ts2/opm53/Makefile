SHELL       = /bin/sh

SDKROOT     = tools/sce
TOP         = tools/sce/ee
LIBDIR      = $(TOP)/lib
INCOPT      = -I$(SDKROOT)/common/include -I$(TOP)/include -Iinclude -Igame

OUTPUT      = SLUS_999.99
OBJS        = crt0.o \
              game/boss/boss.o \
			  game/util/assert.o

LCFILE      = $(LIBDIR)/app.cmd
LIBS        = $(LIBDIR)/libkernl.a \
              $(LIBDIR)/libgraph.a \
              $(LIBDIR)/libcddvd.a

PREFIX      = $(TOP)/gcc/bin/ee
AS          = $(PREFIX)-gcc
CC          = $(PREFIX)-gcc
LD          = $(PREFIX)-gcc
DVPASM      = $(PREFIX)-dvp-as
OBJDUMP     = $(PREFIX)-objdump
RUN         = dsedb -r run
RM          = /bin/rm -f

CFLAGS      = -O2 -Wall -Werror -Wa,-al -fno-common -fno-strict-aliasing
CXXFLAGS    = -O2 -Wall -Werror -Wa,-al -fno-exceptions -fno-common -fno-strict-aliasing
ASFLAGS     = -gstabs -mdebug -c -xassembler-with-cpp -Wa,-al
DVPASMFLAGS =
LDFLAGS     = -Wl,-Map,$(OUTPUT).map -mno-crt0 -L$(LIBDIR) -lsdr -lpad -lm 
TMPFLAGS    = -I../../../../common/include

.SUFFIXES: .c .s .cc .dsm

all: $(OUTPUT).elf

$(OUTPUT).elf: $(OBJS) $(LIBS)
	$(LD) -o $@ -T $(LCFILE) $(OBJS) $(LIBS) $(LDFLAGS)

crt0.o: $(LIBDIR)/crt0.s
	$(AS) $(ASFLAGS) $(TMPFLAGS) -o $@ $< > $*.lst

.s.o:
	$(AS) $(ASFLAGS) $(TMPFLAGS) $(INCOPT) -o $@ $< > $*.lst

.dsm.o:
	$(DVPASM) $(DVPASMFLAGS) $(INCOPT) -o $@ $< > $*.lst

.c.o:
	$(CC) $(CFLAGS) $(TMPFLAGS) $(INCOPT) -c $< -o $*.o > $*.lst

.cc.o:
	$(CC) $(CXXFLAGS) $(TMPFLAGS) $(INCOPT) -c $< -o $*.o > $*.lst

run: $(OUTPUT).elf
	dsreset 0 0; $(RUN) $(OUTPUT).elf

clean:
	$(RM) *.o *.map *.lst core *.dis *.elf
