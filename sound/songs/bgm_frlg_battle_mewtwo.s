	.include "MPlayDef.s"

	.equ	bgm_frlg_battle_mewtwo_grp, voicegroup_86A98BC
	.equ	bgm_frlg_battle_mewtwo_pri, 0
	.equ	bgm_frlg_battle_mewtwo_rev, reverb_set+50
	.equ	bgm_frlg_battle_mewtwo_mvl, 127
	.equ	bgm_frlg_battle_mewtwo_key, 0
	.equ	bgm_frlg_battle_mewtwo_tbs, 1
	.equ	bgm_frlg_battle_mewtwo_exg, 0
	.equ	bgm_frlg_battle_mewtwo_cmp, 1

	.section .rodata
	.global	bgm_frlg_battle_mewtwo
	.align	2

@********************** Track  1 **********************@

bgm_frlg_battle_mewtwo_1:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte	TEMPO , 182*bgm_frlg_battle_mewtwo_tbs/2
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		N06   , Ds4 , v080
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N06   , As3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        Fs3 
	.byte	W24
	.byte	W48
	.byte		        En3 
	.byte	W48
bgm_frlg_battle_mewtwo_1_000:
	.byte	W36
	.byte		N06   , Gn3 , v080
	.byte	W36
	.byte		        Fs3 
	.byte	W24
	.byte	PEND
	.byte	W36
	.byte		VOL   , 57*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N60   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 89*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , As3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        Fs3 
	.byte	W24
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_1_000
	.byte	W36
	.byte		N60   , En3 , v080
	.byte	W12
	.byte		MOD   , 7
	.byte	W48
bgm_frlg_battle_mewtwo_1_B1:
	.byte		VOL   , 89*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
bgm_frlg_battle_mewtwo_1_001:
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	PEND
bgm_frlg_battle_mewtwo_1_002:
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	PEND
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
bgm_frlg_battle_mewtwo_1_003:
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte	PEND
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_1_003
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_1_001
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_1_001
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_1_001
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_1_002
	.byte		N24   , Fn3 , v080
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N72   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W48
	.byte		        90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N96   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W72
	.byte		        90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N96   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   , As4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W84
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N72   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   
	.byte	W24
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W36
	.byte		N48   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_battle_mewtwo_2:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+1
	.byte		N06   , As4 , v064
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		VOICE , 4
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N12   , As4 
	.byte	W36
	.byte		        As3 , v096
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
bgm_frlg_battle_mewtwo_2_000:
	.byte	W36
	.byte		N12   , As3 , v096
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W36
	.byte		N60   , An3 
	.byte	W06
	.byte		VOL   , 23*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        33*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        51*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        64*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_2_000
	.byte	W36
	.byte		N60   , As3 , v096
	.byte	W12
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 39*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        78*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        86*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W19
bgm_frlg_battle_mewtwo_2_B1:
	.byte		VOICE , 81
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , As3 , v096
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , As3 
	.byte	W24
	.byte		N72   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		        0
	.byte		N12   , As4 
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W36
	.byte		N48   , En5 
	.byte	W06
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        36*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 44*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        54*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        70*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        78*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W01
	.byte		        87*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N36   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		VOL   , 78*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		TIE   , Bn4 , v116
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 21*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W72
	.byte	W03
	.byte		        27*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        38*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 45*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        50*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        61*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        74*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        85*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W36
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		TIE   , As4 , v108
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W66
	.byte		        25*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        38*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        50*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        60*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        74*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        84*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		EOT   
	.byte		VOICE , 92
	.byte		VOL   , 67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N48   , Gs3 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
