// STATUS: NOT STARTED

#include "cam.h"

static float viewprop_angx = 0.f;
static float viewprop_angy = 0.f;
static float viewprop_dist = 0.f;
static float viewdeaddist = 0.f;

CamDef CameraDefs[0] = {
};

static ViewDef *miniView = NULL;
static int camera_points = 0;

static CamDef defaultMiniCam = {
	/* .Type = */ 3,
	/* .Min = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	},
	/* .Max = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	},
	/* .Offset = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	}
};

ViewDef *camAllViews = NULL;
int camNumViews = 0;
ViewDef *currentview = NULL;

flexcam_t flexcam = {
	/* .campos = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	},
	/* .lookat = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	},
	/* .translationx = */ 0.f,
	/* .translationy = */ 0.f
};

int cam_dataIndex = 0;
cameradata_s *cam_data = NULL;
static prop *viewprop_prop;
static float viewprop_side;
static float viewprop_height;
static int viewprop_doneframe;
static int cammode;
static flycameradata *cam_flypoints;
static int flysegment;
static float fly_segtime;
static int fly_mainviewwindow;
int viewprop_mode = 0;
static float miniViewOriginalTime;
static float miniViewTime;
static int miniViewTexID;

void camInitViewPos(ViewDef *pView, float *pos, int room) {}

void camInitViewData(ViewDef *pView) {}

static void camRestartView(ViewDef *pView) {
	int skypropnum;
}

ViewDef* camCreateView(boolean PlayerView) {
	ViewDef *pView;
	int i;
}

void camDeleteView(ViewDef *pView) {}

void camRestart() {}

void camReset() {
	int i;
}

void camEnd() {}

void camSetMode(int cm) {
	int i;
}

int camGetMode() {}

void camSetType(ViewDef *pView, int Type) {}

void camSetCamDefPtr(ViewDef *pView, CamDef *pCam, prop *pProp) {
	float Pos[3];
	player *pPlayer;
}

void camSetCamDef(ViewDef *pView, int Cam, prop *pProp) {}

void camTick() {
	player *cp;
	float up[3];
	float pos[3];
	float dir[3];
	int i;
	playergun *pg;
	remotedata *rd;
	mtx_u mat;
	float Pos[3];
	float frac;
	float frac;
	float frac;
}

void camSetPerspectiveMatrix(float near, float far, float aspect, float fov) {}

void camNewShake(ViewDef *pView, float time, float amount) {}

void camRecoil(ViewDef *pView, float translateAmount, float translateDampening, float rotateAmount, float rotateDampening) {}

void camShakeTick() {
	static float shakeangx = 75.f;
	static float shakeangy = 18.f;
	static float shakeangz = 170.f;
	float shakex;
	float shakey;
	float shakez;
	int i;
}

void camRenderCurrentView() {
	u32 AttachedDrawFlags;
	u32 AttachedOtherDrawFlags;
	u32 GunLeftDrawFlags;
	u32 GunRightDrawFlags;
	u32 BagDrawFlags;
	chrdata *pData;
	window_t *window;
	window_t *window;
	chrdata *pData;
}

void camRenderCurrentViewOverlay() {}

static void camResetFlyData() {}

static void camNextFlyData() {
	int i;
	playergun *pg;
}

static void camFlyIntroUpdate(float *pos, float *dir) {
	float *p1;
	float *p2;
	float *p3;
	float *p4;
	float lookcx;
	float looksx;
	float lookcy;
	flycameradata *cd;
}

static void camFlyIntroTick() {
	chrdata *hitcd;
}

static void camResetViewProp() {}

static void camViewPropTick() {
	prop *p;
	player *play;
	float cx;
	float sx;
	float cy;
	float sy;
	float dir[3];
	float pos[3];
	float prad;
	float testdir[3];
	float start[3];
	float hpos[3];
	float hnorm[3];
}

static void camDeathCalcPos(float *rpos) {
	player *cp;
	prop *p;
	float cx;
	float sx;
	float cy;
	float sy;
	float dir[3];
	float hpos[3];
	float hnorm[3];
	float pos[3];
	float last10;
	float f;
	float mindist;
	float minang;
	float frac;
	float distdif;
	float angdif;
	float move;
}

static void camDeathView() {
	player *cp;
	prop *p;
	float rpos[3];
}

static void camResetThirdPerson() {}

static void camThirdPersonTick() {
	player *cp;
	float dir[3];
	float hitpos[3];
	float hitnorm[3];
	int newroom;
	int flags;
}

static void camCutsceneTick() {
	animRawCSCam_t *mtx;
	int frame;
	float focal_to_near;
}

void camMiniViewCreate() {}

boolean camMiniViewDoesExist() {}

boolean camMiniViewIsAvailable() {}

void camMiniViewActivateIfAvailable(CamDef *def, float time) {}

void camMiniViewActivate(CamDef *def, float time) {}

void camMiniViewTick() {}

void camMiniViewGfx() {
	u32 rgba;
	u32 alpha;
	float scalar;
	int sizeY;
	int centrey;
	int y1;
	int y2;
}
