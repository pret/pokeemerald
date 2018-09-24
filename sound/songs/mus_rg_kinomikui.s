	.include "MPlayDef.s"

	.equ	mus_rg_kinomikui_grp, voicegroup132
	.equ	mus_rg_kinomikui_pri, 0
	.equ	mus_rg_kinomikui_rev, reverb_set+50
	.equ	mus_rg_kinomikui_mvl, 127
	.equ	mus_rg_kinomikui_key, 0
	.equ	mus_rg_kinomikui_tbs, 1
	.equ	mus_rg_kinomikui_exg, 0
	.equ	mus_rg_kinomikui_cmp, 1

	.section .rodata
	.global	mus_rg_kinomikui
	.align	2

@********************** Track  1 **********************@

mus_rg_kinomikui_1:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte	TEMPO , 148*mus_rg_kinomikui_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N06   , Bn2 , v096
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
mus_rg_kinomikui_1_B1:
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N36   , Bn3 , v080
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W96
	.byte		N24   , Ds3 , v072
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Cs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N48   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        49*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
mus_rg_kinomikui_1_000:
	.byte		MOD   , 0
	.byte		N36   , As3 , v072
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		N48   , Gs3 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        51*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        51*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N48   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        51*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , Fn4 
	.byte	W15
	.byte		MOD   , 7
	.byte	W21
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N48   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N48   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        48*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_kinomikui_1_000
	.byte		MOD   , 0
	.byte		N48   , Gs3 , v072
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        48*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N48   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N60   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        49*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        44*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 38*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        63*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N60   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        49*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        63*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N60   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        49*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        63*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        49*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N48   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        49*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kinomikui_1_B1
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_kinomikui_mvl/mxv
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_kinomikui_2:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
mus_rg_kinomikui_2_B1:
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N36   , Ds4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W60
	.byte		N06   , Cs3 , v120
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Fs3 , v127
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
mus_rg_kinomikui_2_000:
	.byte		MOD   , 0
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		N84   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        72*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        62*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
mus_rg_kinomikui_2_001:
	.byte		MOD   , 0
	.byte		N96   , Bn3 , v127
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        72*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        62*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
mus_rg_kinomikui_2_002:
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v127
	.byte	W12
	.byte		N84   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        72*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        62*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		        90*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gs4 
	.byte	W12
	.byte		VOL   , 79*mus_rg_kinomikui_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N96   , Cs4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        72*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        62*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        90*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_kinomikui_2_000
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fs4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_kinomikui_2_001
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gs3 , v127
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_kinomikui_2_002
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gs4 , v127
	.byte	W12
	.byte		VOL   , 79*mus_rg_kinomikui_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        90*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N60   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        73*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
mus_rg_kinomikui_2_003:
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N60   , Fs4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        73*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	PEND
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N18   , As4 , v120
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Bn4 , v092
	.byte	W03
	.byte		        As4 , v080
	.byte	W03
	.byte		N12   , Gs4 , v127
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N60   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        73*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_kinomikui_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_kinomikui_2_003
	.byte		N24   , Gs4 , v127
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N96   , Cs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        72*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        61*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte		        56*mus_rg_kinomikui_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kinomikui_2_B1
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_kinomikui_mvl/mxv
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_kinomikui_3:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 44*mus_rg_kinomikui_mvl/mxv
	.byte		N06   , Ds2 , v120
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
mus_rg_kinomikui_3_B1:
	.byte		N36   , Ds3 , v127
	.byte	W36
	.byte		N12   , Cs3 , v120
	.byte	W12
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        As2 , v127
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W48
	.byte		VOICE , 80
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		VOL   , 28*mus_rg_kinomikui_mvl/mxv
	.byte		N06   , Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
mus_rg_kinomikui_3_000:
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte	PEND
mus_rg_kinomikui_3_001:
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs3 
	.byte	W12
	.byte	PEND
mus_rg_kinomikui_3_002:
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Bn2 
	.byte	W12
	.byte	PEND
mus_rg_kinomikui_3_003:
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Ds2 , v120
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
mus_rg_kinomikui_3_004:
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Bn2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
mus_rg_kinomikui_3_005:
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_kinomikui_3_000
	.byte	PATT
	 .word	mus_rg_kinomikui_3_001
	.byte	PATT
	 .word	mus_rg_kinomikui_3_002
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N06   , Cs3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_kinomikui_3_003
	.byte	PATT
	 .word	mus_rg_kinomikui_3_005
	.byte	PATT
	 .word	mus_rg_kinomikui_3_004
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_kinomikui_3_003
	.byte	PATT
	 .word	mus_rg_kinomikui_3_005
	.byte	PATT
	 .word	mus_rg_kinomikui_3_004
	.byte	PATT
	 .word	mus_rg_kinomikui_3_000
	.byte	GOTO
	 .word	mus_rg_kinomikui_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_kinomikui_4:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*mus_rg_kinomikui_mvl/mxv
	.byte	W24
