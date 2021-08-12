	.include "MPlayDef.s"

	.equ	se_m_thunderbolt2_grp, voicegroup128
	.equ	se_m_thunderbolt2_pri, 4
	.equ	se_m_thunderbolt2_rev, reverb_set+50
	.equ	se_m_thunderbolt2_mvl, 127
	.equ	se_m_thunderbolt2_key, 0
	.equ	se_m_thunderbolt2_tbs, 1
	.equ	se_m_thunderbolt2_exg, 0
	.equ	se_m_thunderbolt2_cmp, 1

	.section .rodata
	.global	se_m_thunderbolt2
	.align	2

@********************** Track  1 **********************@

se_m_thunderbolt2_1:
	.byte	KEYSH , se_m_thunderbolt2_key+0
	.byte	TEMPO , 220*se_m_thunderbolt2_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 100*se_m_thunderbolt2_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		PAN   , c_v-9
	.byte		N03   , Cn4 , v080
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N03   , Cn4 , v072
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v064
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Cn4 , v060
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v052
	.byte	W18
	.byte	FINE

@********************** Track  2 **********************@

se_m_thunderbolt2_2:
	.byte	KEYSH , se_m_thunderbolt2_key+0
	.byte		VOICE , 5
	.byte		VOL   , 100*se_m_thunderbolt2_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v072
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v068
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v064
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v060
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v056
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v048
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

se_m_thunderbolt2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_thunderbolt2_pri	@ Priority
	.byte	se_m_thunderbolt2_rev	@ Reverb.

	.word	se_m_thunderbolt2_grp

	.word	se_m_thunderbolt2_1
	.word	se_m_thunderbolt2_2

	.end
