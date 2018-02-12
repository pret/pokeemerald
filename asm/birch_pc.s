	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ScriptGetPokedexInfo
ScriptGetPokedexInfo: @ 8137A4C
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _08137A70
	movs r0, 0
	bl sub_80C0844
	ldr r1, =gSpecialVar_0x8005
	strh r0, [r1]
	movs r0, 0x1
	bl sub_80C0844
	b _08137A80
	.pool
_08137A70:
	movs r0, 0
	bl pokedex_count
	ldr r1, =gSpecialVar_0x8005
	strh r0, [r1]
	movs r0, 0x1
	bl pokedex_count
_08137A80:
	ldr r1, =gSpecialVar_0x8006
	strh r0, [r1]
	bl IsNationalPokedexEnabled
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end ScriptGetPokedexInfo

	thumb_func_start GetPokedexRatingText
GetPokedexRatingText: @ 8137A98
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x9
	bhi _08137AA4
	b _08137BFC
_08137AA4:
	cmp r0, 0x13
	bhi _08137AB0
	ldr r0, =gUnknown_082A5DAB
	b _08137C06
	.pool
_08137AB0:
	cmp r0, 0x1D
	bhi _08137ABC
	ldr r0, =gUnknown_082A5DF1
	b _08137C06
	.pool
_08137ABC:
	cmp r0, 0x27
	bhi _08137AC8
	ldr r0, =gUnknown_082A5E34
	b _08137C06
	.pool
_08137AC8:
	cmp r0, 0x31
	bhi _08137AD4
	ldr r0, =gUnknown_082A5E83
	b _08137C06
	.pool
_08137AD4:
	cmp r0, 0x3B
	bhi _08137AE0
	ldr r0, =gUnknown_082A5EB9
	b _08137C06
	.pool
_08137AE0:
	cmp r0, 0x45
	bhi _08137AEC
	ldr r0, =gUnknown_082A5EF4
	b _08137C06
	.pool
_08137AEC:
	cmp r0, 0x4F
	bhi _08137AF8
	ldr r0, =gUnknown_082A5F39
	b _08137C06
	.pool
_08137AF8:
	cmp r0, 0x59
	bhi _08137B04
	ldr r0, =gUnknown_082A5F82
	b _08137C06
	.pool
_08137B04:
	cmp r0, 0x63
	bhi _08137B10
	ldr r0, =gUnknown_082A5FB9
	b _08137C06
	.pool
_08137B10:
	cmp r0, 0x6D
	bhi _08137B1C
	ldr r0, =gUnknown_082A6018
	b _08137C06
	.pool
_08137B1C:
	cmp r0, 0x77
	bhi _08137B28
	ldr r0, =gUnknown_082A6061
	b _08137C06
	.pool
_08137B28:
	cmp r0, 0x81
	bhi _08137B34
	ldr r0, =gUnknown_082A609C
	b _08137C06
	.pool
_08137B34:
	cmp r0, 0x8B
	bhi _08137B40
	ldr r0, =gUnknown_082A60D5
	b _08137C06
	.pool
_08137B40:
	cmp r0, 0x95
	bhi _08137B4C
	ldr r0, =gUnknown_082A6124
	b _08137C06
	.pool
_08137B4C:
	cmp r0, 0x9F
	bhi _08137B58
	ldr r0, =gUnknown_082A616F
	b _08137C06
	.pool
_08137B58:
	cmp r0, 0xA9
	bhi _08137B64
	ldr r0, =gUnknown_082A61D6
	b _08137C06
	.pool
_08137B64:
	cmp r0, 0xB3
	bhi _08137B70
	ldr r0, =gUnknown_082A623A
	b _08137C06
	.pool
_08137B70:
	cmp r0, 0xBD
	bhi _08137B7C
	ldr r0, =gUnknown_082A6287
	b _08137C06
	.pool
_08137B7C:
	cmp r0, 0xC7
	bls _08137BEA
	cmp r0, 0xC8
	bne _08137BB8
	ldr r0, =0x00000199
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	bne _08137BEA
	movs r0, 0xCD
	lsls r0, 1
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	bne _08137BEA
	b _08137C04
	.pool
_08137BB8:
	cmp r0, 0xC9
	bne _08137BF8
	ldr r0, =0x00000199
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _08137C04
	movs r0, 0xCD
	lsls r0, 1
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _08137C04
_08137BEA:
	ldr r0, =gUnknown_082A62C9
	b _08137C06
	.pool
_08137BF8:
	cmp r0, 0xCA
	beq _08137C04
_08137BFC:
	ldr r0, =gUnknown_082A5D6C
	b _08137C06
	.pool
_08137C04:
	ldr r0, =gUnknown_082A6312
_08137C06:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetPokedexRatingText

	thumb_func_start ShowPokedexRatingMessage
ShowPokedexRatingMessage: @ 8137C10
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl GetPokedexRatingText
	bl ShowFieldMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowPokedexRatingMessage
