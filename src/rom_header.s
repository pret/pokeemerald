@ Note: ROM header data is empty space here.
@       It's populated by gbafix using data provided in the Makefile. 

	.global Start
Start:
	b Init

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

    .word 0

    .global GPIOPortData
GPIOPortData:
    .2byte 0

    .global GPIOPortDirection
GPIOPortDirection:
    .2byte 0

    .global GPIOPortReadEnable
GPIOPortReadEnable:
    .2byte 0

    .2byte 0

    .space 0x34
