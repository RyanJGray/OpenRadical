// STATUS: NOT STARTED

#ifndef GAME_FX_CREDITS_H
#define GAME_FX_CREDITS_H

extern creditline creditsText[0];
extern float sinwavetimestart[0];
extern float sinwaveintensity[0];
extern float creditscamup[3];
extern float dirvec[2];
extern creditTunnelSection tunnel[54];
extern char *tunneltexturename[3];
extern int tunneltexnum[3];
extern float layerMultiplier[3];
extern float layerColMultiplier[3];
extern float layerSpeed[3];
extern int creditalpha[3];
extern tunnelData *tunnelDataHead;
extern tunnelData *currenttunneldata;
extern int creditsTextIndex;
extern int creditsPageSize;
extern float creditsStartPos;
extern float creditspagetime;
extern float creditswaittime;
extern float creditstexttime;
extern float fade;
extern float creditscampos[3];
extern float creditscamdir[3];
extern float creditscamrotz;
extern mtx_u *creditsmatrix;
extern int currenttunnelsection;
extern float layerrot[3];
extern float randomsinewavetime;
extern float randomsinewaveintensity;
extern float creditstime;
extern u32 credits_giftag[4];
extern u32 credits_vif_load_giftag[4];
extern u32 credits_vif_load_xyzw[4];
extern u32 credits_vif_load_stnorm[4];
extern u32 credits_vif_load_rgba[4];

void creditsPreload();
void creditsReset();
void creditsEnd();
void creditsTick();
void creditsGfx();
void creditsRestartTunnel();
void creditsBgReset();
void creditsBgTick();
void getCreditTunnelPos(float *posx, float *posy, float posz);
void getCreditTunnelSection(creditTunnelSection *ct, int tunnelsection);
void creditsSetQuad(tunnelData *td, int tunnelsection1, int tunnelsection2, int c);
void creditsSetST(tunnelData *td, int tunnelsection1, int tunnelsection2);
void creditsBgGfx();
void creditsTextReset();
void creditsTextTick();
int creditsCalcTextWave(int y);
void creditsTextGfx();

#endif // GAME_FX_CREDITS_H
