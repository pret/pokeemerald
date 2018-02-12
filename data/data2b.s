#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082FF1D8:: @ 82FF1D8
	.incbin "graphics/link/minigame_digits.gbapal"

	.align 2
gUnknown_082FF1F8:: @ 82FF1F8
	.incbin "graphics/link/minigame_digits.4bpp.lz"

	.align 2
gUnknown_082FF2B8:: @ 82FF2B8
	.incbin "graphics/link/minigame_digits2.4bpp.lz"

	.align 2
gUnknown_082FF3A8:: @ 82FF3A8
	.byte 0x00, 0x80, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x88, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x90, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x98, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FF3C8:: @ 82FF3C8
	.byte 0x00, 0xa0, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xa8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xb0, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xb8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FF3E8:: @ 82FF3E8
	.byte 0x00, 0xc0, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xc8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xd0, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xd8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FF408:: @ 82FF408
	.byte 0x00, 0xe0, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xe8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xf0, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0xf8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FF428:: @ 82FF428
	obj_frame_tiles gTrainerBackPic_Brendan, 0x0800
	obj_frame_tiles gTrainerBackPic_Brendan + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_Brendan + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_Brendan + 0x1800, 0x0800

	.align 2
gUnknown_082FF448:: @ 82FF448
	obj_frame_tiles gTrainerBackPic_May, 0x0800
	obj_frame_tiles gTrainerBackPic_May + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_May + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_May + 0x1800, 0x0800

	.align 2
gUnknown_082FF468:: @ 82FF468
	obj_frame_tiles gTrainerBackPic_Red, 0x0800
	obj_frame_tiles gTrainerBackPic_Red + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_Red + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_Red + 0x1800, 0x0800
	obj_frame_tiles gTrainerBackPic_Red + 0x2000, 0x0800

	.align 2
gUnknown_082FF490:: @ 82FF490
	obj_frame_tiles gTrainerBackPic_Leaf, 0x0800
	obj_frame_tiles gTrainerBackPic_Leaf + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_Leaf + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_Leaf + 0x1800, 0x0800
	obj_frame_tiles gTrainerBackPic_Leaf + 0x2000, 0x0800

	.align 2
gUnknown_082FF4B8:: @ 82FF4B8
	obj_frame_tiles gTrainerBackPic_RubySapphireBrendan, 0x0800
	obj_frame_tiles gTrainerBackPic_RubySapphireBrendan + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_RubySapphireBrendan + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_RubySapphireBrendan + 0x1800, 0x0800

	.align 2
gUnknown_082FF4D8:: @ 82FF4D8
	obj_frame_tiles gTrainerBackPic_RubySapphireMay, 0x0800
	obj_frame_tiles gTrainerBackPic_RubySapphireMay + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_RubySapphireMay + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_RubySapphireMay + 0x1800, 0x0800

	.align 2
gUnknown_082FF4F8:: @ 82FF4F8
	obj_frame_tiles gTrainerBackPic_Wally, 0x0800
	obj_frame_tiles gTrainerBackPic_Wally + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_Wally + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_Wally + 0x1800, 0x0800

	.align 2
gUnknown_082FF518:: @ 82FF518
	obj_frame_tiles gTrainerBackPic_Steven, 0x0800
	obj_frame_tiles gTrainerBackPic_Steven + 0x0800, 0x0800
	obj_frame_tiles gTrainerBackPic_Steven + 0x1000, 0x0800
	obj_frame_tiles gTrainerBackPic_Steven + 0x1800, 0x0800

	.align 2
gAnimCmd_General_Frame0:: @ 82FF538
    obj_image_anim_frame 0, 0
    obj_image_anim_end

	.align 2
AnimCmd_82FF540:: @ 82FF540
	.2byte 0x0003, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082FF548:: @ 82FF548
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF558:: @ 82FF558
	.2byte 0xff00, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF568:: @ 82FF568
	.2byte 0x0028, 0x0028, 0x0000, 0x0000, 0x0012, 0x0012, 0x0c00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF580:: @ 82FF580
	.2byte 0xfffe, 0xfffe, 0x1200, 0x0000, 0xfff0, 0xfff0, 0x0f00, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF598:: @ 82FF598
	.2byte 0x00a0, 0x0100, 0x0000, 0x0000, 0x0004, 0x0000, 0x0800, 0x0000
	.2byte 0xfffc, 0x0000, 0x0800, 0x0000, 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_082FF5B8:: @ 82FF5B8
	.2byte 0x0002, 0x0002, 0x1400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF5C8:: @ 82FF5C8
	.2byte 0xfffe, 0xfffe, 0x1400, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF5D8:: @ 82FF5D8
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfff0, 0xfff0, 0x0900, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF5F0:: @ 82FF5F0
	.2byte 0x0004, 0x0004, 0x3f00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF600:: @ 82FF600
	.2byte 0x0000, 0x0000, 0x05fd, 0x0000, 0x0000, 0x0000, 0x0503, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF618:: @ 82FF618
	.4byte gUnknown_082FF548
	.4byte gUnknown_082FF568
	.4byte gUnknown_082FF580
	.4byte gUnknown_082FF598
	.4byte gUnknown_082FF5B8
	.4byte gUnknown_082FF5C8
	.4byte gUnknown_082FF5F0
	.4byte gUnknown_082FF600
	.4byte gUnknown_082FF5D8

	.align 2
gUnknown_082FF63C:: @ 82FF63C
	.2byte 0xfffc, 0xfffc, 0x3f04, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF64C:: @ 82FF64C
	.2byte 0x0000, 0x0000, 0x0503, 0x0000, 0x0000, 0x0000, 0x05fd, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF664:: @ 82FF664
	.2byte 0x0000, 0x0000, 0x14fb, 0x0000, 0x0000, 0x0000, 0x1400, 0x0000
	.2byte 0x0000, 0x0000, 0x1405, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF684:: @ 82FF684
	.2byte 0x0000, 0x0000, 0x6e09, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF694:: @ 82FF694
	.4byte gUnknown_082FF548
	.4byte gUnknown_082FF568
	.4byte gUnknown_082FF580
	.4byte gUnknown_082FF598
	.4byte gUnknown_082FF5B8
	.4byte gUnknown_082FF5C8
	.4byte gUnknown_082FF63C
	.4byte gUnknown_082FF64C
	.4byte gUnknown_082FF664
	.4byte gUnknown_082FF5D8
	.4byte gUnknown_082FF684

	.align 2
gUnknown_082FF6C0:: @ 82FF6C0
	.4byte gUnknown_082FF558
	.4byte gUnknown_082FF568
	.4byte gUnknown_082FF580
	.4byte gUnknown_082FF598
	.4byte gUnknown_082FF5B8
	.4byte gUnknown_082FF5C8
	.4byte gUnknown_082FF63C
	.4byte gUnknown_082FF64C
	.4byte gUnknown_082FF664
	.4byte gUnknown_082FF5D8
	.4byte gUnknown_082FF684

	.align 2
gUnknown_082FF6EC:: @ 82FF6EC
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082FF6F4:: @ 82FF6F4
	.2byte 0x0001, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082FF6FC:: @ 82FF6FC
	.2byte 0x0002, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082FF704:: @ 82FF704
	.2byte 0x0003, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082FF70C:: @ 82FF70C
	.4byte gUnknown_082FF6EC
	.4byte gUnknown_082FF6F4
	.4byte gUnknown_082FF6FC
	.4byte gUnknown_082FF704

	.align 2
gUnknown_082FF71C:: @ 82FF71C
	.2byte 0x0000, 0x0001, 0x0001, 0x0019, 0x0000, 0x0007, 0x0001, 0x0007
	.2byte 0x0000, 0x0007, 0xffff, 0x0000

	.align 2
gUnknown_082FF734:: @ 82FF734
	.2byte 0x0000, 0x0001, 0x0002, 0x0008, 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_082FF744:: @ 82FF744
	.2byte 0x0000, 0x000a, 0x0002, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FF750:: @ 82FF750
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FF758:: @ 82FF758
	.2byte 0x0000, 0x0001, 0x0001, 0x0005, 0x0000, 0x0005, 0x0001, 0x0005
	.2byte 0x0000, 0x0005, 0x0001, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF774:: @ 82FF774
	.2byte 0x0000, 0x0001, 0x0002, 0x000c, 0x0000, 0x000e, 0x0002, 0x000c
	.2byte 0x0000, 0x000e, 0x0002, 0x000c, 0xffff, 0x0000

	.align 2
gUnknown_082FF790:: @ 82FF790
	.2byte 0x0000, 0x000e, 0x0002, 0x000c, 0xffff, 0x0000

	.align 2
gUnknown_082FF79C:: @ 82FF79C
	.2byte 0x0000, 0x000a, 0x0001, 0x000a, 0x0000, 0x000a, 0x0001, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FF7B0:: @ 82FF7B0
	.2byte 0x0000, 0x000a, 0x0002, 0x000a, 0x0000, 0x000a, 0x0002, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FF7C4:: @ 82FF7C4
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF7CC:: @ 82FF7CC
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF7D4:: @ 82FF7D4
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF7DC:: @ 82FF7DC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF7E4:: @ 82FF7E4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF7EC:: @ 82FF7EC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF7F4:: @ 82FF7F4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF7FC:: @ 82FF7FC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF804:: @ 82FF804
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF80C:: @ 82FF80C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF814:: @ 82FF814
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF81C:: @ 82FF81C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF824:: @ 82FF824
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF82C:: @ 82FF82C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF834:: @ 82FF834
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF83C:: @ 82FF83C
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF844:: @ 82FF844
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF84C:: @ 82FF84C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF854:: @ 82FF854
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF85C:: @ 82FF85C
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF864:: @ 82FF864
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF86C:: @ 82FF86C
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF874:: @ 82FF874
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF87C:: @ 82FF87C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF884:: @ 82FF884
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF88C:: @ 82FF88C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF894:: @ 82FF894
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF89C:: @ 82FF89C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF8A4:: @ 82FF8A4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF8AC:: @ 82FF8AC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF8B4:: @ 82FF8B4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF8BC:: @ 82FF8BC
	.2byte 0x0000, 0x000f, 0x0008, 0x000f, 0x0002, 0x0016, 0x0008, 0x0005
	.2byte 0x0003, 0x0008, 0x0004, 0x0005, 0x0006, 0x0005, 0x0004, 0x0005
	.2byte 0x0006, 0x0005, 0x0004, 0x0005, 0x0006, 0x0005, 0x0004, 0x0005
	.2byte 0x0006, 0x0005, 0x0005, 0x0005, 0x0007, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FF8FC:: @ 82FF8FC
	.2byte 0x0000, 0x000a, 0x0008, 0x000f, 0x0002, 0x000f, 0x0008, 0x000f
	.2byte 0x0009, 0x000f, 0x0000, 0x000a, 0x0009, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FF91C:: @ 82FF91C
	.2byte 0x0000, 0x000a, 0x0009, 0x000a, 0x0000, 0x000a, 0x000a, 0x0014, 0xffff, 0x0000

	.align 2
gUnknown_082FF930:: @ 82FF930
	.2byte 0x0000, 0x000f, 0x000b, 0x000f, 0xffff, 0x0000

	.align 2
