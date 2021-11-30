//Credits: Gamer2020, AsparagusEduardo
#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "data.h"
#include "decompress.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "item.h"
#include "item_icon.h"
#include "list_menu.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_animation.h"
#include "pokemon_debug.h"
#include "pokemon_icon.h"
#include "reset_rtc_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_pokemon_sprites.h"

#include "constants/items.h"

//Defines
#define DEBUG_MON_X 140
#define DEBUG_MON_Y 14
#define DEBUG_MON_BACK_X 32
#define DEBUG_MON_BACK_Y 50
#define DEBUG_ICON_X 158
#define DEBUG_ICON_Y 90
#define DEBUG_MON_SHINY 0
#define DEBUG_MON_NORMAL 9

#define MODIFY_DIGITS_MAX 4
#define MODIFY_DIGITS_ARROW_X 22
#define MODIFY_DIGITS_ARROW1_Y 12
#define MODIFY_DIGITS_ARROW2_Y 36

#define GENDER_MALE 0
#define GENDER_FEMALE 1
#define MON_PIC_BACK 0
#define MON_PIC_FRONT 1

static const u16 sBgColor[] = {RGB_WHITE};

//Structs
struct PokemonDebugModifyArrows
{
    u8 arrowSpriteId[2];
    u16 minValue;
    u16 maxValue;
    int currValue;
    u8 currentDigit;
    u8 maxDigits;
    u8 charDigits[MODIFY_DIGITS_MAX];
    void *modifiedValPtr;
    u8 typeOfVal;
};

struct PokemonDebugMenu
{
    u16 currentmonId;
    u8 currentmonWindowId;
    u8 InstructionsWindowId;
    u8 frontspriteId;
    u8 backspriteId;
    u8 iconspriteId;
    bool8 isShiny;
    bool8 isFemale;
    struct PokemonDebugModifyArrows modifyArrows;
    u8 modifyWindowId;
    u8 messageBoxWindowId;
};

//WindowTemplates
/*
static const struct WindowTemplate sCurrentTitleTemplate =
{
    .bg = 0,
    .tilemapLeft =1,
    .tilemapTop = 0,
    .width = 14,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x200
};
*/

static const struct WindowTemplate sDebugPokemonInstructionsTemplate =
{
    .bg = 0,
    .tilemapLeft =1,
    .tilemapTop = 207,
    .width = 22,
    .height = 8,
    .paletteNum = 0xF,
    .baseBlock = 0x300
};

static const struct WindowTemplate sModifyWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 14,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x200
};

static const struct WindowTemplate sPokemonDebugMsgBoxWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 3,
    .tilemapTop = 14,
    .width = 11,
    .height = 1,
    .paletteNum = 0xF,
    .baseBlock = 0x100
};

//Function declarations
static void PrintDigitChars(struct PokemonDebugMenu *data);
static void SetUpModifyArrows(struct PokemonDebugMenu *data);
static void UpdateBattlerValue(struct PokemonDebugMenu *data);
static void ValueToCharDigits(u8 *charDigits, u32 newValue, u8 maxDigits);
static bool32 TryMoveDigit(struct PokemonDebugModifyArrows *modArrows, bool32 moveUp);
static void CB2_Debug_Runner(void);
static void ResetBGs_Debug_Menu(u16);
static void Handle_Input_Debug_Pokemon(u8);
static void ReloadPokemonSprites(struct PokemonDebugMenu *data);
static void Exit_Debug_Pokemon(u8);

static struct PokemonDebugMenu *GetStructPtr(u8 taskId)
{
    u8 *taskDataPtr = (u8*)(&gTasks[taskId].data[0]);

    return (struct PokemonDebugMenu*)(T1_READ_PTR(taskDataPtr));
}

//Text handling functions
static void PadString(const u8 *src, u8 *dst)
{
    u32 i;

    for (i = 0; i < 17 && src[i] != EOS; i++)
        dst[i] = src[i];

    for (; i < 17; i++)
        dst[i] = CHAR_SPACE;

    dst[i] = EOS;
}

