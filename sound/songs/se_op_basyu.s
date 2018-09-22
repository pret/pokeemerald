	.include "MPlayDef.s"

	.equ	se_op_basyu_grp, voicegroup127
	.equ	se_op_basyu_pri, 5
	.equ	se_op_basyu_rev, reverb_set+50
	.equ	se_op_basyu_mvl, 127
	.equ	se_op_basyu_key, 0
	.equ	se_op_basyu_tbs, 1
	.equ	se_op_basyu_exg, 0
	.equ	se_op_basyu_cmp, 1

	.section .rodata
	.global	se_op_basyu
	.align	2

@********************** Track  1 **********************@

se_op_basyu_1:
	.byte	KEYSH , se_op_basyu_key+0
	.byte	TEMPO , 110*se_op_basyu_tbs/2
	.byte		VOICE , 123
	.byte		BENDR , 12
	.byte		VOL   , 100*se_op_basyu_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N60   , Gs2 , v052
	.byte	W06
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v+1
	.byte	W04
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+3
	.byte	W02
	.byte		        c_v+5
	.byte	W02
	.byte	W01
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+11
	.byte	W02
	.byte		        c_v+13
	.byte	W02
	.byte	W01
	.byte		        c_v+15
	.byte	W02
	.byte		        c_v+17
	.byte	W03
	.byte		        c_v+19
	.byte	W02
	.byte		        c_v+24
	.byte	W02
	.byte		        c_v+27
	.byte	W02
	.byte	W01
	.byte		        c_v+30
	.byte	W02
	.byte		        c_v+38
	.byte	W03
	.byte		        c_v+43
	.byte	W02
	.byte		        c_v+56
	.byte	W02
	.byte		        c_v+63
	.byte	W02
	.byte		        c_v+0
	.byte		N72   , Gs3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W02
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v+2
	.byte	W02
	.byte	W01
	.byte		        c_v+3
	.byte	W02
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+9
	.byte	W02
	.byte		VOL   , 98*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		VOL   , 96*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 92*se_op_basyu_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+15
	.byte	W01
	.byte		VOL   , 92*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 85*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+19
	.byte	W02
	.byte		VOL   , 81*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		VOL   , 74*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		VOL   , 66*se_op_basyu_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+30
	.byte	W01
	.byte		VOL   , 62*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		VOL   , 56*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+43
	.byte	W02
	.byte		VOL   , 50*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+56
	.byte	W01
	.byte		VOL   , 42*se_op_basyu_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		VOL   , 34*se_op_basyu_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        29*se_op_basyu_mvl/mxv
	.byte	W02
	.byte		        25*se_op_basyu_mvl/mxv
	.byte	W03
	.byte		        23*se_op_basyu_mvl/mxv
	.byte	W02
	.byte		        19*se_op_basyu_mvl/mxv
	.byte	W02
	.byte		        14*se_op_basyu_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        11*se_op_basyu_mvl/mxv
	.byte	W02
	.byte		        5*se_op_basyu_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_op_basyu:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_op_basyu_pri	@ Priority
	.byte	se_op_basyu_rev	@ Reverb.

	.word	se_op_basyu_grp

	.word	se_op_basyu_1

	.end
