#include "global.h"
#include "battle.h"
#include "sprite.h"
#include "constants/trainers.h"
#include "graphics.h"
#include "decompress.h"
#include "bg.h"
#include "palette.h"
#include "main.h"
#include "gpu_regs.h"
#include "link.h"
#include "battle_message.h"
#include "task.h"
#include "trig.h"
#include "sound.h"
#include "constants/songs.h"
#include "strings.h"
#include "window.h"
#include "text_window.h"
#include "menu.h"
#include "battle_setup.h"

struct BattleBackground
{
    const void *tileset;
    const void *tilemap;
    const void *entryTileset;
    const void *entryTilemap;
    const void *palette;
};

extern const struct SpriteTemplate gUnknown_0831A9D0;
extern const struct SpriteTemplate gUnknown_0831A9E8;
extern const struct CompressedSpriteSheet gUnknown_0831AA00;
extern const struct BgTemplate gUnknown_0831AA08[4];
extern const struct WindowTemplate *gUnknown_0831ABA0[];
extern const struct BattleBackground gBattleTerrainTable[];

extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;

extern u8 GetCurrentMapBattleScene(void);

void sub_8035658(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0831AA08, ARRAY_COUNT(gUnknown_0831AA08));

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        gBattleScripting.field_24 = 1;
        SetBgTilemapBuffer(1, gUnknown_02023060);
        SetBgTilemapBuffer(2, gUnknown_02023060);
    }
    else
    {
        gBattleScripting.field_24 = 0;
    }

    InitWindows(gUnknown_0831ABA0[gBattleScripting.field_24]);
    DeactivateAllTextPrinters();
}

void sub_80356D0(void)
{
    DisableInterrupts(INTR_FLAG_HBLANK);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    sub_8035658();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

void ApplyPlayerChosenFrameToBattleMenu(void)
{
    sub_809882C(2, 0x12, 0x10);
    sub_809882C(2, 0x22, 0x10);
    LoadCompressedPalette(gUnknown_08D85600, 0x50, 0x20);

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        sub_81978B0(0x70);
        copy_textbox_border_tile_patterns_to_vram(0, 0x30, 0x70);
        gPlttBufferUnfaded[0x76] = 0;
        CpuCopy16(&gPlttBufferUnfaded[0x76], &gPlttBufferFaded[0x76], 2);
    }
}

void DrawMainBattleBackground(void)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_x2000000))
    {
        LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
        LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
        LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
    {
        LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(VRAM + 0x8000));
        LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(VRAM + 0xD000));
        LoadCompressedPalette(gBattleTerrainPalette_Groudon, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE)
    {
        LZDecompressVram(gBattleTerrainTiles_Water, (void*)(VRAM + 0x8000));
        LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(VRAM + 0xD000));
        LoadCompressedPalette(gBattleTerrainPalette_Kyogre, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RAYQUAZA)
    {
        LZDecompressVram(gBattleTerrainTiles_Rayquaza, (void*)(VRAM + 0x8000));
        LZDecompressVram(gBattleTerrainTilemap_Rayquaza, (void*)(VRAM + 0xD000));
        LoadCompressedPalette(gBattleTerrainPalette_Rayquaza, 0x20, 0x60);
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
                LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
                LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, 0x20, 0x60);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                LoadCompressedPalette(gBattleTerrainPalette_StadiumWallace, 0x20, 0x60);
                return;
            }
        }

        switch (GetCurrentMapBattleScene())
        {
        default:
        case MAP_BATTLE_SCENE_NORMAL:
            LZDecompressVram(gBattleTerrainTable[gBattleTerrain].tileset, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTable[gBattleTerrain].tilemap, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainTable[gBattleTerrain].palette, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_GYM:
            LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_MAGMA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_AQUA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_SIDNEY:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_PHOEBE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_GLACIA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_DRAKE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_FRONTIER:
            LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
            break;
        }
    }
}

void LoadBattleTextboxAndBackground(void)
{
    LZDecompressVram(gBattleTextboxTiles, (void*)(VRAM));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
    CopyBgTilemapBufferToVram(0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x40);
    ApplyPlayerChosenFrameToBattleMenu();

    DrawMainBattleBackground();
}

