	.align 2
LittlerootTown_ProfessorBirchsLab_MapBorder::
	.incbin "data/layouts/LittlerootTown_ProfessorBirchsLab/border.bin"

	.align 2
LittlerootTown_ProfessorBirchsLab_MapBlockdata::
	.incbin "data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin"

	.align 2
LittlerootTown_ProfessorBirchsLab_Layout::
	.4byte 0xd
	.4byte 0xd
	.4byte LittlerootTown_ProfessorBirchsLab_MapBorder
	.4byte LittlerootTown_ProfessorBirchsLab_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Lab