gUnknown_082FF93C:: @ 82FF93C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF944:: @ 82FF944
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FF94C:: @ 82FF94C
	.2byte 0x0000, 0x000a, 0x0001, 0x0007, 0x0002, 0x0007, 0x0003, 0x0004
	.2byte 0x0004, 0x0004, 0x0003, 0x0004, 0x0004, 0x0004, 0x0003, 0x0004
	.2byte 0x0004, 0x0004, 0x0003, 0x0004, 0x0001, 0x0006, 0x0005, 0x0002
	.2byte 0x0000, 0x0002, 0x0005, 0x0002, 0x0000, 0x0002, 0x0005, 0x0002
	.2byte 0x0006, 0x0002, 0x0005, 0x0002, 0x0006, 0x0002, 0x0006, 0x000a
	.2byte 0x0005, 0x0004, 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FF9A8:: @ 82FF9A8
	.2byte 0x0000, 0x000c, 0x0007, 0x000c, 0x0008, 0x000c, 0x0000, 0x000c
	.2byte 0x0007, 0x000c, 0x0008, 0x000c, 0x0000, 0x000c, 0x0007, 0x000c
	.2byte 0x0008, 0x000c, 0x0000, 0x000c, 0x0007, 0x000c, 0x0008, 0x000c
	.2byte 0x0000, 0x000c, 0x0007, 0x000c, 0x0008, 0x000c, 0x0009, 0x0003
	.2byte 0x0000, 0x0003, 0x0009, 0x0003, 0x0000, 0x0003, 0x0007, 0x000c
	.2byte 0x0008, 0x000c, 0xffff, 0x0000

	.align 2
gUnknown_082FFA00:: @ 82FFA00
	.2byte 0x0000, 0x000c, 0x0007, 0x000c, 0x0008, 0x000c, 0x0000, 0x000c
	.2byte 0x0007, 0x000c, 0x0008, 0x000c, 0x0000, 0x000c, 0x0007, 0x000c
	.2byte 0x0008, 0x000c, 0x0000, 0x000c, 0x0007, 0x000c, 0x0008, 0x000c
	.2byte 0x0000, 0x000c, 0x0007, 0x000c, 0x0008, 0x000c, 0x0009, 0x0003
	.2byte 0x0000, 0x0003, 0x0009, 0x0003, 0x0000, 0x0003, 0x0007, 0x000c
	.2byte 0x0008, 0x000c, 0xffff, 0x0000

	.align 2
gUnknown_082FFA58:: @ 82FFA58
	.2byte 0x0000, 0x0012, 0x000a, 0x0012, 0xffff, 0x0000

	.align 2
gUnknown_082FFA64:: @ 82FFA64
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA6C:: @ 82FFA6C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA74:: @ 82FFA74
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA7C:: @ 82FFA7C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA84:: @ 82FFA84
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA8C:: @ 82FFA8C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA94:: @ 82FFA94
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFA9C:: @ 82FFA9C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFAA4:: @ 82FFAA4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFAAC:: @ 82FFAAC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFAB4:: @ 82FFAB4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFABC:: @ 82FFABC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFAC4:: @ 82FFAC4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFACC:: @ 82FFACC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFAD4:: @ 82FFAD4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFADC:: @ 82FFADC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFAE4:: @ 82FFAE4
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFAEC:: @ 82FFAEC
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFAF4:: @ 82FFAF4
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFAFC:: @ 82FFAFC
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFB04:: @ 82FFB04
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFB0C:: @ 82FFB0C
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFB14:: @ 82FFB14
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFB1C:: @ 82FFB1C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFB24:: @ 82FFB24
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFB2C:: @ 82FFB2C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFB34:: @ 82FFB34
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFB3C:: @ 82FFB3C
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFB44:: @ 82FFB44
	.2byte 0x0000, 0x0001, 0x0001, 0x0012, 0x0000, 0x0012, 0x0001, 0x0012
	.2byte 0x0000, 0x0012, 0x0001, 0x0012, 0xffff, 0x0000

	.align 2
gUnknown_082FFB60:: @ 82FFB60
	.2byte 0x0000, 0x0001, 0x0002, 0x0012, 0x0000, 0x0012, 0x0002, 0x0012
	.2byte 0x0000, 0x0012, 0x0002, 0x0012, 0xffff, 0x0000

	.align 2
gUnknown_082FFB7C:: @ 82FFB7C
	.2byte 0x0000, 0x0005, 0x0002, 0x0005, 0x0003, 0x0006, 0x0001, 0x0005
	.2byte 0x0000, 0x0005, 0x0002, 0x0005, 0x0003, 0x0005, 0x0001, 0x0005
	.2byte 0x0000, 0x0005, 0x0001, 0x0007, 0x0000, 0x0004, 0x0004, 0x0004
	.2byte 0x0000, 0x0004, 0x0004, 0x0004, 0x0000, 0x0014, 0xffff, 0x0000

	.align 2
gUnknown_082FFBBC:: @ 82FFBBC
	.2byte 0x0000, 0x0006, 0x0001, 0x0006, 0x0002, 0x0006, 0x0003, 0x0006
	.2byte 0x0001, 0x0006, 0x0000, 0x0006, 0x0001, 0x0006, 0x0000, 0x001e
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FFBE0:: @ 82FFBE0
	.2byte 0x0000, 0x000c, 0x0005, 0x000c, 0x0000, 0x000c, 0x0006, 0x000c, 0xffff, 0x0000

	.align 2
gUnknown_082FFBF4:: @ 82FFBF4
	.2byte 0x0007, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFBFC:: @ 82FFBFC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC04:: @ 82FFC04
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC0C:: @ 82FFC0C
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFC14:: @ 82FFC14
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFC1C:: @ 82FFC1C
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFC24:: @ 82FFC24
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC2C:: @ 82FFC2C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC34:: @ 82FFC34
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC3C:: @ 82FFC3C
	.2byte 0x0000, 0x0001, 0x0001, 0x000a, 0x0000, 0x000a, 0x0001, 0x000a
	.2byte 0x0000, 0x000a, 0x0001, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FFC58:: @ 82FFC58
	.2byte 0x0000, 0x0001, 0x0002, 0x0008, 0x0000, 0x000c, 0x0002, 0x0008
	.2byte 0x0000, 0x000c, 0x0002, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_082FFC74:: @ 82FFC74
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC7C:: @ 82FFC7C
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FFC84:: @ 82FFC84
	.2byte 0x0001, 0x0009, 0xffff, 0x0000

	.align 2
gUnknown_082FFC8C:: @ 82FFC8C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC94:: @ 82FFC94
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFC9C:: @ 82FFC9C
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FFCA4:: @ 82FFCA4
	.2byte 0x0001, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FFCAC:: @ 82FFCAC
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFCB4:: @ 82FFCB4
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFCBC:: @ 82FFCBC
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFCC4:: @ 82FFCC4
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFCCC:: @ 82FFCCC
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFCD4:: @ 82FFCD4
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFCDC:: @ 82FFCDC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFCE4:: @ 82FFCE4
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFCEC:: @ 82FFCEC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFCF4:: @ 82FFCF4
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFCFC:: @ 82FFCFC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD04:: @ 82FFD04
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFD0C:: @ 82FFD0C
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFD14:: @ 82FFD14
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gUnknown_082FFD1C:: @ 82FFD1C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD24:: @ 82FFD24
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD2C:: @ 82FFD2C
	.2byte 0x0002, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD34:: @ 82FFD34
	.2byte 0x0003, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD3C:: @ 82FFD3C
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFD44:: @ 82FFD44
	.2byte 0x0000, 0x003f, 0xffff, 0x0000

	.align 2
gUnknown_082FFD4C:: @ 82FFD4C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD54:: @ 82FFD54
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD5C:: @ 82FFD5C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD64:: @ 82FFD64
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD6C:: @ 82FFD6C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD74:: @ 82FFD74
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD7C:: @ 82FFD7C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD84:: @ 82FFD84
	.2byte 0x0001, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFD8C:: @ 82FFD8C
	.2byte 0x0000, 0x0014, 0x0001, 0x001e, 0x0000, 0x0014, 0x0001, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082FFDA0:: @ 82FFDA0
	.2byte 0x0000, 0x0014, 0x0002, 0x0014, 0x0000, 0x0014, 0x0002, 0x0014, 0xffff, 0x0000

	.align 2
gUnknown_082FFDB4:: @ 82FFDB4
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FFDBC:: @ 82FFDBC
	.2byte 0x0000, 0x000a, 0xffff, 0x0000

	.align 2
