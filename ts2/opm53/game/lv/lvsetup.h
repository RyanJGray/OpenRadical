// STATUS: NOT STARTED

#ifndef GAME_LV_LVSETUP_H
#define GAME_LV_LVSETUP_H

typedef handler_s handler;

struct prop_s {
	int id;
	int num;
	int type;
	int subtype;
	int room;
	int LastTickFrame;
	u32 flags;
	u32 lastflags;
	u32 damageflags;
	u32 frameflags;
	u32 drawflags;
	u32 framedrawflags;
	obinst *inst;
	obinst *swapinst;
	float startpos[3];
	float pos[3];
	float vel[3];
	float rotx;
	float roty;
	float newroty;
	float rotz;
	float rotaxial;
	float rotinc;
	float rotaxis[3];
	float rotvel[3];
	float lastpos[3];
	float moveRate[3];
	float lastrotx;
	float lastroty;
	float lastrotz;
	int posmode;
	int rotmode;
	int rooms[10];
	int numrooms;
	float scrmin[2];
	float scrmax[2];
	obinst *attachobinst;
	int attachmtxnum;
	int attachflag;
	float hitreacttime;
	mtx_u tmat1;
	mtx_u tmat2;
	int tmatindex1;
	int tmatindex2;
	void *data;
	player_s *player;
	handler handlers[11];
	void (*damageHandler)(/* parameters unknown */);
	int usingdisappearancetimer;
	int disappearancetimer;
	float CentrePos[3];
	float CentrePosAtStart[3];
	float Radius[3];
	float health;
	float maxHealth;
	float damageLevel;
	int numTransformedFloors;
	int numTransformedWalls;
	int numTransformedGlass;
	int numTransformedSpecial;
	floordef_s **transformedFloors;
	walldef_s **transformedWalls;
	glassdef **transformedGlass;
	specialdef **transformedSpecial;
	prop_s *otherprop;
	prop_s *MyAttacker;
	float FloorLevel;
	float RockingDisp;
	float RockingVel;
	float BurnSFXTimer;
	s16 ClosestLight[9];
	float attachobworldpos[3];
	int manualLightIndex;
	int NetLifeCounter;
	float activationdistsq;
	float activationdot;
	hudHealthArmourData_s *hudHealthArmourPtr;
	int activationdata;
	int alarmnumber;
};

struct floordef_s {
	u32 numpoints;
	u16 switchmask;
	u16 flags;
	int fxUsage;
	float fxProportion;
	float xzbb[2][2];
	floorpointdef points[0];
};

struct walldef_s {
	u16 switchmask;
	u16 flags;
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
	float xzbb[2][2];
};

struct player_s {
	int num;
	int localnum;
	ViewDef_s *view;
	int flags;
	playerprefs_t *prefs;
	int controls[42];
	float height;
	float crouchheight;
	float eyedist;
	float eyeheight;
	float desteyeheight;
	float eyeheightoffset;
	float eyeheightoffsetsteps;
	float hardrad;
	float softrad;
	float feetpos[3];
	float eyepos[3];
	float lookdir[3];
	float up[3];
	float right[3];
	float feetdir[3];
	float strafedir[3];
	float hitoffset[3];
	float strafeangle;
	float dirx;
	float feetdirx;
	float diry;
	int autocentre;
	int numframes;
	int movemode;
	int movementtype;
	float skateVelocityX;
	float skateVelocityZ;
	float pushdir[3];
	float swayspeedx;
	float swayspeedy;
	float swayamount;
	float swaycountx;
	float swaycounty;
	float swayx;
	float swayy;
	int lastnumframes;
	float lastfeetpos[3];
	float lasteyepos[3];
	float lastdirx;
	float lastdiry;
	float lastmovedist;
	float lastmovedistxz;
	prop *playerprop;
	float gunmovedist;
	float gunoffset[3];
	playergun gunleft;
	playergun gunright;
	int eyeroom;
	int sighton;
	float sightfracx;
	float sightfracy;
	float sightfracfiltx;
	float sightfracfilty;
	autoaiminfo *autoaim;
	prop *autoaimprop;
	floordef *floor;
	prop *curhitprop;
	float curhitpos[3];
	float curhitnorm[3];
	float velocity[3];
	float soundalerttimer;
	float dualshockpower;
	float dualshockpowerSlowdown;
	float lastfwaxis;
	float laststrafeaxis;
	int DeathViewCounter;
	float DeathViewCurrentDir[3];
	boolean FindingNewTarget;
	prop *pNewTarget;
	float NewTargetDot;
	float soundfirehitpos[3];
	float soundimpactradius;
	float soundfirefrompos[3];
	float soundfirefromradius;
};