static void sub_8035AE4(u8 taskId, u8 bank, u8 bgId, u8 destX, u8 destY)
{
    s32 i;
    u16 var = 0;
    u16 src[6];

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gTasks[taskId].data[5] != 0)
        {
            switch (bank)
            {
            case 0:
                var = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                var = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            case 2:
                var = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                var = 0x3F & gTasks[taskId].data[4];
                break;
            }
        }
        else
        {
            switch (bank)
            {
            case 0:
                var = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                var = 0x3F & gTasks[taskId].data[4];
                break;
            case 2:
                var = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                var = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            }
        }

        for (i = 0; i < 3; i++)
        {
            src[i] = ((var & (3 << (i * 2))) >> (i * 2)) + 0x6001;
        }

        CopyToBgTilemapBufferRect_ChangePalette(bgId, src, destX, destY, 3, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
    else
    {
        if (bank == gBattleScripting.multiplayerId)
            var = gTasks[taskId].data[3];
        else
            var = gTasks[taskId].data[4];

        for (i = 0; i < 6; i++)
        {
            src[i] = ((var & (3 << (i * 2))) >> (i * 2)) + 0x6001;
        }

        CopyToBgTilemapBufferRect_ChangePalette(bgId, src, destX, destY, 6, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
}

static void sub_8035C4C(void)
{
    if (gBattleOutcome == B_OUTCOME_DREW)
    {
        BattleHandleAddTextPrinter(gText_Draw, 0x15);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleOutcome == B_OUTCOME_WON)
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].lp_field_18)
            {
            case 0:
                BattleHandleAddTextPrinter(gText_Win, 0x16);
                BattleHandleAddTextPrinter(gText_Loss, 0x17);
                break;
            case 1:
                BattleHandleAddTextPrinter(gText_Win, 0x17);
                BattleHandleAddTextPrinter(gText_Loss, 0x16);
                break;
            case 2:
                BattleHandleAddTextPrinter(gText_Win, 0x16);
                BattleHandleAddTextPrinter(gText_Loss, 0x17);
                break;
            case 3:
                BattleHandleAddTextPrinter(gText_Win, 0x17);
                BattleHandleAddTextPrinter(gText_Loss, 0x16);
                break;
            }
        }
        else
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].lp_field_18)
            {
            case 0:
                BattleHandleAddTextPrinter(gText_Win, 0x17);
                BattleHandleAddTextPrinter(gText_Loss, 0x16);
                break;
            case 1:
                BattleHandleAddTextPrinter(gText_Win, 0x16);
                BattleHandleAddTextPrinter(gText_Loss, 0x17);
                break;
            case 2:
                BattleHandleAddTextPrinter(gText_Win, 0x17);
                BattleHandleAddTextPrinter(gText_Loss, 0x16);
                break;
            case 3:
                BattleHandleAddTextPrinter(gText_Win, 0x16);
                BattleHandleAddTextPrinter(gText_Loss, 0x17);
                break;
            }
        }
    }
    else if (gBattleOutcome == B_OUTCOME_WON)
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].lp_field_18 != 0)
        {
            BattleHandleAddTextPrinter(gText_Win, 0x17);
            BattleHandleAddTextPrinter(gText_Loss, 0x16);
        }
        else
        {
            BattleHandleAddTextPrinter(gText_Win, 0x16);
            BattleHandleAddTextPrinter(gText_Loss, 0x17);
        }
    }
    else
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].lp_field_18 != 0)
        {
            BattleHandleAddTextPrinter(gText_Win, 0x16);
            BattleHandleAddTextPrinter(gText_Loss, 0x17);
        }
        else
        {
            BattleHandleAddTextPrinter(gText_Win, 0x17);
            BattleHandleAddTextPrinter(gText_Loss, 0x16);
        }
    }
}

