// STATUS: NOT STARTED

#ifndef GAME_OB_CS_OB_H
#define GAME_OB_CS_OB_H

struct cs_obdef_s {
	float *xyz;
	float *st;
	float *normal;
	cs_partdef *parts;
	cs_hierarchyinfo *hr;
	int numparts;
	int nummatrices;
	int numbindings;
	texinfo *textures;
	mtx_u *bindmatrices;
};

typedef cs_obdef_s cs_obdef;

struct cs_obinst_s {
	cs_obdef *ob;
	mtx_u *realmatrices;
	mtx_u *gfxmatrices;
	mtx_u *lightdir;
	animinfo anim1;
	float pos[3];
	float roty;
};

typedef cs_obinst_s cs_obinst;
typedef cs_animheader_s cs_animheader;

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
