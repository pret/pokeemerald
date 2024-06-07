	.include "MPlayDef.s"

	.equ	se_m_string_shot2_grp, voicegroup128
	.equ	se_m_string_shot2_pri, 4
	.equ	se_m_string_shot2_rev, 0
	.equ	se_m_string_shot2_mvl, 127
	.equ	se_m_string_shot2_key, 0
	.equ	se_m_string_shot2_tbs, 1
	.equ	se_m_string_shot2_exg, 0
	.equ	se_m_string_shot2_cmp, 1

	.section .rodata
	.global	se_m_string_shot2
	.align	2

@********************** Track  1 **********************@

se_m_string_shot2_1:
	.byte	KEYSH , se_m_string_shot2_key+0
	.byte	TEMPO , 250*se_m_string_shot2_tbs/2
	.byte		VOICE , 10
	.byte		BENDR , 12
	.byte		VOL   , 105*se_m_string_shot2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v+0
	.byte		N09   , En4 , v112
	.byte	W03
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		        c_v+12
	.byte	W05
	.byte		        c_v+8
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		N09   , Gn4
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v-14
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-11
	.byte		N09   , En4
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		        c_v+1
	.byte	W05
	.byte		        c_v-3
	.byte	W01
	.byte		PAN   , c_v-16
	.byte		N09   , Gn4
	.byte	W03
	.byte		BEND  , c_v-19
	.byte	W03
	.byte		        c_v-25
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-19
	.byte		N09   , En4
	.byte	W03
	.byte		BEND  , c_v-13
	.byte	W03
	.byte		        c_v-6
	.byte	W05
	.byte		        c_v-10
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		N09   , Gn4 , v096
	.byte	W03
	.byte		BEND  , c_v-27
	.byte	W03
	.byte		        c_v-32
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-32
	.byte		N09   , En4 , v084
	.byte	W03
	.byte		BEND  , c_v-26
	.byte	W03
	.byte		        c_v-19
	.byte	W05
	.byte		        c_v-23
	.byte	W01
	.byte		PAN   , c_v-16
	.byte		N09   , Gn4 , v060
	.byte	W03
	.byte		BEND  , c_v-40
	.byte	W03
	.byte		        c_v-45
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_m_string_shot2_2:
	.byte	KEYSH , se_m_string_shot2_key+0
	.byte		VOICE , 5
	.byte		VOL   , 105*se_m_string_shot2_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N09   , Cn3 , v052
	.byte	W12
	.byte		PAN   , c_v-7
	.byte		N09   , Gn2
	.byte	W12
se_m_string_shot2_2_000:
	.byte		PAN   , c_v+9
	.byte		N09   , Cn3 , v052
	.byte	W12
	.byte		PAN   , c_v-6
	.byte		N09   , Gn2
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	se_m_string_shot2_2_000
	.byte	PATT
	 .word	se_m_string_shot2_2_000
	.byte	FINE

@******************************************************@
	.align	2

se_m_string_shot2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_string_shot2_pri	@ Priority
	.byte	se_m_string_shot2_rev	@ Reverb.

	.word	se_m_string_shot2_grp

	.word	se_m_string_shot2_1
	.word	se_m_string_shot2_2

	.end
