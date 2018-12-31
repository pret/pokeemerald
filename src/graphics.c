#include "global.h"

const u32 gBattleTextboxTiles[] = INCBIN_U32("graphics/battle_interface/textbox.4bpp.lz");
const u32 gBattleTextboxPalette[] = INCBIN_U32("graphics/battle_interface/textbox.gbapal.lz");
const u32 gBattleTextboxTilemap[] = INCBIN_U32("graphics/battle_interface/textbox_map.bin.lz");

const u32 gMonStillFrontPic_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/front_pics/circled_question_mark_still_front_pic.4bpp.lz");
const u32 gMonBackPic_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/back_pics/circled_question_mark_back_pic.4bpp.lz");
const u32 gMonPalette_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/palettes/circled_question_mark_palette.gbapal.lz");
const u32 gMonShinyPalette_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/palettes/circled_question_mark_shiny_palette.gbapal.lz");

const u32 gUnusedGfx_OldCharmap[] = INCBIN_U32("graphics/unused/old_charmap.4bpp.lz"); // japanese table and bunch of stuff
const u32 gUnusedTimemap_OldCharmap[] = INCBIN_U32("graphics/unused/old_charmap.bin.lz");
const u32 gUnusedPal_OldCharmap[] = INCBIN_U32("graphics/unused/old_charmap.gbapal.lz");

const u32 gSmokescreenImpactTiles[] = INCBIN_U32("graphics/battle_anims/sprites/smokescreen_impact.4bpp.lz");
const u32 gSmokescreenImpactPalette[] = INCBIN_U32("graphics/battle_anims/sprites/smokescreen_impact.gbapal.lz");

#include "data/graphics/interface_pokeballs.h"

const u32 gBlankGfxCompressed[] = INCBIN_U32("graphics/interface/blank.4bpp.lz");

// Battle anims
const u32 gBattleAnimSpriteSheet_146[] = INCBIN_U32("graphics/battle_anims/sprites/146.4bpp.lz");
const u32 gBattleAnimSpriteSheet_000[] = INCBIN_U32("graphics/battle_anims/sprites/000.4bpp.lz");
const u32 gBattleAnimSpriteSheet_003[] = INCBIN_U32("graphics/battle_anims/sprites/003.4bpp.lz");
const u32 gBattleAnimSpriteSheet_004[] = INCBIN_U32("graphics/battle_anims/sprites/004.4bpp.lz");
const u32 gBattleAnimSpriteSheet_005[] = INCBIN_U32("graphics/battle_anims/sprites/005.4bpp.lz");
const u32 gBattleAnimSpriteSheet_006[] = INCBIN_U32("graphics/battle_anims/sprites/006.4bpp.lz");

const u32 gBattleAnimSpritePalette_115[] = INCBIN_U32("graphics/battle_anims/sprites/115.gbapal.lz");
const u32 gBattleAnimSpritePalette_000[] = INCBIN_U32("graphics/battle_anims/sprites/000.gbapal.lz");
const u32 gBattleAnimSpritePalette_003[] = INCBIN_U32("graphics/battle_anims/sprites/003.gbapal.lz");
const u32 gBattleAnimSpritePalette_004[] = INCBIN_U32("graphics/battle_anims/sprites/004.gbapal.lz");
const u32 gBattleAnimSpritePalette_005[] = INCBIN_U32("graphics/battle_anims/sprites/005.gbapal.lz");
const u32 gBattleAnimSpritePalette_006[] = INCBIN_U32("graphics/battle_anims/sprites/006.gbapal.lz");

const u32 gBattleAnimSpriteSheet_161[] = INCBIN_U32("graphics/battle_anims/sprites/161.4bpp.lz");
const u32 gBattleAnimSpritePalette_161[] = INCBIN_U32("graphics/battle_anims/sprites/161.gbapal.lz");

const u32 gBattleAnimSpriteSheet_007[] = INCBIN_U32("graphics/battle_anims/sprites/007.4bpp.lz");
const u32 gBattleAnimSpritePalette_007[] = INCBIN_U32("graphics/battle_anims/sprites/007.gbapal.lz");

const u32 gBattleAnimSpriteSheet_008[] = INCBIN_U32("graphics/battle_anims/sprites/008.4bpp.lz");
const u32 gBattleAnimSpritePalette_008[] = INCBIN_U32("graphics/battle_anims/sprites/008.gbapal.lz");

const u32 gBattleAnimSpritePalette_010[] = INCBIN_U32("graphics/battle_anims/sprites/010.gbapal.lz");
const u32 gBattleAnimSpriteSheet_010[] = INCBIN_U32("graphics/battle_anims/sprites/010.4bpp.lz");

const u32 gBattleAnimSpriteSheet_009[] = INCBIN_U32("graphics/battle_anims/sprites/009.4bpp.lz");
const u32 gBattleAnimSpritePalette_009[] = INCBIN_U32("graphics/battle_anims/sprites/009.gbapal.lz");

const u32 gBattleAnimSpriteSheet_011[] = INCBIN_U32("graphics/battle_anims/sprites/011.4bpp.lz");
const u32 gBattleAnimSpritePalette_011[] = INCBIN_U32("graphics/battle_anims/sprites/011.gbapal.lz");

const u32 gBattleAnimSpriteSheet_012[] = INCBIN_U32("graphics/battle_anims/sprites/012.4bpp.lz");
const u32 gBattleAnimSpritePalette_012[] = INCBIN_U32("graphics/battle_anims/sprites/012.gbapal.lz");

const u32 gBattleAnimSpriteSheet_152[] = INCBIN_U32("graphics/battle_anims/sprites/152.4bpp.lz");
const u32 gBattleAnimSpritePalette_152[] = INCBIN_U32("graphics/battle_anims/sprites/152.gbapal.lz");

const u32 gBattleAnimSpriteSheet_013[] = INCBIN_U32("graphics/battle_anims/sprites/013.4bpp.lz");
const u32 gBattleAnimSpritePalette_013[] = INCBIN_U32("graphics/battle_anims/sprites/013.gbapal.lz");

const u32 gBattleAnimSpriteSheet_015[] = INCBIN_U32("graphics/battle_anims/sprites/015.4bpp.lz");
const u32 gBattleAnimSpritePalette_015[] = INCBIN_U32("graphics/battle_anims/sprites/015.gbapal.lz");

const u32 gBattleAnimSpriteSheet_016[] = INCBIN_U32("graphics/battle_anims/sprites/016.4bpp.lz");
const u32 gBattleAnimSpritePalette_016[] = INCBIN_U32("graphics/battle_anims/sprites/016.gbapal.lz");

const u32 gBattleAnimSpriteSheet_017[] = INCBIN_U32("graphics/battle_anims/sprites/017.4bpp.lz");

const u32 gUnknownGfx_C035B8[] = INCBIN_U32("graphics/unknown/unknown_C035B8.4bpp.lz");

const u32 gBattleAnimSpritePalette_019[] = INCBIN_U32("graphics/battle_anims/sprites/019.gbapal.lz");
const u32 gBattleAnimSpriteSheet_019[] = INCBIN_U32("graphics/battle_anims/sprites/019.4bpp.lz");

const u32 gBattleAnimSpriteSheet_020[] = INCBIN_U32("graphics/battle_anims/sprites/020.4bpp.lz");
const u32 gBattleAnimSpritePalette_020[] = INCBIN_U32("graphics/battle_anims/sprites/020.gbapal.lz");

const u32 gBattleAnimSpritePalette_023[] = INCBIN_U32("graphics/battle_anims/sprites/023.gbapal.lz");
const u32 gBattleAnimSpriteSheet_023[] = INCBIN_U32("graphics/battle_anims/sprites/023.4bpp.lz");

const u32 gUnused_BattleSpritePalette_023[] = INCBIN_U32("graphics/unused/battle_anim_023.gbapal.lz");

const u32 gUnusedGfx_MusicNotes[] = INCBIN_U32("graphics/unused/music_notes.4bpp.lz");

const u32 gBattleAnimSpritePalette_021[] = INCBIN_U32("graphics/battle_anims/sprites/021.gbapal.lz");
const u32 gBattleAnimSpriteSheet_021[] = INCBIN_U32("graphics/battle_anims/sprites/021.4bpp.lz");

const u32 gBattleAnimSpritePalette_022[] = INCBIN_U32("graphics/battle_anims/sprites/022.gbapal.lz");

const u32 gBattleAnimSpritePalette_025[] = INCBIN_U32("graphics/battle_anims/sprites/025.gbapal.lz");
const u32 gBattleAnimSpriteSheet_025[] = INCBIN_U32("graphics/battle_anims/sprites/025.4bpp.lz");

const u32 gBattleAnimSpriteSheet_024[] = INCBIN_U32("graphics/battle_anims/sprites/024.4bpp.lz");
const u32 gBattleAnimSpritePalette_024[] = INCBIN_U32("graphics/battle_anims/sprites/024.gbapal.lz");

const u32 gBattleAnimSpriteSheet_031[] = INCBIN_U32("graphics/battle_anims/sprites/031.4bpp.lz");
const u32 gBattleAnimSpritePalette_031[] = INCBIN_U32("graphics/battle_anims/sprites/031.gbapal.lz");

const u32 gBattleAnimSpritePalette_032[] = INCBIN_U32("graphics/battle_anims/sprites/032.gbapal.lz");
const u32 gBattleAnimSpriteSheet_032[] = INCBIN_U32("graphics/battle_anims/sprites/032.4bpp.lz");

const u32 gBattleAnimSpriteSheet_026[] = INCBIN_U32("graphics/battle_anims/sprites/026.4bpp.lz");
const u32 gBattleAnimSpritePalette_026[] = INCBIN_U32("graphics/battle_anims/sprites/026.gbapal.lz");

const u32 gBattleAnimSpritePalette_027[] = INCBIN_U32("graphics/battle_anims/sprites/027.gbapal.lz");
const u32 gBattleAnimSpriteSheet_027[] = INCBIN_U32("graphics/battle_anims/sprites/027.4bpp.lz");

const u32 gBattleAnimSpritePalette_028[] = INCBIN_U32("graphics/battle_anims/sprites/028.gbapal.lz");
const u32 gBattleAnimSpriteSheet_028[] = INCBIN_U32("graphics/battle_anims/sprites/028.4bpp.lz");

const u32 gBattleAnimSpriteSheet_029[] = INCBIN_U32("graphics/battle_anims/sprites/029.4bpp.lz");
const u32 gBattleAnimSpritePalette_029[] = INCBIN_U32("graphics/battle_anims/sprites/029.gbapal.lz");

const u32 gBattleAnimSpriteSheet_030[] = INCBIN_U32("graphics/battle_anims/sprites/030.4bpp.lz");
const u32 gBattleAnimSpritePalette_030[] = INCBIN_U32("graphics/battle_anims/sprites/030.gbapal.lz");

const u32 gBattleAnimSpritePalette_033[] = INCBIN_U32("graphics/battle_anims/sprites/033.gbapal.lz");
const u32 gBattleAnimSpriteSheet_033[] = INCBIN_U32("graphics/battle_anims/sprites/033.4bpp.lz");

const u32 gBattleAnimSpriteSheet_034[] = INCBIN_U32("graphics/battle_anims/sprites/034.4bpp.lz");
const u32 gBattleAnimSpriteSheet_035[] = INCBIN_U32("graphics/battle_anims/sprites/035.4bpp.lz");

const u32 gBattleAnimSpritePalette_036[] = INCBIN_U32("graphics/battle_anims/sprites/036.gbapal.lz");
const u32 gBattleAnimSpriteSheet_036[] = INCBIN_U32("graphics/battle_anims/sprites/036.4bpp.lz");

const u32 gBattleAnimSpriteSheet_037[] = INCBIN_U32("graphics/battle_anims/sprites/037.4bpp.lz");

const u32 gUnknownGfx_C06D98[] = INCBIN_U32("graphics/unknown/unknown_C06D98.4bpp.lz");
const u32 gUnknownPal_C06D98[] = INCBIN_U32("graphics/unknown/unknown_C06D98.gbapal.lz");
const u32 gUnknownPal_C06D98_2[] = INCBIN_U32("graphics/unknown/unknown_C06D98_2.gbapal.lz");

// old battle interface data, unused

const u32 gOldBattleInterfaceGfx[] = INCBIN_U32("graphics/unused/obi1.4bpp.lz");
const u32 gOldBattleInterfacePal_1_2_3[] = INCBIN_U32("graphics/unused/obi_palpak1.gbapal.lz"); // palettes 1-3
const u32 gOldBattleInterfacePal4[] = INCBIN_U32("graphics/unused/old_pal4.gbapal.lz"); // 4 is by itself
const u32 gOldBattleInterfacePal_5_6_7[] = INCBIN_U32("graphics/unused/obi_palpak3.gbapal.lz"); // palettes 5-7
const u32 gOldBattleInterfaceGfx2[] = INCBIN_U32("graphics/unused/obi2.4bpp.lz");
const u32 gOldBattleInterfaceTilemap[] = INCBIN_U32("graphics/unused/old_battle_interface_tilemap.bin.lz");

const u32 gBattleAnimSpritePalette_038[] = INCBIN_U32("graphics/battle_anims/sprites/038.gbapal.lz");
const u32 gBattleAnimSpritePalette_039[] = INCBIN_U32("graphics/battle_anims/sprites/039.gbapal.lz");

const u32 gBattleAnimSpriteSheet_038[] = INCBIN_U32("graphics/battle_anims/sprites/038.4bpp.lz");
const u32 gBattleAnimSpriteSheet_039[] = INCBIN_U32("graphics/battle_anims/sprites/039.4bpp.lz");
const u32 gBattleAnimSpriteSheet_040[] = INCBIN_U32("graphics/battle_anims/sprites/040.4bpp.lz");
const u32 gBattleAnimSpriteSheet_041[] = INCBIN_U32("graphics/battle_anims/sprites/041.4bpp.lz");

const u32 gPartyMenuHpBar_Gfx[] = INCBIN_U32("graphics/interface/party_menu_hpbar.4bpp.lz");

const u32 gBattleAnimSpriteSheet_042[] = INCBIN_U32("graphics/battle_anims/sprites/042.4bpp.lz");

const u32 gBattleAnimSpritePalette_042[] = INCBIN_U32("graphics/battle_anims/sprites/042.gbapal.lz");

const u32 gBattleAnimSpriteSheet_043[] = INCBIN_U32("graphics/battle_anims/sprites/043.4bpp.lz");
const u32 gBattleAnimSpritePalette_043[] = INCBIN_U32("graphics/battle_anims/sprites/043.gbapal.lz");

const u32 gBattleAnimSpritePalette_044[] = INCBIN_U32("graphics/battle_anims/sprites/044.gbapal.lz");
const u32 gBattleAnimSpriteSheet_044[] = INCBIN_U32("graphics/battle_anims/sprites/044.4bpp.lz");

const u32 gBattleAnimSpritePalette_045[] = INCBIN_U32("graphics/battle_anims/sprites/045.gbapal.lz");
const u32 gBattleAnimSpriteSheet_045[] = INCBIN_U32("graphics/battle_anims/sprites/045.4bpp.lz");

const u32 gUnknown_08C08F0C[] = INCBIN_U32("graphics/battle_interface/unused_window.4bpp.lz");
const u32 gUnknown_08C093C8[] = INCBIN_U32("graphics/battle_interface/unused_window.gbapal.lz");

const u32 gUnknown_08C093F0[] = INCBIN_U32("graphics/interface/hp_numbers.4bpp.lz");

const u32 gBattleAnimSpriteSheet_046[] = INCBIN_U32("graphics/battle_anims/sprites/046.4bpp.lz");
const u32 gBattleAnimSpritePalette_046[] = INCBIN_U32("graphics/battle_anims/sprites/046.gbapal.lz");

const u32 gBattleAnimSpritePalette_047[] = INCBIN_U32("graphics/battle_anims/sprites/047.gbapal.lz");

const u32 gUnusedGfx_Window2[] = INCBIN_U32("graphics/battle_interface/unused_window2.4bpp.lz");
const u32 gUnusedGfx_Window2Bar[] = INCBIN_U32("graphics/battle_interface/unused_window2bar.4bpp.lz");

const u32 gBattleAnimSpriteSheet_048[] = INCBIN_U32("graphics/battle_anims/sprites/048.4bpp.lz");
const u32 gBattleAnimSpritePalette_048[] = INCBIN_U32("graphics/battle_anims/sprites/048.gbapal.lz");

const u32 gBattleAnimSpritePalette_049[] = INCBIN_U32("graphics/battle_anims/sprites/049.gbapal.lz");
const u32 gBattleAnimSpritePalette_050[] = INCBIN_U32("graphics/battle_anims/sprites/050.gbapal.lz");

const u32 gBattleAnimSpriteSheet_050[] = INCBIN_U32("graphics/battle_anims/sprites/050.4bpp.lz");
const u32 gBattleAnimSpriteSheet_051[] = INCBIN_U32("graphics/battle_anims/sprites/051.4bpp.lz");
const u32 gBattleAnimSpriteSheet_052[] = INCBIN_U32("graphics/battle_anims/sprites/052.4bpp.lz");

