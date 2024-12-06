//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_MENU_INGAME_H
#define GAME_MENU_INGAME_H

#include "common.h"
#include "game/signon.h"
#include "text/text.h"
#include "util/matrix.h"
#include "util/misc.h"
#include "window/window.h"

// Forward-declarations.
struct objective_s;

enum {
  MENUFX_COLORS_IGM_FLOATING = 0,
  MENUFX_COLORS_IGM_NORMAL = 1,
  MENUFX_COLORS_IGM_CONTROLS = 2,
  MENUFX_COLORS_NUM = 3
};

typedef struct menufxGeometryPoint_s {
  float pos[3];
  float normalO[3];
  float normal[3];
} menufxGeometryPoint;

typedef struct menufxControlPointSet_s {
  int numControlPoints;
  menufxGeometryPoint controlPoints[20];
} menufxControlPointSet;

typedef struct menufxGeometryEdge_s {
  menufxGeometryPoint *CP0;
  menufxGeometryPoint *start;
  menufxGeometryPoint *end;
  menufxGeometryPoint *CP3;
  int steps;
} menufxGeometryEdge;

typedef struct menufxItemOption_s {
  u8 *text;
  int flags;
  int x;
  int y;
  float controlAlertTime;
} menufxItemOption;

typedef struct menufxGeometrySurface_s {
  menufxGeometryEdge *edges[4];
  boolean reverse[4];
} menufxGeometrySurface;

typedef struct menufxGeometryBar_s {
  menufxGeometryPoint corners[8];
  menufxGeometryEdge edges[12];
  menufxGeometrySurface surfaces[6];
  float xstart;
  float xend;
  float ystart;
  float yend;
  float middlepos;
  float zstart;
  float zend;
  int type;
  union mtx_u matrixDl;
  union mtx_u matrixUcodeBuffer[2];
  union mtx_u *matrixUcode;
} menufxGeometryBar;

typedef struct menufxItem_s {
  int font;
  u8 *text;
  int colorScheme;
  int flags;
  float timeHighlighted;
  void (*select)(/* parameters unknown */);
  int x;
  int y;
  int numOptions;
  int currentOption;
  menufxItemOption options[20];
  void (*onChange)(/* parameters unknown */);
  int iconMiscTex;
  float iconx;
  menufxGeometryBar *bar;
  float texty;
} menufxItem;

typedef struct menufxCurveData_s {
  float circleposx;
  float circleposy;
  float circleradiusx;
  float circleradiusy;
  float circleoutlineradiusx;
  float circleoutlineradiusy;
  int circleSteps;
  float extrapolationChange;
} menufxCurveData;

typedef struct menufxColorScheme_s {
  u32 titlefg[4];
  u32 titlebg[4];
  u32 normalfg[4];
  u32 normalbg[4];
  u32 highlightedfg[4];
  u32 highlightedbg[4];
  u32 disabledfg[4];
  u32 disabledbg[4];
  u32 normalarrow[4];
  u32 highlightedarrow[4];
  u32 selectedarrow[4];
  u32 disabledarrow[4];
} menufxColorScheme;

typedef struct menufxTentacleNode_s {
  float pos[4];
  float points[8][4];
  float stq[8][3];
  float radius;
  float circlex[8];
  float circley[8];
  float axis1[3];
  float axis2[3];
} menufxTentacleNode;

typedef struct menufxTentacle_s {
  menufxTentacleNode nodes[10];
  float startpos[3];
  float endpos[3];
  float time;
  float noiseval0;
  float noiseval1;
  float noiseSpeed;
  float noiseOffset;
} menufxTentacle;

