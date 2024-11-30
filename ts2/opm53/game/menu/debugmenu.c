// STATUS: NOT STARTED

#include "debugmenu.h"

u8 *ontext = 0x45bd00;
u8 *offtext = 0x45bd08;
int padlinkedit = 0;
int propedit = 0;
int ambientlightedit = 0;
int viewportals = 0;
int viewportalrects = 0;
int viewfloors = 0;
int viewwalls = 0;
int viewpropfloors = 0;
int viewpropwalls = 0;
int viewvolumes = 0;
int viewroombb = 0;
int viewpropbb = 0;
int viewweatherbb = 0;
int viewfxbb = 0;
int viewguns = 1;
int viewbg = 1;
int viewhud = 1;
int displaypos = 0;
int turtlecpu = 0;
int turtlegs = 0;
int showglows = 0;
int disableambientlight = 0;

menu debugmenu = {
	/* .title = */ 0x43dd30,
	/* .numitems = */ 13,
	/* .curitem = */ NULL,
	/* .spare = */ 0,
	/* .items = */ {
	}
};

menuitem dm1b = {
	/* .text = */ 0x43dd40,
	/* .xpostype = */ 0,
	/* .xpos = */ 50,
	/* .xposref = */ NULL,
	/* .ypostype = */ 0,
	/* .ypos = */ 30,
	/* .yposref = */ NULL,
	/* .flags = */ 5,
	/* .actiondata = */ &startgameview,
	/* .spare = */ 0
};

menuitem dm1c = {
	/* .text = */ 0x43dd50,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1b,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1b,
	/* .flags = */ 5,
	/* .actiondata = */ &startthirdpersonview,
	/* .spare = */ 0
};

menuitem dm1d = {
	/* .text = */ 0x43dd68,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1c,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1c,
	/* .flags = */ 5,
	/* .actiondata = */ &startPropView,
	/* .spare = */ 0
};

menuitem dm1e = {
	/* .text = */ 0x43dd78,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1d,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1d,
	/* .flags = */ 65,
	/* .actiondata = */ &debugmenu5,
	/* .spare = */ 0
};

menuitem dm1f = {
	/* .text = */ 0x43dd88,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1e,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1e,
	/* .flags = */ 5,
	/* .actiondata = */ &toggledisplaypos,
	/* .spare = */ 0
};

menuitem dm1g = {
	/* .text = */ 0x43dd98,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1f,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1f,
	/* .flags = */ 65,
	/* .actiondata = */ &debugmenu4,
	/* .spare = */ 0
};

menuitem dm1h = {
	/* .text = */ 0x43dda8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1g,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1g,
	/* .flags = */ 65,
	/* .actiondata = */ &debugmenu3,
	/* .spare = */ 0
};

menuitem dm1i = {
	/* .text = */ 0x45bd70,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1h,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1h,
	/* .flags = */ 65,
	/* .actiondata = */ &debugmenu2,
	/* .spare = */ 0
};

menuitem dm1j = {
	/* .text = */ 0x45bd78,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1i,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm1i,
	/* .flags = */ 65,
	/* .actiondata = */ &debugmenu6,
	/* .spare = */ 0
};

menuitem dm1b2 = {
	/* .text = */ &getgameview,
	/* .xpostype = */ 3,
	/* .xpos = */ 70,
	/* .xposref = */ &dm1b,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm1b,
	/* .flags = */ 2,
	/* .actiondata = */ &dm1b,
	/* .spare = */ 0
};

menuitem dm1c2 = {
	/* .text = */ &getthirdpersonview,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1b2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm1b2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm1c,
	/* .spare = */ 0
};

menuitem dm1d2 = {
	/* .text = */ &getpropview,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1c2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm1c2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm1d,
	/* .spare = */ 0
};

menuitem dm1f2 = {
	/* .text = */ &getdisplaypos,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm1d2,
	/* .ypostype = */ 3,
	/* .ypos = */ 16,
	/* .yposref = */ &dm1d2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm1f,
	/* .spare = */ 0
};

int invincible = 0;
int invisible = 0;
int collisions = 1;
int unlock = 0;
int notimer = 0;
int blood = 0;
int pausewithtri = 0;
int screendumpwithsquare = 0;
int movewhenpaused = 0;

