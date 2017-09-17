	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_084975C4:: @ 84975C4
	.incbin "baserom.gba", 0x4975c4, 0x10

gUnknown_084975D4:: @ 84975D4
	.incbin "baserom.gba", 0x4975d4, 0x18

gUnknown_084975EC:: @ 84975EC
	.incbin "baserom.gba", 0x4975ec, 0xc

@ 84975F8
	.include "data/graphics/field_objects/field_object_graphics.inc"

gUnknown_08505438:: @ 8505438
	.incbin "baserom.gba", 0x505438, 0x144

gUnknown_0850557C:: @ 850557C
	.incbin "baserom.gba", 0x50557c, 0x51

gUnknown_085055CD:: @ 85055CD
	.incbin "baserom.gba", 0x5055cd, 0x51

    .align 2, 0
@ 8505620
	.include "data/graphics/field_objects/field_object_graphics_info_pointers.inc"

@ 85059F8
	.include "data/graphics/field_objects/field_effect_object_template_pointers.inc"

@ 8505A8C
	.include "data/graphics/field_objects/field_object_pic_tables.inc"

@ 85089FC
	.include "data/graphics/field_objects/field_object_anims.inc"

gUnknown_085094AC:: @ 85094AC
	.incbin "baserom.gba", 0x5094ac, 0x40

@ 85094EC
	.include "data/graphics/field_objects/field_object_oam.inc"

@ 8509954
	.include "data/graphics/field_objects/field_object_graphics_info.inc"

gUnknown_0850BBC8:: @ 850BBC8
	.incbin "baserom.gba", 0x50bbc8, 0x138

gUnknown_0850BD00:: @ 850BD00
	.incbin "baserom.gba", 0x50bd00, 0x78

gUnknown_0850BD78:: @ 850BD78
	.incbin "baserom.gba", 0x50bd78, 0xc0

gUnknown_0850BE38:: @ 850BE38
	.incbin "baserom.gba", 0x50be38, 0x10

@ 850BE48
	.include "data/graphics/field_objects/berry_tree_graphics_tables.inc"

@ 850C9C0
	.include "data/graphics/field_objects/field_effect_objects.inc"

	.incbin "baserom.gba", 0x50d6d4, 0x8

gUnknown_0850D6DC:: @ 850D6DC
	.incbin "baserom.gba", 0x50d6dc, 0x10

gUnknown_0850D6EC:: @ 850D6EC
	.incbin "baserom.gba", 0x50d6ec, 0x8

gUnknown_0850D6F4:: @ 850D6F4
	.incbin "baserom.gba", 0x50d6f4, 0x1c

gUnknown_0850D710:: @ 850D710
	.incbin "baserom.gba", 0x50d710, 0x4

gUnknown_0850D714:: @ 850D714
	.incbin "baserom.gba", 0x50d714, 0x2c

gUnknown_0850D740:: @ 850D740
	.incbin "baserom.gba", 0x50d740, 0x14

gUnknown_0850D754:: @ 850D754
	.incbin "baserom.gba", 0x50d754, 0x1c

gUnknown_0850D770:: @ 850D770
	.incbin "baserom.gba", 0x50d770, 0x4

gUnknown_0850D774:: @ 850D774
	.incbin "baserom.gba", 0x50d774, 0x1c

gUnknown_0850D790:: @ 850D790
	.incbin "baserom.gba", 0x50d790, 0x4

gUnknown_0850D794:: @ 850D794
	.incbin "baserom.gba", 0x50d794, 0xc

gUnknown_0850D7A0:: @ 850D7A0
	.incbin "baserom.gba", 0x50d7a0, 0x14

gUnknown_0850D7B4:: @ 850D7B4
	.incbin "baserom.gba", 0x50d7b4, 0x14

gUnknown_0850D7C8:: @ 850D7C8
	.incbin "baserom.gba", 0x50d7c8, 0x14