struct ViewDef_s {
	mtx_u pm[2];
	mtx_u mvm[2];
	mtx_u mvpm[2];
	mtx_u imvm[2];
	int mnum;
	mtx_u *perspmtx;
	mtx_u *modelviewmtx;
	mtx_u *modelviewperspmtx;
	mtx_u *inv_modelviewmtx;
	int num;
	int type;
	u32 flags;
	int TexID;
	window_t window;
	float particleScale;
	CamDef *pCam;
	float pos[3];
	int room;
	int lastroom;
	prop_s *attached;
	prop_s *follow;
	float lookat[3];
	float lookdir[3];
	float up[3];
	float right[3];
	float cam1mfrustrumhalfheight;
	float cam1mfrustrumhalfwidth;
	float fovy;
	float destfovy;
	float zoomfovy;
	float minzoomfovy;
	float maxzoomfovy;
	float shaketime;
	float shakeintensity;
	float recoilTranslateAmount;
	float recoilTranslateDampening;
	float recoilRotateAmount;
	float recoilRotateDampening;
	roomcalcdata roomdata[201];
	int maxlevel;
	u8 roomVisibility[201];
	prop_s *skyprop;
	s16 numroomsdrawn;
	s16 numroomsdrawnactual;
	s16 roomsdrawn[225];
};

struct chrset_s {
	int chrnums[12];
};

typedef chrset_s chrset_t;

struct setupprop_s {
	int setupref;
	int createflags;
	int propnum;
	float pos[3];
	float rot[3];
	void *extra;
	int forcedRoom;
};

typedef setupprop_s setupprop;

struct setupbutton_s {
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
};

typedef setupbutton_s setupbutton;
typedef lvbuttondata_s lvbuttondata;
typedef setupheader_s setupheader;

struct setupref_s {
	int setupref;
	void *data;
};

typedef setupref_s setupref;

struct gunset_s {
	short int name;
	int numguns;
	int guncombo[15];
};

typedef gunset_s gunset;

struct skySettings_s {
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
};

typedef skySettings_s skySetting;

struct level_info_s {
	short int name;
	int number;
	int tunenum;
	int skySetting;
	setupheader *setup1up;
	setupheader *setupArcade;
	void (*objectivesSetup)(/* parameters unknown */);
	void (*objectivesTick)(/* parameters unknown */);
};

typedef level_info_s level_info;

struct remotedata_s {
	prop *prop;
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
	prop *lockon;
	chrgun_s *gun;
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
	prop *controller;
	int section;
	int ammo[17];
};

typedef remotedata_s remotedata;
extern int numproprefs;
extern int numremoterefs;
extern int story_state1;
extern chrset_t chrpresets[17];
extern short int arcadechrsetnames[8];
extern gunset gunsets[19];
extern setupheader setup_tileset;
extern setupref proprefs[10];
extern setupref remoterefs[5];

level_info* lvGetInfoFromNum(int levelnum);
level_info* lvGetInfo();
int lvGetNumFromName(char *name);
u8* lvGetNameFromNum(int levelnum);
int lvGetTuneNum();
int lvGetSkyPropNum();
u32 lvGetBgCol();
skySetting* lvGetSkySetting();
int* lvGetLevelChrTypeNums(int levelnum);
void lvGetChrTypeNumFromSetup(int setupchrnum, int *pChrTypeUse, int *pChrTypeOriginal);
gunset* lvGetGunSet();
int lvIsValidGunCombo(int guncombo);
setupheader* lvGetARCADESetup(int levelnum);
setupheader* lvGetSTORYSetup(int levelnum);
setupheader* lvGetLevelSetup(int levelnum);
setupNPC* lvGetRandomLastStandNPC(int npcgroup);
int lvGetRandomPlayerSpawn(void *chr);
int lvGetRandomAiSpawn(void *chr);
int lvGetRandomPadExtref(int paddata, float *pos);
int lvGetPseudoRandomPadExtref(int paddata);
int lvGetPadExtrefFromData(int paddata);
void lvSetupProp(setupprop *sp);
prop_s* lvGetPropFromSetupRef(int setupref);
remotedata* lvGetRemoteFromSetupRef(int setupref);
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
void lvButtonActivate(prop *button, prop *actor);
void lvButtonTick(int b);
prop_s* propNewLvButton(setupbutton *sb);
int lvGetOverseerState();
float lvGetOverseerBackSleepTime();
void lvInitStoryState();
void lvCheckPropStatic(prop *p, int createflags, int forcedRoom);
int lvSetupCountChrsInSetupOfType(int type);

#endif // GAME_LV_LVSETUP_H
