#include "global.h"
#include "main.h"
#include "task.h"
#include "script.h"
#include "sprite.h"
#include "palette.h"
#include "menu.h"
#include "menu_helpers.h"
#include "list_menu.h"
#include "malloc.h"
#include "field_screen.h"
#include "event_data.h"
#include "bg.h"
#include "gpu_regs.h"
#include "learn_move.h"

EWRAM_DATA u8 *gUnknown_0203BC34 = 0;
EWRAM_DATA u8 gUnknown_0203BC38[8] = {0};

extern void (*gFieldCallback)(void);
extern const struct SpritePalette gUnknown_085CEBB8;
extern const struct SpriteSheet gUnknown_085CEBB0;
extern const struct BgTemplate gUnknown_085CEC28;
extern void sub_81D2824(u16);
//extern struct LearnMoveStruct *gUnknown_0203BC34;

//static struct LearnMoveStruct *sLearnMoveStruct;

static void sub_8160664(u8 taskId);
void sub_81606A0(void); //CB2_InitLearnMove
void sub_8160740(void);

void sub_81607EC(void);
void sub_816082C(void);

void sub_8160624(void) //VBlankCB_LearnMove
{
  LoadOam();
  ProcessSpriteCopyRequests();
  TransferPlttBuffer();
}

void sub_8160638(void) //TeachMoveTutorMove
{
  ScriptContext2_Enable();
  CreateTask(sub_8160664, 0xA);
  BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
}

void sub_8160664(u8 taskId)
{
  if (!gPaletteFade.active)
  {
    SetMainCallback2(sub_81606A0);
    gFieldCallback = sub_80AF168;
    DestroyTask(taskId);
  }
}

// void sub_81606A0(void) //CB2_InitLearnMove
// {
//   //AGBPrint("test\n");
//   //AGBPrintFlush();
//   //NoCashGBAPrint("test\n");
//   //Less calls than pokeruby, is it normal ?
//   ResetSpriteData();
//   FreeAllSpritePalettes();
//   ResetTasks();
//   clear_scheduled_bg_copies_to_vram();
// 
//   //LearnMoveStruct**
//   gUnknown_0203BC34 = AllocZeroed(0x118);//gUnknown_0203BC34 is a global pointer to LearnMoveStruct ?
//   //gUnknown_0203BC34->movesToLearn[0] = gSpecialVar_0x8004;
//   ((u8*)gUnknown_0203BC34)[68] = gSpecialVar_0x8004;
// 
//   SetVBlankCallback(sub_8160624);
//   //SetVBlankCallback(/*FIXME sub_8160624*/ (void()(u16))0x081D2824);
//   sub_81607EC();
//   sub_81D2824(0);
// 
//   //gUnknown_0203BC38 ?
//   // weird instruction
//   (gUnknown_0203BC38)[0] = 0;
//   (gUnknown_0203BC38)[2] = 0;
//   (gUnknown_0203BC38)[4] = 0;
// 
//   //FIXME
//   //sub_8161280();
//   __asm__("bl sub_8161280");
// 
//   //LoadSpriteSheet(/*FIXME &gUnknown_085CEBB0*/(void*)0x085CEBB0);
//   //LoadSpritePalette(/*FIXME &gUnknown_085CEBB8*/(void*)0x085CEBB8);
//   LoadSpriteSheet(&gUnknown_085CEBB0);
//   LoadSpritePalette(&gUnknown_085CEBB8);
//   //sub_81610B8();
//   //FIXME
//   __asm__("bl sub_81610B8");
// 
//   ((u8*)gUnknown_0203BC34)[274] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203BC38[0], gUnknown_0203BC38[2]);
//   FillPalette(0, 0, 2);
//   //SetMainCallback2(sub_816082C/*(void*)0x0816082C()*/);
//   //SetMainCallback2(sub_816082C/*(void*)0x0816082C()*/);
//   //FIXME
//   __asm__(
//     "ldr r0, =sub_816082C",
//     "bl SetMainCallback2"
//   );
// }

// void sub_8160740(void)
// {
//   void (*sub_81D2824)(u16) = (void*)0x081D2824;
//   void (*sub_81610B8)(void) = (void*)0x081610B8;
//   void (*sub_8161280)(void) = (void*)0x08161280;
// 
//   u8 data;
// 
//   ResetSpriteData();
//   FreeAllSpritePalettes();
//   ResetTasks();
//   clear_scheduled_bg_copies_to_vram();
// 
//   gUnknown_0203BC34 = AllocZeroed(0x118);//gUnknown_0203BC34 is a global pointer to LearnMoveStruct ?
//   gUnknown_0203BC34->partyMon = gSpecialVar_0x8004; //gUnknown_0203BC34 + 68
//   gUnknown_0203BC34->unk2C6 = gSpecialVar_0x8005; //gUnknown_0203BC34 + 69
// 
//   SetVBlankCallback(sub_8160624);
//   sub_81607EC();
// 
//   //gUnknown_0203BC38 ?
//   sub_81D2824(gUnknown_0203BC38[4]);
//   sub_8161280();
// 
//   LoadSpriteSheet(&gUnknown_085CEBB0);
//   LoadSpritePalette(&gUnknown_085CEBB8);
//   //LoadSpriteSheet(/*FIXME &gUnknown_085CEBB0*/(void*)0x085CEBB0);
//   //LoadSpritePalette(/*FIXME &gUnknown_085CEBB8*/(void*)0x085CEBB8);
// 
//   data = ListMenuInit(&gMultiuseListMenuTemplate, *gUnknown_0203BC38, *((u8*)gUnknown_0203BC38 + 2));
//   *(u8*)(gUnknown_0203BC34 + 274) = data;
//   FillPalette(0, 0, 2);
//   SetMainCallback2(/*FIXME sub_816082C*/(void*)0x0816082C);
// }

void sub_81607EC(void)
{
  ResetVramOamAndBgCntRegs();
  ResetBgsAndClearDma3BusyFlags(0);
  InitBgsFromTemplates(0, &gUnknown_085CEC28, 2);
  ResetAllBgsCoordinates();
  SetGpuReg(0, 0x1040);
  ShowBg(0);
  ShowBg(1);
  SetGpuReg(0x50, 0);
}
void sub_816082C(void)
{
  //FIXME
  //sub_8160868();
  //void(*sub_8160868)(void) = (void (*)(void))0x08160868;
  //sub_8160868();
  __asm__("bl sub_8160868");
  RunTasks();
  AnimateSprites();
  BuildOamBuffer();
  do_scheduled_bg_tilemap_copies_to_vram();
  UpdatePaletteFade();

}
