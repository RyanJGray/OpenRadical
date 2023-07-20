//
// The OpenTS2 Project
// 2023
//

#ifndef GAME_FILE_FILE_H
#define GAME_FILE_FILE_H

#include "../../types.h"

void packfileLoad(u8 *filename, boolean loadmem, int loadmemtype);
u8* fileGetMem(u8 *filename);
int fileGetSector(u8 *filename);
int fileSizeSingleFile(u8 *filename);
int fileSize(u8 *filename);
u8* fileLoad(u8 *filename, int memperiod, int *retsize);
void addfiletoloadedlist(u8 *filename);
int fileLoadTo(u8 *filename, u8 *buffer, int maxsize);
int fileLoadSingleFile(u8 *filename, u8 *buffer, int maxsize);
void fileSave(u8 *filename, u8 *buffer, int len);
void fileCopy(u8 *oldfilename, u8 *newfilename);
void packfileMake();
void packfileRestart();
void packfileReset();
void packfileEnd();

#endif // GAME_FILE_FILE_H