menu debugmenu2 = {
	/* .title = */ 0x43ddb8,
	/* .numitems = */ 18,
	/* .curitem = */ NULL,
	/* .spare = */ 0,
	/* .items = */ {
	}
};

menuitem dm2a = {
	/* .text = */ 0x43ddc8,
	/* .xpostype = */ 0,
	/* .xpos = */ 90,
	/* .xposref = */ NULL,
	/* .ypostype = */ 0,
	/* .ypos = */ 60,
	/* .yposref = */ NULL,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleinvincible,
	/* .spare = */ 0
};

menuitem dm2b = {
	/* .text = */ 0x43ddd8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2a,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2a,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleinvisible,
	/* .spare = */ 0
};

menuitem dm2c = {
	/* .text = */ 0x43dde8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2b,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2b,
	/* .flags = */ 5,
	/* .actiondata = */ &togglecollisions,
	/* .spare = */ 0
};

menuitem dm2d = {
	/* .text = */ 0x43ddf8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2c,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2c,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleblood,
	/* .spare = */ 0
};

menuitem dm2e = {
	/* .text = */ 0x43de08,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2d,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2d,
	/* .flags = */ 5,
	/* .actiondata = */ &togglepausewithtri,
	/* .spare = */ 0
};

menuitem dm2f = {
	/* .text = */ 0x43de18,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2e,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2e,
	/* .flags = */ 5,
	/* .actiondata = */ &togglescreendumpwithsquare,
	/* .spare = */ 0
};

menuitem dm2g = {
	/* .text = */ 0x43de30,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2f,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2f,
	/* .flags = */ 5,
	/* .actiondata = */ &togglemovewhenpaused,
	/* .spare = */ 0
};

menuitem dm2h = {
	/* .text = */ 0x45bda8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2g,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2g,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleunlock,
	/* .spare = */ 0
};

menuitem dm2i = {
	/* .text = */ 0x43de48,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2h,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2h,
	/* .flags = */ 5,
	/* .actiondata = */ &togglenotimer,
	/* .spare = */ 0
};

menuitem dm2a2 = {
	/* .text = */ &getinvincible,
	/* .xpostype = */ 3,
	/* .xpos = */ 200,
	/* .xposref = */ &dm2a,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm2a,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2a,
	/* .spare = */ 0
};

menuitem dm2b2 = {
	/* .text = */ &getinvisible,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2a2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2a2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2b,
	/* .spare = */ 0
};

menuitem dm2c2 = {
	/* .text = */ &getcollisions,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2b2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2b2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2c,
	/* .spare = */ 0
};

menuitem dm2d2 = {
	/* .text = */ &getblood,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2c2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2c2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2d,
	/* .spare = */ 0
};

menuitem dm2e2 = {
	/* .text = */ &getpausewithtri,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2d2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2d2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2e,
	/* .spare = */ 0
};

menuitem dm2f2 = {
	/* .text = */ &getscreendumpwithsquare,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2e2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2e2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2f,
	/* .spare = */ 0
};

menuitem dm2g2 = {
	/* .text = */ &getmovewhenpaused,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2f2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2f2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2g,
	/* .spare = */ 0
};

menuitem dm2h2 = {
	/* .text = */ &getunlock,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2g2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2g2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2h,
	/* .spare = */ 0
};

menuitem dm2i2 = {
	/* .text = */ &getnotimer,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm2h2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm2h2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm2i,
	/* .spare = */ 0
};

int displayspeed = 0;
int displayperfstats = 0;
int displayrooms = 0;
int showenemystats = 0;
int showenemyalertstates = 0;
int showrankingstype = 0;

menu debugmenu3 = {
	/* .title = */ 0x43de58,
	/* .numitems = */ 16,
	/* .curitem = */ NULL,
	/* .spare = */ 0,
	/* .items = */ {
	}
};

menuitem dm3a = {
	/* .text = */ 0x43de70,
	/* .xpostype = */ 0,
	/* .xpos = */ 90,
	/* .xposref = */ NULL,
	/* .ypostype = */ 0,
	/* .ypos = */ 90,
	/* .yposref = */ NULL,
	/* .flags = */ 5,
	/* .actiondata = */ &toggledisplayspeed,
	/* .spare = */ 0
};

