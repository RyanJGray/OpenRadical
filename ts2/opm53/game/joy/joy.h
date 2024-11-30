//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_JOY_JOY_H
#define GAME_JOY_JOY_H

#include "common.h"

typedef struct controller_s {
	u128 dmabuf[16];
	int port;
	int slot;
	int state;
	int laststate;
	int phase;
	int termid;
	int rtermid;
	int lastbut;
	int curbut;
	int newbut;
	int releasebut;
	int axisX1;
	int axisX2;
	int axisY1;
	int axisY2;
	float centrezone;
	u8 act_direct[6];
	u8 act_align[6];
	int actlefttime;
	int actrighttime;
	int clearedbuts;
	int pad[10];
} controller;

// warning: multiple differing types with the same name (size not equal)
typedef struct cheatdef_s {
	u16 buttons[20];
	int numbuttons;
	void (*func)(/* parameters unknown */);
} cheatdef;

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
