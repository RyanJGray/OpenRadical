// STATUS: NOT STARTED

#ifndef GAME_JOY_JOY_H
#define GAME_JOY_JOY_H

typedef u_long128 u128;
extern controller controllers[8];
extern controller NetControllers[16];
extern int joy_justdisconnected;
extern int val1;
extern char pcarray[10];
extern cheatdef cheats[0];

void replayReset(int mode, int numplayers, u8 *buffer, int buflen);
void replayTick();
int joyNum();
int joyUpdatePorts();
int joyMtapGetSlots(int port);
boolean joyAnyPress();
void joyTick();
int joyBut(int j);
int joyNewBut(int j);
int joyReleaseBut(int j);
void joyClearButs(int j, int buttons);
void joyClearAll(int j);
void joySetCentreZone(int j, float f);
float joyGetAxis(int j, int axisnum);
float joyGetButtonAxis(int j, int buttonpos, int buttonneg);
void joySetShock(int j, int left, int right);
int joyGetShockLeft(int j);
int joyGetShockRight(int j);
int joyNewButLOCAL(int j);
int joyButLOCAL(int j);
float joyGetAxisLOCAL(int j, int axisnum);
void joyMake();
void PutControllerInBuff(int Controller, u8 *Buff);
void GetControllerFromBuff(int Controller, u8 *Buff);
void joyTickNetPads();

#endif // GAME_JOY_JOY_H
