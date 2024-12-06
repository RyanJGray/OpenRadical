//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_LV_LVSETUP_H
#define GAME_LV_LVSETUP_H

#include "cam/cam.h"
#include "common.h"
#include "fx/weather.h"
#include "prop/lift.h"

// Forward-declarations.
struct chrgun_s;
struct prop_s;

typedef void (*lvbtnhandlerfn)(/* parameters unknown */);

typedef struct AIHandler_s {
  void (*function)(/* parameters unknown */);
} aihandler;

typedef struct chrset_s {
  int chrnums[12];
} chrset_t;

typedef struct setupNPC_s {
  int createflags;
  int startpad;
  int chrtype;
  int gunsetgun;
  int startstate;
  int triggerdata;
  int triggerpad2;
  int aiflags;
  int maxactive;
  int maxspawns;
  float timeIntervals;
  int patrolroutenum;
  int triggertype;
  int data1;
  int sleepgroup;
} setupNPC;

typedef struct setupprop_s {
  int setupref;
  int createflags;
  int propnum;
  float pos[3];
  float rot[3];
  void *extra;
  int forcedRoom;
} setupprop;

typedef struct setupremote_s {
  int setupref;
  int createflags;
  int propnum;
  int type;
  int data1;
  int padextref;
  float target[3];
  float innerradius;
  float outerradius;
  float minanglex;
  float maxanglex;
  float minangley;
  float maxangley;
  float sweepspeed;
  float VerticalFOV;
  float HorizontalFOV;
} setupremote;

typedef struct setupalarm_s {
  int setupref;
  int createflags;
  float duration;
  int commlist;
} setupalarm;

typedef struct setupbutton_s {
  int setupref;
  int createflags;
  int propnum;
  float pos[3];
  float roty;
  int type;
  int flags;
  lvbtnhandlerfn handlerfn;
  int chrpadextref;
  int data1;
  float fdata1;
  void *vdata1;
} setupbutton;

typedef struct setupdoor_s {
  int createflags;
  int propnum;
  int volumenum;
  int id;
  int extrefpadnum;
  int key;
  int doorflags;
  float pos[3];
  float roty;
} setupdoor;

typedef struct setuplsphase_s {
  float delay;
  int numattackloops;
  struct {
    int numchrs;
    int groupnum;
    int targetbase;
    float chrdelay;
    float enddelay;
  } attack[10];
  int numattacks;
  float targettime;
} setuplsphase;

typedef struct setuplssnipergrp_s {
  int groupnum;
  float mininterval;
  float maxinterval;
} setuplssnipergrp;

typedef struct carpath_s {
  int type;
  float destPos[3];
  float destAng;
  float speed;
  float bankingAngle;
  float liftingAngle;
  float turningAngleAdjust;
  float turnRad;
  float turningPointAngle;
  int special;
  boolean distanceSet;
  float distance;
} carpath;

typedef struct setupPatrolRoutes_s {
  int *patrolrt;
  int size;
} setupPatrolRoutes;

typedef struct setupcar_s {
  int createflags;
  int propnum;
  int mode;
  int carflags;
  carpath *paths;
  int numpaths;
} setupcar;

typedef struct setupspecialfx_s {
  int createflags;
  int type;
  int subtype;
  float pos[3];
  float param;
  void *extra;
} setupspecialfx;

typedef struct setuppickup_s {
  int createflags;
  int propnum;
  int pickuptype;
  float data;
  int data2;
  int team;
  int padextref;
  float rot[3];
  float dy;
  int realpadnum;
} setuppickup;

typedef struct setuppropspawn_s {
  int setupref;
  int createflags;
  int propnum;
  float pos[3];
  float rot[3];
  int triggertype;
  int triggerdata;
  int alarmnum;
} setuppropspawn;

typedef struct setupspawn_s {
  int createflags;
  int padextref;
  int flags;
  int realpadnum;
} setupspawn;

typedef struct lvbuttondata_s {
  int setupref;
  int chrpadnum;
  struct prop_s *prop;
  int type;
  int flags;
  lvbtnhandlerfn handlerfn;
  boolean status;
  struct prop_s *activater;
  float timer1;
  int data1;
  float fdata1;
  void *vdata1;
} lvbuttondata;

typedef struct setupheader_s {
  int setupflags;
  int gunset;
  setupprop *props;
  int numprops;
  setuppickup *pickups;
  int numpickups;
  setupdoor *doors;
  int numdoors;
  setupspawn *spawnpads;
  int numspawnpads;
  setupNPC *NPCsetup;
  int numNPCs;
  setupPatrolRoutes *setupPatrolRoutes;
  int numPatrolroutes;
  aihandler *AIEventHandlers;
  int numAIEventHandlers;
  setupNPC *si;
  int numNPCspawns;
  setupcar *cars;
  int numcars;
  setupremote *sr;
  int numremotes;
  setupspecialfx *specialfx;
  int numspecialfx;
  weatherdata *weatherdat;
  int numweatherdata;
  setuplsphase *lsphases;
  int numlsphases;
  setuplssnipergrp *lssnipergrps;
  int numlssnipergrps;
  setupalarm *alarms;
  int numalarms;
  setuplift *lifts;
  int numlifts;
  setupbutton *lvbuttons;
  int numlvbuttons;
  cameradata *lvcameradata;
  int numcamera;
  setuppropspawn *lvpropspawn;
  int numpropspawns;
} setupheader;

