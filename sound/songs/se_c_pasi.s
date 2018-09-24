	.include "MPlayDef.s"

	.equ	se_c_pasi_grp, voicegroup128
	.equ	se_c_pasi_pri, 5
	.equ	se_c_pasi_rev, reverb_set+50
	.equ	se_c_pasi_mvl, 127
	.equ	se_c_pasi_key, 0
	.equ	se_c_pasi_tbs, 1
	.equ	se_c_pasi_exg, 0
	.equ	se_c_pasi_cmp, 1

	.section .rodata
	.global	se_c_pasi
	.align	2

@********************** Track  1 **********************@

se_c_pasi_1:
	.byte	KEYSH , se_c_pasi_key+0
	.byte	TEMPO , 150*se_c_pasi_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_c_pasi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_c_pasi:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_c_pasi_pri	@ Priority
	.byte	se_c_pasi_rev	@ Reverb.

	.word	se_c_pasi_grp

	.word	se_c_pasi_1

	.end