gUnknown_0850D7DC:: @ 850D7DC
	.incbin "baserom.gba", 0x50d7dc, 0x14

gUnknown_0850D7F0:: @ 850D7F0
	.incbin "baserom.gba", 0x50d7f0, 0x4

gUnknown_0850D7F4:: @ 850D7F4
	.incbin "baserom.gba", 0x50d7f4, 0x14

gUnknown_0850D808:: @ 850D808
	.incbin "baserom.gba", 0x50d808, 0x4

gUnknown_0850D80C:: @ 850D80C
	.incbin "baserom.gba", 0x50d80c, 0x14

gUnknown_0850D820:: @ 850D820
	.incbin "baserom.gba", 0x50d820, 0x4

gUnknown_0850D824:: @ 850D824
	.incbin "baserom.gba", 0x50d824, 0x14

gUnknown_0850D838:: @ 850D838
	.incbin "baserom.gba", 0x50d838, 0x4

gUnknown_0850D83C:: @ 850D83C
	.incbin "baserom.gba", 0x50d83c, 0x14

gUnknown_0850D850:: @ 850D850
	.incbin "baserom.gba", 0x50d850, 0x4

gUnknown_0850D854:: @ 850D854
	.incbin "baserom.gba", 0x50d854, 0x14

gUnknown_0850D868:: @ 850D868
	.incbin "baserom.gba", 0x50d868, 0x4

gUnknown_0850D86C:: @ 850D86C
	.incbin "baserom.gba", 0x50d86c, 0x14

gUnknown_0850D880:: @ 850D880
	.incbin "baserom.gba", 0x50d880, 0x4

gUnknown_0850D884:: @ 850D884
	.incbin "baserom.gba", 0x50d884, 0x14

gUnknown_0850D898:: @ 850D898
	.incbin "baserom.gba", 0x50d898, 0x4

gUnknown_0850D89C:: @ 850D89C
	.incbin "baserom.gba", 0x50d89c, 0x10

gUnknown_0850D8AC:: @ 850D8AC
	.incbin "baserom.gba", 0x50d8ac, 0x8

gUnknown_0850D8B4:: @ 850D8B4
	.incbin "baserom.gba", 0x50d8b4, 0x10

gUnknown_0850D8C4:: @ 850D8C4
	.incbin "baserom.gba", 0x50d8c4, 0x8

gUnknown_0850D8CC:: @ 850D8CC
	.incbin "baserom.gba", 0x50d8cc, 0x10

gUnknown_0850D8DC:: @ 850D8DC
	.incbin "baserom.gba", 0x50d8dc, 0xc

gUnknown_0850D8E8:: @ 850D8E8
	.incbin "baserom.gba", 0x50d8e8, 0x4

gUnknown_0850D8EC:: @ 850D8EC
	.incbin "baserom.gba", 0x50d8ec, 0xc

gUnknown_0850D8F8:: @ 850D8F8
	.incbin "baserom.gba", 0x50d8f8, 0x4

gUnknown_0850D8FC:: @ 850D8FC
	.incbin "baserom.gba", 0x50d8fc, 0xc

gUnknown_0850D908:: @ 850D908
	.incbin "baserom.gba", 0x50d908, 0x4

gUnknown_0850D90C:: @ 850D90C
	.incbin "baserom.gba", 0x50d90c, 0xc

gUnknown_0850D918:: @ 850D918
	.incbin "baserom.gba", 0x50d918, 0x4

gUnknown_0850D91C:: @ 850D91C
	.incbin "baserom.gba", 0x50d91c, 0xc

gUnknown_0850D928:: @ 850D928
	.incbin "baserom.gba", 0x50d928, 0x4

gUnknown_0850D92C:: @ 850D92C
	.incbin "baserom.gba", 0x50d92c, 0xc

gUnknown_0850D938:: @ 850D938
	.incbin "baserom.gba", 0x50d938, 0x4

gUnknown_0850D93C:: @ 850D93C
	.incbin "baserom.gba", 0x50d93c, 0xc

