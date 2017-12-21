	.include "MPlayDef.s"

	.equ	se_pc_logon_grp, voicegroup_869D0F4
	.equ	se_pc_logon_pri, 5
	.equ	se_pc_logon_rev, reverb_set+50
	.equ	se_pc_logon_mvl, 127
	.equ	se_pc_logon_key, 0
	.equ	se_pc_logon_tbs, 1
	.equ	se_pc_logon_exg, 0
	.equ	se_pc_logon_cmp, 1

	.section .rodata
	.global	se_pc_logon
	.align	2

@********************** Track  1 **********************@

se_pc_logon_1:
	.byte	KEYSH , se_pc_logon_key+0
	.byte	TEMPO , 144*se_pc_logon_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_pc_logon_mvl/mxv
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

se_pc_logon:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pc_logon_pri	@ Priority
	.byte	se_pc_logon_rev	@ Reverb.

	.word	se_pc_logon_grp

	.word	se_pc_logon_1

	.end