typedef struct pagedef_s {
  boolean used;
  struct pageinit_s *init;
  u16 focusid;
  u16 spare;
  struct hitbox_s *boxes;
  int numboxes;
  int flags;
  float zoom;
  float worldpos[3];
  int screenposx;
  int screenposy;
  float scrolly;
  float scrollyTime;
  float scrollyDest;
  float scrollyMove;
  float scrollyStep;
  int pageHeight;
  window_t window;
  int numItems;
  menufxItem items[24][2];
  int switchSelected[24];
  int oldSwitchSelected[24];
  float switchScalar[24];
  int itemSelected;
  float selectTime;
  menufxCurveData *curveDataLH;
  menufxCurveData *curveDataRH;
  menufxGeometryBar geometryBars[6];
  menufxControlPointSet controlPointSetLH;
  menufxControlPointSet controlPointSetRH;
  void (*left)(/* parameters unknown */);
  void (*right)(/* parameters unknown */);
} pagedef_t;

typedef struct rankData_s {
  bubblesort_t table[58];
  bubblesort_t *rank[18];
  int numRank;
  int playerRank;
} rankData;

typedef struct igmplayer_s {
  union mtx_u scrollMatrixDl;
  union mtx_u tentacleMatrixDl;
  union mtx_u scrollMatrixUcodeBuffer[2];
  union mtx_u tentacleMatrixUcodeBuffer[2];
  union mtx_u *scrollMatrixUcode;
  union mtx_u *tentacleMatrixUcode;
  union mtx_u barsMatrix;
  union mtx_u perspectiveMatrix;
  int mnum;
  float frustrumHalfWidth;
  float frustrumHalfHeight;
  window_t window;
  int level;
  int oldLevel;
  int flags;
  float time;
  float worldpos[3];
  float startworldpos[3];
  float destworldpos[3];
  textSettings3D textSettings;
  float exitTime;
  float tentacleRotateTimeVertical;
  float tentacleRotateTimeHorizontal;
  float tentacleRotateAngleVertical;
  float tentacleRotateAngleHorizontal;
  float tentacleDirectionHorizontal;
  rankData rankings[3];
  pagedef_t *scrollPageIn;
  pagedef_t *scrollPageOut;
  float scrollTime;
  float scrollDurationX;
  float scrollDurationY;
  struct prop_s *inventoryProp;
  int inventoryPropItemID;
  int inventoryItemID;
  float inventoryItemTime;
  float inventoryScale;
  int numInventoryItems;
  int inventoryIDs[20];
  s8 *inventoryItemNames[20];
  boolean inventoryItemSelectable[20];
  int inventoryItemAmmo[20];
  int inventoryItemAmmoType[20];
  int inventoryItemAmmoSecondary[20];
  int inventoryItemAmmoTypeSecondary[20];
  int inventoryItemClipCount[20];
  struct playerprefs_s newprefs;
  int newcontrols[42];
  int tmpcontrols[42];
} igmplayer_t;

typedef struct igmparms_s {
  igmplayer_t plr[4];
} igmparms_t;

extern float igmDefaultYStart[0][6];
extern float igmDefaultYEnd[0][6];
extern float igmDefaultIconX[0][6];
extern menufxCurveData igmCurveData;
extern menufxColorScheme menufxColors[3];
extern boolean tentaclesSetup;
extern boolean tentaclesTicked;
extern menufxTentacle igmTentacles[17];

float igmGetLevelOutTime();
boolean igmShouldShowScores();
boolean igmShouldShowStatus();
boolean igmShouldShowBriefing();
boolean igmShouldShowAwards();
boolean igmShouldShowStats();
boolean igmShouldShowInventory();
int ingamemenuIsActive(int playernum);
void menufxSetupTentacles();
void menufxUnSetupTentacles();
void menufxTentacleSetPos(menufxTentacle *tentacle, menufxTentacleNode *node,
                          float scalar);
void menufxTentacleTick(menufxTentacle *tentacle);
void menufxTentaclesTick();
void menufxDrawTentacleGlow(menufxTentacle *tentacle, int index);
void menufxDrawTentacle(menufxTentacle *tentacle);
void menufxDrawTentacles();
float menufxGeometryGetXFromCircleLH(float y, float xcirclepos,
                                     float ycirclepos, float radiusx,
                                     float radiusy);