const u32 gUnusedGfx_LineSketch[] = INCBIN_U32("graphics/unused/line_sketch.4bpp.lz");
const u32 gUnusedPal_LineSketch[] = INCBIN_U32("graphics/unused/line_sketch.gbapal.lz");

const u32 gBattleAnimSpriteSheet_054[] = INCBIN_U32("graphics/battle_anims/sprites/054.4bpp.lz");
const u32 gBattleAnimSpritePalette_054[] = INCBIN_U32("graphics/battle_anims/sprites/054.gbapal.lz");

const u32 gBattleAnimSpriteSheet_056[] = INCBIN_U32("graphics/battle_anims/sprites/056.4bpp.lz");
const u32 gBattleAnimSpritePalette_056[] = INCBIN_U32("graphics/battle_anims/sprites/056.gbapal.lz");

const u32 gBattleAnimSpriteSheet_055[] = INCBIN_U32("graphics/battle_anims/sprites/055.4bpp.lz");

const u32 gBattleAnimSpriteSheet_057[] = INCBIN_U32("graphics/battle_anims/sprites/057.4bpp.lz");
const u32 gBattleAnimSpritePalette_057[] = INCBIN_U32("graphics/battle_anims/sprites/057.gbapal.lz");

const u32 gBattleAnimSpriteSheet_058[] = INCBIN_U32("graphics/battle_anims/sprites/058.4bpp.lz");
const u32 gBattleAnimSpritePalette_058[] = INCBIN_U32("graphics/battle_anims/sprites/058.gbapal.lz");

const u32 gBattleAnimSpriteSheet_059[] = INCBIN_U32("graphics/battle_anims/sprites/059.4bpp.lz");
const u32 gBattleAnimSpritePalette_059[] = INCBIN_U32("graphics/battle_anims/sprites/059.gbapal.lz");

const u32 gBattleAnimSpriteSheet_060[] = INCBIN_U32("graphics/battle_anims/sprites/060.4bpp.lz");
const u32 gBattleAnimSpritePalette_060[] = INCBIN_U32("graphics/battle_anims/sprites/060.gbapal.lz");

const u32 gBattleAnimSpriteSheet_061[] = INCBIN_U32("graphics/battle_anims/sprites/061.4bpp.lz");
const u32 gBattleAnimSpritePalette_061[] = INCBIN_U32("graphics/battle_anims/sprites/061.gbapal.lz");

const u32 gBattleAnimSpriteSheet_062[] = INCBIN_U32("graphics/battle_anims/sprites/062.4bpp.lz");
const u32 gBattleAnimSpritePalette_062[] = INCBIN_U32("graphics/battle_anims/sprites/062.gbapal.lz");

const u32 gBattleAnimSpriteSheet_063[] = INCBIN_U32("graphics/battle_anims/sprites/063.4bpp.lz");
const u32 gBattleAnimSpritePalette_063[] = INCBIN_U32("graphics/battle_anims/sprites/063.gbapal.lz");

const u32 gUnusedGfx_Metronome[] = INCBIN_U32("graphics/unused/metronome_hand_small.4bpp.lz"); // unused, was for metronome at one point

const u32 gBattleAnimSpritePalette_091[] = INCBIN_U32("graphics/battle_anims/sprites/091.gbapal.lz");

const u32 gBattleAnimSpriteSheet_065[] = INCBIN_U32("graphics/battle_anims/sprites/065.4bpp.lz");
const u32 gBattleAnimSpritePalette_065[] = INCBIN_U32("graphics/battle_anims/sprites/065.gbapal.lz");

const u32 gBattleAnimSpriteSheet_066[] = INCBIN_U32("graphics/battle_anims/sprites/066.4bpp.lz");
const u32 gBattleAnimSpritePalette_066[] = INCBIN_U32("graphics/battle_anims/sprites/066.gbapal.lz");

const u32 gBattleAnimSpriteSheet_070[] = INCBIN_U32("graphics/battle_anims/sprites/070.4bpp.lz");
const u32 gBattleAnimSpritePalette_070[] = INCBIN_U32("graphics/battle_anims/sprites/070.gbapal.lz");

const u32 gBattleAnimSpriteSheet_071[] = INCBIN_U32("graphics/battle_anims/sprites/071.4bpp.lz");

const u32 gBattleAnimSpriteSheet_072[] = INCBIN_U32("graphics/battle_anims/sprites/072.4bpp.lz");
const u32 gBattleAnimSpritePalette_072[] = INCBIN_U32("graphics/battle_anims/sprites/072.gbapal.lz");

const u32 gBattleAnimSpriteSheet_073[] = INCBIN_U32("graphics/battle_anims/sprites/073.4bpp.lz");
const u32 gBattleAnimSpritePalette_073[] = INCBIN_U32("graphics/battle_anims/sprites/073.gbapal.lz");

const u32 gBattleAnimSpriteSheet_075[] = INCBIN_U32("graphics/battle_anims/sprites/075.4bpp.lz");
const u32 gBattleAnimSpritePalette_075[] = INCBIN_U32("graphics/battle_anims/sprites/075.gbapal.lz");

const u32 gBattleAnimSpriteSheet_078[] = INCBIN_U32("graphics/battle_anims/sprites/078.4bpp.lz");
const u32 gBattleAnimSpritePalette_078[] = INCBIN_U32("graphics/battle_anims/sprites/078.gbapal.lz");

const u32 gBattleAnimSpriteSheet_079[] = INCBIN_U32("graphics/battle_anims/sprites/079.4bpp.lz");

const u32 gBattleAnimSpriteSheet_080[] = INCBIN_U32("graphics/battle_anims/sprites/080.4bpp.lz");
const u32 gBattleAnimSpritePalette_080[] = INCBIN_U32("graphics/battle_anims/sprites/080.gbapal.lz");

const u32 gBattleAnimSpriteSheet_081[] = INCBIN_U32("graphics/battle_anims/sprites/081.4bpp.lz");
const u32 gBattleAnimSpritePalette_081[] = INCBIN_U32("graphics/battle_anims/sprites/081.gbapal.lz");

const u16 gUnknown_C0CA1C[] = INCBIN_U16("graphics/unknown/unknown_C0CA1C.bin");
const u16 gUnknown_C0CA40[] = INCBIN_U16("graphics/unknown/unknown_C0CA40.bin");
const u16 gUnknown_C0CA64[] = INCBIN_U16("graphics/unknown/unknown_C0CA64.bin");
const u32 gUnusedGfx8bpp_LineSketch2[] = INCBIN_U32("graphics/unused/line_sketch_2.8bpp.lz");
const u16 gUnknown_C0CAE0[] = INCBIN_U16("graphics/unknown/unknown_C0CAE0.bin");
const u32 gUnusedTilemap_LineSketch2[] = INCBIN_U32("graphics/unused/line_sketch_2.bin.lz");

const u32 gBattleAnimSpriteSheet_082[] = INCBIN_U32("graphics/battle_anims/sprites/082.4bpp.lz");
const u32 gBattleAnimSpritePalette_082[] = INCBIN_U32("graphics/battle_anims/sprites/082.gbapal.lz");

const u32 gBattleAnimSpritePalette_083[] = INCBIN_U32("graphics/battle_anims/sprites/083.gbapal.lz");
const u32 gBattleAnimSpritePalette_084[] = INCBIN_U32("graphics/battle_anims/sprites/084.gbapal.lz");
const u32 gBattleAnimSpritePalette_085[] = INCBIN_U32("graphics/battle_anims/sprites/085.gbapal.lz");
const u32 gBattleAnimSpritePalette_086[] = INCBIN_U32("graphics/battle_anims/sprites/086.gbapal.lz");
const u32 gBattleAnimSpritePalette_088[] = INCBIN_U32("graphics/battle_anims/sprites/088.gbapal.lz");
const u32 gBattleAnimSpritePalette_089[] = INCBIN_U32("graphics/battle_anims/sprites/089.gbapal.lz");
const u32 gBattleAnimSpritePalette_090[] = INCBIN_U32("graphics/battle_anims/sprites/090.gbapal.lz");
const u32 gBattleAnimSpritePalette_092[] = INCBIN_U32("graphics/battle_anims/sprites/092.gbapal.lz");
const u32 gBattleAnimSpritePalette_093[] = INCBIN_U32("graphics/battle_anims/sprites/093.gbapal.lz");
const u32 gBattleAnimSpritePalette_094[] = INCBIN_U32("graphics/battle_anims/sprites/094.gbapal.lz");

const u32 gUnknown_D0D2B4[] = INCBIN_U32("graphics/unknown/unknown_D0D2B4.bin.lz");

const u32 gBattleAnimSpritePalette_095[] = INCBIN_U32("graphics/battle_anims/sprites/095.gbapal.lz");
const u32 gBattleAnimSpritePalette_096[] = INCBIN_U32("graphics/battle_anims/sprites/096.gbapal.lz");
const u32 gBattleAnimSpritePalette_097[] = INCBIN_U32("graphics/battle_anims/sprites/097.gbapal.lz");
const u32 gBattleAnimSpritePalette_100[] = INCBIN_U32("graphics/battle_anims/sprites/100.gbapal.lz");
const u32 gBattleAnimSpritePalette_101[] = INCBIN_U32("graphics/battle_anims/sprites/101.gbapal.lz");
const u32 gBattleAnimSpritePalette_103[] = INCBIN_U32("graphics/battle_anims/sprites/103.gbapal.lz");

const u32 gBattleAnimSpriteSheet_083[] = INCBIN_U32("graphics/battle_anims/sprites/083.4bpp.lz");
const u32 gBattleAnimSpriteSheet_084[] = INCBIN_U32("graphics/battle_anims/sprites/084.4bpp.lz");
const u32 gBattleAnimSpriteSheet_085[] = INCBIN_U32("graphics/battle_anims/sprites/085.4bpp.lz");
const u32 gBattleAnimSpriteSheet_086[] = INCBIN_U32("graphics/battle_anims/sprites/086.4bpp.lz");
const u32 gBattleAnimSpriteSheet_088[] = INCBIN_U32("graphics/battle_anims/sprites/088.4bpp.lz");
const u32 gBattleAnimSpriteSheet_089[] = INCBIN_U32("graphics/battle_anims/sprites/089.4bpp.lz");
const u32 gBattleAnimSpriteSheet_090[] = INCBIN_U32("graphics/battle_anims/sprites/090.4bpp.lz");
const u32 gBattleAnimSpriteSheet_091[] = INCBIN_U32("graphics/battle_anims/sprites/091.4bpp.lz");
const u32 gBattleAnimSpriteSheet_092[] = INCBIN_U32("graphics/battle_anims/sprites/092.4bpp.lz");
const u32 gBattleAnimSpriteSheet_093[] = INCBIN_U32("graphics/battle_anims/sprites/093.4bpp.lz");
const u32 gBattleAnimSpriteSheet_094[] = INCBIN_U32("graphics/battle_anims/sprites/094.4bpp.lz");
const u32 gBattleAnimSpriteSheet_095[] = INCBIN_U32("graphics/battle_anims/sprites/095.4bpp.lz");
const u32 gBattleAnimSpriteSheet_096[] = INCBIN_U32("graphics/battle_anims/sprites/096.4bpp.lz");
const u32 gBattleAnimSpriteSheet_097[] = INCBIN_U32("graphics/battle_anims/sprites/097.4bpp.lz");
const u32 gBattleAnimSpriteSheet_098[] = INCBIN_U32("graphics/battle_anims/sprites/098.4bpp.lz");
const u32 gBattleAnimSpriteSheet_100[] = INCBIN_U32("graphics/battle_anims/sprites/100.4bpp.lz");
const u32 gBattleAnimSpriteSheet_101[] = INCBIN_U32("graphics/battle_anims/sprites/101.4bpp.lz");
const u32 gBattleAnimSpriteSheet_102[] = INCBIN_U32("graphics/battle_anims/sprites/102.4bpp.lz");
const u32 gBattleAnimSpriteSheet_103[] = INCBIN_U32("graphics/battle_anims/sprites/103.4bpp.lz");

const u32 gBattleAnimSpriteSheet_104[] = INCBIN_U32("graphics/battle_anims/sprites/104.4bpp.lz");
const u32 gBattleAnimSpritePalette_104[] = INCBIN_U32("graphics/battle_anims/sprites/104.gbapal.lz");

const u32 gBattleAnimSpriteSheet_105[] = INCBIN_U32("graphics/battle_anims/sprites/105.4bpp.lz");
const u32 gBattleAnimSpritePalette_105[] = INCBIN_U32("graphics/battle_anims/sprites/105.gbapal.lz");

const u32 gBattleAnimSpriteSheet_106[] = INCBIN_U32("graphics/battle_anims/sprites/106.4bpp.lz");

const u32 gBattleAnimSpriteSheet_107[] = INCBIN_U32("graphics/battle_anims/sprites/107.4bpp.lz");
const u32 gBattleAnimSpritePalette_107[] = INCBIN_U32("graphics/battle_anims/sprites/107.gbapal.lz");

const u32 gBattleAnimSpriteSheet_108[] = INCBIN_U32("graphics/battle_anims/sprites/108.4bpp.lz");

const u32 gBattleAnimSpriteSheet_109[] = INCBIN_U32("graphics/battle_anims/sprites/109.4bpp.lz");
const u32 gBattleAnimSpritePalette_109[] = INCBIN_U32("graphics/battle_anims/sprites/109.gbapal.lz");

const u32 gBattleAnimSpriteSheet_110[] = INCBIN_U32("graphics/battle_anims/sprites/110.4bpp.lz");

const u32 gBattleAnimSpriteSheet_111[] = INCBIN_U32("graphics/battle_anims/sprites/111.4bpp.lz");
const u32 gBattleAnimSpritePalette_111[] = INCBIN_U32("graphics/battle_anims/sprites/111.gbapal.lz");

const u32 gBattleAnimSpriteSheet_112[] = INCBIN_U32("graphics/battle_anims/sprites/112.4bpp.lz");
const u32 gBattleAnimSpritePalette_112[] = INCBIN_U32("graphics/battle_anims/sprites/112.gbapal.lz");

const u32 gBattleAnimSpriteSheet_113[] = INCBIN_U32("graphics/battle_anims/sprites/113.4bpp.lz");
const u32 gBattleAnimSpritePalette_113[] = INCBIN_U32("graphics/battle_anims/sprites/113.gbapal.lz");

const u32 gBattleAnimSpriteSheet_114[] = INCBIN_U32("graphics/battle_anims/sprites/114.4bpp.lz");
const u32 gBattleAnimSpritePalette_114[] = INCBIN_U32("graphics/battle_anims/sprites/114.gbapal.lz");

const u32 gUnusedTilemap_BlueFrame[] = INCBIN_U32("graphics/unused/blue_frame.bin.lz"); // P1, P2, P3 and P4 tilemaps?
const u32 gUnusedTilemap_RedYellowGreenFrame[] = INCBIN_U32("graphics/unused/redyellowgreen_frame.bin.lz");
const u32 gUnusedGfx_ColorFrames[] = INCBIN_U32("graphics/unused/color_frames.4bpp.lz");
const u32 gUnusedPal_ColorFrames[] = INCBIN_U32("graphics/unused/color_frames.gbapal.lz");

const u32 gBattleAnimSpriteSheet_115[] = INCBIN_U32("graphics/battle_anims/sprites/115.4bpp.lz");

const u32 gUnusedGfx8bpp_WaterSplash [] = INCBIN_U32("graphics/unused/water_splash.8bpp.lz");
const u32 gUnusedTilemap_WaterSplash[] = INCBIN_U32("graphics/unused/water_splash.bin.lz");
const u32 gUnusedPalette_WaterSplash[] = INCBIN_U32("graphics/unused/water_splash.gbapal.lz");

const u32 gUnusedGfx_BasicFrame[] = INCBIN_U32("graphics/unused/basic_frame.4bpp.lz");
const u32 gUnusedPal_BasicFrame[] = INCBIN_U32("graphics/unused/basic_frame.gbapal.lz");
const u32 gUnusedTilemap_BasicFrame[] = INCBIN_U32("graphics/unused/basic_frame.bin.lz");

// Battle Interface

const u16 gBattleInterface_BallStatusBarPal[] = INCBIN_U16("graphics/battle_interface/ball_status_bar.gbapal");

const u16 gBattleInterface_BallDisplayPal[] = INCBIN_U16("graphics/battle_interface/ball_display.gbapal");

