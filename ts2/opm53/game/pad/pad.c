// STATUS: NOT STARTED

#include "pad.h"

struct hall_s {
	int numpads;
	int numhalllinks;
	int numintlinks;
	int data[0];
};

typedef hall_s hall;

typedef enum {
	PLMODE_ADDPAD = 0,
	PLMODE_DELETEPAD = 1,
	PLMODE_SETPADFLAGS = 2,
	PLMODE_MOVEPADXYZ = 3,
	PLMODE_ROTATEPAD = 4,
	PLMODE_SETHALL = 5,
	PLMODE_ADDLINK = 6,
	PLMODE_DELETELINK = 7,
	PLMODE_SAVE = 8,
	PLMODE_NUM = 9
};

typedef enum {
	LINKMODE_NORMAL = 0,
	LINKMODE_ONEWAY = 1,
	LINKMODE_DOOR = 2,
	LINKMODE_NUM = 3
};

typedef enum {
	PADMODE_NAVIGATION = 0,
	PADMODE_PLACEMENT = 1,
	PADMODE_NUM = 2
};

typedef enum {
	PADFLAGMODE_ACTIVE = 0,
	PADFLAGMODE_LEDGE = 1,
	PADFLAGMODE_CAMPER = 2,
	PADFLAGMODE_CORNER = 3,
	PADFLAGMODE_PICKUP = 4,
	PADFLAGMODE_PLACEMENTPAD = 5,
	PADFLAGMODE_INTOLIFT = 6,
	PADFLAGMODE_INLIFT = 7,
	PADFLAGMODE_TELEPORT = 8,
	PADFLAGMODE_PLUGNORTH = 9,
	PADFLAGMODE_PLUGEAST = 10,
	PADFLAGMODE_PLUGSOUTH = 11,
	PADFLAGMODE_PLUGWEST = 12,
	PADFLAGMODE_PLUGGED = 13,
	PADFLAGMODE_DROPPEDGUN = 14,
	PADFLAGMODE_DYNAPLACEPAD = 15,
	PADFLAGMODE_NUM = 16
};

struct route_s {
	short int next;
	short int parent;
	short int padnum;
	short int linknum;
	float cost;
	float esttotal;
};

typedef route_s route;

struct routelist_s {
	int head;
};

typedef routelist_s routelist;

float padsizes[8] = {
	/* [0] = */ 0.25f,
	/* [1] = */ 0.5f,
	/* [2] = */ 0.75f,
	/* [3] = */ 1.f,
	/* [4] = */ 1.5f,
	/* [5] = */ 2.f,
	/* [6] = */ 3.f,
	/* [7] = */ 5.f
};

int pad_rev = 2;
int draw_oldstyle_pads = 0;
pad *levelpads = NULL;
link *levellinks = NULL;
pad *levelplacementpads = NULL;
pad *leveldynaplacepads = NULL;
padextrainfo *levelpadsextra = NULL;
roomhalllinks *levelroomhalllinks = NULL;
float lastroutecost = 0.f;
float lasthallroutecost = 0.f;
int plmode = 1;
int linkmode = 0;
int padflagmode = 0;
int padmode = 0;
pad *aimpad = NULL;
pad *lastpad = NULL;
pad *curpad = NULL;
int curpadnum = -1;
int lastpadnum = -1;
int curhall = 0;
int numpads = 0;
int numlinks = 0;
int numplacementpads = 0;
int numPadsDisabled = 0;
int numLinksDisabled = 0;

int padsDisabled[30] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0,
	/* [10] = */ 0,
	/* [11] = */ 0,
	/* [12] = */ 0,
	/* [13] = */ 0,
	/* [14] = */ 0,
	/* [15] = */ 0,
	/* [16] = */ 0,
	/* [17] = */ 0,
	/* [18] = */ 0,
	/* [19] = */ 0,
	/* [20] = */ 0,
	/* [21] = */ 0,
	/* [22] = */ 0,
	/* [23] = */ 0,
	/* [24] = */ 0,
	/* [25] = */ 0,
	/* [26] = */ 0,
	/* [27] = */ 0,
	/* [28] = */ 0,
	/* [29] = */ 0
};

