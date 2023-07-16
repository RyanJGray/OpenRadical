IOP_BIN = STREAM.IRX 

IOP_OBJS = entry.o command.o

INCOPT = -I/usr/local/sce/common/include/ -I/usr/local/sce/iop/include

CFLAGS = $(INCOPT) -I. -G0 -Wall -O2
ASFLAGS = $(INCOPT) -G0

COMPILE.s = $(CC) -xassembler-with-cpp $(ASFLAGS) $(CPPFLAGS) $(TARGET_MACH) -c



all: $(IOP_BIN)

clean:
	rm -f -r $(IOP_OBJS) $(IOP_BIN)

$(IOP_BIN): $(OBJS)
