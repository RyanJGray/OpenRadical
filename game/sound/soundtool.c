// STATUS: NOT STARTED

#include "soundtool.h"

struct snd_s {
	int cursound;
	s16 *envelope;
};

typedef snd_s snd_t;

struct rate_s {
	int value;
	float time;
};

typedef rate_s rate_t;

// warning: multiple differing types with the same name (#22,  not equal)
enum {
	main_sound = 1,
	main_soundfile = 2,
	main_msg = 3,
	main_envelope = 4,
	main_env1 = 5,
	main_env2 = 6,
	main_env3 = 7,
	main_env4 = 8,
	main_env5 = 9,
	main_pitch = 10,
	main_volume = 11,
	main_save = 12,
	main_last = 13
};

static int envmax[5] = {
	/* [0] = */ 127,
	/* [1] = */ 127,
	/* [2] = */ 127,
	/* [3] = */ 15,
	/* [4] = */ 127
};

static float lindectable[128] = {
	/* [0] = */ 4e-05.f,
	/* [1] = */ 5e-05.f,
	/* [2] = */ 6e-05.f,
	/* [3] = */ 7e-05.f,
	/* [4] = */ 9e-05.f,
	/* [5] = */ 0.0001f,
	/* [6] = */ 0.00012f,
	/* [7] = */ 0.00015f,
	/* [8] = */ 0.00018f,
	/* [9] = */ 0.00021f,
	/* [10] = */ 0.00024f,
	/* [11] = */ 0.00029f,
	/* [12] = */ 0.00036f,
	/* [13] = */ 0.00041f,
	/* [14] = */ 0.00048f,
	/* [15] = */ 0.00058f,
	/* [16] = */ 0.00073f,
	/* [17] = */ 0.00083f,
	/* [18] = */ 0.00097f,
	/* [19] = */ 0.0012f,
	/* [20] = */ 0.0015f,
	/* [21] = */ 0.0017f,
	/* [22] = */ 0.0019f,
	/* [23] = */ 0.0023f,
	/* [24] = */ 0.0029f,
	/* [25] = */ 0.0033f,
	/* [26] = */ 0.0039f,
	/* [27] = */ 0.0046f,
	/* [28] = */ 0.0058f,
	/* [29] = */ 0.0066f,
	/* [30] = */ 0.0077f,
	/* [31] = */ 0.0093f,
	/* [32] = */ 0.012f,
	/* [33] = */ 0.013f,
	/* [34] = */ 0.015f,
	/* [35] = */ 0.019f,
	/* [36] = */ 0.023f,
	/* [37] = */ 0.027f,
	/* [38] = */ 0.031f,
	/* [39] = */ 0.037f,
	/* [40] = */ 0.046f,
	/* [41] = */ 0.053f,
	/* [42] = */ 0.062f,
	/* [43] = */ 0.074f,
	/* [44] = */ 0.093f,
	/* [45] = */ 0.11f,
	/* [46] = */ 0.12f,
	/* [47] = */ 0.15f,
	/* [48] = */ 0.19f,
	/* [49] = */ 0.21f,
	/* [50] = */ 0.25f,
	/* [51] = */ 0.3f,
	/* [52] = */ 0.37f,
	/* [53] = */ 0.42f,
	/* [54] = */ 0.5f,
	/* [55] = */ 0.59f,
	/* [56] = */ 0.74f,
	/* [57] = */ 0.85f,
	/* [58] = */ 0.99f,
	/* [59] = */ 1.2f,
	/* [60] = */ 1.5f,
	/* [61] = */ 1.7f,
	/* [62] = */ 2.f,
	/* [63] = */ 2.4f,
	/* [64] = */ 3.f,
	/* [65] = */ 3.4f,
	/* [66] = */ 4.f,
	/* [67] = */ 4.8f,
	/* [68] = */ 5.9f,
	/* [69] = */ 6.8f,
	/* [70] = */ 7.9f,
	/* [71] = */ 9.5f,
	/* [72] = */ 12.f,
	/* [73] = */ 14.f,
	/* [74] = */ 16.f,
	/* [75] = */ 19.f,
	/* [76] = */ 24.f,
	/* [77] = */ 27.f,
	/* [78] = */ 32.f,
	/* [79] = */ 38.f,
	/* [80] = */ 48.f,
	/* [81] = */ 54.f,
	/* [82] = */ 63.f,
	/* [83] = */ 76.f,
	/* [84] = */ 95.f,
	/* [85] = */ 109.f,
	/* [86] = */ 127.f,
	/* [87] = */ 152.f,
	/* [88] = */ 190.f,
	/* [89] = */ 218.f,
	/* [90] = */ 254.f,
	/* [91] = */ 304.f,
	/* [92] = */ 380.f,
	/* [93] = */ 436.f,
	/* [94] = */ 508.f,
	/* [95] = */ 608.f,
	/* [96] = */ 760.f,
	/* [97] = */ 872.f,
	/* [98] = */ 1016.f,
	/* [99] = */ 1216.f,
	/* [100] = */ 1520.f,
	/* [101] = */ 1744.f,
	/* [102] = */ 2032.f,
	/* [103] = */ 2432.f,
	/* [104] = */ 3040.f,
	/* [105] = */ 3488.f,
	/* [106] = */ 4064.f,
	/* [107] = */ 4864.f,
	/* [108] = */ -1.f,
	/* [109] = */ -1.f,
	/* [110] = */ -1.f,
	/* [111] = */ -1.f,
	/* [112] = */ -1.f,
	/* [113] = */ -1.f,
	/* [114] = */ -1.f,
	/* [115] = */ -1.f,
	/* [116] = */ -1.f,
	/* [117] = */ -1.f,
	/* [118] = */ -1.f,
	/* [119] = */ -1.f,
	/* [120] = */ -1.f,
	/* [121] = */ -1.f,
	/* [122] = */ -1.f,
	/* [123] = */ -1.f,
	/* [124] = */ -1.f,
	/* [125] = */ -1.f,
	/* [126] = */ -1.f,
	/* [127] = */ 999999.f
};

