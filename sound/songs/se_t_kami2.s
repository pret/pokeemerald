	.include "MPlayDef.s"

	.equ	se_t_kami2_grp, voicegroup128
	.equ	se_t_kami2_pri, 3
	.equ	se_t_kami2_rev, reverb_set+50
	.equ	se_t_kami2_mvl, 127
	.equ	se_t_kami2_key, 0
	.equ	se_t_kami2_tbs, 1
	.equ	se_t_kami2_exg, 0
	.equ	se_t_kami2_cmp, 1

	.section .rodata
	.global	se_t_kami2
	.align	2

@********************** Track  1 **********************@

se_t_kami2_1:
	.byte	KEYSH , se_t_kami2_key+0
	.byte	TEMPO , 220*se_t_kami2_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_t_kami2_mvl/mxv
	.byte		BEND  , c_v+35
	.byte		TIE   , Dn2 , v112
	.byte	W03
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v+6
	.byte	W06
	.byte		        c_v+0
	.byte	W09
	.byte	W15
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-4
	.byte	W03
	.byte	W06
	.byte		        c_v-13
	.byte	W09
	.byte		        c_v-18
	.byte	W09
	.byte		VOL   , 102*se_t_kami2_mvl/mxv
	.byte		BEND  , c_v-25
	.byte	W09
	.byte		VOL   , 97*se_t_kami2_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W09
	.byte		VOL   , 92*se_t_kami2_mvl/mxv
	.byte		BEND  , c_v-45
	.byte	W06
	.byte	W03
	.byte		VOL   , 83*se_t_kami2_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v-52
	.byte	W03
	.byte		VOL   , 64*se_t_kami2_mvl/mxv
	.byte	W06
	.byte		        47*se_t_kami2_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_t_kami2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_t_kami2_pri	@ Priority
	.byte	se_t_kami2_rev	@ Reverb.

	.word	se_t_kami2_grp

	.word	se_t_kami2_1

	.end
