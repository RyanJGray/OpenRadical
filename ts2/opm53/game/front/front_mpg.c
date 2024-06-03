// STATUS: NOT STARTED

#include "front_mpg.h"

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	FEANIM_NULL = 0,
	FEANIM_GUNTAGGEDALL = 1,
	FEANIM_GUNTAGGEDACT = 2,
	FEANIM_PROPTAGGEDACT = 3,
	FEANIM_PROPTAGGEDALL = 4
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	MODE_INIT = 0,
	MODE_DEMO = 1,
	MODE_STORY = 2,
	MODE_ARCADE = 3,
	MODE_CHALLENGE = 4,
	MODE_MAPMAKER = 5,
	MODE_CREDITS = 6,
	MODE_ILINK = 7
};

struct mpg_s {
	int lastmode;
	int flags;
	int tdflags[4];
	int delay;
	int curgametype;
	int curstorylevel;
	int curarcadelevel;
	int curarcadelevelnum;
	int curchallenge;
	int curgamemode;
	int democountdown;
	int numgamemodes;
	int testingupdate;
	u8 allowedteams[4];
};

typedef mpg_s mpg_t;

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	state_signon_init = 1,
	state_signon_main = 2,
	state_signon_re_edit = 3,
	state_signon_edit_run = 4,
	state_signon_ready = 5
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	state_chrselect_init = 1,
	state_chrselect_model = 2,
	state_chrselect_handicap = 3,
	state_chrselect_team = 4,
	state_chrselect_ready = 5,
	state_chrselect_zzz = 6
};

struct menutree_s {
	char *title;
	void *data;
};

typedef menutree_s menutree;

struct splitmsg_s {
	int id;
	u8 text[256];
};

typedef splitmsg_s splitmsg_t;

struct msgboxinfo_s {
	u8 msg[1024];
	msgfunc_t func;
	u32 colour;
	int control;
	int state;
};

typedef msgboxinfo_s msgboxinfo_t;

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	SIGNONLOAD_BUSY = 0,
	SIGNONLOAD_OK = 1,
	SIGNONLOAD_CANCELLED = 2
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	SOUPSTATE_INIT = 0,
	SOUPSTATE_WAITCARD_NEWSIGNONTOSAVETO = 1,
	SOUPSTATE_NEWSIGNONTOSAVETO_1 = 2,
	SOUPSTATE_NEWSIGNONTOSAVETO_2 = 3,
	SOUPSTATE_WAITCARD_NEWSIGNON_SAVING = 4,
	SOUPSTATE_NEWSIGNONSAVE_DONE = 5,
	SOUPSTATE_WAITCARD_VERIFCARD = 6,
	SOUPSTATE_WAITCARD_UPDATING = 7,
	SOUPSTATE_UPDATING_DONE = 8,
	SOUPSTATE_ERROR_MESSAGE = 9,
	SOUPSTATE_MESSAGE = 10
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	SIGNONUPDATE_BUSY = 0,
	SIGNONUPDATE_OK = 1,
	SIGNONUPDATE_CANCELLED = 2
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	SOUPSTATE_DELETE_INIT = 0,
	SOUPSTATE_DELETE_WAITCARD = 1,
	SOUPSTATE_DELETE_WAITCARD_DELETING = 2,
	SOUPSTATE_DELETE_ERROR_MESSAGE = 3,
	SOUPSTATE_DELETE_MESSAGE = 4
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	SIGNONDELETE_BUSY = 0,
	SIGNONDELETE_OK = 1,
	SIGNONDELETE_CANCELLED = 2
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	we_list = 1,
	we_weaponset = 2,
	we_info = 3,
	we_back = 4,
	we_last = 5
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	COL_CHR = 0,
	COL_TEAM = 1,
	COL_SKILL = 2,
	COL_ACTIVE = 3,
	CHRGRID_COLS = 4
};

struct chrsel_s {
	int chr;
	int team;
	int skill;
	int active;
};

typedef chrsel_s chrsel_t;

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	cs_chrset = 1,
	cs_list = 2,
	cs_grid = 3,
	cs_info = 4,
	cs_back = 5,
	cs_last = 6
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	av_musicon = 1,
	av_musicvol = 2,
	av_soundon = 3,
	av_soundvol = 4,
	av_dispx = 5,
	av_back = 6,
	av_last = 7
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	chrsel_main_model = 1,
	chrsel_main_info = 2,
	chrsel_main_num = 3
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	chrsel_handicap_gv = 1,
	chrsel_handicap_back = 2,
	chrsel_handicap_num = 3
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	chrsel_team_team = 1,
	chrsel_team_back = 2,
	chrsel_team_num = 3
};

struct gmoptions_s {
	int gv_teamplay;
	int gv_friendfire;
	int gv_dispradar;
	int gv_timelimit;
	int gv_killlimit;
	int gv_scorelimit;
	int gv_scoremethod;
	int gv_oneshotkill;
};

typedef gmoptions_s gmoptions_t;

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	ao_t1 = 1,
	ao_option1 = 2,
	ao_option2 = 3,
	ao_option3 = 4,
	ao_option4 = 5,
	ao_option5 = 6,
	ao_option6 = 7,
	ao_option7 = 8,
	ao_option8 = 9,
	ao_option9 = 10,
	ao_option10 = 11,
	ao_weaponset = 12,
	ao_botset = 13,
	ao_ok = 14,
	ao_back = 15,
	ao_more = 16,
	ao_last = 17
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	cht_list = 1,
	cht_back = 2,
	cht_last = 3
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	mf_init_load_dir = 0,
	mf_init_load_wait = 1,
	mf_init_poll_start = 2,
	mf_init_make_menu = 3,
	mf_main = 4,
	mf_load_map_wait = 5
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	ar_tileset = 1,
	ar_level = 2,
	ar_gamemode1 = 3,
	ar_gamemode2 = 4,
	ar_gamemode3 = 5,
	ar_gamemode4 = 6,
	ar_gamemode5 = 7,
	ar_gamemode6 = 8,
	ar_back = 9,
	ar_more = 10,
	ar_cheat = 11,
	ar_last = 12
};

