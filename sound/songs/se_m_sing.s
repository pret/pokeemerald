	.include "MPlayDef.s"

	.equ	se_m_sing_grp, voicegroup128
	.equ	se_m_sing_pri, 4
	.equ	se_m_sing_rev, reverb_set+50
	.equ	se_m_sing_mvl, 127
	.equ	se_m_sing_key, 0
	.equ	se_m_sing_tbs, 1
	.equ	se_m_sing_exg, 0
	.equ	se_m_sing_cmp, 1

	.section .rodata
	.global	se_m_sing
	.align	2

@********************** Track  1 **********************@

se_m_sing_1:
	.byte	KEYSH , se_m_sing_key+0
	.byte	TEMPO , 100*se_m_sing_tbs/2
	.byte		VOICE , 73
	.byte		BENDR , 12
	.byte		LFOS  , 40
	.byte		PAN   , c_v+0
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N44   , Gn4 , v112
	.byte	W06
	.byte	W06
	.byte	W03
	.byte		MOD   , 7
	.byte	W03
	.byte	W03
	.byte		VOL   , 83*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        69*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        50*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        24*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		N21   , Fn5
	.byte	W06
	.byte	W06
se_m_sing_1_000:
	.byte		VOL   , 86*se_m_sing_mvl/mxv
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 75*se_m_sing_mvl/mxv
	.byte	W03
	.byte	PEND
se_m_sing_1_001:
	.byte		VOL   , 55*se_m_sing_mvl/mxv
	.byte	W03
	.byte		        26*se_m_sing_mvl/mxv
	.byte		MOD   , 0
	.byte	W03
	.byte	PEND
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		N21   , Ds5 , v112
	.byte	W06
	.byte	W06
	.byte	PATT
	 .word	se_m_sing_1_000
	.byte	PATT
	 .word	se_m_sing_1_001
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		N66   , Gn4 , v112
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		VOL   , 83*se_m_sing_mvl/mxv
	.byte	W06
	.byte		        69*se_m_sing_mvl/mxv
	.byte	W06
	.byte		        50*se_m_sing_mvl/mxv
	.byte	W06
	.byte		        24*se_m_sing_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_m_sing_2:
	.byte	KEYSH , se_m_sing_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 40
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		BEND  , c_v+9
	.byte	W06
	.byte	W06
	.byte		PAN   , c_v+12
	.byte		N44   , Gn4 , v060
	.byte	W06
	.byte	W06
	.byte	W03
	.byte		MOD   , 7
	.byte	W03
	.byte	W03
	.byte		VOL   , 83*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        69*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        50*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        24*se_m_sing_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N21   , Fn5
	.byte	W06
	.byte	W06
se_m_sing_2_000:
	.byte		VOL   , 86*se_m_sing_mvl/mxv
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 75*se_m_sing_mvl/mxv
	.byte	W03
	.byte	PEND
se_m_sing_2_001:
	.byte		VOL   , 55*se_m_sing_mvl/mxv
	.byte	W03
	.byte		        26*se_m_sing_mvl/mxv
	.byte		MOD   , 0
	.byte	W03
	.byte	PEND
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		PAN   , c_v+12
	.byte		N21   , Ds5 , v060
	.byte	W06
	.byte	W06
	.byte	PATT
	 .word	se_m_sing_2_000
	.byte	PATT
	 .word	se_m_sing_2_001
	.byte		VOL   , 95*se_m_sing_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N66   , Gn4 , v060
	.byte	W06
	.byte	W06
	.byte		PAN   , c_v-8
	.byte	W06
	.byte	W06
	.byte		MOD   , 7
	.byte		PAN   , c_v+0
	.byte	W06
	.byte	W06
	.byte		        c_v+7
	.byte	W06
	.byte		VOL   , 83*se_m_sing_mvl/mxv
	.byte	W06
	.byte		        69*se_m_sing_mvl/mxv
	.byte		PAN   , c_v+15
	.byte	W06
	.byte		VOL   , 50*se_m_sing_mvl/mxv
	.byte	W06
	.byte		        24*se_m_sing_mvl/mxv
	.byte		PAN   , c_v+8
	.byte	W06
	.byte		MOD   , 0
	.byte	FINE

@******************************************************@
	.align	2

se_m_sing:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_sing_pri	@ Priority
	.byte	se_m_sing_rev	@ Reverb.

	.word	se_m_sing_grp

	.word	se_m_sing_1
	.word	se_m_sing_2

	.end
