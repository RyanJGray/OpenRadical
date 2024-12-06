//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_PLAYER_PLAYER_H
#define GAME_PLAYER_PLAYER_H

#include "cam/cam.h"
#include "common.h"
#include "game/signon.h"
#include "gun/gun.h"

typedef struct autoaiminfo_s {
  int visible;
  float dot;
  float dist;
} autoaiminfo;

typedef struct player_s {
  int num;
  int localnum;
  ViewDef *view;
  int flags;
  playerprefs_t *prefs;
  int controls[42];
  float height;
  float crouchheight;
  float eyedist;
  float eyeheight;
  float desteyeheight;
  float eyeheightoffset;
  float eyeheightoffsetsteps;
  float hardrad;
  float softrad;
  float feetpos[3];
  float eyepos[3];
  float lookdir[3];
  float up[3];
  float right[3];
  float feetdir[3];
  float strafedir[3];
  float hitoffset[3];
  float strafeangle;
  float dirx;
  float feetdirx;
  float diry;
  int autocentre;
  int numframes;
  int movemode;
  int movementtype;
  float skateVelocityX;
  float skateVelocityZ;
  float pushdir[3];
  float swayspeedx;
  float swayspeedy;
  float swayamount;
  float swaycountx;
  float swaycounty;
  float swayx;
  float swayy;
  int lastnumframes;
  float lastfeetpos[3];
  float lasteyepos[3];
  float lastdirx;
  float lastdiry;
  float lastmovedist;
  float lastmovedistxz;
  prop *playerprop;
  float gunmovedist;
  float gunoffset[3];
  playergun gunleft;
  playergun gunright;
  int eyeroom;
  int sighton;
  float sightfracx;
  float sightfracy;
  float sightfracfiltx;
  float sightfracfilty;
  autoaiminfo *autoaim;
  prop *autoaimprop;
  floordef *floor;
  prop *curhitprop;
  float curhitpos[3];
  float curhitnorm[3];
  float velocity[3];
  float soundalerttimer;
  float dualshockpower;
  float dualshockpowerSlowdown;
  float lastfwaxis;
  float laststrafeaxis;
  int DeathViewCounter;
  float DeathViewCurrentDir[3];
  boolean FindingNewTarget;
  prop *pNewTarget;
  float NewTargetDot;
  float soundfirehitpos[3];
  float soundimpactradius;
  float soundfirefrompos[3];
  float soundfirefromradius;
} player;

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
void playerDie(player *p, prop *attacker, int bullettype, float *hitpos,
               float *bulletnorm, int parthit, int deathflag);
void playerOnGroundDie(player *p, int bullettype, float *hitpos,
                       float *bulletnorm, int parthit, int deathflag);
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
