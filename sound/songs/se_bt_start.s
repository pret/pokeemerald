	.include "MPlayDef.s"

	.equ	se_bt_start_grp, voicegroup_869D6F4
	.equ	se_bt_start_pri, 5
	.equ	se_bt_start_rev, reverb_set+50
	.equ	se_bt_start_mvl, 127
	.equ	se_bt_start_key, 0
	.equ	se_bt_start_tbs, 1
	.equ	se_bt_start_exg, 0
	.equ	se_bt_start_cmp, 1

	.section .rodata
	.global	se_bt_start
	.align	2

@********************** Track  1 **********************@

se_bt_start_1:
	.byte	KEYSH , se_bt_start_key+0
	.byte	TEMPO , 110*se_bt_start_tbs/2
	.byte		VOICE , 66
	.byte		BENDR , 12
	.byte		VOL   , 90*se_bt_start_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N90   , Gs3 , v040
	.byte	W06
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W04
	.byte		        c_v+3
	.byte	W02
	.byte	W04
	.byte		        c_v+5
	.byte	W02
	.byte	W04
	.byte		        c_v+8
	.byte	W02
	.byte	W03
	.byte		        c_v+11
	.byte	W03
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte	W02
	.byte		        c_v+24
	.byte	W04
	.byte		        c_v+30
	.byte	W02
	.byte		        c_v+38
	.byte	W02
	.byte		        c_v+43
	.byte	W02
	.byte	W01
	.byte		        c_v+56
	.byte	W02
	.byte		        c_v+63
	.byte	W03
	.byte	W03
	.byte		VOL   , 83*se_bt_start_mvl/mxv
	.byte	W03
	.byte		        75*se_bt_start_mvl/mxv
	.byte	W04
	.byte		        68*se_bt_start_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        55*se_bt_start_mvl/mxv
	.byte	W04
	.byte		        42*se_bt_start_mvl/mxv
	.byte	W01
	.byte	W03
	.byte		        29*se_bt_start_mvl/mxv
	.byte	W03
	.byte		        17*se_bt_start_mvl/mxv
	.byte	W03
	.byte		        8*se_bt_start_mvl/mxv
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_bt_start_2:
	.byte	KEYSH , se_bt_start_key+0
	.byte		VOICE , 2
	.byte		VOL   , 14*se_bt_start_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn3 , v100
	.byte	W01
	.byte		VOL   , 19*se_bt_start_mvl/mxv
	.byte	W01
	.byte		        30*se_bt_start_mvl/mxv
	.byte	W02
	.byte		        37*se_bt_start_mvl/mxv
	.byte	W02
	.byte	W02
	.byte		        44*se_bt_start_mvl/mxv
	.byte	W04
	.byte		        49*se_bt_start_mvl/mxv
	.byte	W04
	.byte		        53*se_bt_start_mvl/mxv
	.byte	W02
	.byte	W03
	.byte		        58*se_bt_start_mvl/mxv
	.byte	W03
	.byte	W02
	.byte		        64*se_bt_start_mvl/mxv
	.byte	W04
	.byte		        68*se_bt_start_mvl/mxv
	.byte	W03
	.byte		        74*se_bt_start_mvl/mxv
	.byte	W03
	.byte	W01
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		VOL   , 81*se_bt_start_mvl/mxv
	.byte	W04
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 90*se_bt_start_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v+4
	.byte	W02
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte	W01
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+6
	.byte	W02
	.byte	W02
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+10
	.byte	W02
	.byte	W01
	.byte		        c_v+14
	.byte	W02
	.byte		        c_v+17
	.byte	W03
	.byte		        c_v+24
	.byte	W02
	.byte		        c_v+30
	.byte	W01
	.byte		        c_v+41
	.byte	W01
	.byte		        c_v+46
	.byte	W02
	.byte		        c_v+55
	.byte	W01
	.byte		        c_v+60
	.byte	W01
	.byte		        c_v+63
	.byte	W01
	.byte		VOL   , 87*se_bt_start_mvl/mxv
	.byte	W03
	.byte		        85*se_bt_start_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W02
	.byte		VOL   , 78*se_bt_start_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W02
	.byte		VOL   , 75*se_bt_start_mvl/mxv
	.byte		PAN   , c_v-6
	.byte	W02
	.byte	W01
	.byte		VOL   , 69*se_bt_start_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		VOL   , 59*se_bt_start_mvl/mxv
	.byte		PAN   , c_v-20
	.byte	W03
	.byte		VOL   , 49*se_bt_start_mvl/mxv
	.byte		PAN   , c_v+22
	.byte	W02
	.byte		VOL   , 41*se_bt_start_mvl/mxv
	.byte		PAN   , c_v-37
	.byte	W02
	.byte		VOL   , 30*se_bt_start_mvl/mxv
	.byte		PAN   , c_v+37
	.byte	W02
	.byte	W01
	.byte		VOL   , 19*se_bt_start_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W02
	.byte		VOL   , 10*se_bt_start_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W01
	.byte		VOL   , 4*se_bt_start_mvl/mxv
	.byte	W02
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_bt_start:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_bt_start_pri	@ Priority
	.byte	se_bt_start_rev	@ Reverb.

	.word	se_bt_start_grp

	.word	se_bt_start_1
	.word	se_bt_start_2

	.end
