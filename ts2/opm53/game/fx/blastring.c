// STATUS: NOT STARTED

#include "blastring.h"

struct blastring_s {
	float radiusinner;
	float radiusouter;
	float speed;
	float time;
	float axisrot;
	float axisrotinc;
	float axis[3];
};

typedef blastring_s blastring;
static int numrings = 0;

blastring br[5] = {
	/* [0] = */ {
		/* .radiusinner = */ 0.f,
		/* .radiusouter = */ 0.f,
		/* .speed = */ 0.f,
		/* .time = */ 0.f,
		/* .axisrot = */ 0.f,
		/* .axisrotinc = */ 0.f,
		/* .axis = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		}
	},
	/* [1] = */ {
		/* .radiusinner = */ 0.f,
		/* .radiusouter = */ 0.f,
		/* .speed = */ 0.f,
		/* .time = */ 0.f,
		/* .axisrot = */ 0.f,
		/* .axisrotinc = */ 0.f,
		/* .axis = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		}
	},
	/* [2] = */ {
		/* .radiusinner = */ 0.f,
		/* .radiusouter = */ 0.f,
		/* .speed = */ 0.f,
		/* .time = */ 0.f,
		/* .axisrot = */ 0.f,
		/* .axisrotinc = */ 0.f,
		/* .axis = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		}
	},
	/* [3] = */ {
		/* .radiusinner = */ 0.f,
		/* .radiusouter = */ 0.f,
		/* .speed = */ 0.f,
		/* .time = */ 0.f,
		/* .axisrot = */ 0.f,
		/* .axisrotinc = */ 0.f,
		/* .axis = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		}
	},
	/* [4] = */ {
		/* .radiusinner = */ 0.f,
		/* .radiusouter = */ 0.f,
		/* .speed = */ 0.f,
		/* .time = */ 0.f,
		/* .axisrot = */ 0.f,
		/* .axisrotinc = */ 0.f,
		/* .axis = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		}
	}
};

void blastringReset() {}

void blastringNew() {}

void blastringGfx() {
	float vertex[42][3];
	float sin;
	float cos;
	float angle;
	float angleinc;
	float pos[3];
	float circlePt1[3];
	float circlePt2[3];
	int vi;
	int i;
	int j;
	int v;
	mtx_u mtx;
	u32 col;
	u32 *ref;
	int i;
	void *addr;
}

void blastringEnd() {}
