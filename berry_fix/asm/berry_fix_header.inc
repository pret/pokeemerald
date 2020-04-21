	.global BerryFixMBHeaderNintendoLogo
BerryFixMBHeaderNintendoLogo:
	.space 156

BerryFixMBHeaderGameTitle:
	.space 12

	.global BerryFixMBHeaderGameCode
BerryFixMBHeaderGameCode:
	.space 4

BerryFixMBHeaderMakerCode:
	.space 2

BerryFixMBHeaderMagic:
	.byte 0

BerryFixMBHeaderMainUnitCode:
	.byte 0

BerryFixMBHeaderDeviceType:
	.byte 0

BerryFixMBHeaderReserved1:
	.space 7

	.global BerryFixMBHeaderSoftwareVersion
BerryFixMBHeaderSoftwareVersion:
	.byte 0

BerryFixMBHeaderChecksum:
	.byte 0

BerryFixMBHeaderReserved2:
	.space 2
