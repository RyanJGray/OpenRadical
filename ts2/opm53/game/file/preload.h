// STATUS: NOT STARTED

#ifndef GAME_FILE_PRELOAD_H
#define GAME_FILE_PRELOAD_H

typedef preloadinfo_u preloadinfo;

void preloadReset();
void preloadAddFile(u8 *filename, u8 *loadpos);
void preloadAddFileLocal(u8 *filename, u8 *loadpos);
void preloadAddOb(u8 *filename, u8 *loadpos);
void preloadAddObAfter(u8 *filename, u8 *loadpos);
void preloadAddTexName(u8 *filename, texinfo *inf);
void preloadAddTexNum(int num, texinfo *inf);
preloadinfo* preloadGetFile(u8 *filename);
preloadinfo* preloadGetFileLocal(u8 *filename);
preloadinfo* preloadGetOb(u8 *filename);
preloadinfo* preloadGetObAfter(u8 *filename);
preloadinfo* preloadGetTexName(u8 *filename);
preloadinfo* preloadGetTexNum(int num);
void preloadExec();
void preloadExecAfter();
void preloadPass2AddTexNum(int num, texinfo *inf, int *newtexnum);
void preloadPass2AddTexName(u8 *name, texinfo *inf, int *newtexnum);
void preloadPass2Exec();

#endif // GAME_FILE_PRELOAD_H