typedef struct setupref_s {
  int setupref;
  void *data;
} setupref;

typedef struct gunset_s {
  short int name;
  int numguns;
  int guncombo[15];
} gunset;

typedef struct skySettings_s {
  char *name;
  int skypropnum;
  u32 bgcol;
  u32 cloudcol;
  u32 outercloudcol;
  float cloudradius;
  float cloudheight;
  float cloudheightadjust;
  float skyheightadjust;
  float skyroty;
} skySetting;

typedef struct level_info_s {
  short int name;
  int number;
  int tunenum;
  int skySetting;
  setupheader *setup1up;
  setupheader *setupArcade;
  void (*objectivesSetup)(/* parameters unknown */);
  void (*objectivesTick)(/* parameters unknown */);
} level_info;

typedef struct remotedata_s {
  struct prop_s *prop;
  int setupref;
  int type;
  int state;
  int team;
  float anglex;
  float oldanglex;
  float angley;
  float oldangley;
  float anglez;
  float oldanglez;
  float minanglex;
  float maxanglex;
  float minangley;
  float maxangley;
  float minanglez;
  float maxanglez;
  float speedx;
  float speedy;
  float speedz;
  float target[3];
  float sweeppt[3];
  float sweepradius;
  struct prop_s *lockon;
  struct chrgun_s *gun;
  int barrelfire;
  float starty;
  float startx;
  float startAngles[3];
  float startSpeeds[3];
  float startMins[3];
  float startMaxs[3];
  int CanSeeTimer;
  int FireFromRoom;
  float recoilVelocityLeft;
  float recoilVelocityRight;
  float recoilVelocitySlide;
  float dualshockpower;
  int alarmnum;
  float innerradius;
  float fovHorizontal;
  float fovVertical;
  int AlertPause;
  struct prop_s *controller;
  int section;
  int ammo[17];
} remotedata;

extern int numproprefs;
extern int numremoterefs;
extern int story_state1;
extern chrset_t chrpresets[17];
extern short int arcadechrsetnames[8];
extern gunset gunsets[19];
extern setupheader setup_tileset;
extern setupref proprefs[10];
extern setupref remoterefs[5];

level_info *lvGetInfoFromNum(int levelnum);
level_info *lvGetInfo();
int lvGetNumFromName(char *name);
u8 *lvGetNameFromNum(int levelnum);
int lvGetTuneNum();
int lvGetSkyPropNum();
u32 lvGetBgCol();
skySetting *lvGetSkySetting();
int *lvGetLevelChrTypeNums(int levelnum);
void lvGetChrTypeNumFromSetup(int setupchrnum, int *pChrTypeUse,
                              int *pChrTypeOriginal);
gunset *lvGetGunSet();
int lvIsValidGunCombo(int guncombo);
setupheader *lvGetARCADESetup(int levelnum);
setupheader *lvGetSTORYSetup(int levelnum);
setupheader *lvGetLevelSetup(int levelnum);
setupNPC *lvGetRandomLastStandNPC(int npcgroup);
int lvGetRandomPlayerSpawn(void *chr);
int lvGetRandomAiSpawn(void *chr);
int lvGetRandomPadExtref(int paddata, float *pos);
int lvGetPseudoRandomPadExtref(int paddata);
int lvGetPadExtrefFromData(int paddata);
void lvSetupProp(setupprop *sp);
struct prop_s *lvGetPropFromSetupRef(int setupref);
remotedata *lvGetRemoteFromSetupRef(int setupref);
boolean lvCheckCreateFlagsCore(int flags);
boolean lvCheckCreateFlagsRestart(int flags);
boolean lvCheckCreateFlagsPreload(int flags);
boolean lvCheckCreateFlagsChallenge(int flags);
void lvLevelSetupPreload();
void lvLevelSetup();
void lvbtnhndAlarm(lvbuttondata *bd);
void lvbtnhndDoor(lvbuttondata *bd);
void lvbtnhndMultiDoor(lvbuttondata *bd);
void lvbtnhndRemote(lvbuttondata *bd);
void lvbtnhndEnemyRemote(lvbuttondata *bd);
void lvButtonChangeStatus(lvbuttondata *bd);
void lvButtonActivate(struct prop_s *button, struct prop_s *actor);
void lvButtonTick(int b);
struct prop_s *propNewLvButton(setupbutton *sb);
int lvGetOverseerState();
float lvGetOverseerBackSleepTime();
void lvInitStoryState();
void lvCheckPropStatic(struct prop_s *p, int createflags, int forcedRoom);
int lvSetupCountChrsInSetupOfType(int type);

#endif // GAME_LV_LVSETUP_H
