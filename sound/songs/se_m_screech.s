	.include "MPlayDef.s"

	.equ	se_m_screech_grp, voicegroup_rs_sfx_2
	.equ	se_m_screech_pri, 4
	.equ	se_m_screech_rev, reverb_set+50
	.equ	se_m_screech_mvl, 127
	.equ	se_m_screech_key, 0
	.equ	se_m_screech_tbs, 1
	.equ	se_m_screech_exg, 0
	.equ	se_m_screech_cmp, 1

	.section .rodata
	.global	se_m_screech
	.align	2

@********************** Track  1 **********************@

se_m_screech_1:
	.byte		VOL   , 110*se_m_screech_mvl/mxv
	.byte	KEYSH , se_m_screech_key+0
	.byte	TEMPO , 150*se_m_screech_tbs/2
	.byte		VOICE , 44
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N21   , Fs5 , v112
	.byte	W01
	.byte		PAN   , c_v-5
	.byte	W01
	.byte		        c_v-10
	.byte		VOL   , 15*se_m_screech_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		VOL   , 41*se_m_screech_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 69*se_m_screech_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		        c_v+10
	.byte		VOL   , 84*se_m_screech_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 97*se_m_screech_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-5
	.byte	W02
	.byte		VOL   , 110*se_m_screech_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+10
	.byte	W02
	.byte		VOL   , 100*se_m_screech_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 84*se_m_screech_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 55*se_m_screech_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_m_screech_2:
	.byte		VOL   , 110*se_m_screech_mvl/mxv
	.byte	KEYSH , se_m_screech_key+0
	.byte		VOICE , 42
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N21   , Fn6 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte	W01
	.byte		        c_v+0
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_screech:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_screech_pri	@ Priority
	.byte	se_m_screech_rev	@ Reverb.

	.word	se_m_screech_grp

	.word	se_m_screech_1
	.word	se_m_screech_2

	.end
