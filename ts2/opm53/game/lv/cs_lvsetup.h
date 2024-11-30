//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_LV_CS_LVSETUP_H
#define GAME_LV_CS_LVSETUP_H

#include "ob/cs_ob.h"

extern cs_animheader cs_dam_intro;

void cs_setup_dam_intro();
cs_animheader* cs_getAnimHeader(int intro);

#endif // GAME_LV_CS_LVSETUP_H
