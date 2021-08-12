	.include "MPlayDef.s"

	.equ	se_m_dig_grp, voicegroup128
	.equ	se_m_dig_pri, 4
	.equ	se_m_dig_rev, reverb_set+50
	.equ	se_m_dig_mvl, 127
	.equ	se_m_dig_key, 0
	.equ	se_m_dig_tbs, 1
	.equ	se_m_dig_exg, 0
	.equ	se_m_dig_cmp, 1

	.section .rodata
	.global	se_m_dig
	.align	2

@********************** Track  1 **********************@

se_m_dig_1:
	.byte	KEYSH , se_m_dig_key+0
	.byte	TEMPO , 150*se_m_dig_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 115*se_m_dig_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn2 , v112
	.byte	W01
	.byte		VOICE , 26
	.byte		N02   , Cn3 , v127
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v+16
	.byte		N03   
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+28
	.byte	W02
	.byte		        c_v+45
	.byte	W01
	.byte		VOICE , 36
	.byte		PAN   , c_v+12
	.byte		BEND  , c_v+0
	.byte		N02   , Cn3 , v056
	.byte	W02
	.byte	W03
	.byte		PAN   , c_v-12
	.byte		N02   , Cn3 , v036
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_dig:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_dig_pri	@ Priority
	.byte	se_m_dig_rev	@ Reverb.

	.word	se_m_dig_grp

	.word	se_m_dig_1

	.end
