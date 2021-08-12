	.include "MPlayDef.s"

	.equ	se_m_encore2_grp, voicegroup128
	.equ	se_m_encore2_pri, 4
	.equ	se_m_encore2_rev, reverb_set+50
	.equ	se_m_encore2_mvl, 127
	.equ	se_m_encore2_key, 0
	.equ	se_m_encore2_tbs, 1
	.equ	se_m_encore2_exg, 0
	.equ	se_m_encore2_cmp, 1

	.section .rodata
	.global	se_m_encore2
	.align	2

@********************** Track  1 **********************@

se_m_encore2_1:
	.byte	KEYSH , se_m_encore2_key+0
	.byte	TEMPO , 150*se_m_encore2_tbs/2
	.byte		VOICE , 60
	.byte		BENDR , 12
	.byte		VOL   , 25*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Cn3 , v127
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 34*se_m_encore2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 46*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		VOL   , 56*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 70*se_m_encore2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 80*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		VOL   , 88*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		VOL   , 96*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		VOL   , 100*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
se_m_encore2_1_000:
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte	PEND
	.byte	PATT
	 .word	se_m_encore2_1_000
	.byte	PATT
	 .word	se_m_encore2_1_000
	.byte	PATT
	 .word	se_m_encore2_1_000
	.byte	PATT
	 .word	se_m_encore2_1_000
	.byte	PATT
	 .word	se_m_encore2_1_000
	.byte	PATT
	 .word	se_m_encore2_1_000
	.byte		VOL   , 96*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 92*se_m_encore2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 84*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		VOL   , 72*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		VOL   , 63*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		VOL   , 52*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 37*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W01
	.byte		VOL   , 22*se_m_encore2_mvl/mxv
	.byte	W01
	.byte		        12*se_m_encore2_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

se_m_encore2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_encore2_pri	@ Priority
	.byte	se_m_encore2_rev	@ Reverb.

	.word	se_m_encore2_grp

	.word	se_m_encore2_1

	.end