gUnknown_082FFDC4:: @ 82FFDC4
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_082FFDCC:: @ 82FFDCC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDD0:: @ 82FFDD0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDD4:: @ 82FFDD4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDD8:: @ 82FFDD8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDDC:: @ 82FFDDC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDE0:: @ 82FFDE0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDE4:: @ 82FFDE4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDE8:: @ 82FFDE8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDEC:: @ 82FFDEC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDF0:: @ 82FFDF0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDF4:: @ 82FFDF4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDF8:: @ 82FFDF8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFDFC:: @ 82FFDFC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE00:: @ 82FFE00
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE04:: @ 82FFE04
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE08:: @ 82FFE08
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE0C:: @ 82FFE0C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE10:: @ 82FFE10
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE14:: @ 82FFE14
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE18:: @ 82FFE18
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE1C:: @ 82FFE1C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE20:: @ 82FFE20
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE24:: @ 82FFE24
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE28:: @ 82FFE28
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE2C:: @ 82FFE2C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE30:: @ 82FFE30
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE34:: @ 82FFE34
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE38:: @ 82FFE38
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE3C:: @ 82FFE3C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE40:: @ 82FFE40
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE44:: @ 82FFE44
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE48:: @ 82FFE48
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE4C:: @ 82FFE4C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE50:: @ 82FFE50
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE54:: @ 82FFE54
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE58:: @ 82FFE58
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE5C:: @ 82FFE5C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE60:: @ 82FFE60
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE64:: @ 82FFE64
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE68:: @ 82FFE68
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE6C:: @ 82FFE6C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE70:: @ 82FFE70
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE74:: @ 82FFE74
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE78:: @ 82FFE78
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE7C:: @ 82FFE7C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE80:: @ 82FFE80
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE84:: @ 82FFE84
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE88:: @ 82FFE88
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE8C:: @ 82FFE8C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE90:: @ 82FFE90
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE94:: @ 82FFE94
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE98:: @ 82FFE98
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFE9C:: @ 82FFE9C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEA0:: @ 82FFEA0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEA4:: @ 82FFEA4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEA8:: @ 82FFEA8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEAC:: @ 82FFEAC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEB0:: @ 82FFEB0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEB4:: @ 82FFEB4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEB8:: @ 82FFEB8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEBC:: @ 82FFEBC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEC0:: @ 82FFEC0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEC4:: @ 82FFEC4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEC8:: @ 82FFEC8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFECC:: @ 82FFECC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFED0:: @ 82FFED0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFED4:: @ 82FFED4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFED8:: @ 82FFED8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEDC:: @ 82FFEDC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEE0:: @ 82FFEE0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEE4:: @ 82FFEE4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEE8:: @ 82FFEE8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEEC:: @ 82FFEEC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEF0:: @ 82FFEF0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEF4:: @ 82FFEF4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEF8:: @ 82FFEF8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFEFC:: @ 82FFEFC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF00:: @ 82FFF00
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF04:: @ 82FFF04
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF08:: @ 82FFF08
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF0C:: @ 82FFF0C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF10:: @ 82FFF10
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF14:: @ 82FFF14
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF18:: @ 82FFF18
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF1C:: @ 82FFF1C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF20:: @ 82FFF20
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF24:: @ 82FFF24
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF28:: @ 82FFF28
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF2C:: @ 82FFF2C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF30:: @ 82FFF30
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF34:: @ 82FFF34
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF38:: @ 82FFF38
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF3C:: @ 82FFF3C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF40:: @ 82FFF40
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF44:: @ 82FFF44
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF48:: @ 82FFF48
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF4C:: @ 82FFF4C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF50:: @ 82FFF50
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF54:: @ 82FFF54
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF58:: @ 82FFF58
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF5C:: @ 82FFF5C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF60:: @ 82FFF60
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF64:: @ 82FFF64
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF68:: @ 82FFF68
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF6C:: @ 82FFF6C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF70:: @ 82FFF70
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF74:: @ 82FFF74
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF78:: @ 82FFF78
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF7C:: @ 82FFF7C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF80:: @ 82FFF80
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF84:: @ 82FFF84
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF88:: @ 82FFF88
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF8C:: @ 82FFF8C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF90:: @ 82FFF90
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF94:: @ 82FFF94
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF98:: @ 82FFF98
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFF9C:: @ 82FFF9C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFA0:: @ 82FFFA0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFA4:: @ 82FFFA4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFA8:: @ 82FFFA8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFAC:: @ 82FFFAC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFB0:: @ 82FFFB0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFB4:: @ 82FFFB4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFB8:: @ 82FFFB8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFBC:: @ 82FFFBC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFC0:: @ 82FFFC0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFC4:: @ 82FFFC4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFC8:: @ 82FFFC8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFCC:: @ 82FFFCC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFD0:: @ 82FFFD0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFD4:: @ 82FFFD4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFD8:: @ 82FFFD8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFDC:: @ 82FFFDC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFE0:: @ 82FFFE0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFE4:: @ 82FFFE4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFE8:: @ 82FFFE8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFEC:: @ 82FFFEC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFF0:: @ 82FFFF0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFF4:: @ 82FFFF4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFF8:: @ 82FFFF8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_082FFFFC:: @ 82FFFFC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300000:: @ 8300000
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300004:: @ 8300004
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300008:: @ 8300008
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830000C:: @ 830000C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300010:: @ 8300010
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300014:: @ 8300014
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300018:: @ 8300018
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830001C:: @ 830001C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300020:: @ 8300020
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300024:: @ 8300024
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300028:: @ 8300028
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830002C:: @ 830002C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300030:: @ 8300030
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300034:: @ 8300034
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300038:: @ 8300038
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830003C:: @ 830003C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300040:: @ 8300040
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300044:: @ 8300044
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300048:: @ 8300048
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830004C:: @ 830004C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300050:: @ 8300050
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300054:: @ 8300054
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300058:: @ 8300058
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830005C:: @ 830005C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300060:: @ 8300060
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300064:: @ 8300064
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300068:: @ 8300068
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830006C:: @ 830006C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300070:: @ 8300070
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300074:: @ 8300074
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300078:: @ 8300078
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830007C:: @ 830007C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300080:: @ 8300080
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300084:: @ 8300084
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300088:: @ 8300088
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830008C:: @ 830008C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300090:: @ 8300090
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300094:: @ 8300094
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300098:: @ 8300098
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830009C:: @ 830009C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000A0:: @ 83000A0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000A4:: @ 83000A4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000A8:: @ 83000A8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000AC:: @ 83000AC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000B0:: @ 83000B0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000B4:: @ 83000B4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000B8:: @ 83000B8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000BC:: @ 83000BC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000C0:: @ 83000C0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000C4:: @ 83000C4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000C8:: @ 83000C8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000CC:: @ 83000CC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000D0:: @ 83000D0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000D4:: @ 83000D4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000D8:: @ 83000D8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000DC:: @ 83000DC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000E0:: @ 83000E0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000E4:: @ 83000E4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000E8:: @ 83000E8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000EC:: @ 83000EC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000F0:: @ 83000F0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000F4:: @ 83000F4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000F8:: @ 83000F8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083000FC:: @ 83000FC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300100:: @ 8300100
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300104:: @ 8300104
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300108:: @ 8300108
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830010C:: @ 830010C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300110:: @ 8300110
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300114:: @ 8300114
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300118:: @ 8300118
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830011C:: @ 830011C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300120:: @ 8300120
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300124:: @ 8300124
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300128:: @ 8300128
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830012C:: @ 830012C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300130:: @ 8300130
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300134:: @ 8300134
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300138:: @ 8300138
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830013C:: @ 830013C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300140:: @ 8300140
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300144:: @ 8300144
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300148:: @ 8300148
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830014C:: @ 830014C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300150:: @ 8300150
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300154:: @ 8300154
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300158:: @ 8300158
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830015C:: @ 830015C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300160:: @ 8300160
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300164:: @ 8300164
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300168:: @ 8300168
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830016C:: @ 830016C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300170:: @ 8300170
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300174:: @ 8300174
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300178:: @ 8300178
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830017C:: @ 830017C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300180:: @ 8300180
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300184:: @ 8300184
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300188:: @ 8300188
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830018C:: @ 830018C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300190:: @ 8300190
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300194:: @ 8300194
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300198:: @ 8300198
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830019C:: @ 830019C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001A0:: @ 83001A0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001A4:: @ 83001A4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001A8:: @ 83001A8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001AC:: @ 83001AC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001B0:: @ 83001B0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001B4:: @ 83001B4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001B8:: @ 83001B8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001BC:: @ 83001BC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001C0:: @ 83001C0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001C4:: @ 83001C4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001C8:: @ 83001C8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001CC:: @ 83001CC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001D0: @ 83001D0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001D4:: @ 83001D4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF71C
	.4byte gUnknown_082FF734
	.4byte gUnknown_082FF744
	.4byte gUnknown_082FF750

	.align 2
gUnknown_083001E8:: @ 83001E8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083001EC:: @ 83001EC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF758
	.4byte gUnknown_082FF774
	.4byte gUnknown_082FF790

	.align 2
gUnknown_083001FC:: @ 83001FC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300200:: @ 8300200
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF79C
	.4byte gUnknown_082FF7B0

	.align 2
gUnknown_0830020C:: @ 830020C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF7C4

	.align 2
gUnknown_08300214:: @ 8300214
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF7CC

	.align 2
gUnknown_0830021C:: @ 830021C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF7D4

	.align 2
gUnknown_08300224:: @ 8300224
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF7DC
	.4byte gUnknown_082FF7E4

	.align 2
gUnknown_08300230:: @ 8300230
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF7EC
	.4byte gUnknown_082FF7F4

	.align 2
gUnknown_0830023C:: @ 830023C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF7FC
	.4byte gUnknown_082FF804

	.align 2
gUnknown_08300248:: @ 8300248
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF80C
	.4byte gUnknown_082FF814

	.align 2
gUnknown_08300254:: @ 8300254
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF81C
	.4byte gUnknown_082FF824

	.align 2
gUnknown_08300260:: @ 8300260
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300264:: @ 8300264
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF82C

	.align 2
gUnknown_0830026C:: @ 830026C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF834
	.4byte gUnknown_082FF83C

	.align 2
gUnknown_08300278:: @ 8300278
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF844

	.align 2
gUnknown_08300280:: @ 8300280
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF84C

	.align 2
gUnknown_08300288:: @ 8300288
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF854
	.4byte gUnknown_082FF85C

	.align 2
gUnknown_08300294:: @ 8300294
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300298:: @ 8300298
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830029C:: @ 830029C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083002A0:: @ 83002A0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF864

	.align 2
gUnknown_083002A8:: @ 83002A8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF86C

	.align 2
gUnknown_083002B0:: @ 83002B0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF874

	.align 2
gUnknown_083002B8:: @ 83002B8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF87C

	.align 2
gUnknown_083002C0:: @ 83002C0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083002C4:: @ 83002C4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF884

	.align 2
gUnknown_083002CC:: @ 83002CC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF88C
	.4byte gUnknown_082FF894

	.align 2
gUnknown_083002D8:: @ 83002D8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF89C
	.4byte gUnknown_082FF8A4

	.align 2
gUnknown_083002E4:: @ 83002E4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF8AC
	.4byte gUnknown_082FF8B4

	.align 2
gUnknown_083002F0:: @ 83002F0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF8BC
	.4byte gUnknown_082FF8FC
	.4byte gUnknown_082FF91C
	.4byte gUnknown_082FF930

	.align 2
gUnknown_08300304:: @ 8300304
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300308:: @ 8300308
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF93C

	.align 2
gUnknown_08300310:: @ 8300310
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF944

	.align 2
gUnknown_08300318:: @ 8300318
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FF94C
	.4byte gUnknown_082FF9A8
	.4byte gUnknown_082FFA00
	.4byte gUnknown_082FFA58

	.align 2
gUnknown_0830032C:: @ 830032C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFA64

	.align 2
gUnknown_08300334:: @ 8300334
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFA6C

	.align 2
gUnknown_0830033C:: @ 830033C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFA74

	.align 2
gUnknown_08300344:: @ 8300344
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300348:: @ 8300348
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFA7C
	.4byte gUnknown_082FFA84

	.align 2
gUnknown_08300354:: @ 8300354
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300358:: @ 8300358
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830035C:: @ 830035C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFA8C
	.4byte gUnknown_082FFA94

	.align 2
gUnknown_08300368:: @ 8300368
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830036C:: @ 830036C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300370:: @ 8300370
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFA9C
	.4byte gUnknown_082FFAA4

	.align 2
gUnknown_0830037C:: @ 830037C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFAAC
	.4byte gUnknown_082FFAB4

	.align 2
gUnknown_08300388:: @ 8300388
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFABC
	.4byte gUnknown_082FFAC4

	.align 2
gUnknown_08300394:: @ 8300394
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFACC
	.4byte gUnknown_082FFAD4

	.align 2
gUnknown_083003A0:: @ 83003A0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFADC

	.align 2
gUnknown_083003A8:: @ 83003A8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFAE4

	.align 2
gUnknown_083003B0:: @ 83003B0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFAEC

	.align 2
gUnknown_083003B8:: @ 83003B8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFAF4

	.align 2
gUnknown_083003C0:: @ 83003C0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFAFC

	.align 2
gUnknown_083003C8:: @ 83003C8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB04
	.4byte gUnknown_082FFB0C

	.align 2
gUnknown_083003D4:: @ 83003D4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB14

	.align 2
gUnknown_083003DC:: @ 83003DC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB1C
	.4byte gUnknown_082FFB24

	.align 2
gUnknown_083003E8:: @ 83003E8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB2C

	.align 2
gUnknown_083003F0:: @ 83003F0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB34

	.align 2
gUnknown_083003F8:: @ 83003F8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB3C

	.align 2
gUnknown_08300400:: @ 8300400
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB44
	.4byte gUnknown_082FFB60

	.align 2
gUnknown_0830040C:: @ 830040C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300410:: @ 8300410
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300414:: @ 8300414
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300418:: @ 8300418
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830041C:: @ 830041C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300420:: @ 8300420
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300424:: @ 8300424
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFB7C
	.4byte gUnknown_082FFBBC
	.4byte gUnknown_082FFBE0
	.4byte gUnknown_082FFBF4

	.align 2
gUnknown_08300438:: @ 8300438
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFBFC
	.4byte gUnknown_082FFC04

	.align 2
gUnknown_08300444:: @ 8300444
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC0C

	.align 2
gUnknown_0830044C:: @ 830044C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC14

	.align 2
gUnknown_08300454:: @ 8300454
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC1C

	.align 2
