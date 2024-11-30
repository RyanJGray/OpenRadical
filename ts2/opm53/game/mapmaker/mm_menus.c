// STATUS: NOT STARTED

#include "mm_menus.h"

// warning: multiple differing types with the same name (descriptor not equal)
struct menulist_s {
	u16 numitems;
	u16 numdisplay;
	s16 baseleft;
	s16 basetop;
	u16 flags;
	u16 selected;
	int firstdisplay;
};

typedef enum {
	mmg_type = 1,
	mmg_size = 2,
	mmg_lights = 3,
	mmg_create = 4,
	mmg_back = 5,
	mmg_last = 6
};

typedef enum {
	mmo_gridintensity = 1,
	mmo_maze = 2,
	mmo_back = 3,
	mmo_last = 4
};

typedef enum {
	enterdesc_init = 0,
	enterdesc_wait = 1
};

typedef enum {
	mmmap_tileset = 1,
	mmmap_wpnset = 2,
	mmmap_tune = 3,
	mmmap_desc = 4,
	mmmap_back = 5,
	mmmap_last = 6
};

typedef enum {
	tm_header = 1,
	tm_gamemode1 = 2,
	tm_gamemode2 = 3,
	tm_gamemode3 = 4,
	tm_gamemode4 = 5,
	tm_gamemode5 = 6,
	tm_gamemode6 = 7,
	tm_back = 8,
	tm_comment1 = 9,
	tm_comment2 = 10,
	tm_comment3 = 11,
	tm_comment4 = 12,
	tm_comment5 = 13,
	tm_comment6 = 14,
	tm_last = 15
};

typedef enum {
	mf_init_load_dir = 0,
	mf_init_load_wait = 1,
	mf_init_poll_start = 2,
	mf_init_make_menu = 3,
	mf_main = 4,
	mf_delete_ask = 5,
	mf_ask_overwrite = 6,
	mf_save_overwrite_ask = 7,
	mf_save_name_init = 8,
	mf_save_name_wait = 9,
	mf_save_map_check = 10,
	mf_save_map_start = 11,
	mf_save_fullsize_wait = 12,
	mf_save_map_wait = 13,
	mf_save_dir_wait = 14,
	mf_okcancel = 15,
	mf_okreloaddir = 16,
	mf_load_map_wait = 17
};

typedef enum {
	mmmain_mapsettings = 1,
	mmmain_testmap = 2,
	mmmain_undo = 3,
	mmmain_centermap = 4,
	mmmain_clearmap = 5,
	mmmain_settings = 6,
	mmmain_loadmap = 7,
	mmmain_savemap = 8,
	mmmain_help = 9,
	mmmain_quit = 10,
	mmmain_exit = 11,
	mmmain_last = 12
};

typedef enum {
	enemyedit_ba = 1,
	enemyedit_bo = 2,
	enemyedit_exit = 3,
	enemyedit_last = 4
};

typedef enum {
	mmpadact_clear = 1,
	mmpadact_start = 2,
	mmpadact_drop = 3,
	mmpadact_health = 4,
	mmpadact_armour = 5,
	mmpadact_gun = 6,
	mmpadact_ammo = 7,
	mmpadact_bag = 8,
	mmpadact_enemy = 9,
	mmpadact_key = 10,
	mmpadact_pwup = 11,
	mmpadact_props = 12,
	mmpadact_tele = 13,
	mmpadact_last = 14
};

gamevar gv_gridintensity = {
	/* .value = */ 48,
	/* .min = */ 0,
	/* .max = */ 127,
	/* .flags = */ 1,
	/* .display = */ NULL,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

gvdisp disp_tilesets[0] = {
};

static u8 disptunenums[0] = {
};

gvdisp disp_tunes[0] = {
};

gamevar gv_tileset = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 4,
	/* .flags = */ 0,
	/* .display = */ disp_tilesets,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ -140,
	/* .arrowrightofs = */ 0
};

gamevar gv_tune = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 23,
	/* .flags = */ 0,
	/* .display = */ disp_tunes,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ -140,
	/* .arrowrightofs = */ 0
};

gamevar gv_wpnset = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 10,
	/* .flags = */ 0,
	/* .display = */ disp_wpnset,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ -140,
	/* .arrowrightofs = */ 0
};

gunset mmgunset = {
	/* .name = */ 0,
	/* .numguns = */ 5,
	/* .guncombo = */ {
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
		/* [14] = */ 0
	}
};