static float lininctable[128] = {
	/* [0] = */ 5e-05.f,
	/* [1] = */ 6e-05.f,
	/* [2] = */ 7e-05.f,
	/* [3] = */ 9e-05.f,
	/* [4] = */ 0.0001f,
	/* [5] = */ 0.00012f,
	/* [6] = */ 0.00015f,
	/* [7] = */ 0.00018f,
	/* [8] = */ 0.00021f,
	/* [9] = */ 0.00024f,
	/* [10] = */ 0.00029f,
	/* [11] = */ 0.00036f,
	/* [12] = */ 0.00041f,
	/* [13] = */ 0.00048f,
	/* [14] = */ 0.00058f,
	/* [15] = */ 0.00073f,
	/* [16] = */ 0.00083f,
	/* [17] = */ 0.00097f,
	/* [18] = */ 0.0012f,
	/* [19] = */ 0.0015f,
	/* [20] = */ 0.0017f,
	/* [21] = */ 0.0019f,
	/* [22] = */ 0.0023f,
	/* [23] = */ 0.0029f,
	/* [24] = */ 0.0033f,
	/* [25] = */ 0.0039f,
	/* [26] = */ 0.0046f,
	/* [27] = */ 0.0058f,
	/* [28] = */ 0.0066f,
	/* [29] = */ 0.0077f,
	/* [30] = */ 0.0093f,
	/* [31] = */ 0.012f,
	/* [32] = */ 0.013f,
	/* [33] = */ 0.015f,
	/* [34] = */ 0.019f,
	/* [35] = */ 0.023f,
	/* [36] = */ 0.027f,
	/* [37] = */ 0.031f,
	/* [38] = */ 0.037f,
	/* [39] = */ 0.046f,
	/* [40] = */ 0.053f,
	/* [41] = */ 0.062f,
	/* [42] = */ 0.074f,
	/* [43] = */ 0.093f,
	/* [44] = */ 0.11f,
	/* [45] = */ 0.12f,
	/* [46] = */ 0.15f,
	/* [47] = */ 0.19f,
	/* [48] = */ 0.21f,
	/* [49] = */ 0.25f,
	/* [50] = */ 0.3f,
	/* [51] = */ 0.37f,
	/* [52] = */ 0.42f,
	/* [53] = */ 0.5f,
	/* [54] = */ 0.59f,
	/* [55] = */ 0.74f,
	/* [56] = */ 0.85f,
	/* [57] = */ 0.99f,
	/* [58] = */ 1.2f,
	/* [59] = */ 1.5f,
	/* [60] = */ 1.7f,
	/* [61] = */ 2.f,
	/* [62] = */ 2.4f,
	/* [63] = */ 3.f,
	/* [64] = */ 3.4f,
	/* [65] = */ 4.f,
	/* [66] = */ 4.8f,
	/* [67] = */ 5.9f,
	/* [68] = */ 6.8f,
	/* [69] = */ 7.9f,
	/* [70] = */ 9.5f,
	/* [71] = */ 12.f,
	/* [72] = */ 14.f,
	/* [73] = */ 16.f,
	/* [74] = */ 19.f,
	/* [75] = */ 24.f,
	/* [76] = */ 27.f,
	/* [77] = */ 32.f,
	/* [78] = */ 38.f,
	/* [79] = */ 48.f,
	/* [80] = */ 54.f,
	/* [81] = */ 63.f,
	/* [82] = */ 76.f,
	/* [83] = */ 95.f,
	/* [84] = */ 109.f,
	/* [85] = */ 127.f,
	/* [86] = */ 152.f,
	/* [87] = */ 190.f,
	/* [88] = */ 218.f,
	/* [89] = */ 254.f,
	/* [90] = */ 304.f,
	/* [91] = */ 380.f,
	/* [92] = */ 436.f,
	/* [93] = */ 508.f,
	/* [94] = */ 608.f,
	/* [95] = */ 760.f,
	/* [96] = */ 872.f,
	/* [97] = */ 1016.f,
	/* [98] = */ 1216.f,
	/* [99] = */ 1520.f,
	/* [100] = */ 1744.f,
	/* [101] = */ 2032.f,
	/* [102] = */ 2432.f,
	/* [103] = */ 3040.f,
	/* [104] = */ 3488.f,
	/* [105] = */ 4064.f,
	/* [106] = */ 4864.f,
	/* [107] = */ 6080.f,
	/* [108] = */ -1.f,
	/* [109] = */ -1.f,
	/* [110] = */ -1.f,
	/* [111] = */ -1.f,
	/* [112] = */ -1.f,
	/* [113] = */ -1.f,
	/* [114] = */ -1.f,
	/* [115] = */ -1.f,
	/* [116] = */ -1.f,
	/* [117] = */ -1.f,
	/* [118] = */ -1.f,
	/* [119] = */ -1.f,
	/* [120] = */ -1.f,
	/* [121] = */ -1.f,
	/* [122] = */ -1.f,
	/* [123] = */ -1.f,
	/* [124] = */ -1.f,
	/* [125] = */ -1.f,
	/* [126] = */ -1.f,
	/* [127] = */ 999999.f
};

