	.include "MPlayDef.s"

	.equ	se_m_hyper_beam2_grp, voicegroup128
	.equ	se_m_hyper_beam2_pri, 4
	.equ	se_m_hyper_beam2_rev, reverb_set+50
	.equ	se_m_hyper_beam2_mvl, 127
	.equ	se_m_hyper_beam2_key, 0
	.equ	se_m_hyper_beam2_tbs, 1
	.equ	se_m_hyper_beam2_exg, 0
	.equ	se_m_hyper_beam2_cmp, 1

	.section .rodata
	.global	se_m_hyper_beam2
	.align	2

@********************** Track  1 **********************@

se_m_hyper_beam2_1:
	.byte	KEYSH , se_m_hyper_beam2_key+0
	.byte	TEMPO , 150*se_m_hyper_beam2_tbs/2
	.byte		VOICE , 45
	.byte		VOL   , 110*se_m_hyper_beam2_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v092
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+0
	.byte		N02   , Cs4 
	.byte	W01
	.byte		BEND  , c_v+30
	.byte	W02
	.byte		        c_v+0
	.byte		N03   , As3 
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+0
	.byte		N02   , En4 
	.byte	W01
	.byte		BEND  , c_v+30
	.byte	W02
	.byte		PAN   , c_v+7
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v040
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+0
	.byte		N02   , Cs4 
	.byte	W01
	.byte		BEND  , c_v+30
	.byte	W02
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+0
	.byte		N03   , As3 , v016
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+0
	.byte		N02   , En4 
	.byte	W01
	.byte		BEND  , c_v+30
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_m_hyper_beam2_2:
	.byte	KEYSH , se_m_hyper_beam2_key+0
	.byte		VOICE , 5
	.byte		VOL   , 110*se_m_hyper_beam2_mvl/mxv
	.byte		N01   , Cn3 , v032
	.byte	W02
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W04
se_m_hyper_beam2_2_000:
	.byte		N01   , Cn3 , v020
	.byte	W02
	.byte		N01   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	se_m_hyper_beam2_2_000
	.byte	FINE

@******************************************************@
	.align	2

se_m_hyper_beam2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_hyper_beam2_pri	@ Priority
	.byte	se_m_hyper_beam2_rev	@ Reverb.

	.word	se_m_hyper_beam2_grp

	.word	se_m_hyper_beam2_1
	.word	se_m_hyper_beam2_2

	.end
