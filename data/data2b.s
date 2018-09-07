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
	obj_frame_tiles gHeap + 0x8000, 0x800
	obj_frame_tiles gHeap + 0x8800, 0x800
	obj_frame_tiles gHeap + 0x9000, 0x800
	obj_frame_tiles gHeap + 0x9800, 0x800

	.align 2
gUnknown_082FF3C8:: @ 82FF3C8
	obj_frame_tiles gHeap + 0xA000, 0x800
	obj_frame_tiles gHeap + 0xA800, 0x800
	obj_frame_tiles gHeap + 0xB000, 0x800
	obj_frame_tiles gHeap + 0xB800, 0x800

	.align 2
gUnknown_082FF3E8:: @ 82FF3E8
	obj_frame_tiles gHeap + 0xC000, 0x800
	obj_frame_tiles gHeap + 0xC800, 0x800
	obj_frame_tiles gHeap + 0xD000, 0x800
	obj_frame_tiles gHeap + 0xD800, 0x800

	.align 2
gUnknown_082FF408:: @ 82FF408
	obj_frame_tiles gHeap + 0xE000, 0x800
	obj_frame_tiles gHeap + 0xE800, 0x800
	obj_frame_tiles gHeap + 0xF000, 0x800
	obj_frame_tiles gHeap + 0xF800, 0x800

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
