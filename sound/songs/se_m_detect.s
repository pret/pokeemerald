	.include "MPlayDef.s"

	.equ	se_m_detect_grp, voicegroup_rs_sfx_2
	.equ	se_m_detect_pri, 4
	.equ	se_m_detect_rev, reverb_set+50
	.equ	se_m_detect_mvl, 127
	.equ	se_m_detect_key, 0
	.equ	se_m_detect_tbs, 1
	.equ	se_m_detect_exg, 0
	.equ	se_m_detect_cmp, 1

	.section .rodata
	.global	se_m_detect
	.align	2

@********************** Track  1 **********************@

se_m_detect_1:
	.byte	KEYSH , se_m_detect_key+0
	.byte	TEMPO , 220*se_m_detect_tbs/2
	.byte		VOICE , 54
	.byte		VOL   , 100*se_m_detect_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v127
	.byte	W01
	.byte		PAN   , c_v+2
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W02
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v104
	.byte	W01
	.byte		PAN   , c_v-2
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W04
	.byte	W01
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v080
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v048
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_detect:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_detect_pri	@ Priority
	.byte	se_m_detect_rev	@ Reverb.

	.word	se_m_detect_grp

	.word	se_m_detect_1

	.end