static float expdectable[128] = {
	/* [0] = */ 7e-05.f,
	/* [1] = */ 9e-05.f,
	/* [2] = */ 0.00011f,
	/* [3] = */ 0.00014f,
	/* [4] = */ 0.00018f,
	/* [5] = */ 0.00021f,
	/* [6] = */ 0.00025f,
	/* [7] = */ 0.00031f,
	/* [8] = */ 0.00039f,
	/* [9] = */ 0.00045f,
	/* [10] = */ 0.00053f,
	/* [11] = */ 0.00064f,
	/* [12] = */ 0.00081f,
	/* [13] = */ 0.00093f,
	/* [14] = */ 0.0011f,
	/* [15] = */ 0.0013f,
	/* [16] = */ 0.0016f,
	/* [17] = */ 0.0019f,
	/* [18] = */ 0.0022f,
	/* [19] = */ 0.0026f,
	/* [20] = */ 0.0033f,
	/* [21] = */ 0.0038f,
	/* [22] = */ 0.0044f,
	/* [23] = */ 0.0053f,
	/* [24] = */ 0.0067f,
	/* [25] = */ 0.0076f,
	/* [26] = */ 0.0089f,
	/* [27] = */ 0.011f,
	/* [28] = */ 0.013f,
	/* [29] = */ 0.015f,
	/* [30] = */ 0.018f,
	/* [31] = */ 0.021f,
	/* [32] = */ 0.027f,
	/* [33] = */ 0.031f,
	/* [34] = */ 0.036f,
	/* [35] = */ 0.043f,
	/* [36] = */ 0.053f,
	/* [37] = */ 0.061f,
	/* [38] = */ 0.071f,
	/* [39] = */ 0.086f,
	/* [40] = */ 0.11f,
	/* [41] = */ 0.12f,
	/* [42] = */ 0.14f,
	/* [43] = */ 0.17f,
	/* [44] = */ 0.21f,
	/* [45] = */ 0.24f,
	/* [46] = */ 0.29f,
	/* [47] = */ 0.34f,
	/* [48] = */ 0.43f,
	/* [49] = */ 0.49f,
	/* [50] = */ 0.57f,
	/* [51] = */ 0.68f,
	/* [52] = */ 0.86f,
	/* [53] = */ 0.98f,
	/* [54] = */ 1.1f,
	/* [55] = */ 1.4f,
	/* [56] = */ 1.7f,
	/* [57] = */ 2.f,
	/* [58] = */ 2.3f,
	/* [59] = */ 2.7f,
	/* [60] = */ 3.4f,
	/* [61] = */ 3.9f,
	/* [62] = */ 4.6f,
	/* [63] = */ 5.5f,
	/* [64] = */ 6.8f,
	/* [65] = */ 7.8f,
	/* [66] = */ 9.1f,
	/* [67] = */ 11.f,
	/* [68] = */ 14.f,
	/* [69] = */ 16.f,
	/* [70] = */ 18.f,
	/* [71] = */ 22.f,
	/* [72] = */ 27.f,
	/* [73] = */ 31.f,
	/* [74] = */ 36.f,
	/* [75] = */ 44.f,
	/* [76] = */ 55.f,
	/* [77] = */ 63.f,
	/* [78] = */ 73.f,
	/* [79] = */ 88.f,
	/* [80] = */ 109.f,
	/* [81] = */ 125.f,
	/* [82] = */ 146.f,
	/* [83] = */ 175.f,
	/* [84] = */ 219.f,
	/* [85] = */ 250.f,
	/* [86] = */ 292.f,
	/* [87] = */ 350.f,
	/* [88] = */ 438.f,
	/* [89] = */ 500.f,
	/* [90] = */ 584.f,
	/* [91] = */ 700.f,
	/* [92] = */ 876.f,
	/* [93] = */ 1000.f,
	/* [94] = */ 1168.f,
	/* [95] = */ 1400.f,
	/* [96] = */ 1752.f,
	/* [97] = */ 2000.f,
	/* [98] = */ 2336.f,
	/* [99] = */ 2800.f,
	/* [100] = */ 3504.f,
	/* [101] = */ 4000.f,
	/* [102] = */ 4672.f,
	/* [103] = */ 5600.f,
	/* [104] = */ 7008.f,
	/* [105] = */ 8000.f,
	/* [106] = */ 9344.f,
	/* [107] = */ 11200.f,
	/* [108] = */ -1.f,
	/* [109] = */ -1.f,
	/* [110] = */ -1.f,
	/* [111] = */ -1.f,
	/* [112] = */ -1.f,
	/* [113] = */ -1.f,
	/* [114] = */ -1.f,
	/* [115] = */ -1.f,
	/* [116] = */ -1.f,
	/* [117] = */ -1.f,
	/* [118] = */ -1.f,
	/* [119] = */ -1.f,
	/* [120] = */ -1.f,
	/* [121] = */ -1.f,
	/* [122] = */ -1.f,
	/* [123] = */ -1.f,
	/* [124] = */ -1.f,
	/* [125] = */ -1.f,
	/* [126] = */ -1.f,
	/* [127] = */ 999999.f
};

