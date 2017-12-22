	.include "MPlayDef.s"

	.equ	se_c_maku_u_grp, voicegroup_869D6F4
	.equ	se_c_maku_u_pri, 5
	.equ	se_c_maku_u_rev, reverb_set+50
	.equ	se_c_maku_u_mvl, 127
	.equ	se_c_maku_u_key, 0
	.equ	se_c_maku_u_tbs, 1
	.equ	se_c_maku_u_exg, 0
	.equ	se_c_maku_u_cmp, 1

	.section .rodata
	.global	se_c_maku_u
	.align	2

@********************** Track  1 **********************@

se_c_maku_u_1:
	.byte	KEYSH , se_c_maku_u_key+0
	.byte	TEMPO , 150*se_c_maku_u_tbs/2
	.byte		VOICE , 25
	.byte		VOL   , 12*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Gs4 , v060
	.byte	W01
	.byte		VOL   , 22*se_c_maku_u_mvl/mxv
	.byte	W01
	.byte		        33*se_c_maku_u_mvl/mxv
	.byte	W01
	.byte		        46*se_c_maku_u_mvl/mxv
	.byte	W01
	.byte		        58*se_c_maku_u_mvl/mxv
	.byte	W02
	.byte		        70*se_c_maku_u_mvl/mxv
	.byte	W02
	.byte		        60*se_c_maku_u_mvl/mxv
	.byte	W01
	.byte		        42*se_c_maku_u_mvl/mxv
	.byte	W01
	.byte		        22*se_c_maku_u_mvl/mxv
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_c_maku_u_2:
	.byte	KEYSH , se_c_maku_u_key+0
	.byte		VOICE , 15
	.byte		VOL   , 12*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Fn3 , v100
	.byte	W01
	.byte		VOL   , 22*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 33*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		VOL   , 46*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		VOL   , 58*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		VOL   , 70*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		        c_v+20
	.byte	W01
	.byte		VOL   , 60*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		VOL   , 42*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+32
	.byte	W01
	.byte		VOL   , 22*se_c_maku_u_mvl/mxv
	.byte		BEND  , c_v+38
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_c_maku_u:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_c_maku_u_pri	@ Priority
	.byte	se_c_maku_u_rev	@ Reverb.

	.word	se_c_maku_u_grp

	.word	se_c_maku_u_1
	.word	se_c_maku_u_2

	.end