void sub_8035D74(u8 taskId)
{
    struct LinkPlayer *linkPlayer;
    u8 *name;
    s32 i, palId;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                name = gLinkPlayers[i].name;
                linkPlayer = &gLinkPlayers[i];

                switch (linkPlayer->lp_field_18)
                {
                case 0:
                    BattleHandleAddTextPrinter(name, 0x11);
                    sub_8035AE4(taskId, linkPlayer->lp_field_18, 1, 2, 4);
                    break;
                case 1:
                    BattleHandleAddTextPrinter(name, 0x12);
                    sub_8035AE4(taskId, linkPlayer->lp_field_18, 2, 2, 4);
                    break;
                case 2:
                    BattleHandleAddTextPrinter(name, 0x13);
                    sub_8035AE4(taskId, linkPlayer->lp_field_18, 1, 2, 8);
                    break;
                case 3:
                    BattleHandleAddTextPrinter(name, 0x14);
                    sub_8035AE4(taskId, linkPlayer->lp_field_18, 2, 2, 8);
                    break;
                }
            }
        }
        else
        {
            u8 playerId = gBattleScripting.multiplayerId;
            u8 opponentId = playerId ^ BIT_SIDE;
            u8 opponentId_copy = opponentId;

            if (gLinkPlayers[playerId].lp_field_18 != 0)
                opponentId = playerId, playerId = opponentId_copy;

            name = gLinkPlayers[playerId].name;
            BattleHandleAddTextPrinter(name, 0xF);

            name = gLinkPlayers[opponentId].name;
            BattleHandleAddTextPrinter(name, 0x10);

            sub_8035AE4(taskId, playerId, 1, 2, 7);
            sub_8035AE4(taskId, opponentId, 2, 2, 7);
        }
        gTasks[taskId].data[0]++;
        break;
    case 1:
        palId = AllocSpritePalette(0x2710);
        gPlttBufferUnfaded[palId * 16 + 0x10F] = gPlttBufferFaded[palId * 16 + 0x10F] = 0x7FFF;
        gBattleStruct->field_7D = CreateSprite(&gUnknown_0831A9D0, 111, 80, 0);
        gBattleStruct->field_7E = CreateSprite(&gUnknown_0831A9E8, 129, 80, 0);
        gSprites[gBattleStruct->field_7D].invisible = 1;
        gSprites[gBattleStruct->field_7E].invisible = 1;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (gTasks[taskId].data[5] != 0)
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG1_Y = -36;
            gBattle_BG2_Y = -36;
        }
        else
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG1_Y = (Cos2(gTasks[taskId].data[1]) / 32) - 164;
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG2_Y = (Cos2(gTasks[taskId].data[2]) / 32) - 164;
        }

        if (gTasks[taskId].data[2] != 0)
        {
            gTasks[taskId].data[2] -= 2;
            gTasks[taskId].data[1] += 2;
        }
        else
        {
            if (gTasks[taskId].data[5] != 0)
                sub_8035C4C();

            PlaySE(SE_W231);
            DestroyTask(taskId);
            gSprites[gBattleStruct->field_7D].invisible = 0;
            gSprites[gBattleStruct->field_7E].invisible = 0;
            gSprites[gBattleStruct->field_7E].oam.tileNum += 0x40;
            gSprites[gBattleStruct->field_7D].data[0] = 0;
            gSprites[gBattleStruct->field_7E].data[0] = 1;
            gSprites[gBattleStruct->field_7D].data[1] = gSprites[gBattleStruct->field_7D].pos1.x;
            gSprites[gBattleStruct->field_7E].data[1] = gSprites[gBattleStruct->field_7E].pos1.x;
            gSprites[gBattleStruct->field_7D].data[2] = 0;
            gSprites[gBattleStruct->field_7E].data[2] = 0;
        }
        break;
    }
}

