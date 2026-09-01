#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "data.h"
#include "constants/pokemon_icon.h"

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);

const struct SpritePalette gMonIconPaletteTable[] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

u8 CreateMonIcon(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality)
{
    return CreateMonIconIsEgg(species, callback, x, y, subpriority, personality, FALSE);
}

u8 CreateMonIconIsEgg(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 isEgg)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtrIsEgg(species, personality, isEgg),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gSpeciesInfo[species].iconPalIndex,
    };
    species = SanitizeSpeciesId(species);

    if (isEgg)
    {
        if (gSpeciesInfo[species].eggId != EGG_ID_NONE)
            iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG + gEggDatas[gSpeciesInfo[species].eggId].eggIconPalIndex;
        else
            iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG + gSpeciesInfo[SPECIES_EGG].iconPalIndex;
    }
    else if (species > NUM_SPECIES)
    {
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;
    }
#if P_GENDER_DIFFERENCES
    else if (gSpeciesInfo[species].iconSpriteFemale != NULL && IsPersonalityFemale(species, personality))
    {
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG + gSpeciesInfo[species].iconPalIndexFemale;
    }
#endif

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}


u8 CreateMonIconNoPersonality(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    return CreateMonIconNoPersonalityIsEgg(species, callback, x, y, subpriority, FALSE);
}
u8 CreateMonIconNoPersonalityIsEgg(enum Species species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 isEgg)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gSpeciesInfo[species].iconPalIndex,
    };

    iconTemplate.image = GetMonIconTilesIsEgg(species, 0, isEgg);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 CreateTaggedMonIcon(u32 tileTag, u32 paletteTag, enum Species species)
{
    struct SpritePalette palette;
    palette.data = gMonIconPaletteTable[gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex].data;
    palette.tag = paletteTag;
    LoadSpritePalette(&palette);

    struct SpriteSheet spriteSheet;
    spriteSheet.data = GetMonIconTilesIsEgg(species, 0, FALSE);
    spriteSheet.size = 2 * sSpriteImageSizes[sMonIconOamData.shape][sMonIconOamData.size];
    spriteSheet.tag = tileTag;
    LoadSpriteSheet(&spriteSheet);

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = tileTag,
        .paletteTag = paletteTag,
        .oam = &sMonIconOamData,
        .anims = sMonIconAnims,
        .images = NULL,
        .affineAnims = sMonIconAffineAnims
    };

    u8 spriteId = CreateSprite(&spriteTemplate, 0, 0, 0);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    UpdateMonIconFrame(&gSprites[spriteId]);
    return spriteId;
}

enum Species GetIconSpecies(enum Species species, u32 personality)
{
    species = SanitizeSpeciesId(species);
    if (species == SPECIES_UNOWN)
        species = GetUnownSpeciesId(personality);
    return species;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    if (!personality)
        return 0;
    else
        return GET_UNOWN_LETTER(personality);
}

enum Species GetIconSpeciesNoPersonality(enum Species species)
{
    species = SanitizeSpeciesId(species);

    if (MailSpeciesToSpecies(species, &species) == SPECIES_UNOWN)
        return species += SPECIES_UNOWN_B; // TODO
    return GetIconSpecies(species, 0);
}

const u8 *GetMonIconPtr(enum Species species, u32 personality)
{
    return GetMonIconPtrIsEgg(species, personality, FALSE);
}

const u8 *GetMonIconPtrIsEgg(enum Species species, u32 personality, bool32 isEgg)
{
    return GetMonIconTilesIsEgg(GetIconSpecies(species, personality), personality, isEgg);
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

void LoadMonIconPalette(enum Species species)
{
    u8 palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalettePersonality(enum Species species, u32 personality)
{
    u8 palIndex;
    species = SanitizeSpeciesId(species);
#if P_GENDER_DIFFERENCES
    if (gSpeciesInfo[species].iconSpriteFemale != NULL && IsPersonalityFemale(species, personality))
        palIndex = gSpeciesInfo[species].iconPalIndexFemale;
    else
#endif
        palIndex = gSpeciesInfo[species].iconPalIndex;
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(enum Species species)
{
    u8 palIndex;
    palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(enum Species species)
{
    u8 palIndex;
    palIndex = gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void SpriteCB_MonIcon(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8 *GetMonIconTiles(enum Species species, u32 personality)
{
    return GetMonIconTilesIsEgg(species, personality, FALSE);
}

const u8 *GetMonIconTilesIsEgg(enum Species species, u32 personality, bool32 isEgg)
{
    const u8 *iconSprite;

    if (species > NUM_SPECIES)
        species = SPECIES_NONE;

    if (isEgg)
    {
        if (gSpeciesInfo[species].eggId != EGG_ID_NONE)
            iconSprite = gEggDatas[gSpeciesInfo[species].eggId].eggIcon;
        else
            iconSprite = gSpeciesInfo[SPECIES_EGG].iconSprite;
    }
    else
    {
#if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].iconSpriteFemale != NULL && IsPersonalityFemale(species, personality))
            iconSprite = gSpeciesInfo[species].iconSpriteFemale;
        else
#endif
        if (gSpeciesInfo[species].iconSprite != NULL)
            iconSprite = gSpeciesInfo[species].iconSprite;
        else
            iconSprite = gSpeciesInfo[SPECIES_NONE].iconSprite;
    }

    return iconSprite;
}

const u8 *GetMonIconTilesByIconType(enum Species species, enum SpeciesIconType iconType)
{
    if (iconType == EGG_ICON)
        return gEggDatas[gSpeciesInfo[species].eggId].eggIcon;
    if (iconType == FEMALE_ICON)
        return gSpeciesInfo[species].iconSpriteFemale;
    return gSpeciesInfo[species].iconSprite;
}

void TryLoadAllMonIconPalettesAtOffset(u16 offset)
{
    s32 i;
    if (offset <= BG_PLTT_ID(16 - ARRAY_COUNT(gMonIconPaletteTable)))
    {
        for (i = 0; i < (int)ARRAY_COUNT(gMonIconPaletteTable); i++)
        {
            LoadPalette(gMonIconPaletteTable[i].data, offset, PLTT_SIZE_4BPP);
            offset += 16;
        }
    }
}

u8 GetValidMonIconPalIndex(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
}

u8 GetMonIconPaletteIndexFromSpecies(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex;
}

const u16 *GetValidMonIconPalettePtr(enum Species species)
{
    return gMonIconPaletteTable[gSpeciesInfo[SanitizeSpeciesId(species)].iconPalIndex].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            if (sprite->usingSheet)
            {
                sprite->oam.tileNum = sprite->sheetTileStart + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame / TILE_SIZE_4BPP);
            }
            else
            {
                RequestSpriteCopy(
                    // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                    // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                    // arithmetic can be performed.
                    (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                    (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                    sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            }
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
