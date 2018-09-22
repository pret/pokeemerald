	.include "MPlayDef.s"

	.equ	se_w062_grp, voicegroup128
	.equ	se_w062_pri, 4
	.equ	se_w062_rev, reverb_set+50
	.equ	se_w062_mvl, 127
	.equ	se_w062_key, 0
	.equ	se_w062_tbs, 1
	.equ	se_w062_exg, 0
	.equ	se_w062_cmp, 1

	.section .rodata
	.global	se_w062
	.align	2

@********************** Track  1 **********************@

se_w062_1:
	.byte	KEYSH , se_w062_key+0
	.byte	TEMPO , 150*se_w062_tbs/2
	.byte		VOICE , 9
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 24*se_w062_mvl/mxv
	.byte		BEND  , c_v-17
	.byte		N78   , Bn4 , v080
	.byte	W01
	.byte		VOL   , 32*se_w062_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		VOL   , 38*se_w062_mvl/mxv
	.byte		PAN   , c_v-7
	.byte	W01
	.byte		VOL   , 48*se_w062_mvl/mxv
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		VOL   , 66*se_w062_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W02
	.byte		VOL   , 78*se_w062_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		VOL   , 94*se_w062_mvl/mxv
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		VOL   , 110*se_w062_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-7
	.byte	W02
se_w062_1_000:
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte	PEND
se_w062_1_001:
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v+9
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+6
	.byte	W02
	.byte	PEND
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v+9
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v+9
	.byte	W01
	.byte		        c_v-13
	.byte	W02
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v-7
	.byte	W02
	.byte	PATT
	 .word	se_w062_1_000
	.byte	PATT
	 .word	se_w062_1_001
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		VOL   , 103*se_w062_mvl/mxv
	.byte		PAN   , c_v-7
	.byte	W01
	.byte		VOL   , 91*se_w062_mvl/mxv
	.byte		PAN   , c_v+9
	.byte	W02
	.byte		VOL   , 72*se_w062_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W01
	.byte		VOL   , 58*se_w062_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		VOL   , 38*se_w062_mvl/mxv
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		VOL   , 15*se_w062_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 7*se_w062_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_w062:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w062_pri	@ Priority
	.byte	se_w062_rev	@ Reverb.

	.word	se_w062_grp

	.word	se_w062_1

	.end
