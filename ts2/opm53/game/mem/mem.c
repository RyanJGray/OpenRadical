// STATUS: NOT STARTED

#include "mem.h"

struct localhead_s {
	u32 id[2];
	s32 length;
	u8 *check;
};

typedef localhead_s localhead_t;
u8 *mem_eternal_at = NULL;
u8 *mem_eternal_end = NULL;
int mem_eternal_free = 0;
u8 *mem_level_at = NULL;
u8 *mem_level_end = NULL;
int mem_level_free = 0;
u8 *mem_local_at = NULL;
int mem_allow_eter = 1;
u8 *memBuffer = NULL;
int memBufferSize = 0;

static void memMark(u8 *start, u8 *end) {
	u8 *pos;
}

static int memCheck(u8 *pos, int period) {
	localhead_t *h;
}

void memMake(u8 *buffer, int length) {}

void memRestart() {}

void memReset() {}

void memEnd() {}

void memTick() {}

u8* memAlloc(int length, int period) {
	u8 *retval;
}

u8* memAllocAlign64(int length, int period) {
	int alignbytes;
}

void memFree(void *localmem) {
	u8 *buffer;
	localhead_t *h;
}

void memLocalFree() {}

int memGetFreeLevel() {}

int memGetFreeEter() {}

void memPrintFree() {}
