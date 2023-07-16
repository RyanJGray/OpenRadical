// STATUS: NOT STARTED

#ifndef GAME_MAPMAKER_MM_DIALOGS_H
#define GAME_MAPMAKER_MM_DIALOGS_H

struct zoomview_s {
	int wcx;
	int wcy;
	int ww;
	int wh;
	int dest[3];
	int destframes;
	float dist;
	float roty;
	float tilt;
	u32 flags;
	prop *prop;
	int itemnum;
	object_t *obj;
	int tilenum;
};

typedef zoomview_s zoomview_t;

struct tilepadinfo_s {
	pad *ppad;
	prop *prop;
	float pos[3];
};

typedef tilepadinfo_s tilepadinfo_t;
extern u32 lightpalette[64];
extern prop *itemprop;
extern pageinit_t zoomtile_page;
extern fix_t pagemargins[4];
extern e_icon mmcursor;
extern u8 lighttype;
extern u8 lightphase;
extern float lightHSV[3];
extern int curlightcol;
extern u32 custompalette[64];
extern zoomview_t zoomview;
extern tilepadinfo_t *aimpadinfo;
extern prop *tileprops[30];
extern prop *circleprop;
extern obdef *iconobs[21];

char* getLightDesc(int mask);
u8* MM_GetFullName(int itemnum);
void MM_PointerSet(int push, int pop);
void MM_DrawCursor(hitbox_t *hb);
void zoomviewPreload();
void zoomviewReset();
void mm_setpadicon(tilepadinfo_t *pi);
void zoomviewWindow(int cx, int cy, int width);
void zoomviewWindowDest(int cx, int cy, int width, int nframes);
boolean zoomviewZoomed();
float zoomviewSizeToDist(int tilenum);
void zoomviewViewSet(int tilenum, float roty);
void zoomviewTick();
void zoomviewGfx();
void MM_StartMainDialog();
void MM_StartZoomTileView(object_t *tileobj);
void MM_DialogsMake();
void MM_DialogsReset();

#endif // GAME_MAPMAKER_MM_DIALOGS_H
