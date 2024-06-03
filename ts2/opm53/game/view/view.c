// STATUS: NOT STARTED

#include "view.h"

float view_campos[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

float view_camdir[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 1.f
};

float view_angx = 0.f;
float view_angy = 0.f;
mtx_u *viewmatrix = NULL;

void viewTick() {
	float lookat[3];
	float up[3];
	mtx_u tmpmtx;
	int but;
}
