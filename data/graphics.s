	.section gfx_data, "aw", %progbits

	@ random garbage at the end. why, game freak?
	.space 0x54BAC
	.byte 0x0D, 0x00, 0x58, 0x02 @ why?
	@ E38BC8
	.space 0x1145
	.byte 0x02 @ whyyyyy?
	.space 0x3242
	.byte 0x40 @ WHYYYYYYYY
	.space 0x13
