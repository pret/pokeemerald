	.include "MPlayDef.s"

	.equ	se_w103_grp, voicegroup128
	.equ	se_w103_pri, 4
	.equ	se_w103_rev, reverb_set+50
	.equ	se_w103_mvl, 127
	.equ	se_w103_key, 0
	.equ	se_w103_tbs, 1
	.equ	se_w103_exg, 0
	.equ	se_w103_cmp, 1

	.section .rodata
	.global	se_w103
	.align	2

@********************** Track  1 **********************@

se_w103_1:
	.byte		VOL   , 110*se_w103_mvl/mxv
	.byte	KEYSH , se_w103_key+0
	.byte	TEMPO , 150*se_w103_tbs/2
	.byte		VOICE , 44
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N21   , Fs5 , v112
	.byte	W01
	.byte		PAN   , c_v-5
	.byte	W01
	.byte		        c_v-10
	.byte		VOL   , 15*se_w103_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		VOL   , 41*se_w103_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 69*se_w103_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		        c_v+10
	.byte		VOL   , 84*se_w103_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 97*se_w103_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-5
	.byte	W02
	.byte		VOL   , 110*se_w103_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+10
	.byte	W02
	.byte		VOL   , 100*se_w103_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 84*se_w103_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 55*se_w103_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_w103_2:
	.byte		VOL   , 110*se_w103_mvl/mxv
	.byte	KEYSH , se_w103_key+0
	.byte		VOICE , 42
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N21   , Fn6 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte	W01
	.byte		        c_v+0
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_w103:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w103_pri	@ Priority
	.byte	se_w103_rev	@ Reverb.

	.word	se_w103_grp

	.word	se_w103_1
	.word	se_w103_2

	.end
