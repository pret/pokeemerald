#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "graphics.h"
#include "sound.h"
#include "constants/songs.h"

extern u8 sub_81CB0C8(u32 a);
extern bool32 sub_81CAE08(u32 a);
void *sub_81C9958(void);
u32 LoopedTask_sub_81C9A10(s32 a0);
bool32 sub_81C99FC(void);
void sub_81CA7F4(void);
void sub_81C9FEC(void);
void sub_81CA994(void);
extern u32 sub_81C9894(void);
void sub_81CA850(void);
void sub_81CA6E0(void);
void sub_81CA7D4(void);
void sub_81C9FC4(void);
void sub_81CA714(void);
void sub_81CA02C(void);
void sub_81CA640(void);
void sub_81CA0C8(void);
bool32 sub_81CA7C4(void);
void sub_81CA20C(void);
void titlescreen_0(void);
bool32 sub_81CA324(void);

extern void *gUnknown_086201A0[];
extern const u32 gUnknown_0861FD6C[];
extern const u32 gUnknown_0861FFF4[];
extern const u16 gUnknown_0861FD4C[];
extern const u32 gUnknown_0861FC98[];
extern const u32 gUnknown_0861FCAC[];
extern const u16 gUnknown_0861FC78[];

extern const struct BgTemplate gUnknown_08620194[];

struct UnknownPokenavSubstruct2
{
	bool32 (* callback)(void);
	u32 field_4;
	u8 windowId;
	u8 filler_9[3];
	u8 field_C;
	u8 field_D;
	u8 filler_E[0x7E];
	u32 field_8C;
};

bool8 sub_81C98D4(void)
{
	s32 i;
	
	for(i = 0; i < 78; i++)
	{
		if(sub_81CB0C8(i) == gMapHeader.regionMapSectionId)
		{
			if(sub_81CAE08(i))
			{
				if(gSaveBlock1Ptr->trainerRematches[i])
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

bool8 sub_81C9924(void)
{
	struct UnknownPokenavSubstruct2 *pokenavstruct = sub_81C9958();
	if(!pokenavstruct)
	{
		return FALSE;
	}
	pokenavstruct->field_D = 0;
	return TRUE;
}

bool8 sub_81C9940(void)
{
	struct UnknownPokenavSubstruct2 *pokenavstruct = sub_81C9958();
	if(!pokenavstruct)
	{
		return FALSE;
	}
	pokenavstruct->field_D = 1;
	return TRUE;
}

void *sub_81C9958(void)
{
	struct UnknownPokenavSubstruct2 *ptr;
	ptr = AllocSubstruct(2, 0x88C);
	if(ptr)
	{
		ptr->field_C = 0;
		ptr->field_4 = CreateLoopedTask(LoopedTask_sub_81C9A10, 1);
		ptr->callback = sub_81C99FC;
	}
	
	return ptr;
}

void sub_81C9990(u32 a)
{
	struct UnknownPokenavSubstruct2 *ptr;
	ptr = GetSubstructPtr(2);
	ptr->field_4 = CreateLoopedTask(gUnknown_086201A0[a], 1);
	ptr->callback = sub_81C99FC;
}

void *sub_81C99C0(void)
{
	struct UnknownPokenavSubstruct2 *ptr;
	ptr = GetSubstructPtr(2);
	ptr->callback();
}

void sub_81C99D4(void)
{
	struct UnknownPokenavSubstruct2 *ptr;
	ptr = GetSubstructPtr(2);
	sub_81CA7F4();
	RemoveWindow(ptr->windowId);
	sub_81C9FEC();
	sub_81CA994();
	FreePokenavSubstruct(2);
}

bool32 sub_81C99FC(void)
{
	struct UnknownPokenavSubstruct2 *ptr;
	ptr = GetSubstructPtr(2);
	return IsLoopedTaskActive(ptr->field_4);
}

u32 LoopedTask_sub_81C9A10(s32 a0)
{
	struct UnknownPokenavSubstruct2 *ptr;
	ptr = GetSubstructPtr(2);
	
	switch (a0)
	{
		case 0:
			InitBgTemplates(gUnknown_08620194, 3);
			decompress_and_copy_tile_data_to_vram(1, gPokenavMessageBox_Gfx, 0, 0, 0);
			SetBgTilemapBuffer(1, (void *) &ptr->field_8C);
			CopyToBgTilemapBuffer(1, gPokenavMessageBox_Tilemap, 0, 0);
			CopyBgTilemapBufferToVram(1);
			CopyPaletteIntoBufferUnfaded( (const u16 *) &gPokenavMessageBox_Pal, 16, 32);
			ChangeBgX(1, 0, 0);
			ChangeBgY(1, 0, 0);
			ChangeBgX(2, 0, 0);
			ChangeBgY(2, 0, 0);
			ChangeBgX(3, 0, 0);
			ChangeBgY(3, 0, 0);
			return 0;
		case 1:
			if (!free_temp_tile_data_buffers_if_possible())
			{
				decompress_and_copy_tile_data_to_vram(2, gUnknown_0861FD6C, 0, 0, 0);
				decompress_and_copy_tile_data_to_vram(2, gUnknown_0861FFF4, 0, 0, 1);
				CopyPaletteIntoBufferUnfaded(gUnknown_0861FD4C, 32, 32);
				return 0;
			}
			return 2;
		case 2:
			if (!free_temp_tile_data_buffers_if_possible())
			{
				decompress_and_copy_tile_data_to_vram(3, gUnknown_0861FC98, 0, 0, 0);
				decompress_and_copy_tile_data_to_vram(3, gUnknown_0861FCAC, 0, 0, 1);
				CopyPaletteIntoBufferUnfaded(gUnknown_0861FC78, 48, 32);
				if (sub_81C9894() == 3 || sub_81C9894() == 4)
				{
					sub_81CA850();
					return 0;
				}
				return 0;
			}
			return 2;
		case 3:
			if (!free_temp_tile_data_buffers_if_possible())
			{
				sub_81CA6E0();
				sub_81CA7D4();
				return 1;
			}
			return 2;
		case 4:
			sub_81C9FC4();
			return 1;
		case 5:
			sub_81CA714();
			sub_81CA02C();
			sub_81CA640();
			sub_81CA0C8();
			return 0;
		case 6:
			if (sub_81CA7C4())
			{
				return 2;
			}
			return 1;
		case 7:
			ShowBg(1);
			ShowBg(2);
			ShowBg(3);
			if (ptr->field_D)
			{
				sub_81C7AC0(1);
			}
			else
			{
				PlaySE(SE_PN_ON);
				sub_81C7AC0(3);
			}
			switch (sub_81C9894())
			{
				case 4:
					LoadLeftHeaderGfxForIndex(7);
				case 3:
					LoadLeftHeaderGfxForIndex(1);
					break;
				default:
					LoadLeftHeaderGfxForIndex(0);
					break;
			}
			return 0;
		case 8:
			if (!IsPaletteFadeActive())
			{
				switch (sub_81C9894())
				{
					case 4:
						sub_81C7FA0(7, 0, 0);
					case 3:
						sub_81C7FA0(1, 0, 0);
						break;
					default:
						sub_81C7FA0(0, 0, 0);
						break;
				}
				sub_81CA20C();
				titlescreen_0();
				return 1;
			}
			return 2;
		case 9:
			if (!sub_81CA324())
			{
				if(sub_81C8010())
				{
					return 2;
				}
				else
				{
					return 4;
				}
			}
			return 2;
		default:
			return 4;
	}
}