mus_rg_kinomikui_4_B1:
	.byte		N36   , Ds2 , v120
	.byte	W36
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W60
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
mus_rg_kinomikui_4_000:
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte	PEND
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Bn2 , v096
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v100
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
mus_rg_kinomikui_4_001:
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte	PEND
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		N06   , Bn2 , v096
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte	PATT
	 .word	mus_rg_kinomikui_4_000
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte	PATT
	 .word	mus_rg_kinomikui_4_001
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		N06   , Bn3 , v088
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Bn3 , v096
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Cs4 , v072
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Bn2 , v096
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Ds1 , v120
	.byte	W12
	.byte		N06   , Bn3 , v096
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W06
	.byte		N12   , Fs1 , v120
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_kinomikui_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_kinomikui_5:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*mus_rg_kinomikui_mvl/mxv
	.byte	W24
mus_rg_kinomikui_5_B1:
	.byte		VOICE , 73
	.byte	W96
	.byte	W12
	.byte		N06   , Cs5 , v127
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Ds5 , v120
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 , v096
	.byte	W03
	.byte		        Ds5 , v076
	.byte	W03
	.byte		        Cs5 , v068
	.byte	W03
	.byte		        Ds5 , v060
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 , v032
	.byte	W03
	.byte	W96
	.byte		VOL   , 40*mus_rg_kinomikui_mvl/mxv
	.byte		N06   , Cs5 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte	W96
	.byte	W12
	.byte		N06   , Cs6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		N03   , Cs6 
	.byte	W03
	.byte		        Dn6 , v060
	.byte	W03
	.byte		        Cs6 , v120
	.byte	W03
	.byte		        Dn6 , v064
	.byte	W03
	.byte		        Cs6 , v120
	.byte	W03
	.byte		        Dn6 , v060
	.byte	W03
	.byte		        Cs6 , v120
	.byte	W03
	.byte		        Dn6 , v060
	.byte	W03
	.byte		        Cs6 , v092
	.byte	W03
	.byte		        Dn6 , v040
	.byte	W03
	.byte		        Cs6 , v064
	.byte	W03
	.byte		        Dn6 , v028
	.byte	W03
	.byte		        Cs6 , v064
	.byte	W03
	.byte		        Dn6 , v028
	.byte	W03
	.byte		        Cs6 , v060
	.byte	W03
	.byte		        Dn6 , v032
	.byte	W03
	.byte	W96
	.byte		N06   , As5 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte	W96
	.byte		VOICE , 73
	.byte		N06   , Cs6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		N12   , Cs6 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte	W96
	.byte		VOICE , 14
	.byte		VOL   , 50*mus_rg_kinomikui_mvl/mxv
	.byte	W24
	.byte		N24   , Fn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte	W96
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Gs5 
	.byte	W96
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Gs5 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
	.byte		VOICE , 14
	.byte		N24   , Fs5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Fs5 
	.byte	W48
	.byte		VOICE , 73
	.byte		VOL   , 38*mus_rg_kinomikui_mvl/mxv
	.byte		N03   , Gn5 
	.byte	W03
	.byte		N09   , Fs5 
	.byte	W09
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N06   , As5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		N06   , Fs5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N03   , Fs5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Fs5 , v096
	.byte	W03
	.byte		        Gs5 , v076
	.byte	W03
	.byte		        Fs5 , v088
	.byte	W03
	.byte		        Gs5 , v064
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Gs5 , v048
	.byte	W03
	.byte		        Fs5 , v056
	.byte	W03
	.byte		        Gs5 , v032
	.byte	W03
	.byte		VOICE , 14
	.byte		N24   , Fn5 , v120
	.byte	W48
	.byte		        Cs5 
	.byte	W48
	.byte		VOL   , 48*mus_rg_kinomikui_mvl/mxv
	.byte		N24   , Fs5 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
	.byte		        Gs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Bn5 
	.byte	W24
	.byte		        Gs5 
	.byte	W24
	.byte		        Cs6 
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_kinomikui_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_kinomikui_6:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 49*mus_rg_kinomikui_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W24
mus_rg_kinomikui_6_B1:
	.byte		N12   , Ds2 , v120
	.byte	W24
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v080
	.byte	W06
	.byte		N12   , Gs1 , v120
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Gs2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W96
	.byte		        Fs1 
	.byte	W96
	.byte		PAN   , c_v+32
	.byte	W24
	.byte		N12   , Cs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , As1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Gs1 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Fs1 
	.byte	W96
	.byte		PAN   , c_v+32
	.byte		N12   , Gs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cs2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Gs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cs2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Gs1 
	.byte	W96
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte		N24   
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Gs1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Gs1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Fs1 
	.byte	W72
	.byte		PAN   , c_v-32
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cs2 
	.byte	W96
	.byte		N24   
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N24   , Fs1 
	.byte	W48
	.byte		PAN   , c_v+32
	.byte		N24   , Bn1 
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+32
	.byte		N24   , Fs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cs2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Fs2 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cs2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Fs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cs2 
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	W48
	.byte		        Fs1 
	.byte	W48
	.byte	W48
	.byte		PAN   , c_v+32
	.byte		N12   , Gs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cs2 
	.byte	W24
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_kinomikui_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_kinomikui_7:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 0
	.byte		VOL   , 74*mus_rg_kinomikui_mvl/mxv
	.byte	W24
