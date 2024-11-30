//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FILE_PRELOAD_H
#define GAME_FILE_PRELOAD_H

#include "common.h"
#include "em/em.h"

enum {
	PRELOAD_FILE = 0,
	PRELOAD_OB = 1,
	PRELOAD_TEXNAME = 2,
	PRELOAD_TEXNUM = 3,
	PRELOAD_FILELOCAL = 4,
	PRELOAD_OB_AFTER = 5,
	PRELOAD_NUM = 6
};

// Forward-declare
typedef union preloadinfo_u preloadinfo;

typedef struct preloadfileinfo_s {
	u16 type;
	u16 flags;
	preloadinfo *next;
	int cdsector;
	char *filename;
	u8 *loadpos;
	int size;
} preloadfileinfo;

typedef struct preloadtexnameinfo_s {
	u16 type;
	u16 flags;
	preloadinfo *next;
	int cdsector;
	char *filename;
	texinfo *inf;
	int texnum;
} preloadtexnameinfo;

typedef struct preloadtexnuminfo_s {
	u16 type;
	u16 flags;
	preloadinfo *next;
	int cdsector;
	int texfilenum;
	texinfo *inf;
	int texnum;
} preloadtexnuminfo;

typedef union preloadinfo_u {
	preloadfileinfo file;
	preloadfileinfo ob;
	preloadtexnameinfo texname;
	preloadtexnuminfo texnum;
} preloadinfo;

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
