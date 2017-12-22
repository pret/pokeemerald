	.include "MPlayDef.s"

	.equ	se_w028_grp, voicegroup_869D6F4
	.equ	se_w028_pri, 4
	.equ	se_w028_rev, reverb_set+50
	.equ	se_w028_mvl, 127
	.equ	se_w028_key, 0
	.equ	se_w028_tbs, 1
	.equ	se_w028_exg, 0
	.equ	se_w028_cmp, 1

	.section .rodata
	.global	se_w028
	.align	2

@********************** Track  1 **********************@

se_w028_1:
	.byte	KEYSH , se_w028_key+0
	.byte	TEMPO , 150*se_w028_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w028_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Gn5 , v092
	.byte	W02
	.byte		        Cn5 
	.byte	W04
	.byte		VOICE , 36
	.byte		VOL   , 84*se_w028_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		N15   , Gn5 , v040
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		VOL   , 94*se_w028_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		VOL   , 110*se_w028_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W02
	.byte		VOL   , 96*se_w028_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		VOL   , 68*se_w028_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		VOL   , 15*se_w028_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_w028_2:
	.byte	KEYSH , se_w028_key+0
	.byte		VOICE , 25
	.byte		VOL   , 110*se_w028_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 , v040
	.byte	W02
	.byte		N01   
	.byte	W22
	.byte	FINE

@******************************************************@
	.align	2

se_w028:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w028_pri	@ Priority
	.byte	se_w028_rev	@ Reverb.

	.word	se_w028_grp

	.word	se_w028_1
	.word	se_w028_2

	.end
