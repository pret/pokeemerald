	.include "MPlayDef.s"

	.equ	se_m_psybeam2_grp, voicegroup128
	.equ	se_m_psybeam2_pri, 4
	.equ	se_m_psybeam2_rev, reverb_set+50
	.equ	se_m_psybeam2_mvl, 127
	.equ	se_m_psybeam2_key, 0
	.equ	se_m_psybeam2_tbs, 1
	.equ	se_m_psybeam2_exg, 0
	.equ	se_m_psybeam2_cmp, 1

	.section .rodata
	.global	se_m_psybeam2
	.align	2

@********************** Track  1 **********************@

se_m_psybeam2_1:
	.byte	KEYSH , se_m_psybeam2_key+0
	.byte	TEMPO , 190*se_m_psybeam2_tbs/2
	.byte		VOICE , 45
	.byte		BENDR , 8
	.byte		VOL   , 36*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-44
	.byte		N12   , Gs2 , v127
	.byte	W01
	.byte		VOL   , 52*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 67*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 78*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+44
	.byte	W02
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		VOL   , 86*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+28
	.byte	W01
	.byte		VOL   , 55*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 33*se_m_psybeam2_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W02
	.byte		VOICE , 37
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		N02   , Gs3 , v080
	.byte	W01
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		VOICE , 45
	.byte		VOL   , 36*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-44
	.byte		N12   , As2 , v127
	.byte	W01
	.byte		VOL   , 52*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 67*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+17
	.byte	W02
	.byte		VOL   , 78*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		PAN   , c_v-11
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		VOL   , 86*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+28
	.byte	W02
	.byte		VOL   , 55*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 33*se_m_psybeam2_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOICE , 37
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		N02   , As3 , v056
	.byte	W01
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		VOICE , 45
	.byte		VOL   , 36*se_m_psybeam2_mvl/mxv
	.byte		BEND  , c_v-44
	.byte		N12   , Gs2 , v080
	.byte	W02
	.byte		VOL   , 52*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 67*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 78*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+63
	.byte	W02
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		VOL   , 86*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+28
	.byte	W01
	.byte		VOL   , 55*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 33*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOICE , 37
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		N02   , Gs3 , v024
	.byte	W02
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		VOICE , 45
	.byte		VOL   , 36*se_m_psybeam2_mvl/mxv
	.byte		BEND  , c_v-44
	.byte		N12   , As2 , v040
	.byte	W01
	.byte		VOL   , 52*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 67*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 78*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+27
	.byte	W02
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		PAN   , c_v-11
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		VOL   , 86*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+28
	.byte	W01
	.byte		VOL   , 55*se_m_psybeam2_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+17
	.byte	W02
	.byte		VOL   , 33*se_m_psybeam2_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOICE , 37
	.byte		VOL   , 105*se_m_psybeam2_mvl/mxv
	.byte		N02   , As3 , v016
	.byte	W01
	.byte		BEND  , c_v+16
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_m_psybeam2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_psybeam2_pri	@ Priority
	.byte	se_m_psybeam2_rev	@ Reverb.

	.word	se_m_psybeam2_grp

	.word	se_m_psybeam2_1

	.end
