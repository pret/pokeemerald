#include "global.h"
#include "field_ground_effect.h"
#include "field_map_obj.h"
#include "field_effect.h"
#include "map_obj_8097404.h"
#include "malloc.h"
#include "task.h"
#include "util.h"

extern void sub_8097D68(struct Sprite *sprite);
extern void sub_8097FE4(u8);

typedef void (*SpriteStepFunc)(struct Sprite *sprite, u8 dir);

extern const struct Coords16 gUnknown_0850DB7C[4];
extern s16 gUnknown_0850E768[];
extern SpriteStepFunc *const gUnknown_0850E754[];
extern const s8 gUnknown_0850E772[];
extern const s8 gUnknown_0850E7BA[];
extern const s8 *const gUnknown_0850E834[];
extern s16 gUnknown_0850E840[];
extern u8 gUnknown_0850E846[];
extern s16 gUnknown_0850E84A[];
extern u8 gUnknown_0850E850[];

bool8 FreezeMapObject(struct MapObject *mapObject)
{
    if (mapObject->mapobj_bit_6 || mapObject->mapobj_bit_8)
    {
        return TRUE;
    }
    else
    {
        mapObject->mapobj_bit_8 = 1;
        mapObject->mapobj_bit_23 = gSprites[mapObject->spriteId].animPaused;
        mapObject->mapobj_bit_24 = gSprites[mapObject->spriteId].affineAnimPaused;
        gSprites[mapObject->spriteId].animPaused = 1;
        gSprites[mapObject->spriteId].affineAnimPaused = 1;
        return FALSE;
    }
}

void FreezeMapObjects(void)
{
    u8 i;
    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
        if (gMapObjects[i].active && i != gPlayerAvatar.mapObjectId)
            FreezeMapObject(&gMapObjects[i]);
}

void FreezeMapObjectsExceptOne(u8 a1)
{
    u8 i;
    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
        if (i != a1 && gMapObjects[i].active && i != gPlayerAvatar.mapObjectId)
            FreezeMapObject(&gMapObjects[i]);
}

void npc_sync_anim_pause_bits(struct MapObject *mapObject)
{
    if (mapObject->active && mapObject->mapobj_bit_8)
    {
        mapObject->mapobj_bit_8 = 0;
        gSprites[mapObject->spriteId].animPaused = mapObject->mapobj_bit_23;
        gSprites[mapObject->spriteId].affineAnimPaused = mapObject->mapobj_bit_24;
    }
}

void UnfreezeMapObjects(void)
{
    u8 i;
    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
        if (gMapObjects[i].active)
            npc_sync_anim_pause_bits(&gMapObjects[i]);
}

void little_step(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += gUnknown_0850DB7C[dir].x;
    sprite->pos1.y += gUnknown_0850DB7C[dir].y;
}

void double_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) gUnknown_0850DB7C[dir].x;
    sprite->pos1.y += 2 * (u16) gUnknown_0850DB7C[dir].y;
}

void triple_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) gUnknown_0850DB7C[dir].x + (u16) gUnknown_0850DB7C[dir].x;
    sprite->pos1.y += 2 * (u16) gUnknown_0850DB7C[dir].y + (u16) gUnknown_0850DB7C[dir].y;
}

void quad_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 4 * (u16) gUnknown_0850DB7C[dir].x;
    sprite->pos1.y += 4 * (u16) gUnknown_0850DB7C[dir].y;
}

void oct_little_steps(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 8 * (u16) gUnknown_0850DB7C[dir].x;
    sprite->pos1.y += 8 * (u16) gUnknown_0850DB7C[dir].y;
}

void oamt_npc_ministep_reset(struct Sprite *sprite, u8 a2, u8 a3)
{
    sprite->data[3] = a2;
    sprite->data[4] = a3;
    sprite->data[5] = 0;
}

