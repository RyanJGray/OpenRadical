// STATUS: NOT STARTED

#ifndef GAME_USB_MOUSE_H
#define GAME_USB_MOUSE_H

typedef unsigned char u_char;
typedef unsigned int u_int;

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
