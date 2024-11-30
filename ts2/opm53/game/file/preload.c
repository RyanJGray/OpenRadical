//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "preload.h"

typedef struct preloadpass2info_s {
	int type;
	u8 *texname;
	int texnum;
	texinfo *inf;
	int *newtexnum;
	struct preloadpass2info_s *next;
} preloadpass2info;

static int numpreload = 0;
static preloadinfo preload[500];
static preloadpass2info preloadpass2[1000];
static int numpreloadpass2;
static preloadinfo *preloadhead;
static preloadpass2info *preloadpass2head;

void preloadReset() {}

static void preloadInsert(preloadinfo *pl) {
	preloadinfo *last;
	preloadinfo *next;
	int done;
}

void preloadAddFile(u8 *filename, u8 *loadpos) {
	preloadinfo *pl;
}

void preloadAddFileLocal(u8 *filename, u8 *loadpos) {
	preloadinfo *pl;
}

void preloadAddOb(u8 *filename, u8 *loadpos) {
	preloadinfo *pl;
}

void preloadAddObAfter(u8 *filename, u8 *loadpos) {
	preloadinfo *pl;
}

void preloadAddTexName(u8 *filename, texinfo *inf) {
	preloadinfo *pl;
}

void preloadAddTexNum(int num, texinfo *inf) {
	preloadinfo *pl;
}

preloadinfo* preloadGetFile(u8 *filename) {
	int i;
	preloadinfo *pl;
}

preloadinfo* preloadGetFileLocal(u8 *filename) {
	int i;
	preloadinfo *pl;
}

preloadinfo* preloadGetOb(u8 *filename) {
	int i;
	preloadinfo *pl;
}

preloadinfo* preloadGetObAfter(u8 *filename) {
	int i;
	preloadinfo *pl;
}

preloadinfo* preloadGetTexName(u8 *filename) {
	int i;
	preloadinfo *pl;
}

preloadinfo* preloadGetTexNum(int num) {
	int i;
	preloadinfo *pl;
}

void preloadExec() {
	preloadinfo *pl;
	int Num;
}

void preloadExecAfter() {
	preloadinfo *pl;
}

static void preloadPass2Insert(preloadpass2info *pl) {
	preloadpass2info *last;
	preloadpass2info *next;
	int done;
}

void preloadPass2AddTexNum(int num, texinfo *inf, int *newtexnum) {
	preloadpass2info *pl;
}

void preloadPass2AddTexName(u8 *name, texinfo *inf, int *newtexnum) {
	preloadpass2info *pl;
}

void preloadPass2Exec() {
	preloadpass2info *pl;
}