bool8 obj_npc_ministep(struct Sprite *sprite)
{
    if (sprite->data[5] >= gUnknown_0850E768[sprite->data[4]])
        return FALSE;

    gUnknown_0850E754[sprite->data[4]][sprite->data[5]](sprite, sprite->data[3]);

    sprite->data[5]++;

    if (sprite->data[5] < gUnknown_0850E768[sprite->data[4]])
        return FALSE;

    return TRUE;
}

void sub_80976DC(struct Sprite *sprite, u8 a2)
{
    sprite->data[3] = a2;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

bool8 sub_80976EC(struct Sprite *sprite)
{
    if (!(sprite->data[4] & 1))
    {
        little_step(sprite, sprite->data[3]);
        sprite->data[5]++;
    }

    sprite->data[4]++;

    if (sprite->data[5] > 15)
        return TRUE;
    else
        return FALSE;
}

// new helper added here in the middle. Perhaps Game Freak kept these organized in alphebetical order or some other heirarchy?

s16 sub_8097728(s16 a1)
{
    return gUnknown_0850E7BA[a1];
}

s16 sub_809773C(s16 a1)
{
    return gUnknown_0850E772[a1];
}

void sub_8097750(struct Sprite *sprite)
{
    sprite->data[6] = 0;
    sprite->data[7] = 0;
}

bool8 sub_8097758(struct Sprite *sprite)
{
    bool8 result = FALSE;

    switch(sprite->data[7])
    {
        case 0:
            sprite->pos2.x += sub_809773C(sprite->data[6]);
            sprite->pos2.y += sub_8097728(sprite->data[6]);
            break;
        case 1:
            sprite->pos2.x -= sub_809773C(0x47 - sprite->data[6]);
            sprite->pos2.y += sub_8097728(0x47 - sprite->data[6]);
            break;
        case 2:
            sprite->pos2.x -= sub_809773C(sprite->data[6]);
            sprite->pos2.y += sub_8097728(sprite->data[6]);
            break;
        case 3:
            sprite->pos2.x += sub_809773C(0x47 - sprite->data[6]);
            sprite->pos2.y += sub_8097728(0x47 - sprite->data[6]);
            break;
    }
    if(++sprite->data[6] == 0x48)
    {
        sprite->data[6] = 0;
        sprite->data[7]++;
    }
    if(sprite->data[7] == 0x4)
    {
        sprite->pos2.y = 0;
        sprite->pos2.x = 0;
        result = TRUE;
    }
    return result;
}

s16 sub_8097820(s16 a1, u8 a2)
{
    return gUnknown_0850E834[a2][a1];
}

void sub_809783C(struct Sprite *sprite, u8 a2, u8 a3, u8 a4)
{
    sprite->data[3] = a2;
    sprite->data[4] = a3;
    sprite->data[5] = a4;
    sprite->data[6] = 0;
}

u8 sub_809785C(struct Sprite *sprite)
{
    s16 v5[3];
    u8 v6[3];
    u8 v2;

    memcpy(v5, gUnknown_0850E840, 6); // TODO: get rid of memcpy
    memcpy(v6, gUnknown_0850E846, 3);
    v2 = 0;

    if (sprite->data[4])
        little_step(sprite, sprite->data[3]);

    sprite->pos2.y = sub_8097820(sprite->data[6] >> v6[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == (v5[sprite->data[4]] >> 1))
        v2 = 1;

    if (sprite->data[6] >= v5[sprite->data[4]])
    {
        sprite->pos2.y = 0;
        v2 = -1;
    }

    return v2;
}

u8 sub_80978E4(struct Sprite *sprite)
{
    s16 v5[3];
    u8 v6[3];
    u8 v2;

    memcpy(v5, gUnknown_0850E84A, 6);
    memcpy(v6, gUnknown_0850E850, 3);
    v2 = 0;

    if (sprite->data[4] && !(sprite->data[6] & 1))
        little_step(sprite, sprite->data[3]);

    sprite->pos2.y = sub_8097820(sprite->data[6] >> v6[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == (v5[sprite->data[4]] >> 1))
        v2 = 1;

    if (sprite->data[6] >= v5[sprite->data[4]])
    {
        sprite->pos2.y = 0;
        v2 = -1;
    }

    return v2;
}

void SetFieldObjectStepTimer(struct Sprite *sprite, u16 timer)
{
    sprite->data[3] = timer;
}


bool8 RunFieldObjectStepTimer(struct Sprite *sprite)
{
    sprite->data[3]--;

    if (sprite->data[3] == 0)
        return TRUE;
    else
        return FALSE;
}

void obj_anim_image_set_and_seek(struct Sprite *sprite, u8 a2, u8 a3)
{
    sprite->animNum = a2;
    sprite->animPaused = 0 ;
    SeekSpriteAnim(sprite, a3);
}

bool8 sub_80979BC(struct Sprite *sprite)
{
    if (sprite->animEnded)
        return TRUE;
    else
        return FALSE;
}

void sub_80979D4(struct Sprite *sprite, bool8 invisible)
{
    u16 x, y;
    s16 x2, y2;

    sprite->invisible = invisible;

    if (sprite->coordOffsetEnabled)
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    }
    else
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    }

    x2 = x - (sprite->centerToCornerVecX >> 1);
    y2 = y - (sprite->centerToCornerVecY >> 1);

    if ((s16)x > 255 || x2 < -16)
        sprite->invisible = 1;
    if ((s16)y > 175 || y2 < -16)
        sprite->invisible = 1;
}

void sub_8097AC8(struct Sprite *sprite)
{
    sub_8097D68(sprite);
    SetObjectSubpriorityByZCoord(sprite->data[1], sprite, 1);
    sub_80979D4(sprite, sprite->data[2]);
}

void sub_8097AF0(void)
{
    int i;

    for(i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == sub_8097AC8)
            DestroySprite(sprite);
    }
}