menuitem dm3b = {
	/* .text = */ 0x43de80,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3a,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3a,
	/* .flags = */ 5,
	/* .actiondata = */ &toggledisplayperfstats,
	/* .spare = */ 0
};

menuitem dm3c = {
	/* .text = */ 0x43de98,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3b,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3b,
	/* .flags = */ 5,
	/* .actiondata = */ &toggledisplayrooms,
	/* .spare = */ 0
};

menuitem dm3d = {
	/* .text = */ 0x43deb0,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3c,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3c,
	/* .flags = */ 5,
	/* .actiondata = */ &memPrintFree,
	/* .spare = */ 0
};

menuitem dm3e = {
	/* .text = */ 0x43dec0,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3d,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3d,
	/* .flags = */ 5,
	/* .actiondata = */ &memdbPrintFree,
	/* .spare = */ 0
};

menuitem dm3f = {
	/* .text = */ 0x43ded8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3e,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3e,
	/* .flags = */ 5,
	/* .actiondata = */ &notdone,
	/* .spare = */ 0
};

menuitem dm3g = {
	/* .text = */ 0x43dee8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3f,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3f,
	/* .flags = */ 5,
	/* .actiondata = */ &emPrintStats,
	/* .spare = */ 0
};

menuitem dm3h = {
	/* .text = */ 0x43def8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3g,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3g,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleshowenemystats,
	/* .spare = */ 0
};

menuitem dm3i = {
	/* .text = */ 0x43df10,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3h,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3h,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleshowenemyalertstates,
	/* .spare = */ 0
};

menuitem dm3j = {
	/* .text = */ 0x43df28,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3h,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm3i,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleshowrankingstype,
	/* .spare = */ 0
};

menuitem dm3a2 = {
	/* .text = */ &getdisplayspeed,
	/* .xpostype = */ 3,
	/* .xpos = */ 90,
	/* .xposref = */ &dm3a,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm3a,
	/* .flags = */ 2,
	/* .actiondata = */ &dm3a,
	/* .spare = */ 0
};

menuitem dm3b2 = {
	/* .text = */ &getdisplayperfstats,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3a2,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm3b,
	/* .flags = */ 2,
	/* .actiondata = */ &dm3b,
	/* .spare = */ 0
};

menuitem dm3c2 = {
	/* .text = */ &getdisplayrooms,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3b2,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm3c,
	/* .flags = */ 2,
	/* .actiondata = */ &dm3c,
	/* .spare = */ 0
};

menuitem dm3h2 = {
	/* .text = */ &getshowenemystats,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3b2,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm3h,
	/* .flags = */ 2,
	/* .actiondata = */ &dm3h,
	/* .spare = */ 0
};

menuitem dm3i2 = {
	/* .text = */ &getshowenemyalertstates,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3b2,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm3i,
	/* .flags = */ 2,
	/* .actiondata = */ &dm3i,
	/* .spare = */ 0
};

menuitem dm3j2 = {
	/* .text = */ &getshowrankingstype,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm3b2,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm3j,
	/* .flags = */ 2,
	/* .actiondata = */ &dm3j,
	/* .spare = */ 0
};

menu debugmenu4 = {
	/* .title = */ 0x43df38,
	/* .numitems = */ 32,
	/* .curitem = */ NULL,
	/* .spare = */ 0,
	/* .items = */ {
	}
};

menuitem dm4a = {
	/* .text = */ 0x43df50,
	/* .xpostype = */ 0,
	/* .xpos = */ 90,
	/* .xposref = */ NULL,
	/* .ypostype = */ 0,
	/* .ypos = */ 45,
	/* .yposref = */ NULL,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewportals,
	/* .spare = */ 0
};

menuitem dm4b = {
	/* .text = */ 0x43df60,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4a,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4a,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewportalrects,
	/* .spare = */ 0
};

menuitem dm4c = {
	/* .text = */ 0x43df78,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4b,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4b,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewfloors,
	/* .spare = */ 0
};

menuitem dm4d = {
	/* .text = */ 0x43df88,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4c,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4c,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewwalls,
	/* .spare = */ 0
};

menuitem dm4e = {
	/* .text = */ 0x43df98,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4d,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4d,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewvolumes,
	/* .spare = */ 0
};

