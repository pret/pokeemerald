	.include "MPlayDef.s"

	.equ	se_w127_grp, voicegroup128
	.equ	se_w127_pri, 4
	.equ	se_w127_rev, reverb_set+50
	.equ	se_w127_mvl, 127
	.equ	se_w127_key, 0
	.equ	se_w127_tbs, 1
	.equ	se_w127_exg, 0
	.equ	se_w127_cmp, 1

	.section .rodata
	.global	se_w127
	.align	2

@********************** Track  1 **********************@

se_w127_1:
	.byte	KEYSH , se_w127_key+0
	.byte	TEMPO , 150*se_w127_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 115*se_w127_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N60   , Gn2 , v127
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v-16
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-14
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v-11
	.byte	W02
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-8
	.byte	W04
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-2
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+4
	.byte	W04
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v+7
	.byte	W02
	.byte		VOL   , 109*se_w127_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+10
	.byte	W02
	.byte		VOL   , 103*se_w127_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v+13
	.byte	W03
	.byte		VOL   , 92*se_w127_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		VOL   , 79*se_w127_mvl/mxv
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+18
	.byte	W02
	.byte	W02
	.byte		VOL   , 62*se_w127_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+21
	.byte	W04
	.byte		VOL   , 40*se_w127_mvl/mxv
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+26
	.byte	W02
	.byte		VOL   , 22*se_w127_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 8*se_w127_mvl/mxv
	.byte		BEND  , c_v+43
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_w127_2:
	.byte	KEYSH , se_w127_key+0
	.byte		VOICE , 25
	.byte		VOL   , 115*se_w127_mvl/mxv
	.byte		N06   , Cn3 , v040
	.byte	W06
	.byte		        Gn2 
	.byte	W06
se_w127_2_000:
	.byte		N06   , Cn3 , v040
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	se_w127_2_000
	.byte		N06   , Cn3 , v032
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 , v012
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_w127:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w127_pri	@ Priority
	.byte	se_w127_rev	@ Reverb.

	.word	se_w127_grp

	.word	se_w127_1
	.word	se_w127_2

	.end