//Originally an array?
const u8 gHealthboxElementsGfxTable[] = INCBIN_U8("graphics/battle_interface/hpbar.4bpp");
const u8 gHealthboxElementsGfxTable_ExpBar[] = INCBIN_U8("graphics/battle_interface/expbar.4bpp");
const u8 gHealthboxElementsGfxTable_StatusPsn[] = INCBIN_U8("graphics/battle_interface/status_psn.4bpp");
const u8 gHealthboxElementsGfxTable_StatusPar[] = INCBIN_U8("graphics/battle_interface/status_par.4bpp");
const u8 gHealthboxElementsGfxTable_StatusSlp[] = INCBIN_U8("graphics/battle_interface/status_slp.4bpp");
const u8 gHealthboxElementsGfxTable_StatusFrz[] = INCBIN_U8("graphics/battle_interface/status_frz.4bpp");
const u8 gHealthboxElementsGfxTable_StatusBrn[] = INCBIN_U8("graphics/battle_interface/status_brn.4bpp");
const u8 gHealthboxElementsGfxTable_Misc[] = INCBIN_U8("graphics/battle_interface/misc.4bpp");
const u8 gHealthboxElementsGfxTable_HpBarAnim[] = INCBIN_U8("graphics/battle_interface/hpbar_anim.4bpp");
const u8 gHealthboxElementsGfxTable_MiscFrameEnd[] = INCBIN_U8("graphics/battle_interface/misc_frameend.4bpp");

const u8 gBattleInterface_BallDisplayGfx[] = INCBIN_U8("graphics/battle_interface/ball_display.4bpp");

//Originally an array?
const u8 gUnknown_08C1249C[] = INCBIN_U8("graphics/battle_interface/ball_display_unused_extra.4bpp");
const u8 gBattleInterfaceGfx_Status2[] = INCBIN_U8("graphics/battle_interface/status2.4bpp"); // these three duplicate sets of graphics are for the opponent pokemon
const u8 gBattleInterfaceGfx_Status3[] = INCBIN_U8("graphics/battle_interface/status3.4bpp"); // and are also for use in double battles. they use dynamic palettes so
const u8 gBattleInterfaceGfx_Status4[] = INCBIN_U8("graphics/battle_interface/status4.4bpp"); // coloring them is an extreme headache and wont be done for now
const u8 gUnknown_D12FEC[] = INCBIN_U8("graphics/unknown/unknown_D12FEC.4bpp");
const u8 gUnknown_D1300C[] = INCBIN_U8("graphics/unknown/unknown_D1300C.4bpp");
const u32 gBattleInterfaceGfx_UnusedWindow3[] = INCBIN_U32("graphics/battle_interface/unused_window3.4bpp.lz");
const u32 gBattleInterfaceGfx_UnusedWindow4[] = INCBIN_U32("graphics/battle_interface/unused_window4.4bpp.lz");

const u32 gBattleAnimSpriteSheet_116[] = INCBIN_U32("graphics/battle_anims/sprites/116.4bpp.lz");
const u32 gBattleAnimSpritePalette_116[] = INCBIN_U32("graphics/battle_anims/sprites/116.gbapal.lz");

const u32 gBattleAnimSpriteSheet_117[] = INCBIN_U32("graphics/battle_anims/sprites/117.4bpp.lz");
const u32 gBattleAnimSpritePalette_117[] = INCBIN_U32("graphics/battle_anims/sprites/117.gbapal.lz");

const u32 gBattleAnimSpriteSheet_118[] = INCBIN_U32("graphics/battle_anims/sprites/118.4bpp.lz");
const u32 gBattleAnimSpritePalette_118[] = INCBIN_U32("graphics/battle_anims/sprites/118.gbapal.lz");

const u32 gBattleAnimSpriteSheet_119[] = INCBIN_U32("graphics/battle_anims/sprites/119.4bpp.lz");
const u32 gBattleAnimSpritePalette_119[] = INCBIN_U32("graphics/battle_anims/sprites/119.gbapal.lz");

const u32 gBattleAnimSpriteSheet_120[] = INCBIN_U32("graphics/battle_anims/sprites/120.4bpp.lz");
const u32 gBattleAnimSpritePalette_120[] = INCBIN_U32("graphics/battle_anims/sprites/120.gbapal.lz");

const u32 gBattleAnimSpriteSheet_121[] = INCBIN_U32("graphics/battle_anims/sprites/121.4bpp.lz");
const u32 gBattleAnimSpritePalette_121[] = INCBIN_U32("graphics/battle_anims/sprites/121.gbapal.lz");

const u32 gBattleAnimSpriteSheet_122[] = INCBIN_U32("graphics/battle_anims/sprites/122.4bpp.lz");
const u32 gBattleAnimSpritePalette_122[] = INCBIN_U32("graphics/battle_anims/sprites/122.gbapal.lz");

const u32 gBattleAnimSpriteSheet_123[] = INCBIN_U32("graphics/battle_anims/sprites/123.4bpp.lz");

const u32 gBattleAnimSpriteSheet_124[] = INCBIN_U32("graphics/battle_anims/sprites/124.4bpp.lz");
const u32 gBattleAnimSpritePalette_124[] = INCBIN_U32("graphics/battle_anims/sprites/124.gbapal.lz");

const u32 gBattleAnimSpriteSheet_125[] = INCBIN_U32("graphics/battle_anims/sprites/125.4bpp.lz");
const u32 gBattleAnimSpritePalette_125[] = INCBIN_U32("graphics/battle_anims/sprites/125.gbapal.lz");

const u32 gBattleAnimSpriteSheet_126[] = INCBIN_U32("graphics/battle_anims/sprites/126.4bpp.lz");
const u32 gBattleAnimSpritePalette_126[] = INCBIN_U32("graphics/battle_anims/sprites/126.gbapal.lz");

const u32 gBattleAnimSpriteSheet_127[] = INCBIN_U32("graphics/battle_anims/sprites/127.4bpp.lz");
const u32 gBattleAnimSpritePalette_127[] = INCBIN_U32("graphics/battle_anims/sprites/127.gbapal.lz");

const u32 gBattleAnimSpriteSheet_128[] = INCBIN_U32("graphics/battle_anims/sprites/128.4bpp.lz");
const u32 gBattleAnimSpritePalette_128[] = INCBIN_U32("graphics/battle_anims/sprites/128.gbapal.lz");

const u32 gBattleAnimSpriteSheet_129[] = INCBIN_U32("graphics/battle_anims/sprites/129.4bpp.lz");

const u32 gBattleAnimSpriteSheet_130[] = INCBIN_U32("graphics/battle_anims/sprites/130.4bpp.lz");
const u32 gBattleAnimSpritePalette_130[] = INCBIN_U32("graphics/battle_anims/sprites/130.gbapal.lz");

const u32 gBattleAnimSpriteSheet_131[] = INCBIN_U32("graphics/battle_anims/sprites/131.4bpp.lz");

const u32 gBattleAnimSpriteSheet_132[] = INCBIN_U32("graphics/battle_anims/sprites/132.4bpp.lz");
const u32 gBattleAnimSpritePalette_132[] = INCBIN_U32("graphics/battle_anims/sprites/132.gbapal.lz");

const u32 gBattleAnimSpriteSheet_133[] = INCBIN_U32("graphics/battle_anims/sprites/133.4bpp.lz");
const u32 gBattleAnimSpritePalette_133[] = INCBIN_U32("graphics/battle_anims/sprites/133.gbapal.lz");

const u32 gBattleAnimSpriteSheet_134[] = INCBIN_U32("graphics/battle_anims/sprites/134.4bpp.lz");

const u32 gBattleAnimSpriteSheet_076[] = INCBIN_U32("graphics/battle_anims/sprites/076.4bpp.lz");
const u32 gBattleAnimSpritePalette_076[] = INCBIN_U32("graphics/battle_anims/sprites/076.gbapal.lz");

const u32 gBattleAnimSpriteSheet_077[] = INCBIN_U32("graphics/battle_anims/sprites/077.4bpp.lz");

// Contest

const u32 gUnusedGfx_OldContest[] = INCBIN_U32("graphics/unused/old_contest.4bpp.lz");
const u32 gUnusedPal_OldContest[] = INCBIN_U32("graphics/unused/old_contest.gbapal.lz");
const u32 gUnusedTilemap_OldContest[] = INCBIN_U32("graphics/unused/old_contest.bin.lz");

const u32 gUnknownTilemap_C15BC0[] = INCBIN_U32("graphics/unknown/unknown_C15BC0.bin.lz");

const u32 gUnusedGfx_OldContest2[] = INCBIN_U32("graphics/unused/old_contest_2.4bpp.lz");
const u32 gUnknown_08C16E90[] = INCBIN_U32("graphics/unused/old_contest_2.gbapal.lz");
const u32 gUnknown_08C16FA8[] = INCBIN_U32("graphics/unused/old_contest_2.bin.lz");

const u32 gUnknown_08C17170[] = INCBIN_U32("graphics/unknown/unknown_C17170.bin.lz");

const u32 gUnknown_08C17410[] = INCBIN_U32("graphics/unknown/unknown_C17410.bin.lz");

const u32 gUnknown_08C1751C[] = INCBIN_U32("graphics/unknown/unknown_C1751C.bin.lz");

const u32 gUnknown_08C17980[] = INCBIN_U32("graphics/unknown/unknown_C17980.bin.lz");

const u32 gContestMiscGfx[] = INCBIN_U32("graphics/contest/misc.4bpp.lz");

const u32 gContestAudienceGfx[] = INCBIN_U32("graphics/contest/audience.4bpp.lz");

const u32 gUnknown_08C19168[] = INCBIN_U32("graphics/contest/faces.4bpp.lz");

const u32 gContestJudgeSymbolsGfx[] = INCBIN_U32("graphics/contest/judge_symbols.4bpp.lz");
const u32 gContest3Pal[] = INCBIN_U32("graphics/contest/judge_symbols.gbapal.lz");

const u8 gTiles_8C19450[] = INCBIN_U8("graphics/contest/heart.4bpp");

const u32 gUnknownGfx_C19470[] = INCBIN_U32("graphics/unknown/unknown_C19470.4bpp.lz");
const u32 gUnknownPal_C19470[] = INCBIN_U32("graphics/unknown/unknown_C19470.gbapal.lz");

const u32 gUnknown_08C19588[] = INCBIN_U32("graphics/contest/misc_2.4bpp.lz");

const u32 gUnknown_08C19EEC[] = INCBIN_U32("graphics/contest/misc_2_tilemap_1.bin.lz");
const u32 gUnknown_08C1A000[] = INCBIN_U32("graphics/contest/misc_2_tilemap_2.bin.lz");
const u32 gUnknown_08C1A12C[] = INCBIN_U32("graphics/contest/misc_2_tilemap_3.bin.lz");

const u32 gUnknown_08C1A2B4[] = INCBIN_U32("graphics/contest/misc_2.gbapal.lz");

const u32 gBattleAnimSpriteSheet_135[] = INCBIN_U32("graphics/battle_anims/sprites/135.4bpp.lz");
const u32 gBattleAnimSpritePalette_135[] = INCBIN_U32("graphics/battle_anims/sprites/135.gbapal.lz");

const u32 gBattleAnimSpriteSheet_Particles[] = INCBIN_U32("graphics/battle_anims/sprites/particles.4bpp.lz");

const u32 gBattleAnimSpriteSheet_136[] = INCBIN_U32("graphics/battle_anims/sprites/136.4bpp.lz");
const u32 gBattleAnimSpritePalette_136[] = INCBIN_U32("graphics/battle_anims/sprites/136.gbapal.lz");

const u32 gBattleAnimSpriteSheet_137[] = INCBIN_U32("graphics/battle_anims/sprites/137.4bpp.lz");

const u32 gBattleAnimSpriteSheet_139[] = INCBIN_U32("graphics/battle_anims/sprites/139.4bpp.lz");
const u32 gBattleAnimSpritePalette_139[] = INCBIN_U32("graphics/battle_anims/sprites/139.gbapal.lz");

const u32 gBattleAnimSpriteSheet_145[] = INCBIN_U32("graphics/battle_anims/sprites/145.4bpp.lz");

const u32 gBattleAnimSpriteSheet_138[] = INCBIN_U32("graphics/battle_anims/sprites/138.4bpp.lz");

const u32 gBattleAnimSpriteSheet_140[] = INCBIN_U32("graphics/battle_anims/sprites/140.4bpp.lz");
const u32 gBattleAnimSpritePalette_140[] = INCBIN_U32("graphics/battle_anims/sprites/140.gbapal.lz");

const u32 gBattleAnimSpriteSheet_141[] = INCBIN_U32("graphics/battle_anims/sprites/141.4bpp.lz");
const u32 gBattleAnimSpritePalette_141[] = INCBIN_U32("graphics/battle_anims/sprites/141.gbapal.lz");

const u32 gBattleAnimSpriteSheet_142[] = INCBIN_U32("graphics/battle_anims/sprites/142.4bpp.lz");

const u32 gUnusedGfx_OldBeatUp[] = INCBIN_U32("graphics/unused/old_beatup.4bpp.lz");
const u32 gUnusedPal_OldBeatUp[] = INCBIN_U32("graphics/unused/old_beatup.gbapal.lz");

const u32 gBattleAnimSpriteSheet_147[] = INCBIN_U32("graphics/battle_anims/sprites/147.4bpp.lz");
const u32 gBattleAnimSpritePalette_147[] = INCBIN_U32("graphics/battle_anims/sprites/147.gbapal.lz");

const u32 gBattleAnimSpriteSheet_149[] = INCBIN_U32("graphics/battle_anims/sprites/149.4bpp.lz");

const u32 gBattleAnimSpriteSheet_148[] = INCBIN_U32("graphics/battle_anims/sprites/148.4bpp.lz");
const u32 gBattleAnimSpritePalette_148[] = INCBIN_U32("graphics/battle_anims/sprites/148.gbapal.lz");

const u32 gBattleAnimSpritePalette_259[] = INCBIN_U32("graphics/battle_anims/sprites/259.gbapal.lz");

const u32 gBattleAnimSpriteSheet_074[] = INCBIN_U32("graphics/battle_anims/sprites/074.4bpp.lz");
const u32 gBattleAnimSpritePalette_074[] = INCBIN_U32("graphics/battle_anims/sprites/074.gbapal.lz");

const u32 gBattleAnimSpriteSheet_150[] = INCBIN_U32("graphics/battle_anims/sprites/150.4bpp.lz");
const u32 gBattleAnimSpritePalette_150[] = INCBIN_U32("graphics/battle_anims/sprites/150.gbapal.lz");

const u32 gBattleAnimSpriteSheet_151[] = INCBIN_U32("graphics/battle_anims/sprites/151.4bpp.lz");

const u32 gBattleAnimSpriteSheet_153[] = INCBIN_U32("graphics/battle_anims/sprites/153.4bpp.lz");
const u32 gBattleAnimSpritePalette_153[] = INCBIN_U32("graphics/battle_anims/sprites/153.gbapal.lz");

const u32 gBattleAnimSpriteSheet_154[] = INCBIN_U32("graphics/battle_anims/sprites/154.4bpp.lz");
const u32 gBattleAnimSpritePalette_154[] = INCBIN_U32("graphics/battle_anims/sprites/154.gbapal.lz");

const u32 gBattleAnimSpriteSheet_155[] = INCBIN_U32("graphics/battle_anims/sprites/155.4bpp.lz");
const u32 gBattleAnimSpritePalette_155[] = INCBIN_U32("graphics/battle_anims/sprites/155.gbapal.lz");

const u32 gBattleAnimSpriteSheet_156[] = INCBIN_U32("graphics/battle_anims/sprites/156.4bpp.lz");
const u32 gBattleAnimSpritePalette_156[] = INCBIN_U32("graphics/battle_anims/sprites/156.gbapal.lz");

const u32 gBattleAnimSpriteSheet_157[] = INCBIN_U32("graphics/battle_anims/sprites/157.4bpp.lz");
const u32 gBattleAnimSpritePalette_157[] = INCBIN_U32("graphics/battle_anims/sprites/157.gbapal.lz");

const u32 gBattleAnimSpriteSheet_158[] = INCBIN_U32("graphics/battle_anims/sprites/158.4bpp.lz");

const u32 gBattleAnimSpritePalette_158[] = INCBIN_U32("graphics/battle_anims/sprites/158.gbapal.lz");

const u32 gBattleAnimSpriteSheet_159[] = INCBIN_U32("graphics/battle_anims/sprites/159.4bpp.lz");
const u32 gBattleAnimSpritePalette_159[] = INCBIN_U32("graphics/battle_anims/sprites/159.gbapal.lz");

const u32 gBattleAnimSpriteSheet_160[] = INCBIN_U32("graphics/battle_anims/sprites/160.4bpp.lz");
const u32 gBattleAnimSpritePalette_160[] = INCBIN_U32("graphics/battle_anims/sprites/160.gbapal.lz");

const u32 gBattleAnimSpriteSheet_144[] = INCBIN_U32("graphics/battle_anims/sprites/144.4bpp.lz");
const u32 gBattleAnimSpritePalette_144[] = INCBIN_U32("graphics/battle_anims/sprites/144.gbapal.lz");

const u32 gUnknownGfx_D1C060[] = INCBIN_U32("graphics/unknown/unknown_D1C060.4bpp.lz");
const u32 gUnknownPal_D1C060[] = INCBIN_U32("graphics/unknown/unknown_D1C060.gbapal.lz");
const u32 gUnknownTilemap_D1C060[] = INCBIN_U32("graphics/unknown/unknown_D1C060.bin.lz");

