// STATUS: NOT STARTED

#include "mouse.h"

struct mousedata_s {
	char len;
	char buttons;
	char x;
	char y;
	char wheel;
	char extra[123];
};

typedef mousedata_s mousedata_t;
static char mousebut = 0;
static char mouselastbut = 0;
static char mousenewbut = 0;
static char mousereleasebut = 0;
static sceSifClientData cdUsbMouse;
static u_char info[128];
static u_char location[128];
static u_int sdata[32];
static mousedata_t mousedata;
static int mousex;
static int mousey;

int sceUsbMouseInit() {
	unsigned int i;
}

int sceUsbMouseGetInfo(u_char *info) {}

int sceUsbMouseRead(u_int no, char *data) {}

int sceUsbMouseGetLocation(int no, u_char *location) {}

int sceUsbMouseSync(int mode) {}

void mouseTick() {
	int mousenum;
	int nummsgs;
}

void mouseMake() {}

int mouseBut(int m) {}

int mouseNewBut(int m) {}

int mouseReleaseBut(int m) {}

int mouseAxisX(int m) {}

int mouseAxisY(int m) {}
