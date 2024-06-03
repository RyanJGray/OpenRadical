// STATUS: NOT STARTED

#ifndef GAME_PLAYER_PLAYER_H
#define GAME_PLAYER_PLAYER_H

typedef player_s player;
extern short int handicapstrings[7];
extern float crouchSpeed[2];
extern float runSpeed[2];
extern float walkSpeed[2];
extern float runStrafeSpeed[2];
extern float walkStrafeSpeed[2];
extern float maxForwardAccel[2];
extern float maxForwardDecel[2];
extern float maxStrafeAccel[2];
extern int playerConfigNames[7];
extern player *players;
extern player *currentplayer;

void playerprintpos(int p);
void playerSetWindow(player *p);
void playerSetStartPos(player *p);
float playerGetAxis(player *player, int gameControl);
void playerPreload();
void playerSetDefaultControls(int confignum, int *controls);
void playerSetControls(player *p);
void playerRestart();
void playerReset();
void playerDirtyPosReset();
void playerRespawn(player *ply);
void playerDie(player *p, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, int parthit, int deathflag);
void playerOnGroundDie(player *p, int bullettype, float *hitpos, float *bulletnorm, int parthit, int deathflag);
void playerMessage(player *player, u8 *text);
void playerAutoAimTick();
void playerHandleZoom();
void playerCalculateSway();
void playerTick();
void playerFrustrumGfx();
void playerHitPosGfx();
void playerEnd();
float anglediff(float a1, float a2);
void debugtesthits();
int playerGetHudType(player *player);
boolean playerIsDead(player *player);

#endif // GAME_PLAYER_PLAYER_H