/*
static void PrintOnCurrentMonWindow(u8 windowId, u16 monId)
{
    u8 text[POKEMON_NAME_LENGTH + 10];

    text[0] = CHAR_0 + monId / 100;
    text[1] = CHAR_0 + (monId % 100) / 10;
    text[2] = CHAR_0 + (monId % 100) % 10;
    text[3] = CHAR_SPACE;
    text[4] = CHAR_HYPHEN;
    text[5] = CHAR_SPACE;

    StringCopy(&text[6], gSpeciesNames[monId]);

    FillWindowPixelBuffer(windowId, 0x11);
    AddTextPrinterParameterized(windowId, 1, text, 0, 0, 0, NULL);
    CopyWindowToVram(windowId, 3);
}
*/

static void PrintInstructionsOnWindow(u8 windowId, struct PokemonDebugMenu *data)
{
    u8 text[] = _("A - Shiny  START - Cry\nL - Back  R - Front$");
    u8 textGender[] = _("A - Shiny  START - Cry\nL - Back  R - Front SEL - Gender$");
    u16 species = data->modifyArrows.currValue;
    

    FillWindowPixelBuffer(windowId, 0x11);
    if (SpeciesHasGenderDifference[species])
        AddTextPrinterParameterized(windowId, 1, textGender, 0, 0, 0, NULL);
    else
        AddTextPrinterParameterized(windowId, 1, text, 0, 0, 0, NULL);
    CopyWindowToVram(windowId, 3);
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void SetStructPtr(u8 taskId, void *ptr)
{
    u32 structPtr = (u32)(ptr);
    u8 *taskDataPtr = (u8*)(&gTasks[taskId].data[0]);

    taskDataPtr[0] = structPtr >> 0;
    taskDataPtr[1] = structPtr >> 8;
    taskDataPtr[2] = structPtr >> 16;
    taskDataPtr[3] = structPtr >> 24;
}

//Digit and arrow functions
#define VAL_U16     0
static void PrintDigitChars(struct PokemonDebugMenu *data)
{
    s32 i;
    u16 species = data->modifyArrows.currValue;
    u8 text[MODIFY_DIGITS_MAX + POKEMON_NAME_LENGTH + 8];

    for (i = 0; i < data->modifyArrows.maxDigits; i++)
        text[i] = data->modifyArrows.charDigits[i];
    
    text[i++] = CHAR_SPACE;
    text[i++] = CHAR_HYPHEN;

    if (SpeciesHasGenderDifference[species])
    {
        if (data->isFemale)
            text[i++] = CHAR_FEMALE;
        else
            text[i++] = CHAR_MALE;   
        text[i++] = CHAR_HYPHEN;
    }

    text[i++] = CHAR_SPACE;
    StringCopy(&text[i], gSpeciesNames[species]);

    FillWindowPixelBuffer(data->modifyWindowId, 0x11);
    AddTextPrinterParameterized(data->modifyWindowId, 1, text, 3, 0, 0, NULL);
}

static u32 CharDigitsToValue(u8 *charDigits, u8 maxDigits)
{
    s32 i;
    u8 id = 0;
    u32 newValue = 0;
    u8 valueDigits[MODIFY_DIGITS_MAX];

    for (i = 0; i < MODIFY_DIGITS_MAX; i++)
        valueDigits[i] = charDigits[i] - CHAR_0;

    if (maxDigits >= MODIFY_DIGITS_MAX)
        newValue += valueDigits[id++] * 1000;
    if (maxDigits >= MODIFY_DIGITS_MAX - 1)
        newValue += valueDigits[id++] * 100;
    if (maxDigits >= MODIFY_DIGITS_MAX - 2)
        newValue += valueDigits[id++] * 10;
    if (maxDigits >= MODIFY_DIGITS_MAX - 3)
        newValue += valueDigits[id++];

    return newValue;
}

static void ValueToCharDigits(u8 *charDigits, u32 newValue, u8 maxDigits)
{
    s32 i;
    u8 valueDigits[MODIFY_DIGITS_MAX];
    u8 id = 0;

    if (maxDigits >= MODIFY_DIGITS_MAX)
        valueDigits[id++] = newValue / 1000;
    if (maxDigits >= MODIFY_DIGITS_MAX - 1)
        valueDigits[id++] = (newValue % 1000) / 100;
    if (maxDigits >= MODIFY_DIGITS_MAX - 2)
        valueDigits[id++] = (newValue % 100) / 10;
    if (maxDigits >= MODIFY_DIGITS_MAX - 3)
        valueDigits[id++] = newValue % 10;

    for (i = 0; i < MODIFY_DIGITS_MAX; i++)
        charDigits[i] = valueDigits[i] + CHAR_0;
}

static void SetUpModifyArrows(struct PokemonDebugMenu *data)
{
    LoadSpritePalette(&sSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X, MODIFY_DIGITS_ARROW1_Y, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X, MODIFY_DIGITS_ARROW2_Y, 0);
    gSprites[data->modifyArrows.arrowSpriteId[1]].animNum = 1;

    data->modifyArrows.minValue = 1;
    data->modifyArrows.maxValue = NUM_SPECIES - 1;
    data->modifyArrows.maxDigits = 4;
    data->modifyArrows.modifiedValPtr = &data->currentmonId;
    data->modifyArrows.typeOfVal = VAL_U16;
    data->modifyArrows.currValue = data->currentmonId;

    data->modifyArrows.currentDigit = 0;
    ValueToCharDigits(data->modifyArrows.charDigits, data->modifyArrows.currValue, data->modifyArrows.maxDigits);
}

static bool32 TryMoveDigit(struct PokemonDebugModifyArrows *modArrows, bool32 moveUp)
{
    s32 i;
    u8 charDigits[MODIFY_DIGITS_MAX];
    u32 newValue;

    for (i = 0; i < MODIFY_DIGITS_MAX; i++)
        charDigits[i] = modArrows->charDigits[i];

    if (moveUp)
    {
        if (charDigits[modArrows->currentDigit] == CHAR_9)
        {
            charDigits[modArrows->currentDigit] = CHAR_0;
            for (i = modArrows->currentDigit - 1; i >= 0; i--)
            {
                if (charDigits[i] == CHAR_9)
                    charDigits[i] = CHAR_0;
                else
                {
                    charDigits[i]++;
                    break;
                }
            }
        }
        else
            charDigits[modArrows->currentDigit]++;
    }
    else
    {
        if (charDigits[modArrows->currentDigit] == CHAR_0)
        {
            charDigits[modArrows->currentDigit] = CHAR_9;
            
            for (i = modArrows->currentDigit - 1; i >= 0; i--)
            {
                if (charDigits[i] == CHAR_0)
                    charDigits[i] = CHAR_9;
                else
                {
                    charDigits[i]--;
                    break;
                }
            }
        }

        else
            charDigits[modArrows->currentDigit]--;
    }

    newValue = CharDigitsToValue(charDigits, modArrows->maxDigits);
    if (newValue > modArrows->maxValue || newValue < modArrows->minValue)
    {
        return FALSE;
    }
    else
    {
        modArrows->currValue = newValue;
        for (i = 0; i < MODIFY_DIGITS_MAX; i++)
             modArrows->charDigits[i] = charDigits[i];
        return TRUE;
    }
}

static void UpdateBattlerValue(struct PokemonDebugMenu *data)
{
    u32 i;
    switch (data->modifyArrows.typeOfVal)
    {
    case VAL_U16:
        *(u16*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    }
}

//Sprite functions
static const struct CompressedSpritePalette *GetMonSpritePalStructCustom(u16 species, bool8 isFemale, bool8 isShiny)
{
    if (isShiny)
    {
        if (SpeciesHasGenderDifference[species] && isFemale)
            return &gMonShinyPaletteTableFemale[species];
        else
            return &gMonShinyPaletteTable[species];
    }
    else
    {
        if (SpeciesHasGenderDifference[species] && isFemale)
            return &gMonPaletteTableFemale[species];
        else
            return &gMonPaletteTable[species];
    }
}

/*
// One entry for each of the four Castform forms.
extern const struct MonCoords gCastformFrontSpriteCoords[];
static const u8 sCastformElevations[] =
{
    13, // NORMAL
    14, // SUN
    13, // RAIN
    13, // HAIL
};
// Const rom data
static const struct UCoords8 sBattlerCoords[][4] =
{
    {
        { 72, 80 },
        { 176, 40 },
        { 48, 40 },
        { 112, 80 },
    },
    {
        { 32, 80 },
        { 200, 40 },
        { 90, 88 },
        { 152, 32 },
    },
};
static u8 GetBattlerYDeltaCustom(u8 pic_type, u16 species)
{
    u32 personality;
    u8 ret;
    u16 coordSpecies;

    if (pic_type == MON_PIC_BACK)
    {
        if (species == SPECIES_UNOWN)
        {
            //coordSpecies = GetUnownSpeciesId(personality);
            //ret = gMonBackPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
            ret = 0; //sCastformBackSpriteYCoords[0]]; //all of them are 0???
        else if (species > NUM_SPECIES)
            ret = gMonBackPicCoords[0].y_offset;
        else
            ret = gMonBackPicCoords[species].y_offset;
    }
    else
    {
        if (species == SPECIES_UNOWN)
        {
            //coordSpecies = GetUnownSpeciesId(personality);
            //ret = gMonFrontPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
            ret = gCastformFrontSpriteCoords[0].y_offset;
        else if (species > NUM_SPECIES)
            ret = gMonFrontPicCoords[0].y_offset;
        else
            ret = gMonFrontPicCoords[species].y_offset;
    }
    return ret;
}
static u8 GetBattlerElevationCustom(u8 pic_type, u16 species)
{
    u8 ret = 0;
    if (pic_type == MON_PIC_FRONT)
    {
        if (species == SPECIES_CASTFORM)
            ret = sCastformElevations[0];
        else if (species > NUM_SPECIES)
            ret = gEnemyMonElevation[0];
        else
            ret = gEnemyMonElevation[species];
    }
    return ret;
}
u8 GetBattlerSpriteFinal_YCustom(u8 pic_type, u16 species, bool8 a3)
{
    u16 offset;
    u8 y;

    if (pic_type == MON_PIC_BACK)
        offset = GetBattlerYDeltaCustom(pic_type, species);
    else
    {
        offset = GetBattlerYDeltaCustom(pic_type, species);
        offset -= GetBattlerElevationCustom(pic_type, species);
    }
    y = offset + sBattlerCoords[0][pic_type].y;
    if (a3)
    {
        if (pic_type == MON_PIC_BACK)
            y += 8;
        if (y > 104)
            y = 104;
    }
    return y;
}
static u8 GetBattlerSpriteCoordCustom(u16 species, u8 pic_type, u8 coordType)
{
    u8 retVal;

    switch (coordType)
    {
    case BATTLER_COORD_X:
    case BATTLER_COORD_X_2:
        retVal = sBattlerCoords[0][pic_type].x;
        break;
    case BATTLER_COORD_Y:
        retVal = sBattlerCoords[0][pic_type].y;
        break;
    case BATTLER_COORD_Y_PIC_OFFSET:
        retVal = GetBattlerSpriteFinal_YCustom(pic_type, species, TRUE);
        break;
    case BATTLER_COORD_Y_PIC_OFFSET_DEFAULT: 
        retVal = GetBattlerSpriteFinal_YCustom(pic_type, species, FALSE);
        break;
    }

    return retVal;
}
static s16 GetBattlerSpriteCoordAttrCustom(u16 species, u8 pic_type, u8 attr, bool8 transformSpecies)
{
    u32 personality;
    int ret = 0;
    const struct MonCoords *coords;


    if (pic_type == MON_PIC_BACK)
    {
        if (!transformSpecies)
            //personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
        else
            //personality = gTransformedPersonalities[battlerId];
        
        if (species == SPECIES_UNOWN)
        {
            //species = GetUnownSpeciesId(personality);
            coords = &gMonBackPicCoords[species];
        }
        else if (species > NUM_SPECIES)
            coords = &gMonBackPicCoords[0];
        else
            coords = &gMonBackPicCoords[species];
    }
    else
    {
        if (!transformSpecies)
            //personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PERSONALITY);
        else
            //personality = gTransformedPersonalities[battlerId];
        
        if (species == SPECIES_UNOWN)
        {
            //species = GetUnownSpeciesId(personality);
            coords = &gMonFrontPicCoords[species];
        }
        else if (species == SPECIES_CASTFORM)
            coords = &gCastformFrontSpriteCoords[0];
        else if (species > NUM_SPECIES)
            coords = &gMonFrontPicCoords[0];
        else
            coords = &gMonFrontPicCoords[species];
    }


    switch (attr)
    {
    case BATTLER_COORD_ATTR_HEIGHT:
        return (coords->size & 0xf) * 8;
    case BATTLER_COORD_ATTR_WIDTH:
        return (coords->size >> 4) * 8;
    case BATTLER_COORD_ATTR_LEFT:
        return GetBattlerSpriteCoordCustom(species, pic_type, BATTLER_COORD_X_2) - ((coords->size >> 4) * 4);
    case BATTLER_COORD_ATTR_RIGHT:
        return GetBattlerSpriteCoordCustom(species, pic_type, BATTLER_COORD_X_2) + ((coords->size >> 4) * 4);
    case BATTLER_COORD_ATTR_TOP:
        return GetBattlerSpriteCoordCustom(species, pic_type, BATTLER_COORD_Y_PIC_OFFSET) - ((coords->size & 0xf) * 4);
    case BATTLER_COORD_ATTR_BOTTOM:
        return GetBattlerSpriteCoordCustom(species, pic_type, BATTLER_COORD_Y_PIC_OFFSET) + ((coords->size & 0xf) * 4);
    case BATTLER_COORD_ATTR_RAW_BOTTOM:
        ret = GetBattlerSpriteCoordCustom(species, pic_type, BATTLER_COORD_Y) + 31;
        return ret - coords->y_offset;
    default:
        return 0;
    }

}
*/

// *******************************
// Main functions
void CB2_Debug_Pokemon(void)
{
    u8 taskId;
    const struct CompressedSpritePalette *palette;
    struct PokemonDebugMenu *data;
    s16 offset_x, offset_y;
    u16 species;

    switch (gMain.state)
    {
        case 0:
        default:
            SetVBlankCallback(NULL);
            FreeMonSpritesGfx();
            ResetBGs_Debug_Menu(0);
            DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000)
            DmaClear32(3, OAM, OAM_SIZE);
            DmaClear16(3, PLTT, PLTT_SIZE);
            gMain.state = 1;
            break;
        case 1:
            ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetPaletteFade();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 8;
            ResetAllPicSprites();
            gMain.state++;
            break;
        case 2:
            AllocateMonSpritesGfx();

            LoadPalette(sBgColor, 0, 2);
            LoadMonIconPalettes();
            //LoadPalette(GetOverworldTextboxPalettePtr(), 0xf0, 16);

            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(1);

            //input task handler
            taskId = CreateTask(Handle_Input_Debug_Pokemon, 0);

            data = AllocZeroed(sizeof(struct PokemonDebugMenu));
            SetStructPtr(taskId, data);

            data->currentmonId = 1;
            species = data->currentmonId;
            /*
            data->currentmonWindowId = AddWindow(&sCurrentTitleTemplate);
            PutWindowTilemap(data->currentmonWindowId);
            PrintOnCurrentMonWindow(data->currentmonWindowId, data->currentmonId);
            */

            data->InstructionsWindowId = AddWindow(&sDebugPokemonInstructionsTemplate);
            PutWindowTilemap(data->InstructionsWindowId);
            PrintInstructionsOnWindow(data->InstructionsWindowId, data);

            HandleLoadSpecialPokePicCustom(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[1], species, 0, data->isFemale);
            data->isShiny = FALSE;
            data->isFemale = FALSE;
            palette = GetMonSpritePalStructCustom(species, data->isFemale, data->isShiny);
            LoadCompressedSpritePalette(palette);
            SetMultiuseSpriteTemplateToPokemon(species, 1);
            gMultiuseSpriteTemplate.paletteTag = palette->tag;
            data->frontspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_X + 32, DEBUG_MON_Y + 40, 0);
            gSprites[data->frontspriteId].callback = SpriteCallbackDummy;
            gSprites[data->frontspriteId].oam.priority = 0;

            HandleLoadSpecialPokePicCustom(&gMonBackPicTable[species], gMonSpritesGfxPtr->sprites.ptr[2], species, 0, data->isFemale);
            palette = GetMonSpritePalStructCustom(species, data->isFemale, data->isShiny);
            LoadCompressedSpritePalette(palette);
            SetMultiuseSpriteTemplateToPokemon(species, 2);
            gMultiuseSpriteTemplate.paletteTag = palette->tag;
            //offset_y = GetBattlerSpriteCoordAttrCustom(species, MON_PIC_BACK, BATTLER_COORD_ATTR_BOTTOM, FALSE);
            offset_y = gMonBackPicCoords[species].y_offset;
            data->backspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_BACK_X + 32, DEBUG_MON_BACK_Y + 30 + offset_y, 0);
            gSprites[data->backspriteId].callback = SpriteCallbackDummy;
            gSprites[data->backspriteId].oam.priority = 0;

            //Icon Sprite
            data->iconspriteId = CreateMonIconCustom(species, SpriteCB_MonIcon, DEBUG_ICON_X + 32, DEBUG_ICON_Y + 40, 4, data->isShiny, data->isFemale, data->isShiny);
            gSprites[data->iconspriteId].oam.priority = 0;

            //Modify Arrows
            data->modifyWindowId = AddWindow(&sModifyWindowTemplate);
            PutWindowTilemap(data->modifyWindowId);
            CopyWindowToVram(data->modifyWindowId, 3);
            SetUpModifyArrows(data);
            PrintDigitChars(data);

            //MessageBox line
            data->messageBoxWindowId = AddWindow(&sPokemonDebugMsgBoxWindowTemplate);
            PutWindowTilemap(data->messageBoxWindowId);
            CopyWindowToVram(data->messageBoxWindowId, 3);
            FillWindowPixelRect(data->messageBoxWindowId, PIXEL_FILL(0x2), 0, 0, 90, 4);

            gMain.state++;
            break;
        case 3:
            EnableInterrupts(1);
            SetVBlankCallback(VBlankCB);
            SetMainCallback2(CB2_Debug_Runner);
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
            break;
    }
}

