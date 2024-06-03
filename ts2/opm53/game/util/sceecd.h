// STATUS: NOT STARTED

#ifndef GAME_UTIL_SCEECD_H
#define GAME_UTIL_SCEECD_H

typedef struct {
	u_char trycount;
	u_char spindlctrl;
	u_char datapattern;
	u_char pad;
} sceCdRMode;

typedef struct {
	int pos;
	int size;
} FILEDETAILS;

extern unsigned char loadbuf[22528];
extern sceCdRMode CDmode;

void cd_read(long int size, long int loc, char *buf);
void GetRootDirDetails(int *secNum, int *numSectors);
int SCEECdSearchFile(FILEDETAILS *fp, char *name);
int IsFileInDir(int *startSec, int *numSectors, char *name);
int makeInt(int secnum, int start);

#endif // GAME_UTIL_SCEECD_H
