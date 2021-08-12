	.include "MPlayDef.s"

	.equ	se_m_swagger_grp, voicegroup128
	.equ	se_m_swagger_pri, 4
	.equ	se_m_swagger_rev, reverb_set+50
	.equ	se_m_swagger_mvl, 127
	.equ	se_m_swagger_key, 0
	.equ	se_m_swagger_tbs, 1
	.equ	se_m_swagger_exg, 0
	.equ	se_m_swagger_cmp, 1

	.section .rodata
	.global	se_m_swagger
	.align	2

@********************** Track  1 **********************@

se_m_swagger_1:
	.byte	KEYSH , se_m_swagger_key+0
	.byte	TEMPO , 190*se_m_swagger_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 28*se_m_swagger_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N15   , An1 , v127
	.byte	W01
	.byte		VOL   , 60*se_m_swagger_mvl/mxv
	.byte	W01
	.byte		        111*se_m_swagger_mvl/mxv
	.byte	W01
	.byte		        120*se_m_swagger_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 109*se_m_swagger_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-10
	.byte	W01
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-14
	.byte	W01
	.byte		VOL   , 95*se_m_swagger_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-19
	.byte	W02
	.byte		VOL   , 71*se_m_swagger_mvl/mxv
	.byte		BEND  , c_v-29
	.byte	W01
	.byte		VOL   , 41*se_m_swagger_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W01
	.byte		VOL   , 15*se_m_swagger_mvl/mxv
	.byte		BEND  , c_v-52
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_m_swagger:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_swagger_pri	@ Priority
	.byte	se_m_swagger_rev	@ Reverb.

	.word	se_m_swagger_grp

	.word	se_m_swagger_1

	.end