gUnknown_0830045C:: @ 830045C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC24

	.align 2
gUnknown_08300464:: @ 8300464
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC2C

	.align 2
gUnknown_0830046C:: @ 830046C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC34

	.align 2
gUnknown_08300474:: @ 8300474
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC3C
	.4byte gUnknown_082FFC58

	.align 2
gUnknown_08300480:: @ 8300480
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC74

	.align 2
gUnknown_08300488:: @ 8300488
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC7C
	.4byte gUnknown_082FFC84

	.align 2
gUnknown_08300494:: @ 8300494
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC8C
	.4byte gUnknown_082FFC94

	.align 2
gUnknown_083004A0:: @ 83004A0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFC9C
	.4byte gUnknown_082FFCA4

	.align 2
gUnknown_083004AC:: @ 83004AC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083004B0:: @ 83004B0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCAC

	.align 2
gUnknown_083004B8:: @ 83004B8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCB4

	.align 2
gUnknown_083004C0:: @ 83004C0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCBC

	.align 2
gUnknown_083004C8:: @ 83004C8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCC4

	.align 2
gUnknown_083004D0:: @ 83004D0
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCCC

	.align 2
gUnknown_083004D8:: @ 83004D8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCD4

	.align 2
gUnknown_083004E0:: @ 83004E0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083004E4:: @ 83004E4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083004E8:: @ 83004E8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083004EC:: @ 83004EC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCDC

	.align 2
gUnknown_083004F4:: @ 83004F4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083004F8:: @ 83004F8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083004FC:: @ 83004FC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCE4

	.align 2
gUnknown_08300504:: @ 8300504
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCEC
	.4byte gUnknown_082FFCF4

	.align 2
gUnknown_08300510:: @ 8300510
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFCFC

	.align 2
gUnknown_08300518:: @ 8300518
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830051C:: @ 830051C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300520:: @ 8300520
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300524:: @ 8300524
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD04

	.align 2
gUnknown_0830052C:: @ 830052C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD0C

	.align 2
gUnknown_08300534:: @ 8300534
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD14

	.align 2
gUnknown_0830053C:: @ 830053C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD1C
	.4byte gUnknown_082FFD24
	.4byte gUnknown_082FFD2C
	.4byte gUnknown_082FFD34

	.align 2
gUnknown_08300550:: @ 8300550
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD3C

	.align 2
gUnknown_08300558:: @ 8300558
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD44

	.align 2
gUnknown_08300560:: @ 8300560
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300564:: @ 8300564
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300568:: @ 8300568
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830056C:: @ 830056C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300570:: @ 8300570
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300574:: @ 8300574
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300578:: @ 8300578
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830057C:: @ 830057C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD4C
	.4byte gUnknown_082FFD54

	.align 2
gUnknown_08300588:: @ 8300588
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830058C:: @ 830058C
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD5C
	.4byte gUnknown_082FFD64

	.align 2
gUnknown_08300598:: @ 8300598
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830059C:: @ 830059C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005A0:: @ 83005A0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005A4:: @ 83005A4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD6C

	.align 2
gUnknown_083005AC:: @ 83005AC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD74

	.align 2
gUnknown_083005B4:: @ 83005B4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD7C
	.4byte gUnknown_082FFD84

	.align 2
gUnknown_083005C0:: @ 83005C0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005C4:: @ 83005C4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005C8:: @ 83005C8
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFD8C
	.4byte gUnknown_082FFDA0

	.align 2
gUnknown_083005D4:: @ 83005D4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005D8:: @ 83005D8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005DC:: @ 83005DC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_082FFDC4

	.align 2