static pageinit_t message_page = {
	/* .tick = */ &message_pageTick,
	/* .draw_before = */ &message_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static gvdisp disp_gentype[0] = {
};

static gamevar gv_gentype = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 2,
	/* .flags = */ 0,
	/* .display = */ disp_gentype,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 456,
	/* .arrowleftofs = */ -134,
	/* .arrowrightofs = */ 0
};

static gvdisp disp_gensize[0] = {
};

static gamevar gv_gensize = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 2,
	/* .flags = */ 0,
	/* .display = */ disp_gensize,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 456,
	/* .arrowleftofs = */ -134,
	/* .arrowrightofs = */ 0
};

static gvdisp disp_genlight[0] = {
};

static gamevar gv_genlight = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 2,
	/* .flags = */ 0,
	/* .display = */ disp_genlight,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 456,
	/* .arrowleftofs = */ -134,
	/* .arrowrightofs = */ 0
};

static menu_t generatemap_menu = {
	/* .numitems = */ 5,
	/* .baseleft = */ 254,
	/* .basetop = */ 249,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0202020[0] = {
};

static pageinit_t generatemap_page = {
	/* .tick = */ &generatemap_pageTick,
	/* .draw_before = */ &pagebackgroundGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ &menu_pageDrawAfter,
	/* .construct = */ NULL
};

static menu_t settings_menu = {
	/* .numitems = */ 3,
	/* .baseleft = */ 140,
	/* .basetop = */ 140,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0200[0] = {
};

static pageinit_t settings_page = {
	/* .tick = */ &settings_pageTick,
	/* .draw_before = */ &pagebackgroundGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ &menu_pageDrawAfter,
	/* .construct = */ NULL
};

static pageinit_t mmenterdesc_page = {
	/* .tick = */ &mmenterdesc_pageTick,
	/* .draw_before = */ &mmenterdesc_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t mapsettings_menu = {
	/* .numitems = */ 5,
	/* .baseleft = */ 140,
	/* .basetop = */ 140,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0300[0] = {
};

static pageinit_t mapsettings_page = {
	/* .tick = */ &mapsettings_pageTick,
	/* .draw_before = */ &pagebackgroundGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ &menu_pageDrawAfter,
	/* .construct = */ NULL
};

static u8 gamemodelist[0] = {
};

static menu_t testmap_menu = {
	/* .numitems = */ 14,
	/* .baseleft = */ 140,
	/* .basetop = */ 140,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0400[0] = {
};

static pageinit_t testmap_page = {
	/* .tick = */ &testmap_pageTick,
	/* .draw_before = */ &testmap_pageDraw,
	/* .initfocusid = */ 2,
	/* .pad = */ 0,
	/* .draw_after = */ &menu_pageDrawAfter,
	/* .construct = */ NULL
};

static pageinit_t mapnameedit_page = {
	/* .tick = */ &mapnameedit_pageTick,
	/* .draw_before = */ &mapnameedit_pageDraw,
	/* .initfocusid = */ 32000,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
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

static menuitem_t mi_dirnew = {
	/* .text = */ 0x41d,
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
	/* .text = */ 0x41e,
	/* .left = */ 0,
	/* .top = */ 160,
	/* .id = */ 0,
	/* .flags = */ 32,
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
	/* .text = */ 0x41f,
	/* .left = */ 0,
	/* .top = */ 280,
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

static menuitem_t mi_dirdelback = {
	/* .text = */ 0x420,
	/* .left = */ 0,
	/* .top = */ 280,
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

static menu_t mapfile_menu = {
	/* .numitems = */ -666,
	/* .baseleft = */ 66,
	/* .basetop = */ 69,
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

static int firstmap = 0;

static pageinit_t mapfile_page = {
	/* .tick = */ &mapfile_pageTick,
	/* .draw_before = */ &mapfile_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menu_t mmmain_menu = {
	/* .numitems = */ 11,
	/* .baseleft = */ 120,
	/* .basetop = */ 100,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0100[0] = {
};

static pageinit_t mmmain_page = {
	/* .tick = */ &mmmain_pageTick,
	/* .draw_before = */ &pagebackgroundGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ &menu_pageDrawAfter,
	/* .construct = */ NULL
};

gvdisp disp_npcstate[0] = {
};

static gamevar gv_npcstate = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 3,
	/* .flags = */ 0,
	/* .display = */ disp_npcstate,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static menu_t enemyedit_menu = {
	/* .numitems = */ 3,
	/* .baseleft = */ 60,
	/* .basetop = */ 22,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0600[0] = {
};

pageinit_t enemyedit_page = {
	/* .tick = */ &enemyedit_pageTick,
	/* .draw_before = */ &enemyedit_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

int rolloffset = 0;

gvdisp disp_padactstart[0] = {
};

static gamevar gv_padactstart = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 4,
	/* .flags = */ 0,
	/* .display = */ disp_padactstart,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gvdisp disp_padactdrop[0] = {
};

static gamevar gv_padactdrop = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 3,
	/* .flags = */ 0,
	/* .display = */ disp_padactdrop,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gvdisp disp_padacthealth[0] = {
};

static gamevar gv_padacthealth = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 2,
	/* .flags = */ 0,
	/* .display = */ disp_padacthealth,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gamevar gv_padactgun = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 5,
	/* .flags = */ 0,
	/* .display = */ NULL,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gamevar gv_padactammo = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 5,
	/* .flags = */ 0,
	/* .display = */ NULL,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gamevar gv_padactarmour = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 2,
	/* .flags = */ 0,
	/* .display = */ disp_padacthealth,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

gvdisp disp_padactpwup[0] = {
};

static gamevar gv_padactpwup = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 5,
	/* .flags = */ 0,
	/* .display = */ disp_padactpwup,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gamevar gv_padactenemy = {
	/* .value = */ 1,
	/* .min = */ 1,
	/* .max = */ 6,
	/* .flags = */ 0,
	/* .display = */ NULL,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

gvdisp disp_padactkey[0] = {
};

static gamevar gv_padactkey = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 3,
	/* .flags = */ 0,
	/* .display = */ disp_padactkey,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

gvdisp disp_padacttele[0] = {
};

static gamevar gv_padacttele = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 9,
	/* .flags = */ 0,
	/* .display = */ disp_padacttele,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static gvdisp disp_padactbag[0] = {
};

static gamevar gv_padactbag = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_padactbag,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

static s8 items_padactprops[0] = {
};

static gvdisp disp_padactprops[0] = {
};

static gamevar gv_padactprops = {
	/* .value = */ 0,
	/* .min = */ 0,
	/* .max = */ 2,
	/* .flags = */ 0,
	/* .display = */ disp_padactprops,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 280,
	/* .arrowleftofs = */ -110,
	/* .arrowrightofs = */ 0
};

menu_t padact_menu = {
	/* .numitems = */ 13,
	/* .baseleft = */ 60,
	/* .basetop = */ 22,
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t m0500[0] = {
};

u16 padactcuritem = 2;

pageinit_t padact_page = {
	/* .tick = */ &padact_pageTick,
	/* .draw_before = */ &padact_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static menuitem_t *highlightitem;
static rect_t menusize;
static gvdisp disp_wpnset[12];
static u8 msgbox_msg[1024];
static msgfunc_t msgbox_func;
static u32 msgbox_colour;
static int msgbox_state;
static int msgbox_saveflags;
static u8 mfstate;
static u8 tempmapdesc[128];
static u8 gamemodeenable[6];
static u8 titletop[64];
static u8 dispfiles[10][34];
static mapentry_t entryinfo;
static u8 newmap;
static int entrynum;
static int curmapentry;
static int numdispfiles;
static int newfileentry;
static int numlistentries;

static void M_MenuExit(pagedef_t *page) {}

static void M_SliderGfx(int x, int y, int value, int range, boolean enabled) {
	int xv;
	int w;
	int h;
}

static void M_DrawText(hitbox_t *box) {
	int x;
	int y;
	u32 colour;
	u32 bgcolour;
	menuitem_t *mi;
	int font;
}

static void M_ItemGfx(hitbox_t *box) {
	menuitem_t *mi;
	gamevar *gv;
	u8 *s;
	int x;
	int y;
	int font;
	u32 fgcol;
	u32 bgcol;
	int marginx;
	int w;
	int found;
	int maxw;
	int i;
}

void M_MakeBox(hitbox_t *box, s16 x, s16 y, s16 w, s16 h, u16 id, u16 flags, void (*draw)(/* parameters unknown */)) {}

static void M_MakeItem(hitbox_t *box, s16 *pos, menuitem_t *mi) {
	int x;
	int y;
	int w;
	int h;
	int font;
}

static int M_ListMake(hitbox_t *box, menulist_t *list) {
	hitbox_t *startbox;
	menuitem_t *mi;
	u16 basepos[2];
	int i;
}

static int M_MenuMake(hitbox_t *box, menu_t *menu) {
	int i;
	menuitem_t *mi;
	hitbox_t *startbox;
	s16 pos[2];
}

static menuitem_t* M_ItemGet(menu_t *menu, u16 id) {
	int i;
	menuitem_t *mi;
	int j;
	menulist_t *list;
	menuitem_t *item;
}

static menuitem_t* M_ItemGetSelected(menu_t *menu) {
	int i;
	menuitem_t *mi;
	int j;
	menulist_t *list;
	menuitem_t *item;
}

static void M_ItemSetFocus(pagedef_t *page) {
	hitbox_t *box;
}

static menulist_t* M_IsInList(menu_t *menu, u16 id) {
	int i;
	menuitem_t *mi;
	int j;
	menulist_t *list;
	menuitem_t *item;
}

static void M_MenuTick(pagedef_t *page, menu_t *menu) {
	int i;
	menuitem_t *mi;
	menulist_t *ml;
	menuitem_t *firstitem;
	int index;
	int mod;
}

static void pagebackgroundGfx(pagedef_t *page) {
	hitbox_t *box;
	rect_t s;
}

int MM_GetTuneNum() {}

void MM_SetTuneNum(int tunenum) {
	int i;
}

int MM_GetWeaponSetNum() {}

int MM_GetGunComboNum(int levelgun) {
	gunset *gunset;
}

void MM_SetGunComboNum(int levelgun, int guncombo) {}

static int messageGetState() {}

static void message_pageDraw(pagedef_t *page) {}

static boolean defaultmessagetick() {}

static void message_pageTick(pagedef_t *page) {
	fix_t margins[4];
}

void MM_StartMessage(u8 *text, u32 colour, msgfunc_t msgfunc) {
	int i;
	rect_t s;
	int w;
	int h;
}

static void generatemap_pageTick(pagedef_t *page) {}

static void settings_pageTick(pagedef_t *page) {}

static void mmenterdesc_pageDraw(pagedef_t *page) {}

static void mmenterdesc_pageTick(pagedef_t *page) {}

static void mapsettings_pageTick(pagedef_t *page) {
	int i;
}

static void testmap_pageDraw(pagedef_t *page) {
	int i;
	hitbox_t *box;
	hitbox_t *box;
}

static void testmap_pageTick(pagedef_t *page) {
	int i;
	int f;
	resetgameparms p;
	int i;
	u8 *msg;
}

static void mapnameedit_pageDraw(pagedef_t *page) {}

static void mapnameedit_pageTick(pagedef_t *page) {}

static int confirmyesno() {}

static int CircleYesTriangleNo() {}

static void updateDir(boolean deletedentry) {}

static void mapfile_pageDraw(pagedef_t *page) {
	rect_t s;
	int i;
	hitbox_t *box;
	u32 arrowcol;
	u8 *stime;
	int y;
	int mapindex;
}

static void mapfile_pageTick(pagedef_t *page) {
	int i;
	int y;
	menuitem_t *mi;
	int l;
	int i;
	int i;
}

void MM_StartMainMenu() {}

static void exitmapmaker() {
	resetgameparms p;
}

static int quitconfirmfunc() {}

static int clearmapconfirmfunc() {}

static void menu_pageDrawAfter(pagedef_t *page) {}

static void mmmain_pageTick(pagedef_t *page) {
	menuitem_t *mi;
}

void enemyedit_pageDraw(pagedef_t *page) {
	int x1;
	int x2;
	int y1;
	int y2;
}

void enemyedit_pageTick(pagedef_t *page) {}

int rollmenumake(hitbox_t *box, menu_t *menu, u16 curitem, boolean inactive) {
	menuitem_t *prev;
	menuitem_t *cur;
	menuitem_t *next;
	menuitem_t *mi;
	hitbox_t *startbox;
	s16 pos[2];
	int i;
}

void padact_pageDraw(pagedef_t *page) {
	rect_t s;
	hitbox_t *box;
}

void padact_pageTick(pagedef_t *page) {
	item_t *it;
	int i;
	item_t *it;
	int itemnum;
	item_t *it;
	menuitem_t *mi;
}
