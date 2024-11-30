//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "joy.h"

controller controllers[8] = {0};

controller NetControllers[16] = {0};

static u16 cycbuf[20] = {0};

static int cycbufpos = 0;
static int mtappollcount = 0;

static int max_slots[2] = {0};

static int playercontrollers[8] = {
	/* [0] = */ 0,
	/* [1] = */ 4,
	/* [2] = */ 4,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0
};

int joy_justdisconnected = 0;
static u8 *replaybuf = NULL;
static int replaybuflen = 0;
static int replaymode = 0;
static int replaynumplayers = 0;
static int replayend = 0;
int val1 = 0;

char pcarray[10] = {0};

cheatdef cheats[0] = {

};

static u8 *replayptr;

void replayReset(int mode, int numplayers, u8 *buffer, int buflen) {}

void replayTick() {
	static int total = 0;
	static int num = 0;
	int i;
	int j;
	int c;
	u32 rndcheck2;
	int endreplay;
	u8 Data;
	u8 Data;
	u32 Data;
	u16 Data;
	u16 Data;
	u16 Data;
	u16 Data;
	u8 Data;
	u8 Data;
	u8 Data;
	u8 Data;
	u32 Data;
	u32 Data;
}

int joyNum() {
	int i;
	int num;
}

int joyUpdatePorts() {
	int i;
	int num;
}

static float joyFixVal(int ival, float centrezone) {
	float val;
}

static void controllerOpen(controller *c) {
	int i;
}

static void controllerTick(controller *c) {
	u8 rdata[32];
	int id;
	int exid;
}

static void joyMtapTick() {}

int joyMtapGetSlots(int port) {}

static void set_cheat(int num) {}

static void cheat1() {}

static void setcheat1() {}

static void setcheat2() {}

static void setcheat3() {}

static void setcheat4() {}

static void setcheat5() {}

static void cheatTick() {
	int i;
	int j;
	cheatdef *cheat;
	int activated;
	int pos;
}

boolean joyAnyPress() {
	int i;
	boolean press;
	int j;
}

void joyTick() {
	int i;
	controller *nc;
	controller *c;
	controller *nc;
	controller *c;
}

int joyBut(int j) {}

int joyNewBut(int j) {}

int joyReleaseBut(int j) {}

void joyClearButs(int j, int buttons) {
	controller *c;
}

void joyClearAll(int j) {
	controller *c;
}

void joySetCentreZone(int j, float f) {
	controller *c;
}

float joyGetAxis(int j, int axisnum) {
	controller *c;
}

float joyGetButtonAxis(int j, int buttonpos, int buttonneg) {
	float pos;
	float neg;
}

void joySetShock(int j, int left, int right) {
	controller *c;
}

int joyGetShockLeft(int j) {
	controller *c;
}

int joyGetShockRight(int j) {
	controller *c;
}

int joyNewButLOCAL(int j) {}

int joyButLOCAL(int j) {}

float joyGetAxisLOCAL(int j, int axisnum) {
	controller *c;
}

void joyMake() {}

void PutControllerInBuff(int Controller, u8 *Buff) {
	controller *c;
	u16 Data;
	u8 Data;
	u8 Data;
	u8 Data;
	u8 Data;
}

void GetControllerFromBuff(int Controller, u8 *Buff) {
	controller *c;
	u16 Data;
	u8 Data;
	u8 Data;
	u8 Data;
	u8 Data;
}

void joyTickNetPads() {}