int sub_8097B2C(u8 var) // this should return a u8, because all that call this shifts to u8, but it wont match because it doesnt shift u8 at the end.
{
    int i;

    for(i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == sub_8097AC8 && (u8)sprite->data[0] == var)
            return i;
    }
    return MAX_SPRITES;
}

void sub_8097B78(u8 var1, u8 var2)
{
    u8 spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
        StartSpriteAnim(&gSprites[spriteId], FieldObjectDirectionToImageAnimId(var2));
}

void sub_8097BB4(u8 var1, u8 var2)
{
    int spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        const struct MapObjectGraphicsInfo *gfxInfo = GetFieldObjectGraphicsInfo(var2);
        u16 tileNum = sprite->oam.tileNum;

        sprite->oam = *gfxInfo->oam;
        sprite->oam.tileNum = tileNum;
        sprite->oam.paletteNum = gfxInfo->paletteSlot;
        sprite->images = gfxInfo->images;

        if(gfxInfo->subspriteTables == NULL)
        {
            sprite->subspriteTables = NULL;
            sprite->subspriteTableNum = 0;
            sprite->subspriteMode = 0;
        }
        else
        {
            SetSubspriteTables(sprite, gfxInfo->subspriteTables);
            sprite->subspriteMode = 2;
        }
        StartSpriteAnim(sprite, 0);
    }
}

void sub_8097C44(u8 var, bool32 var2)
{
    u8 spriteId = sub_8097B2C(var);

    if(spriteId == MAX_SPRITES)
        return;

    if(var2)
        gSprites[spriteId].data[2] = 1;
    else
        gSprites[spriteId].data[2] = 0;
}

bool32 sub_8097C8C(u8 var)
{
    u8 spriteId = sub_8097B2C(var);

    if(spriteId == MAX_SPRITES)
        return FALSE;

    return (gSprites[spriteId].data[2] == TRUE);
}