const u32 gBattleAnimSpriteSheet_162[] = INCBIN_U32("graphics/battle_anims/sprites/162.4bpp.lz");
const u32 gBattleAnimSpritePalette_162[] = INCBIN_U32("graphics/battle_anims/sprites/162.gbapal.lz");

const u32 gBattleAnimSpriteSheet_163[] = INCBIN_U32("graphics/battle_anims/sprites/163.4bpp.lz");
const u32 gBattleAnimSpritePalette_163[] = INCBIN_U32("graphics/battle_anims/sprites/163.gbapal.lz");

const u32 gBattleAnimSpritePalette_288[] = INCBIN_U32("graphics/battle_anims/sprites/288.gbapal.lz");
const u32 gBattleAnimSpritePalette_164[] = INCBIN_U32("graphics/battle_anims/sprites/164.gbapal.lz");
const u32 gBattleAnimSpritePalette_165[] = INCBIN_U32("graphics/battle_anims/sprites/165.gbapal.lz");

const u32 gBattleAnimSpriteSheet_166[] = INCBIN_U32("graphics/battle_anims/sprites/166.4bpp.lz");
const u32 gBattleAnimSpritePalette_166[] = INCBIN_U32("graphics/battle_anims/sprites/166.gbapal.lz");

const u32 gBattleAnimSpritePalette_167[] = INCBIN_U32("graphics/battle_anims/sprites/167.gbapal.lz");
const u32 gBattleAnimSpritePalette_168[] = INCBIN_U32("graphics/battle_anims/sprites/168.gbapal.lz");
const u32 gBattleAnimSpritePalette_169[] = INCBIN_U32("graphics/battle_anims/sprites/169.gbapal.lz");
const u32 gBattleAnimSpritePalette_170[] = INCBIN_U32("graphics/battle_anims/sprites/170.gbapal.lz");

const u32 gBattleAnimSpriteSheet_171[] = INCBIN_U32("graphics/battle_anims/sprites/171.4bpp.lz");
const u32 gBattleAnimSpritePalette_171[] = INCBIN_U32("graphics/battle_anims/sprites/171.gbapal.lz");

const u32 gBattleAnimSpritePalette_172[] = INCBIN_U32("graphics/battle_anims/sprites/172.gbapal.lz");

const u32 gContestJudgeGfx[] = INCBIN_U32("graphics/contest/judge.4bpp.lz");
const u32 gContest2Pal[] = INCBIN_U32("graphics/contest/judge.gbapal.lz");

const u32 gBattleAnimSpriteSheet_001[] = INCBIN_U32("graphics/battle_anims/sprites/001.4bpp.lz");
const u32 gBattleAnimSpritePalette_001[] = INCBIN_U32("graphics/battle_anims/sprites/001.gbapal.lz");

const u32 gBattleAnimSpriteSheet_173[] = INCBIN_U32("graphics/battle_anims/sprites/173.4bpp.lz");

