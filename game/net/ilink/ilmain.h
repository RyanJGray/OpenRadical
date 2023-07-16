// STATUS: NOT STARTED

#ifndef GAME_NET_ILINK_ILMAIN_H
#define GAME_NET_ILINK_ILMAIN_H

typedef long unsigned int u_long;

void th_Receiver();
boolean ilinkIsConnected(int ID);
void sceSocketPrepare();
void ilinkMake();
void ilinkInitialise();
void ilinkDeinitialise();
boolean ilinkConnect();
void ilinkDoDisconnect(int ID);
void ilinkSendImAServer();
void ilinkAskForServers();
boolean ilinkAreThereAnyServers();
void ilinkTick();
boolean ilinkGetNextPacket(int *pFromID, char *pBuffer, int *pSize);
int ilinkSendPacket(int ToID, char *pBuffer, int Size, boolean Guarantee);

#endif // GAME_NET_ILINK_ILMAIN_H