bgm_frlg_battle_mewtwo_2_001:
	.byte		MOD   , 0
	.byte		N48   , Fn4 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	PEND
	.byte		        0
	.byte		N96   , Gn4 
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        35*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        40*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        47*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        52*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        57*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        63*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        76*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        28*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        36*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        46*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        53*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        62*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        65*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        70*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        75*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W18
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_2_001
	.byte		MOD   , 0
	.byte		N96   , As4 , v096
	.byte	W06
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 43*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        46*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        48*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        51*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        60*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        75*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   , Ds5 
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        24*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 28*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        36*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        42*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        50*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        58*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        74*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        83*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Gn4 
	.byte	W06
	.byte		VOL   , 45*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        46*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 47*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        49*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        53*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        58*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        60*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        77*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W01
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   
	.byte	W24
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W84
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N72   , Gs4 
	.byte	W06
	.byte		VOL   , 45*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        46*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 47*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        49*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        53*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        58*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        60*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        77*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W01
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   
	.byte	W24
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W36
	.byte		N48   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_battle_mewtwo_3:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 83
	.byte		PAN   , c_v-64
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N06   , En2 , v092
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
bgm_frlg_battle_mewtwo_3_000:
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 , v092
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
bgm_frlg_battle_mewtwo_3_001:
	.byte		PAN   , c_v-64
	.byte		N12   , En2 , v092
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N24   , En2 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-64
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N24   , En2 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , As2 
	.byte	W03
	.byte		        Bn2 , v088
	.byte	W03
	.byte		N06   , As2 
	.byte	W06
	.byte		N12   , Gs2 , v092
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_001
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_001
bgm_frlg_battle_mewtwo_3_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 , v092
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte		PAN   , c_v-64
	.byte		N72   , Bn2 , v092
	.byte	W72
	.byte		PAN   , c_v+63
	.byte		N12   , As2 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An2 , v096
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		N06   , An2 
	.byte	W06
	.byte		N12   , Fs2 , v092
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 , v092
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
bgm_frlg_battle_mewtwo_3_002:
	.byte		PAN   , c_v-64
	.byte		N12   , En2 , v092
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_002
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
bgm_frlg_battle_mewtwo_3_003:
	.byte		PAN   , c_v-64
	.byte		N12   , Cs2 , v092
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_003
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
bgm_frlg_battle_mewtwo_3_004:
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 , v092
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_004
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_002
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_3_002
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_battle_mewtwo_4:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 38
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+0
	.byte		N06   , En1 , v116
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
bgm_frlg_battle_mewtwo_4_000:
	.byte		N12   , Ds1 , v127
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , En1 
	.byte	W12
	.byte		N36   , En2 
	.byte	W09
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-44
	.byte	W03
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-60
	.byte	W03
	.byte		        c_v-63
	.byte	W03
	.byte		        c_v+0
	.byte		N12   , En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_4_000
	.byte		N12   , Ds1 , v127
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
bgm_frlg_battle_mewtwo_4_B1:
	.byte		N12   , Ds1 , v127
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N12   , As1 
	.byte	W12
	.byte		N18   , Ds1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N24   , Ds1 , v120
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		N18   , Gs1 
	.byte	W18
	.byte		N03   , Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N24   , En1 , v127
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N18   , En1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N18   , Cs1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N48   , Cs2 
	.byte	W12
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-17
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-31
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-42
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-64
	.byte	W12
	.byte		        c_v+0
	.byte		N24   , As1 
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		N36   
	.byte	W12
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-28
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs2 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N48   , Gs1 
	.byte	W12
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-17
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-31
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-42
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-64
	.byte	W12
	.byte		        c_v+0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N30   , Ds1 
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N24   
	.byte	W36
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N18   , Ds1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		N18   , En1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W36
	.byte		        Bn1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_battle_mewtwo_5:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 69*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		N06   , As5 , v064
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		VOL   , 56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N12   , As4 , v112
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
bgm_frlg_battle_mewtwo_5_000:
	.byte	W36
	.byte		N12   , As3 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W36
	.byte		N60   , An3 
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        52*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        71*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_5_000
	.byte	W36
	.byte		N60   , As3 , v112
	.byte	W12
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 47*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        59*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        69*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        78*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        84*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W19
bgm_frlg_battle_mewtwo_5_B1:
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 78*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N36   , As3 , v104
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , As3 
	.byte	W24
	.byte		N72   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		        0
	.byte		N12   , As4 
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W36
	.byte		N48   , En5 
	.byte	W06
	.byte		VOL   , 31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        40*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 46*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        69*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        87*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N36   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N36   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		VOICE , 60
	.byte		TIE   , Bn4 , v100
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 21*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W72
	.byte	W03
	.byte		        27*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        38*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 45*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        50*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        61*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        74*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        85*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W36
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		TIE   , As4 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W78
	.byte		VOL   , 25*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        38*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        50*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        60*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        74*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        84*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		        90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		EOT   
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N48   , Gs4 , v084
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Cs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
bgm_frlg_battle_mewtwo_5_001:
	.byte		MOD   , 0
	.byte		N48   , Fn5 , v084
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Gs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	PEND
	.byte		        0
	.byte		N96   , Gn5 
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 32*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        37*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        43*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        48*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        61*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        75*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        80*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   
	.byte	W06
	.byte		VOL   , 23*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 32*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        37*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        47*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        53*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        58*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        75*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        80*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W24
	.byte		        68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Cs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_5_001
	.byte		MOD   , 0
	.byte		N96   , As5 , v084
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        23*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        35*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        48*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        53*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        57*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        63*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        70*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        71*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   , Ds6 
	.byte	W06
	.byte		VOL   , 26*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        34*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        37*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        41*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        45*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        48*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        57*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        63*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        65*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        69*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        75*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W19
	.byte		        56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Gn5 
	.byte	W06
	.byte		VOL   , 29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 33*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        36*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        40*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        44*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        48*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        63*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        70*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		N12   
	.byte	W24
	.byte		VOL   , 67*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N12   , Gs5 
	.byte	W12
	.byte		N24   , Gn5 
	.byte	W84
	.byte		VOL   , 56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N72   , Gs5 
	.byte	W06
	.byte		VOL   , 29*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W06
	.byte		        31*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 33*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        36*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        40*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        44*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        48*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        55*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        63*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		        70*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W05
	.byte		        72*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		N12   
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N12   , Bn5 
	.byte	W12
	.byte		        As5 
	.byte	W36
	.byte		N48   , Gs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_5_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_battle_mewtwo_6:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W84
	.byte		N06   , Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N48   , Cn3 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Cn1 , v080
	.byte	W12
	.byte		        Cn1 , v127
	.byte		N48   , Gn2 , v088
	.byte	W12
	.byte		N06   , Cn1 , v064
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cn1 , v068
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
bgm_frlg_battle_mewtwo_6_000:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Cn1 , v064
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Fn1 , v120
	.byte	W12
	.byte	PEND
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W36
	.byte		        Cn1 , v068
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W12
	.byte		        En1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn2 , v120
	.byte		N24   , Bn2 , v096
	.byte	W06
	.byte		N06   , An1 , v120
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , Cs2 , v088
	.byte	W12
	.byte		N06   , Cn1 , v064
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cn1 , v068
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_6_000
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cn1 , v068
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W12
	.byte		        Bn0 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cs1 , v096
	.byte		N24   , Cs2 , v120
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
bgm_frlg_battle_mewtwo_6_B1:
	.byte		N06   , Cn1 , v120
	.byte		N48   , Gn2 
	.byte	W24
	.byte		N06   , Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Gn1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		        Bn1 , v120
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N06   , Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W12
bgm_frlg_battle_mewtwo_6_001:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte	PEND
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , An2 , v096
	.byte	W24
	.byte		N06   , Cs1 
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        An1 , v120
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		N06   
	.byte		N24   , Bn2 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N06   , Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte		N06   , Fn2 , v096
	.byte	W24