gUnknown_083005E4:: @ 83005E4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005E8:: @ 83005E8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005EC:: @ 83005EC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005F0:: @ 83005F0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005F4:: @ 83005F4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005F8:: @ 83005F8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083005FC:: @ 83005FC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300600:: @ 8300600
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300604:: @ 8300604
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300608:: @ 8300608
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830060C:: @ 830060C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300610:: @ 8300610
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300614:: @ 8300614
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300618:: @ 8300618
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830061C:: @ 830061C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300620:: @ 8300620
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300624:: @ 8300624
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300628:: @ 8300628
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830062C:: @ 830062C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300630:: @ 8300630
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300634:: @ 8300634
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300638:: @ 8300638
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830063C:: @ 830063C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300640:: @ 8300640
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300644:: @ 8300644
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300648:: @ 8300648
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830064C:: @ 830064C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300650:: @ 8300650
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08300654:: @ 8300654
	.4byte gAnimCmd_General_Frame0

	.4byte gUnknown_082FFDCC
	.4byte gUnknown_082FFDD0
	.4byte gUnknown_082FFDD4
	.4byte gUnknown_082FFDD8
	.4byte gUnknown_082FFDDC
	.4byte gUnknown_082FFDE0
	.4byte gUnknown_082FFDE4
	.4byte gUnknown_082FFDE8
	.4byte gUnknown_082FFDEC
	.4byte gUnknown_082FFDF0
	.4byte gUnknown_082FFDF4
	.4byte gUnknown_082FFDF8
	.4byte gUnknown_082FFDFC
	.4byte gUnknown_082FFE00
	.4byte gUnknown_082FFE04
	.4byte gUnknown_082FFE08
	.4byte gUnknown_082FFE0C
	.4byte gUnknown_082FFE10
	.4byte gUnknown_082FFE14
	.4byte gUnknown_082FFE18
	.4byte gUnknown_082FFE1C
	.4byte gUnknown_082FFE20
	.4byte gUnknown_082FFE24
	.4byte gUnknown_082FFE28
	.4byte gUnknown_082FFE2C
	.4byte gUnknown_082FFE30
	.4byte gUnknown_082FFE34
	.4byte gUnknown_082FFE38
	.4byte gUnknown_082FFE3C
	.4byte gUnknown_082FFE40
	.4byte gUnknown_082FFE44
	.4byte gUnknown_082FFE48
	.4byte gUnknown_082FFE4C
	.4byte gUnknown_082FFE50
	.4byte gUnknown_082FFE54
	.4byte gUnknown_082FFE58
	.4byte gUnknown_082FFE5C
	.4byte gUnknown_082FFE60
	.4byte gUnknown_082FFE64
	.4byte gUnknown_082FFE68
	.4byte gUnknown_082FFE6C
	.4byte gUnknown_082FFE70
	.4byte gUnknown_082FFE74
	.4byte gUnknown_082FFE78
	.4byte gUnknown_082FFE7C
	.4byte gUnknown_082FFE80
	.4byte gUnknown_082FFE84
	.4byte gUnknown_082FFE88
	.4byte gUnknown_082FFE8C
	.4byte gUnknown_082FFE90
	.4byte gUnknown_082FFE94
	.4byte gUnknown_082FFE98
	.4byte gUnknown_082FFE9C
	.4byte gUnknown_082FFEA0
	.4byte gUnknown_082FFEA4
	.4byte gUnknown_082FFEA8
	.4byte gUnknown_082FFEAC
	.4byte gUnknown_082FFEB0
	.4byte gUnknown_082FFEB4
	.4byte gUnknown_082FFEB8
	.4byte gUnknown_082FFEBC
	.4byte gUnknown_082FFEC0
	.4byte gUnknown_082FFEC4
	.4byte gUnknown_082FFEC8
	.4byte gUnknown_082FFECC
	.4byte gUnknown_082FFED0
	.4byte gUnknown_082FFED4
	.4byte gUnknown_082FFED8
	.4byte gUnknown_082FFEDC
	.4byte gUnknown_082FFEE0
	.4byte gUnknown_082FFEE4
	.4byte gUnknown_082FFEE8
	.4byte gUnknown_082FFEEC
	.4byte gUnknown_082FFEF0
	.4byte gUnknown_082FFEF4
	.4byte gUnknown_082FFEF8
	.4byte gUnknown_082FFEFC
	.4byte gUnknown_082FFF00
	.4byte gUnknown_082FFF04
	.4byte gUnknown_082FFF08
	.4byte gUnknown_082FFF0C
	.4byte gUnknown_082FFF10
	.4byte gUnknown_082FFF14
	.4byte gUnknown_082FFF18
	.4byte gUnknown_082FFF1C
	.4byte gUnknown_082FFF20
	.4byte gUnknown_082FFF24
	.4byte gUnknown_082FFF28
	.4byte gUnknown_082FFF2C
	.4byte gUnknown_082FFF30
	.4byte gUnknown_082FFF34
	.4byte gUnknown_082FFF38
	.4byte gUnknown_082FFF3C
	.4byte gUnknown_082FFF40
	.4byte gUnknown_082FFF44
	.4byte gUnknown_082FFF48
	.4byte gUnknown_082FFF4C
	.4byte gUnknown_082FFF50
	.4byte gUnknown_082FFF54
	.4byte gUnknown_082FFF58
	.4byte gUnknown_082FFF5C
	.4byte gUnknown_082FFF60
	.4byte gUnknown_082FFF64
	.4byte gUnknown_082FFF68
	.4byte gUnknown_082FFF6C
	.4byte gUnknown_082FFF70
	.4byte gUnknown_082FFF74
	.4byte gUnknown_082FFF78
	.4byte gUnknown_082FFF7C
	.4byte gUnknown_082FFF80
	.4byte gUnknown_082FFF84
	.4byte gUnknown_082FFF88
	.4byte gUnknown_082FFF8C
	.4byte gUnknown_082FFF90
	.4byte gUnknown_082FFF94
	.4byte gUnknown_082FFF98
	.4byte gUnknown_082FFF9C
	.4byte gUnknown_082FFFA0
	.4byte gUnknown_082FFFA4
	.4byte gUnknown_082FFFA8
	.4byte gUnknown_082FFFAC
	.4byte gUnknown_082FFFB0
	.4byte gUnknown_082FFFB4
	.4byte gUnknown_082FFFB8
	.4byte gUnknown_082FFFBC
	.4byte gUnknown_082FFFC0
	.4byte gUnknown_082FFFC4
	.4byte gUnknown_082FFFC8
	.4byte gUnknown_082FFFCC
	.4byte gUnknown_082FFFD0
	.4byte gUnknown_082FFFD4
	.4byte gUnknown_082FFFD8
	.4byte gUnknown_082FFFDC
	.4byte gUnknown_082FFFE0
	.4byte gUnknown_082FFFE4
	.4byte gUnknown_082FFFE8
	.4byte gUnknown_082FFFEC
	.4byte gUnknown_082FFFF0
	.4byte gUnknown_082FFFF4
	.4byte gUnknown_082FFFF8
	.4byte gUnknown_082FFFFC
	.4byte gUnknown_08300000
	.4byte gUnknown_08300004
	.4byte gUnknown_08300008
	.4byte gUnknown_0830000C
	.4byte gUnknown_08300010
	.4byte gUnknown_08300014
	.4byte gUnknown_08300018
	.4byte gUnknown_0830001C
	.4byte gUnknown_08300020
	.4byte gUnknown_08300024
	.4byte gUnknown_08300028
	.4byte gUnknown_0830002C
	.4byte gUnknown_08300030
	.4byte gUnknown_08300034
	.4byte gUnknown_08300038
	.4byte gUnknown_0830003C
	.4byte gUnknown_08300040
	.4byte gUnknown_08300044
	.4byte gUnknown_08300048
	.4byte gUnknown_0830004C
	.4byte gUnknown_08300050
	.4byte gUnknown_08300054
	.4byte gUnknown_08300058
	.4byte gUnknown_0830005C
	.4byte gUnknown_08300060
	.4byte gUnknown_08300064
	.4byte gUnknown_08300068
	.4byte gUnknown_0830006C
	.4byte gUnknown_08300070
	.4byte gUnknown_08300074
	.4byte gUnknown_08300078
	.4byte gUnknown_0830007C
	.4byte gUnknown_08300080
	.4byte gUnknown_08300084
	.4byte gUnknown_08300088
	.4byte gUnknown_0830008C
	.4byte gUnknown_08300090
	.4byte gUnknown_08300094
	.4byte gUnknown_08300098
	.4byte gUnknown_0830009C
	.4byte gUnknown_083000A0
	.4byte gUnknown_083000A4
	.4byte gUnknown_083000A8
	.4byte gUnknown_083000AC
	.4byte gUnknown_083000B0
	.4byte gUnknown_083000B4
	.4byte gUnknown_083000B8
	.4byte gUnknown_083000BC
	.4byte gUnknown_083000C0
	.4byte gUnknown_083000C4
	.4byte gUnknown_083000C8
	.4byte gUnknown_083000CC
	.4byte gUnknown_083000D0
	.4byte gUnknown_083000D4
	.4byte gUnknown_083000D8
	.4byte gUnknown_083000DC
	.4byte gUnknown_083000E0
	.4byte gUnknown_083000E4
	.4byte gUnknown_083000E8
	.4byte gUnknown_083000EC
	.4byte gUnknown_083000F0
	.4byte gUnknown_083000F4
	.4byte gUnknown_083000F8
	.4byte gUnknown_083000FC
	.4byte gUnknown_08300100
	.4byte gUnknown_08300104
	.4byte gUnknown_08300108
	.4byte gUnknown_0830010C
	.4byte gUnknown_08300110
	.4byte gUnknown_08300114
	.4byte gUnknown_08300118
	.4byte gUnknown_0830011C
	.4byte gUnknown_08300120
	.4byte gUnknown_08300124
	.4byte gUnknown_08300128
	.4byte gUnknown_0830012C
	.4byte gUnknown_08300130
	.4byte gUnknown_08300134
	.4byte gUnknown_08300138
	.4byte gUnknown_0830013C
	.4byte gUnknown_08300140
	.4byte gUnknown_08300144
	.4byte gUnknown_08300148
	.4byte gUnknown_0830014C
	.4byte gUnknown_08300150
	.4byte gUnknown_08300154
	.4byte gUnknown_08300158
	.4byte gUnknown_0830015C
	.4byte gUnknown_08300160
	.4byte gUnknown_08300164
	.4byte gUnknown_08300168
	.4byte gUnknown_0830016C
	.4byte gUnknown_08300170
	.4byte gUnknown_08300174
	.4byte gUnknown_08300178
	.4byte gUnknown_0830017C
	.4byte gUnknown_08300180
	.4byte gUnknown_08300184
	.4byte gUnknown_08300188
	.4byte gUnknown_0830018C
	.4byte gUnknown_08300190
	.4byte gUnknown_08300194
	.4byte gUnknown_08300198
	.4byte gUnknown_0830019C
	.4byte gUnknown_083001A0
	.4byte gUnknown_083001A4
	.4byte gUnknown_083001A8
	.4byte gUnknown_083001AC
	.4byte gUnknown_083001B0
	.4byte gUnknown_083001B4
	.4byte gUnknown_083001B8
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001BC
	.4byte gUnknown_083001C0
	.4byte gUnknown_083001C4
	.4byte gUnknown_083001C8
	.4byte gUnknown_083001CC
	.4byte gUnknown_083001D0
	.4byte gUnknown_083001D4
	.4byte gUnknown_083001E8
	.4byte gUnknown_083001EC
	.4byte gUnknown_083001FC
	.4byte gUnknown_08300200
	.4byte gUnknown_0830020C
	.4byte gUnknown_08300214
	.4byte gUnknown_0830021C
	.4byte gUnknown_08300224
	.4byte gUnknown_08300230
	.4byte gUnknown_0830023C
	.4byte gUnknown_08300248
	.4byte gUnknown_08300254
	.4byte gUnknown_08300260
	.4byte gUnknown_08300264
	.4byte gUnknown_0830026C
	.4byte gUnknown_08300278
	.4byte gUnknown_08300280
	.4byte gUnknown_08300288
	.4byte gUnknown_08300294
	.4byte gUnknown_08300298
	.4byte gUnknown_0830029C
	.4byte gUnknown_083002A0
	.4byte gUnknown_083002A8
	.4byte gUnknown_083002B0
	.4byte gUnknown_083002B8
	.4byte gUnknown_083002C0
	.4byte gUnknown_083002C4
	.4byte gUnknown_083002CC
	.4byte gUnknown_083002D8
	.4byte gUnknown_083002E4
	.4byte gUnknown_083002F0
	.4byte gUnknown_08300304
	.4byte gUnknown_08300308
	.4byte gUnknown_08300310
	.4byte gUnknown_08300318
	.4byte gUnknown_0830032C
	.4byte gUnknown_08300334
	.4byte gUnknown_0830033C
	.4byte gUnknown_08300344
	.4byte gUnknown_08300348
	.4byte gUnknown_08300354
	.4byte gUnknown_08300358
	.4byte gUnknown_0830035C
	.4byte gUnknown_08300368
	.4byte gUnknown_0830036C
	.4byte gUnknown_08300370
	.4byte gUnknown_0830037C
	.4byte gUnknown_08300388
	.4byte gUnknown_08300394
	.4byte gUnknown_083003A0
	.4byte gUnknown_083003A8
	.4byte gUnknown_083003B0
	.4byte gUnknown_083003B8
	.4byte gUnknown_083003C0
	.4byte gUnknown_083003C8
	.4byte gUnknown_083003D4
	.4byte gUnknown_083003DC
	.4byte gUnknown_083003E8
	.4byte gUnknown_083003F0
	.4byte gUnknown_083003F8
	.4byte gUnknown_08300400
	.4byte gUnknown_0830040C
	.4byte gUnknown_08300410
	.4byte gUnknown_08300414
	.4byte gUnknown_08300418
	.4byte gUnknown_0830041C
	.4byte gUnknown_08300420
	.4byte gUnknown_08300424
	.4byte gUnknown_08300438
	.4byte gUnknown_08300444
	.4byte gUnknown_0830044C
	.4byte gUnknown_08300454
	.4byte gUnknown_0830045C
	.4byte gUnknown_08300464
	.4byte gUnknown_0830046C
	.4byte gUnknown_08300474
	.4byte gUnknown_08300480
	.4byte gUnknown_08300488
	.4byte gUnknown_08300494
	.4byte gUnknown_083004A0
	.4byte gUnknown_083004AC
	.4byte gUnknown_083004B0
	.4byte gUnknown_083004B8
	.4byte gUnknown_083004C0
	.4byte gUnknown_083004C8
	.4byte gUnknown_083004D0
	.4byte gUnknown_083004D8
	.4byte gUnknown_083004E0
	.4byte gUnknown_083004E4
	.4byte gUnknown_083004E8
	.4byte gUnknown_083004EC
	.4byte gUnknown_083004F4
	.4byte gUnknown_083004F8
	.4byte gUnknown_083004FC
	.4byte gUnknown_08300504
	.4byte gUnknown_08300510
	.4byte gUnknown_08300518
	.4byte gUnknown_0830051C
	.4byte gUnknown_08300520
	.4byte gUnknown_08300524
	.4byte gUnknown_0830052C
	.4byte gUnknown_08300534
	.4byte gUnknown_0830053C
	.4byte gUnknown_08300550
	.4byte gUnknown_08300558
	.4byte gUnknown_08300560
	.4byte gUnknown_08300564
	.4byte gUnknown_08300568
	.4byte gUnknown_0830056C
	.4byte gUnknown_08300570
	.4byte gUnknown_08300574
	.4byte gUnknown_08300578
	.4byte gUnknown_0830057C
	.4byte gUnknown_08300588
	.4byte gUnknown_0830058C
	.4byte gUnknown_08300598
	.4byte gUnknown_0830059C
	.4byte gUnknown_083005A0
	.4byte gUnknown_083005A4
	.4byte gUnknown_083005AC
	.4byte gUnknown_083005B4
	.4byte gUnknown_083005C0
	.4byte gUnknown_083005C4
	.4byte gUnknown_083005C8
	.4byte gUnknown_083005D4
	.4byte gUnknown_083005D8
	.4byte gUnknown_083005DC
	.4byte gUnknown_083005E4
	.4byte gUnknown_083005E8
	.4byte gUnknown_083005EC
	.4byte gUnknown_083005EC
	.4byte gUnknown_083005F0
	.4byte gUnknown_083005F4
	.4byte gUnknown_083005F8
	.4byte gUnknown_083005FC
	.4byte gUnknown_08300600
	.4byte gUnknown_08300604
	.4byte gUnknown_08300608
	.4byte gUnknown_0830060C
	.4byte gUnknown_08300610
	.4byte gUnknown_08300614
	.4byte gUnknown_08300618
	.4byte gUnknown_0830061C
	.4byte gUnknown_08300620
	.4byte gUnknown_08300624
	.4byte gUnknown_08300628
	.4byte gUnknown_0830062C
	.4byte gUnknown_08300630
	.4byte gUnknown_08300634
	.4byte gUnknown_08300638
	.4byte gUnknown_0830063C
	.4byte gUnknown_08300640
	.4byte gUnknown_08300644
	.4byte gUnknown_08300648
	.4byte gUnknown_0830064C
	.4byte gUnknown_08300650
	.4byte gUnknown_08300654

	.align 2