gUnknown_0850D948:: @ 850D948
	.incbin "baserom.gba", 0x50d948, 0xc

gUnknown_0850D954:: @ 850D954
	.incbin "baserom.gba", 0x50d954, 0x4

gUnknown_0850D958:: @ 850D958
	.incbin "baserom.gba", 0x50d958, 0xc

gUnknown_0850D964:: @ 850D964
	.incbin "baserom.gba", 0x50d964, 0x4

gUnknown_0850D968:: @ 850D968
	.incbin "baserom.gba", 0x50d968, 0xc

gUnknown_0850D974:: @ 850D974
	.incbin "baserom.gba", 0x50d974, 0x4

gUnknown_0850D978:: @ 850D978
	.incbin "baserom.gba", 0x50d978, 0xc

gUnknown_0850D984:: @ 850D984
	.incbin "baserom.gba", 0x50d984, 0x4

gUnknown_0850D988:: @ 850D988
	.incbin "baserom.gba", 0x50d988, 0xc

gUnknown_0850D994:: @ 850D994
	.incbin "baserom.gba", 0x50d994, 0x4

gUnknown_0850D998:: @ 850D998
	.incbin "baserom.gba", 0x50d998, 0xc

gUnknown_0850D9A4:: @ 850D9A4
	.incbin "baserom.gba", 0x50d9a4, 0x4

gUnknown_0850D9A8:: @ 850D9A8
	.incbin "baserom.gba", 0x50d9a8, 0xc

gUnknown_0850D9B4:: @ 850D9B4
	.incbin "baserom.gba", 0x50d9b4, 0x4

gUnknown_0850D9B8:: @ 850D9B8
	.incbin "baserom.gba", 0x50d9b8, 0xc

gUnknown_0850D9C4:: @ 850D9C4
	.incbin "baserom.gba", 0x50d9c4, 0x4

gUnknown_0850D9C8:: @ 850D9C8
	.incbin "baserom.gba", 0x50d9c8, 0xc

gUnknown_0850D9D4:: @ 850D9D4
	.incbin "baserom.gba", 0x50d9d4, 0x4

gUnknown_0850D9D8:: @ 850D9D8
	.incbin "baserom.gba", 0x50d9d8, 0xc

gUnknown_0850D9E4:: @ 850D9E4
	.incbin "baserom.gba", 0x50d9e4, 0x4

gUnknown_0850D9E8:: @ 850D9E8
	.incbin "baserom.gba", 0x50d9e8, 0xc

gUnknown_0850D9F4:: @ 850D9F4
	.incbin "baserom.gba", 0x50d9f4, 0x4

gUnknown_0850D9F8:: @ 850D9F8
	.incbin "baserom.gba", 0x50d9f8, 0xc

gUnknown_0850DA04:: @ 850DA04
	.incbin "baserom.gba", 0x50da04, 0x4

gUnknown_0850DA08:: @ 850DA08
	.incbin "baserom.gba", 0x50da08, 0xc

gUnknown_0850DA14:: @ 850DA14
	.incbin "baserom.gba", 0x50da14, 0x4

gUnknown_0850DA18:: @ 850DA18
	.incbin "baserom.gba", 0x50da18, 0xc

gUnknown_0850DA24:: @ 850DA24
	.incbin "baserom.gba", 0x50da24, 0x4

gUnknown_0850DA28:: @ 850DA28
	.incbin "baserom.gba", 0x50da28, 0xc

gUnknown_0850DA34:: @ 850DA34
	.incbin "baserom.gba", 0x50da34, 0x4

gUnknown_0850DA38:: @ 850DA38
	.incbin "baserom.gba", 0x50da38, 0xc

gUnknown_0850DA44:: @ 850DA44
	.incbin "baserom.gba", 0x50da44, 0x4

gUnknown_0850DA48:: @ 850DA48
	.incbin "baserom.gba", 0x50da48, 0xc

