//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "sound.h"
#include "sounddata.h"

#include <libsdr.h>

typedef struct soundbuffer_s {
	int sfxloadpos;
	int sfxloadsize;
	int cursfxloadpos;
	int cursfxloadleft;
} soundbuffer;

typedef struct loopsound_s {
	sound *snd;
	int sfxnum;
	int voice;
	int haspos;
	float pos[3];
	float range;
} loopsound;

typedef struct delaysound_s {
	int state;
	int sfxnum;
	u16 haspos;
	u16 locked;
	float pos[3];
	int delay;
	int voice;
} delaysound;

enum {
	DS_FREE = 0,
	DS_WAIT = 1,
	DS_TRANSIOPSTART = 2,
	DS_TRANSIOPWAIT = 3,
	DS_TRANSSPUSTART = 4,
	DS_TRANSSPUWAIT = 5,
	DS_PLAY = 6,
	DS_NUM = 7
};

static soundbuffer soundbuffers[9];
static soundbuffer *thissoundbuf = soundbuffers;
static int transinprogress = 0;
static int lastannounce = -1;
static int announcecountdown = -1;
static int totalSize = 0;
static int totalMainMem = 0;
static int sound_core = -1;
static int sound_voice = -1;
static int soundbatchlen = 0;
static int demand_contents[8];
static int ioploadbuf;
static int iopcmdbuf;
static int numloopsounds;
static loopsound loopsounds[6];
static delaysound delaysounds[10];
static sceSdBatch soundbatch[200];

void soundMake() {}

void soundSelectBuffer(int num) {}

void soundResetBuffer(int num) {
	soundbuffer *sb;
}

void soundCreateBuffer(int num, u32 start, u32 end) {
	soundbuffer *sb;
}

void soundRestart() {
	sceSdEffectAttr reverb;
	int i;
	int c;
}

void soundReset() {
	int i;
	int demandsize;
}

void soundRestartAfter() {}

void soundResetAfter() {
	preloadinfo *pl;
}

void soundPreload() {
	int i;
	int Total;
	int Num;
	int Total;
	int Num;
}

void soundEnd() {}

static void soundSetChannel(int core, int voice) {}

static void soundBatchAdd(u16 func, u16 entry, u32 value) {
	sceSdBatch *sb;
}

static void soundBatchExec() {}

static void soundBatchReset() {}

static void soundCalcVol(sound *snd, float *pos, int *voll, int *volr, float range, int minvolume) {
	float dir[3];
	float distsq;
	float mindistsq;
	float mul;
	int i;
	int vol;
	float dist;
	player *p;
	float pan;
}

void announceTick() {
	int num;
}

void soundPauseLoopedSounds() {
	int core;
	int voice;
	int i;
	loopsound *ls;
}

void soundResumeLoopedSounds() {
	int core;
	int voice;
	int i;
	loopsound *ls;
}

void soundTick() {
	static int demandbuf2 = 1;
	int i;
	int in_menu;
	delaysound *ds;
	u8 *loadpos;
	loopsound *ls;
	int voll;
	int volr;
}

void soundLoad(int sfxnum) {
	int size;
	u8 *spos;
	int slen;
}

void soundStop(int voice) {
	int c;
	int v;
}

void soundDelayStop(int sounddelaynum) {}

int soundStart(int sfxnum, float *pos) {
	int i;
}

static void getNextChannel(int *core, int *voice) {
	static int c = 0;
	static int v = 11;
}

int soundStartRange(int sfxnum, float *pos, float range, int minvolume) {
	static int soundsplayed[100];
	static int lastsoundframenum = -1;
	static int numsounds = 0;
	int i;
	int c;
	int voll;
	int volr;
	int voice;
	sound *snd;
}

int soundDelayStartEx(int sfxnum, float *pos, int delay, int lock) {
	delaysound *ds;
	int i;
}

int soundStartLoop(int sfxnum, float *pos) {}

int soundStartLoopRange(int sfxnum, float *pos, float range) {
	int v;
	loopsound *ls;
}

void soundSetLoopPos(int voice, float *pos) {
	loopsound *ls;
}

void soundAddPreLoad(int sfxnum) {
	sound *s;
}
