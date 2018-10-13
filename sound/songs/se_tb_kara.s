	.include "MPlayDef.s"

	.equ	se_tb_kara_grp, voicegroup127
	.equ	se_tb_kara_pri, 5
	.equ	se_tb_kara_rev, reverb_set+50
	.equ	se_tb_kara_mvl, 127
	.equ	se_tb_kara_key, 0
	.equ	se_tb_kara_tbs, 1
	.equ	se_tb_kara_exg, 0
	.equ	se_tb_kara_cmp, 1

	.section .rodata
	.global	se_tb_kara
	.align	2

@********************** Track  1 **********************@

se_tb_kara_1:
	.byte	KEYSH , se_tb_kara_key+0
	.byte	TEMPO , 150*se_tb_kara_tbs/2
	.byte		VOICE , 119
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*se_tb_kara_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N02   , Gs4 , v040
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_tb_kara:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tb_kara_pri	@ Priority
	.byte	se_tb_kara_rev	@ Reverb.

	.word	se_tb_kara_grp

	.word	se_tb_kara_1

	.end
