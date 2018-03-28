#include "global.h"
#include "main.h"
#include "task.h"
#include "script.h"
#include "sprite.h"
#include "palette.h"
#include "menu.h"
#include "list_menu.h"
#include "malloc.h"
#include "field_screen.h"
#include "event_data.h"
#include "learn_move.h"

extern void (*gFieldCallback)(void);
extern struct LearnMoveStruct *gUnknown_0203BC34;

// Ew, just copied from pokeruby...
const u16 gDexArrows_Pal[] = INCBIN_U16("graphics/pokedex/arrows.gbapal");
const u8 gDexArrows_Gfx[] = INCBIN_U8("graphics/pokedex/arrows.4bpp");
const struct SpritePalette gUnknown_085CEBB8 = {gDexArrows_Pal, 5526};
const struct SpriteSheet gUnknown_085CEBB0 = {gDexArrows_Gfx, sizeof(gDexArrows_Gfx), 5525};

static struct LearnMoveStruct *sLearnMoveStruct;
static void sub_8160664(u8 taskId);
void sub_81606A0(void); //CB2_InitLearnMove

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
  BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
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

void sub_81606A0(void) //CB2_InitLearnMove
{
  //Less calls than pokeruby, is it normal ?
  ResetSpriteData();
  FreeAllSpritePalettes();
  ResetTasks();
  clear_scheduled_bg_copies_to_vram();


  //LearnMoveStruct**
  //r1 = &gSpecialVar_0x8004; //What is this global ?
  //u8* partyMon = gUnknown_0203BC34 + 0x44 //partyMon ?
  //*partyMon = r1;
  gUnknown_0203BC34 = AllocZeroed(0x118);//gUnknown_0203BC34 is a global pointer to LearnMoveStruct ?
  gUnknown_0203BC34->partyMon = gSpecialVar_0x8004;

  SetVBlankCallback(sub_8160624);
  sub_81607EC();
  sub_81D2824(0);

  //gUnknown_0203BC38 ?
  (&gUnknown_0203BC38)[0] = 0;
  (&gUnknown_0203BC38)[2] = 0;
  (&gUnknown_0203BC38)[4] = 0;

  sub_8161280();
  LoadSpriteSheet(&gUnknown_085CEBB0);
  LoadSpritePalette(&gUnknown_085CEBB8);
  sub_81610B8();

  ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
  FillPalette(0, 0, 2);
  SetMainCallback2(sub_816082C);
}
