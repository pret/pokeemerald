	.include "MPlayDef.s"

	.equ	se_m_string_shot_grp, voicegroup128
	.equ	se_m_string_shot_pri, 4
	.equ	se_m_string_shot_rev, 0
	.equ	se_m_string_shot_mvl, 127
	.equ	se_m_string_shot_key, 0
	.equ	se_m_string_shot_tbs, 1
	.equ	se_m_string_shot_exg, 0
	.equ	se_m_string_shot_cmp, 1

	.section .rodata
	.global	se_m_string_shot
	.align	2

@********************** Track  1 **********************@

se_m_string_shot_1:
	.byte	KEYSH , se_m_string_shot_key+0
	.byte	TEMPO , 250*se_m_string_shot_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_string_shot_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , Fn4 , v108
	.byte	W03
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		PAN   , c_v+15
	.byte		BEND  , c_v+12
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+21
	.byte	W02
	.byte		        c_v+8
	.byte	W01
	.byte		PAN   , c_v-1
	.byte	W03
	.byte		        c_v-9
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v-14
	.byte	W03
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		VOL   , 90*se_m_string_shot_mvl/mxv
	.byte	W03
	.byte		        71*se_m_string_shot_mvl/mxv
	.byte	W03
	.byte		        58*se_m_string_shot_mvl/mxv
	.byte	W03
	.byte		        41*se_m_string_shot_mvl/mxv
	.byte	W03
	.byte		        27*se_m_string_shot_mvl/mxv
	.byte	W03
	.byte		        7*se_m_string_shot_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_string_shot:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_string_shot_pri	@ Priority
	.byte	se_m_string_shot_rev	@ Reverb.

	.word	se_m_string_shot_grp

	.word	se_m_string_shot_1

	.end
