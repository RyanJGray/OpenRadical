// STATUS: NOT STARTED

#include "screendump.h"

u8 *frame1 = NULL;
u8 *frame2 = NULL;
u8 *outfile = NULL;

sceGsStoreImage gs_simage = {
	/* .vifcode = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .giftag = */ {
		/* .NLOOP = */ BITFIELD,
		/* .EOP = */ BITFIELD,
		/* .pad16 = */ BITFIELD,
		/* .id = */ BITFIELD,
		/* .PRE = */ BITFIELD,
		/* .PRIM = */ BITFIELD,
		/* .FLG = */ BITFIELD,
		/* .NREG = */ BITFIELD,
		/* .REGS0 = */ BITFIELD,
		/* .REGS1 = */ BITFIELD,
		/* .REGS2 = */ BITFIELD,
		/* .REGS3 = */ BITFIELD,
		/* .REGS4 = */ BITFIELD,
		/* .REGS5 = */ BITFIELD,
		/* .REGS6 = */ BITFIELD,
		/* .REGS7 = */ BITFIELD,
		/* .REGS8 = */ BITFIELD,
		/* .REGS9 = */ BITFIELD,
		/* .REGS10 = */ BITFIELD,
		/* .REGS11 = */ BITFIELD,
		/* .REGS12 = */ BITFIELD,
		/* .REGS13 = */ BITFIELD,
		/* .REGS14 = */ BITFIELD,
		/* .REGS15 = */ BITFIELD
	},
	/* .bitbltbuf = */ {
		/* .SBP = */ BITFIELD,
		/* .pad14 = */ BITFIELD,
		/* .SBW = */ BITFIELD,
		/* .pad22 = */ BITFIELD,
		/* .SPSM = */ BITFIELD,
		/* .pad30 = */ BITFIELD,
		/* .DBP = */ BITFIELD,
		/* .pad46 = */ BITFIELD,
		/* .DBW = */ BITFIELD,
		/* .pad54 = */ BITFIELD,
		/* .DPSM = */ BITFIELD,
		/* .pad62 = */ BITFIELD
	},
	/* .bitbltbufaddr = */ 0,
	/* .trxpos = */ {
		/* .SSAX = */ BITFIELD,
		/* .pad11 = */ BITFIELD,
		/* .SSAY = */ BITFIELD,
		/* .pad27 = */ BITFIELD,
		/* .DSAX = */ BITFIELD,
		/* .pad43 = */ BITFIELD,
		/* .DSAY = */ BITFIELD,
		/* .DIR = */ BITFIELD,
		/* .pad61 = */ BITFIELD
	},
	/* .trxposaddr = */ 0,
	/* .trxreg = */ {
		/* .RRW = */ BITFIELD,
		/* .pad12 = */ BITFIELD,
		/* .RRH = */ BITFIELD,
		/* .pad44 = */ BITFIELD
	},
	/* .trxregaddr = */ 0,
	/* .finish = */ {
		/* .pad00 = */ 0
	},
	/* .finishaddr = */ 0,
	/* .trxdir = */ {
		/* .XDR = */ BITFIELD,
		/* .pad02 = */ BITFIELD
	},
	/* .trxdiraddr = */ 0
};

void screenDumpGetFrame1() {}

void screenDumpGetFrame2() {}

void screenDumpSave() {}

void zbDump() {}
