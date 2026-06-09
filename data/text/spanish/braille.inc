@ NOTE: The brailleformat macro in this file is leftover from RS.
@       The numbers are simply skipped over. If you'd like to omit
@       this macro you must also stop it from skipping over this
@       section by editing ScrCmd_braillemessage.

@ For some reason esp version uses 0x3F character before commans and periods(which are actually 0x10 - ')

Underwater_SealedChamber_Braille_GoUpHere::
	brailleformat 4, 6, 26, 13, 7, 9
	.braille "SUBE AHORA"
	.byte 0x3F
	.braille "'$"

SealedChamber_OuterRoom_Braille_ABC:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "ABC$"

SealedChamber_OuterRoom_Braille_GHI:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "GHI$"

SealedChamber_OuterRoom_Braille_MNO:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "MNO$"

SealedChamber_OuterRoom_Braille_TUV:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "TUV$"

SealedChamber_OuterRoom_Braille_DEF:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "DEF$"

SealedChamber_OuterRoom_Braille_JKL:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "JKL$"

SealedChamber_OuterRoom_Braille_PQRS:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "PQRS$"

SealedChamber_OuterRoom_Braille_Period:
	brailleformat 9, 6, 19, 13, 12, 9
	.byte 0x3F
	.braille "'$"

SealedChamber_OuterRoom_Braille_WXYZ:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "WXYZ$"

SealedChamber_OuterRoom_Braille_Comma:
	brailleformat 9, 6, 19, 13, 12, 9
	.byte 0x3F
	.braille ",$"

SealedChamber_OuterRoom_Braille_DigHere:
	brailleformat 7, 4, 23, 15, 10, 7
	.braille "CAVA AHORA"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth:
	brailleformat 0, 0, 29, 19, 3, 3
	.braille "PRIMERO\n"
	.braille "WAILORD"
	.byte 0x3F
	.braille "'\n"
	.braille "AL FINAL\n"
	.braille "RELICANTH"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived:
	brailleformat 2, 0, 26, 19, 5, 3
	.braille "ESTA CUEVA\n"
	.braille "HA SIDO\n"
	.braille "NUESTRO\n"
	.braille "HOGAR"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon:
	brailleformat 7, 2, 23, 17, 10, 5
	.braille "LO QUE SOMOS"
	.byte 0x3F
	.braille ",\n"
	.braille "SE LO DEBEMOS\n"
	.braille "A LOS\n"
	.braille "POKEMON"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway:
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "PERO LOS\n"
	.braille "ENCERRAMOS\n"
	.braille "PARA\n"
	.braille "SIEMPRE"
	.byte 0x3F, 0x10
	.braille "$"

SealedChamber_InnerRoom_Braille_WeFearedIt:
	brailleformat 5, 6, 25, 13, 8, 9
	.braille "TUVIMOS\n"
	.braille "MIEDO"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_ThoseWithCourageHope:
	brailleformat 6, 0, 24, 19, 9, 3
	.braille "QUIENES\n"
	.braille "POSEEN\n"
	.braille "VALOR Y\n"
	.braille "ESPERANZA"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits:
	brailleformat 3, 2, 27, 17, 6, 5
	.braille "ABREN LA\n"
	.braille "PUERTA HACIA\n"
	.braille "UN POKEMON\n"
	.braille "ETERNO"
	.byte 0x3F
	.braille "'$"

DesertRuins_Braille_UseRockSmash:
	brailleformat 1, 0, 27, 19, 4, 3
	.braille "IZDA"
	.byte 0x3F
	.braille "' IZDA"
	.byte 0x3F
	.braille "'\n"
	.braille "ABAJO ABAJO"
	.byte 0x3F
	.braille "'\n"
	.braille "ENTONCES"
	.byte 0x3F
	.braille ", USA\n"
	.braille "GOLPE ROCA"
	.byte 0x3F
	.braille "'$"

IslandCave_Braille_RunLapAroundWall:
	brailleformat 5, 0, 25, 19, 8, 3
	.braille "PONTE JUNTO\n"
	.braille "AL MURO"
	.byte 0x3F
	.braille "'\n"
	.braille "DA UNA VUELTA\n"
	.braille "COMPLETA"
	.byte 0x3F
	.braille "'$"

AncientTomb_Braille_ShineInTheMiddle:
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "QUIEN DESEE LO\n"
	.braille "QUE NOSOTROS"
	.byte 0x3F
	.braille ",\n"
	.braille "QUE BRILLE\n"
	.braille "EN EL CENTRO"
	.byte 0x3F
	.braille "'$"
