	.include "MPlayDef.s"

	.equ	se_exp_grp, voicegroup127
	.equ	se_exp_pri, 5
	.equ	se_exp_rev, reverb_set+50
	.equ	se_exp_mvl, 127
	.equ	se_exp_key, 0
	.equ	se_exp_tbs, 1
	.equ	se_exp_exg, 0
	.equ	se_exp_cmp, 1

	.section .rodata
	.global	se_exp
	.align	2

@********************** Track  1 **********************@

se_exp_1:
	.byte	KEYSH , se_exp_key+0
	.byte	TEMPO , 240*se_exp_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 26
	.byte		VOL   , 80*se_exp_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Fn3 , v112
	.byte	W01
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		        c_v+16
	.byte	W01
	.byte		        c_v+22
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		        c_v+38
	.byte	W01
	.byte		VOL   , 71*se_exp_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		        c_v+16
	.byte	W01
	.byte		        c_v+22
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		        c_v+38
	.byte	W01
	.byte		        c_v+15
	.byte	W01
	.byte		VOL   , 50*se_exp_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+3
	.byte	W01
	.byte		VOL   , 51*se_exp_mvl/mxv
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v+4
	.byte	W02
	.byte		VOL   , 52*se_exp_mvl/mxv
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v+7
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 52*se_exp_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W02
	.byte		        c_v+8
	.byte	W01
	.byte		        c_v+7
	.byte	W01
	.byte		        c_v+10
	.byte	W01
	.byte		VOL   , 54*se_exp_mvl/mxv
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+12
	.byte	W01
	.byte		        c_v+12
	.byte	W01
	.byte		VOL   , 55*se_exp_mvl/mxv
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		        c_v+14
	.byte	W01
	.byte		        c_v+13
	.byte	W02
	.byte		        c_v+12
	.byte	W01
	.byte		VOL   , 56*se_exp_mvl/mxv
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		        c_v+15
	.byte	W01
	.byte		        c_v+14
	.byte	W01
	.byte		        c_v+17
	.byte	W02
	.byte		VOL   , 57*se_exp_mvl/mxv
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		        c_v+16
	.byte	W01
	.byte		        c_v+20
	.byte	W01
	.byte		        c_v+19
	.byte	W01
	.byte		VOL   , 57*se_exp_mvl/mxv
	.byte		BEND  , c_v+19
	.byte	W02
	.byte		        c_v+21
	.byte	W01
	.byte		        c_v+20
	.byte	W01
	.byte		        c_v+20
	.byte	W01
	.byte		VOL   , 59*se_exp_mvl/mxv
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		        c_v+22
	.byte	W02
	.byte		        c_v+21
	.byte	W01
	.byte		        c_v+25
	.byte	W01
	.byte		VOL   , 60*se_exp_mvl/mxv
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+26
	.byte	W02
	.byte		        c_v+25
	.byte	W01
	.byte		VOL   , 61*se_exp_mvl/mxv
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+26
	.byte	W02
	.byte		VOL   , 62*se_exp_mvl/mxv
	.byte		BEND  , c_v+30
	.byte	W01
	.byte		        c_v+29
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+32
	.byte	W01
	.byte		VOL   , 62*se_exp_mvl/mxv
	.byte		BEND  , c_v+30
	.byte	W02
	.byte		        c_v+30
	.byte	W01
	.byte		        c_v+33
	.byte	W01
	.byte		        c_v+32
	.byte	W01
	.byte		VOL   , 64*se_exp_mvl/mxv
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+35
	.byte	W02
	.byte		        c_v+34
	.byte	W01
	.byte		        c_v+33
	.byte	W01
	.byte		VOL   , 65*se_exp_mvl/mxv
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		        c_v+36
	.byte	W01
	.byte		        c_v+35
	.byte	W02
	.byte		        c_v+39
	.byte	W01
	.byte		VOL   , 66*se_exp_mvl/mxv
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+40
	.byte	W01
	.byte		        c_v+39
	.byte	W02
	.byte		VOL   , 67*se_exp_mvl/mxv
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+42
	.byte	W01
	.byte		        c_v+41
	.byte	W01
	.byte		        c_v+40
	.byte	W01
	.byte		VOL   , 68*se_exp_mvl/mxv
	.byte		BEND  , c_v+44
	.byte	W02
	.byte		        c_v+43
	.byte	W01
	.byte		        c_v+42
	.byte	W01
	.byte		        c_v+46
	.byte	W01
	.byte		VOL   , 69*se_exp_mvl/mxv
	.byte		BEND  , c_v+45
	.byte	W01
	.byte		        c_v+44
	.byte	W02
	.byte		        c_v+48
	.byte	W01
	.byte		        c_v+46
	.byte	W01
	.byte		VOL   , 70*se_exp_mvl/mxv
	.byte		BEND  , c_v+45
	.byte	W01
	.byte		        c_v+49
	.byte	W01
	.byte		        c_v+48
	.byte	W02
	.byte		        c_v+48
	.byte	W01
	.byte		VOL   , 71*se_exp_mvl/mxv
	.byte		BEND  , c_v+51
	.byte	W01
	.byte		        c_v+50
	.byte	W01
	.byte		        c_v+49
	.byte	W01
	.byte		        c_v+53
	.byte	W02
	.byte		VOL   , 72*se_exp_mvl/mxv
	.byte		BEND  , c_v+52
	.byte	W01
	.byte		        c_v+51
	.byte	W01
	.byte		        c_v+55
	.byte	W01
	.byte		        c_v+53
	.byte	W01
	.byte		VOL   , 73*se_exp_mvl/mxv
	.byte		BEND  , c_v+52
	.byte	W02
	.byte		        c_v+56
	.byte	W01
	.byte		        c_v+55
	.byte	W01
	.byte		        c_v+54
	.byte	W01
	.byte		VOL   , 74*se_exp_mvl/mxv
	.byte		BEND  , c_v+58
	.byte	W01
	.byte		        c_v+57
	.byte	W02
	.byte		        c_v+56
	.byte	W01
	.byte		        c_v+59
	.byte	W01
	.byte		VOL   , 75*se_exp_mvl/mxv
	.byte		BEND  , c_v+59
	.byte	W01
	.byte		        c_v+58
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		        c_v+61
	.byte	W01
	.byte		VOL   , 76*se_exp_mvl/mxv
	.byte		BEND  , c_v+60
	.byte	W01
	.byte		        c_v+63
	.byte	W01
	.byte		        c_v+62
	.byte	W01
	.byte		        c_v+61
	.byte	W02
	.byte		VOL   , 77*se_exp_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		        c_v+62
	.byte	W01
	.byte		        c_v+61
	.byte	W01
	.byte		        c_v+63
	.byte	W01
	.byte		VOL   , 78*se_exp_mvl/mxv
	.byte		BEND  , c_v+62
	.byte	W02
	.byte		        c_v+61
	.byte	W01
	.byte		        c_v+63
	.byte	W01
	.byte		        c_v+62
	.byte	W01
	.byte		VOL   , 79*se_exp_mvl/mxv
	.byte		BEND  , c_v+61
	.byte	W01
	.byte		        c_v+63
	.byte	W02
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_exp:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_exp_pri	@ Priority
	.byte	se_exp_rev	@ Reverb.

	.word	se_exp_grp

	.word	se_exp_1

	.end
