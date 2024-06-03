// STATUS: NOT STARTED

#ifndef GAME_CAM_CAM_H
#define GAME_CAM_CAM_H

struct CamDef_s {
	int Type;
	float Min[3];
	float Max[3];
	float Offset[3];
};

typedef CamDef_s CamDef;
typedef ViewDef_s ViewDef;

struct flexcam_s {
	float campos[3];
	float lookat[3];
	float translationx;
	float translationy;
};

typedef flexcam_s flexcam_t;

struct cameradata_s {
	flycameradata_s *lvflycameradata;
	int numcamerapoints;
	float stillTime;
	int text;
};

extern CamDef CameraDefs[0];
extern ViewDef *camAllViews;
extern int camNumViews;
extern ViewDef *currentview;
extern flexcam_t flexcam;
extern int cam_dataIndex;
extern cameradata_s *cam_data;
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
void camSetCamDefPtr(ViewDef *pView, CamDef *pCam, prop *pProp);
void camSetCamDef(ViewDef *pView, int Cam, prop *pProp);
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
