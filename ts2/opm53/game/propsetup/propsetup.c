// STATUS: NOT STARTED

#include "propsetup.h"

// warning: multiple differing types with the same name (#100,  not equal)
enum {
	PEMODE_MOVEXYZPROP = 0,
	PEMODE_ROTATEPROP = 1,
	PEMODE_SHOWPADS = 2,
	PEMODE_NUM = 3
};

static int lasteditpropnum = 174;
int pemode = 0;
prop *aimprop = NULL;
prop *lastprop = NULL;
prop *curprop = NULL;
static int showpads = 1;

int propEditable(prop *p) {}

static int propEditValidPropnum(int propnum) {
	int valid;
}

static void propEditDelete(prop *p) {}

void propEditGfx() {}

static void drawPropSelector(prop *p, int rgba) {
	float v1[3];
	float v2[3];
	float v3[3];
	float v4[3];
	float v5[3];
	float v6[3];
	float v7[3];
	float v8[3];
	mtx_u *pView;
}
