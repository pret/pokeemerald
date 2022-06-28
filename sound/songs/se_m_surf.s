	.include "MPlayDef.s"

	.equ	se_m_surf_grp, voicegroup128
	.equ	se_m_surf_pri, 4
	.equ	se_m_surf_rev, 0
	.equ	se_m_surf_mvl, 127
	.equ	se_m_surf_key, 0
	.equ	se_m_surf_tbs, 1
	.equ	se_m_surf_exg, 0
	.equ	se_m_surf_cmp, 1

	.section .rodata
	.global	se_m_surf
	.align	2

@********************** Track  1 **********************@

se_m_surf_1:
	.byte	KEYSH , se_m_surf_key+0
	.byte	TEMPO , 150*se_m_surf_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		VOL   , 27*se_m_surf_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N96   , Cn3 , v112
	.byte	W04
	.byte		VOL   , 45*se_m_surf_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-4
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		VOL   , 60*se_m_surf_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-10
	.byte	W02
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		VOL   , 88*se_m_surf_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-5
	.byte	W02
	.byte		BEND  , c_v+14
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 110*se_m_surf_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+19
	.byte	W03
	.byte		PAN   , c_v+4
	.byte	W02
	.byte		BEND  , c_v+24
	.byte	W04
	.byte		PAN   , c_v+11
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-4
	.byte	W02
	.byte		BEND  , c_v+19
	.byte	W04
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		VOL   , 98*se_m_surf_mvl/mxv
	.byte	W05
	.byte		        81*se_m_surf_mvl/mxv
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+12
	.byte	W06
	.byte		VOL   , 68*se_m_surf_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 50*se_m_surf_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		VOL   , 31*se_m_surf_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+22
	.byte	W02
	.byte		VOL   , 11*se_m_surf_mvl/mxv
	.byte	W04
	.byte		        6*se_m_surf_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+30
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_surf:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_surf_pri	@ Priority
	.byte	se_m_surf_rev	@ Reverb.

	.word	se_m_surf_grp

	.word	se_m_surf_1

	.end
