//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_HUD_HUD_H
#define GAME_HUD_HUD_H

#include "common.h"
#include "game/objectives.h"

typedef struct hudHealthArmourSegment_s {
	float healthArmourThreshold;
	float gfxThreshold;
	int col[3];
} hudHealthArmourSegment;

typedef struct hudMessage_s {
	int type;
	u8 text[256];
	objective *objectiveMessage;
	float time;
	float waitTime;
	float moveTime;
	float lifeTime;
	float forceOutTime;
} hudMessage;

typedef struct hudHealthArmourData_s {
	boolean healthSegmentOn[20];
	boolean armourSegmentOn[20];
	float healthSegmentFadeTime[20];
	float armourSegmentFadeTime[20];
	float hudBarsTime;
} hudHealthArmourData;

typedef struct hudparms_s {
	hudplrparms_t plr[4];
} hudparms_t;

extern hudHealthArmourSegment hudHealth[21];
extern hudHealthArmourSegment hudArmour[21];
extern hudparms_t hudparms;

void hudPreload();
void hudRestart();
void hudReset();
hudHealthArmourData* hudAllocHealthArmourData();
void hudResetHealthArmourData(hudHealthArmourData *haData, prop *p);
void hudRestartMessages();
void hudAddMessage(int localnum, int type, u8 *message, float delay);
void hudObjectiveMessage(int localnum, objective *obj, float delay);
void hudClearAllMessages(int localplayer);
void hudClearMessages(int localplayer, int type);
void hudMainMessageGfx(hudMessage *msg);
void hudFadeMessageGfx(hudMessage *msg);
int hudGetSmallMessageY();
void hudSmallFadeMessageGfx(hudMessage *msg, float offsetScalar);
void hudObjectiveMessageGfx(hudMessage *msg);
void hudScrollMessageGfx(hudMessage *msg);
void hudMessagesTick();
void hudMessagesGfx();
void hudKillMessage(chrdata *attackerchr);
void hudTick();
void hudShowScore(int playernum, int time);
void hudAmmoIcon(int ammoType, int x, int y);
void hudPainGfx(u32 rgba, float bludang);
void hudMeterTick();
void hudDrawFixedGunMeter(int barLeft, int top, int barRight, int bottom, int meter, u8 *title);
void hudFixedGunGfx();
void hudRemoteDeviceGfx();
void hudDrawCrossHair();
boolean hudShouldShowGuns();
void hudFRDLogoGfx(int offsety);
void hudFlyIntroText();
void hudGfx();
void hudEnd();
void hudSetDamage(int localplayer, float damage);
void hudAddDamage(int localplayer, float damage);
void hudPlayerSpawn(player *pl);
void hudHealthArmourTick(hudHealthArmourData *haData, prop *p);
void hudPropHealthBarGfx(prop *p, u8 *s, int x1, int y1, int x2, int y2, u32 barOnAlpha, u32 barOffAlpha);
void hudPlayerHealthBarGfx();
float hudGetHealthSegmentIntensity(hudHealthArmourData *haData, int segment);
float hudGetArmourSegmentIntensity(hudHealthArmourData *haData, int segment);
float hudGetSegmentIntensity(int type, hudHealthArmourData *haData, int segment);
void hudIgmPlayerHealthGfx(hudHealthArmourData *haData, float movex, float movey, float scale, u32 barOnAlpha, u32 barOffAlpha, u32 borderAlpha);
void hudPropApacheLaunchers(u8 *s, int x1, int y1, int x2, int y2);

#endif // GAME_HUD_HUD_H