void sub_8097CC4(u8 var1, u8 var2)
{
    u8 spriteId = sub_8097B2C(var1);

    if(spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[3] = var2;
        gSprites[spriteId].data[4] = 0;
    }
}

void sub_8097CF4(struct Sprite *sprite)
{
    switch(sprite->data[4])
    {
        case 0:
            sprite->pos2.y = 0;
            sprite->data[4]++;
        case 1:
            sprite->pos2.y -= 8;
            if(sprite->pos2.y == -160)
            {
                sprite->pos2.y = 0;
                sprite->data[2] = 1;
                sprite->data[3] = 0;
                sprite->data[4] = 0;
            }
    }
}

void sub_8097D30(struct Sprite *sprite)
{
    switch(sprite->data[4])
    {
        case 0:
            sprite->pos2.y = -160;
            sprite->data[4]++;
        case 1:
            sprite->pos2.y += 8;
            if(sprite->pos2.y == 0)
            {
                sprite->data[3] = 0;
                sprite->data[4] = 0;
            }
    }
}

void sub_8097D68(struct Sprite *sprite)
{
    switch(sprite->data[3])
    {
        case 1:
            sub_8097D30(sprite);
            break;
        case 2:
            sub_8097CF4(sprite);
            break;
        case 0:
            break;
        default:
            sprite->data[3] = 0;
            break;
    }
}

bool32 sub_8097D9C(u8 var)
{
    u8 spriteId = sub_8097B2C(var);

    if(spriteId == MAX_SPRITES)
        return FALSE;

    if(gSprites[spriteId].data[3] != FALSE)
        return TRUE;

    return FALSE;
}

