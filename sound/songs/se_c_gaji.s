	.include "MPlayDef.s"

	.equ	se_c_gaji_grp, voicegroup128
	.equ	se_c_gaji_pri, 5
	.equ	se_c_gaji_rev, reverb_set+50
	.equ	se_c_gaji_mvl, 127
	.equ	se_c_gaji_key, 0
	.equ	se_c_gaji_tbs, 1
	.equ	se_c_gaji_exg, 0
	.equ	se_c_gaji_cmp, 1

	.section .rodata
	.global	se_c_gaji
	.align	2

@********************** Track  1 **********************@

se_c_gaji_1:
	.byte	KEYSH , se_c_gaji_key+0
	.byte	TEMPO , 150*se_c_gaji_tbs/2
	.byte		VOICE , 14
	.byte		VOL   , 90*se_c_gaji_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N02   , Cn5 , v112
	.byte	W02
	.byte		N09   , Gn4 
	.byte	W04
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_c_gaji:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_c_gaji_pri	@ Priority
	.byte	se_c_gaji_rev	@ Reverb.

	.word	se_c_gaji_grp

	.word	se_c_gaji_1

	.end