menuitem dm4f = {
	/* .text = */ 0x43dfa8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4e,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4e,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewguns,
	/* .spare = */ 0
};

menuitem dm4g = {
	/* .text = */ 0x43dfb8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4f,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4f,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewbg,
	/* .spare = */ 0
};

menuitem dm4h = {
	/* .text = */ 0x43dfd0,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4g,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4g,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewroombb,
	/* .spare = */ 0
};

menuitem dm4i = {
	/* .text = */ 0x43dfe8,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4h,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4h,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewpropbb,
	/* .spare = */ 0
};

menuitem dm4j = {
	/* .text = */ 0x43e000,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4i,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4i,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewfxbb,
	/* .spare = */ 0
};

menuitem dm4k = {
	/* .text = */ 0x43e018,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4j,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4j,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewhud,
	/* .spare = */ 0
};

menuitem dm4l = {
	/* .text = */ 0x43e028,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4k,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4k,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewweatherbb,
	/* .spare = */ 0
};

menuitem dm4m = {
	/* .text = */ 0x43e040,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4l,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4l,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewglows,
	/* .spare = */ 0
};

menuitem dm4n = {
	/* .text = */ 0x43e058,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4m,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4m,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewpropfloors,
	/* .spare = */ 0
};

menuitem dm4o = {
	/* .text = */ 0x43e070,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4n,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4n,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleviewpropwalls,
	/* .spare = */ 0
};

menuitem dm4p = {
	/* .text = */ 0x43e088,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4o,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm4o,
	/* .flags = */ 5,
	/* .actiondata = */ &toggledisableambientlight,
	/* .spare = */ 0
};

menuitem dm4a2 = {
	/* .text = */ &getviewportals,
	/* .xpostype = */ 3,
	/* .xpos = */ 120,
	/* .xposref = */ &dm4a,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm4a,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4a,
	/* .spare = */ 0
};

menuitem dm4b2 = {
	/* .text = */ &getviewportalrects,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4a2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4a2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4b,
	/* .spare = */ 0
};

menuitem dm4c2 = {
	/* .text = */ &getviewfloors,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4b2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4b2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4c,
	/* .spare = */ 0
};

menuitem dm4d2 = {
	/* .text = */ &getviewwalls,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4c2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4c2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4d,
	/* .spare = */ 0
};

menuitem dm4e2 = {
	/* .text = */ &getviewvolumes,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4d2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4d2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4e,
	/* .spare = */ 0
};

menuitem dm4f2 = {
	/* .text = */ &getviewguns,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4e2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4e2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4f,
	/* .spare = */ 0
};

menuitem dm4g2 = {
	/* .text = */ &getviewbg,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4f2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4f2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4g,
	/* .spare = */ 0
};

menuitem dm4h2 = {
	/* .text = */ &getviewroombb,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4g2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4g2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4h,
	/* .spare = */ 0
};

menuitem dm4i2 = {
	/* .text = */ &getviewpropbb,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4h2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4h2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4i,
	/* .spare = */ 0
};

menuitem dm4j2 = {
	/* .text = */ &getviewfxbb,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4i2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4i2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4j,
	/* .spare = */ 0
};

menuitem dm4k2 = {
	/* .text = */ &getviewhud,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4j2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4j2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4k,
	/* .spare = */ 0
};

menuitem dm4l2 = {
	/* .text = */ &getviewweatherbb,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4k2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4k2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4l,
	/* .spare = */ 0
};

menuitem dm4m2 = {
	/* .text = */ &getviewglows,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4l2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4l2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4m,
	/* .spare = */ 0
};

menuitem dm4n2 = {
	/* .text = */ &getviewpropfloors,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4m2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4m2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4n,
	/* .spare = */ 0
};

menuitem dm4o2 = {
	/* .text = */ &getviewpropwalls,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4n2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4n2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4o,
	/* .spare = */ 0
};

menuitem dm4p2 = {
	/* .text = */ &getdisableambientlight,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm4o2,
	/* .ypostype = */ 3,
	/* .ypos = */ 2,
	/* .yposref = */ &dm4o2,
	/* .flags = */ 2,
	/* .actiondata = */ &dm4p,
	/* .spare = */ 0
};