u32 oe_exec_and_other_stuff(u8 fieldEffectId, struct MapObject *mapObject)
{
    FieldObjectGetLocalIdAndMap(mapObject, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    return FieldEffectStart(fieldEffectId);
}

void DoShadowFieldEffect(struct MapObject *mapObject)
{
    if (!mapObject->mapobj_bit_22)
    {
        mapObject->mapobj_bit_22 = 1;
        oe_exec_and_other_stuff(FLDEFF_SHADOW, mapObject);
    }
}

void DoRippleFieldEffect(struct MapObject *mapObject, struct Sprite *sprite)
{
    const struct MapObjectGraphicsInfo *gfxInfo = GetFieldObjectGraphicsInfo(mapObject->graphicsId);
    gFieldEffectArguments[0] = sprite->pos1.x;
    gFieldEffectArguments[1] = sprite->pos1.y + (gfxInfo->height >> 1) - 2;
    gFieldEffectArguments[2] = 151;
    gFieldEffectArguments[3] = 3;
    FieldEffectStart(FLDEFF_RIPPLE);
}

#ifdef NONMATCHING
bool32 sub_8097E50(struct MapObject *mapObject, struct Sprite *sprite)
{
    bool32 ableToStore = FALSE;
    if (gUnknown_020375B8 == NULL)
    {
        gUnknown_020375B8 = AllocZeroed(0x14);
        gUnknown_020375B8[0] = mapObject->localId;
        gUnknown_020375B8[16] = 1;
        ableToStore = TRUE;
    }
    else
    {
        u8 i;
        u8 firstFreeSlot;
        bool32 found;
        for (firstFreeSlot = 16, found = FALSE, i = 0; i < 16; i++)
        {
            if (firstFreeSlot == 16 && gUnknown_020375B8[i] == 0)
                firstFreeSlot = i;
            
            if (gUnknown_020375B8[i] == mapObject->localId)
            {
                found = TRUE;
                break;
            }
        }
        
        if (!found && firstFreeSlot != 16)
        {
            gUnknown_020375B8[firstFreeSlot] = mapObject->localId;
            gUnknown_020375B8[16]++;
            ableToStore = TRUE; // the nonmatching problem is that ableToStore == TRUE isnt being merged with the above ableToStore = TRUE assignment.
        }
    }
    
    if (ableToStore == TRUE)
    {
        mapObject->mapobj_bit_12 = TRUE;
        mapObject->mapobj_bit_9 = TRUE;
    }
    
    sprite->data[2] = 1;
    return TRUE;
}
#else
__attribute__((naked))
bool32 sub_8097E50(struct MapObject *mapObject, struct Sprite *sprite)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    adds r4, r0, 0\n\
    mov r8, r1\n\
    movs r0, 0\n\
    mov r12, r0\n\
    ldr r0, =gUnknown_020375B8\n\
    ldr r1, [r0]\n\
    adds r6, r0, 0\n\
    cmp r1, 0\n\
    bne _08097E80\n\
    movs r0, 0x14\n\
    bl AllocZeroed\n\
    str r0, [r6]\n\
    ldrb r1, [r4, 0x8]\n\
    strb r1, [r0]\n\
    ldr r1, [r6]\n\
    movs r0, 0x1\n\
    strb r0, [r1, 0x10]\n\
    b _08097ECC\n\
    .pool\n\
_08097E80:\n\
    movs r2, 0x10\n\
    movs r5, 0\n\
    movs r1, 0\n\
    adds r3, r6, 0\n\
    b _08097E90\n\
_08097E8A:\n\
    adds r0, r1, 0x1\n\
    lsls r0, 24\n\
    lsrs r1, r0, 24\n\
_08097E90:\n\
    cmp r1, 0xF\n\
    bhi _08097EB2\n\
    cmp r2, 0x10\n\
    bne _08097EA4\n\
    ldr r0, [r3]\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    cmp r0, 0\n\
    bne _08097EA4\n\
    adds r2, r1, 0\n\
_08097EA4:\n\
    ldr r0, [r3]\n\
    adds r0, r1\n\
    ldrb r0, [r0]\n\
    ldrb r7, [r4, 0x8]\n\
    cmp r0, r7\n\
    bne _08097E8A\n\
    movs r5, 0x1\n\
_08097EB2:\n\
    cmp r5, 0\n\
    bne _08097ECE\n\
    cmp r2, 0x10\n\
    beq _08097ECE\n\
    ldr r0, [r6]\n\
    adds r0, r2\n\
    ldrb r1, [r4, 0x8]\n\
    strb r1, [r0]\n\
    ldr r1, [r6]\n\
    ldrb r0, [r1, 0x10]\n\
    adds r0, 0x1\n\
    strb r0, [r1, 0x10]\n\
    movs r0, 0x1\n\
_08097ECC:\n\
    mov r12, r0\n\
_08097ECE:\n\
    mov r1, r12\n\
    cmp r1, 0x1\n\
    bne _08097EE0\n\
    ldrb r0, [r4, 0x1]\n\
    movs r1, 0x10\n\
    orrs r0, r1\n\
    movs r1, 0x2\n\
    orrs r0, r1\n\
    strb r0, [r4, 0x1]\n\
_08097EE0:\n\
    movs r0, 0x1\n\
    mov r7, r8\n\
    strh r0, [r7, 0x32]\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .syntax divided");
}
#endif

// this function is very similar to the above one and I don't want to decompile this one until the above is matching.
__attribute__((naked))
bool32 sub_8097EF0(struct MapObject *mapObject, struct Sprite *sprite)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    adds r6, r0, 0\n\
    mov r8, r1\n\
    movs r0, 0x1\n\
    strh r0, [r1, 0x32]\n\
    ldr r5, =gUnknown_020375B8\n\
    ldr r0, [r5]\n\
    cmp r0, 0\n\
    beq _08097F68\n\
    movs r7, 0\n\
    adds r0, r6, 0\n\
    bl sub_8097F78\n\
    lsls r0, 24\n\
    lsrs r1, r0, 24\n\
    cmp r1, 0x10\n\
    beq _08097F28\n\
    ldr r0, [r5]\n\
    adds r0, r1\n\
    movs r1, 0\n\
    strb r1, [r0]\n\
    ldr r1, [r5]\n\
    ldrb r0, [r1, 0x10]\n\
    subs r0, 0x1\n\
    strb r0, [r1, 0x10]\n\
    movs r7, 0x1\n\
