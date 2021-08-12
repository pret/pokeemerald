	.include "MPlayDef.s"

	.equ	se_m_reflect_grp, voicegroup128
	.equ	se_m_reflect_pri, 4
	.equ	se_m_reflect_rev, reverb_set+50
	.equ	se_m_reflect_mvl, 127
	.equ	se_m_reflect_key, 0
	.equ	se_m_reflect_tbs, 1
	.equ	se_m_reflect_exg, 0
	.equ	se_m_reflect_cmp, 1

	.section .rodata
	.global	se_m_reflect
	.align	2

@********************** Track  1 **********************@

se_m_reflect_1:
	.byte	KEYSH , se_m_reflect_key+0
	.byte	TEMPO , 150*se_m_reflect_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v+6
	.byte		N06   , Gn6 , v080
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-14
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-31
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-41
	.byte	W02
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Gn6 , v072
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-1
	.byte		N06   , Gn6 , v068
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-21
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-48
	.byte	W02
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-1
	.byte		N06   , Gn6 , v060
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-21
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-48
	.byte	W02
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-2
	.byte		N06   , Gn6 , v052
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-49
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-2
	.byte		N06   , Gn6 , v048
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-49
	.byte	W02
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-2
	.byte		N06   , Gn6 , v040
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-13
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-49
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-2
	.byte		N06   , Gn6 , v032
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-13
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 20*se_m_reflect_mvl/mxv
	.byte		BEND  , c_v-49
	.byte	W02
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_m_reflect_2:
	.byte	KEYSH , se_m_reflect_key+0
	.byte		VOICE , 53
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*se_m_reflect_mvl/mxv
	.byte	W02
	.byte		N06   , En6 , v064
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
	.byte		        60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        90*se_m_reflect_mvl/mxv
	.byte		N06   , En6 , v056
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
se_m_reflect_2_000:
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        90*se_m_reflect_mvl/mxv
	.byte		N06   , En6 , v052
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
	.byte	PEND
	.byte	PATT
	 .word	se_m_reflect_2_000
	.byte		VOL   , 60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        90*se_m_reflect_mvl/mxv
	.byte		N06   , En6 , v048
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
	.byte		        60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        90*se_m_reflect_mvl/mxv
	.byte		N06   , En6 , v044
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
	.byte		        60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        90*se_m_reflect_mvl/mxv
	.byte		N06   , En6 , v040
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
	.byte		        60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        90*se_m_reflect_mvl/mxv
	.byte		N06   , En6 , v036
	.byte	W02
	.byte		VOL   , 74*se_m_reflect_mvl/mxv
	.byte	W02
	.byte		        60*se_m_reflect_mvl/mxv
	.byte	W01
	.byte		        20*se_m_reflect_mvl/mxv
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_m_reflect:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_reflect_pri	@ Priority
	.byte	se_m_reflect_rev	@ Reverb.

	.word	se_m_reflect_grp

	.word	se_m_reflect_1
	.word	se_m_reflect_2

	.end