bgm_frlg_battle_mewtwo_6_002:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v096
	.byte		N06   , Fn2 
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v096
	.byte		N24   , Gn2 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cs1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn2 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N06   , Fn2 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W24
	.byte		        Cn1 , v120
	.byte		N06   , Fn2 , v096
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_6_002
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v096
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		VOICE , 0
	.byte		N06   , Cn1 , v120
	.byte		N48   , Cn3 , v096
	.byte	W06
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , Cs2 
	.byte	W24
	.byte		N06   , Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_6_001
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_battle_mewtwo_7:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 127
	.byte		VOL   , 79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W96
	.byte	W12
	.byte		N03   , Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v044
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v056
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v084
	.byte	W06
	.byte		N03   
	.byte	W06
bgm_frlg_battle_mewtwo_7_000:
	.byte		N03   , Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte	PEND
bgm_frlg_battle_mewtwo_7_001:
	.byte		N03   , Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W24
	.byte		        Cn5 , v064
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W24
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
bgm_frlg_battle_mewtwo_7_002:
	.byte		N03   , Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_001
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_000
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_002
bgm_frlg_battle_mewtwo_7_B1:
bgm_frlg_battle_mewtwo_7_003:
	.byte		N03   , Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
bgm_frlg_battle_mewtwo_7_004:
	.byte		N03   , Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_003
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_004
	.byte	W12
	.byte		N03   , Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_003
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_003
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_004
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_003
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_004
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N03   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
bgm_frlg_battle_mewtwo_7_005:
	.byte	W12
	.byte		N03   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v072
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte		        Cn5 , v072
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte	PEND
bgm_frlg_battle_mewtwo_7_006:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W24
	.byte	PEND
bgm_frlg_battle_mewtwo_7_007:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_005
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_006
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_7_007
	.byte		VOL   , 79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W12
	.byte		N03   , Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 79*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte		N03   , Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_battle_mewtwo_8:
	.byte	KEYSH , bgm_frlg_battle_mewtwo_key+0
	.byte		VOICE , 126
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*bgm_frlg_battle_mewtwo_mvl/mxv
	.byte	W96
	.byte		N12   , Gn5 , v044
	.byte	W24
	.byte		        Gn5 , v068
	.byte	W24
	.byte		        Gn5 , v088
	.byte	W24
	.byte		        Gn5 , v120
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		        Gn5 , v088
	.byte	W24
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W72
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W96
bgm_frlg_battle_mewtwo_8_B1:
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		        Gn5 , v120
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		        Gn5 , v096
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		        Gn5 , v120
	.byte	W12
	.byte	W96
bgm_frlg_battle_mewtwo_8_000:
	.byte		N12   , Gn5 , v092
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	W84
	.byte		        Gn5 , v096
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_frlg_battle_mewtwo_8_000
	.byte	W84
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte	W96
	.byte		        Gn5 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_battle_mewtwo_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_battle_mewtwo:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_battle_mewtwo_pri	@ Priority
	.byte	bgm_frlg_battle_mewtwo_rev	@ Reverb.

	.word	bgm_frlg_battle_mewtwo_grp

	.word	bgm_frlg_battle_mewtwo_1
	.word	bgm_frlg_battle_mewtwo_2
	.word	bgm_frlg_battle_mewtwo_3
	.word	bgm_frlg_battle_mewtwo_4
	.word	bgm_frlg_battle_mewtwo_5
	.word	bgm_frlg_battle_mewtwo_6
	.word	bgm_frlg_battle_mewtwo_7
	.word	bgm_frlg_battle_mewtwo_8

	.end
