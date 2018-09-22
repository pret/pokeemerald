	.include "MPlayDef.s"

	.equ	se_tama_grp, voicegroup128
	.equ	se_tama_pri, 5
	.equ	se_tama_rev, reverb_set+50
	.equ	se_tama_mvl, 127
	.equ	se_tama_key, 0
	.equ	se_tama_tbs, 1
	.equ	se_tama_exg, 0
	.equ	se_tama_cmp, 1

	.section .rodata
	.global	se_tama
	.align	2

@********************** Track  1 **********************@

se_tama_1:
	.byte	KEYSH , se_tama_key+0
	.byte	TEMPO , 110*se_tama_tbs/2
	.byte		VOICE , 15
	.byte		BENDR , 12
	.byte		VOL   , 100*se_tama_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+30
	.byte		TIE   , Cn4 , v100
	.byte	W01
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		        c_v+19
	.byte	W01
	.byte		        c_v+14
	.byte	W01
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+0
	.byte	W04
	.byte	W04
	.byte		        c_v+1
	.byte	W02
	.byte	W06
	.byte		        c_v+1
	.byte	W06
	.byte		        c_v+1
	.byte	W06
	.byte		        c_v+2
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+5
	.byte	W06
	.byte		        c_v+6
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+10
	.byte	W06
	.byte		        c_v+12
	.byte	W06
	.byte		        c_v+14
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+18
	.byte	W06
	.byte		        c_v+20
	.byte	W06
	.byte		VOL   , 98*se_tama_mvl/mxv
	.byte		BEND  , c_v+22
	.byte	W03
	.byte		VOL   , 97*se_tama_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		VOL   , 94*se_tama_mvl/mxv
	.byte	W03
	.byte		        91*se_tama_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+26
	.byte	W02
	.byte		VOL   , 88*se_tama_mvl/mxv
	.byte	W02
	.byte		        85*se_tama_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+28
	.byte	W02
	.byte		VOL   , 80*se_tama_mvl/mxv
	.byte	W02
	.byte		        73*se_tama_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+30
	.byte	W01
	.byte		VOL   , 68*se_tama_mvl/mxv
	.byte	W02
	.byte		        62*se_tama_mvl/mxv
	.byte	W03
	.byte		        55*se_tama_mvl/mxv
	.byte		BEND  , c_v+32
	.byte	W02
	.byte		VOL   , 47*se_tama_mvl/mxv
	.byte	W02
	.byte		        37*se_tama_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+36
	.byte	W01
	.byte		VOL   , 30*se_tama_mvl/mxv
	.byte	W01
	.byte		        20*se_tama_mvl/mxv
	.byte	W01
	.byte		        13*se_tama_mvl/mxv
	.byte	W01
	.byte		        4*se_tama_mvl/mxv
	.byte	W02
	.byte		EOT   
	.byte	FINE

@********************** Track  2 **********************@

se_tama_2:
	.byte	KEYSH , se_tama_key+0
	.byte		VOICE , 25
	.byte		VOL   , 15*se_tama_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Gs2 , v060
	.byte	W01
	.byte		VOL   , 21*se_tama_mvl/mxv
	.byte	W01
	.byte		        33*se_tama_mvl/mxv
	.byte	W01
	.byte		        41*se_tama_mvl/mxv
	.byte	W01
	.byte		        49*se_tama_mvl/mxv
	.byte	W02
	.byte		        55*se_tama_mvl/mxv
	.byte	W01
	.byte		        61*se_tama_mvl/mxv
	.byte	W01
	.byte		        69*se_tama_mvl/mxv
	.byte	W01
	.byte		        76*se_tama_mvl/mxv
	.byte	W01
	.byte		        80*se_tama_mvl/mxv
	.byte	W02
	.byte		        86*se_tama_mvl/mxv
	.byte	W01
	.byte		        90*se_tama_mvl/mxv
	.byte	W01
	.byte		        100*se_tama_mvl/mxv
	.byte	W04
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
	.byte		BEND  , c_v+1
	.byte	W05
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W02
	.byte		        c_v+2
	.byte	W04
	.byte	W01
	.byte		        c_v+4
	.byte	W05
	.byte		        c_v+5
	.byte	W03
	.byte		VOL   , 97*se_tama_mvl/mxv
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		VOL   , 94*se_tama_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		VOL   , 87*se_tama_mvl/mxv
	.byte	W02
	.byte		        83*se_tama_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W02
	.byte	W01
	.byte		VOL   , 77*se_tama_mvl/mxv
	.byte		BEND  , c_v+10
	.byte	W02
	.byte		VOL   , 66*se_tama_mvl/mxv
	.byte		BEND  , c_v+14
	.byte	W03
	.byte		VOL   , 55*se_tama_mvl/mxv
	.byte		BEND  , c_v+17
	.byte	W02
	.byte		VOL   , 45*se_tama_mvl/mxv
	.byte		BEND  , c_v+24
	.byte	W02
	.byte		VOL   , 33*se_tama_mvl/mxv
	.byte		BEND  , c_v+30
	.byte	W02
	.byte		        c_v+41
	.byte	W01
	.byte		VOL   , 21*se_tama_mvl/mxv
	.byte		BEND  , c_v+46
	.byte	W01
	.byte		        c_v+55
	.byte	W01
	.byte		VOL   , 11*se_tama_mvl/mxv
	.byte		BEND  , c_v+60
	.byte	W01
	.byte		VOL   , 5*se_tama_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W02
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_tama:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tama_pri	@ Priority
	.byte	se_tama_rev	@ Reverb.

	.word	se_tama_grp

	.word	se_tama_1
	.word	se_tama_2

	.end
