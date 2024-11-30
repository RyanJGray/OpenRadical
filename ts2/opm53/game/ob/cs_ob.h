//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_OB_CS_OB_H
#define GAME_OB_CS_OB_H

#include "common.h"
#include "anim/cs_anim.h"
#include "em/em.h"
#include "util/matrix.h"

typedef struct cs_gfxchunk_s {
	int texnum;
	int offset;
	int numvtx;
} cs_gfxchunk;

typedef struct cs_partdef_s {
	cs_gfxchunk *chunklist;
	int numchunks;
	int *bindings;
	int numbindings;
	int firstbinding;
} cs_partdef;

typedef struct cs_hierarchyinfo_s {
	int matrixnum;
	int parent;
	int child;
	int next;
	int prev;
} cs_hierarchyinfo;

typedef struct cs_obdef_s {
	float *xyz;
	float *st;
	float *normal;
	cs_partdef *parts;
	cs_hierarchyinfo *hr;
	int numparts;
	int nummatrices;
	int numbindings;
	texinfo *textures;
	mtx *bindmatrices;
} cs_obdef;

typedef struct cs_obinst_s {
	cs_obdef *ob;
	mtx *realmatrices;
	mtx *gfxmatrices;
	mtx *lightdir;
	animinfo anim1;
	float pos[3];
	float roty;
} cs_obinst;

void csPreLoad();
cs_obdef* cs_obLoad(u8 *filename);
void cs_relocateModel(cs_obinst *inst, char *bindfile);
void cs_obInstGfx(cs_animheader *cs, int slotnum);
cs_obinst* cs_obInstNew(cs_obdef *ob);
void cs_obInstTick(cs_animheader *cs, int slotnum);
boolean cutsceneDoesEndOnStill();
void cutsceneStartFade();
float cutsceneGetTime();
float cutsceneGetTotalTime();
void csTick();
void csGfxTick();
void cutsceneFilterGfx();

#endif // GAME_OB_CS_OB_H