gMonFrontPicCoords:: @ 8300D38
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x45, 0x0e, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x45, 0x10, 0x00, 0x00
	.byte 0x54, 0x14, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x54, 0x12, 0x00, 0x00
	.byte 0x45, 0x0e, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x67, 0x0b, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x44, 0x10, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x45, 0x0f, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x67, 0x09, 0x00, 0x00
	.byte 0x67, 0x04, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x45, 0x0f, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x78, 0x02, 0x00, 0x00
	.byte 0x55, 0x10, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x45, 0x10, 0x00, 0x00
	.byte 0x67, 0x08, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x45, 0x0f, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x54, 0x12, 0x00, 0x00
	.byte 0x75, 0x0d, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x56, 0x09, 0x00, 0x00
	.byte 0x78, 0x02, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x74, 0x13, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x65, 0x0f, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x54, 0x12, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x43, 0x15, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x57, 0x05, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x55, 0x10, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x78, 0x02, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x44, 0x13, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x67, 0x04, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x45, 0x0f, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x78, 0x02, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x88, 0x08, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x54, 0x11, 0x00, 0x00
	.byte 0x56, 0x09, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x55, 0x0d, 0x00, 0x00
	.byte 0x45, 0x0f, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x54, 0x11, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x75, 0x0e, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0d, 0x00, 0x00
	.byte 0x75, 0x0d, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x47, 0x04, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x55, 0x0d, 0x00, 0x00
	.byte 0x58, 0x03, 0x00, 0x00
	.byte 0x56, 0x0c, 0x00, 0x00
	.byte 0x67, 0x04, 0x00, 0x00
	.byte 0x54, 0x13, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x75, 0x10, 0x00, 0x00
	.byte 0x87, 0x0b, 0x00, 0x00
	.byte 0x45, 0x0c, 0x00, 0x00
	.byte 0x44, 0x14, 0x00, 0x00
	.byte 0x44, 0x12, 0x00, 0x00
	.byte 0x34, 0x14, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00
	.byte 0x44, 0x14, 0x00, 0x00
	.byte 0x47, 0x07, 0x00, 0x00
	.byte 0x55, 0x10, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x45, 0x0e, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x58, 0x03, 0x00, 0x00
	.byte 0x44, 0x10, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x54, 0x10, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x67, 0x08, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x58, 0x01, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x35, 0x0f, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x74, 0x11, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0d, 0x00, 0x00
	.byte 0x57, 0x06, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x45, 0x0d, 0x00, 0x00
	.byte 0x78, 0x01, 0x00, 0x00
	.byte 0x45, 0x0d, 0x00, 0x00
	.byte 0x57, 0x0d, 0x00, 0x00
	.byte 0x43, 0x14, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x78, 0x04, 0x00, 0x00
	.byte 0x54, 0x10, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x35, 0x0f, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x45, 0x0d, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00
	.byte 0x56, 0x09, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x56, 0x0c, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x85, 0x0f, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x45, 0x0e, 0x00, 0x00
	.byte 0x75, 0x11, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x74, 0x10, 0x00, 0x00
	.byte 0x86, 0x0f, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x46, 0x10, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x74, 0x12, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x64, 0x10, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x54, 0x10, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x68, 0x08, 0x00, 0x00
	.byte 0x84, 0x18, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x65, 0x0f, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x75, 0x0f, 0x00, 0x00
	.byte 0x87, 0x0a, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x55, 0x10, 0x00, 0x00
	.byte 0x78, 0x06, 0x00, 0x00
	.byte 0x56, 0x0c, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x46, 0x0b, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x46, 0x18, 0x00, 0x00
	.byte 0x66, 0x0c, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x46, 0x0d, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x54, 0x10, 0x00, 0x00
	.byte 0x86, 0x0c, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x64, 0x12, 0x00, 0x00
	.byte 0x67, 0x04, 0x00, 0x00
	.byte 0x65, 0x0f, 0x00, 0x00
	.byte 0x87, 0x09, 0x00, 0x00
	.byte 0x65, 0x10, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x74, 0x10, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x56, 0x0e, 0x00, 0x00
	.byte 0x66, 0x0c, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x68, 0x01, 0x00, 0x00
	.byte 0x76, 0x11, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x74, 0x12, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x55, 0x12, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x68, 0x00, 0x00, 0x00
	.byte 0x56, 0x0e, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x77, 0x08, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x77, 0x0b, 0x00, 0x00
	.byte 0x43, 0x14, 0x00, 0x00
	.byte 0x75, 0x0d, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x34, 0x11, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x35, 0x0f, 0x00, 0x00
	.byte 0x47, 0x06, 0x00, 0x00
	.byte 0x78, 0x01, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x78, 0x04, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x66, 0x0d, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x37, 0x06, 0x00, 0x00
	.byte 0x33, 0x14, 0x00, 0x00
	.byte 0x34, 0x10, 0x00, 0x00
	.byte 0x44, 0x10, 0x00, 0x00
	.byte 0x44, 0x10, 0x00, 0x00
	.byte 0x44, 0x11, 0x00, 0x00
	.byte 0x44, 0x11, 0x00, 0x00
	.byte 0x35, 0x0e, 0x00, 0x00
	.byte 0x44, 0x10, 0x00, 0x00
	.byte 0x34, 0x10, 0x00, 0x00
	.byte 0x34, 0x11, 0x00, 0x00
	.byte 0x44, 0x11, 0x00, 0x00
	.byte 0x34, 0x13, 0x00, 0x00
	.byte 0x44, 0x13, 0x00, 0x00
	.byte 0x43, 0x14, 0x00, 0x00
	.byte 0x44, 0x10, 0x00, 0x00
	.byte 0x34, 0x13, 0x00, 0x00
	.byte 0x43, 0x15, 0x00, 0x00
	.byte 0x34, 0x13, 0x00, 0x00
	.byte 0x45, 0x0c, 0x00, 0x00
	.byte 0x34, 0x12, 0x00, 0x00
	.byte 0x44, 0x12, 0x00, 0x00
	.byte 0x44, 0x12, 0x00, 0x00
	.byte 0x44, 0x13, 0x00, 0x00
	.byte 0x33, 0x15, 0x00, 0x00
	.byte 0x34, 0x11, 0x00, 0x00
	.byte 0x34, 0x10, 0x00, 0x00
	.byte 0x35, 0x0f, 0x00, 0x00
	.byte 0x35, 0x0d, 0x00, 0x00

@ 8301418
	.include "data/graphics/pokemon/still_front_pic_table.inc"

	.align 2
gUnknown_083021D8:: @ 83021D8
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x64, 0x10, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x46, 0x0a, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x85, 0x0c, 0x00, 0x00
	.byte 0x78, 0x02, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x75, 0x0d, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x63, 0x14, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x54, 0x10, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x74, 0x10, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x67, 0x04, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x75, 0x0c, 0x00, 0x00
	.byte 0x84, 0x10, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x43, 0x14, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x75, 0x0c, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x55, 0x0e, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x85, 0x0c, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x54, 0x11, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x78, 0x01, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x68, 0x03, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x73, 0x15, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x65, 0x0f, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x54, 0x10, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x54, 0x11, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x75, 0x0c, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x85, 0x0f, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x66, 0x09, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x36, 0x08, 0x00, 0x00
	.byte 0x75, 0x0c, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x65, 0x0f, 0x00, 0x00
	.byte 0x84, 0x10, 0x00, 0x00
	.byte 0x85, 0x0f, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x63, 0x15, 0x00, 0x00
	.byte 0x75, 0x0d, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x75, 0x0d, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x55, 0x0c, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x65, 0x0e, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x56, 0x09, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x67, 0x05, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x76, 0x09, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x85, 0x0f, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x83, 0x15, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x73, 0x14, 0x00, 0x00
	.byte 0x83, 0x14, 0x00, 0x00
	.byte 0x75, 0x0f, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x83, 0x14, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x64, 0x11, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x88, 0x00, 0x00, 0x00
	.byte 0x83, 0x15, 0x00, 0x00
	.byte 0x83, 0x16, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x85, 0x0c, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x46, 0x0a, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x67, 0x07, 0x00, 0x00
	.byte 0x68, 0x02, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x75, 0x0e, 0x00, 0x00
	.byte 0x74, 0x11, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x84, 0x10, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x86, 0x0b, 0x00, 0x00
	.byte 0x84, 0x13, 0x00, 0x00
	.byte 0x64, 0x12, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x85, 0x0f, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x76, 0x0a, 0x00, 0x00
	.byte 0x85, 0x0c, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x87, 0x04, 0x00, 0x00
	.byte 0x76, 0x0b, 0x00, 0x00
	.byte 0x68, 0x03, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x87, 0x06, 0x00, 0x00
	.byte 0x77, 0x07, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x85, 0x0f, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x86, 0x08, 0x00, 0x00
	.byte 0x66, 0x0b, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x68, 0x02, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x78, 0x03, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x65, 0x0c, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x88, 0x01, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x54, 0x11, 0x00, 0x00
	.byte 0x84, 0x11, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x45, 0x0d, 0x00, 0x00
	.byte 0x76, 0x08, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x83, 0x17, 0x00, 0x00
	.byte 0x77, 0x05, 0x00, 0x00
	.byte 0x45, 0x0d, 0x00, 0x00
	.byte 0x57, 0x06, 0x00, 0x00
	.byte 0x77, 0x04, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x85, 0x0d, 0x00, 0x00
	.byte 0x77, 0x06, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x84, 0x10, 0x00, 0x00
	.byte 0x83, 0x14, 0x00, 0x00
	.byte 0x86, 0x0a, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x85, 0x0e, 0x00, 0x00
	.byte 0x84, 0x13, 0x00, 0x00
	.byte 0x87, 0x07, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00
	.byte 0x88, 0x02, 0x00, 0x00
	.byte 0x88, 0x03, 0x00, 0x00
	.byte 0x87, 0x05, 0x00, 0x00
	.byte 0x86, 0x09, 0x00, 0x00
	.byte 0x47, 0x07, 0x00, 0x00
	.byte 0x36, 0x0a, 0x00, 0x00
	.byte 0x56, 0x09, 0x00, 0x00
	.byte 0x67, 0x06, 0x00, 0x00
	.byte 0x56, 0x08, 0x00, 0x00
	.byte 0x56, 0x0a, 0x00, 0x00
	.byte 0x66, 0x0a, 0x00, 0x00
	.byte 0x57, 0x05, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x37, 0x07, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00
	.byte 0x57, 0x07, 0x00, 0x00
	.byte 0x46, 0x0a, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x66, 0x08, 0x00, 0x00
	.byte 0x46, 0x0a, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x45, 0x0c, 0x00, 0x00
	.byte 0x57, 0x04, 0x00, 0x00
	.byte 0x45, 0x0d, 0x00, 0x00
	.byte 0x65, 0x0d, 0x00, 0x00
	.byte 0x56, 0x0b, 0x00, 0x00
	.byte 0x55, 0x0d, 0x00, 0x00
	.byte 0x55, 0x0f, 0x00, 0x00
	.byte 0x46, 0x0a, 0x00, 0x00
	.byte 0x46, 0x0a, 0x00, 0x00
	.byte 0x37, 0x06, 0x00, 0x00
	.byte 0x47, 0x06, 0x00, 0x00

@ 83028B8
	.include "data/graphics/pokemon/back_pic_table.inc"

@ 8303678
	.include "data/graphics/pokemon/palette_table.inc"

@ 8304438
	.include "data/graphics/pokemon/shiny_palette_table.inc"

gUnknown_083051F8:: @ 83051F8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083051FC:: @ 83051FC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305200:: @ 8305200
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305204:: @ 8305204
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305208:: @ 8305208
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830520C:: @ 830520C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305210:: @ 8305210
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305214:: @ 8305214
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305218:: @ 8305218
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830521C:: @ 830521C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305220:: @ 8305220
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305224:: @ 8305224
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305228:: @ 8305228
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830522C:: @ 830522C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305230:: @ 8305230
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305234:: @ 8305234
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305238:: @ 8305238
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830523C:: @ 830523C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305240:: @ 8305240
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305244:: @ 8305244
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305248:: @ 8305248
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830524C:: @ 830524C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305250:: @ 8305250
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305254:: @ 8305254
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305258:: @ 8305258
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830525C:: @ 830525C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305260:: @ 8305260
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305264:: @ 8305264
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305268:: @ 8305268
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830526C:: @ 830526C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305270:: @ 8305270
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305274:: @ 8305274
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305278:: @ 8305278
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830527C:: @ 830527C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305280:: @ 8305280
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305284:: @ 8305284
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305288:: @ 8305288
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830528C:: @ 830528C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305290:: @ 8305290
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305294:: @ 8305294
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305298:: @ 8305298
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830529C:: @ 830529C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052A0:: @ 83052A0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052A4:: @ 83052A4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052A8:: @ 83052A8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052AC:: @ 83052AC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052B0:: @ 83052B0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052B4:: @ 83052B4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052B8:: @ 83052B8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052BC:: @ 83052BC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052C0:: @ 83052C0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052C4:: @ 83052C4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052C8:: @ 83052C8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052CC:: @ 83052CC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052D0:: @ 83052D0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052D4:: @ 83052D4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052D8:: @ 83052D8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052DC:: @ 83052DC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052E0:: @ 83052E0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052E4:: @ 83052E4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052E8:: @ 83052E8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052EC:: @ 83052EC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052F0:: @ 83052F0
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052F4:: @ 83052F4
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052F8:: @ 83052F8
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_083052FC:: @ 83052FC
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305300:: @ 8305300
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305304:: @ 8305304
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305308:: @ 8305308
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830530C:: @ 830530C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305310:: @ 8305310
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305314:: @ 8305314
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305318:: @ 8305318
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830531C:: @ 830531C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305320:: @ 8305320
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305324:: @ 8305324
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305328:: @ 8305328
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830532C:: @ 830532C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305330:: @ 8305330
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305334:: @ 8305334
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305338:: @ 8305338
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830533C:: @ 830533C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305340:: @ 8305340
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305344:: @ 8305344
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305348:: @ 8305348
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830534C:: @ 830534C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305350:: @ 8305350
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305354:: @ 8305354
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305358:: @ 8305358
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830535C:: @ 830535C
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305360:: @ 8305360
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305364:: @ 8305364
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_08305368:: @ 8305368
	.4byte gAnimCmd_General_Frame0

	.align 2