static snd_t snd = {
	/* .cursound = */ 0,
	/* .envelope = */ NULL
};

static menu_t soundselect_menu = {
	/* .numitems = */ 21,
	/* .baseleft = */ 128,
	/* .basetop = */ 22,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t soundselect_menuitems[0] = {
};

static int first_sound = 0;

static pageinit_t soundselect_page = {
	/* .tick = */ soundselect_pageTick,
	/* .draw_before = */ soundselect_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t message_page = {
	/* .tick = */ message_pageTick,
	/* .draw_before = */ message_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static gvdisp disp_vol[0] = {
};

static gamevar gv_volume = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 100,
	/* .flags = */ 1,
	/* .display = */ disp_vol,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

static menu_t main_menu = {
	/* .numitems = */ 12,
	/* .baseleft = */ 64,
	/* .basetop = */ 44,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0000[0] = {
};

static pageinit_t main_page = {
	/* .tick = */ main_pageTick,
	/* .draw_before = */ main_pageDraw,
	/* .initfocusid = */ 2,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static u16 pitches[576];
static u8 msgbox_msg[1024];
static msgfunc_t msgbox_func;
static u32 msgbox_colour;

static void calcPitches() {
	u16 *p;
	int o;
	int n;
	int s;
	float note;
}

static int getNote(u16 pitch) {
	int i;
}

static void setcursound(int num) {}

static void sounddataSave() {
	char *filename;
	char tempname[1000];
	u8 *buffer;
	u8 *buffer_write;
	int i;
	sound *s;
	s16 *envelope;
}

static void menutick(pagedef_t *page, menu_t *menu) {
	int i;
	menuitem_t *mi;
	menulist_t *ml;
	menulist_t *ml;
	menuitem_t *firstitem;
	int index;
	int mod;
}

static void pagedrawbg(pagedef_t *page, u8 *title) {
	int font;
	int minx;
	int miny;
	int maxx;
	int maxy;
	int x;
	int y;
	int w;
	int h;
	rect_t s;
	hitbox_t *box;
	int x1;
	int y1;
}

static void soundselect_pageDraw(pagedef_t *page) {}

static void soundselect_pageTick(pagedef_t *page) {
	static u8 nums[64];
	int i;
}

static void message_pageDraw(pagedef_t *page) {
	int x;
	int y;
}

static boolean defaultmessagetick() {}

static void message_pageTick(pagedef_t *page) {}

static void startMessage(u8 *text, u32 colour, msgfunc_t msgfunc) {
	int i;
	rect_t s;
	int w;
	int h;
}

static void envelope_draw(hitbox_t *box) {
	int x;
	int y;
	int x2;
	int y2;
}

static void adsrvalue_draw(hitbox_t *box) {
	int x;
	int y;
	int envtype;
	int value;
	float f;
	u8 s[16];
}

static void main_pageDraw(pagedef_t *page) {
	int i;
	int n;
	hitbox_t *box;
	int x;
	int y;
	char *s;
	int fine;
	int note;
	int oct;
}

static void main_pageTick(pagedef_t *page) {
	int note;
	hitbox_t *box;
}

void soundtoolStart() {}