struct gmtab_s {
	u8 gamemode;
	u8 setupflags;
};

typedef gmtab_s gmtab_t;

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	storychrsel_main_model = 1,
	storychrsel_main_ready = 2,
	storychrsel_main_last = 3
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	st_level = 1,
	st_skill1 = 2,
	st_skill2 = 3,
	st_skill3 = 4,
	st_back = 5,
	st_more = 6,
	st_cheat = 7,
	st_last = 8
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	ch_num = 1,
	ch_desc = 2,
	ch_back = 3,
	ch_more = 4,
	ch_last = 5
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	il_back = 0,
	il_more = 1,
	il_last = 2
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	sta_player = 1,
	sta_statgametype = 2,
	sta_statcat = 3,
	sta_back = 4,
	sta_last = 5
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	gt_story = 1,
	gt_arcade = 2,
	gt_challenge = 3,
	gt_ilink = 4,
	gt_credits = 5,
	gt_statistics = 6,
	gt_audiovideo = 7,
	gt_save = 8,
	gt_back = 9,
	gt_more = 10,
	gt_last = 11
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	so_new = 2000,
	so_load = 2001
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	MSGID_DELETE = 1,
	MSGID_DUPLICATE = 2
};

// warning: multiple differing types with the same name (#74,  not equal)
enum {
	np_one = 1,
	np_two = 2,
	np_three = 3,
	np_four = 4,
	np_last = 5
};

static int fe_animation_list[50][5] = {
	/* [0] = */ {
		/* [0] = */ 166,
		/* [1] = */ 166,
		/* [2] = */ 166,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [1] = */ {
		/* [0] = */ 166,
		/* [1] = */ 166,
		/* [2] = */ 166,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [2] = */ {
		/* [0] = */ 166,
		/* [1] = */ 166,
		/* [2] = */ 166,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [3] = */ {
		/* [0] = */ 166,
		/* [1] = */ 166,
		/* [2] = */ 166,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [4] = */ {
		/* [0] = */ 166,
		/* [1] = */ 166,
		/* [2] = */ 166,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [5] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [6] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [7] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [8] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [9] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [10] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [11] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [12] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [13] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [14] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [15] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [16] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [17] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [18] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [19] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [20] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [21] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [22] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [23] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [24] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [25] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [26] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [27] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [28] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [29] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [30] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [31] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [32] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [33] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [34] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [35] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [36] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [37] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [38] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [39] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [40] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [41] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [42] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [43] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [44] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [45] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [46] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [47] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [48] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* [49] = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	}
};

static int fe_propanim[0][4] = {
};

static u8 characterorder[0] = {
};

static prop *gun[4] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL
};

static prop *gun2[4] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL
};

static prop *testprop = NULL;

static int gundrawflag[4] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0
};

static int gundrawflag2[4] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0
};

static int propdrawflag[4] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0
};

static prop *stage[4] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL
};

gamevar gv_playmusic = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_onoff,
	/* .onChange = */ musicvolume_onchange,
	/* .suffix = */ NULL,
	/* .marginright = */ 352,
	/* .arrowleftofs = */ -64,
	/* .arrowrightofs = */ 0
};

gamevar gv_playsound = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_onoff,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 352,
	/* .arrowleftofs = */ -64,
	/* .arrowrightofs = */ 0
};

gamevar gv_musicvolume = {
	/* .value = */ 16,
	/* .min = */ 0,
	/* .max = */ 16,
	/* .flags = */ 1,
	/* .display = */ NULL,
	/* .onChange = */ musicvolume_onchange,
	/* .suffix = */ NULL,
	/* .marginright = */ 352,
	/* .arrowleftofs = */ -64,
	/* .arrowrightofs = */ 0
};

gamevar gv_soundvolume = {
	/* .value = */ 16,
	/* .min = */ 0,
	/* .max = */ 16,
	/* .flags = */ 1,
	/* .display = */ NULL,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 352,
	/* .arrowleftofs = */ -64,
	/* .arrowrightofs = */ 0
};

static gamevar gv_dispx = {
	/* .value = */ 0,
	/* .min = */ -64,
	/* .max = */ 64,
	/* .flags = */ 1,
	/* .display = */ NULL,
	/* .onChange = */ displayoffsetx_onchange,
	/* .suffix = */ NULL,
	/* .marginright = */ 352,
	/* .arrowleftofs = */ -64,
	/* .arrowrightofs = */ 0
};

static gamevar gv_teamplay = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_friendfire = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_useteamstarts = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_bagshoot = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_dispradar = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_timelimit = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 120,
	/* .flags = */ 1,
	/* .display = */ disp_none,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_killlimit = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1000000,
	/* .flags = */ 1,
	/* .display = */ disp_none,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gvdisp disp_scorem[0] = {
};

static gamevar gv_scoremethod = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_scorem,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_scorelimit = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1000000,
	/* .flags = */ 1,
	/* .display = */ disp_none,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_oneshotkill = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_handicaps = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_spawngun = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -160,
	/* .arrowrightofs = */ 0
};

