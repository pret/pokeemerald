	.include "MPlayDef.s"

	.equ	se_ru_hyuu_grp, voicegroup128
	.equ	se_ru_hyuu_pri, 4
	.equ	se_ru_hyuu_rev, reverb_set+50
	.equ	se_ru_hyuu_mvl, 127
	.equ	se_ru_hyuu_key, 0
	.equ	se_ru_hyuu_tbs, 1
	.equ	se_ru_hyuu_exg, 0
	.equ	se_ru_hyuu_cmp, 1

	.section .rodata
	.global	se_ru_hyuu
	.align	2

@********************** Track  1 **********************@

se_ru_hyuu_1:
	.byte	KEYSH , se_ru_hyuu_key+0
	.byte	TEMPO , 170*se_ru_hyuu_tbs/2
	.byte		VOICE , 22
	.byte		VOL   , 110*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v+60
	.byte		N44   , Gn3 , v080
	.byte	W03
	.byte		BEND  , c_v+57
	.byte	W03
	.byte		        c_v+52
	.byte	W03
	.byte		        c_v+43
	.byte	W03
	.byte		        c_v+36
	.byte	W03
	.byte		        c_v+30
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		VOL   , 104*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		VOL   , 90*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		VOL   , 82*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		VOL   , 71*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		VOL   , 58*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		VOL   , 45*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v-36
	.byte	W03
	.byte		VOL   , 36*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v-50
	.byte	W03
	.byte		VOL   , 11*se_ru_hyuu_mvl/mxv
	.byte		BEND  , c_v-63
	.byte	W03
	.byte		VOL   , 3*se_ru_hyuu_mvl/mxv
	.byte	FINE

@******************************************************@
	.align	2

se_ru_hyuu:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ru_hyuu_pri	@ Priority
	.byte	se_ru_hyuu_rev	@ Reverb.

	.word	se_ru_hyuu_grp

	.word	se_ru_hyuu_1

	.end
