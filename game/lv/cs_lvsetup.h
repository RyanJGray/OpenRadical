// STATUS: NOT STARTED

#ifndef GAME_LV_CS_LVSETUP_H
#define GAME_LV_CS_LVSETUP_H

typedef cs_animslot_s cs_animslot;

struct cs_animheader_s {
	int numframes;
	float time;
	int curframe;
	float fadeTime;
	float fadeBeforeEnd;
	float currentFadeTime;
	boolean fading;
	int numslots;
	cs_animslot as[15];
};

extern cs_animheader cs_dam_intro;

void cs_setup_dam_intro();
cs_animheader_s* cs_getAnimHeader(int intro);

#endif // GAME_LV_CS_LVSETUP_H