_08097F28:\n\
    ldr r0, [r5]\n\
    ldrb r4, [r0, 0x10]\n\
    cmp r4, 0\n\
    bne _08097F36\n\
    bl Free\n\
    str r4, [r5]\n\
_08097F36:\n\
    cmp r7, 0x1\n\
    bne _08097F68\n\
    ldrb r0, [r6, 0x5]\n\
    bl GetFieldObjectGraphicsInfo\n\
    ldrb r1, [r0, 0xC]\n\
    lsls r1, 25\n\
    lsrs r1, 31\n\
    lsls r1, 4\n\
    ldrb r2, [r6, 0x1]\n\
    movs r0, 0x11\n\
    negs r0, r0\n\
    ands r0, r2\n\
    orrs r0, r1\n\
    movs r1, 0x3\n\
    negs r1, r1\n\
    ands r0, r1\n\
    strb r0, [r6, 0x1]\n\
    mov r2, r8\n\
    adds r2, 0x2C\n\
    ldrb r1, [r2]\n\
    movs r0, 0x41\n\
    negs r0, r0\n\
    ands r0, r1\n\
    strb r0, [r2]\n\
_08097F68:\n\
    movs r0, 0x1\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .pool\n\
    .syntax divided");
}

u8 sub_8097F78(struct MapObject *mapObject)
{
    u8 i;

    for(i = 0; i < MAP_OBJECTS_COUNT; i++)
    {
        if(gUnknown_020375B8[i] == mapObject->localId)
            return i;
    }
    return MAP_OBJECTS_COUNT;
}

void sub_8097FA4(struct MapObject *mapObject)
{
    u8 taskId = CreateTask(sub_8097FE4, 0xFF);
    struct Task *task = &gTasks[taskId];

    StoreWordInTwoHalfwords(&task->data[0], (u32)mapObject);
    mapObject->mapobj_unk_1B = taskId;
    task->data[3] = 0xFFFF;
}

void sub_8097FE4(u8 taskId)
{
    struct MapObject *mapObject;
    struct Sprite *sprite;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&mapObject); // load the map object pointer.
    sprite = &gSprites[mapObject->spriteId];

    if(!(task->data[2] & 0x3))
        sprite->pos2.y += task->data[3];

    if(!(task->data[2] & 0xF))
        task->data[3] = -task->data[3];

    task->data[2]++;
}

void sub_8098044(u8 taskId)
{
    u32 word;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], &word); // huh??? why does it load a word that never gets used???
    DestroyTask(taskId);
}

void sub_8098074(u8 var1, u8 var2)
{
    u8 i;

    for(i = 0; i < MAP_OBJECTS_COUNT; i++)
    {
        if(i != var1 && i != var2 &&
            gMapObjects[i].active && i != gPlayerAvatar.mapObjectId)
                FreezeMapObject(&gMapObjects[i]);
    }
}

bool32 sub_80980C0(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y = 0;
    sprite->data[2]++;
    return FALSE;
}

bool32 sub_80980D0(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y -= 8;

    if(sprite->pos2.y == -160)
        sprite->data[2]++;
    return FALSE;
}

bool32 sub_80980F4(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y = -160;
    sprite->data[2]++;
    return FALSE;
}

bool32 sub_8098108(struct MapObject *mapObject, struct Sprite *sprite)
{
    sprite->pos2.y += 8;

    if(!sprite->pos2.y)
        sprite->data[2]++;
    return FALSE;
}

// though this function returns TRUE without doing anything, this header is required due to being in an array of functions which needs it.
bool32 sub_8098124(struct MapObject *mapObject, struct Sprite *sprite)
{
    return TRUE;
}