static gamevar gv_weaponset = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 10,
	/* .flags = */ 0,
	/* .display = */ disp_wpsets,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -256,
	/* .arrowrightofs = */ 0
};

static gamevar gv_chrset = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 10,
	/* .flags = */ 0,
	/* .display = */ disp_chrset,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ -256,
	/* .arrowrightofs = */ 0
};

static pageinit_t message_page = {
	/* .tick = */ message_pageTick,
	/* .draw_before = */ message_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static int gunzlistrowtop = 0;
static int gunzlistrow = 0;

static gunset gunzpack = {
	/* .name = */ 0,
	/* .numguns = */ 5,
	/* .guncombo = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1,
		/* [3] = */ -1,
		/* [4] = */ -1,
		/* [5] = */ 0,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 0,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 0,
		/* [14] = */ 0
	}
};

static menu_t weapons_menu = {
	/* .numitems = */ 4,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0600[0] = {
};

static pageinit_t weapons_page = {
	/* .tick = */ weapons_pageTick,
	/* .draw_before = */ weapons_pageDraw,
	/* .initfocusid = */ 2,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t chrsets_menu = {
	/* .numitems = */ 5,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0500[0] = {
};

static pageinit_t chrsets_page = {
	/* .tick = */ chrsets_pageTick,
	/* .draw_before = */ chrsets_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t audiovideo_menu = {
	/* .numitems = */ 6,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i04b00[0] = {
};

static pageinit_t audiovideo_page = {
	/* .tick = */ audiovideo_pageTick,
	/* .draw_before = */ audiovideo_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t chrselect_ready_waiting = {
	/* .numitems = */ 2,
	/* .baseleft = */ 64,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0903[0] = {
};

static menu_t chrselect_ready_go = {
	/* .numitems = */ 2,
	/* .baseleft = */ 64,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0903b[0] = {
};

static menu_t chrselect_main_menu = {
	/* .numitems = */ 2,
	/* .baseleft = */ 0,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0901[0] = {
};

static menu_t chrselect_main_menu_p234 = {
	/* .numitems = */ 2,
	/* .baseleft = */ 0,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0901b[0] = {
};

static menu_t chrselect_handicap_menu = {
	/* .numitems = */ 2,
	/* .baseleft = */ 0,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0905[0] = {
};

static menu_t chrselect_team_menu = {
	/* .numitems = */ 2,
	/* .baseleft = */ 0,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0904[0] = {
};

static pageinit_t chrplayer_page = {
	/* .tick = */ chrplayer_pageTick,
	/* .draw_before = */ chrplayer_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t characterselect_page = {
	/* .tick = */ characterselect_pageTick,
	/* .draw_before = */ characterselect_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ characterselect_pageDrawAfter,
	/* .construct = */ NULL
};

static menuitem_t null_menuitem = {
	/* .text = */ NULL,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 0,
	/* .flags = */ 0,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menu_t arcadeoptions_menu = {
	/* .numitems = */ 16,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0410[0] = {
};

static menuitem_t bagtag_menuitems[0] = {
};

static menuitem_t ctf_menuitems[0] = {
};

static menuitem_t deathmatch_menuitems[0] = {
};

static menuitem_t escort_menuitems[0] = {
};

static menuitem_t knockout_menuitems[0] = {
};

static menuitem_t laststand_menuitems[0] = {
};

static pageinit_t arcadeoptions_page = {
	/* .tick = */ arcadeoptions_pageTick,
	/* .draw_before = */ arcadeoptions_pageDraw,
	/* .initfocusid = */ 14,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static gamevar gv_cheat = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_onoff,
	/* .onChange = */ cheatOnChange,
	/* .suffix = */ NULL,
	/* .marginright = */ 412,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

static menulist_t cheats_list = {
	/* .numitems = */ 0,
	/* .numdisplay = */ 64870,
	/* .baseleft = */ 96,
	/* .basetop = */ 38,
	/* .flags = */ 0,
	/* .selected = */ 0,
	/* .firstdisplay = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	}
};

static menuitem_t cheats_mi[15] = {
	/* [0] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [1] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [2] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [3] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [4] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [5] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [6] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [7] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [8] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [9] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [10] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [11] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [12] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [13] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [14] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	}
};

static menu_t cheats_menu = {
	/* .numitems = */ 2,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i02000[0] = {
};

static pageinit_t cheats_page = {
	/* .tick = */ cheats_pageTick,
	/* .draw_before = */ cheats_pageDraw,
	/* .initfocusid = */ 1000,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static int firstmap = 0;

static menu_t mapfile_menu = {
	/* .numitems = */ -666,
	/* .baseleft = */ 80,
	/* .basetop = */ 40,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mfmi[14] = {
	/* [0] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [1] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [2] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [3] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [4] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [5] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [6] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [7] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [8] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [9] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [10] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [11] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [12] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [13] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	}
};

static menuitem_t mi_dirtop = {
	/* .text = */ titletop,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 0,
	/* .flags = */ 512,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mi_dirfile = {
	/* .text = */ NULL,
	/* .left = */ 26,
	/* .top = */ 0,
	/* .id = */ 0,
	/* .flags = */ 0,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mi_dirempty = {
	/* .text = */ 0x11f,
	/* .left = */ 0,
	/* .top = */ 40,
	/* .id = */ 0,
	/* .flags = */ 0,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mi_dirback = {
	/* .text = */ 0x21d,
	/* .left = */ 0,
	/* .top = */ 140,
	/* .id = */ 0,
	/* .flags = */ 0,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static pageinit_t arcade_mmload_page = {
	/* .tick = */ arcade_mmload_pageTick,
	/* .draw_before = */ arcade_mmload_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static int arcadelevels[19] = {
	/* [0] = */ 26,
	/* [1] = */ 16,
	/* [2] = */ 21,
	/* [3] = */ 13,
	/* [4] = */ 14,
	/* [5] = */ 11,
	/* [6] = */ 2,
	/* [7] = */ 22,
	/* [8] = */ 5,
	/* [9] = */ 15,
	/* [10] = */ 9,
	/* [11] = */ 17,
	/* [12] = */ 8,
	/* [13] = */ 18,
	/* [14] = */ 24,
	/* [15] = */ 10,
	/* [16] = */ 27,
	/* [17] = */ 12,
	/* [18] = */ 100
};

static gmtab_t gmtab[6] = {
	/* [0] = */ {
		/* .gamemode = */ 3,
		/* .setupflags = */ 4
	},
	/* [1] = */ {
		/* .gamemode = */ 1,
		/* .setupflags = */ 1
	},
	/* [2] = */ {
		/* .gamemode = */ 2,
		/* .setupflags = */ 2
	},
	/* [3] = */ {
		/* .gamemode = */ 5,
		/* .setupflags = */ 16
	},
	/* [4] = */ {
		/* .gamemode = */ 4,
		/* .setupflags = */ 8
	},
	/* [5] = */ {
		/* .gamemode = */ 6,
		/* .setupflags = */ 32
	}
};

static gamevar gv_tileset = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 4,
	/* .flags = */ 0,
	/* .display = */ disp_tilesets,
	/* .onChange = */ tileset_onchange,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ -176,
	/* .arrowrightofs = */ 0
};

static menu_t arcade_menu1 = {
	/* .numitems = */ 11,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0400[0] = {
};

static pageinit_t arcade_page = {
	/* .tick = */ arcade_pageTick,
	/* .draw_before = */ arcade_pageDraw,
	/* .initfocusid = */ 3,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t storychrsel_menu = {
	/* .numitems = */ 2,
	/* .baseleft = */ 64,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0450[0] = {
};

static pageinit_t storychrsel_page = {
	/* .tick = */ storychrsel_pageTick,
	/* .draw_before = */ storychrsel_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t storychr_page = {
	/* .tick = */ storychr_pageTick,
	/* .draw_before = */ storychr_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t story_menu = {
	/* .numitems = */ 7,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0440[0] = {
};

static pageinit_t story_page = {
	/* .tick = */ story_pageTick,
	/* .draw_before = */ story_pageDraw,
	/* .initfocusid = */ 2,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t challengechr_page = {
	/* .tick = */ challengechr_pageTick,
	/* .draw_before = */ challengechr_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t challenge_menu = {
	/* .numitems = */ 4,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0700[0] = {
};

static pageinit_t challenge_page = {
	/* .tick = */ challenge_pageTick,
	/* .draw_before = */ challenge_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t ilink_menu = {
	/* .numitems = */ 1,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0800[0] = {
};

static pageinit_t ilink_page = {
	/* .tick = */ ilink_pageTick,
	/* .draw_before = */ ilink_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static gamevar gv_statsplayer = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 3,
	/* .flags = */ 0,
	/* .display = */ disp_statsplayer,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

static gamevar gv_statstype = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 3,
	/* .flags = */ 0,
	/* .display = */ disp_statstype,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

static gamevar gv_statscat = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_statscat,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

static menu_t statistics_menu = {
	/* .numitems = */ 4,
	/* .baseleft = */ 32,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i01000[0] = {
};

static pageinit_t statistics_page = {
	/* .tick = */ statistics_pageTick,
	/* .draw_before = */ statistics_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t gamemode_menu = {
	/* .numitems = */ 10,
	/* .baseleft = */ 64,
	/* .basetop = */ 32,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0300[0] = {
};

static pageinit_t gametype_page = {
	/* .tick = */ gametype_pageTick,
	/* .draw_before = */ gametype_pageDraw,
	/* .initfocusid = */ 2,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t signon_ready_waiting = {
	/* .numitems = */ 2,
	/* .baseleft = */ 64,
	/* .basetop = */ 140,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0201[0] = {
};

static menulist_t signonplr_list = {
	/* .numitems = */ 64870,
	/* .numdisplay = */ 6,
	/* .baseleft = */ 64,
	/* .basetop = */ 0,
	/* .flags = */ 0,
	/* .selected = */ 0,
	/* .firstdisplay = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	}
};

static menuitem_t somi[146] = {
	/* [0] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [1] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [2] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [3] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [4] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [5] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [6] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [7] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [8] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [9] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [10] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [11] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [12] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [13] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [14] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [15] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [16] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [17] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [18] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [19] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [20] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [21] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [22] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [23] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [24] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [25] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [26] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [27] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [28] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [29] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [30] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [31] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [32] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [33] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [34] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [35] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [36] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [37] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [38] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [39] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [40] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [41] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [42] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [43] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [44] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [45] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [46] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [47] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [48] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [49] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [50] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [51] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [52] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [53] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [54] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [55] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [56] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [57] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [58] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [59] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [60] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [61] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [62] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [63] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [64] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [65] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [66] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [67] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [68] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [69] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [70] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [71] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [72] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [73] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [74] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [75] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [76] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [77] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [78] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [79] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [80] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [81] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [82] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [83] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [84] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [85] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [86] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [87] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [88] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [89] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [90] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [91] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [92] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [93] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [94] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [95] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [96] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [97] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [98] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [99] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [100] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [101] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [102] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [103] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [104] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [105] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [106] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [107] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [108] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [109] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [110] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [111] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [112] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [113] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [114] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [115] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [116] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [117] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [118] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [119] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [120] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [121] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [122] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [123] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [124] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [125] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [126] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [127] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [128] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [129] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [130] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [131] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [132] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [133] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [134] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [135] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [136] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [137] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [138] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [139] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [140] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [141] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [142] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [143] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [144] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	},
	/* [145] = */ {
		/* .text = */ NULL,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .id = */ 0,
		/* .flags = */ 0,
		/* .data = */ NULL,
		/* .next = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .spare = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL
		}
	}
};

static menuitem_t mi_signon = {
	/* .text = */ NULL,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 0,
	/* .flags = */ 0,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mi_signonnew = {
	/* .text = */ 0x178,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 2000,
	/* .flags = */ 64,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mi_signonload = {
	/* .text = */ 0x179,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 2001,
	/* .flags = */ 64,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menu_t signonplr_menu = {
	/* .numitems = */ 1,
	/* .baseleft = */ 64,
	/* .basetop = */ 0,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0200[0] = {
};

static pageinit_t signonplr_page = {
	/* .tick = */ signonplr_pageTick,
	/* .draw_before = */ signonplr_pageDraw,
	/* .initfocusid = */ 2001,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t signon_page = {
	/* .tick = */ signon_pageTick,
	/* .draw_before = */ signon_pageDrawBefore,
	/* .initfocusid = */ 2001,
	/* .pad = */ 0,
	/* .draw_after = */ signon_pageDrawAfter,
	/* .construct = */ NULL
};

static pageinit_t demosplash_page = {
	/* .tick = */ demosplash_pageTick,
	/* .draw_before = */ demosplash_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t nplayers_menu = {
	/* .numitems = */ 4,
	/* .baseleft = */ 0,
	/* .basetop = */ 186,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t i0100[0] = {
};

static pageinit_t nplayers_page = {
	/* .tick = */ nplayers_pageTick,
	/* .draw_before = */ nplayers_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t statsupdate_page = {
	/* .tick = */ statsupdate_pageTick,
	/* .draw_before = */ statsupdate_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t goodies_page = {
	/* .tick = */ goodies_pageTick,
	/* .draw_before = */ goodies_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static u8 curdemo = 1;

window_t frontendWindow = {
	/* .left = */ 0,
	/* .right = */ 0,
	/* .midx = */ 0,
	/* .width = */ 0,
	/* .halfwidth = */ 0,
	/* .top = */ 0,
	/* .bottom = */ 0,
	/* .midy = */ 0,
	/* .height = */ 0,
	/* .halfheight = */ 0,
	/* .scalex = */ 0.f,
	/* .scaley = */ 0.f,
	/* .scaleshiftx = */ 0,
	/* .scaleshifty = */ 0,
	/* .zbufferrange = */ 0.f,
	/* .zbufferoffset = */ 0.f,
	/* .zbufferbias = */ 0.f
};

static int animplayed[4][50];
static mpg_t mpg;
static int frontmpg_numplayers;
static u8 state[4];
static prop *chrprops[4];
static float fxStageScalar[4];
static float fxStageOffset[4];
static int fxStageDirection[4];
static float fxStageSpeed[4];
static int fxCurChr[4];
static int fxNewChr[4];
static int fxSelect[4];
static int fxCameraFlash[4];
static float fxCameraFlashScalar[4];
static int fxStageSkip[4];
static float fxStageAlt[4];
static int actingsound[4];
static menutree mtree[16];
static int mtreepos;
static char mtreetitle[256];
static splitmsg_t splitmsgs[4];
static u16 tofocus[4];
static resetgameparms gameparms;
static gvdisp disp_wpsets[12];
static gvdisp disp_chrset[12];
static msgboxinfo_t msgboxes[4];
static int so_player;
static memcarddata_t *signon_buf;
static u8 signonload;
static u32 signonloadfileid;
static u8 signondelete;
static u8 signontodelete;
static u8 signonsave;
static u8 soupstate;
static int gunzlist[40];
static int gunzlistnum;
static chrsel_t chrsel[10];
static s8 custombotsets[3][10];
static int chrlist[50];
static int chrlistnum;
static int chrmovefromrow;
static int chrmovefromcol;
static int chrgridrow;
static int chrgridcol;
static int chrlistrowtop;
static int chrlistrow;
static int chrgridfirstcol;
static int chrselflags;
static int playerteams[4];
static gmoptions_t gmoptions[9];
static gamevar gv_cheats[15];
static int numdispfiles;
static u8 titletop[64];
static u8 dispfiles[10][34];
static u8 mfstate;
static mapentry_t entryinfo;
static int entrynum;
static int curmapentry;
static int ilinkPageTimer;
static boolean ilinkPageSentSignons;
static boolean ilinkPageReadyToStart;
static gvdisp disp_statsplayer[5];
static gvdisp disp_statstype[5];
static gvdisp disp_statscat[3];
static u8 buftest[128];
static u16 lastfocus[4];
static u8 plrnewname[4][30];
static u8 signontobedeleted[4];
static u8 signonmessage;
static u8 signonids[144];
static rect_t sozoomfrom;
static int sozoomframes;
static int sozoomstarted;
static u32 goodies_cheats;
static u32 goodies_levels;
static u32 goodies_availablechrs[3];
static u32 goodies_playablechrs[3];
static int goodies_botsets;
static u8 goodies_misc;
static int goodiemsgtimer;
static u8 *goodiemsg;

static void setStates(u8 statenum) {}

static void makemtreeTitle() {
	int i;
	u8 *s;
}

static void pageRoot() {}

static void pageOut() {
	int i;
}

static void pageIn(pagedef_t *page) {}

static void pageSetTitle(u8 *title) {}

static void pageSet(u8 *title, void *data) {}

static void menutick(pagedef_t *page, menu_t *menu) {
	int i;
	menuitem_t *mi;
	menulist_t *ml;
	menuitem_t *firstitem;
	int index;
	int mod;
}

static void pagebackgroundGfx(pagedef_t *page) {
	int font;
	rect_t s;
	int state;
	hitbox_t *box;
	int h;
	u8 *s;
	int x1;
	int y1;
	int on;
	u32 fgcol;
}

static void splitMessageStart(int playernum, int id, u8 *message) {
	splitmsg_t *sm;
}

static void splitMessageClear(int playernum) {
	splitmsg_t *sm;
}

static void splitMessageDraw(int playernum) {
	splitmsg_t *sm;
	rect_t p;
}

static int splitMessageTick(int playernum) {
	static int joybutton[4] = {
		/* [0] = */ 32,
		/* [1] = */ 64,
		/* [2] = */ 16,
		/* [3] = */ 128
	};
	splitmsg_t *sm;
	int i;
	int button;
}

static void SetWindow(int playernum, int nviews, boolean gfx) {
	int win[4];
	int height;
	int basey;
}

static void splitpageDraw(pagedef_t *basepage, pageinit_t *splitpage) {
	int i;
}

static void splitpageTick(pagedef_t *basepage, pageinit_t *splitpage) {
	int i;
}

static void splitpageInit(pageinit_t *splitpage) {
	int i;
}

static void displayoffsetx_onchange(gamevar *gv, int oldvalue) {}

static void musicvolume_onchange(gamevar *gv, int oldvalue) {}

static u8* cheatOption(u32 menucheats) {}

static int messageGetState(int playernum) {}

static void message_pageDraw(pagedef_t *page) {
	msgboxinfo_t *mb;
}

static boolean defaultmessagetick(int control) {}

static void message_pageTick(pagedef_t *page) {
	msgboxinfo_t *mb;
}

static void frontStartMessage(int control, u8 *text, u32 colour, msgfunc_t msgfunc) {
	msgboxinfo_t *mb;
	int i;
	rect_t s;
	int w;
	int h;
}

static u8* GetPlayerDialogTitle(int playernum, u8 *title) {
	static u8 sDialogTitle[256];
}

static u8* GetPlayerSignOnMessage(int playernum, u8 *message) {
	static u8 sDialogMessage[256];
	u8 sSaveMessage[256];
}

static void signonLoadRetry(int playernum) {
	u8 *sTitle;
}

static void signonLoadStart(int playernum) {}

static void corruptLoadMessage(int playernum) {}

static boolean signonLoadTick(int playernum) {
	int msgdone;
	u8 *msg;
	gamefile1_t *sofile;
	int i;
	int reloaded;
	u8 *msg;
}

static void signonUpdateStart(int playernum) {}

static int signonUpdateTick(int playernum) {
	int msgdone;
	int sonum;
	u8 *sDialogTitle;
	int mcardfrom;
	u8 *msg;
	gamefile1_t *sofile;
	gamefile1_t *sofile;
	int index;
	gamefile1_t *sofile;
	gamefile1_t *sofile;
	int index;
}

static void signonDeleteStart(int playernum) {}

static boolean signonDeleteTick(int playernum) {
	int msgdone;
	int index;
}

int frontmpgGetGunComboNum(int levelgun) {
	gunset *gunset;
}

static boolean weaponsetAvail(int arcadegunset) {
	unlockcondition_t unlockbricks;
}

static void weaponSetDec() {}

static void weaponSetInc() {}

static void weapons_pageDraw(pagedef_t *page) {
	int font;
	u32 fgcol;
	u32 bgcol;
	u8 *s;
	int i;
	u32 colours[5];
	gunset *gunset;
	int gunnum;
	u8 s[2];
	int y;
	int row;
	int x1;
	int y1;
	int row;
}

static boolean checkNoGuns() {}

static void weapons_pageTick(pagedef_t *page) {
	int i;
}

static void chrsets_pageDraw(pagedef_t *page) {
	int i;
	int font;
	int x;
	int y;
	int w;
	int h;
	u32 fgcol;
	u32 bgcol;
	u32 highcol;
	u8 *s;
	int w;
	int x1;
	int y1;
	int x1;
	int y1;
	int j;
}

static void botsetInit(int chrsetnum) {
	int i;
	int c;
}

static void chrsetDec() {}

static void chrsetInc() {}

static void chrsets_pageTick(pagedef_t *page) {
	int i;
	int curchrset;
	int chrnum;
	int k;
	chrsel_t temp;
	u8 *s;
}

static void checkUnavailableThings() {
	int i;
	int j;
}

static int numAllowedTeams() {
	int i;
	int n;
}

static void checkAllowedTeams() {
	int i;
}

static int countBots(int team) {
	int i;
	int count;
}

static boolean selectableTeam(int team) {
	int otherteam;
	int playersleft;
	int i;
}

static int onlyoneselectableteam() {
	int i;
	int selteam;
	int numselteams;
}

static boolean checkOkToGo() {
	int i;
	int difteams;
}

static void drawTeamPlayers(int team, int *x, int y) {
	int j;
	int image;
}

static void drawTeamBots(int team, int *x, int y, int drawinteamcolour) {
	int j;
	int image;
	u32 fgcol;
}

static void drawBotSet(int basex, int basey) {
	u8 *s;
	int i;
}

static void drawLittleGuys() {
	int x;
	int y;
	int x1;
	int i;
	int n;
	int extra;
	int infra;
	int extrateam;
	int x1;
	int teamw;
}

static void drawWarning(int x, int y, u8 *msg) {
	u32 fgcol;
	int font;
}

static void audiovideo_pageDraw(pagedef_t *page) {
	int x1;
	int y1;
	int x2;
	int y2;
	u32 col;
	u32 col2;
}

static void audiovideo_pageTick(pagedef_t *page) {}

void tlhAdjustChrPosition(prop *p) {}

static void selectChar(int playernum, int chrtype) {
	prop *p;
	int i;
	int numsame;
}

static void rotateChar(prop *chrprop, float angle) {}

static void drawChar(prop *chrprop) {
	mtx_u rotmtx;
	float pos[3];
	int oldzbmode;
}

static void drawSelectCharArrows(int y1, u8 *string) {
	int x1;
	int defw;
}

static void drawCharName(pagedef_t *page, u16 boxid, u8 *name, boolean drawarrows) {
	int y1;
	u32 fgcol;
	u32 bgcol;
	hitbox_t *box;
}

static void chrplayer_pageDraw(pagedef_t *page) {
	playerprefs_t *pprefs;
	int chrnum;
	hitbox_t *box;
	rect_t s;
	u8 *s;
	int x1;
	int y1;
	u32 fgcol;
	u32 fgcol;
	u32 bgcol;
	u32 hicol;
	int x1;
	int y1;
	u8 *s;
	int font;
}

static void resetchrprops() {
	int i;
	int j;
	int numsame;
}

static void chrplayer_pageTick(pagedef_t *page) {
	playerprefs_t *pprefs;
	menu_t *buildmenu;
	int i;
	int i;
	int oneteam;
	int i;
}

static void characterselect_pageDraw(pagedef_t *page) {}

static void characterselect_pageDrawAfter(pagedef_t *page) {}

static void characterselect_pageTick(pagedef_t *page) {
	int i;
	playerprefs_t *pprefs;
}

static void fxCreateStage(int i) {}

static void fxSelectCharReset() {
	int i;
	manualLighting *lighting;
}

static void fxSelectCharLeft(int story) {
	playerprefs_t *pprefs;
	storyinfo_t *si;
	int i;
}

static void fxSelectCharRight(int story) {
	playerprefs_t *pprefs;
	storyinfo_t *si;
	int i;
}

static void actingsoundStop(int player) {}

static void fxSelectCharInit(int player, int newchr) {}

static void fxSelectCharTick(int story) {
	playerprefs_t *pprefs;
	manualLighting *lighting;
	manualLighting *lighting;
}

static void fxSelectCharGfx() {
	float topshutter;
	float bottomshutter;
	float scale;
	int alpha;
}

static void fxSelectCharFlashInit(int player) {}

static void gameoptionsMake() {
	int i;
	gmoptions_t *gmo;
}

static void getGameModeOptions(int gamemode) {
	gmoptions_t *s;
}

static void storeGameModeOptions(int gamemode) {
	gmoptions_t *s;
}

static void arcadeoptions_pageDraw(pagedef_t *page) {}

static void arcadeoptions_pageTick(pagedef_t *page) {
	int i;
	menuitem_t *dest;
	menuitem_t *src;
	int numsrc;
	u8 *s;
	int j;
}

static void cheatOnChange(gamevar *gv, int oldvalue) {
	int cheatbit;
}

static void cheats_pageDraw(pagedef_t *page) {
	int x1;
	int y1;
	u32 fgcol;
}

static void cheats_pageTick(pagedef_t *page) {
	int i;
	int n;
	int numselectedcheats;
	menuitem_t *mi;
	int cheatsinmenu;
	u8 *pagetitle;
}

static void arcade_mmload_pageDraw(pagedef_t *page) {
	rect_t s;
	int i;
	hitbox_t *box;
	u32 arrowcol;
	u8 *stime;
	int y;
}

static void arcade_mmload_pageTick(pagedef_t *page) {
	int i;
	int y;
	menuitem_t *mi;
	int l;
	int i;
}

static void tileset_onchange(gamevar *gv, int oldvalue) {}

static void arcade_pageDraw(pagedef_t *page) {
	int font;
	int x1;
	int y1;
	hitbox_t *box;
	u8 *s;
	mmfileinfo *mminfo;
}

static void arcade_pageTick(pagedef_t *page) {
	int gamemodelist[6];
	int i;
	int left;
	int right;
	int numoptions;
	s16 ypos;
	u8 *s;
	setupheader *setup;
	menuitem_t *mi;
	resetgameparms p;
}

static void storychrsel_pageDraw(pagedef_t *page) {
	playerprefs_t *pprefs;
}

static void storychrsel_pageTick(pagedef_t *page) {
	playerprefs_t *pprefs;
	menu_t *buildmenu;
	int i;
}

static void storychr_pageDraw(pagedef_t *page) {}

static void storychr_pageTick(pagedef_t *page) {
	int i;
	playerprefs_t *pprefs;
	storyinfo_t *si;
}

static void story_pageDraw(pagedef_t *page) {
	int font;
	int i;
	u32 fgcol;
	int x1;
	int y1;
	int x;
	u8 *s;
	int time;
	int levelnum;
}

static boolean storyDifficultyAvail(int storylevel, int difficulty) {
	int i;
	int start;
	unlockcondition_t uc;
}

static void story_pageTick(pagedef_t *page) {
	menuitem_t *mi;
	u8 *s;
	int left;
	int right;
	int i;
}

static void challengechr_pageDraw(pagedef_t *page) {
	int chrnum;
}

static void challengechr_pageTick(pagedef_t *page) {
	menu_t *buildmenu;
	int chrnum;
}

static void challenge_pageDraw(pagedef_t *page) {
	u32 fgcol;
	int x1;
	int y1;
	int font;
	u8 *s;
}

static void challenge_pageTick(pagedef_t *page) {}

static void ilink_pageDraw(pagedef_t *page) {
	int i;
	int x;
	int y;
	char s[256];
}

static void ilink_pageTick(pagedef_t *page) {
	int i;
	int Signon;
	int i;
	int Signon;
}

static void statistics_pageDraw(pagedef_t *page) {
	int player;
	int gametype;
	int spage;
	lifestats_t *lifestats;
	lifestats_t overallstats;
	int x;
	int y;
	u32 col;
	char *s;
	int left;
	int right;
	int favchar;
	int favchartimes;
	int e;
}

void statistics_pageDrawInfo(int left, int right, int col, lifestats_t *lifestats, int gametype, int page, int player) {
	int x;
	int y;
	char h[255];
	char *s;
	int secs;
	float successrate;
	int favlevel;
	int favlevelcount;
	int e;
	int count;
	int favgun;
	float favguntime;
	int e;
	float miles;
	float accuracy;
	int percent;
	float accuracy;
	float secs;
	float hours;
	float speed;
	int count;
	int m;
}

static void statistics_pageTick(pagedef_t *page) {
	int i;
}

static void gametype_pageDraw(pagedef_t *page) {}

static void gametype_pageTick(pagedef_t *page) {
	u8 *s;
	resetgameparms p;
}

static void makesignonmenu() {
	int so_count;
	int i;
	int j;
	int card;
	menuitem_t *mi;
	int sonum;
}

static void signonplr_pageDraw(pagedef_t *page) {
	boolean toppage;
	int font;
	char *s;
	u32 fgcol;
	u32 bgcol;
	u32 col;
	int x;
	int y;
	menuitem_t *firstitem;
	int x1;
	int y1;
	int h;
	int i;
	u32 col;
	int listindex;
	int sonum;
	int y;
	hitbox_t *b;
}

static void signonplr_pageTick(pagedef_t *page) {
	menu_t *buildmenu;
	menuitem_t *curmi;
	int i;
	int sonum;
	int i;
}

static void signon_pageDrawBefore(pagedef_t *page) {}

static void soZoomStart(int playernum) {}

static void soZoomGfx() {
	rect_t p;
}

static void signon_pageDrawAfter(pagedef_t *page) {}

static void signon_pageTick(pagedef_t *page) {
	int playernum;
	int but;
	int playernum;
	int i;
	int playernum;
	int ret;
	int sonum;
	int i;
	int n;
	u8 *errormsg;
	int playernum;
	int sonum;
	u8 *msg;
	int but;
	int i;
	int p;
	playerprefs_t *pprefs;
}

static void demosplash_pageGfx(pagedef_t *page) {}

static void demosplash_pageTick(pagedef_t *page) {}

static void nplayers_pageGfx(pagedef_t *page) {}

static void nplayers_pageTick(pagedef_t *page) {
	int i;
	int numjs;
}

static void setlastgamemodepage() {}

static boolean setStatsUpdatePage() {
	int i;
}

static void statsupdate_pageDraw(pagedef_t *page) {}

static void statsupdate_pageTick(pagedef_t *page) {
	int but;
}

static u8 goodiesGetMisc() {
	u8 misc;
}

static u32 goodiesGetLevels() {
	u32 levels;
	int i;
}

static void goodiesGetAvailableChrs(u32 *bits) {
	int i;
}

static void goodiesGetPlayableChrs(u32 *bits) {
	int i;
}

static int goodiesGetBotSets() {
	int botsets;
	int i;
}

static void frontmpgStoreGoodies() {}

static boolean frontmpgNewGoodies() {
	u32 availchrs[3];
	u32 playchrs[3];
}

static u8* getNextGoodieString() {
	u32 availchrs[3];
	u32 playchrs[3];
	u32 cheats;
	u32 levels;
	u8 misc;
	int botsets;
}

static void goodieMessage(u8 *message) {}

static void goodieMessageGfx(int timer, u32 fgcol) {
	int y1;
	int xofs;
	int font;
	int pos;
	u8 *text;
	u32 fg;
	u8 *newline;
	int x;
	int y;
}

static void goodies_pageGfx(pagedef_t *page) {
	u8 *s;
	int i;
	int timer;
}

static void goodies_pageTick(pagedef_t *page) {}

static void frontmpgSetGoodiesPage() {}

static void frontmpgtestGoodies() {}

static void demoplaybackTick() {}

void frontmpgMake() {
	int i;
}

void frontmpgPreload() {}

void frontmpgReset() {
	int i;
	static u8 txt[3][32];
}

void frontmpgEnd() {}

void frontmpgSetFlags(int flag) {}

static void settingsToMenus() {}

static void menusToSettings() {}

static void frontmpgStartGame() {
	resetgameparms *p;
	setupchallenge *ch;
	int i;
	int teams[6];
	int i;
	int teams[5];
}

static void animStopImmediately() {
	int j;
}

static void animTick(pagedef_t *page) {}
