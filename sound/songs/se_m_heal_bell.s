	.include "MPlayDef.s"

	.equ	se_m_heal_bell_grp, voicegroup_rs_sfx_2
	.equ	se_m_heal_bell_pri, 4
	.equ	se_m_heal_bell_rev, reverb_set+50
	.equ	se_m_heal_bell_mvl, 127
	.equ	se_m_heal_bell_key, 0
	.equ	se_m_heal_bell_tbs, 1
	.equ	se_m_heal_bell_exg, 0
	.equ	se_m_heal_bell_cmp, 1

	.section .rodata
	.global	se_m_heal_bell
	.align	2

@********************** Track  1 **********************@

se_m_heal_bell_1:
	.byte	KEYSH , se_m_heal_bell_key+0
	.byte	TEMPO , 150*se_m_heal_bell_tbs/2
	.byte		VOICE , 51
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*se_m_heal_bell_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N03   , As5 , v100
	.byte	W01
	.byte		PAN   , c_v-13
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v+1
	.byte		N01   , An5
	.byte	W01
	.byte		MOD   , 7
	.byte		N18   , Bn5
	.byte	W02
	.byte		PAN   , c_v+11
	.byte	W01
	.byte		MOD   , 0
	.byte		PAN   , c_v-14
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+11
	.byte	W02
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		MOD   , 7
	.byte		PAN   , c_v-14
	.byte	W02
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v-13
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_heal_bell:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_heal_bell_pri	@ Priority
	.byte	se_m_heal_bell_rev	@ Reverb.

	.word	se_m_heal_bell_grp

	.word	se_m_heal_bell_1

	.end