menu debugmenu5 = {
	/* .title = */ 0x43e0a0,
	/* .numitems = */ 6,
	/* .curitem = */ NULL,
	/* .spare = */ 0,
	/* .items = */ {
	}
};

menuitem dm5a = {
	/* .text = */ 0x43e0b0,
	/* .xpostype = */ 0,
	/* .xpos = */ 90,
	/* .xposref = */ NULL,
	/* .ypostype = */ 0,
	/* .ypos = */ 60,
	/* .yposref = */ NULL,
	/* .flags = */ 5,
	/* .actiondata = */ &togglepadlinkedit,
	/* .spare = */ 0
};

menuitem dm5b = {
	/* .text = */ 0x43e0c0,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm5a,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm5a,
	/* .flags = */ 5,
	/* .actiondata = */ &togglepropedit,
	/* .spare = */ 0
};

menuitem dm5c = {
	/* .text = */ 0x43e0d0,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm5b,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm5b,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleambientlightedit,
	/* .spare = */ 0
};

menuitem dm5a2 = {
	/* .text = */ &getpadlinkedit,
	/* .xpostype = */ 1,
	/* .xpos = */ 170,
	/* .xposref = */ &dm5a,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm5a,
	/* .flags = */ 2,
	/* .actiondata = */ &dm5a,
	/* .spare = */ 0
};

menuitem dm5b2 = {
	/* .text = */ &getpropedit,
	/* .xpostype = */ 1,
	/* .xpos = */ 170,
	/* .xposref = */ &dm5b,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm5b,
	/* .flags = */ 2,
	/* .actiondata = */ &dm5b,
	/* .spare = */ 0
};

menuitem dm5c2 = {
	/* .text = */ &getambientlightedit,
	/* .xpostype = */ 1,
	/* .xpos = */ 170,
	/* .xposref = */ &dm5c,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm5c,
	/* .flags = */ 2,
	/* .actiondata = */ &dm5c,
	/* .spare = */ 0
};

menu debugmenu6 = {
	/* .title = */ 0x43e0e8,
	/* .numitems = */ 4,
	/* .curitem = */ NULL,
	/* .spare = */ 0,
	/* .items = */ {
	}
};

menuitem dm6a = {
	/* .text = */ 0x43e0f8,
	/* .xpostype = */ 0,
	/* .xpos = */ 90,
	/* .xposref = */ NULL,
	/* .ypostype = */ 0,
	/* .ypos = */ 60,
	/* .yposref = */ NULL,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleturtlecpu,
	/* .spare = */ 0
};

menuitem dm6b = {
	/* .text = */ 0x43e108,
	/* .xpostype = */ 1,
	/* .xpos = */ 0,
	/* .xposref = */ &dm6a,
	/* .ypostype = */ 3,
	/* .ypos = */ 1,
	/* .yposref = */ &dm6a,
	/* .flags = */ 5,
	/* .actiondata = */ &toggleturtlegs,
	/* .spare = */ 0
};

menuitem dm6a2 = {
	/* .text = */ &getturtlecpu,
	/* .xpostype = */ 1,
	/* .xpos = */ 150,
	/* .xposref = */ &dm6a,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm6a,
	/* .flags = */ 2,
	/* .actiondata = */ &dm6a,
	/* .spare = */ 0
};

menuitem dm6b2 = {
	/* .text = */ &getturtlegs,
	/* .xpostype = */ 1,
	/* .xpos = */ 150,
	/* .xposref = */ &dm6b,
	/* .ypostype = */ 1,
	/* .ypos = */ 0,
	/* .yposref = */ &dm6b,
	/* .flags = */ 2,
	/* .actiondata = */ &dm6b,
	/* .spare = */ 0
};

int debugmenujoymode = 0;

static float framePercent[2] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f
};

static float framePercentMax[2] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f
};

static int framePercentChange[2] = {
	/* [0] = */ 0,
	/* [1] = */ 0
};

void startgameview(menuitem *item) {}

u8* getgameview(menuitem *item) {}

void startthirdpersonview(menuitem *item) {}

u8* getthirdpersonview(menuitem *item) {}

void startPropView(menuitem *item) {}

u8* getpropview(menuitem *item) {}

void toggledisplaypos(menuitem *item) {}

