#include "global.h"
#include "alloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"
#include "field_weather.h"
#include "palette.h"
#include "pokemon_storage_system.h"
#include "sound.h"
#include "constants/songs.h"
#include "window.h"
#include "gpu_regs.h"
#include "bg.h"
#include "menu.h"
#include "graphics.h"
#include "gba/macro.h"

#define UNKNOWN_OFFSET 100000

struct PaletteDescriptor {
	void *palette;
	u16 tag;
};

struct UnknownStruct_0203CF40 {
	u32 (*field0)(void);
	u32 field4;
	u16 field8;
	u16 fieldA;
	u32 fieldC;
	void* field10[19];
};

struct UnknownStruct_0861F3EC {
	u32 (*data[7])(void);
};

struct UnknownStruct_sub_81C7850 {
	// Unknown size; at least 3.
	void (*data[3])(u32);
};

struct UnknownStruct_sub_81C76C4 {
	u32 data[523];
};

extern struct BgTemplate gUnknown_0861FA04;

extern struct UnknownStruct_0203CF40 *gUnknown_0203CF40;
extern u8 gUnknown_0203CF3C;
extern struct UnknownStruct_0861F3EC gUnknown_0861F3EC[7]; // Unknown size; at least 7.

extern void sub_81C9430(void);
extern void sub_81CAADC(void);
extern void sub_81C99D4(void);
extern void sub_81C7C94(void);
extern void sub_8199D98(void);
extern void sub_81C7B74(void);
extern void sub_81C7C28(void);
extern void sub_81C7D28(void);


u32 sub_81C791C(s32 a0);
bool32 sub_81C756C(u32 a0);
bool32 sub_81C76C4(void);
u32 AnyMonHasRibbon(void);
u32 sub_81C75E0(void);
u32 sub_81C75D4(void);
u32 sub_81C76FC(void);
u32 sub_81C786C(void);
u32 sub_81C7764(s32 a0);
u32 atk47_cmd47(s32 a0);
bool32 sub_81C7738(void);
void CopyPaletteIntoBufferUnfaded(void *palette, u32 a1, u32 a2);
void sub_81C7834(u32 (*a0)(void), u32(*a1)(void));
void sub_81C7360(struct UnknownStruct_0203CF40 *a0);
void sub_81C7650(u32 index);
void sub_81C7850(u32 a0);
void sub_81C71E4(u8 a0);
void sub_81C7170(u8 a0);
void sub_81C742C(u8 taskId);
void sub_81C7710(void);
void sub_81C75F4(void);
void sub_81C7334(void);
void sub_81C7418(void);
void sub_81C7400(void);
void sub_81C72BC(void);

u32 sub_81C7078(u32 (*a0)(s32), u32 a1)
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

bool32 sub_81C70D8(u32 a0)
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
        sub_81C7360(gUnknown_0203CF40);
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
			sub_81C7360(gUnknown_0203CF40);
			gUnknown_0203CF40->field8 = 1;
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

// Clears UnknownStruct_0203CF40
void sub_81C7360(struct UnknownStruct_0203CF40 *a0) {
	s32 i;
	void **arrayPtr;
	void *fill;

	fill = NULL;
	i = 18;
	arrayPtr = &(a0->field10[18]);
	for (i; i >= 0; i--) {
		*arrayPtr = fill;
		arrayPtr -= 1;
	}
	a0->field8 = 0;
	a0->field4 = 0;
	a0->fieldC = AnyMonHasRibbon();
	a0->field0 = NULL;
}

