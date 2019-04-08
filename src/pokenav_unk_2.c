#include "global.h"
#include "pokenav.h"

extern u8 sub_81CB0C8(u32 a);
extern bool32 sub_81CAE08(u32 a);
void *sub_81C9958(void);
u32 LoopedTask_sub_81C9A10(s32 a0);
void sub_81C99FC(void);
extern void *gUnknown_086201A0[];
struct UnknownPokenavSubstruct2
{
	void (* callback)(void);
	u32 field_4;
	u8 filler_8[4];
	u8 field_C;
	u8 field_D;
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

void *sub_81C99C0


























