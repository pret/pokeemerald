#ifndef GUARD_BERRY_BLENDER_H
#define GUARD_BERRY_BLENDER_H

// Indices into gSendCmd / gRecvCmds
#define BLENDER_COMM_INPUT_STATE   0
#define BLENDER_COMM_RESP          1
#define BLENDER_COMM_SCORE         2
#define BLENDER_COMM_STOP_TYPE     2 // re-used
#define BLENDER_COMM_PLAYER_ID     3
#define BLENDER_COMM_UNUSED        4
#define BLENDER_COMM_PROGRESS_BAR  5
#define BLENDER_COMM_ARROW_POS     6

extern u8 gInGameOpponentsNo;

void DoBerryBlending(void);
u16 GetBlenderArrowPosition(void);
void ShowBerryBlenderRecordWindow(void);

#endif // GUARD_BERRY_BLENDER_H