u8* getdisplaypos(menuitem *item) {}

void toggleinvincible(menuitem *item) {}

u8* getinvincible(menuitem *item) {}

void toggleinvisible(menuitem *item) {}

u8* getinvisible(menuitem *item) {}

void togglecollisions(menuitem *item) {
	player *cp;
	chrdata *chr;
	float start[3];
	float dir[3];
	float hpos[3];
	float hnorm[3];
}

u8* getcollisions(menuitem *item) {}

void toggleunlock(menuitem *item) {}

u8* getunlock(menuitem *item) {}

void togglenotimer(menuitem *item) {}

u8* getnotimer(menuitem *item) {}

void toggleblood(menuitem *item) {}

u8* getblood(menuitem *item) {}

void togglepausewithtri(menuitem *item) {}

u8* getpausewithtri(menuitem *item) {}

void togglescreendumpwithsquare(menuitem *item) {}

u8* getscreendumpwithsquare(menuitem *item) {}

void togglemovewhenpaused(menuitem *item) {}

u8* getmovewhenpaused(menuitem *item) {}

void notdone(menuitem *item) {}

void toggledisplayspeed(menuitem *item) {}

void toggledisplayperfstats(menuitem *item) {}

void toggledisplayrooms(menuitem *item) {}

void toggleshowenemystats(menuitem *item) {}

void toggleshowenemyalertstates(menuitem *item) {}

void toggleshowrankingstype(menuitem *item) {}

u8* getdisplayspeed(menuitem *item) {}

u8* getdisplayperfstats(menuitem *item) {}

u8* getdisplayrooms(menuitem *item) {}

u8* getshowenemystats(menuitem *item) {}

u8* getshowenemyalertstates(menuitem *item) {}

u8* getshowrankingstype(menuitem *item) {}

void toggleviewhud(menuitem *item) {}

u8* getviewhud(menuitem *item) {}

void toggleviewportals(menuitem *item) {}

u8* getviewportals(menuitem *item) {}

void toggleviewportalrects(menuitem *item) {}

u8* getviewportalrects(menuitem *item) {}

void toggleviewfloors(menuitem *item) {}

u8* getviewfloors(menuitem *item) {}

void toggleviewwalls(menuitem *item) {}

u8* getviewwalls(menuitem *item) {}

void toggleviewpropwalls(menuitem *item) {}

u8* getviewpropwalls(menuitem *item) {}

void toggleviewpropfloors(menuitem *item) {}

u8* getviewpropfloors(menuitem *item) {}

void toggleviewvolumes(menuitem *item) {}

u8* getviewvolumes(menuitem *item) {}

void toggleviewguns(menuitem *item) {}

u8* getviewguns(menuitem *item) {}

void toggleviewbg(menuitem *item) {}

u8* getviewbg(menuitem *item) {}

void toggleviewroombb(menuitem *item) {}

u8* getviewroombb(menuitem *item) {}

void toggleviewpropbb(menuitem *item) {}

u8* getviewpropbb(menuitem *item) {}

void toggleviewfxbb(menuitem *item) {}

u8* getviewfxbb(menuitem *item) {}

void toggleviewweatherbb(menuitem *item) {}

u8* getviewweatherbb(menuitem *item) {}

void toggleviewglows(menuitem *item) {}

u8* getviewglows(menuitem *item) {}

void toggledisableambientlight(menu *item) {}

u8* getdisableambientlight(menuitem *item) {}

void togglepadlinkedit(menuitem *item) {}

u8* getpadlinkedit(menuitem *item) {}

void togglepropedit(menuitem *item) {}

u8* getpropedit(menuitem *item) {}

void toggleambientlightedit(menu *item) {}

u8* getambientlightedit(menuitem *item) {}

static u8* getturtlecpu(menuitem *item) {}

static u8* getturtlegs(menuitem *item) {}

static void toggleturtlecpu(menuitem *item) {}

static void toggleturtlegs(menuitem *item) {}

void debugmenuSetJoyMode(int newmode) {}

int debugmenuGetJoyMode() {}

static void displayspeedGfx() {}

static void displayperfstatsGfx() {}

static void displayposGfx() {}

void debugmenuStart() {}

void debugmenuTick() {}

void debugmenuGfx() {}

void debugmenuEnd() {}
