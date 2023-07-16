// STATUS: NOT STARTED

#ifndef GAME_FX_SKY_H
#define GAME_FX_SKY_H

extern boolean cloudsEnabled;

void skySetMeshVertices(skymesh *mesh);
void skyMeshTick(skymesh *mesh, float translateu, float translatev, float periodx, float periodz, float amplitudex, float amplitudez, float speedx, float speedz);
void skyMeshGfx(mtx_u *finalmtx, skymesh *mesh);
void skyCloudsMeshesReset();
void skyCloudsMeshesTick();
void skyCloudsMeshesGfx();
void skyPreload();
void skyReset();
void skyResetAfter();
void skyRestart();
void skyEnd();
void skyTick();
void skyGfx();

#endif // GAME_FX_SKY_H