static void CB2_Debug_Runner(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void ResetBGs_Debug_Menu(u16 a)
{
    if (!(a & DISPCNT_BG0_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    }
    if (!(a & DISPCNT_BG1_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG1_ON);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    }
    if (!(a & DISPCNT_BG2_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    }
    if (!(a & DISPCNT_BG3_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    }
    if (!(a & DISPCNT_OBJ_ON))
    {
        ClearGpuRegBits(0, DISPCNT_OBJ_ON);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
    }
}

static void Handle_Input_Debug_Pokemon(u8 taskId)
{
    struct PokemonDebugMenu *data = GetStructPtr(taskId);
    struct Sprite *Frontsprite = &gSprites[data->frontspriteId];
    struct Sprite *Backsprite = &gSprites[data->backspriteId];

    if (JOY_NEW(L_BUTTON))
    {
        LaunchAnimationTaskForBackSprite(Backsprite, GetSpeciesBackAnimSet(data->currentmonId));
    }
    else if (JOY_NEW(R_BUTTON))
    {
        if (HasTwoFramesAnimation(data->currentmonId))
            StartSpriteAnim(Frontsprite, 1);
        BattleAnimateFrontSprite(Frontsprite, data->currentmonId, TRUE, 1);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        data->isShiny = !data->isShiny;
        
        if(data->isShiny)
            PlaySE(SE_SHINY);

        ReloadPokemonSprites(data);

    }
    else if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Exit_Debug_Pokemon;
        PlaySE(SE_PC_OFF);
    }
    else if (JOY_NEW(START_BUTTON))
    {
        PlayCryInternal(data->currentmonId, 0, 120, 10, 0);
    }
    else if (JOY_NEW(SELECT_BUTTON) && SpeciesHasGenderDifference[data->currentmonId])
    {
        data->isFemale = !data->isFemale;
        PrintDigitChars(data);
        UpdateBattlerValue(data);
        ReloadPokemonSprites(data);
        while (!(gMain.intrCheck & INTR_FLAG_VBLANK));
    }
    else if (JOY_NEW(DPAD_DOWN)) // || gMain.heldKeys & DPAD_DOWN)
    {
        if (TryMoveDigit(&data->modifyArrows, FALSE))
        {
            data->isFemale = FALSE;
            PrintDigitChars(data);
            UpdateBattlerValue(data);
            ReloadPokemonSprites(data);
        }

        PlaySE(SE_DEX_SCROLL);

        while (!(gMain.intrCheck & INTR_FLAG_VBLANK));
    }
    else if (JOY_NEW(DPAD_UP)) // || gMain.heldKeys & DPAD_UP)
    {
        if (TryMoveDigit(&data->modifyArrows, TRUE))
        {
            data->isFemale = FALSE;
            PrintDigitChars(data);
            UpdateBattlerValue(data);
            ReloadPokemonSprites(data);
        }

        PlaySE(SE_DEX_SCROLL);

    }
    else if (JOY_NEW(DPAD_LEFT)) // || gMain.heldKeys & DPAD_LEFT)
    {
        if (data->modifyArrows.currentDigit != 0)
        {
            data->modifyArrows.currentDigit--;
            gSprites[data->modifyArrows.arrowSpriteId[0]].x2 -= 6;
            gSprites[data->modifyArrows.arrowSpriteId[1]].x2 -= 6;
        }
    }
    else if (JOY_NEW(DPAD_RIGHT)) // || gMain.heldKeys & DPAD_RIGHT)
    {
        if (data->modifyArrows.currentDigit != (data->modifyArrows.maxDigits - 1))
        {
            data->modifyArrows.currentDigit++;
            gSprites[data->modifyArrows.arrowSpriteId[0]].x2 += 6;
            gSprites[data->modifyArrows.arrowSpriteId[1]].x2 += 6;
        }
    }
}

static void ReloadPokemonSprites(struct PokemonDebugMenu *data)
{
    s16 offset_x = 0; 
    s16 offset_y = 0;
    u16 species = data->currentmonId;
    const struct CompressedSpritePalette *palette;

    DestroySprite(&gSprites[data->frontspriteId]);
    DestroySprite(&gSprites[data->backspriteId]);
    DestroySprite(&gSprites[data->iconspriteId]);

    FreeMonSpritesGfx();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AllocateMonSpritesGfx();

    FreeAllSpritePalettes();
    FreeMonIconPalettes();

    LoadMonIconPalettes();

    PrintInstructionsOnWindow(data->InstructionsWindowId, data);

    HandleLoadSpecialPokePicCustom(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[1], species, 0, data->isFemale);
    palette = GetMonSpritePalStructCustom(species, data->isFemale, data->isShiny);
    LoadCompressedSpritePalette(palette);
    SetMultiuseSpriteTemplateToPokemon(species, 1);
    gMultiuseSpriteTemplate.paletteTag = palette->tag;
    data->frontspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_X + 32, DEBUG_MON_Y + 40, 0);
    gSprites[data->frontspriteId].callback = SpriteCallbackDummy;
    gSprites[data->frontspriteId].oam.priority = 0;
    
    HandleLoadSpecialPokePicCustom(&gMonBackPicTable[species], gMonSpritesGfxPtr->sprites.ptr[2], species, 0, data->isFemale);
    palette = GetMonSpritePalStructCustom(species, data->isFemale, data->isShiny);
    LoadCompressedSpritePalette(palette);
    SetMultiuseSpriteTemplateToPokemon(species, 2);
    gMultiuseSpriteTemplate.paletteTag = palette->tag;
    //offset_y = GetBattlerSpriteCoordAttrCustom(species, MON_PIC_BACK, BATTLER_COORD_ATTR_BOTTOM, FALSE);
    offset_y = gMonBackPicCoords[species].y_offset;
    data->backspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_BACK_X + 32, DEBUG_MON_BACK_Y + 30 + offset_y, 0);
    gSprites[data->backspriteId].callback = SpriteCallbackDummy;
    gSprites[data->backspriteId].oam.priority = 0;

    //Icon Sprite
    data->iconspriteId = CreateMonIconCustom(species, SpriteCB_MonIcon, DEBUG_ICON_X + 32, DEBUG_ICON_Y + 40, 4, data->isShiny, data->isFemale, data->isShiny);
    gSprites[data->iconspriteId].oam.priority = 0;
    
    //Modify Arrows
    LoadSpritePalette(&sSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X + (data->modifyArrows.currentDigit * 6), MODIFY_DIGITS_ARROW1_Y, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X + (data->modifyArrows.currentDigit * 6), MODIFY_DIGITS_ARROW2_Y, 0);
    gSprites[data->modifyArrows.arrowSpriteId[1]].animNum = 1;
}

static void Exit_Debug_Pokemon(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct PokemonDebugMenu *data = GetStructPtr(taskId);
        Free(data);
        FreeMonSpritesGfx();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToField);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
}