void LoadBattleEntryBackground(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        LZDecompressVram(gUnknown_08D778F0, (void*)(VRAM + 0x4000));
        LZDecompressVram(gUnknown_08D77B0C, (void*)(VRAM + 0x10000));
        LoadCompressedPalette(gUnknown_08D77AE4, 0x60, 0x20);
        SetBgAttribute(1, BG_CTRL_ATTR_MAPBASEINDEX, 1);
        SetGpuReg(REG_OFFSET_BG1CNT, 0x5C04);
        CopyToBgTilemapBuffer(1, gUnknown_08D779D8, 0, 0);
        CopyToBgTilemapBuffer(2, gUnknown_08D779D8, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        SetGpuReg(REG_OFFSET_WININ, 0x36);
        SetGpuReg(REG_OFFSET_WINOUT, 0x36);
        gBattle_BG1_Y = 0xFF5C;
        gBattle_BG2_Y = 0xFF5C;
        LoadCompressedObjectPicUsingHeap(&gUnknown_0831AA00);
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_EREADER_TRAINER))
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) || gPartnerTrainerId == STEVEN_PARTNER_ID)
        {
            LZDecompressVram(gBattleTerrainAnimTiles_Building, (void*)(VRAM + 0x4000));
            LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void*)(VRAM + 0xE000));
        }
        else
        {
            SetBgAttribute(1, BG_CTRL_ATTR_VISIBLE, 2);
            SetBgAttribute(2, BG_CTRL_ATTR_VISIBLE, 2);
            CopyToBgTilemapBuffer(1, gUnknown_08D857A8, 0, 0);
            CopyToBgTilemapBuffer(2, gUnknown_08D85A1C, 0, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
    {
        LZDecompressVram(gBattleTerrainAnimTiles_Cave, (void*)(VRAM + 0x4000));
        LZDecompressVram(gBattleTerrainAnimTilemap_Cave, (void*)(VRAM + 0xE000));
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE)
    {
        LZDecompressVram(gBattleTerrainAnimTiles_Underwater, (void*)(VRAM + 0x4000));
        LZDecompressVram(gBattleTerrainAnimTilemap_Underwater, (void*)(VRAM + 0xE000));
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RAYQUAZA)
    {
        LZDecompressVram(gBattleTerrainAnimTiles_Rayquaza, (void*)(VRAM + 0x4000));
        LZDecompressVram(gBattleTerrainAnimTilemap_Rayquaza, (void*)(VRAM + 0xE000));
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void*)(VRAM + 0x4000));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void*)(VRAM + 0xE000));
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void*)(VRAM + 0x4000));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void*)(VRAM + 0xE000));
                return;
            }
        }

        if (GetCurrentMapBattleScene() == MAP_BATTLE_SCENE_NORMAL)
        {
            LZDecompressVram(gBattleTerrainTable[gBattleTerrain].entryTileset, (void*)(VRAM + 0x4000));
            LZDecompressVram(gBattleTerrainTable[gBattleTerrain].entryTilemap, (void*)(VRAM + 0xE000));
        }
        else
        {
            LZDecompressVram(gBattleTerrainAnimTiles_Building, (void*)(VRAM + 0x4000));
            LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void*)(VRAM + 0xE000));
        }
    }
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;

    switch (caseId)
    {
    case 0:
        LZDecompressVram(gBattleTextboxTiles, (void*)(VRAM));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadCompressedPalette(gBattleTextboxPalette, 0, 0x40);
        break;
    case 3:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_EREADER_TRAINER))
        {
            LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
        {
            LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(VRAM + 0x8000));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressVram(gBattleTerrainTable[gBattleTerrain].tileset, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
                break;
            }
        }
        break;
    case 4:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_EREADER_TRAINER))
        {
            LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        {
            if (gGameVersion == VERSION_RUBY)
                LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(VRAM + 0xD000));
            else
                LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(VRAM + 0xD000));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressVram(gBattleTerrainTable[gBattleTerrain].tilemap, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
                break;
            }
        }
        break;
    case 5:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000 | BATTLE_TYPE_EREADER_TRAINER))
        {
            LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        {
            if (gGameVersion == VERSION_RUBY)
                LoadCompressedPalette(gBattleTerrainPalette_Groudon, 0x20, 0x60);
            else
                LoadCompressedPalette(gBattleTerrainPalette_Kyogre, 0x20, 0x60);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, 0x20, 0x60);
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LoadCompressedPalette(gBattleTerrainPalette_StadiumWallace, 0x20, 0x60);
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LoadCompressedPalette(gBattleTerrainTable[gBattleTerrain].palette, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_GYM:
                LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
                break;
            }
        }
        break;
    case 6:
        ApplyPlayerChosenFrameToBattleMenu();
        break;
    default:
        ret = TRUE;
        break;
    }

    return ret;
}