float menufxGeometryGetXFromCircleRH(float y, float xcirclepos,
                                     float ycirclepos, float radiusx,
                                     float radiusy);
void menufxGeometryGetSurfacePos(float *combinedpos,
                                 menufxGeometrySurface *surface, float s,
                                 float t, float *posOrigin);
void menufxGeometryGetNormal(float *normal, menufxGeometrySurface *surface,
                             float s, float t);
void menufxGeometryRenderSurface(menufxGeometrySurface *surface, u32 rgba,
                                 int texture);
void menufxConstructBarGeometry(
    menufxGeometryBar *bar, boolean leftCurve, boolean rightCurve,
    menufxGeometryPoint *topLeftCP, menufxGeometryPoint *topLeft,
    menufxGeometryPoint *bottomLeft, menufxGeometryPoint *bottomLeftCP,
    int stepsLeft, menufxGeometryPoint *topRightCP,
    menufxGeometryPoint *topRight, menufxGeometryPoint *bottomRight,
    menufxGeometryPoint *bottomRightCP, int stepsRight);
u32 menufxChangeAlpha(u32 color, float multiplier);
void menufxRenderGeometryBar(menufxGeometryBar *bar);
void menufxGeometryBarTick(igmplayer_t *igm, pagedef_t *page, menufxItem *mi,
                           int menuitemflags, float highlighttime,
                           float bartime);
void menufxDrawBarIcon(pagedef_t *page, menufxItem *mi, int order);
void menufxItemDrawBarText(pagedef_t *page, menufxItem *mi, int order);
void menufxItemDrawText(pagedef_t *page, menufxItem *mi, float alphaScalar);
void menufxItemReset(menufxItem *mi);
void menufxItemTick(pagedef_t *page, menufxItem *mi);
int menufxItemGetWidth(menufxItem *mi);
int menufxItemGetHeight(menufxItem *mi);
menufxItem *pageGetSwitchedItem(pagedef_t *page, int itemIndex);
void menufxHighlightItem(pagedef_t *page, int itemIndex);
void menufxSetupStraightBars(pagedef_t *page);
void menufxSetupBarsWithCircularControlPoints(pagedef_t *page);
void igmUpdateMatrices(igmplayer_t *igm);
int ingamemenuShouldRenderGame(int player);
void igmRemovalCheck(pagedef_t *page);
void ingamemenuTickBefore();
void ingamemenuTickPlayerBefore();
float igmGetSwitchScalar(pagedef_t *page, int itemID, int switchValue);
void ingamemenuTickPlayerAfter();
void ingamemenuGfxPlayerBefore();
void ingamemenuGfxPlayerAfter();
void ingamemenuPreload();
void ingamemenuRestart();
void ingamemenuReset();
void ingamemenuEnd();
void ingamemenuActivate(int playernum);
void ingamemenuSelect(int playernum);
void ingamemenuPause(int playernum);
void ingamemenuEndScreen(int playernum);
void ingamemenuExit(int playernum);
void ingamemenuCheckUnpause();
void objectiveMessage(struct objective_s *obj, int xLeft, int yDesc, int xRight,
                      int yState, int alpha, boolean ingamemenu);
void setupconfirm_setControls();
void setupconfirm_pageAccept(pagedef_t *page);
void setupconfirm_pageReject(pagedef_t *page);
void setupconfirm_pageCancel(pagedef_t *page);
void prefsaccept_pageReject(pagedef_t *page);
void stats_pageConstruct(pagedef_t *page);
void awards_pageConstruct(pagedef_t *page);
void endgame_pageConstruct(pagedef_t *page);
void options_pageConstruct(pagedef_t *page);
void scores_pageConstruct(pagedef_t *page);
void inventory_pageConstruct(pagedef_t *page);
void status_pageObjectives(pagedef_t *page, boolean draw);
void status_pageConstruct(pagedef_t *page);
void briefing_pageConstruct(pagedef_t *page);

#endif // GAME_MENU_INGAME_H
