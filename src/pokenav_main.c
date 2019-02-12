#include "global.h"
#include "alloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"
#include "field_weather.h"
#include "palette.h"

// Can confirm the size is correct on line 287 of the generated pokenav_main.s
// file. The expected size is 0x5C.
struct UnknownStruct_0203CF40 {
	u8 data1[8];
	u16 field_0;
	u8 data[0x52];
};

extern struct UnknownStruct_0203CF40 *gUnknown_0203CF40;
extern u8 gUnknown_0203CF3C;

extern void sub_81C7360(void);
extern void sub_81C742C(u8 taskId);
extern void sub_81C7400(void);
extern void sub_81C7418(void);
extern void sub_81C7170(u8 a0);
extern void sub_81C71E4(u8 a0);
extern void sub_81C7650(s32 a0);

void sub_81C72BC(void);

u32 sub_81C7078(u32 (*a0)(u32), u32 a1)
{
    u16 taskId;

    if (!is_c1_link_related_active())
        taskId = CreateTask(sub_81C7170, a1);
	else
        taskId = CreateTask(sub_81C71E4, a1);

    SetWordTaskArg(taskId, 1, (u32)a0);

    gTasks[taskId].data[3] = gUnknown_0203CF3C;
    return ((gUnknown_0203CF3C++) << 16) | taskId;
}

bool32 sub_81C70D8(u32 a0, u32 unused)
{
	u32 v1 = a0 & 0xFFFF;
	u32 v2 = a0 >> 16;
	if (gTasks[v1].isActive
		&& (gTasks[v1].func == sub_81C7170 || gTasks[v1].func == sub_81C71E4)
		&& gTasks[v1].data[3] == v2)
	{
	
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool32 sub_81C7124(u32 a0)
{
	s32 i;
	for (i = 0; i < 16; i++) {
		if (gTasks[i].isActive
			&& (gTasks[i].func == sub_81C7170 || gTasks[i].func == sub_81C71E4))
		{
			u32 arg = GetWordTaskArg((u8)i, 1);
			if (arg == a0) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

void sub_81C7170(u8 taskId)
{
	s16 *dataPtr;
	u32 (*func)(u32);
	bool32 exitLoop;

	func = (u32 (*)(u32))GetWordTaskArg(taskId, 1);
	dataPtr = gTasks[taskId].data;
	exitLoop = FALSE;
	while (!exitLoop) {
		u32 v1 =((u32 (*)(u32))func)(dataPtr[0]); 
		switch (v1) {
		case 1:
			dataPtr[0] = dataPtr[0] + 1;
			break;
		case 0:
			dataPtr[0]++;
			return;
		case 4:
			DestroyTask(taskId);
			return;
		default:
			dataPtr[0] = v1 - 5;
			break;
		case 3:
			break;
		case 2:
			return;
		}
	}
}

void sub_81C71E4(u8 taskId) {
	u32 (*func)(u32);
	s16 *data;
	u32 v1;

	if (sub_8087598()) {
		return;
	}
	func = (u32 (*)(u32))GetWordTaskArg(taskId, 1);
	data = gTasks[taskId].data;
	v1 = func(data[0]);
	switch (v1) {
		case 0:
		case 1:
			data[0]++;
			break;
		case 4:
			DestroyTask(taskId);
			break;
		default:
			data[0] = v1 - 5;
			break;
		case 2:
		case 3:
	}
}

void CB2_PokeNav(void)
{
    gUnknown_0203CF40 = Alloc(sizeof(struct UnknownStruct_0203CF40));
    if (gUnknown_0203CF40 == NULL) {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    } else {
        sub_81C7360();
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(sub_81C7400);
        SetVBlankCallback(sub_81C7418);
    }
}

void sub_81C72A4() {
	SetMainCallback2(sub_81C72BC);
	FadeScreen(1, 0);
}

void sub_81C72BC() {
	UpdatePaletteFade();
	if (!gPaletteFade.active) {
		gUnknown_0203CF40 = Alloc(sizeof(struct UnknownStruct_0203CF40));
		if (gUnknown_0203CF40 == NULL) {
			SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
		} else {
			sub_81C7360();
			gUnknown_0203CF40->field_0 = 1;
			ResetTasks();
			ResetSpriteData();
			FreeAllSpritePalettes();
			SetVBlankCallback(NULL);
			CreateTask(sub_81C742C, 0);
			SetMainCallback2(sub_81C7400);
			SetVBlankCallback(sub_81C7418);
		}
	}
}

void sub_81C7334() {
	s32 i;
	for (i = 0; i < 19; i++) {
		sub_81C7650(i);
	}

	Free(gUnknown_0203CF40);
	gUnknown_0203CF40 = NULL;
	InitKeys();
}