gUnknown_0850DA54:: @ 850DA54
	.incbin "baserom.gba", 0x50da54, 0x4

gUnknown_0850DA58:: @ 850DA58
	.incbin "baserom.gba", 0x50da58, 0xc

gUnknown_0850DA64:: @ 850DA64
	.incbin "baserom.gba", 0x50da64, 0x2c

gUnknown_0850DA90:: @ 850DA90
	.incbin "baserom.gba", 0x50da90, 0xc

gUnknown_0850DA9C:: @ 850DA9C
	.incbin "baserom.gba", 0x50da9c, 0x4

gUnknown_0850DAA0:: @ 850DAA0
	.incbin "baserom.gba", 0x50daa0, 0x8

gUnknown_0850DAA8:: @ 850DAA8
	.incbin "baserom.gba", 0x50daa8, 0x8

gUnknown_0850DAB0:: @ 850DAB0
	.incbin "baserom.gba", 0x50dab0, 0x8

gUnknown_0850DAB8:: @ 850DAB8
	.incbin "baserom.gba", 0x50dab8, 0x8

gUnknown_0850DAC0:: @ 850DAC0
	.incbin "baserom.gba", 0x50dac0, 0xc

gUnknown_0850DACC:: @ 850DACC
	.incbin "baserom.gba", 0x50dacc, 0x9

gUnknown_0850DAD5:: @ 850DAD5
	.incbin "baserom.gba", 0x50dad5, 0x9

gUnknown_0850DADE:: @ 850DADE
	.incbin "baserom.gba", 0x50dade, 0x9

gUnknown_0850DAE7:: @ 850DAE7
	.incbin "baserom.gba", 0x50dae7, 0x9

gUnknown_0850DAF0:: @ 850DAF0
	.incbin "baserom.gba", 0x50daf0, 0x9

gUnknown_0850DAF9:: @ 850DAF9
	.incbin "baserom.gba", 0x50daf9, 0x9

gUnknown_0850DB02:: @ 850DB02
	.incbin "baserom.gba", 0x50db02, 0x9

gUnknown_0850DB0B:: @ 850DB0B
	.incbin "baserom.gba", 0x50db0b, 0x9

gUnknown_0850DB14:: @ 850DB14
	.incbin "baserom.gba", 0x50db14, 0x9

gUnknown_0850DB1D:: @ 850DB1D
	.incbin "baserom.gba", 0x50db1d, 0x9

gUnknown_0850DB26:: @ 850DB26
	.incbin "baserom.gba", 0x50db26, 0x9

gUnknown_0850DB2F:: @ 850DB2F
	.incbin "baserom.gba", 0x50db2f, 0x9

gUnknown_0850DB38:: @ 850DB38
	.incbin "baserom.gba", 0x50db38, 0x9

gUnknown_0850DB41:: @ 850DB41
	.incbin "baserom.gba", 0x50db41, 0x9

gUnknown_0850DB4A:: @ 850DB4A
	.incbin "baserom.gba", 0x50db4a, 0x9

gUnknown_0850DB53:: @ 850DB53
	.incbin "baserom.gba", 0x50db53, 0x9

gUnknown_0850DB5C:: @ 850DB5C
	.incbin "baserom.gba", 0x50db5c, 0x10

gUnknown_0850DB6C:: @ 850DB6C
	.incbin "baserom.gba", 0x50db6c, 0x10

gUnknown_0850DB7C:: @ 850DB7C
	.incbin "baserom.gba", 0x50db7c, 0x24

gUnknown_0850DBA0:: @ 850DBA0
	.incbin "baserom.gba", 0x50dba0, 0x5

gUnknown_0850DBA5:: @ 850DBA5
	.incbin "baserom.gba", 0x50dba5, 0x5

gUnknown_0850DBAA:: @ 850DBAA
	.incbin "baserom.gba", 0x50dbaa, 0x5