bool32 AnyMonHasRibbon() {
	s32 i;
	s32 j;

	for (i = 0; i < 6; i++) {
		if (GetMonData(&gPlayerParty[i],  MON_DATA_SANITY_HAS_SPECIES)
			&& !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
			&& GetMonData(&gPlayerParty[i], MON_DATA_RIBBON_COUNT) != 0)
		{
			return TRUE;
		}
	}

	for (j = 0; j < 14; j++) {
		for (i = 0; i < 30; i++) {
			if (CheckBoxMonSanityAt(j, i)
				&& GetBoxMonDataAt(j, i, MON_DATA_RIBBON_COUNT) != 0)
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}

void sub_81C7400() {
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	UpdatePaletteFade();
}

void sub_81C7418() {
	TransferPlttBuffer();
	LoadOam();
	ProcessSpriteCopyRequests();
}

void sub_81C742C(u8 taskId) {
	s16* dataPtr;
	u32 v1;
	bool32 v2;

	dataPtr = gTasks[taskId].data;

	switch (dataPtr[0]) {
	case 0:
		sub_81C76C4();
		dataPtr[0] = 1;
		break;
	case 1:
		if (sub_81C76FC()) {
			break;
		}
		sub_81C756C(UNKNOWN_OFFSET);
		dataPtr[0] = 4;
		break;
	case 2:
		if (sub_81C786C()) {
			break;
		}
		dataPtr[0] = 3;
	case 3:
		v1 = sub_81C75E0();
		if (v1 == -1) {
			sub_81C7710();
			dataPtr[0] = 5;
		} else if (v1 >= UNKNOWN_OFFSET) {
			gUnknown_0861F3EC[gUnknown_0203CF40->field4].data[6]();
			gUnknown_0861F3EC[gUnknown_0203CF40->field4].data[5]();
			if (sub_81C756C(v1)) {
				dataPtr[0] = 4;
			} else {
				sub_81C7710();
				dataPtr[0] = 5;
			}
		} else if (v1 != 0) {
			sub_81C7850(v1);
			if (sub_81C786C()) {
				dataPtr[0] = 2;
			}
		}
		break;
	case 4:
		if (!sub_81C75D4()) {
			dataPtr[0] = 3;
		}
		break;
	case 5:
		if (!sub_81C7738()) {
			v2 = gUnknown_0203CF40->field8 != 0;
			sub_81C9430();
			sub_81C7334();
			if (v2) {
				SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
			} else {
				SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
			}
		}
	}
}

bool32 sub_81C756C(u32 a0) {
	u32 index;

	index = a0 - UNKNOWN_OFFSET;
	sub_81C75F4();
	if (!gUnknown_0861F3EC[index].data[0]()) {
		return FALSE;
	}
	if (!gUnknown_0861F3EC[index].data[2]()) {
		return FALSE;
	}
	sub_81C7834(gUnknown_0861F3EC[index].data[3], gUnknown_0861F3EC[index].data[4]);
	gUnknown_0203CF40->field0 = gUnknown_0861F3EC[index].data[1];
	gUnknown_0203CF40->field4 = index;
	return TRUE;
}

u32 sub_81C75D4(void) {
	return sub_81C786C();
}

u32 sub_81C75E0(void) {
	return gUnknown_0203CF40->field0();
}

void sub_81C75F4(void) {
	InitKeys();
}

void IndirectSetVBlankCallback(IntrCallback callback) {
	SetVBlankCallback(callback);
}

void sub_81C760C(void) {
	SetVBlankCallback(sub_81C7418);
}

void* sub_81C761C(u32 index, u32 size) {
	return gUnknown_0203CF40->field10[index] = (void*)Alloc(size);
}

void* sub_81C763C(u32 index) {
	return gUnknown_0203CF40->field10[index];
}

void sub_81C7650(u32 index) {
	if (gUnknown_0203CF40->field10[index] != NULL) {
		Free(gUnknown_0203CF40->field10[index]);
		gUnknown_0203CF40->field10[index] = NULL;
	}
}

u16 sub_81C767C(void) {
	return gUnknown_0203CF40->field8;
}

void sub_81C7688(u16 a0) {
	gUnknown_0203CF40->field8 = a0;
}

void sub_81C7694(u32 a0) {
	u32 value;
	value = a0;
	if (a0 > 4) {
		value = 0;
	}
	gUnknown_0203CF40->fieldA = value;
}

u16 sub_81C76AC(void) {
	return gUnknown_0203CF40->fieldA;
}

u32 sub_81C76B8(void) {
	return gUnknown_0203CF40->fieldC;
}

bool32 sub_81C76C4(void) {
	struct UnknownStruct_sub_81C76C4 *v1;

	v1 = (struct UnknownStruct_sub_81C76C4*)sub_81C761C(0, sizeof(struct UnknownStruct_sub_81C76C4));
	if (v1 == NULL) {
		return FALSE;
	} else {
		ResetSpriteData();
		FreeAllSpritePalettes();
		v1->data[3] = sub_81C7078(sub_81C7764, 1);
		return TRUE;
	}
}

u32 sub_81C76FC(void) {
	// This is a guess.
	struct UnknownStruct_sub_81C76C4 *v1;
	v1 = sub_81C763C(0);
	return sub_81C70D8(v1->data[3]);
}

void sub_81C7710(void) {
	PlaySE(SE_PN_OFF);
	sub_81CAADC();
	BeginNormalPaletteFade(-1, -1, 0, 16, 0);
}

bool32 sub_81C7738(void) {
	if (!gPaletteFade.active) {
		sub_81C99D4();
		sub_81C7C94();
		FreeAllWindowBuffers();
		return FALSE;
	} else {
		return TRUE;
	}
}

u32 sub_81C7764(s32 a0) {
	// This is a guess.
	struct UnknownStruct_sub_81C76C4 *v1;

	switch (a0) {
	case 0:
		SetGpuReg(0, 0x82 << 5);
		FreeAllWindowBuffers();
		ResetBgsAndClearDma3BusyFlags(0);
		InitBgsFromTemplates(0, &gUnknown_0861FA04, 1);
		sub_8199D98();
		reset_temp_tile_data_buffers();
		return 1;
	case 1:
		v1 = sub_81C763C(0);
		decompress_and_copy_tile_data_to_vram(0, &gPokenavHeader_Gfx, 0, 0, 0);
		SetBgTilemapBuffer(0, &v1->data[11]);
		CopyToBgTilemapBuffer(0, &gPokenavHeader_Tilemap, 0, 0);
		CopyPaletteIntoBufferUnfaded(&gPokenavHeader_Pal, 0, 0x20);
		CopyBgTilemapBufferToVram(0);
		return 0;
	case 2:
		if (free_temp_tile_data_buffers_if_possible()) {
			return 2;
		} else {
			sub_81C7B74();
			return 0;
		}
	case 3:
		if (IsDma3ManagerBusyWithBgCopy()) {
			return 2;
		} else {
			sub_81C7C28();
			sub_81C7D28();
			ShowBg(0);
			return 4;
		}
	default:
		return 4;
	}
}

void sub_81C7834(u32 (*a0)(void), u32(*a1)(void)) {
	// This is a guess.
	struct UnknownStruct_0861F3EC *v1;

	v1 = sub_81C763C(0);
	v1->data[0] = a0;
	v1->data[1] = a1;
	v1->data[2] = NULL;
}

void sub_81C7850(u32 a0) {
	// This is a guess.
	struct UnknownStruct_sub_81C7850 *v1;

	v1 = sub_81C763C(0);
	v1->data[2] = NULL;
	v1->data[0](a0);
}

u32 sub_81C786C(void) {
	// This is a guess.
	struct UnknownStruct_0861F3EC *v1;

	v1 = sub_81C763C(0);
	return v1->data[1]();
}

void sub_81C7880(void) {
	// This is a guess.
	struct UnknownStruct_0203CF40* v1;
	
	v1 = sub_81C763C(0);
	v1->fieldC = sub_81C7078(atk47_cmd47, 4);
}

void sub_81C78A0(void) {
	// This is a guess.
	struct UnknownStruct_0203CF40* v1;

	v1 = sub_81C763C(0);
	v1->fieldC = sub_81C7078(sub_81C791C, 4);
}

bool32 sub_81C78C0(void) {
	// This is a guess.
	struct UnknownStruct_0203CF40* v1;

	v1 = sub_81C763C(0);
	return sub_81C70D8(v1->fieldC);
}

u32 atk47_cmd47(s32 a0) {
	switch (a0) {
	default:
		return 4;
	case 1:
		return 0;
	case 0:
		return 0;
	case 2:
		if ((u32)ChangeBgY(0, 384, 1) >= 0x2000) {
			ChangeBgY(0, 0x2000, 0);
			return 4;
		} else {
			return 2;
		}
	}
}

u32 sub_81C791C(s32 a0) {
	if (ChangeBgY(0, 384, 2) <= 0) {
		ChangeBgY(0, 0, 0);
		return 4;
	} else {
		return 2;
	}
}

void CopyPaletteIntoBufferUnfaded(void *palette, u32 bufferOffset, u32 size) {
	CpuCopy16(palette, gPlttBufferUnfaded + bufferOffset, size);
}

void sub_81C795C(struct PaletteDescriptor *palettes) {
	struct PaletteDescriptor *current;
    u32 index;

    for (current = palettes; current->palette != NULL; current++) 
    {
        index = AllocSpritePalette(current->tag);
        if (index == 0xFF) 
        {
            break;
        }
        else
        {
            index = (index * 16) + 0x100;
            CopyPaletteIntoBufferUnfaded(current->palette, index, 0x20);
        }
    }
}