gUnknown_0830536C:: @ 830536C
	.4byte gUnknown_083051F8
	.4byte gUnknown_083051FC
	.4byte gUnknown_08305200
	.4byte gUnknown_08305204
	.4byte gUnknown_08305208
	.4byte gUnknown_0830520C
	.4byte gUnknown_08305210
	.4byte gUnknown_08305214
	.4byte gUnknown_08305218
	.4byte gUnknown_0830521C
	.4byte gUnknown_08305220
	.4byte gUnknown_08305224
	.4byte gUnknown_08305228
	.4byte gUnknown_0830522C
	.4byte gUnknown_08305230
	.4byte gUnknown_08305234
	.4byte gUnknown_08305238
	.4byte gUnknown_0830523C
	.4byte gUnknown_08305240
	.4byte gUnknown_08305244
	.4byte gUnknown_08305248
	.4byte gUnknown_0830524C
	.4byte gUnknown_08305250
	.4byte gUnknown_08305254
	.4byte gUnknown_08305258
	.4byte gUnknown_0830525C
	.4byte gUnknown_08305260
	.4byte gUnknown_08305264
	.4byte gUnknown_08305268
	.4byte gUnknown_0830526C
	.4byte gUnknown_08305270
	.4byte gUnknown_08305274
	.4byte gUnknown_08305278
	.4byte gUnknown_0830527C
	.4byte gUnknown_08305280
	.4byte gUnknown_08305284
	.4byte gUnknown_08305288
	.4byte gUnknown_0830528C
	.4byte gUnknown_08305290
	.4byte gUnknown_08305294
	.4byte gUnknown_08305298
	.4byte gUnknown_0830529C
	.4byte gUnknown_083052A0
	.4byte gUnknown_083052A4
	.4byte gUnknown_083052A8
	.4byte gUnknown_083052AC
	.4byte gUnknown_083052B0
	.4byte gUnknown_083052B4
	.4byte gUnknown_083052B8
	.4byte gUnknown_083052BC
	.4byte gUnknown_083052C0
	.4byte gUnknown_083052C4
	.4byte gUnknown_083052C8
	.4byte gUnknown_083052CC
	.4byte gUnknown_083052D0
	.4byte gUnknown_083052D4
	.4byte gUnknown_083052D8
	.4byte gUnknown_083052DC
	.4byte gUnknown_083052E0
	.4byte gUnknown_083052E4
	.4byte gUnknown_083052E8
	.4byte gUnknown_083052EC
	.4byte gUnknown_083052F0
	.4byte gUnknown_083052F4
	.4byte gUnknown_083052F8
	.4byte gUnknown_083052FC
	.4byte gUnknown_08305300
	.4byte gUnknown_08305304
	.4byte gUnknown_08305308
	.4byte gUnknown_0830530C
	.4byte gUnknown_08305310
	.4byte gUnknown_08305314
	.4byte gUnknown_08305318
	.4byte gUnknown_0830531C
	.4byte gUnknown_08305320
	.4byte gUnknown_08305324
	.4byte gUnknown_08305328
	.4byte gUnknown_0830532C
	.4byte gUnknown_08305330
	.4byte gUnknown_08305334
	.4byte gUnknown_08305338
	.4byte gUnknown_0830533C
	.4byte gUnknown_08305340
	.4byte gUnknown_08305344
	.4byte gUnknown_08305348
	.4byte gUnknown_0830534C
	.4byte gUnknown_08305350
	.4byte gUnknown_08305354
	.4byte gUnknown_08305358
	.4byte gUnknown_0830535C
	.4byte gUnknown_08305360
	.4byte gUnknown_08305364
	.4byte gUnknown_08305368

@ 83054E0
	.include "data/graphics/trainers/front_pic_coords.inc"

@ 8305654
	.include "data/graphics/trainers/front_pic_table.inc"

@ 830593C
	.include "data/graphics/trainers/front_pic_palette_table.inc"

gUnknown_08305C24:: @ 8305C24
	.2byte 0x0000, 0x0018, 0x0001, 0x0009, 0x0002, 0x0018, 0x0000, 0x0009
	.2byte 0x0003, 0x0032, 0xffff, 0x0000

	.align 2
gUnknown_08305C3C:: @ 8305C3C
	.2byte 0x0000, 0x0018, 0x0001, 0x0009, 0x0002, 0x0018, 0x0000, 0x0009
	.2byte 0x0003, 0x0032, 0xffff, 0x0000

	.align 2
gUnknown_08305C54:: @ 8305C54
	.2byte 0x0000, 0x0018, 0x0001, 0x0009, 0x0002, 0x0018, 0x0000, 0x0009
	.2byte 0x0003, 0x0032, 0xffff, 0x0000

	.align 2
gUnknown_08305C6C:: @ 8305C6C
	.2byte 0x0001, 0x0014, 0x0002, 0x0006, 0x0003, 0x0006, 0x0004, 0x0018
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08305C84:: @ 8305C84
	.2byte 0x0001, 0x0014, 0x0002, 0x0006, 0x0003, 0x0006, 0x0004, 0x0018
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08305C9C:: @ 8305C9C
	.2byte 0x0000, 0x0018, 0x0001, 0x0009, 0x0002, 0x0018, 0x0000, 0x0009
	.2byte 0x0003, 0x0032, 0xffff, 0x0000

	.align 2
gUnknown_08305CB4:: @ 8305CB4
	.2byte 0x0000, 0x0018, 0x0001, 0x0009, 0x0002, 0x0018, 0x0000, 0x0009
	.2byte 0x0003, 0x0032, 0xffff, 0x0000

	.align 2
gUnknown_08305CCC:: @ 8305CCC
	.4byte AnimCmd_82FF540
	.4byte gUnknown_08305C24

	.align 2
gUnknown_08305CD4:: @ 8305CD4
	.4byte AnimCmd_82FF540
	.4byte gUnknown_08305C3C

	.align 2
gUnknown_08305CDC:: @ 8305CDC
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_08305C6C

	.align 2
gUnknown_08305CE4:: @ 8305CE4
	.4byte gAnimCmd_General_Frame0
	.4byte gUnknown_08305C84

	.align 2
gUnknown_08305CEC:: @ 8305CEC
	.4byte AnimCmd_82FF540
	.4byte gUnknown_08305C9C

	.align 2
gUnknown_08305CF4:: @ 8305CF4
	.4byte AnimCmd_82FF540
	.4byte gUnknown_08305CB4

	.align 2
gUnknown_08305CFC:: @ 8305CFC
	.4byte AnimCmd_82FF540
	.4byte gUnknown_08305C54

	.align 2
gUnknown_08305D04:: @ 8305D04
	.4byte AnimCmd_82FF540
	.4byte gUnknown_08305C3C

	.align 2
gUnknown_08305D0C:: @ 8305D0C
	.4byte gUnknown_08305CCC
	.4byte gUnknown_08305CD4
	.4byte gUnknown_08305CDC
	.4byte gUnknown_08305CE4
	.4byte gUnknown_08305CEC
	.4byte gUnknown_08305CF4
	.4byte gUnknown_08305CFC
	.4byte gUnknown_08305D04


@ 8305D2C
	.include "data/graphics/trainers/back_pic_coords.inc"

@ 8305D4C
	.include "data/graphics/trainers/back_pic_table.inc"

@ 8305D8C
	.include "data/graphics/trainers/back_pic_palette_table.inc"

@ 8305DCC
	.include "data/enemy_mon_elevation.inc"

@ 8305F68
	.include "data/graphics/pokemon/front_anims.inc"

@ 830A18C
	.include "data/graphics/pokemon/front_pic_table.inc"

@ 830AF4C
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000088, 0x00000888, 0x00000888, 0x00000886
	.4byte 0x00000888, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000886, 0x00000886
	.4byte 0x00000888, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000888, 0x00000886, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000886, 0x00000886
	.4byte 0x00000888, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000886, 0x00000886, 0x00000088
	.4byte 0x00000886, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000886, 0x00000888, 0x00000088, 0x00000088
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000886
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000886
	.4byte 0x00000886, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000886, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000886, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000886, 0x00000886, 0x00000888
	.4byte 0x00000886, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000088, 0x00000088, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000886, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000088, 0x00000886
	.4byte 0x00000888, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000888, 0x00000886, 0x00000888
	.4byte 0x00000088, 0x00000088, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000088, 0x00000888, 0x00000886
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000088
	.4byte 0x00000888, 0x00000886, 0x00000886, 0x00000888
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000886
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000088, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000088, 0x00000888, 0x00000888, 0x00000886
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000886
	.4byte 0x00000888, 0x00000886, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000888, 0x00000088, 0x00000888
	.4byte 0x00000888, 0x00000088, 0x00000088, 0x00000888
	.4byte 0x00000886, 0x00000888, 0x00000886, 0x00000886
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000088, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000088, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000088, 0x00000088
	.4byte 0x00000886, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000088, 0x00000888
	.4byte 0x00000886, 0x00000888, 0x00000088, 0x00000088
	.4byte 0x00000888, 0x00000888, 0x00000088, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000088
	.4byte 0x00000888, 0x00000888, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000888, 0x00000088, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000886
	.4byte 0x00000088, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000886, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000886
	.4byte 0x00000886, 0x00000886, 0x00000888, 0x00000888
	.4byte 0x00000886, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000088, 0x00000886, 0x00000886
	.4byte 0x00001882, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000886, 0x00000088, 0x00000886, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000886
	.4byte 0x00000886, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000886, 0x00000088
	.4byte 0x00000088, 0x00000886, 0x00000886, 0x00000886
	.4byte 0x00000886, 0x00000886, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000886
	.4byte 0x00000886, 0x00000886, 0x00000886, 0x00000088
	.4byte 0x00000886, 0x00000088, 0x00000886, 0x00000886
	.4byte 0x00000886, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000886, 0x00000886
	.4byte 0x00000886, 0x00000888, 0x00000886, 0x00000886
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000886, 0x00000886, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000088, 0x00000088, 0x00000088
	.4byte 0x00000088, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888
	.4byte 0x00000888, 0x00000888, 0x00000888, 0x00000888

@ 830B62C
	.include "data/trainer_parties.inc"

@ 830FCD4
	.include "data/text/trainer_class_names.inc"

@ 8310030
	.include "data/trainers.inc"

