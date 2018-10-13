@ commands

	.macro loadspritegfx param0
	.byte 0x0
	.2byte \param0
	.endm

	.macro unloadspritegfx param0
	.byte 0x1
	.2byte \param0
	.endm

	.macro createsprite template, priority, argv:vararg
	.byte 0x02
	.4byte \template
	.byte \priority
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	.macro createvisualtask addr, priority, argv:vararg
	.byte 0x03
	.4byte \addr
	.byte \priority
	.byte (.Lcreatetask_\@_2 - .Lcreatetask_\@_1) / 2
.Lcreatetask_\@_1:
	.2byte \argv
.Lcreatetask_\@_2:
	.endm

	.macro delay param0
	.byte 0x4
	.byte \param0
	.endm

	.macro waitforvisualfinish
	.byte 0x5
	.endm

	.macro hang1
	.byte 0x6
	.endm

	.macro hang2
	.byte 0x7
	.endm

	.macro end
	.byte 0x8
	.endm

	.macro playse param0
	.byte 0x9
	.2byte \param0
	.endm

	.macro monbg battler
	.byte 0xa
	.byte \battler
	.endm

	.macro clearmonbg battler
	.byte 0xb
	.byte \battler
	.endm

	.macro setalpha eva, evb
	.byte 0x0C
	.2byte ((\evb) << 8) | (\eva)
	.endm

	.macro blendoff
	.byte 0xd
	.endm

	.macro call param0
	.byte 0xe
	.4byte \param0
	.endm

	.macro return
	.byte 0xf
	.endm

	.macro setarg param0, param1
	.byte 0x10
	.byte \param0
	.2byte \param1
	.endm

	.macro choosetwoturnanim param0, param1
	.byte 0x11
	.4byte \param0
	.4byte \param1
	.endm

	.macro jumpifmoveturn param0, param1
	.byte 0x12
	.byte \param0
	.4byte \param1
	.endm

	.macro goto param0
	.byte 0x13
	.4byte \param0
	.endm

	.macro fadetobg param0
	.byte 0x14
	.byte \param0
	.endm

	.macro restorebg
	.byte 0x15
	.endm

	.macro waitbgfadeout
	.byte 0x16
	.endm

	.macro waitbgfadein
	.byte 0x17
	.endm

	.macro changebg param0
	.byte 0x18
	.byte \param0
	.endm

	.macro playsewithpan param0, param1
	.byte 0x19
	.2byte \param0
	.byte \param1
	.endm

	.macro setpan param0
	.byte 0x1a
	.byte \param0
	.endm

	.macro panse_1B param0, param1, param2, param3, param4
	.byte 0x1b
	.2byte \param0
	.byte \param1
	.byte \param2
	.byte \param3
	.byte \param4
	.endm

	.macro loopsewithpan param0, param1, param2, param3
	.byte 0x1c
	.2byte \param0
	.byte \param1
	.byte \param2
	.byte \param3
	.endm

	.macro waitplaysewithpan param0, param1, param2
	.byte 0x1d
	.2byte \param0
	.byte \param1
	.byte \param2
	.endm

	.macro setbldcnt param0
	.byte 0x1e
	.2byte \param0
	.endm

	.macro createsoundtask addr, argv:vararg
	.byte 0x1F
	.4byte \addr
	.byte (.Lcreatetask_1F_\@_2 - .Lcreatetask_1F_\@_1) / 2
.Lcreatetask_1F_\@_1:
	.2byte \argv
.Lcreatetask_1F_\@_2:
	.endm

	.macro waitsound
	.byte 0x20
	.endm

	.macro jumpargeq param0, param1, param2
	.byte 0x21
	.byte \param0
	.2byte \param1
	.4byte \param2
	.endm

	.macro monbg_22 battler
	.byte 0x22
	.byte \battler
	.endm

	.macro clearmonbg_23 battler
	.byte 0x23
	.byte \battler
	.endm

	.macro jumpifcontest param0
	.byte 0x24
	.4byte \param0
	.endm

	.macro fadetobgfromset param0, param1, param2
	.byte 0x25
	.byte \param0
	.byte \param1
	.byte \param2
	.endm

	.macro panse_26 param0, param1, param2, param3, param4
	.byte 0x26
	.2byte \param0
	.byte \param1
	.byte \param2
	.byte \param3
	.byte \param4
	.endm

	.macro panse_27 param0, param1, param2, param3, param4
	.byte 0x27
	.2byte \param0
	.byte \param1
	.byte \param2
	.byte \param3
	.byte \param4
	.endm

	.macro monbgprio_28 battler
	.byte 0x28
	.byte \battler
	.endm

	.macro monbgprio_29
	.byte 0x29
	.endm

	.macro monbgprio_2A battler
	.byte 0x2a
	.byte \battler
	.endm

	.macro invisible battler
	.byte 0x2b
	.byte \battler
	.endm

	.macro visible battler
	.byte 0x2c
	.byte \battler
	.endm

	.macro doublebattle_2D battler
	.byte 0x2d
	.byte \battler
	.endm

	.macro doublebattle_2E battler
	.byte 0x2e
	.byte \battler
	.endm

	.macro stopsound
	.byte 0x2f
	.endm
	
@ useful macros
	.macro jumpreteq value, ptr
	jumpargeq ARG_RET_ID, \value, \ptr
	.endm
	
	.macro jumprettrue ptr
	jumpreteq TRUE, \ptr
	.endm
	
	.macro jumpretfalse ptr
	jumpreteq FALSE, \ptr
	.endm
