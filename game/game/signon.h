// STATUS: NOT STARTED

#ifndef GAME_GAME_SIGNON_H
#define GAME_GAME_SIGNON_H

struct playerprefs_s {
	u16 confignum;
	u16 controlflags;
	int customcontrols[42];
	int colourid;
	int chrnum;
	int gunoption;
	int handicap;
};

typedef playerprefs_s playerprefs_t;

struct gamestatus_s {
	chrstats_t chrs[50];
	levelstats_t levels[47];
	challengestats_t challenges[27];
	lifestats_t lifestats_story;
	lifestats_t lifestats_arcade;
	lifestats_t lifestats_challenge;
};

typedef gamestatus_s gamestatus_t;

struct gamesettings_s {
	int gv_dispx;
};

typedef gamesettings_s gamesettings_t;

struct signondata_s {
	u8 name[31];
	playerprefs_t playerprefs;
	gamesettings_t gamesettings;
	gamestatus_t gamestatus;
};

typedef signondata_s signondata_t;

struct gamefile1_s {
	int lastsignon;
	u32 unique;
	int reserved[2];
	signondata_t soentries[16];
};

typedef gamefile1_s gamefile1_t;

struct signoninfo_s {
	int card;
	u32 fileid;
};

typedef signoninfo_s signoninfo_t;
extern gamevar gv_autosave;
extern signondata_t *signonarray;
extern signoninfo_t signoninfo[144];

void playerprefsNew(playerprefs_t *pprefs);
void statsCombine(int numplayers);
gamestatus_t* statsGet();
gamestatus_t* statsGetPlayer(int playernum);
void statsDebug(gamestatus_t *status);
gamesettings_t* settingsGet();
int signonFileGetFree(signondata_t *array);
int signonGetFree();
u32 signonMakeFileId();
int signonNew(u8 *signonname);
int signonFileGetName(signondata_t *array, u8 *name);
int signonGetName(u8 *name);
void signonCheckSlot(gamefile1_t *sofile, int cardnum);
void signonAddFile(gamefile1_t *sofile, int cardnum);
int signonFileCount(signondata_t *array);
void signonFileDelete(signondata_t *array, int signonnum);
int signonFileSize();
void signonDelete(int signonnum);
int signonCount();
int signonMemCount();
void signonSet(int playernum, int signonnum);
void signonMake();
void debugsignon();
int signonGet(int playernum);

#endif // GAME_GAME_SIGNON_H