mus_rg_kinomikui_7_B1:
	.byte		N48   , Cs2 , v120
	.byte	W48
	.byte		        An2 
	.byte	W48
	.byte		        Gn2 
	.byte	W96
	.byte		        An2 
	.byte	W96
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte		N12   
	.byte	W96
	.byte		N48   , An2 
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte		        Gn2 
	.byte	W96
	.byte		N24   , An2 
	.byte	W96
	.byte		        Gn2 
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte		        Bn2 
	.byte	W96
	.byte		N48   , Cs2 
	.byte	W96
	.byte		N24   , An2 
	.byte	W96
	.byte		N48   , Bn2 
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte	W72
	.byte		N24   , An2 
	.byte	W24
	.byte		N48   , Cs2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        An2 
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte		        Bn2 
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_kinomikui_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_kinomikui_8:
	.byte	KEYSH , mus_rg_kinomikui_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 41*mus_rg_kinomikui_mvl/mxv
	.byte	W24
mus_rg_kinomikui_8_B1:
	.byte		N01   , Gn3 , v120
	.byte	W36
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W60
	.byte		        Gn3 , v064
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		        Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
mus_rg_kinomikui_8_000:
	.byte		N01   , Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v052
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte	PEND
mus_rg_kinomikui_8_001:
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v044
	.byte	W03
	.byte		        Gn3 , v100
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
mus_rg_kinomikui_8_002:
	.byte		N01   , Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
	.byte	PATT
	 .word	mus_rg_kinomikui_8_002
mus_rg_kinomikui_8_003:
	.byte		N01   , Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte	PEND
mus_rg_kinomikui_8_004:
	.byte		N01   , Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte	PEND
mus_rg_kinomikui_8_005:
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W12
	.byte		        Gn3 , v084
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte	PEND
	.byte		N01   
	.byte	W12
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
	.byte	PATT
	 .word	mus_rg_kinomikui_8_002
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
	.byte	PATT
	 .word	mus_rg_kinomikui_8_001
	.byte	PATT
	 .word	mus_rg_kinomikui_8_000
	.byte	PATT
	 .word	mus_rg_kinomikui_8_002
	.byte	PATT
	 .word	mus_rg_kinomikui_8_002
	.byte	PATT
	 .word	mus_rg_kinomikui_8_003
	.byte	PATT
	 .word	mus_rg_kinomikui_8_004
	.byte	PATT
	 .word	mus_rg_kinomikui_8_005
	.byte	GOTO
	 .word	mus_rg_kinomikui_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_kinomikui:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_kinomikui_pri	@ Priority
	.byte	mus_rg_kinomikui_rev	@ Reverb.

	.word	mus_rg_kinomikui_grp

	.word	mus_rg_kinomikui_1
	.word	mus_rg_kinomikui_2
	.word	mus_rg_kinomikui_3
	.word	mus_rg_kinomikui_4
	.word	mus_rg_kinomikui_5
	.word	mus_rg_kinomikui_6
	.word	mus_rg_kinomikui_7
	.word	mus_rg_kinomikui_8

	.end
