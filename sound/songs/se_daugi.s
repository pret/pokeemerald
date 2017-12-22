	.include "MPlayDef.s"

	.equ	se_daugi_grp, voicegroup_869D0F4
	.equ	se_daugi_pri, 5
	.equ	se_daugi_rev, reverb_set+50
	.equ	se_daugi_mvl, 127
	.equ	se_daugi_key, 0
	.equ	se_daugi_tbs, 1
	.equ	se_daugi_exg, 0
	.equ	se_daugi_cmp, 1

	.section .rodata
	.global	se_daugi
	.align	2

@********************** Track  1 **********************@

se_daugi_1:
	.byte	KEYSH , se_daugi_key+0
	.byte	TEMPO , 128*se_daugi_tbs/2
	.byte		VOICE , 89
	.byte		BENDR , 12
	.byte		VOL   , 90*se_daugi_mvl/mxv
	.byte		BEND  , c_v-1
	.byte		N03   , Fs2 , v127
	.byte	W03
	.byte		N01   , Ds3 
	.byte	W03
	.byte		VOICE , 6
	.byte		N03   , Gs3 , v100
	.byte	W03
	.byte	W01
	.byte		N18   , Fn5 , v072
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_daugi_2:
	.byte	KEYSH , se_daugi_key+0
	.byte		VOICE , 14
	.byte		VOL   , 90*se_daugi_mvl/mxv
	.byte		BEND  , c_v-8
	.byte		N03   , Gs3 , v100
	.byte	W03
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte	W01
	.byte		N18   , Fn5 
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_daugi:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_daugi_pri	@ Priority
	.byte	se_daugi_rev	@ Reverb.

	.word	se_daugi_grp

	.word	se_daugi_1
	.word	se_daugi_2

	.end
