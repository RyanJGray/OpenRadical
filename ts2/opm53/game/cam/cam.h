//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_CAM_CAM_H
#define GAME_CAM_CAM_H

#include "util/matrix.h"
#include "window/window.h"

// Forward-declarations.
struct prop_s;

enum {
	CAMMODE_GAMECAM = 0,
	CAMMODE_RESETTHIRDPERSONCHEAT = 1,
	CAMMODE_THIRDPERSONCHEAT = 2,
	CAMMODE_MOVEVIEW = 3,
	CAMMODE_RESETVIEWPROP = 4,
	CAMMODE_VIEWPROP = 5,
	CAMMODE_SHOWPROPBACK = 6,
	CAMMODE_FLEXIBLE = 7,
	CAMMODE_MATRIX1 = 8,
	CAMMODE_CUTSCENE = 9,
	CAMMODE_RESETFLYINTRO = 10,
	CAMMODE_FLYINTRO = 11,
	CAMMODE_MAX = 12
};

enum {
	CAMTYPE_FIRSTPERSON = 0,
	CAMTYPE_DEATHVIEW = 1,
	CAMTYPE_REMOTEGUN = 2,
	CAMTYPE_FIXED = 3,
	CAMTYPE_FIXEDFOLLOW = 4,
	CAMTYPE_MOVEFOLLOW = 5,
	CAMTYPE_FLY = 6,
	CAMTYPE_NUM = 7
};

enum {
	CAMDEF_FIRSTPERSON = 0,
	CAMDEF_DEATHVIEW = 1,
	CAMDEF_REMOTEGUN = 2
};

typedef struct roomcalcdata_s {
	int level;
	s16 scrmin[2];
	s16 scrmax[2];
} roomcalcdata;

typedef struct CamDef_s {
	int Type;
	float Min[3];
	float Max[3];
	float Offset[3];
} CamDef;

typedef struct ViewDef_s {
	mtx pm[2];
	mtx mvm[2];
	mtx mvpm[2];
	mtx imvm[2];
	int mnum;
	mtx *perspmtx;
	mtx *modelviewmtx;
	mtx *modelviewperspmtx;
	mtx *inv_modelviewmtx;
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
	struct prop_s *attached;
	struct prop_s *follow;
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
	struct prop_s *skyprop;
	s16 numroomsdrawn;
	s16 numroomsdrawnactual;
	s16 roomsdrawn[225];
} ViewDef;

typedef struct flexcam_s {
	float campos[3];
	float lookat[3];
	float translationx;
	float translationy;
} flexcam_t;

typedef struct flycameradata_s {
	float pos[3];
	float dir[3];
	float speed;
} flycameradata;

typedef struct cameradata_s {
	flycameradata *lvflycameradata;
	int numcamerapoints;
	float stillTime;
	int text;
} cameradata;

extern CamDef CameraDefs[0];
extern ViewDef *camAllViews;
extern int camNumViews;
extern ViewDef *currentview;
extern flexcam_t flexcam;
extern int cam_dataIndex;
extern cameradata *cam_data;
extern int viewprop_mode;

void camInitViewPos(ViewDef *pView, float *pos, int room);
void camInitViewData(ViewDef *pView);
ViewDef* camCreateView(boolean PlayerView);
void camDeleteView(ViewDef *pView);
void camRestart();
void camReset();
void camEnd();
void camSetMode(int cm);
int camGetMode();
void camSetType(ViewDef *pView, int Type);
void camSetCamDefPtr(ViewDef *pView, CamDef *pCam, struct prop_s *pProp);
void camSetCamDef(ViewDef *pView, int Cam, struct prop_s *pProp);
void camTick();
void camSetPerspectiveMatrix(float near, float far, float aspect, float fov);
void camNewShake(ViewDef *pView, float time, float amount);
void camRecoil(ViewDef *pView, float translateAmount, float translateDampening, float rotateAmount, float rotateDampening);
void camShakeTick();
void camRenderCurrentView();
void camRenderCurrentViewOverlay();
void camMiniViewCreate();
boolean camMiniViewDoesExist();
boolean camMiniViewIsAvailable();
void camMiniViewActivateIfAvailable(CamDef *def, float time);
void camMiniViewActivate(CamDef *def, float time);
void camMiniViewTick();
void camMiniViewGfx();

#endif // GAME_CAM_CAM_H
