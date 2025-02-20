//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GAME_GAME_H
#define GAME_GAME_GAME_H

#include "common.h"
#include "util/misc.h"

typedef struct gamemodeinfo_s {
	short int name;
	int useteamspawns;
	int useteamdrops;
} gamemodeinfo_t;

typedef struct storyinfo_s {
	short int title;
	short int levelnum;
	u16 male;
	u16 female;
} storyinfo_t;

typedef struct teaminfo_s {
	short int name;
	u32 colour;
} teaminfo_t;

typedef struct resetgameparms_s {
	int numplayers;
	int numlocalplayers;
	int numbots;
	int numteams;
	u8 teamnums[5];
	u8 chrtypes[14];
	u8 chrteams[14];
	// u8[14] chrskill
	// s8[14] chrheads
	// s16 levelnum
	int levelnum;
	int challengenum;
	int gamemode;
	int gameskill;
	u32 gameflags;
	u32 miscflags;
	int timelimit;
	int killlimit;
	int scorelimit;
	int inactivitytimer;
	int demonum;
	u8 teamactive[5];
	int totalbotskill;
} resetgameparms;

extern int demo_completed;
extern int demo_aborted;
extern int demo_timeout;
extern int demo_attractend;
extern int demo_attractabort;
extern storyinfo_t storydata[9];
extern teaminfo_t teamdata[5];
extern gamemodeinfo_t gamemodedata[9];
extern u32 charcolours[14];
extern int doingminimalreset;
extern int minimalresetdone;
extern resetgameparms curgameparms;
extern resetgameparms deferedgameparms;
extern int gameframe;
extern int gamestate;
extern float gamestatetime;
extern bubblesort_t *gameranksteam[58];
extern int gameranksizeteam;
extern bubblesort_t *gamerankschr[58];
extern int gameranksizechr;

boolean gameIsPlayingGame();
u8* gameGetTeamName(int team);
u8* gameFormatBagTagTime(int frames);
u8* gameFormatTime(int frames);
boolean gameModeDisplayRank();
int UnlockCombo();
int UnlockCombo2();
void gameSetState(int state);
boolean gameModeIsArcade();
void gameEndLevelSound();
void gameLevelRestart();
void gameLevelImmediateQuit();
void gameLevelQuit();
void gameRankingMessages();
void gameLevelCompleted();
void gmSpawnKnockOutBag(int ghostbagnum, int padnum);
int gmEscorteeReachedDest();
int gmLastStandAllBasesDestroyed();
int gameGetRankTeam(int teamnum);
int gameGetRankChr(int chrnum);
char* gameConvertRankToString(int ranking);
void gameDeferedReset(resetgameparms *p);
void gameRestart();
void gameRestartAfter();
void gameReset();
void gameResetAfter();
void gameEndCutscene();
void gameEndIntro();
void gameTick();
void gameEnd();
boolean gameTerminateButtonsPressed();
boolean gameSkipButtonsPressed();

#endif // GAME_GAME_GAME_H
