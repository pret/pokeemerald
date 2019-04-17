#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "graphics.h"
#include "sound.h"
#include "constants/songs.h"
#include "decompress.h"

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
void sub_81CAA3C(void);
void sub_81CA278(void);
void sub_81CA9C8(void);
void sub_81CA2DC(void);
void sub_81C7FC4(u8, u8);
void sub_81CA818(void);
bool32 sub_81CA89C(void);
void sub_81CA9D8(void);
void sub_81CA864(void);
void sub_81CA770(void);
void sub_81C7BA4(u16 a0);
u32 sub_81C98C4(void);
void sub_81C7880(void);
void sub_81CA094(void);
void sub_81CA698(void);
void sub_81CA0EC(const u32*, u16, u16);

extern void *gUnknown_086201A0[];
extern const u32 gUnknown_0861FD6C[];
extern const u32 gUnknown_0861FFF4[];
extern const u16 gUnknown_0861FD4C[];
extern const u32 gUnknown_0861FC98[];
extern const u32 gUnknown_0861FCAC[];
extern const u16 gUnknown_0861FC78[];

extern const struct BgTemplate gUnknown_08620194[];
extern const struct CompressedSpriteSheet gUnknown_086201C4;
extern const struct SpritePalette gUnknown_086201D4;
extern const struct SpriteTemplate gUnknown_0862034C;
extern const u32 gUnknown_08620244[];
extern const u32 gUnknown_08620240[];