int linksDisabled[60] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0,
	/* [10] = */ 0,
	/* [11] = */ 0,
	/* [12] = */ 0,
	/* [13] = */ 0,
	/* [14] = */ 0,
	/* [15] = */ 0,
	/* [16] = */ 0,
	/* [17] = */ 0,
	/* [18] = */ 0,
	/* [19] = */ 0,
	/* [20] = */ 0,
	/* [21] = */ 0,
	/* [22] = */ 0,
	/* [23] = */ 0,
	/* [24] = */ 0,
	/* [25] = */ 0,
	/* [26] = */ 0,
	/* [27] = */ 0,
	/* [28] = */ 0,
	/* [29] = */ 0,
	/* [30] = */ 0,
	/* [31] = */ 0,
	/* [32] = */ 0,
	/* [33] = */ 0,
	/* [34] = */ 0,
	/* [35] = */ 0,
	/* [36] = */ 0,
	/* [37] = */ 0,
	/* [38] = */ 0,
	/* [39] = */ 0,
	/* [40] = */ 0,
	/* [41] = */ 0,
	/* [42] = */ 0,
	/* [43] = */ 0,
	/* [44] = */ 0,
	/* [45] = */ 0,
	/* [46] = */ 0,
	/* [47] = */ 0,
	/* [48] = */ 0,
	/* [49] = */ 0,
	/* [50] = */ 0,
	/* [51] = */ 0,
	/* [52] = */ 0,
	/* [53] = */ 0,
	/* [54] = */ 0,
	/* [55] = */ 0,
	/* [56] = */ 0,
	/* [57] = */ 0,
	/* [58] = */ 0,
	/* [59] = */ 0
};

hall **halls = NULL;
int numhalls = 0;
static int numactivepads;
static int numactiveintlinks;
static int numactivehalllinks;
static int numactiveplacementpads;
static u8 padfileinname[64];
static u8 padfileoutname[64];
static route hr_routes[1000];
static routelist hr_openlist;
static routelist hr_closedlist;
static routelist hr_freelist;
static int hr_destpadnum;
static int hr_desthallnum;
static route r_routes[1000];
static routelist r_openlist;
static routelist r_closedlist;
static routelist r_freelist;
static int r_destpadnum;

u8* padFileInName() {}

static u8* padFileOutName() {}

void padMake() {}

void padPreload() {}

void padRestart() {
	int i;
}

void padReset() {
	int i;
	int j;
	int allocsize;
	u8 *buffer;
	u8 *curpos;
	int h1;
	int h2;
	int h1;
	int h2;
}

void padEnd() {}

void padOnePadLabelGfx(pad *p, u32 col, float yoffset) {}

void padOnePadLabelExtrefGfx(pad *p, u32 col, float yoffset) {}

void padPadExtrefGfx() {}

void padOnePadGfx(pad *p, u32 col, float yoffset) {}

static void padDrawLineGfx(float *pos1, float *pos2, u32 col) {}

static void padOnePlacementLinkGfx(pad *p, u32 col) {}

static void padOneLinkGfx(link *l, u32 col) {}

static void printpadinfo(pad *p) {}

static void generatepad(pad *p) {}

static void createpad() {
	int pos;
	pad *p;
}

static void deletelink(link *l) {
	int h1;
	int h2;
}

static void deletepad(pad *p) {
	int i;
	int mypadnum;
	link *l;
}

static void deleteplacementpad(pad *p) {}

static link* newlink() {
	int i;
	int pos;
}

link* findlink(pad *pad1, pad *pad2) {
	int i;
	int pad1num;
	int pad2num;
	link *l;
}

link* findlinkAllTypes(pad *pad1, pad *pad2) {
	int i;
	int pad1num;
	int pad2num;
	link *l;
}

int padGetLinkNum(int e1, int e2) {
	int i;
	int pad1num;
	int pad2num;
	link *l;
}

int findpadslinked2pad(int padnum, int *padlist, int maxlistsize, int excludeflag) {
	int i;
	int index;
	link *l;
}

void padTick() {
	int i;
	link *l;
}

int padValid(pad *p) {
	int val;
}

void createlink(pad *curpad, pad *lastpad) {
	link *l;
	int h1;
	int h2;
}

int counthallpads(int testhall) {
	int i;
	int padcount;
}

char* padFlagsToString(int flags, int num, char *s) {
	int i;
	char *sw;
}

void padInfoGfx(pad *p) {
	char s[1000];
	char fs[100];
	int x;
	int y;
}

void padDisplayPads() {}

void padGfx() {}

int padNumFromExtref(int myextref) {
	int a;
	int b;
	int i;
	int previ;
}

int padNumFromPlacementExtref(int myextref) {
	int a;
	int b;
	int i;
	int previ;
}

pad* padPtrFromExtref(int extref) {
	int i;
}

pad* padPtrFromNum(int padnum) {
	pad *padptr;
}

int padExtrefFromNum(int padnum) {}

static int padNumFromPtr(pad *padptr) {
	int i;
}

void linkEnable(int linknum) {}

void linkDisable(int linknum) {}

static int findTwinPlugPad(float *pos, u32 padflags, int thispadhallnum) {
	int i;
	int closest;
	float mindist;
	float dx;
	float dy;
	float dz;
}

static void padLinkTileSetPads() {
	int i;
	int pad2num;
	link *newlink;
}

