//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_USB_MOUSE_H
#define GAME_USB_MOUSE_H

#include "common.h"

int sceUsbMouseInit();
int sceUsbMouseGetInfo(u_char *info);
int sceUsbMouseRead(u_int no, char *data);
int sceUsbMouseGetLocation(int no, u_char *location);
int sceUsbMouseSync(int mode);
void mouseTick();
void mouseMake();
int mouseBut(int m);
int mouseNewBut(int m);
int mouseReleaseBut(int m);
int mouseAxisX(int m);
int mouseAxisY(int m);

#endif // GAME_USB_MOUSE_H