struct UnknownPokenavSubstruct2
{
	bool32 (* callback)(void);
	u32 field_4;
	u8 windowId;
	u8 filler_9[3];
	u8 field_C;
	u8 field_D;
	u8 filler_E[0x1E];
	struct Sprite *field_2C;
	u8 filler_30[0x5C];
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

u32 sub_81C9C6C(u32 a0)
{
	switch(a0)	
	{
		case 0:
			sub_81CAA3C();
			sub_81CA278();
			sub_81CA714();
			PlaySE(SE_SELECT);
			return 0;	
		case 1:
			if (sub_81CA324())
			{
				return 2;
			}
			else if (sub_81CA7C4())
			{
				return 2;
			}
			else
			{
				return 4;
			}
		default:
			return 4;
	}
}

u32 sub_81C9CA8(s32 a0)
{
	switch (a0)
	{
		case 0:
			sub_81CA9C8();
			sub_81CA2DC();
			sub_81C7FC4(0, 0);
			PlaySE(SE_SELECT);
			return 0;
		case 1:
			if (!sub_81CA324())
			{
				if (!sub_81C8010())
				{
					sub_81CA0C8();
					LoadLeftHeaderGfxForIndex(1);
					return 0;
				}
			}
			return 2;
		case 2:
			sub_81CA20C();
			sub_81C7FA0(1, 0, 0);
			sub_81CA818();
			sub_81CA714();
			return 0;
		case 3:
			if (!sub_81CA324() && !sub_81C8010() && !sub_81CA89C())
			{
				if (sub_81CA7C4())
				{
					return 2;
				}
				else 
				{
					sub_81CA9D8();
					return 4;
				}
			}
			return 2;
		default:
			return 4;
	}
}

u32 sub_81C9D44(s32 a0)
{
	switch (a0)
	{
		case 0:
			sub_81CA9C8();
			sub_81CA2DC();
			sub_81C7FC4(1, 0);
			return 0;
		case 1:
			if (!sub_81CA324())
			{
				if (!sub_81C8010())
				{
					sub_81CA0C8();
					LoadLeftHeaderGfxForIndex(0);
					return 0;
				}
			}
			return 2;
		case 2:
			sub_81CA20C();
			sub_81C7FA0(0, 0, 0);
			sub_81CA864();
			sub_81CA714();
			return 0;
		case 3:
			if (!sub_81CA324() && !sub_81C8010() && !sub_81CA89C())
			{
				if (sub_81CA7C4())
				{
					return 2;
				}
				else 
				{
					sub_81CA9D8();
					return 4;
				}
			}
			return 2;
		default:
			return 4;
	}
}

u32 sub_81C9DD8(s32 a0)
{
	switch (a0)
	{
		case 0:
			sub_81CA9C8();
			sub_81CA2DC();
			PlaySE(SE_SELECT);
			return 0;
		case 1:
			if (!sub_81CA324())
			{
				LoadLeftHeaderGfxForIndex(7);
				sub_81CA0C8();
				return 0;
			}
			return 2;
		case 2:
			sub_81CA20C();
			sub_81C7FA0(7, 0, 0);
			sub_81CA714();
			return 0;
		case 3:
			if (!sub_81CA324() && !sub_81C8010())
			{
				if(sub_81CA89C())
				{
					return 2;	
				}
				else
				{
					sub_81CA9D8();
					return 4;
				}
			}
			return 2;	
		default:
			return 4;
	}
}

u32 sub_81C9E58(s32 a0)
{
	switch (a0)
	{
		case 0:
			sub_81CA9C8();
			sub_81CA2DC();
			sub_81C7FC4(7, 0);
			return 0;
		case 1:
			if (!sub_81CA324())
			{
				if (!sub_81C8010())
				{
					sub_81CA0C8();
					return 0;
				}
			}
			return 2;
		case 2:
			sub_81CA20C();
			sub_81CA714();
			return 0;
		case 3:
			if (!sub_81CA324())
			{
				if(sub_81CA89C())
				{
					return 2;	
				}
				else
				{
					sub_81CA9D8();
					return 4;
				}
			}
			return 2;	
		default:
			return 4;
	}
}

u32 sub_81C9EC8(s32 a0)
{
	switch(a0)
	{
		case 0:
			PlaySE(SE_HAZURE);
			sub_81CA770();
			return 0;	
		case 1:
			if (IsDma3ManagerBusyWithBgCopy())
			{
				return 2;
			}
			else
			{
				return 4;
			}
		default:
			return 4;
	}
}

u32 sub_81C9EF8(s32 a0)
{
	switch(a0)
	{
		case 0:
			PlaySE(SE_SELECT);
			sub_81CA714();
			return 0;	
		case 1:
			if (IsDma3ManagerBusyWithBgCopy())
			{
				return 2;
			}
			else
			{
				return 4;
			}
		default:
			return 4;
	}
}

u32 sub_81C9F28(s32 a0)
{
	switch (a0)
	{
		case 0:
			sub_81C7BA4(sub_81C98C4());
			return 0;
		case 1:
			if (!IsDma3ManagerBusyWithBgCopy_())
			{
				sub_81C7880();
				sub_81CA9C8();
				sub_81CA2DC();
				switch (sub_81C9894())
				{
					case 4:
						sub_81C7FC4(7, 0);
					case 3:
						sub_81C7FC4(1, 0);
						break;
					default:
						sub_81C7FC4(0, 0);
						break;
				}
				PlaySE(SE_SELECT);
				return 0;
			}
			return 2;
		case 2:
			if (!sub_81CA324())
			{
				if (!sub_81C8010())
				{
					sub_81C7AC0(0);
					return 0;
				}
			}
			return 2;
		case 3:
			if (!IsPaletteFadeActive())
			{
				return 4;
			}
			return 2;	
		default:
			return 4;
	}
}

void sub_81C9FC4(void)
{
	u32 i;
	const struct CompressedSpriteSheet *ptr;
	for(i = 0, ptr = &gUnknown_086201C4; i < 2; i++)
	{
		LoadCompressedSpriteSheet(ptr);
		ptr++;
	}
	Pokenav_AllocAndLoadPalettes(&gUnknown_086201D4);
}

void sub_81C9FEC(void)
{
	FreeSpriteTilesByTag(3);
	FreeSpriteTilesByTag(1);
	FreeSpritePaletteByTag(4);
	FreeSpritePaletteByTag(5);
	FreeSpritePaletteByTag(6);
	FreeSpritePaletteByTag(7);
	FreeSpritePaletteByTag(8);
	FreeSpritePaletteByTag(3);
	sub_81CA094();
	sub_81CA698();
}

#ifdef NONMATCHING
void sub_81CA02C(void)
{
	struct UnknownPokenavSubstruct2 *ptr;
	u32 i;
	u32 j;
	u32 var;
	struct Sprite **var2;
	struct Sprite *var3;
	struct Sprite *var4;
	u32 k;
	
	ptr = GetSubstructPtr(2);
	i = 0;
	var4 = ptr->field_2C;
	
	for(i = 0; i < 6; i++)
	{
		j = 0;
		var = (4 * i);
		var += j;
		
		var <<= 18;
		var += 0x280000;
		var2 = (struct Sprite **) (i * 16 + var4);
		
		while(j < 4)
		{
			var3 = &gSprites[CreateSprite(&gUnknown_0862034C, 140, var >> 16, 3)];
			*var2 = var3;
			var2++;
			var3->pos2.x = 32 * j++;
		}
	}
}
#else
NAKED
void sub_81CA02C(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	movs r0, 0x2\n\
	bl GetSubstructPtr\n\
	movs r2, 0\n\
	adds r0, 0x2C\n\
	mov r8, r0\n\
_081CA03E:\n\
	movs r4, 0\n\
	lsls r0, r2, 2\n\
	lsls r1, r2, 4\n\
	adds r7, r2, 0x1\n\
	adds r0, r2\n\
	lsls r0, 18\n\
	movs r2, 0xA0\n\
	lsls r2, 14\n\
	adds r5, r0, r2\n\
	mov r0, r8\n\
	adds r6, r1, r0\n\
_081CA054:\n\
	ldr r0, =gUnknown_0862034C\n\
	movs r1, 0x8C\n\
	asrs r2, r5, 16\n\
	movs r3, 0x3\n\
	bl CreateSprite\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	lsls r1, r0, 4\n\
	adds r1, r0\n\
	lsls r1, 2\n\
	ldr r0, =gSprites\n\
	adds r1, r0\n\
	stm r6!, {r1}\n\
	lsls r0, r4, 5\n\
	strh r0, [r1, 0x24]\n\
	adds r4, 0x1\n\
	cmp r4, 0x3\n\
	ble _081CA054\n\
	adds r2, r7, 0\n\
	cmp r2, 0x5\n\
	ble _081CA03E\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
");
}
#endif // NONMATCHING

#ifdef NONMATCHING
void sub_81CA094(void)
{
	struct UnknownPokenavSubstruct2 *ptr;
	s32 i;
	s32 j;
	struct Sprite *var;
	struct Sprite **var3;
	
	ptr = GetSubstructPtr(2);
	
	for(i = 0, var = ptr->field_2C; i < 6; i++)
	{
		var3 = (struct Sprite **) var + i * 4;
		
	
		for(j = 0; j < 4; j++)
		{
			FreeSpriteOamMatrix(*var3);
			DestroySprite(*var3++);
		}
	}
}
#else
NAKED
void sub_81CA094(void)
{
    asm_unified("\n\
  	push {r4-r7,lr}\n\
	movs r0, 0x2\n\
	bl GetSubstructPtr\n\
	movs r1, 0\n\
	adds r7, r0, 0\n\
	adds r7, 0x2C\n\
_081CA0A2:\n\
	lsls r0, r1, 4\n\
	adds r6, r1, 0x1\n\
	adds r4, r0, r7\n\
	movs r5, 0x3\n\
_081CA0AA:\n\
	ldr r0, [r4]\n\
	bl FreeSpriteOamMatrix\n\
	ldm r4!, {r0}\n\
	bl DestroySprite\n\
	subs r5, 0x1\n\
	cmp r5, 0\n\
	bge _081CA0AA\n\
	adds r1, r6, 0\n\
	cmp r1, 0x5\n\
	ble _081CA0A2\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
");
}
#endif // NONMATCHING

#ifdef NONMATCHING
void sub_81CA0C8(void)
{
	u32 something;
	u16 *ptr;
	something = sub_81C9894() * 7;
	ptr = (u16 *) (gUnknown_08620240 + something);
	sub_81CA0EC(&gUnknown_08620244[something], *ptr, *(ptr + 1));
	
}
#else
NAKED
void sub_81CA0C8(void)
{
    asm_unified("\n\
	push {lr}\n\
	bl sub_81C9894\n\
	lsls r2, r0, 3\n\
	subs r2, r0\n\
	lsls r2, 2\n\
	ldr r1, =gUnknown_08620244\n\
	adds r0, r2, r1\n\
	subs r1, 0x4\n\
	adds r2, r1\n\
	ldrh r1, [r2]\n\
	ldrh r2, [r2, 0x2]\n\
	bl sub_81CA0EC\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
");
}
#endif // NONMATCHING


















