//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_ANIM_CS_ANIM_H
#define GAME_ANIM_CS_ANIM_H

#include "prop/prop.h"
#include "ob/cs_ob.h"

typedef struct {
	char id[4];
	int animHeaderOfs;
	int animRawCSCamOfs;
	int animRawCSCamLen;
	int animRawCSLightOfs[3];
	int animRawCSLightLen[3];
} animRawHeader_t;

typedef struct cs_animslot_s {
	int animnum;
	int framestart;
	int frameend;
	int chrtype;
	int sfx;
	animRawHeader_t *animheader;
	prop *prop;
	cs_obinst *cs_inst;
} cs_animslot;

typedef struct cs_animheader_s {
	int numframes;
	float time;
	int curframe;
	float fadeTime;
	float fadeBeforeEnd;
	float currentFadeTime;
	boolean fading;
	int numslots;
	cs_animslot as[15];
} cs_animheader;

void cs_calMatrices(cs_animheader *cs, int slotnum, cs_obinst *inst, int relocating);

#endif // GAME_ANIM_CS_ANIM_H
