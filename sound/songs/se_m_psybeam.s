	.include "MPlayDef.s"

	.equ	se_m_psybeam_grp, voicegroup128
	.equ	se_m_psybeam_pri, 4
	.equ	se_m_psybeam_rev, 0
	.equ	se_m_psybeam_mvl, 127
	.equ	se_m_psybeam_key, 0
	.equ	se_m_psybeam_tbs, 1
	.equ	se_m_psybeam_exg, 0
	.equ	se_m_psybeam_cmp, 1

	.section .rodata
	.global	se_m_psybeam
	.align	2

@********************** Track  1 **********************@

se_m_psybeam_1:
	.byte	KEYSH , se_m_psybeam_key+0
	.byte	TEMPO , 190*se_m_psybeam_tbs/2
	.byte		VOICE , 45
	.byte		BENDR , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*se_m_psybeam_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+1
	.byte		N42   , As2 , v120
	.byte	W01
	.byte		PAN   , c_v+3
	.byte	W01
	.byte		        c_v+5
	.byte		VOL   , 57*se_m_psybeam_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		VOL   , 71*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v+1
	.byte		VOL   , 82*se_m_psybeam_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-3
	.byte		VOL   , 94*se_m_psybeam_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-6
	.byte	W02
	.byte		        c_v-10
	.byte		VOL   , 110*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte	W06
	.byte		        c_v+3
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+5
	.byte	W02
	.byte		        c_v+1
	.byte		VOL   , 95*se_m_psybeam_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-3
	.byte		VOL   , 83*se_m_psybeam_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		        c_v-10
	.byte		VOL   , 71*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 56*se_m_psybeam_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-3
	.byte	W01
	.byte		VOL   , 38*se_m_psybeam_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	FINE

@********************** Track  2 **********************@

se_m_psybeam_2:
	.byte	KEYSH , se_m_psybeam_key+0
	.byte		VOICE , 47
	.byte		BENDR , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*se_m_psybeam_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+1
	.byte		N42   , As1 , v040
	.byte	W02
	.byte		VOL   , 57*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		        71*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        82*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		        94*se_m_psybeam_mvl/mxv
	.byte	W03
	.byte		        110*se_m_psybeam_mvl/mxv
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        95*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		        83*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		        71*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        56*se_m_psybeam_mvl/mxv
	.byte	W02
	.byte		        38*se_m_psybeam_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_psybeam:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_psybeam_pri	@ Priority
	.byte	se_m_psybeam_rev	@ Reverb.

	.word	se_m_psybeam_grp

	.word	se_m_psybeam_1
	.word	se_m_psybeam_2

	.end
