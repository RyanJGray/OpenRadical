// STATUS: NOT STARTED

#ifndef GAME_BG_BG_H
#define GAME_BG_BG_H

bgLoad();
isroomvisible();
isRoomVisibleByAnyPlayer();
bgRoomBBIntersectionNumRooms();
bgCalcRoomArray();
bgIsAnyRoomsVisibleByPlayer();
bgTileLoad();
bgTileSetRoomNums();
bgTileSetPortalNums();
bgTileSetTextureNums();
bgPreload();
bgPreloadTextures();
bgRestart();
bgReset();
bgEnd();
bgGfx();
bgGetRoomsTick();
bgRoomGetLevel();
bgRoomBBIntersection();
bgFloorBBIntersection();
bgFloorBBIntersectionXZ();
bgWallBBIntersection();
bgPortalBBIntersection();
bgGetNeighbours();
bgGetFloors();
bgGetWalls();
bgGetGlass();
bgGetVolume();
bgPortalDisable();
bgPortalEnable();
bgPortalDisableFromRooms();
bgPortalEnableFromRooms();
bgPortalTick();
bgPortalGfx();
bgPortalRectGfx();
bgVolumeGfx();
bgFloorGfx();
bgWallGfx();
bgPortalCrossed();
bgLineTest();
bgGlassSwipeTestRoom();
bgGlassMoveTestRoom();
bgGlassLineTestRoom();
bgProcessGlasshits();
bgAmountGlassLeft();
bgAllGlassBroken();
bgTick();

#endif // GAME_BG_BG_H
