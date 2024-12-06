//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FRONT_MCSEQ_H
#define GAME_FRONT_MCSEQ_H

#include "common.h"

extern u32 mcseq_slotcolours[9];
extern u32 mcseq_flags;
extern int mcseq_msgflags;

u8* mcseqSlotMakeName(int cardnum);
u8* mcseqSlotGetLongName();
u8* mcseqSlotGetShortName();
void mcseqWindowClose();
int mcseqGetRequiredSpace();
int mcseqGetResult();
int mcseqGetState();
void mcseqLoad(int num, u8 *title, u8 *titleact, u8 *filename, u8 *buffer, int length, int seekstart);
void mcseqSave(int num, u8 *title, u8 *titleact, u8 *filename, u8 *buffer, int length, int seekstart);
void mcseqController(int num);
void mcseqAddOption(u8 *text);
void mcseqPollLoop();
int mcseqPollCount();
void mcseqUnvalidateCards();
int mcseqGetCurCard();
void mcseqSetCurCard(int card);
int mcseqGetNumCards();
void mcseqMake();
void mcseqMessage(int flags, char *line1, char *line2);
u8* mcseqGetMsg(int msgnum);

#endif // GAME_FRONT_MCSEQ_H
