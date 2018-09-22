	.include "MPlayDef.s"

	.equ	se_c_syu_grp, voicegroup128
	.equ	se_c_syu_pri, 5
	.equ	se_c_syu_rev, reverb_set+50
	.equ	se_c_syu_mvl, 127
	.equ	se_c_syu_key, 0
	.equ	se_c_syu_tbs, 1
	.equ	se_c_syu_exg, 0
	.equ	se_c_syu_cmp, 1

	.section .rodata
	.global	se_c_syu
	.align	2

@********************** Track  1 **********************@

se_c_syu_1:
	.byte	KEYSH , se_c_syu_key+0
	.byte	TEMPO , 150*se_c_syu_tbs/2
	.byte		VOICE , 36
	.byte		VOL   , 49*se_c_syu_mvl/mxv
	.byte		BEND  , c_v-64
	.byte		N03   , Cn6 , v112
	.byte	W01
	.byte		VOL   , 68*se_c_syu_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 90*se_c_syu_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		VOL   , 69*se_c_syu_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Cn6 , v040
	.byte	W01
	.byte		VOL   , 90*se_c_syu_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_c_syu:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_c_syu_pri	@ Priority
	.byte	se_c_syu_rev	@ Reverb.

	.word	se_c_syu_grp

	.word	se_c_syu_1

	.end
