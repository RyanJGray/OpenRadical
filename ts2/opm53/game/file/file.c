//
// The OpenTS2 Project
// 2023
//

#include "file.h"

typedef struct {
	char name[48];
	int filepos;
	int filelen;
	int gziplen;
} packfile_t;

typedef struct {
	char id[4];
	int dirofs;
	int dirlen;
} packheader_t;

typedef struct {
	int handle;
	int cdsector;
	int filesize;
	int numfiles;
	u8 *filebuffer;
	packfile_t *pfiles;
} packinfo_t;

union speedy_u {
	u32 w[12];
	u8 s[48];
};

static packfile_t *remember = NULL;
static u8 oneblockbuffer[2048];
static sceCdRMode rmode;
static sceCdlFILE cdfp;
static int numpackfiles;
static int numlevelpackfiles;
static packinfo_t packfiles[8];
static packinfo_t *pakfilefound;

static void fileLoadCD(int sector, u8 *buffer, int size) {
	int numsecs;
	int remainder;
	int reading;
	int wait;
	int thisnum;
	int retry;
	int retry;
}

void packfileLoad(u8 *filename, boolean loadmem, int loadmemtype) {
	packheader_t header;
	packinfo_t *pinfo;
	int handle;
	int cdsector;
	int filesize;
	int foundfile;
	u8 *loadmembuffer;
	int loadmemsize;
	int dirpos;
}

static packfile_t* packfileSeek(u8 *filename) {
	int p;
	int i;
	int j;
	packfile_t *pfile;
	speedy_u speedy;
	boolean found;
}

u8* fileGetMem(u8 *filename) {
	packfile_t *pf;
}

static void pause() {}

int fileGetSector(u8 *filename) {
	packfile_t *pf;
}

int fileSizeSingleFile(u8 *filename) {
	int fd;
	int size;
}

int fileSize(u8 *filename) {
	packfile_t *pf;
}

u8* fileLoad(u8 *filename, int memperiod, int *retsize) {
	u8 *buffer;
	int size;
}

void addfiletoloadedlist(u8 *filename) {}

int fileLoadTo(u8 *filename, u8 *buffer, int maxsize) {
	int size;
	packfile_t *pf;
	int cdsector;
	int cdsector;
	u8 *gzippos;
}

int fileLoadSingleFile(u8 *filename, u8 *buffer, int maxsize) {}

void fileSave(u8 *filename, u8 *buffer, int len) {
	int fd;
}

void fileCopy(u8 *oldfilename, u8 *newfilename) {
	static char *copybuffer;
	int size;
}

void packfileMake() {}

void packfileRestart() {}

void packfileReset() {}

void packfileEnd() {}
