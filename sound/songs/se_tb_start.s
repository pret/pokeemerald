	.include "MPlayDef.s"

	.equ	se_tb_start_grp, voicegroup_869D6F4
	.equ	se_tb_start_pri, 5
	.equ	se_tb_start_rev, reverb_set+50
	.equ	se_tb_start_mvl, 127
	.equ	se_tb_start_key, 0
	.equ	se_tb_start_tbs, 1
	.equ	se_tb_start_exg, 0
	.equ	se_tb_start_cmp, 1

	.section .rodata
	.global	se_tb_start
	.align	2

@********************** Track  1 **********************@

se_tb_start_1:
	.byte	KEYSH , se_tb_start_key+0
	.byte	TEMPO , 150*se_tb_start_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 16*se_tb_start_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N09   , Gn5 , v032
	.byte	W01
	.byte		VOL   , 63*se_tb_start_mvl/mxv
	.byte	W01
	.byte		        98*se_tb_start_mvl/mxv
	.byte	W01
	.byte		        110*se_tb_start_mvl/mxv
	.byte	W01
	.byte		        99*se_tb_start_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W02
	.byte		VOL   , 63*se_tb_start_mvl/mxv
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 22*se_tb_start_mvl/mxv
	.byte		BEND  , c_v+21
	.byte	W01
	.byte		VOL   , 9*se_tb_start_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_tb_start_2:
	.byte	KEYSH , se_tb_start_key+0
	.byte		VOICE , 71
	.byte		PAN   , c_v+32
	.byte		VOL   , 110*se_tb_start_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N09   , Fs4 , v060
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_tb_start:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tb_start_pri	@ Priority
	.byte	se_tb_start_rev	@ Reverb.

	.word	se_tb_start_grp

	.word	se_tb_start_1
	.word	se_tb_start_2

	.end