gUnknown_0850DBAF:: @ 850DBAF
	.incbin "baserom.gba", 0x50dbaf, 0x5

gUnknown_0850DBB4:: @ 850DBB4
	.incbin "baserom.gba", 0x50dbb4, 0x5

gUnknown_0850DBB9:: @ 850DBB9
	.incbin "baserom.gba", 0x50dbb9, 0x5

gUnknown_0850DBBE:: @ 850DBBE
	.incbin "baserom.gba", 0x50dbbe, 0x5

gUnknown_0850DBC3:: @ 850DBC3
	.incbin "baserom.gba", 0x50dbc3, 0x5

gUnknown_0850DBC8:: @ 850DBC8
	.incbin "baserom.gba", 0x50dbc8, 0x5

gUnknown_0850DBCD:: @ 850DBCD
	.incbin "baserom.gba", 0x50dbcd, 0x5

gUnknown_0850DBD2:: @ 850DBD2
	.incbin "baserom.gba", 0x50dbd2, 0x5

gUnknown_0850DBD7:: @ 850DBD7
	.incbin "baserom.gba", 0x50dbd7, 0x5

gUnknown_0850DBDC:: @ 850DBDC
	.incbin "baserom.gba", 0x50dbdc, 0x5

gUnknown_0850DBE1:: @ 850DBE1
	.incbin "baserom.gba", 0x50dbe1, 0x5

gUnknown_0850DBE6:: @ 850DBE6
	.incbin "baserom.gba", 0x50dbe6, 0x5

gUnknown_0850DBEB:: @ 850DBEB
	.incbin "baserom.gba", 0x50dbeb, 0x5

gUnknown_0850DBF0:: @ 850DBF0
	.incbin "baserom.gba", 0x50dbf0, 0x5

gUnknown_0850DBF5:: @ 850DBF5
	.incbin "baserom.gba", 0x50dbf5, 0x5

gUnknown_0850DBFA:: @ 850DBFA
	.incbin "baserom.gba", 0x50dbfa, 0x5

gUnknown_0850DBFF:: @ 850DBFF
	.incbin "baserom.gba", 0x50dbff, 0x5

gUnknown_0850DC04:: @ 850DC04
	.incbin "baserom.gba", 0x50dc04, 0x5

gUnknown_0850DC09:: @ 850DC09
	.incbin "baserom.gba", 0x50dc09, 0x5

gUnknown_0850DC0E:: @ 850DC0E
	.incbin "baserom.gba", 0x50dc0e, 0x5

gUnknown_0850DC13:: @ 850DC13
	.incbin "baserom.gba", 0x50dc13, 0x5

gUnknown_0850DC18:: @ 850DC18
	.incbin "baserom.gba", 0x50dc18, 0x5

gUnknown_0850DC1D:: @ 850DC1D
	.incbin "baserom.gba", 0x50dc1d, 0x5

gUnknown_0850DC22:: @ 850DC22
	.incbin "baserom.gba", 0x50dc22, 0x5

gUnknown_0850DC27:: @ 850DC27
	.incbin "baserom.gba", 0x50dc27, 0x8

gUnknown_0850DC2F:: @ 850DC2F
	.incbin "baserom.gba", 0x50dc2f, 0x10

gUnknown_0850DC3F:: @ 850DC3F
	.incbin "baserom.gba", 0x50dc3f, 0x11

gUnknown_0850DC50:: @ 850DC50
	.incbin "baserom.gba", 0x50dc50, 0x298

gUnknown_0850DEE8:: @ 850DEE8
	.incbin "baserom.gba", 0x50dee8, 0xd4

gUnknown_0850DFBC:: @ 850DFBC
	.incbin "baserom.gba", 0x50dfbc, 0x6

gUnknown_0850DFC2:: @ 850DFC2
    .incbin "baserom.gba", 0x50dfc2, 0x6

gUnknown_0850DFC8:: @ 850DFC8
	.incbin "baserom.gba", 0x50dfc8, 0x614
