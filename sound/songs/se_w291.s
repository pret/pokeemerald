	.include "MPlayDef.s"

	.equ	se_w291_grp, voicegroup128
	.equ	se_w291_pri, 4
	.equ	se_w291_rev, reverb_set+50
	.equ	se_w291_mvl, 127
	.equ	se_w291_key, 0
	.equ	se_w291_tbs, 1
	.equ	se_w291_exg, 0
	.equ	se_w291_cmp, 1

	.section .rodata
	.global	se_w291
	.align	2

@********************** Track  1 **********************@

se_w291_1:
	.byte	KEYSH , se_w291_key+0
	.byte	TEMPO , 150*se_w291_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*se_w291_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N06   , Fn2 , v127
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v-16
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-14
	.byte		N04   
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		N36   , Gn3 , v092
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-8
	.byte	W04
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		VOL   , 100*se_w291_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		VOL   , 94*se_w291_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+1
	.byte	W02
	.byte		VOL   , 84*se_w291_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+4
	.byte	W04
	.byte		PAN   , c_v+3
	.byte		VOL   , 72*se_w291_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		VOL   , 57*se_w291_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		VOL   , 37*se_w291_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		VOL   , 20*se_w291_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		VOL   , 7*se_w291_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v-16
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_w291_2:
	.byte	KEYSH , se_w291_key+0
	.byte		VOICE , 25
	.byte		VOL   , 105*se_w291_mvl/mxv
	.byte		N06   , An2 , v040
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs3 , v044
	.byte	W07
	.byte		        Gs3 , v036
	.byte	W05
	.byte	W02
	.byte		        Gs3 , v028
	.byte	W07
	.byte		        Gs3 , v020
	.byte	W03
	.byte	W04
	.byte		        Gs3 , v012
	.byte	W08
	.byte	FINE

@******************************************************@
	.align	2

se_w291:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w291_pri	@ Priority
	.byte	se_w291_rev	@ Reverb.

	.word	se_w291_grp

	.word	se_w291_1
	.word	se_w291_2

	.end