const u32 gBattleAnimBackgroundImage_00[] = INCBIN_U32("graphics/battle_anims/backgrounds/00.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_00[] = INCBIN_U32("graphics/battle_anims/backgrounds/00.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_00[] = INCBIN_U32("graphics/battle_anims/backgrounds/00.bin.lz");

const u32 gUnknown_08C1D0AC[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.4bpp.lz");
const u32 gUnknown_08C1D1E8[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.gbapal.lz");
const u32 gUnknown_08C1D210[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.bin.lz");

const u32 gUnusedGfx_Goosuto[] = INCBIN_U32("graphics/unused/goosuto.4bpp.lz"); // ghost
const u32 gUnusedPal_Goosuto[] = INCBIN_U32("graphics/unused/goosuto.gbapal.lz");
const u32 gUnusedTilemap_Goosuto[] = INCBIN_U32("graphics/unused/goosuto.bin.lz");

const u32 gBattleAnimSpriteSheet_174[] = INCBIN_U32("graphics/battle_anims/sprites/174.4bpp.lz");
const u32 gBattleAnimSpritePalette_174[] = INCBIN_U32("graphics/battle_anims/sprites/174.gbapal.lz");

const u32 gBattleAnimSpriteSheet_175[] = INCBIN_U32("graphics/battle_anims/sprites/175.4bpp.lz");
const u32 gBattleAnimSpritePalette_175[] = INCBIN_U32("graphics/battle_anims/sprites/175.gbapal.lz");

const u32 gBattleAnimSpriteSheet_176[] = INCBIN_U32("graphics/battle_anims/sprites/176.4bpp.lz");
const u32 gBattleAnimSpritePalette_176[] = INCBIN_U32("graphics/battle_anims/sprites/176.gbapal.lz");

const u32 gBattleAnimSpriteSheet_177[] = INCBIN_U32("graphics/battle_anims/sprites/177.4bpp.lz");
const u32 gBattleAnimSpritePalette_177[] = INCBIN_U32("graphics/battle_anims/sprites/177.gbapal.lz");

const u32 gBattleAnimSpriteSheet_178[] = INCBIN_U32("graphics/battle_anims/sprites/178.4bpp.lz");
const u32 gBattleAnimSpritePalette_178[] = INCBIN_U32("graphics/battle_anims/sprites/178.gbapal.lz");

const u32 gBattleAnimSpritePalette_179[] = INCBIN_U32("graphics/battle_anims/sprites/179.gbapal.lz");
const u32 gBattleAnimSpriteSheet_179[] = INCBIN_U32("graphics/battle_anims/sprites/179.4bpp.lz");

const u32 gBattleAnimSpriteSheet_180[] = INCBIN_U32("graphics/battle_anims/sprites/180.4bpp.lz");
const u32 gBattleAnimSpriteSheet_181[] = INCBIN_U32("graphics/battle_anims/sprites/181.4bpp.lz");

const u32 gBattleAnimSpriteSheet_182[] = INCBIN_U32("graphics/battle_anims/sprites/182.4bpp.lz");
const u32 gBattleAnimSpritePalette_182[] = INCBIN_U32("graphics/battle_anims/sprites/182.gbapal.lz");

const u32 gBattleAnimSpriteSheet_183[] = INCBIN_U32("graphics/battle_anims/sprites/183.4bpp.lz");
const u32 gBattleAnimSpritePalette_183[] = INCBIN_U32("graphics/battle_anims/sprites/183.gbapal.lz");

const u32 gBattleAnimSpriteSheet_184[] = INCBIN_U32("graphics/battle_anims/sprites/184.4bpp.lz");
const u32 gBattleAnimSpritePalette_184[] = INCBIN_U32("graphics/battle_anims/sprites/184.gbapal.lz");

const u32 gBattleAnimSpriteSheet_185[] = INCBIN_U32("graphics/battle_anims/sprites/185.4bpp.lz");
const u32 gBattleAnimSpritePalette_185[] = INCBIN_U32("graphics/battle_anims/sprites/185.gbapal.lz");

const u32 gBattleAnimBackgroundImage_03[] = INCBIN_U32("graphics/battle_anims/backgrounds/03.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_03[] = INCBIN_U32("graphics/battle_anims/backgrounds/03.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_03[] = INCBIN_U32("graphics/battle_anims/backgrounds/03.bin.lz");

const u32 gBattleAnimSpriteSheet_187[] = INCBIN_U32("graphics/battle_anims/sprites/187.4bpp.lz");
const u32 gBattleAnimSpritePalette_187[] = INCBIN_U32("graphics/battle_anims/sprites/187.gbapal.lz");

const u32 gBattleAnimSpriteSheet_186[] = INCBIN_U32("graphics/battle_anims/sprites/186.4bpp.lz");
const u32 gBattleAnimSpritePalette_186[] = INCBIN_U32("graphics/battle_anims/sprites/186.gbapal.lz");

const u32 gHealthboxSinglesPlayerGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_player.4bpp.lz");
const u32 gHealthboxSinglesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_opponent.4bpp.lz");
const u32 gHealthboxDoublesPlayerGfx[] = INCBIN_U32( "graphics/battle_interface/healthbox_doubles_player.4bpp.lz");
const u32 gHealthboxDoublesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_doubles_opponent.4bpp.lz");
const u32 gHealthboxSafariGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_safari.4bpp.lz");

const u32 gUnusedGfx_Shadow[] = INCBIN_U32("graphics/unused/shadow.4bpp.lz");
const u32 gUnusedPal_Shadow[] = INCBIN_U32("graphics/unused/shadow.gbapal.lz");

const u32 gBattleAnimSpriteSheet_014[] = INCBIN_U32("graphics/battle_anims/sprites/014.4bpp.lz");
const u32 gBattleAnimSpritePalette_014[] = INCBIN_U32("graphics/battle_anims/sprites/014.gbapal.lz");

const u32 gBattleAnimSpriteSheet_190[] = INCBIN_U32("graphics/battle_anims/sprites/190.4bpp.lz");
const u32 gBattleAnimSpritePalette_190[] = INCBIN_U32("graphics/battle_anims/sprites/190.gbapal.lz");

const u32 gBattleAnimSpriteSheet_191[] = INCBIN_U32("graphics/battle_anims/sprites/191.4bpp.lz");
const u32 gBattleAnimSpritePalette_191[] = INCBIN_U32("graphics/battle_anims/sprites/191.gbapal.lz");

const u32 gBattleAnimSpriteSheet_189[] = INCBIN_U32("graphics/battle_anims/sprites/189.4bpp.lz");
const u32 gBattleAnimSpritePalette_189[] = INCBIN_U32("graphics/battle_anims/sprites/189.gbapal.lz");

const u32 gBattleAnimSpriteSheet_192[] = INCBIN_U32("graphics/battle_anims/sprites/192.4bpp.lz");
const u32 gBattleAnimSpritePalette_192[] = INCBIN_U32("graphics/battle_anims/sprites/192.gbapal.lz");

const u32 gBattleAnimSpriteSheet_193[] = INCBIN_U32("graphics/battle_anims/sprites/193.4bpp.lz");
const u32 gBattleAnimSpritePalette_193[] = INCBIN_U32("graphics/battle_anims/sprites/193.gbapal.lz");

const u32 gUnknown_08C20668[] = INCBIN_U32("graphics/battle_anims/masks/curse.4bpp.lz");
const u32 gUnknown_08C20684[] = INCBIN_U32("graphics/battle_anims/masks/curse.bin.lz");

const u32 gBattleAnimSpriteSheet_002[] = INCBIN_U32("graphics/battle_anims/sprites/002.4bpp.lz");
const u32 gBattleAnimSpritePalette_002[] = INCBIN_U32("graphics/battle_anims/sprites/002.gbapal.lz");

const u32 gBattleAnimSpriteSheet_196[] = INCBIN_U32("graphics/battle_anims/sprites/196.4bpp.lz");
const u32 gBattleAnimSpritePalette_196[] = INCBIN_U32("graphics/battle_anims/sprites/196.gbapal.lz");

const u32 gBattleAnimSpriteSheet_194[] = INCBIN_U32("graphics/battle_anims/sprites/194.4bpp.lz");
const u32 gBattleAnimSpritePalette_194[] = INCBIN_U32("graphics/battle_anims/sprites/194.gbapal.lz");

const u32 gBattleAnimSpriteSheet_195[] = INCBIN_U32("graphics/battle_anims/sprites/195.4bpp.lz");
const u32 gBattleAnimSpritePalette_195[] = INCBIN_U32("graphics/battle_anims/sprites/195.gbapal.lz");

const u32 gBattleAnimSpriteSheet_197[] = INCBIN_U32("graphics/battle_anims/sprites/197.4bpp.lz");
const u32 gBattleAnimSpritePalette_197[] = INCBIN_U32("graphics/battle_anims/sprites/197.gbapal.lz");

const u32 gBattleAnimSpriteSheet_198[] = INCBIN_U32("graphics/battle_anims/sprites/198.4bpp.lz");
const u32 gBattleAnimSpritePalette_198[] = INCBIN_U32("graphics/battle_anims/sprites/198.gbapal.lz");

const u32 gBattleAnimSpriteSheet_199[] = INCBIN_U32("graphics/battle_anims/sprites/199.4bpp.lz");
const u32 gBattleAnimSpritePalette_199[] = INCBIN_U32("graphics/battle_anims/sprites/199.gbapal.lz");

const u32 gBattleAnimSpriteSheet_200[] = INCBIN_U32("graphics/battle_anims/sprites/200.4bpp.lz");
const u32 gBattleAnimSpritePalette_200[] = INCBIN_U32("graphics/battle_anims/sprites/200.gbapal.lz");

const u32 gBattleAnimSpriteSheet_201[] = INCBIN_U32("graphics/battle_anims/sprites/201.4bpp.lz");
const u32 gBattleAnimSpritePalette_201[] = INCBIN_U32("graphics/battle_anims/sprites/201.gbapal.lz");

const u32 gBattleAnimSpriteSheet_204[] = INCBIN_U32("graphics/battle_anims/sprites/204.4bpp.lz");
const u32 gBattleAnimSpritePalette_204[] = INCBIN_U32("graphics/battle_anims/sprites/204.gbapal.lz");

const u32 gBattleAnimSpriteSheet_202[] = INCBIN_U32("graphics/battle_anims/sprites/202.4bpp.lz");
const u32 gBattleAnimSpritePalette_202[] = INCBIN_U32("graphics/battle_anims/sprites/202.gbapal.lz");

const u32 gBattleAnimSpriteSheet_203[] = INCBIN_U32("graphics/battle_anims/sprites/203.4bpp.lz");
const u32 gBattleAnimSpritePalette_203[] = INCBIN_U32("graphics/battle_anims/sprites/203.gbapal.lz");

const u32 gBattleAnimSpriteSheet_206[] = INCBIN_U32("graphics/battle_anims/sprites/206.4bpp.lz");
const u32 gBattleAnimSpritePalette_206[] = INCBIN_U32("graphics/battle_anims/sprites/206.gbapal.lz");

const u32 gBattleAnimSpriteSheet_205[] = INCBIN_U32("graphics/battle_anims/sprites/205.4bpp.lz");
const u32 gBattleAnimSpritePalette_205[] = INCBIN_U32("graphics/battle_anims/sprites/205.gbapal.lz");

const u32 gBattleAnimSpriteSheet_207[] = INCBIN_U32("graphics/battle_anims/sprites/207.4bpp.lz");
const u32 gBattleAnimSpritePalette_207[] = INCBIN_U32("graphics/battle_anims/sprites/207.gbapal.lz");

const u32 gBattleAnimSpriteSheet_208[] = INCBIN_U32("graphics/battle_anims/sprites/208.4bpp.lz");

const u32 gBattleAnimSpriteSheet_209[] = INCBIN_U32("graphics/battle_anims/sprites/209.4bpp.lz");
const u32 gBattleAnimSpritePalette_209[] = INCBIN_U32("graphics/battle_anims/sprites/209.gbapal.lz");

const u32 gBattleAnimSpriteSheet_064[] = INCBIN_U32("graphics/battle_anims/sprites/064.4bpp.lz");
const u32 gBattleAnimSpritePalette_064[] = INCBIN_U32("graphics/battle_anims/sprites/064.gbapal.lz");

const u32 gBattleAnimSpriteSheet_210[] = INCBIN_U32("graphics/battle_anims/sprites/210.4bpp.lz");

const u32 gBattleAnimSpritePalette_219[] = INCBIN_U32("graphics/battle_anims/sprites/219.gbapal.lz");
const u32 gBattleAnimSpritePalette_210[] = INCBIN_U32("graphics/battle_anims/sprites/210.gbapal.lz");
const u32 gBattleAnimSpritePalette_216[] = INCBIN_U32("graphics/battle_anims/sprites/216.gbapal.lz");

const u32 gUnknown_08C232E0[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.4bpp.lz");
const u32 gUnknown_08C23D50[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.gbapal.lz");
const u32 gUnknown_08C23D78[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.bin.lz");

const u32 gBattleAnimSpriteSheet_217[] = INCBIN_U32("graphics/battle_anims/sprites/217.4bpp.lz");
const u32 gBattleAnimSpritePalette_217[] = INCBIN_U32("graphics/battle_anims/sprites/217.gbapal.lz");

const u32 gBattleAnimSpriteSheet_212[] = INCBIN_U32("graphics/battle_anims/sprites/212.4bpp.lz");
const u32 gBattleAnimSpriteSheet_211[] = INCBIN_U32("graphics/battle_anims/sprites/211.4bpp.lz");
const u32 gBattleAnimSpriteSheet_213[] = INCBIN_U32("graphics/battle_anims/sprites/213.4bpp.lz");

const u32 gBattleAnimSpritePalette_211[] = INCBIN_U32("graphics/battle_anims/sprites/211.gbapal.lz");

const u32 gBattleAnimSpriteSheet_214[] = INCBIN_U32("graphics/battle_anims/sprites/214.4bpp.lz");

const u32 gBattleAnimSpriteSheet_215[] = INCBIN_U32("graphics/battle_anims/sprites/215.4bpp.lz");
const u32 gBattleAnimSpritePalette_215[] = INCBIN_U32("graphics/battle_anims/sprites/215.gbapal.lz");

const u32 gUnknown_08C249D0[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.gbapal.lz");
const u32 gUnknown_08C249F8[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.4bpp.lz");

const u32 gBattleAnimSpritePalette_218[] = INCBIN_U32("graphics/battle_anims/sprites/218.gbapal.lz");
const u32 gBattleAnimSpriteSheet_218[] = INCBIN_U32("graphics/battle_anims/sprites/218.4bpp.lz");

const u32 gBattleAnimSpriteSheet_087[] = INCBIN_U32("graphics/battle_anims/sprites/087.4bpp.lz");
const u32 gBattleAnimSpritePalette_087[] = INCBIN_U32("graphics/battle_anims/sprites/087.gbapal.lz");

const u32 gBattleAnimSpriteSheet_018[] = INCBIN_U32("graphics/battle_anims/sprites/018.4bpp.lz");
const u32 gBattleAnimSpritePalette_018[] = INCBIN_U32("graphics/battle_anims/sprites/018.gbapal.lz");

const u32 gBattleAnimSpritePalette_220[] = INCBIN_U32("graphics/battle_anims/sprites/220.gbapal.lz");
const u32 gBattleAnimSpriteSheet_220[] = INCBIN_U32("graphics/battle_anims/sprites/220.4bpp.lz");

const u32 gBattleAnimSpritePalette_221[] = INCBIN_U32("graphics/battle_anims/sprites/221.gbapal.lz");
const u32 gBattleAnimSpriteSheet_221[] = INCBIN_U32("graphics/battle_anims/sprites/221.4bpp.lz");

const u32 gBattleAnimSpriteSheet_222[] = INCBIN_U32("graphics/battle_anims/sprites/222.4bpp.lz");
const u32 gBattleAnimSpritePalette_222[] = INCBIN_U32("graphics/battle_anims/sprites/222.gbapal.lz");

const u32 gBattleAnimSpritePalette_223[] = INCBIN_U32("graphics/battle_anims/sprites/223.gbapal.lz");
const u32 gBattleAnimSpriteSheet_223[] = INCBIN_U32("graphics/battle_anims/sprites/223.4bpp.lz");

const u32 gBattleAnimSpritePalette_224[] = INCBIN_U32("graphics/battle_anims/sprites/224.gbapal.lz");
const u32 gBattleAnimSpriteSheet_224[] = INCBIN_U32("graphics/battle_anims/sprites/224.4bpp.lz");

const u32 gBattleAnimSpritePalette_230[] = INCBIN_U32("graphics/battle_anims/sprites/230.gbapal.lz");
const u32 gBattleAnimSpriteSheet_230[] = INCBIN_U32("graphics/battle_anims/sprites/230.4bpp.lz");

const u32 gBattleAnimSpritePalette_228[] = INCBIN_U32("graphics/battle_anims/sprites/228.gbapal.lz");
const u32 gBattleAnimSpriteSheet_228[] = INCBIN_U32("graphics/battle_anims/sprites/228.4bpp.lz");

const u32 gBattleAnimBackgroundPalette_04[] = INCBIN_U32("graphics/battle_anims/backgrounds/04.gbapal.lz");
const u32 gBattleAnimBackgroundImage_04[] = INCBIN_U32("graphics/battle_anims/backgrounds/04.4bpp.lz");
const u32 gBattleAnimBackgroundTilemap_04[] = INCBIN_U32("graphics/battle_anims/backgrounds/04.bin.lz");

const u32 gBattleAnimBackgroundTilemap_05[] = INCBIN_U32("graphics/battle_anims/backgrounds/05.bin.lz");
const u32 gBattleAnimBackgroundTilemap_06[] = INCBIN_U32("graphics/battle_anims/backgrounds/06.bin.lz");

const u32 gBattleAnimSpriteSheet_225[] = INCBIN_U32("graphics/battle_anims/sprites/225.4bpp.lz");
const u32 gBattleAnimSpritePalette_225[] = INCBIN_U32("graphics/battle_anims/sprites/225.gbapal.lz");

const u32 gBattleAnimSpriteSheet_227[] = INCBIN_U32("graphics/battle_anims/sprites/227.4bpp.lz");

const u32 gBattleAnimSpriteSheet_226[] = INCBIN_U32("graphics/battle_anims/sprites/226.4bpp.lz");
const u32 gBattleAnimSpritePalette_226[] = INCBIN_U32("graphics/battle_anims/sprites/226.gbapal.lz");

const u32 gBattleAnimSpriteSheet_229[] = INCBIN_U32("graphics/battle_anims/sprites/229.4bpp.lz");
const u32 gBattleAnimSpritePalette_229[] = INCBIN_U32("graphics/battle_anims/sprites/229.gbapal.lz");

const u32 gBattleAnimSpriteSheet_099[] = INCBIN_U32("graphics/battle_anims/sprites/099.4bpp.lz");
const u32 gBattleAnimSpritePalette_099[] = INCBIN_U32("graphics/battle_anims/sprites/099.gbapal.lz");

const u32 gBattleAnimSpriteSheet_232[] = INCBIN_U32("graphics/battle_anims/sprites/232.4bpp.lz");

const u32 gBattleAnimSpritePalette_231[] = INCBIN_U32("graphics/battle_anims/sprites/231.gbapal.lz");
const u32 gBattleAnimSpriteSheet_231[] = INCBIN_U32("graphics/battle_anims/sprites/231.4bpp.lz");

const u32 gBattleAnimSpriteSheet_233[] = INCBIN_U32("graphics/battle_anims/sprites/233.4bpp.lz");
const u32 gBattleAnimSpritePalette_233[] = INCBIN_U32("graphics/battle_anims/sprites/233.gbapal.lz");

const u32 gBattleAnimSpriteSheet_234[] = INCBIN_U32("graphics/battle_anims/sprites/234.4bpp.lz");
const u32 gBattleAnimSpritePalette_234[] = INCBIN_U32("graphics/battle_anims/sprites/234.gbapal.lz");

const u32 gBattleAnimSpriteSheet_238[] = INCBIN_U32("graphics/battle_anims/sprites/238.4bpp.lz");
const u32 gBattleAnimSpritePalette_238[] = INCBIN_U32("graphics/battle_anims/sprites/238.gbapal.lz");

const u32 gBattleAnimSpriteSheet_235[] = INCBIN_U32("graphics/battle_anims/sprites/235.4bpp.lz");
const u32 gBattleAnimSpritePalette_235[] = INCBIN_U32("graphics/battle_anims/sprites/235.gbapal.lz");

const u32 gBattleAnimSpritePalette_236[] = INCBIN_U32("graphics/battle_anims/sprites/236.gbapal.lz");
const u32 gBattleAnimSpritePalette_237[] = INCBIN_U32("graphics/battle_anims/sprites/237.gbapal.lz");

const u32 gBattleAnimBackgroundImage_07[] = INCBIN_U32("graphics/battle_anims/backgrounds/07.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_07[] = INCBIN_U32("graphics/battle_anims/backgrounds/07.gbapal.lz");

const u32 gBattleAnimBackgroundPalette_18[] = INCBIN_U32("graphics/battle_anims/backgrounds/18.gbapal.lz");

const u32 gBattleAnimBackgroundTilemap_07[] = INCBIN_U32("graphics/battle_anims/backgrounds/07.bin.lz");
const u32 gBattleAnimBackgroundTilemap_08[] = INCBIN_U32("graphics/battle_anims/backgrounds/08.bin.lz");

const u32 gBattleAnimBackgroundImage_20[] = INCBIN_U32("graphics/battle_anims/backgrounds/20.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_20[] = INCBIN_U32("graphics/battle_anims/backgrounds/20.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_20[] = INCBIN_U32("graphics/battle_anims/backgrounds/20.bin.lz");

const u32 gBattleAnimBackgroundTilemap_09[] = INCBIN_U32("graphics/battle_anims/backgrounds/09.bin.lz");
const u32 gBattleAnimBackgroundPalette_09[] = INCBIN_U32("graphics/battle_anims/backgrounds/09.gbapal.lz");

const u32 gBattleAnimBackgroundPalette_22[] = INCBIN_U32("graphics/battle_anims/backgrounds/22.gbapal.lz");

const u32 gBattleAnimBackgroundImage_09[] = INCBIN_U32("graphics/battle_anims/backgrounds/09.4bpp.lz");
const u32 gBattleAnimBackgroundTilemap_10[] = INCBIN_U32("graphics/battle_anims/backgrounds/10.bin.lz");

const u32 gUnknown_08C2A634[] = INCBIN_U32("graphics/battle_anims/masks/morning_sun.4bpp.lz");
const u32 gUnknown_08C2A6D4[] = INCBIN_U32("graphics/battle_anims/masks/morning_sun.gbapal.lz");
const u32 gUnknown_08C2A6EC[] = INCBIN_U32("graphics/battle_anims/masks/morning_sun.bin.lz");

const u32 gBattleAnimBackgroundTilemap_12[] = INCBIN_U32("graphics/battle_anims/backgrounds/12.bin.lz");
const u32 gBattleAnimBackgroundTilemap_13[] = INCBIN_U32("graphics/battle_anims/backgrounds/13.bin.lz");
const u32 gBattleAnimBackgroundTilemap_14[] = INCBIN_U32("graphics/battle_anims/backgrounds/14.bin.lz");

const u32 gBattleAnimBackgroundImage_12[] = INCBIN_U32("graphics/battle_anims/backgrounds/12.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_12[] = INCBIN_U32("graphics/battle_anims/backgrounds/12.gbapal.lz");

const u32 gBattleAnimBackgroundImage_11[] = INCBIN_U32("graphics/battle_anims/backgrounds/11.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_11[] = INCBIN_U32("graphics/battle_anims/backgrounds/11.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_11[] = INCBIN_U32("graphics/battle_anims/backgrounds/11.bin.lz");

const u32 gBattleAnimSpriteSheet_239[] = INCBIN_U32("graphics/battle_anims/sprites/239.4bpp.lz");
const u32 gBattleAnimSpritePalette_239[] = INCBIN_U32("graphics/battle_anims/sprites/239.gbapal.lz");

const u32 gBattleAnimSpriteSheet_143[] = INCBIN_U32("graphics/battle_anims/sprites/143.4bpp.lz");
const u32 gBattleAnimSpritePalette_143[] = INCBIN_U32("graphics/battle_anims/sprites/143.gbapal.lz");

const u32 gBattleAnimSpriteSheet_240[] = INCBIN_U32("graphics/battle_anims/sprites/240.4bpp.lz");
const u32 gBattleAnimSpritePalette_240[] = INCBIN_U32("graphics/battle_anims/sprites/240.gbapal.lz");

const u32 gSubstituteDollPal[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.gbapal.lz");
const u32 gSubstituteDollGfx[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.4bpp.lz");
const u32 gSubstituteDollTilemap[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.bin.lz");

const u32 gBattleAnimSpriteSheet_241[] = INCBIN_U32("graphics/battle_anims/sprites/241.4bpp.lz");
const u32 gBattleAnimSpritePalette_241[] = INCBIN_U32("graphics/battle_anims/sprites/241.gbapal.lz");

const u32 gContestConfetti_Gfx[] = INCBIN_U32("graphics/misc/confetti.4bpp.lz");
const u32 gContestConfetti_Pal[] = INCBIN_U32("graphics/misc/confetti.gbapal.lz");

const u32 gBattleAnimSpriteSheet_242[] = INCBIN_U32("graphics/battle_anims/sprites/242.4bpp.lz");
const u32 gBattleAnimSpritePalette_242[] = INCBIN_U32("graphics/battle_anims/sprites/242.gbapal.lz");

const u32 gBattleAnimSpriteSheet_243[] = INCBIN_U32("graphics/battle_anims/sprites/243.4bpp.lz");
const u32 gBattleAnimSpritePalette_243[] = INCBIN_U32("graphics/battle_anims/sprites/243.gbapal.lz");

const u32 gBattleStatMask_Gfx[] = INCBIN_U32("graphics/battle_anims/masks/stat.4bpp.lz");
const u32 gBattleStatMask1_Tilemap[] = INCBIN_U32("graphics/battle_anims/masks/stat_tilemap_1.bin.lz");
const u32 gBattleStatMask2_Tilemap[] = INCBIN_U32("graphics/battle_anims/masks/stat_tilemap_2.bin.lz");

const u32 gBattleStatMask1_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat1.gbapal.lz");
const u32 gBattleStatMask2_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat2.gbapal.lz");
const u32 gBattleStatMask3_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat3.gbapal.lz");
const u32 gBattleStatMask4_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat4.gbapal.lz");
const u32 gBattleStatMask5_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat5.gbapal.lz");
const u32 gBattleStatMask6_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat6.gbapal.lz");
const u32 gBattleStatMask7_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat7.gbapal.lz");
const u32 gBattleStatMask8_Pal[] = INCBIN_U32("graphics/battle_anims/masks/stat8.gbapal.lz");

const u32 gUnknown_08C2DC68[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.4bpp.lz");
const u32 gUnknown_08C2DDA4[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.gbapal.lz");
const u32 gUnknown_08C2DDC4[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.bin.lz");

const u32 gBattleAnimSpritePalette_245[] = INCBIN_U32("graphics/battle_anims/sprites/245.gbapal.lz");
const u32 gBattleAnimSpriteSheet_245[] = INCBIN_U32("graphics/battle_anims/sprites/245.4bpp.lz");

const u32 gBattleAnimSpriteSheet_246[] = INCBIN_U32("graphics/battle_anims/sprites/246.4bpp.lz");

const u32 gBattleAnimSpriteSheet_244[] = INCBIN_U32("graphics/battle_anims/sprites/244.4bpp.lz");
const u32 gBattleAnimSpritePalette_244[] = INCBIN_U32("graphics/battle_anims/sprites/244.gbapal.lz");

const u32 gBattleAnimSpriteSheet_247[] = INCBIN_U32("graphics/battle_anims/sprites/247.4bpp.lz");

const u32 gBattleAnimSpriteSheet_053[] = INCBIN_U32("graphics/battle_anims/sprites/053.4bpp.lz");

const u32 gUnknown_08C2EA50[] = INCBIN_U32("graphics/battle_anims/masks/unknown_C2EA50.4bpp.lz");
const u32 gUnknown_08C2EA9C[] = INCBIN_U32("graphics/battle_anims/masks/unknown_C2EA50.bin.lz");

const u32 gBattleAnimSpriteSheet_248[] = INCBIN_U32("graphics/battle_anims/sprites/248.4bpp.lz");
const u32 gBattleAnimSpritePalette_248[] = INCBIN_U32("graphics/battle_anims/sprites/248.gbapal.lz");

const u32 gBattleAnimSpriteSheet_249[] = INCBIN_U32("graphics/battle_anims/sprites/249.4bpp.lz");
const u32 gBattleAnimSpritePalette_249[] = INCBIN_U32("graphics/battle_anims/sprites/249.gbapal.lz");

const u32 gBattleAnimSpriteSheet_250[] = INCBIN_U32("graphics/battle_anims/sprites/250.4bpp.lz");

const u32 gBattleAnimSpriteSheet_251[] = INCBIN_U32("graphics/battle_anims/sprites/251.4bpp.lz");
const u32 gBattleAnimSpritePalette_251[] = INCBIN_U32("graphics/battle_anims/sprites/251.gbapal.lz");

const u32 gBattleAnimSpriteSheet_252[] = INCBIN_U32("graphics/battle_anims/sprites/252.4bpp.lz");
const u32 gBattleAnimSpritePalette_252[] = INCBIN_U32("graphics/battle_anims/sprites/252.gbapal.lz");

const u32 gBattleAnimSpriteSheet_253[] = INCBIN_U32("graphics/battle_anims/sprites/253.4bpp.lz");
const u32 gBattleAnimSpritePalette_253[] = INCBIN_U32("graphics/battle_anims/sprites/253.gbapal.lz");

const u32 gBattleAnimSpriteSheet_254[] = INCBIN_U32("graphics/battle_anims/sprites/254.4bpp.lz");
const u32 gBattleAnimSpritePalette_254[] = INCBIN_U32("graphics/battle_anims/sprites/254.gbapal.lz");

const u32 gBattleAnimSpriteSheet_255[] = INCBIN_U32("graphics/battle_anims/sprites/255.4bpp.lz");
const u32 gBattleAnimSpritePalette_255[] = INCBIN_U32("graphics/battle_anims/sprites/255.gbapal.lz");

const u32 gBattleAnimSpriteSheet_258[] = INCBIN_U32("graphics/battle_anims/sprites/258.4bpp.lz");
const u32 gBattleAnimSpritePalette_258[] = INCBIN_U32("graphics/battle_anims/sprites/258.gbapal.lz");

const u32 gBattleAnimSpriteSheet_256[] = INCBIN_U32("graphics/battle_anims/sprites/256.4bpp.lz");
const u32 gBattleAnimSpritePalette_256[] = INCBIN_U32("graphics/battle_anims/sprites/256.gbapal.lz");

const u32 gBattleAnimSpriteSheet_257[] = INCBIN_U32("graphics/battle_anims/sprites/257.4bpp.lz");
const u32 gBattleAnimSpritePalette_257[] = INCBIN_U32("graphics/battle_anims/sprites/257.gbapal.lz");

const u32 gUnknownPal_C2F9E0[] = INCBIN_U32("graphics/unknown/unknown_C2F9E0.gbapal.lz");

#include "data/graphics/pokemon.h"
#include "data/graphics/trainers.h"

const u8 gMonIcon_QuestionMark[] = INCBIN_U8("graphics/pokemon/icons/question_mark_icon.4bpp");
const u8 gMonFootprint_QuestionMark[] = INCBIN_U8("graphics/pokemon/footprints/question_mark_footprint.1bpp");

const u32 gUnknown_08D778F0[] = INCBIN_U32("graphics/battle_transitions/vs_frame.4bpp.lz");
const u32 gUnknown_08D779D8[] = INCBIN_U32("graphics/battle_transitions/vs_frame.bin.lz");
const u32 gUnknown_08D77AE4[] = INCBIN_U32("graphics/battle_transitions/vs_frame.gbapal.lz");

const u32 gUnknown_08D77B0C[] = INCBIN_U32("graphics/battle_transitions/vs.4bpp.lz");

#include "data/graphics/battle_terrain.h"

const u32 gUnknown_08D82F10[] = INCBIN_U32("graphics/battle_frontier/tourney_bg.4bpp.lz");
const u32 gUnknown_08D834FC[] = INCBIN_U32("graphics/battle_frontier/tourney_line.4bpp.lz"); // the red glow mask for the tourney advancement lines

const u32 gUnknown_08D83900[] = INCBIN_U32("graphics/unknown/unknown_D83900.bin.lz"); // tilemaps likely

const u32 gUnknown_08D83B2C[] = INCBIN_U32("graphics/unknown/unknown_D83B2C.bin.lz");

const u32 gUnknown_08D83C3C[] = INCBIN_U32("graphics/unknown/unknown_D83C3C.bin.lz");

const u32 gUnknown_08D83D50[] = INCBIN_U32("graphics/battle_frontier/misc1.4bpp.lz");

const u32 gUnknown_08D84970[] = INCBIN_U32("graphics/unknown/unknown_D84970.bin.lz");

const u32 gUnknown_08D84F00[] = INCBIN_U32("graphics/unknown/unknown_D84F00.bin.lz");

const u32 gBattleFrontierGfx_DomeOptions[] = INCBIN_U32("graphics/battle_frontier/options.4bpp.lz");
const u32 gUnknown_08D85358[] = INCBIN_U32("graphics/battle_frontier/options_pal1.gbapal.lz");
const u32 gUnknown_08D85444[] = INCBIN_U32("graphics/battle_frontier/options_pal2.gbapal.lz"); // pokeball pal
const u32 gUnknown_08D854C8[] = INCBIN_U32("graphics/battle_frontier/options_pal3.gbapal.lz"); // arrow pal

const u32 gUnknown_08D854E8[] = INCBIN_U32("graphics/battle_frontier/symbols.4bpp.lz");
const u32 gUnknown_08D855E8[] = INCBIN_U32("graphics/battle_frontier/symbols.gbapal.lz");

const u32 gUnknown_08D85600[] = INCBIN_U32("graphics/battle_frontier/text.gbapal.lz");
const u16 gUnknown_08D85620[] = INCBIN_U16("graphics/battle_frontier/text_pp.gbapal");

const u16 gTilesetAnims_BattleDomePals0_0[] = INCBIN_U16("graphics/battle_frontier/dome_anim1.gbapal");
const u16 gTilesetAnims_BattleDomePals0_1[] = INCBIN_U16("graphics/battle_frontier/dome_anim2.gbapal");
const u16 gTilesetAnims_BattleDomePals0_2[] = INCBIN_U16("graphics/battle_frontier/dome_anim3.gbapal");
const u16 gTilesetAnims_BattleDomePals0_3[] = INCBIN_U16("graphics/battle_frontier/dome_anim4.gbapal");

// 8D856C0
asm(".2byte 0x013F, 0x0119, 0x0113, 0x010E"); // unused?

const u16 gUnknown_08D856C8[] = INCBIN_U16("graphics/battle_frontier/pyramid_light.gbapal"); // unfaded pal for the player light in battle pyramid

const u32 gUnknown_08D857A8[] = INCBIN_U32("graphics/battle_frontier/battle_tilemap1.bin.lz");
const u32 gUnknown_08D85A1C[] = INCBIN_U32("graphics/battle_frontier/battle_tilemap2.bin.lz");

#include "data/graphics/intro_scene.h"

const u32 gBattleAnimSpriteSheet_261[] = INCBIN_U32("graphics/battle_anims/sprites/261.4bpp.lz");

const u32 gUnknown_08D8D410[] = INCBIN_U32("graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz");
const u32 gUnknown_08D8D58C[] = INCBIN_U32("graphics/battle_anims/backgrounds/sandstorm_brew.4bpp.lz");

const u32 gBattleAnimSpritePalette_261[] = INCBIN_U32("graphics/battle_anims/sprites/261.gbapal.lz");

const u32 gBattleAnimSpriteSheet_260[] = INCBIN_U32("graphics/battle_anims/sprites/260.4bpp.lz");
const u32 gBattleAnimSpritePalette_260[] = INCBIN_U32("graphics/battle_anims/sprites/260.gbapal.lz");

const u32 gBattleAnimBackgroundImage_15[] = INCBIN_U32("graphics/battle_anims/backgrounds/15.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_15[] = INCBIN_U32("graphics/battle_anims/backgrounds/15.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_15[] = INCBIN_U32("graphics/battle_anims/backgrounds/15.bin.lz");

const u32 gBattleAnimSpriteSheet_262[] = INCBIN_U32("graphics/battle_anims/sprites/262.4bpp.lz");
const u32 gBattleAnimSpritePalette_262[] = INCBIN_U32("graphics/battle_anims/sprites/262.gbapal.lz");

const u32 gContestNextTurnGfx[] = INCBIN_U32("graphics/contest/nextturn.4bpp.lz");
const u8 gUnknown_08D8E9B4[] = INCBIN_U8("graphics/contest/nextturn_numbers.4bpp");
const u8 gUnknown_08D8EA34[] = INCBIN_U8("graphics/contest/nextturn_random.4bpp");

const u32 gBattleAnimSpriteSheet_264[] = INCBIN_U32("graphics/battle_anims/sprites/264.4bpp.lz");
const u32 gBattleAnimSpritePalette_264[] = INCBIN_U32("graphics/battle_anims/sprites/264.gbapal.lz");
const u32 gBattleAnimSpritePalette_265[] = INCBIN_U32("graphics/battle_anims/sprites/265.gbapal.lz");
const u32 gBattleAnimSpritePalette_067[] = INCBIN_U32("graphics/battle_anims/sprites/067.gbapal.lz");
const u32 gBattleAnimSpritePalette_068[] = INCBIN_U32("graphics/battle_anims/sprites/068.gbapal.lz");

const u32 gContestApplauseGfx[] = INCBIN_U32("graphics/contest/applause.4bpp.lz");
const u8 gContestApplauseMeterGfx[] = INCBIN_U8("graphics/contest/applause_meter.4bpp");

const u16 gContestPal[] = INCBIN_U16("graphics/contest/nextturn.gbapal");

const u32 gBattleAnimSpriteSheet_272[] = INCBIN_U32("graphics/battle_anims/sprites/272.4bpp.lz");
const u32 gBattleAnimSpritePalette_272[] = INCBIN_U32("graphics/battle_anims/sprites/272.gbapal.lz");

const u32 gBattleAnimSpriteSheet_273[] = INCBIN_U32("graphics/battle_anims/sprites/273.4bpp.lz");

const u32 gBattleAnimSpriteSheet_269[] = INCBIN_U32("graphics/battle_anims/sprites/269.4bpp.lz");
const u32 gBattleAnimSpritePalette_269[] = INCBIN_U32("graphics/battle_anims/sprites/269.gbapal.lz");

const u32 gBattleAnimSpriteSheet_274[] = INCBIN_U32("graphics/battle_anims/sprites/274.4bpp.lz");
const u32 gBattleAnimSpriteSheet_275[] = INCBIN_U32("graphics/battle_anims/sprites/275.4bpp.lz");
const u32 gBattleAnimSpriteSheet_276[] = INCBIN_U32("graphics/battle_anims/sprites/276.4bpp.lz");

const u32 gBattleAnimSpritePalette_274[] = INCBIN_U32("graphics/battle_anims/sprites/274.gbapal.lz");

const u32 gBattleAnimBackgroundImage_17[] = INCBIN_U32("graphics/battle_anims/backgrounds/17.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_17[] = INCBIN_U32("graphics/battle_anims/backgrounds/17.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_17[] = INCBIN_U32("graphics/battle_anims/backgrounds/17.bin.lz");

const u32 gBattleAnimSpriteSheet_280[] = INCBIN_U32("graphics/battle_anims/sprites/280.4bpp.lz");
const u32 gBattleAnimSpritePalette_280[] = INCBIN_U32("graphics/battle_anims/sprites/280.gbapal.lz");

const u32 gBattleAnimBackgroundImageMuddyWater_Pal[] = INCBIN_U32("graphics/battle_anims/backgrounds/water_muddy.gbapal.lz");

const u32 gEnemyMonShadow_Gfx[] = INCBIN_U32("graphics/battle_interface/enemy_mon_shadow.4bpp.lz");

const u32 gBattleInterface_BallStatusBarGfx[] = INCBIN_U32("graphics/battle_interface/ball_status_bar.4bpp.lz");

const u8 gMonIcon_Egg[] = INCBIN_U8("graphics/pokemon/icons/egg_icon.4bpp");

const u32 gBattleAnimBackgroundImage_02[] = INCBIN_U32("graphics/battle_anims/backgrounds/02.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_02[] = INCBIN_U32("graphics/battle_anims/backgrounds/02.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_02[] = INCBIN_U32("graphics/battle_anims/backgrounds/02.bin.lz");

const u32 gBattleAnimSpritePalette_287[] = INCBIN_U32("graphics/battle_anims/sprites/287.gbapal.lz");

const u32 gBattleAnimBackgroundPalette_24[] = INCBIN_U32("graphics/battle_anims/backgrounds/24.gbapal.lz");

const u32 gUnknown_E6BC04[] = INCBIN_U32("graphics/unknown/unknown_E6BC04.bin.lz");

const u32 sBlenderCenterGfx[] = INCBIN_U32("graphics/berry_blender/center.8bpp.lz");

const u32 gUnknown_08D91DB8[] = INCBIN_U32("graphics/berry_blender/outer.4bpp.lz");
const u32 gUnknown_08D927EC[] = INCBIN_U32("graphics/berry_blender/outer_map.bin.lz");

const u32 gBattleAnimBackgroundPalette_16[] = INCBIN_U32("graphics/battle_anims/backgrounds/16.gbapal.lz");
const u32 gBattleAnimBackgroundImage_16[] = INCBIN_U32("graphics/battle_anims/backgrounds/16.4bpp.lz");
const u32 gBattleAnimBackgroundTilemap_16[] = INCBIN_U32("graphics/battle_anims/backgrounds/16.bin.lz");

const u32 gBattleAnimSpritePalette_277[] = INCBIN_U32("graphics/battle_anims/sprites/277.gbapal.lz");
const u32 gBattleAnimSpriteSheet_277[] = INCBIN_U32("graphics/battle_anims/sprites/277.4bpp.lz");

const u32 gBattleAnimFogTilemap[] = INCBIN_U32("graphics/battle_anims/backgrounds/fog.bin.lz");

const u32 gBattleAnimSpritePalette_283[] = INCBIN_U32("graphics/battle_anims/sprites/283.gbapal.lz");
const u32 gBattleAnimSpriteSheet_283[] = INCBIN_U32("graphics/battle_anims/sprites/283.4bpp.lz");

const u32 gBattleAnimBackgroundTilemap_ScaryFacePlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_player.bin.lz");
const u32 gBattleAnimBackgroundTilemap_ScaryFaceOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz");
const u32 gBattleAnimBackgroundTilemap_ScaryFaceContest[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_contest.bin.lz");

const u32 gBattleAnimSpriteSheet_263[] = INCBIN_U32("graphics/battle_anims/sprites/263.4bpp.lz");
const u32 gBattleAnimSpritePalette_263[] = INCBIN_U32("graphics/battle_anims/sprites/263.gbapal.lz");

const u32 gBattleAnimSpriteSheet_266[] = INCBIN_U32("graphics/battle_anims/sprites/266.4bpp.lz");
const u32 gBattleAnimSpritePalette_266[] = INCBIN_U32("graphics/battle_anims/sprites/266.gbapal.lz");
const u32 gBattleAnimSpritePalette_267[] = INCBIN_U32("graphics/battle_anims/sprites/267.gbapal.lz");
const u32 gBattleAnimSpritePalette_268[] = INCBIN_U32("graphics/battle_anims/sprites/268.gbapal.lz");

const u32 gBattleAnimSpriteSheet_278[] = INCBIN_U32("graphics/battle_anims/sprites/278.4bpp.lz");
const u32 gBattleAnimSpritePalette_278[] = INCBIN_U32("graphics/battle_anims/sprites/278.gbapal.lz");

const u32 gBattleAnimSpriteSheet_279[] = INCBIN_U32("graphics/battle_anims/sprites/279.4bpp.lz");
const u32 gBattleAnimSpritePalette_279[] = INCBIN_U32("graphics/battle_anims/sprites/279.gbapal.lz");

const u32 gBattleAnimSpriteSheet_281[] = INCBIN_U32("graphics/battle_anims/sprites/281.4bpp.lz");
const u32 gBattleAnimSpritePalette_281[] = INCBIN_U32("graphics/battle_anims/sprites/281.gbapal.lz");

const u32 gBattleAnimBackgroundImage_21[] = INCBIN_U32("graphics/battle_anims/backgrounds/21.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_21[] = INCBIN_U32("graphics/battle_anims/backgrounds/21.gbapal.lz");
const u32 gBattleAnimBackgroundTilemap_21[] = INCBIN_U32("graphics/battle_anims/backgrounds/21.bin.lz");

const u32 gBattleAnimSpriteSheet_284[] = INCBIN_U32("graphics/battle_anims/sprites/284.4bpp.lz");
const u32 gBattleAnimSpritePalette_284[] = INCBIN_U32("graphics/battle_anims/sprites/284.gbapal.lz");

const u32 gBattleAnimSpriteSheet_285[] = INCBIN_U32("graphics/battle_anims/sprites/285.4bpp.lz");
const u32 gBattleAnimSpritePalette_285[] = INCBIN_U32("graphics/battle_anims/sprites/285.gbapal.lz");

const u32 gBattleAnimBackgroundImage_Surf[] = INCBIN_U32("graphics/battle_anims/backgrounds/water.4bpp.lz");
const u32 gBattleAnimBackgroundPalette_Surf[] = INCBIN_U32("graphics/battle_anims/backgrounds/water.gbapal.lz");

const u32 gUnknown_08D95E00[] = INCBIN_U32("graphics/unknown/unknown_D95E00.bin.lz");

const u32 gUnknown_08D960D0[] = INCBIN_U32("graphics/unknown/unknown_D960D0.bin.lz");

const u32 gUnknown_08D963A4[] = INCBIN_U32("graphics/unknown/unknown_D963A4.bin.lz");

const u32 gBattleAnimSpritePalette_286[] = INCBIN_U32("graphics/battle_anims/sprites/286.gbapal.lz");

const u32 gBattleAnimSpriteSheet_188[] = INCBIN_U32("graphics/battle_anims/sprites/188.4bpp.lz");
const u32 gBattleAnimSpritePalette_188[] = INCBIN_U32("graphics/battle_anims/sprites/188.gbapal.lz");

const u32 gPartyMenuMisc_Gfx[] = INCBIN_U32("graphics/interface/party_menu_misc.4bpp.lz");
const u32 gPartyMenuMisc_Pal[] = INCBIN_U32("graphics/interface/party_menu_misc.gbapal.lz");
const u32 gPartyMenuMisc_Tilemap[] = INCBIN_U32("graphics/interface/party_menu_misc.bin.lz");

const u32 gPartyMenuPokeball_Gfx[] = INCBIN_U32("graphics/interface/party_menu_pokeball.4bpp.lz");
const u32 gPartyMenuPokeballSmall_Gfx[] = INCBIN_U32("graphics/interface/party_menu_pokeball_small.4bpp.lz"); //unused
const u32 gPartyMenuPokeball_Pal[] = INCBIN_U32("graphics/interface/party_menu_pokeball.gbapal.lz");

const u32 gStatusGfx_Icons[] = INCBIN_U32("graphics/interface/status_icons.4bpp.lz");
const u32 gStatusPal_Icons[] = INCBIN_U32("graphics/interface/status_icons.gbapal.lz");

const u32 gMoveTypes_Gfx[] = INCBIN_U32("graphics/types/move_types.4bpp.lz");
const u32 gMoveTypes_Pal[] = INCBIN_U32("graphics/types/move_types.gbapal.lz");

const u32 gUnknown_08D97BEC[] = INCBIN_U32("graphics/interface/summary_frames.4bpp.lz");
const u32 gUnknown_08D97CF4[] = INCBIN_U32("graphics/interface/summary_frames.gbapal.lz");

const u32 gUnknown_08D97D0C[] = INCBIN_U32("graphics/interface/status_screen.4bpp.lz");
const u32 gUnknown_08D9853C[] = INCBIN_U32("graphics/interface/status_screen.gbapal.lz");
const u32 gUnknown_08D9862C[] = INCBIN_U32("graphics/interface/status_screen.bin.lz");

const u32 gUnknown_08D987FC[] = INCBIN_U32("graphics/interface/status_tilemap1.bin.lz");
const u32 gUnknown_08D9898C[] = INCBIN_U32("graphics/interface/status_tilemap2.bin.lz");
const u32 gUnknown_08D98B28[] = INCBIN_U32("graphics/interface/status_tilemap3.bin.lz");
const u32 gUnknown_08D98CC8[] = INCBIN_U32("graphics/interface/status_tilemap0.bin.lz");

const u32 gBagMaleTiles[] = INCBIN_U32("graphics/misc/bag_male.4bpp.lz");
const u32 gBagFemaleTiles[] = INCBIN_U32("graphics/misc/bag_female.4bpp.lz");
const u32 gBagPalette[] = INCBIN_U32("graphics/misc/bag.gbapal.lz");

const u32 gBagScreenMale_Pal[] = INCBIN_U32("graphics/interface/bag_screen_male.gbapal.lz");
const u32 gBagScreenFemale_Pal[] = INCBIN_U32("graphics/interface/bag_screen_female.gbapal.lz");

const u32 gBagScreen_Gfx[] = INCBIN_U32("graphics/interface/bag_screen.4bpp.lz");

const u32 gUnknown_08D9A88C[] = INCBIN_U32("graphics/unknown/unknown_D9A88C.bin.lz");

const u32 gBattleFrontierGfx_PyramidBag[] = INCBIN_U32("graphics/interface/bag_pyramid.4bpp.lz");
const u32 gUnknown_08D9ADD0[] = INCBIN_U32("graphics/interface/bag_pyramid.gbapal.lz"); // female palette is first and male is second.

const u32 gUnknown_08D9AE04[] = INCBIN_U32("graphics/unknown/unknown_D9AE04.bin.lz");

const u32 gUnknown_08D9AF44[] = INCBIN_U32("graphics/unknown/unknown_D9AF44.gbapal.lz");

const u32 gBagSwapLineGfx[] = INCBIN_U32("graphics/interface/bag_swap.4bpp.lz");
const u32 gBagSwapLinePal[] = INCBIN_U32("graphics/interface/bag_swap.gbapal.lz");

const u32 gBuyMenuFrame_Gfx[] = INCBIN_U32("graphics/interface/mart_frame.4bpp.lz");
const u32 gMenuMoneyPal[] = INCBIN_U32("graphics/interface/mart_frame.gbapal.lz");
const u32 gBuyMenuFrame_Tilemap[] = INCBIN_U32("graphics/interface/mart_frame.bin.lz");

const u32 gMenuMoneyGfx[] = INCBIN_U32("graphics/interface/money.4bpp.lz");

// Pokeblock

const u32 gMenuPokeblock_Gfx[] = INCBIN_U32("graphics/interface/pokeblock_case_frame.4bpp.lz");
const u32 gMenuPokeblock_Pal[] = INCBIN_U32("graphics/interface/pokeblock_case_frame.gbapal.lz");

const u32 gMenuPokeblockDevice_Gfx[] = INCBIN_U32("graphics/interface/pokeblock_device.4bpp.lz");
const u32 gMenuPokeblockDevice_Pal[] = INCBIN_U32("graphics/interface/pokeblock_device.gbapal.lz");

const u32 gMenuPokeblock_Tilemap[] = INCBIN_U32("graphics/interface/pokeblock.bin.lz");
const u32 gPokeblock_Gfx[] = INCBIN_U32("graphics/pokeblock/pokeblock.4bpp.lz");
const u32 gPokeblockRed_Pal[] = INCBIN_U32("graphics/pokeblock/red.gbapal.lz");
const u32 gPokeblockBlue_Pal[] = INCBIN_U32("graphics/pokeblock/blue.gbapal.lz");
const u32 gPokeblockPink_Pal[] = INCBIN_U32("graphics/pokeblock/pink.gbapal.lz");
const u32 gPokeblockGreen_Pal[] = INCBIN_U32("graphics/pokeblock/green.gbapal.lz");
const u32 gPokeblockYellow_Pal[] = INCBIN_U32("graphics/pokeblock/yellow.gbapal.lz");
const u32 gPokeblockPurple_Pal[] = INCBIN_U32("graphics/pokeblock/purple.gbapal.lz");
const u32 gPokeblockIndigo_Pal[] = INCBIN_U32("graphics/pokeblock/indigo.gbapal.lz");
const u32 gPokeblockBrown_Pal[] = INCBIN_U32("graphics/pokeblock/brown.gbapal.lz");
const u32 gPokeblockLiteBlue_Pal[] = INCBIN_U32("graphics/pokeblock/liteblue.gbapal.lz");
const u32 gPokeblockOlive_Pal[] = INCBIN_U32("graphics/pokeblock/olive.gbapal.lz");
const u32 gPokeblockGray_Pal[] = INCBIN_U32("graphics/pokeblock/gray.gbapal.lz");
const u32 gPokeblockBlack_Pal[] = INCBIN_U32("graphics/pokeblock/black.gbapal.lz");
const u32 gPokeblockWhite_Pal[] = INCBIN_U32("graphics/pokeblock/white.gbapal.lz");
const u32 gPokeblockGold_Pal[] = INCBIN_U32("graphics/pokeblock/gold.gbapal.lz");

const u32 gUnknown_08D9BA44[] = INCBIN_U32("graphics/interface/pokeblock_feeding_bg_map.bin.lz");

#include "data/graphics/berries.h"
#include "data/graphics/rayquaza_scene.h"
#include "data/graphics/items.h"
#include "data/graphics/decorations.h"

const u32 gBattleAnimSpritePalette_282[] = INCBIN_U32("graphics/battle_anims/sprites/282.gbapal.lz");
const u32 gBattleAnimSpriteSheet_282[] = INCBIN_U32("graphics/battle_anims/sprites/282.4bpp.lz");

const u32 gBattleAnimSpritePalette_270[] = INCBIN_U32("graphics/battle_anims/sprites/270.gbapal.lz");
const u32 gBattleAnimSpriteSheet_270[] = INCBIN_U32("graphics/battle_anims/sprites/270.4bpp.lz");

const u32 gBattleAnimSpritePalette_271[] = INCBIN_U32("graphics/battle_anims/sprites/271.gbapal.lz");
const u32 gBattleAnimSpriteSheet_271[] = INCBIN_U32("graphics/battle_anims/sprites/271.4bpp.lz");

const u16 gUnknown_08DBA518[] = INCBIN_U16("graphics/misc/cable_car_bg.gbapal");
const u16 gCableCar_Pal[] = INCBIN_U16("graphics/misc/cable_car.gbapal");

const u32 gUnknown_08DBA5B8[] = INCBIN_U32("graphics/misc/cable_car_bg.4bpp.lz");
const u32 gCableCar_Gfx[] = INCBIN_U32("graphics/misc/cable_car.4bpp.lz");
const u32 gCableCarDoor_Gfx[] = INCBIN_U32("graphics/misc/cable_car_door.4bpp.lz");
const u32 gCableCarCord_Gfx[] = INCBIN_U32("graphics/misc/cable_car_cord.4bpp.lz");

const u32 gRouletteMenuTiles[] = INCBIN_U32("graphics/roulette/window.4bpp.lz");
const u32 gRouletteWheelTiles[] = INCBIN_U32("graphics/roulette/wheel.8bpp.lz");
const u32 gRouletteCenter_Gfx[] = INCBIN_U32("graphics/roulette/center.4bpp.lz");
const u32 gRouletteHeadersTiles[] = INCBIN_U32("graphics/roulette/headers.4bpp.lz");
const u32 gRouletteCreditTiles[] = INCBIN_U32("graphics/roulette/credit.4bpp.lz");
const u32 gRouletteNumbersTiles[] = INCBIN_U32("graphics/roulette/numbers.4bpp.lz");
const u32 gRouletteMultiplierTiles[] = INCBIN_U32("graphics/roulette/multiplier.4bpp.lz");

#include "data/graphics/mail.h"

const u16 gFrontierFactorySelectMenu_Pal[] = INCBIN_U16("graphics/battle_frontier/factory_menu1.gbapal");
const u16 gFrontierFactorySelectMenu_Pal2[] = INCBIN_U16("graphics/battle_frontier/factory_menu2.gbapal");

const u8 gFrontierFactorySelectMenu_Gfx[] = INCBIN_U8("graphics/battle_frontier/factory_menu1.4bpp");
const u8 gFrontierFactorySelectMenu_Gfx2[] = INCBIN_U8("graphics/battle_frontier/factory_menu2.4bpp");

const u16 gFrontierFactorySelectMenu_Tilemap[] = INCBIN_U16("graphics/battle_frontier/factory_menu.bin");

const u32 gFrontierPassMedals_Gfx[] = INCBIN_U32("graphics/frontier_pass/medals.4bpp.lz");

const u16 gFrontierPassCursor_Pal[] = INCBIN_U16("graphics/frontier_pass/cursor.gbapal");

const u16 gFrontierPassMapCursor_Pal[] = INCBIN_U16("graphics/frontier_pass/map_cursor.gbapal");

const u16 gFrontierPassMedalsSilver_Pal[] = INCBIN_U16("graphics/frontier_pass/silver.gbapal");
const u16 gFrontierPassMedalsGold_Pal[] = INCBIN_U16("graphics/frontier_pass/gold.gbapal");

const u16 gPokedexText_Pal[] = INCBIN_U16("graphics/pokedex/text.gbapal");

const u16 gPokedexCaughtScreenFade_Pal[] = INCBIN_U16("graphics/pokedex/fade.gbapal");

const u16 gPokedexHoennBg_Pal[] = INCBIN_U16("graphics/pokedex/hoenn_bg.gbapal");
const u16 gPokedexNationalBg_Pal[] = INCBIN_U16("graphics/pokedex/national_bg.gbapal");

const u32 gPokedexMenu_Gfx[] = INCBIN_U32("graphics/pokedex/menu.4bpp.lz");
const u32 gPokedexMenu2_Gfx[] = INCBIN_U32("graphics/pokedex/menu2.4bpp.lz");

const u32 gUnused_PokedexNoBall[] = INCBIN_U32("graphics/pokedex/noball_unused.4bpp.lz");

const u32 gPokedexTilemap_StartMenu1[] = INCBIN_U32("graphics/pokedex/tilemap1.bin.lz");
const u32 gPokedexTilemap_StartMenu2[] = INCBIN_U32("graphics/pokedex/tilemap2.bin.lz");
const u32 gPokedexTilemap_Main[] = INCBIN_U32("graphics/pokedex/tilemap3.bin.lz");
const u32 gPokedexTilemap_MainUnderlay[] = INCBIN_U32("graphics/pokedex/tilemap4.bin.lz");
const u32 gPokedexTilemap_SizeScreen[] = INCBIN_U32("graphics/pokedex/tilemap5.bin.lz");
const u32 gPokedexTilemap_ScreenSelectBar1[] = INCBIN_U32("graphics/pokedex/tilemap6.bin.lz");
const u32 gPokedexTilemap_ScreenSelectBar2[] = INCBIN_U32("graphics/pokedex/tilemap7.bin.lz");
const u32 gPokedexTilemap_DescriptionScreen[] = INCBIN_U32("graphics/pokedex/tilemap8.bin.lz");
const u32 gPokedexTilemap_CryScreen[] = INCBIN_U32("graphics/pokedex/tilemap9.bin.lz");

const u16 gPokedexSearchMenu_Pal[] = INCBIN_U16("graphics/pokedex/search_menu.gbapal");
const u32 gPokedexSearchMenu_Gfx[] = INCBIN_U32("graphics/pokedex/search_menu.4bpp.lz");
const u32 gPokedexSearch1_Tilemap[] = INCBIN_U32("graphics/pokedex/search1.bin.lz");
const u32 gPokedexSearch2_Tilemap[] = INCBIN_U32("graphics/pokedex/search2.bin.lz");

const u16 gSummaryScreenPowAcc_Tilemap[] = INCBIN_U16("graphics/interface/powacc_tilemap.bin");

const u16 gUnknown_08DC3C34[] = INCBIN_U16("graphics/interface/unk_tilemap.bin"); // probably trade summary screen related?

const u16 gSummaryScreenWindow_Tilemap[] = INCBIN_U16("graphics/interface/summary.bin");

const u16 gIntroCopyright_Pal[] = INCBIN_U16("graphics/intro/copyright.gbapal");
const u32 gIntroCopyright_Gfx[] = INCBIN_U32("graphics/intro/copyright.4bpp.lz");
const u32 gIntroCopyright_Tilemap[] = INCBIN_U32("graphics/intro/copyright.bin.lz");

const u16 gPokedexAreaScreenAreaUnknown_Pal[] = INCBIN_U16("graphics/pokedex/area_unknown.gbapal");
const u32 gPokedexAreaScreenAreaUnknown_Gfx[] = INCBIN_U32("graphics/pokedex/area_unknown.4bpp.lz");

// seems to be fire red leftovers, but the menu elements is reused in the item menu for TM descriptions.

const u16 gFireRedMenuElements1_Pal[] = INCBIN_U16("graphics/interface_fr/menu1.gbapal");
const u16 gFireRedMenuElements2_Pal[] = INCBIN_U16("graphics/interface_fr/menu2.gbapal");
const u16 gFireRedMenuElements3_Pal[] = INCBIN_U16("graphics/interface_fr/menu3.gbapal");
const u8 gFireRedMenuElements_Gfx[] = INCBIN_U8("graphics/interface_fr/menu.4bpp"); //the types are reused for item menu

const u8 gBagMenuHMIcon_Gfx[] = INCBIN_U8("graphics/interface/hm.4bpp");

// contest link stuff, appears to be a set of tilemaps

const u16 gUnknown_08DC63F8[] = INCBIN_U16("graphics/contest/clink_tilemap1.bin");
const u16 gUnknown_08DC6420[] = INCBIN_U16("graphics/contest/clink_tilemap2.bin");
const u16 gUnknown_08DC6448[] = INCBIN_U16("graphics/contest/clink_tilemap3.bin");
const u16 gUnknown_08DC6470[] = INCBIN_U16("graphics/contest/clink_tilemap4.bin");
const u16 gUnknown_08DC6498[] = INCBIN_U16("graphics/contest/clink_tilemap5.bin");
const u16 gUnknown_08DC64AC[] = INCBIN_U16("graphics/contest/clink_tilemap6.bin");
const u16 gUnknown_08DC64C0[] = INCBIN_U16("graphics/contest/clink_tilemap7.bin");
const u16 gUnknown_08DC64D4[] = INCBIN_U16("graphics/contest/clink_tilemap8.bin");
const u16 gUnknown_08DC64E8[] = INCBIN_U16("graphics/contest/clink_tilemap9.bin");
const u16 gUnknown_08DC64FC[] = INCBIN_U16("graphics/contest/clink_tilemap10.bin");
const u16 gUnknown_08DC6510[] = INCBIN_U16("graphics/contest/clink_tilemap11.bin");

// pokenav

const u16 gPokenavCondition_Pal[] = INCBIN_U16("graphics/pokenav/condition.gbapal");

const u32 gPokenavCondition_Gfx[] = INCBIN_U32("graphics/pokenav/condition.4bpp.lz");
const u32 gPokenavCondition_Tilemap[] = INCBIN_U32("graphics/pokenav/condition.bin.lz");

const u16 gPokenavOptions_Tilemap[] = INCBIN_U16("graphics/pokenav/options/options.bin");
const u32 gPokenavOptions_Gfx[] = INCBIN_U32("graphics/pokenav/options/options.4bpp.lz");
const u16 gPokenavOptions_Pal[] = INCBIN_U16("graphics/pokenav/options/options.gbapal");

const u16 gPokenavHeader_Pal[] = INCBIN_U16("graphics/pokenav/header.gbapal");
const u32 gPokenavHeader_Gfx[] = INCBIN_U32("graphics/pokenav/header.4bpp.lz"); // TODO: use width 9 and makefile rule for cleanliness, make wasnt behaving, didnt want to apply num_tiles to this
const u32 gPokenavHeader_Tilemap[] = INCBIN_U32("graphics/pokenav/header.bin.lz");

const u16 gPokenavLeftHeader_Pal[] = INCBIN_U16("graphics/pokenav/left_headers/palette.gbapal");
const u32 gPokenavLeftHeaderBeauty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/beauty.4bpp.lz");
const u32 gPokenavLeftHeaderSmart_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/smart.4bpp.lz");
const u32 gPokenavLeftHeaderCondition_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/condition.4bpp.lz");
const u32 gPokenavLeftHeaderCute_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cute.4bpp.lz");
const u32 gPokenavLeftHeaderMatchCall_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/match_call.4bpp.lz");
const u32 gPokenavLeftHeaderMainMenu_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/main_menu.4bpp.lz");
const u32 gPokenavLeftHeaderHoennMap_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/hoenn_map.4bpp.lz");
const u32 gPokenavLeftHeaderRibbons_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/ribbons.4bpp.lz");
const u32 gPokenavLeftHeaderSearch_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/search.4bpp.lz");
const u32 gPokenavLeftHeaderTough_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/tough.4bpp.lz");
const u32 gPokenavLeftHeaderCool_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cool.4bpp.lz");
const u32 gPokenavLeftHeaderParty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/party.4bpp.lz");

const u16 gPokenavMessageBox_Pal[] = INCBIN_U16("graphics/pokenav/message.gbapal");
const u32 gPokenavMessageBox_Gfx[] = INCBIN_U32("graphics/pokenav/message.4bpp.lz");
const u32 gPokenavMessageBox_Tilemap[] = INCBIN_U32("graphics/pokenav/message.bin.lz");

const u16 gHoennMapZoomIcons_Pal[] = INCBIN_U16("graphics/pokenav/zoom.gbapal");
const u32 gHoennMapZoomIcons_Gfx[] = INCBIN_U32("graphics/pokenav/zoom.4bpp.lz");

const u16 gPokenavConditionCancel_Pal[] = INCBIN_U16("graphics/pokenav/cancel.gbapal");
const u8 gPokenavConditionCancel_Gfx[] = INCBIN_U8("graphics/pokenav/cancel.4bpp");

const u16 gPokenavConditionMarker_Pal[] = INCBIN_U16("graphics/pokenav/marker.gbapal");
const u8 gPokenavConditionMarker_Gfx[] = INCBIN_U8("graphics/pokenav/marker.4bpp");

const u16 gBerryBlenderMiscPalette[] = INCBIN_U16("graphics/berry_blender/misc.gbapal");

const u16 gBerryBlenderArrowPalette[] = INCBIN_U16("graphics/berry_blender/arrow.gbapal");

const u8 gBerryBlenderBetaArrow_Gfx[] = INCBIN_U8("graphics/berry_blender/arrow_old.4bpp"); //unused

const u8 gBerryBlenderMarubatsuTiles[] = INCBIN_U8("graphics/berry_blender/marubatsu.4bpp");

const u8 gBerryBlenderParticlesTiles[] = INCBIN_U8("graphics/berry_blender/particles.4bpp");

asm(".space 0x120");

const u8 gBerryBlenderCountdownNumbersTiles[] = INCBIN_U8("graphics/berry_blender/countdown_numbers.4bpp");

const u8 gBerryBlenderStartTiles[] = INCBIN_U8("graphics/berry_blender/start.4bpp");

asm(".space 0x200");

const u8 gBerryBlenderArrowTiles[] = INCBIN_U8("graphics/berry_blender/arrow.4bpp");

asm(".space 0x2C0");

const u16 gEasyChatCursor_Pal[] = INCBIN_U16("graphics/easy_chat/cursor.gbapal");
const u32 gEasyChatCursor_Gfx[] = INCBIN_U32("graphics/easy_chat/cursor.4bpp.lz");

const u16 gEasyChatRightWindow_Pal[] = INCBIN_U16("graphics/easy_chat/rwindow.gbapal");
const u32 gEasyChatRightWindow_Gfx[] = INCBIN_U32("graphics/easy_chat/rwindow.4bpp.lz");

const u32 gEasyChatMode_Gfx[] = INCBIN_U32("graphics/easy_chat/mode.4bpp.lz");
const u16 gEasyChatMode_Pal[] = INCBIN_U16("graphics/easy_chat/mode.gbapal");

const u32 gEasyChatWindow_Gfx[] = INCBIN_U32("graphics/easy_chat/window.4bpp.lz"); // uses mode pal
const u32 gEasyChatWindow_Tilemap[] = INCBIN_U32("graphics/easy_chat/window.bin.lz");

const u16 gWallclockMale_Pal[] = INCBIN_U16("graphics/interface/wallclock_male.gbapal");
const u16 gWallclockFemale_Pal[] = INCBIN_U16("graphics/interface/wallclock_female.gbapal");
const u32 gWallclock_Gfx[] = INCBIN_U32("graphics/interface/wallclock.4bpp.lz");
const u32 gUnknown_08DCC648[] = INCBIN_U32("graphics/interface/wallclock1.bin.lz");
const u32 gUnknown_08DCC908[] = INCBIN_U32("graphics/interface/wallclock2.bin.lz");

const u16 gUsePokeblockCondition_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/condition.gbapal");
const u32 gUsePokeblockCondition_Gfx[] = INCBIN_U32("graphics/pokeblock/use_screen/condition.4bpp.lz");

const u16 gUsePokeblockUpDown_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/updown.gbapal");
const u8 gUsePokeblockUpDown_Gfx[] = INCBIN_U8("graphics/pokeblock/use_screen/updown.4bpp");

const u16 gUsePokeblockGraph_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/graph.gbapal");
const u32 gUsePokeblockGraph_Gfx[] = INCBIN_U32("graphics/pokeblock/use_screen/graph.4bpp.lz");

const u32 gUsePokeblockGraph_Tilemap[] = INCBIN_U32("graphics/pokeblock/use_screen/graph.bin.lz");
const u16 gUsePokeblockNatureWin_Pal[] = INCBIN_U16("graphics/pokeblock/use_screen/nature.gbapal");

#include "data/graphics/slot_machine.h"

const u16 gUnknown_08DD19F8[] = INCBIN_U16("graphics/unknown/unknown_DD19F8.bin");

const u8 gUnknown_08DD1A18[] = INCBIN_U8("graphics/unknown/unknown_DD1A18.4bpp");

// trainer card

const u16 gEmeraldTrainerCard0Star_Pal[] = INCBIN_U16("graphics/trainer_card/0star.gbapal");
const u32 gEmeraldTrainerCard_Gfx[] = INCBIN_U32("graphics/trainer_card/card.4bpp.lz");

const u32 gUnknown_08DD1F78[] = INCBIN_U32("graphics/unknown/unknown_DD1F78.bin.lz");
const u32 gUnknown_08DD2010[] = INCBIN_U32("graphics/unknown/unknown_DD2010.bin.lz");
const u32 gUnknown_08DD21B0[] = INCBIN_U32("graphics/unknown/unknown_DD21B0.bin.lz");
const u32 gUnknown_08DD228C[] = INCBIN_U32("graphics/unknown/unknown_DD228C.bin.lz");

const u16 gFireRedTrainerCard0Star_Pal[] = INCBIN_U16("graphics/trainer_card/0star_fr.gbapal");
const u32 gFireRedTrainerCard_Gfx[] = INCBIN_U32("graphics/trainer_card/card_fr.4bpp.lz");

const u32 gUnknown_08DD2AE0[] = INCBIN_U32("graphics/unknown/unknown_DD2AE0.bin.lz");
const u32 gUnknown_08DD2B78[] = INCBIN_U32("graphics/unknown/unknown_DD2B78.bin.lz");
const u32 gUnknown_08DD2D30[] = INCBIN_U32("graphics/unknown/unknown_DD2D30.bin.lz");
const u32 gUnknown_08DD2E5C[] = INCBIN_U32("graphics/unknown/unknown_DD2E5C.bin.lz");

// pokemon storage system

const u32 gPSSMenu_Gfx[] = INCBIN_U32("graphics/pokemon_storage/menu.4bpp.lz");
const u16 gPSSMenu_Pal[] = INCBIN_U16("graphics/pokemon_storage/menu.gbapal");
const u32 gUnknown_08DD36C8[] = INCBIN_U32("graphics/unknown/unknown_DD36C8.bin.lz");

// naming screen

const u16 gNamingScreenMenu_Pal[] = INCBIN_U16("graphics/naming_screen/menu.gbapal");
const u32 gNamingScreenMenu_Gfx[] = INCBIN_U32("graphics/naming_screen/menu.4bpp.lz");
const u8 gNamingScreenRWindow_Gfx[] = INCBIN_U8("graphics/naming_screen/rwindow.4bpp");
const u8 gNamingScreenROptions_Gfx[] = INCBIN_U8("graphics/naming_screen/roptions.4bpp");
const u8 gNamingScreenCursor_Gfx[] = INCBIN_U8("graphics/naming_screen/cursor.4bpp");
const u8 gNamingScreenKeyboardButton_Gfx[] = INCBIN_U8("graphics/naming_screen/keyboard_button.4bpp");

const u8 gNamingScreenRightPointingTriangleTiles[] = INCBIN_U8("graphics/naming_screen/right_pointing_triangle.4bpp");
const u8 gNamingScreenUnderscoreTiles[] = INCBIN_U8("graphics/naming_screen/underscore.4bpp");

const u32 gUnknown_08DD4544[] = INCBIN_U32("graphics/unknown/unknown_DD4544.bin.lz");
const u32 gUnknown_08DD4620[] = INCBIN_U32("graphics/unknown/unknown_DD4620.bin.lz");
const u32 gUnknown_08DD46E0[] = INCBIN_U32("graphics/unknown/unknown_DD46E0.bin.lz");
const u32 gUnknown_08DD47A0[] = INCBIN_U32("graphics/unknown/unknown_DD47A0.bin.lz");

// link

const u16 gLinkMiscMenu_Pal[] = INCBIN_U16("graphics/link/misc.gbapal");
const u32 gLinkMiscMenu_Gfx[] = INCBIN_U32("graphics/link/misc.4bpp.lz");
const u32 gLinkMiscMenu_Tilemap[] = INCBIN_U32("graphics/link/misc.bin.lz");

const u16 gUnknown_08DD4BB0[] = INCBIN_U16("graphics/link/link1.gbapal");
const u16 gUnknown_08DD4BD0[] = INCBIN_U16("graphics/link/link2.gbapal");

const u32 gUnknown_08DD4BF0[] = INCBIN_U32("graphics/link/link_winedge.4bpp.lz");
const u32 gUnknown_08DD4C4C[] = INCBIN_U32("graphics/link/link_winedge.bin.lz");

const u32 gUnknown_08DD4CF8[] = INCBIN_U32("graphics/interface/unk_change_case.4bpp.lz");

const u16 gTilesetPalettes_General[][16] =
{
    INCBIN_U16("data/tilesets/primary/general/palettes/00.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/01.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/02.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/03.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/04.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/05.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/06.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/07.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/08.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/09.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/10.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/11.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/12.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/13.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/14.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/15.gbapal"),
};

const u32 gTilesetTiles_General[] = INCBIN_U32("data/tilesets/primary/general/tiles.4bpp.lz");

// trade/egg hatch

const u16 gTradeGba_Pal[] = INCBIN_U16("graphics/link/gba.gbapal");
const u16 gTradeGba2_Pal[] = INCBIN_U16("graphics/link/gba_pal2.gbapal");
const u8 gTradeGba_Gfx[] = INCBIN_U8("graphics/link/gba.4bpp");

// 8DD8760
asm(".space 0x20"); //blank palette??

#include "data/graphics/berry_fix.h"

// more trade stuff?

const u16 gUnknown_08DDB3E4[] = INCBIN_U16("graphics/trade/menu.gbapal");

const u16 gUnknown_08DDB444[] = INCBIN_U16("graphics/unknown/unknown_DDB444.gbapal");

const u8 gUnknown_08DDB464[] = INCBIN_U8("graphics/trade/menu.4bpp");

const u8 gUnknown_08DDC6E4[] = INCBIN_U8("graphics/trade/buttons.4bpp");

const u16 gUnused_DDCEE4[] = INCBIN_U16("graphics/unused/unused_DDCEE4.bin");

const u16 gUnknown_08DDCF04[] = INCBIN_U16("graphics/unknown/unknown_DDCF04.bin");

const u16 gUnknown_08DDD704[] = INCBIN_U16("graphics/unknown/unknown_DDD704.bin"); // textbox tilemap??

const u16 gMessageBox_Pal[] = INCBIN_U16("graphics/text_window/message_box.gbapal");
const u8 gMessageBox_Gfx[] = INCBIN_U8("graphics/text_window/message_box.4bpp");

const u32 gWallpaperIcon_Cross[] = INCBIN_U32("graphics/pokemon_storage/cross_icon.4bpp.lz");
const u32 gWallpaperIcon_Bolt[] = INCBIN_U32("graphics/pokemon_storage/bolt_icon.4bpp.lz");
const u32 gWallpaperIcon_Plusle[] = INCBIN_U32("graphics/pokemon_storage/plusle_icon.4bpp.lz");

const u16 gWallpaperPalettes_Horizontal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/horizontal_bg.gbapal"),
};

const u32 gWallpaperTiles_Horizontal[] = INCBIN_U32("graphics/pokemon_storage/horizontal.4bpp.lz");
const u32 gWallpaperTilemap_Horizontal[] = INCBIN_U32("graphics/pokemon_storage/horizontal.bin.lz");

const u16 gWallpaperPalettes_Ribbon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/ribbon_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/ribbon_bg.gbapal"),
};

const u32 gWallpaperTiles_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/ribbon.4bpp.lz");
const u32 gWallpaperTilemap_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/ribbon.bin.lz");

// pokenav

const u16 gUnknown_08DDE010[] = INCBIN_U16("graphics/pokenav/ribbons.gbapal");
const u32 gUnknown_08DDE030[] = INCBIN_U32("graphics/pokenav/ribbons.4bpp.lz");
const u32 gUnknown_08DDE12C[] = INCBIN_U32("graphics/pokenav/ribbons.bin.lz");

const u16 gMonIconPalettes[][16] =
{
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_0.gbapal"),
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_1.gbapal"),
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_2.gbapal"),
};

const u16 gTitleScreenBgPalettes[] = INCBIN_U16("graphics/title_screen/pokemon_logo.gbapal");
const u16 gTitleScreenBgPalettes2[] = INCBIN_U16("graphics/title_screen/rayquaza_and_clouds.gbapal");

const u16 gTitleScreenEmeraldVersionPal[] = INCBIN_U16("graphics/title_screen/emerald_version.gbapal");

const u32 gUnknown_08DDE458[] = INCBIN_U32("graphics/title_screen/title_screen1.bin.lz");

const u32 gTitleScreenPokemonLogoGfx[] = INCBIN_U32("graphics/title_screen/pokemon_logo.8bpp.lz");

const u32 gTitleScreenEmeraldVersionGfx[] = INCBIN_U32("graphics/title_screen/emerald_version.8bpp.lz");

const u16 gTitleScreenPressStartPal[] = INCBIN_U16("graphics/title_screen/press_start.gbapal");
const u32 gTitleScreenPressStartGfx[] = INCBIN_U32("graphics/title_screen/press_start.4bpp.lz");

const u32 gUnknown_08DE0644[] = INCBIN_U32("graphics/title_screen/title_screen2.bin.lz");

// more trainer card stuff

const u16 gUnknown_08DE07C8[] = INCBIN_U16("graphics/frontier_pass/tiles.gbapal");// size in LoadPalette calls is reported as 0xD0 << 1, which is 0x1A0, but palette is only 0x100 bytes long so it loads garbage as well
const u32 gUnknown_08DE08C8[] = INCBIN_U32("graphics/frontier_pass/tiles.4bpp.lz");
const u32 gUnknown_08DE2084[] = INCBIN_U32("graphics/frontier_pass/tiles2.8bpp.lz");
const u32 gUnknown_08DE3060[] = INCBIN_U32("graphics/frontier_pass/tiles.bin.lz");
const u16 gUnknown_08DE3350[] = INCBIN_U16("graphics/frontier_pass/tilemap1.bin");
const u16 gUnknown_08DE3374[] = INCBIN_U16("graphics/frontier_pass/tilemap2.bin");

// berry crusher

const u16 gUnknown_08DE3398[] = INCBIN_U16("graphics/berry_crusher/tiles.gbapal");
const u32 gUnknown_08DE34B8[] = INCBIN_U32("graphics/berry_crusher/tiles.4bpp.lz");
const u32 gUnknown_08DE3FD4[] = INCBIN_U32("graphics/berry_crusher/tiles.bin.lz");

// random garbage at the end.
asm(".space 0x54BAC \n\
     .byte 0x0D, 0x00, 0x58, 0x02 \n\
     .space 0x1145 \n\
     .byte 0x02 \n\
     .space 0x3242 \n\
     .byte 0x40 \n\
     .space 0x13");
