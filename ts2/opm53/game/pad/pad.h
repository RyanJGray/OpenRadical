// STATUS: NOT STARTED

#ifndef GAME_PAD_PAD_H
#define GAME_PAD_PAD_H

typedef pad_s pad;

struct padextrainfo_s {
	prop_s *closesthealth;
	prop_s *closestarmour;
	float closesthealthdist;
	float closestarmourdist;
	prop_s *closestdrop[4];
	prop_s *closestgun[5];
};

typedef padextrainfo_s padextrainfo;

struct link_s {
	u32 flags;
	int pad1num;
	int pad2num;
	float multiplier;
	float cost;
};

typedef link_s link;

struct roomhalllinks_s {
	int numlinks;
	link *links;
};

typedef roomhalllinks_s roomhalllinks;
extern float padsizes[8];
extern int pad_rev;
extern int draw_oldstyle_pads;
extern pad *levelpads;
extern link *levellinks;
extern pad *levelplacementpads;
extern pad *leveldynaplacepads;
extern padextrainfo *levelpadsextra;
extern roomhalllinks *levelroomhalllinks;
extern float lastroutecost;
extern float lasthallroutecost;
extern int plmode;
extern int linkmode;
extern int padflagmode;
extern int padmode;
extern pad *aimpad;
extern pad *lastpad;
extern pad *curpad;
extern int curpadnum;
extern int lastpadnum;
extern int curhall;
extern int numpads;
extern int numlinks;
extern int numplacementpads;
extern int numPadsDisabled;
extern int numLinksDisabled;
extern int padsDisabled[30];
extern int linksDisabled[60];
extern hall **halls;
extern int numhalls;

u8* padFileInName();
void padMake();
void padPreload();
void padRestart();
void padReset();
void padEnd();
void padOnePadLabelGfx(pad *p, u32 col, float yoffset);
void padOnePadLabelExtrefGfx(pad *p, u32 col, float yoffset);
void padPadExtrefGfx();
void padOnePadGfx(pad *p, u32 col, float yoffset);
link* findlink(pad *pad1, pad *pad2);
link* findlinkAllTypes(pad *pad1, pad *pad2);
int padGetLinkNum(int e1, int e2);
int findpadslinked2pad(int padnum, int *padlist, int maxlistsize, int excludeflag);
void padTick();
int padValid(pad *p);
void createlink(pad *curpad, pad *lastpad);
int counthallpads(int testhall);
char* padFlagsToString(int flags, int num, char *s);
void padInfoGfx(pad *p);
void padDisplayPads();
void padGfx();
int padNumFromExtref(int myextref);
int padNumFromPlacementExtref(int myextref);
pad* padPtrFromExtref(int extref);
pad* padPtrFromNum(int padnum);
int padExtrefFromNum(int padnum);
void linkEnable(int linknum);
void linkDisable(int linknum);
void padAddTilePads(u8 *buffer, mtx_u *transmtx, leveltile *lt);
void padCheckLinks();
void padSave();
void editTranslate(float *pos);
void editRotate(float *rot);
void editPadSize(pad *p);
int hr_findroute(routelist *list, int linknum);
int hr_findroutetohall(routelist *list, int hallnum);
int hallrouteCalc(int startpadnum, int destpadnum, int *links, int maxlinks);
int r_findroute(routelist *list, int linknum);
int routeCalc(int startpadnum, int destpadnum, int *links, int maxlinks);
int closestpad(float *pos, float distgreaterthan);
int closestpadInRoom(float *pos, int room, float distgreaterthan);
int closestpadinlist(float *pos, int listnum, int *padlist);
int findhallslinked2hall(int curhallnum, int *halllist, int maxlistsize, int excludeflag);
int padGetHallPads(int hallnum, int **hallpads);
int padGetHallLinks(int hallnum, int **halllinks);
int padCreateDynaPlacePad(float *pos, int linkedpadextref, int extraflags);
void padDeleteDynaPlacePad(int padnum);
int padGetHallNum(pad *p);

#endif // GAME_PAD_PAD_H
