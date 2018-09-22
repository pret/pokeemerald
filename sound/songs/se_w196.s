	.include "MPlayDef.s"

	.equ	se_w196_grp, voicegroup128
	.equ	se_w196_pri, 4
	.equ	se_w196_rev, reverb_set+50
	.equ	se_w196_mvl, 127
	.equ	se_w196_key, 0
	.equ	se_w196_tbs, 1
	.equ	se_w196_exg, 0
	.equ	se_w196_cmp, 1

	.section .rodata
	.global	se_w196
	.align	2

@********************** Track  1 **********************@

se_w196_1:
	.byte	KEYSH , se_w196_key+0
	.byte	TEMPO , 150*se_w196_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 100*se_w196_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Ds4 , v112
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		N01   , Bn4 , v040
	.byte	W04
	.byte		PAN   , c_v-5
	.byte		N01   , Ds4 , v112
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Bn4 
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_w196_2:
	.byte	KEYSH , se_w196_key+0
	.byte		VOICE , 5
	.byte		VOL   , 100*se_w196_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Dn4 , v040
	.byte	W04
	.byte		        Bn3 
	.byte	W02
	.byte		PAN   , c_v-7
	.byte	W02
	.byte		        c_v+9
	.byte	W01
	.byte		N01   , Dn4 
	.byte	W01
	.byte		PAN   , c_v-7
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_w196:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w196_pri	@ Priority
	.byte	se_w196_rev	@ Reverb.

	.word	se_w196_grp

	.word	se_w196_1
	.word	se_w196_2

	.end
