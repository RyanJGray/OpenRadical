// STATUS: NOT STARTED

#ifndef GAME_MCARD_MCARD_H
#define GAME_MCARD_MCARD_H

struct memcarddata_s {
	u32 id;
	u8 data[0];
};

typedef memcarddata_s memcarddata_t;

int mcardIconClusters(int gamedir);
void mcardMake();
void mcardReset();
void mcardEnd();
void mcardTick();
void mcunformat();
void mcardCheckCards(int *cards, int *free, int *state);
void mcardSelectCard(int p, int s);
void mcardFormat();
void mcardGetEntSpace(char *pathname, int *retval);
void mcardMkdir(int gamedir, int overwriteok, int copyprotect);
void mcardCheckDir(int gamedir);
void mcardFileExists(char *filename);
void mcardFileRead(char *filename, u8 *buffer, int length, int seekstart);
void mcardFileWrite(char *filename, u8 *buffer, int length, boolean overwriteok, int seekstart);
void mcardFileDelete(char *filename);
int mcardGetResult();
int memcardFileSize(int datasize);
memcarddata_t* memcardFileAlloc(int datasize, int period);
void memcardFileMakeCRC(memcarddata_t *p, u32 id, int datasize);
int memcardFileCheck(memcarddata_t *p, u32 id, int datasize);

#endif // GAME_MCARD_MCARD_H
