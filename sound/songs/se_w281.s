	.include "MPlayDef.s"

	.equ	se_w281_grp, voicegroup128
	.equ	se_w281_pri, 4
	.equ	se_w281_rev, reverb_set+50
	.equ	se_w281_mvl, 127
	.equ	se_w281_key, 0
	.equ	se_w281_tbs, 1
	.equ	se_w281_exg, 0
	.equ	se_w281_cmp, 1

	.section .rodata
	.global	se_w281
	.align	2

@********************** Track  1 **********************@

se_w281_1:
	.byte		VOL   , 110*se_w281_mvl/mxv
	.byte	KEYSH , se_w281_key+0
	.byte	TEMPO , 150*se_w281_tbs/2
	.byte		VOICE , 61
	.byte		BENDR , 44
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 , v108
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		PAN   , c_v-4
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-3
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_w281_2:
	.byte	KEYSH , se_w281_key+0
	.byte		VOICE , 66
	.byte		BENDR , 44
	.byte		PAN   , c_v+1
	.byte		VOL   , 110*se_w281_mvl/mxv
	.byte		N48   , Dn3 , v020
	.byte	W24
	.byte	W03
	.byte		VOL   , 103*se_w281_mvl/mxv
	.byte	W04
	.byte		        96*se_w281_mvl/mxv
	.byte	W03
	.byte		        83*se_w281_mvl/mxv
	.byte	W04
	.byte		        67*se_w281_mvl/mxv
	.byte	W04
	.byte		        49*se_w281_mvl/mxv
	.byte	W03
	.byte		        23*se_w281_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_w281:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w281_pri	@ Priority
	.byte	se_w281_rev	@ Reverb.

	.word	se_w281_grp

	.word	se_w281_1
	.word	se_w281_2

	.end