@ 83185C8
	.include "data/text/species_names.inc"

@ 831977C
	.include "data/text/move_names.inc"

.align 2
	.2byte 0x0300, 0x0000

	.align 2
gUnknown_0831A988:: @ 831A988
	.byte 0x00, 0x03, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_0831A990:: @ 831A990
	.byte 0x00, 0x03, 0x00, 0xc0, 0x40, 0x00, 0x00, 0x00

	.align 2
gUnknown_0831A998:: @ 831A998
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0831A9A8:: @ 831A9A8
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x0018, 0x0018, 0x8000, 0x0000
	.2byte 0x0018, 0x0018, 0x8000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0831A9C8:: @ 831A9C8
	.4byte gUnknown_0831A998
	.4byte gUnknown_0831A9A8

	.align 2
gUnknown_0831A9D0:: @ 831A9D0
	spr_template 0x2710, 0x2710, gUnknown_0831A988, gDummySpriteAnimTable, NULL, gUnknown_0831A9C8, nullsub_17

	.align 2
gUnknown_0831A9E8:: @ 831A9E8
	spr_template 0x2710, 0x2710, gUnknown_0831A990, gDummySpriteAnimTable, NULL, gUnknown_0831A9C8, nullsub_17

	.align 2
gUnknown_0831AA00:: @ 831AA00
	obj_tiles gUnknown_08D77B0C, 0x1000, 0x2710

	.align 2
gUnknown_0831AA08:: @ 831AA08
	.4byte 0x00000580, 0x000005c5, 0x000013e6, 0x000033ab

	.align 2
gUnknown_0831AA18:: @ 831AA18
	window_template 0x00, 0x02, 0x0f, 0x1a, 0x04, 0x00, 0x0090
	window_template 0x00, 0x01, 0x23, 0x0e, 0x04, 0x00, 0x01c0
	window_template 0x00, 0x11, 0x23, 0x0c, 0x04, 0x05, 0x0190
	window_template 0x00, 0x02, 0x37, 0x08, 0x02, 0x05, 0x0300
	window_template 0x00, 0x0b, 0x37, 0x08, 0x02, 0x05, 0x0310
	window_template 0x00, 0x02, 0x39, 0x08, 0x02, 0x05, 0x0320
	window_template 0x00, 0x0b, 0x39, 0x08, 0x02, 0x05, 0x0330
	window_template 0x00, 0x15, 0x37, 0x04, 0x02, 0x05, 0x0290
	window_template 0x00, 0x15, 0x39, 0x00, 0x00, 0x05, 0x0298
	window_template 0x00, 0x19, 0x37, 0x04, 0x02, 0x05, 0x0298
	window_template 0x00, 0x15, 0x39, 0x08, 0x02, 0x05, 0x02a0
	window_template 0x00, 0x15, 0x37, 0x08, 0x04, 0x05, 0x02b0
	window_template 0x00, 0x1a, 0x09, 0x03, 0x04, 0x05, 0x0100
	window_template 0x01, 0x13, 0x08, 0x0a, 0x0b, 0x05, 0x0100
	window_template 0x02, 0x12, 0x00, 0x0c, 0x03, 0x06, 0x016e
	window_template 0x01, 0x02, 0x03, 0x06, 0x02, 0x05, 0x0020
	window_template 0x02, 0x02, 0x03, 0x06, 0x02, 0x05, 0x0040
	window_template 0x01, 0x02, 0x02, 0x06, 0x02, 0x05, 0x0020
	window_template 0x02, 0x02, 0x02, 0x06, 0x02, 0x05, 0x0040
	window_template 0x01, 0x02, 0x06, 0x06, 0x02, 0x05, 0x0060
	window_template 0x02, 0x02, 0x06, 0x06, 0x02, 0x05, 0x0080
	window_template 0x00, 0x0c, 0x02, 0x06, 0x02, 0x00, 0x00a0
	window_template 0x00, 0x04, 0x02, 0x07, 0x02, 0x00, 0x00a0
	window_template 0x00, 0x13, 0x02, 0x07, 0x02, 0x00, 0x00b0
	null_window_template

	.align 2
gUnknown_0831AAE0:: @ 831AAE0
	window_template 0x00, 0x02, 0x0f, 0x1a, 0x04, 0x00, 0x0090
	window_template 0x00, 0x01, 0x23, 0x0e, 0x04, 0x00, 0x01c0
	window_template 0x00, 0x11, 0x23, 0x0c, 0x04, 0x05, 0x0190
	window_template 0x00, 0x02, 0x37, 0x08, 0x02, 0x05, 0x0300
	window_template 0x00, 0x0b, 0x37, 0x08, 0x02, 0x05, 0x0310
	window_template 0x00, 0x02, 0x39, 0x08, 0x02, 0x05, 0x0320
	window_template 0x00, 0x0b, 0x39, 0x08, 0x02, 0x05, 0x0330
	window_template 0x00, 0x15, 0x37, 0x04, 0x02, 0x05, 0x0290
	window_template 0x00, 0x15, 0x39, 0x00, 0x00, 0x05, 0x0298
	window_template 0x00, 0x19, 0x37, 0x04, 0x02, 0x05, 0x0298
	window_template 0x00, 0x15, 0x39, 0x08, 0x02, 0x05, 0x02a0
	window_template 0x00, 0x15, 0x37, 0x08, 0x04, 0x05, 0x02b0
	window_template 0x00, 0x1a, 0x09, 0x03, 0x04, 0x05, 0x0100
	window_template 0x01, 0x13, 0x08, 0x0a, 0x0b, 0x05, 0x0100
	window_template 0x02, 0x12, 0x00, 0x0c, 0x03, 0x06, 0x016e
	window_template 0x00, 0x06, 0x01, 0x08, 0x02, 0x05, 0x0100
	window_template 0x00, 0x0e, 0x01, 0x02, 0x02, 0x05, 0x0110
	window_template 0x00, 0x10, 0x01, 0x08, 0x02, 0x05, 0x0114
	window_template 0x00, 0x0c, 0x04, 0x06, 0x02, 0x05, 0x0124
	window_template 0x00, 0x0c, 0x06, 0x06, 0x02, 0x05, 0x0130
	window_template 0x00, 0x0c, 0x08, 0x06, 0x02, 0x05, 0x013c
	window_template 0x00, 0x08, 0x0b, 0x0e, 0x02, 0x05, 0x0148
	window_template 0x00, 0x02, 0x0f, 0x1a, 0x04, 0x07, 0x0090
	null_window_template

	.align 2
gUnknown_0831ABA0:: @ 831ABA0
	.4byte gUnknown_0831AA18
	.4byte gUnknown_0831AAE0

	.align 2
gBattleTerrainTable:: @ 831ABA8
	@ tall_grass
	.4byte gBattleTerrainTiles_TallGrass
	.4byte gBattleTerrainTilemap_TallGrass
	.4byte gBattleTerrainAnimTiles_TallGrass
	.4byte gBattleTerrainAnimTilemap_TallGrass
	.4byte gBattleTerrainPalette_TallGrass

	@ long_grass
	.4byte gBattleTerrainTiles_LongGrass
	.4byte gBattleTerrainTilemap_LongGrass
	.4byte gBattleTerrainAnimTiles_LongGrass
	.4byte gBattleTerrainAnimTilemap_LongGrass
	.4byte gBattleTerrainPalette_LongGrass

	@ sand
	.4byte gBattleTerrainTiles_Sand
	.4byte gBattleTerrainTilemap_Sand
	.4byte gBattleTerrainAnimTiles_Sand
	.4byte gBattleTerrainAnimTilemap_Sand
	.4byte gBattleTerrainPalette_Sand

	@ underwater
	.4byte gBattleTerrainTiles_Underwater
	.4byte gBattleTerrainTilemap_Underwater
	.4byte gBattleTerrainAnimTiles_Underwater
	.4byte gBattleTerrainAnimTilemap_Underwater
	.4byte gBattleTerrainPalette_Underwater

	@ water
	.4byte gBattleTerrainTiles_Water
	.4byte gBattleTerrainTilemap_Water
	.4byte gBattleTerrainAnimTiles_Water
	.4byte gBattleTerrainAnimTilemap_Water
	.4byte gBattleTerrainPalette_Water

	@ pond_water
	.4byte gBattleTerrainTiles_PondWater
	.4byte gBattleTerrainTilemap_PondWater
	.4byte gBattleTerrainAnimTiles_PondWater
	.4byte gBattleTerrainAnimTilemap_PondWater
	.4byte gBattleTerrainPalette_PondWater

	@ rock
	.4byte gBattleTerrainTiles_Rock
	.4byte gBattleTerrainTilemap_Rock
	.4byte gBattleTerrainAnimTiles_Rock
	.4byte gBattleTerrainAnimTilemap_Rock
	.4byte gBattleTerrainPalette_Rock

	@ cave
	.4byte gBattleTerrainTiles_Cave
	.4byte gBattleTerrainTilemap_Cave
	.4byte gBattleTerrainAnimTiles_Cave
	.4byte gBattleTerrainAnimTilemap_Cave
	.4byte gBattleTerrainPalette_Cave

	@ building
	.4byte gBattleTerrainTiles_Building
	.4byte gBattleTerrainTilemap_Building
	.4byte gBattleTerrainAnimTiles_Building
	.4byte gBattleTerrainAnimTilemap_Building
	.4byte gBattleTerrainPalette_Building

	@ plain
	.4byte gBattleTerrainTiles_Building
	.4byte gBattleTerrainTilemap_Building
	.4byte gBattleTerrainAnimTiles_Building
	.4byte gBattleTerrainAnimTilemap_Building
	.4byte gBattleTerrainPalette_Plain

	.align 2
gUnknown_0831AC70:: @ 831AC70
	.4byte REG_BG3HOFS
	.4byte ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1
	.4byte 1
	.4byte REG_BG3HOFS
	.4byte ((DMA_ENABLE | DMA_START_HBLANK | DMA_32BIT | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1
	.4byte 1

	.align 2
gUnknown_0831AC88:: @ 831AC88
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8038528

gText_ShedinjaJapaneseName:: @ 831ACA0
	.string "ヌケニン$" @ Nukenin
    
	.align 2
gUnknown_0831ACA8:: @ 831ACA8
	.2byte 0x0100
	.2byte 0xC000
	.2byte 0x0800

	.align 2
gUnknown_0831ACB0:: @ 831ACB0
	.2byte 0x0100
	.2byte 0xC000
	.2byte 0x2800

	.align 2
gUnknown_0831ACB8:: @ 831ACB8
	.2byte 0x0000, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_0831ACC0:: @ 831ACC0
	.4byte gUnknown_0831ACB8

	.align 2
gUnknown_0831ACC4:: @ 831ACC4
	.2byte 0xfff0, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000, 0x3c00, 0x0000, 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_0831ACDC:: @ 831ACDC
	.4byte gUnknown_0831ACC4

	.align 2
gUnknown_0831ACE0:: @ 831ACE0
	.byte 0xe0, 0xf0, 0xf0, 0xe0, 0xe0, 0x00, 0x00, 0x00

@ 831ACE8
	.include "data/type_effectiveness.inc"

@ 831AE38
	.include "data/text/type_names.inc"

@ 831AEB8
	.include "data/trainer_money.inc"

@ 831AF98
	.include "data/text/ability_descriptions.inc"

@ 831B6DB
	.include "data/text/ability_names.inc"

@ 831BAD4
	.include "data/text/ability_description_pointers.inc"
