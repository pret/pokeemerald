	.include "MPlayDef.s"

	.equ	se_m_brick_break_grp, voicegroup128
	.equ	se_m_brick_break_pri, 4
	.equ	se_m_brick_break_rev, reverb_set+50
	.equ	se_m_brick_break_mvl, 127
	.equ	se_m_brick_break_key, 0
	.equ	se_m_brick_break_tbs, 1
	.equ	se_m_brick_break_exg, 0
	.equ	se_m_brick_break_cmp, 1

	.section .rodata
	.global	se_m_brick_break
	.align	2

@********************** Track  1 **********************@

se_m_brick_break_1:
	.byte	KEYSH , se_m_brick_break_key+0
	.byte	TEMPO , 150*se_m_brick_break_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 110*se_m_brick_break_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn4 , v127
	.byte	W01
	.byte		N03   , Cn5
	.byte	W01
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		VOICE , 3
	.byte		PAN   , c_v+0
	.byte		N01   , Gs4 , v112
	.byte	W02
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		N01   , Dn5 , v096
	.byte	W03
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		N01   , Gs4 , v084
	.byte	W04
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		N01   , Dn5 , v068
	.byte	W05
	.byte		PAN   , c_v+7
	.byte		N01   , Gs4 , v052
	.byte	W04
	.byte		PAN   , c_v-8
	.byte		N01   , Dn5 , v032
	.byte	W02
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_m_brick_break_2:
	.byte	KEYSH , se_m_brick_break_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_m_brick_break_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 , v064
	.byte	W01
	.byte		N03   , Gn3
	.byte	W05
	.byte	W01
	.byte		N02   , En4 , v040
	.byte	W05
	.byte		        Gn3
	.byte	W04
	.byte		        En4 , v032
	.byte	W02
	.byte	W03
	.byte		        Gn3
	.byte	W03
	.byte	W02
	.byte		        En4 , v020
	.byte	W04
	.byte	W01
	.byte		        Gn3
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_m_brick_break:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_brick_break_pri	@ Priority
	.byte	se_m_brick_break_rev	@ Reverb.

	.word	se_m_brick_break_grp

	.word	se_m_brick_break_1
	.word	se_m_brick_break_2

	.end
