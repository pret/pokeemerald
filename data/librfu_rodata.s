	.section .rodata

llsf_struct:: @ 89A3220
	.byte 2, 14, 0, 10, 9, 5, 7, 2
	.byte 0, 15, 1, 3, 3, 0, 31, 0
	.byte 3, 22, 18, 14, 13, 9, 11, 3
	.byte 15, 15, 1, 3, 3, 0, 0x7f, 0

	.asciz "RFU_V1026"

	.align 2
str_checkMbootLL:: @ 89A324C
	.asciz "RFU-MBOOT"

	.align 2
Sio32ConnectionData:: @ 89A3258
	.asciz "NINTENDOSio32ID_030820"
