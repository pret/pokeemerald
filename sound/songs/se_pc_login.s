	.include "MPlayDef.s"

	.equ	se_pc_login_grp, voicegroup127
	.equ	se_pc_login_pri, 5
	.equ	se_pc_login_rev, reverb_set+50
	.equ	se_pc_login_mvl, 127
	.equ	se_pc_login_key, 0
	.equ	se_pc_login_tbs, 1
	.equ	se_pc_login_exg, 0
	.equ	se_pc_login_cmp, 1

	.section .rodata
	.global	se_pc_login
	.align	2

@********************** Track  1 **********************@

se_pc_login_1:
	.byte	KEYSH , se_pc_login_key+0
	.byte	TEMPO , 144*se_pc_login_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_pc_login_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N08   , Cn4 , v112
	.byte	W08
	.byte		N04   , Cn4 , v028
	.byte	W04
	.byte		N08   , Cn4 , v112
	.byte	W08
	.byte		N04   , Cn4 , v024
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_pc_login:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pc_login_pri	@ Priority
	.byte	se_pc_login_rev	@ Reverb.

	.word	se_pc_login_grp

	.word	se_pc_login_1

	.end
