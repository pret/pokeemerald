	.include "MPlayDef.s"

	.equ	se_ru_gashin_grp, voicegroup_869D6F4
	.equ	se_ru_gashin_pri, 4
	.equ	se_ru_gashin_rev, reverb_set+50
	.equ	se_ru_gashin_mvl, 127
	.equ	se_ru_gashin_key, 0
	.equ	se_ru_gashin_tbs, 1
	.equ	se_ru_gashin_exg, 0
	.equ	se_ru_gashin_cmp, 1

	.section .rodata
	.global	se_ru_gashin
	.align	2

@********************** Track  1 **********************@

se_ru_gashin_1:
	.byte	KEYSH , se_ru_gashin_key+0
	.byte	TEMPO , 150*se_ru_gashin_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 90*se_ru_gashin_mvl/mxv
	.byte		BEND  , c_v+16
	.byte		N03   , En3 , v112
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		N12   , En4 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_ru_gashin_2:
	.byte	KEYSH , se_ru_gashin_key+0
	.byte		VOICE , 4
	.byte		VOL   , 90*se_ru_gashin_mvl/mxv
	.byte		N03   , Gs3 , v096
	.byte	W04
	.byte		N12   , Gs4 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_ru_gashin:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ru_gashin_pri	@ Priority
	.byte	se_ru_gashin_rev	@ Reverb.

	.word	se_ru_gashin_grp

	.word	se_ru_gashin_1
	.word	se_ru_gashin_2

	.end
