	.global RomHeaderNintendoLogo
RomHeaderNintendoLogo:
	.space 156

RomHeaderGameTitle:
	.space 12

	.global RomHeaderGameCode
RomHeaderGameCode:
	.space 4

RomHeaderMakerCode:
	.space 2

RomHeaderMagic:
	.byte 0

RomHeaderMainUnitCode:
	.byte 0

RomHeaderDeviceType:
	.byte 0

RomHeaderReserved1:
	.space 7

	.global RomHeaderSoftwareVersion
RomHeaderSoftwareVersion:
	.byte 0

RomHeaderChecksum:
	.byte 0

RomHeaderReserved2:
	.space 2
