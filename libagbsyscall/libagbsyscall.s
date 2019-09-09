	.include "../constants/gba_constants.inc"
	.include "../asm/macros/function.inc"

	.text

	.set SOFT_RESET_DIRECT_BUF, 0x03007FFA
	.set RESET_EX_WRAM_FLAG,           0x1

	.ifdef NO_GRANULAR_AGBSYSCALL
	.set L_IntrWait, 1
	.set L_RegisterRamReset, 1
	.set L_Sqrt, 1
	.set L_MusicPlayerOpen, 1
	.set L_SoundBiasReset, 1
	.set L_SoundDriverVSyncOn, 1
	.set L_Mod, 1
	.set L_VBlankIntrWait, 1
	.set L_MusicPlayerStart, 1
	.set L_SoundDriverVSyncOff, 1
	.set L_HuffUnComp, 1
	.set L_SoftResetExram, 1
	.set L_MusicPlayerFadeOut, 1
	.set L_LZ77UnCompWram, 1
	.set L_SoundDriverMain, 1
	.set L_SoundBiasChange, 1
	.set L_LZ77UnCompVram, 1
	.set L_ArcTan2, 1
	.set L_MusicPlayerStop, 1
	.set L_DivArm, 1
	.set L_ModArm, 1
	.set L_SoundDriverVSync, 1
	.set L_SoundDriverInit, 1
	.set L_BgAffineSet, 1
	.set L_Diff8bitUnFilterWram, 1
	.set L_MultiBoot, 1
	.set L_MidiKey2Freq, 1
	.set L_Div, 1
	.set L_Diff8bitUnFilterVram, 1
	.set L_ArcTan, 1
	.set L_ObjAffineSet, 1
	.set L_SoftResetRom, 1
	.set L_SoundDriverMode, 1
	.set L_RLUnCompWram, 1
	.set L_BitUnPack, 1
	.set L_SoundChannelClear, 1
	.set L_CpuFastSet, 1
	.set L_CpuSet, 1
	.set L_Diff16bitUnFilter, 1
	.set L_SoundBiasSet, 1
	.set L_MusicPlayerContinue, 1
	.set L_SoftReset, 1
	.set L_RLUnCompVram, 1
	.endif

	.ifdef L_IntrWait
	thumb_func_start IntrWait
IntrWait:
	mov r2, #0
	swi 4
	bx lr
	thumb_func_end IntrWait
	.endif

	.ifdef L_RegisterRamReset
	thumb_func_start RegisterRamReset
RegisterRamReset:
	swi 1
	bx lr
	thumb_func_end RegisterRamReset
	.endif

	.ifdef L_Sqrt
	thumb_func_start Sqrt
Sqrt:
	swi 8
	bx lr
	thumb_func_end Sqrt
	.endif

	.ifdef L_MusicPlayerOpen
	thumb_func_start MusicPlayerOpen
MusicPlayerOpen:
	swi 32
	bx lr
	thumb_func_end MusicPlayerOpen
	.endif

	.ifdef L_SoundBiasReset
	thumb_func_start SoundBiasReset
SoundBiasReset:
	mov r0, #0
	swi 25
	bx lr
	thumb_func_end SoundBiasReset
	.endif

	.ifdef L_SoundDriverVSyncOn
	thumb_func_start SoundDriverVSyncOn
SoundDriverVSyncOn:
	swi 41
	bx lr
	thumb_func_end SoundDriverVSyncOn
	.endif

	.ifdef L_Mod
	thumb_func_start Mod
Mod:
	swi 6
	mov r0, r1
	bx lr
	thumb_func_end Mod
	.endif

	.ifdef L_VBlankIntrWait
	thumb_func_start VBlankIntrWait
VBlankIntrWait:
	mov r2, #0
	swi 5
	bx lr
	thumb_func_end VBlankIntrWait
	.endif

	.ifdef L_MusicPlayerStart
	thumb_func_start MusicPlayerStart
