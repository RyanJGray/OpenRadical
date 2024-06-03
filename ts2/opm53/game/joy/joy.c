// STATUS: NOT STARTED

#include "joy.h"

struct controller_s {
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
};

typedef controller_s controller;

// warning: multiple differing types with the same name (#17, size not equal)
struct cheatdef_s {
	u16 buttons[20];
	int numbuttons;
	void (*func)(/* parameters unknown */);
};

typedef cheatdef_s cheatdef;

controller controllers[8] = {
	/* [0] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [1] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 1,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [2] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 2,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [3] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 3,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [4] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 1,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [5] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 1,
		/* .slot = */ 1,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [6] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 1,
		/* .slot = */ 2,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [7] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 1,
		/* .slot = */ 3,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	}
};

controller NetControllers[16] = {
	/* [0] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [1] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [2] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [3] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [4] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [5] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [6] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [7] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [8] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [9] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [10] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [11] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [12] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [13] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [14] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	},
	/* [15] = */ {
		/* .dmabuf = */ {
			/* [0] = */ VECTOR(0, 0, 0, 0),
			/* [1] = */ VECTOR(0, 0, 0, 0),
			/* [2] = */ VECTOR(0, 0, 0, 0),
			/* [3] = */ VECTOR(0, 0, 0, 0),
			/* [4] = */ VECTOR(0, 0, 0, 0),
			/* [5] = */ VECTOR(0, 0, 0, 0),
			/* [6] = */ VECTOR(0, 0, 0, 0),
			/* [7] = */ VECTOR(0, 0, 0, 0),
			/* [8] = */ VECTOR(0, 0, 0, 0),
			/* [9] = */ VECTOR(0, 0, 0, 0),
			/* [10] = */ VECTOR(0, 0, 0, 0),
			/* [11] = */ VECTOR(0, 0, 0, 0),
			/* [12] = */ VECTOR(0, 0, 0, 0),
			/* [13] = */ VECTOR(0, 0, 0, 0),
			/* [14] = */ VECTOR(0, 0, 0, 0),
			/* [15] = */ VECTOR(0, 0, 0, 0)
		},
		/* .port = */ 0,
		/* .slot = */ 0,
		/* .state = */ 0,
		/* .laststate = */ 0,
		/* .phase = */ 0,
		/* .termid = */ 0,
		/* .rtermid = */ 0,
		/* .lastbut = */ 0,
		/* .curbut = */ 0,
		/* .newbut = */ 0,
		/* .releasebut = */ 0,
		/* .axisX1 = */ 128,
		/* .axisX2 = */ 128,
		/* .axisY1 = */ 128,
		/* .axisY2 = */ 128,
		/* .centrezone = */ 0.25f,
		/* .act_direct = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .act_align = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0
		},
		/* .actlefttime = */ 0,
		/* .actrighttime = */ 0,
		/* .clearedbuts = */ 0,
		/* .pad = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0,
			/* [4] = */ 0,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0
		}
	}
};

static u16 cycbuf[20] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0,
	/* [10] = */ 0,
	/* [11] = */ 0,
	/* [12] = */ 0,
	/* [13] = */ 0,
	/* [14] = */ 0,
	/* [15] = */ 0,
	/* [16] = */ 0,
	/* [17] = */ 0,
	/* [18] = */ 0,
	/* [19] = */ 0
};

static int cycbufpos = 0;
static int mtappollcount = 0;

static int max_slots[2] = {
	/* [0] = */ 0,
	/* [1] = */ 0
};

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

char pcarray[10] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0
};

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
