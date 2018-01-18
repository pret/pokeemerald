	.include "MPlayDef.s"

	.equ	se_c_maku_d_grp, voicegroup_869D6F4
	.equ	se_c_maku_d_pri, 5
	.equ	se_c_maku_d_rev, reverb_set+50
	.equ	se_c_maku_d_mvl, 127
	.equ	se_c_maku_d_key, 0
	.equ	se_c_maku_d_tbs, 1
	.equ	se_c_maku_d_exg, 0
	.equ	se_c_maku_d_cmp, 1

	.section .rodata
	.global	se_c_maku_d
	.align	2

@********************** Track  1 **********************@

se_c_maku_d_1:
	.byte	KEYSH , se_c_maku_d_key+0
	.byte	TEMPO , 150*se_c_maku_d_tbs/2
	.byte		VOICE , 25
	.byte		VOL   , 12*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Gs4 , v060
	.byte	W01
	.byte		VOL   , 22*se_c_maku_d_mvl/mxv
	.byte	W01
	.byte		        33*se_c_maku_d_mvl/mxv
	.byte	W01
	.byte		        46*se_c_maku_d_mvl/mxv
	.byte	W01
	.byte		        58*se_c_maku_d_mvl/mxv
	.byte	W02
	.byte		        70*se_c_maku_d_mvl/mxv
	.byte	W02
	.byte		        60*se_c_maku_d_mvl/mxv
	.byte	W01
	.byte		        42*se_c_maku_d_mvl/mxv
	.byte	W01
	.byte		        22*se_c_maku_d_mvl/mxv
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_c_maku_d_2:
	.byte	KEYSH , se_c_maku_d_key+0
	.byte		VOICE , 15
	.byte		VOL   , 12*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Fn3 , v100
	.byte	W01
	.byte		VOL   , 22*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 33*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		VOL   , 46*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-10
	.byte	W01
	.byte		VOL   , 58*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		VOL   , 70*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-23
	.byte	W01
	.byte		        c_v-31
	.byte	W01
	.byte		VOL   , 60*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W01
	.byte		VOL   , 42*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-48
	.byte	W01
	.byte		VOL   , 22*se_c_maku_d_mvl/mxv
	.byte		BEND  , c_v-55
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_c_maku_d:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_c_maku_d_pri	@ Priority
	.byte	se_c_maku_d_rev	@ Reverb.

	.word	se_c_maku_d_grp

	.word	se_c_maku_d_1
	.word	se_c_maku_d_2

	.end