MusicPlayerStart:
	swi 33
	bx lr
	thumb_func_end MusicPlayerStart
	.endif

	.ifdef L_SoundDriverVSyncOff
	thumb_func_start SoundDriverVSyncOff
SoundDriverVSyncOff:
	swi 40
	bx lr
	thumb_func_end SoundDriverVSyncOff
	.endif

	.ifdef L_HuffUnComp
	thumb_func_start HuffUnComp
HuffUnComp:
	swi 19
	bx lr
	thumb_func_end HuffUnComp
	.endif

	.ifdef L_SoftResetExram
	thumb_func_start SoftResetExram
SoftResetExram:
	ldr r3, =REG_IME
	mov r2, #0
	strb r2, [r3, #0]
	ldr r3, =SOFT_RESET_DIRECT_BUF
	mov r2, #1
	strb r2, [r3, #0]
	sub r3, #SOFT_RESET_DIRECT_BUF - 0x3007f00
	mov sp, r3
	mov r2, #RESET_EX_WRAM_FLAG
	bic r0, r2
	swi 1
	swi 0
	.pool
	thumb_func_end SoftResetExram
	.endif

	.ifdef L_MusicPlayerFadeOut
	thumb_func_start MusicPlayerFadeOut
MusicPlayerFadeOut:
	swi 36
	bx lr
	thumb_func_end MusicPlayerFadeOut
	.endif

	.ifdef L_LZ77UnCompWram
	thumb_func_start LZ77UnCompWram
LZ77UnCompWram:
	swi 17
	bx lr
	thumb_func_end LZ77UnCompWram
	.endif

	.ifdef L_SoundDriverMain
	thumb_func_start SoundDriverMain
SoundDriverMain:
	swi 28
	bx lr
	thumb_func_end SoundDriverMain
	.endif

	.ifdef L_SoundBiasChange
	thumb_func_start SoundBiasChange
SoundBiasChange:
	swi 25
	bx lr
	thumb_func_end SoundBiasChange
	.endif

	.ifdef L_LZ77UnCompVram
	thumb_func_start LZ77UnCompVram
LZ77UnCompVram:
	swi 18
	bx lr
	thumb_func_end LZ77UnCompVram
	.endif

	.ifdef L_ArcTan2
	thumb_func_start ArcTan2
ArcTan2:
	swi 10
	bx lr
	thumb_func_end ArcTan2
	.endif

	.ifdef L_MusicPlayerStop
	thumb_func_start MusicPlayerStop
MusicPlayerStop:
	swi 34
	bx lr
	thumb_func_end MusicPlayerStop
	.endif

	.ifdef L_DivArm
	thumb_func_start DivArm
DivArm:
	swi 7
	bx lr
	thumb_func_end DivArm
	.endif

	.ifdef L_ModArm
	thumb_func_start ModArm
ModArm:
	swi 7
	mov r0, r1
	bx lr
	thumb_func_end ModArm
	.endif

	.ifdef L_SoundDriverVSync
	thumb_func_start SoundDriverVSync
SoundDriverVSync:
	swi 29
	bx lr
	thumb_func_end SoundDriverVSync
	.endif

	.ifdef L_SoundDriverInit
	thumb_func_start SoundDriverInit
SoundDriverInit:
	swi 26
	bx lr
	thumb_func_end SoundDriverInit
	.endif

	.ifdef L_BgAffineSet
	thumb_func_start BgAffineSet
BgAffineSet:
	swi 14
	bx lr
	thumb_func_end BgAffineSet
	.endif

	.ifdef L_Diff8bitUnFilterWram
	thumb_func_start Diff8bitUnFilterWram
Diff8bitUnFilterWram:
	swi 22
	bx lr
	thumb_func_end Diff8bitUnFilterWram
	.endif

	.ifdef L_MultiBoot
	thumb_func_start MultiBoot
MultiBoot:
	mov r1, #1
	swi 37
	bx lr
	thumb_func_end MultiBoot
	.endif

	.ifdef L_MidiKey2Freq
	thumb_func_start MidiKey2Freq
MidiKey2Freq:
	swi 31
	bx lr
	thumb_func_end MidiKey2Freq
	.endif

	.ifdef L_Div
	thumb_func_start Div
Div:
	swi 6
	bx lr
	thumb_func_end Div
	.endif

	.ifdef L_Diff8bitUnFilterVram
	thumb_func_start Diff8bitUnFilterVram
Diff8bitUnFilterVram:
	swi 23
	bx lr
	thumb_func_end Diff8bitUnFilterVram
	.endif

	.ifdef L_ArcTan
	thumb_func_start ArcTan
ArcTan:
	swi 9
	bx lr
	thumb_func_end ArcTan
	.endif

	.ifdef L_ObjAffineSet
	thumb_func_start ObjAffineSet
ObjAffineSet:
	swi 15
	bx lr
	thumb_func_end ObjAffineSet
	.endif

	.ifdef L_SoftResetRom
	thumb_func_start SoftResetRom
SoftResetRom:
	ldr r3, =REG_IME
	mov r2, #0
	strb r2, [r3, #0]
	ldr r3, =SOFT_RESET_DIRECT_BUF
	mov r2, #0
	strb r2, [r3, #0]
	sub r3, #SOFT_RESET_DIRECT_BUF - 0x3007f00
	mov sp, r3
	swi 1
	swi 0
	.pool
	thumb_func_end SoftResetRom
	.endif

	.ifdef L_SoundDriverMode
	thumb_func_start SoundDriverMode
SoundDriverMode:
	swi 27
	bx lr
	thumb_func_end SoundDriverMode
	.endif

	.ifdef L_RLUnCompWram
	thumb_func_start RLUnCompWram
RLUnCompWram:
	swi 20
	bx lr
	thumb_func_end RLUnCompWram
	.endif

	.ifdef L_BitUnPack
	thumb_func_start BitUnPack
BitUnPack:
	swi 16
	bx lr
	thumb_func_end BitUnPack
	.endif

	.ifdef L_SoundChannelClear
	thumb_func_start SoundChannelClear
SoundChannelClear:
	swi 30
	bx lr
	thumb_func_end SoundChannelClear
	.endif

	.ifdef L_CpuFastSet
	thumb_func_start CpuFastSet
CpuFastSet:
	swi 12
	bx lr
	thumb_func_end CpuFastSet
	.endif

	.ifdef L_CpuSet
	thumb_func_start CpuSet
CpuSet:
	swi 11
	bx lr
	thumb_func_end CpuSet
	.endif

	.ifdef L_Diff16bitUnFilter
	thumb_func_start Diff16bitUnFilter
Diff16bitUnFilter:
	swi 24
	bx lr
	thumb_func_end Diff16bitUnFilter
	.endif

	.ifdef L_SoundBiasSet
	thumb_func_start SoundBiasSet
SoundBiasSet:
	mov r0, #1
	swi 25
	bx lr
	thumb_func_end SoundBiasSet
	.endif

	.ifdef L_MusicPlayerContinue
	thumb_func_start MusicPlayerContinue
MusicPlayerContinue:
	swi 35
	bx lr
	thumb_func_end MusicPlayerContinue
	.endif

	.ifdef L_SoftReset
	thumb_func_start SoftReset
SoftReset:
	ldr r3, =REG_IME
	mov r2, #0
	strb r2, [r3, #0]
	ldr r1, =0x3007f00
	mov sp, r1
	swi 1
	swi 0
	.pool
	thumb_func_end SoftReset
	.endif

	.ifdef L_RLUnCompVram
	thumb_func_start RLUnCompVram
RLUnCompVram:
	swi 21
	bx lr
	thumb_func_end RLUnCompVram
	.endif

	.align 2, 0 @ Don't pad with nop
