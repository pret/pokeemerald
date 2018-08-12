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

void sub_8160868(void);
void sub_8161280(void);
void sub_81610B8(void);
void sub_816082C(void);

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

// Doesn't match
void sub_81606A0(void) //CB2_InitLearnMove
{
  ResetSpriteData();
  FreeAllSpritePalettes();
  ResetTasks();
  clear_scheduled_bg_copies_to_vram();

  gUnknown_0203BC34 = AllocZeroed(0x118); //gUnknown_0203BC34 ?
  gUnknown_0203BC34[68] = gSpecialVar_0x8004;

  SetVBlankCallback(sub_8160624);
  sub_81607EC();
  sub_81D2824(0);

  //gUnknown_0203BC38 ?
  gUnknown_0203BC38[0] = 0;
  gUnknown_0203BC38[2] = 0;
  gUnknown_0203BC38[4] = 0;

  sub_8161280();

  LoadSpriteSheet(&gUnknown_085CEBB0);
  LoadSpritePalette(&gUnknown_085CEBB8);
  sub_81610B8();

  gUnknown_0203BC34[274] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203BC38[0], gUnknown_0203BC38[2]);
  FillPalette(0, 0, 2);
  SetMainCallback2(sub_816082C);
}

// Doesn't match
void sub_8160740(void)
{
  ResetSpriteData();
  FreeAllSpritePalettes();
  ResetTasks();
  clear_scheduled_bg_copies_to_vram();

  gUnknown_0203BC34 = AllocZeroed(0x118); //gUnknown_0203BC34 ?
  gUnknown_0203BC34[68] = gSpecialVar_0x8004;
  gUnknown_0203BC34[69] = gSpecialVar_0x8005;

  SetVBlankCallback(sub_8160624);
  sub_81607EC();

  //gUnknown_0203BC38 ?
  sub_81D2824(gUnknown_0203BC38[4]);
  sub_8161280();

  LoadSpriteSheet(&gUnknown_085CEBB0);
  LoadSpritePalette(&gUnknown_085CEBB8);

  gUnknown_0203BC34[274] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203BC38[0], gUnknown_0203BC38[2]);
  FillPalette(0, 0, 2);
  SetMainCallback2(sub_816082C);
}

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
  sub_8160868();
  RunTasks();
  AnimateSprites();
  BuildOamBuffer();
  do_scheduled_bg_tilemap_copies_to_vram();
  UpdatePaletteFade();
}
