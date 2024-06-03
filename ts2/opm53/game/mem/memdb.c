// STATUS: NOT STARTED

#include "memdb.h"

static int printfree = 0;
static int buflen = 0;
static int maxused = 0;
static u8 *memdbbuffer = NULL;
static int dballoc = 0;
static u8 *curbuf;
static u8 *lastbuf;
static u8 *curbufat;
static u8 dbuf[2][10240];

void memdbRestart(int state) {}

void memdbReset(int state) {}

void memdbTick() {
	u8 *tmp;
	int bufused;
}

u8* memdbAlloc(int length) {
	u8 *retval;
}

void memdbPrintFree() {}
