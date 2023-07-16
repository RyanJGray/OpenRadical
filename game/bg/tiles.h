// STATUS: NOT STARTED

#ifndef GAME_BG_TILES_H
#define GAME_BG_TILES_H

typedef short unsigned int u16;
typedef padv1_s padv1;

struct padfile_s {
	int revision;
	int numpads;
	int numlinks;
	union {
		pad v2[0];
		padv1 v1[0];
	} pads;
};

struct itemdef_s {
	short int desc;
	short int group;
	u32 spotcol;
	int propnum;
	int mapicon;
	int flags;
};

typedef itemdef_s itemdef;

struct plugpad_s {
	s16 extref;
	u16 switchmask;
};

typedef plugpad_s plugpad_t;
extern int itemgrouplimits[20];
extern itemdef itemdefs[53];
extern float tilerotang[4];
extern mtx_u tilerotmtx[4];
extern u8 tile_1_data[0];
extern u8 tile_2_data[0];
extern u8 tile_3_data[0];
extern u8 tile_4_data[0];
extern u8 tile_5_data[0];
extern u8 tile_6_data[2][4];
extern u8 tile_7_data[2][6];
extern u8 tile_8_data[2][9];
extern u8 tile_9_data[4][4];
extern u8 tile_10_data[0];
extern u8 tile_11_data[0];
extern u8 tile_12_data[2][9];
extern u8 tile_13_data[2][9];
extern u8 tile_14_data[2][9];
extern u8 tile_15_data[2][2];
extern u8 tile_16_data[2][9];
extern u8 tile_17_data[2][9];
extern u8 tile_18_data[0];
extern u8 tile_19_data[0];
extern u8 tile_20_data[2][9];
extern u8 tile_21_data[2][9];
extern u8 tile_22_data[2][9];
extern u8 tile_23_data[2][9];
extern u8 tile_24_data[2][9];
extern u8 tile_25_data[2][9];
extern u8 tile_26_data[2][9];
extern u8 tile_27_data[2][9];
extern u8 tile_28_data[2][9];
extern u8 tile_29_data[2][4];
extern u8 tile_30_data[2][3];
extern u16 tile_1_ipads[0];
extern u16 tile_2_ipads[0];
extern u16 tile_3_ipads[0];
extern u16 tile_4_ipads[0];
extern u16 tile_5_ipads[0];
extern u16 tile_6_ipads[2][4];
extern u16 tile_7_ipads[2][6];
extern u16 tile_8_ipads[2][9];
extern u16 tile_9_ipads[4][4];
extern u16 tile_10_ipads[0];
extern u16 tile_11_ipads[0];
extern u16 tile_12_ipads[2][9];
extern u16 tile_13_ipads[2][9];
extern u16 tile_14_ipads[2][9];
extern u16 tile_15_ipads[2][2];
extern u16 tile_16_ipads[2][9];
extern u16 tile_17_ipads[2][9];
extern u16 tile_18_ipads[0];
extern u16 tile_19_ipads[0];
extern u16 tile_20_ipads[2][9];
extern u16 tile_21_ipads[2][9];
extern u16 tile_22_ipads[2][9];
extern u16 tile_23_ipads[2][9];
extern u16 tile_24_ipads[2][9];
extern u16 tile_25_ipads[2][9];
extern u16 tile_26_ipads[2][9];
extern u16 tile_27_ipads[2][9];
extern u16 tile_28_ipads[2][9];
extern u16 tile_29_ipads[2][4];
extern u16 tile_30_ipads[2][3];
extern plugpad_t tile_1_plugs[0];
extern plugpad_t tile_2_plugs[0];
extern plugpad_t tile_3_plugs[0];
extern plugpad_t tile_4_plugs[0];
extern plugpad_t tile_5_plugs[0];
extern plugpad_t tile_6_plugs[0];
extern plugpad_t tile_7_plugs[0];
extern plugpad_t tile_8_plugs[0];
extern plugpad_t tile_9_plugs[0];
extern plugpad_t tile_10_plugs[0];
extern plugpad_t tile_11_plugs[0];
extern plugpad_t tile_12_plugs[0];
extern plugpad_t tile_13_plugs[0];
extern plugpad_t tile_14_plugs[0];
extern plugpad_t tile_15_plugs[0];
extern plugpad_t tile_16_plugs[0];
extern plugpad_t tile_17_plugs[0];
extern plugpad_t tile_18_plugs[0];
extern plugpad_t tile_19_plugs[0];
extern plugpad_t tile_20_plugs[0];
extern plugpad_t tile_21_plugs[0];
extern plugpad_t tile_22_plugs[0];
extern plugpad_t tile_23_plugs[0];
extern plugpad_t tile_24_plugs[0];
extern plugpad_t tile_25_plugs[0];
extern plugpad_t tile_26_plugs[0];
extern plugpad_t tile_27_plugs[0];
extern plugpad_t tile_28_plugs[0];
extern plugpad_t tile_29_plugs[0];
extern plugpad_t tile_30_plugs[0];
extern plugpad_t *tileplugpads[30];
extern tiledef tileset1[30];
extern u8 tilefilenames[30][64];
extern u8 tilepadfilenames[30][64];
extern padfile_s *tilepaddata[30];


#endif // GAME_BG_TILES_H