void padAddTilePads(u8 *buffer, mtx_u *transmtx, leveltile *lt) {
	int numtilepads;
	int numtilelinks;
	int numtilehalls;
	pad *tmppad;
	link *tmplink;
	int i;
	int j;
	int n;
	int n;
	plugpad_t *p;
	int h1;
	int h2;
}

static void padLoad(char *filename) {
	padfile *buffer;
	int size;
	int padfile_rev;
	pad *p;
	preloadinfo *pl;
	pad *tmppad;
	link *tmplink;
	int i;
	int j;
	int k;
	int numdiscardedlinks;
	int h1;
	int h2;
}

static void padSetRoomNums() {
	float diff;
	int i;
}

void padCheckLinks() {
	int i;
	int j;
	int linked;
	int i;
}

void padSave() {
	char *filename;
	char tempname[1000];
	u8 *buffer;
	u8 *buffer_write;
	int i;
	int numactivelinks;
	pad *p;
	int saveflags;
}

void editTranslate(float *pos) {
	int action;
	int ymod;
}

void editRotate(float *rot) {
	int action;
	float rotinc;
}

void editPadSize(pad *p) {}

static void hr_initroutes() {
	int i;
}

static void hr_addroute(int parent, int padnum, int linknum, float cost, float esttotal) {
	int pos;
	int newroutenum;
	route *newroute;
	route *r;
	route *lastr;
	int done;
}

int hr_findroute(routelist *list, int linknum) {
	int routenum;
}

int hr_findroutetohall(routelist *list, int hallnum) {
	int routenum;
}

static void hr_deleteroute(routelist *list, int routenum) {
	int r;
	int done;
	int next;
}

static float hr_calcestcost(int pad1num, int pad2num) {
	pad *pad1;
	pad *pad2;
	float dx;
	float dy;
	float dz;
}

static float hr_calclinkcost(link *l) {}

static int hr_addnewroutes(int parent, int padnum, float curcost) {
	pad *p;
	int hallnum;
	hall *h;
	int *linknums;
	int numlinks;
	int i;
	int thislinknum;
	link *l;
	int thissidepadnum;
	int othersidepadnum;
	float cost;
	float esttotal;
	int openroutenum;
	int closedroutenum;
}

int hallrouteCalc(int startpadnum, int destpadnum, int *links, int maxlinks) {
	int bestroutenum;
	route *bestroute;
	int done;
	int outlinks;
}

static void r_initroutes() {
	int i;
}

static void r_addroute(int parent, int padnum, int linknum, float cost, float esttotal) {
	int pos;
	int newroutenum;
	route *newroute;
	route *r;
	route *lastr;
	int done;
}

int r_findroute(routelist *list, int linknum) {
	int routenum;
}

static void r_deleteroute(routelist *list, int routenum) {
	int r;
	int done;
	int next;
}

static float r_calcestcost(int pad1num, int pad2num) {
	pad *pad1;
	pad *pad2;
	float dx;
	float dy;
	float dz;
}

static float r_calclinkcost(link *l) {}

static int r_addnewroutes(int parent, int padnum, float curcost) {
	pad *p;
	int hallnum;
	hall *h;
	int *linknums;
	int numlinks;
	int i;
	int thislinknum;
	link *l;
	int otherpadnum;
	float cost;
	float esttotal;
	int openroutenum;
	int closedroutenum;
}

int routeCalc(int startpadnum, int destpadnum, int *links, int maxlinks) {
	int bestroutenum;
	route *bestroute;
	int done;
	int outlinks;
}

int closestpad(float *pos, float distgreaterthan) {
	int i;
	int closest;
	float mindist;
	float dist;
	float dx;
	float dy;
	float dz;
	float distgreaterthansq;
}

int closestpadInRoom(float *pos, int room, float distgreaterthan) {
	int i;
	int closest;
	float mindist;
	float dist;
	float dx;
	float dy;
	float dz;
	float distgreaterthansq;
}

int closestpadinlist(float *pos, int listnum, int *padlist) {
	int i;
	int closest;
	int pad;
	float mindist;
	float dx;
	float dy;
	float dz;
}

int findhallslinked2hall(int curhallnum, int *halllist, int maxlistsize, int excludeflag) {
	int i;
	int index;
	int hallnum;
	hall *h;
	int *hlinks;
	boolean *addedalready[0];
	link *l;
}

int padGetHallPads(int hallnum, int **hallpads) {
	hall *h;
}

int padGetHallLinks(int hallnum, int **halllinks) {
	hall *h;
}

int padCreateDynaPlacePad(float *pos, int linkedpadextref, int extraflags) {
	int i;
	boolean found;
	pad *p;
	pad *lp;
}

void padDeleteDynaPlacePad(int padnum) {}

int padGetHallNum(pad *p) {
	pad *lp;
}
