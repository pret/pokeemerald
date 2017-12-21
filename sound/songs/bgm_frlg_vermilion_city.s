	.include "MPlayDef.s"

	.equ	bgm_frlg_vermilion_city_grp, voicegroup_86AEB6C
	.equ	bgm_frlg_vermilion_city_pri, 0
	.equ	bgm_frlg_vermilion_city_rev, reverb_set+50
	.equ	bgm_frlg_vermilion_city_mvl, 127
	.equ	bgm_frlg_vermilion_city_key, 0
	.equ	bgm_frlg_vermilion_city_tbs, 1
	.equ	bgm_frlg_vermilion_city_exg, 0
	.equ	bgm_frlg_vermilion_city_cmp, 1

	.section .rodata
	.global	bgm_frlg_vermilion_city
	.align	2

@********************** Track  1 **********************@

bgm_frlg_vermilion_city_1:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_1_B1:
	.byte	TEMPO , 116*bgm_frlg_vermilion_city_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N24   , An3 , v127
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
bgm_frlg_vermilion_city_1_000:
	.byte		PAN   , c_v-32
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-32
	.byte		N24   , An3 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Gn3 , v127
	.byte	W06
	.byte		        Dn3 , v120
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , An3 , v127
	.byte	W06
	.byte		        Fs3 , v120
	.byte	W06
	.byte		        Bn3 , v127
	.byte	W06
	.byte		        As3 , v120
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N24   , An3 , v127
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_1_000
	.byte		PAN   , c_v-32
	.byte		N24   , An3 , v127
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , An3 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
bgm_frlg_vermilion_city_1_001:
	.byte		PAN   , c_v-32
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-32
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   , Dn1 , v120
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
bgm_frlg_vermilion_city_1_002:
	.byte		PAN   , c_v-32
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-32
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_1_001
	.byte		PAN   , c_v-32
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_1_002
	.byte		VOICE , 24
	.byte		PAN   , c_v+40
	.byte		VOL   , 43*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Cs4 , v120
	.byte	W06
	.byte		N03   , Cs4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs4 , v120
	.byte	W06
	.byte		N01   , Cs4 , v052
	.byte	W06
	.byte		N03   , Gn4 , v084
	.byte	W06
	.byte		        Bn3 
	.byte		N01   , Cs4 
	.byte	W03
	.byte		N03   , Cn4 , v088
	.byte	W03
	.byte		N06   , Cs4 , v120
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte	W06
	.byte		N03   , Gs3 , v084
	.byte	W03
	.byte		        Bn3 , v088
	.byte	W03
	.byte		        Cs4 , v120
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N01   , An4 , v116
	.byte	W06
	.byte		N06   , Cs4 , v052
	.byte	W06
	.byte		N03   , Gs3 , v072
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Bn3 , v080
	.byte	W03
	.byte		        Cs4 , v120
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N01   , En4 , v068
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		N03   , An4 , v096
	.byte	W06
	.byte		N06   , An3 , v084
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_vermilion_city_2:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_2_B1:
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 78*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N48   , Dn4 , v100
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 78*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 78*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 78*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 78*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		VOICE , 4
	.byte		VOL   , 81*bgm_frlg_vermilion_city_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Dn5 , v108
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 81*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N24   , Gn5 , v076
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte		N36   , En5 , v108
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 81*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Dn5 , v088
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N48   , Fs5 , v084
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 81*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N48   , Dn5 , v108
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 81*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N24   , Gn5 , v088
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte		N36   , En5 , v108
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 81*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Fs5 , v084
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte		N48   , Dn5 , v088
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		VOICE , 17
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N24   , En4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , En5 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N24   , Dn5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , En4 , v120
	.byte	W12
	.byte		N06   , Fs4 , v127
	.byte	W12
	.byte		N12   , Fs4 , v120
	.byte	W12
	.byte		N06   , Gn4 , v127
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 , v120
	.byte	W06
	.byte		        An4 , v127
	.byte	W12
	.byte		N12   , An4 , v120
	.byte	W12
	.byte		N48   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N48   , En5 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N12   , Dn5 , v127
	.byte	W12
	.byte		N06   , Gn4 , v120
	.byte	W12
	.byte		N24   , Cs5 , v127
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        En5 , v120
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Cs5 , v096
	.byte	W03
	.byte		N06   , Bn4 , v088
	.byte	W06
	.byte		N12   , An4 , v120
	.byte	W12
	.byte		N36   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Cs5 , v120
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N48   , An4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 87*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N96   , An3 , v120
	.byte	W12
	.byte		MOD   , 5
	.byte	W84
	.byte		        0
	.byte	W24
	.byte		VOICE , 73
	.byte		VOL   , 70*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W24
	.byte		        22*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N24   
	.byte	W03
	.byte		VOL   , 29*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W06
	.byte		        41*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W03
	.byte		        52*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W03
	.byte		        63*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W03
	.byte		        76*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Dn4 , v088
	.byte	W03
	.byte		N06   , Cs4 , v120
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_vermilion_city_3:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_3_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-63
	.byte		VOL   , 44*bgm_frlg_vermilion_city_mvl/mxv
	.byte		MOD   , 3
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Cs3 , v120
	.byte	W03
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N12   , An2 , v127
	.byte	W12
bgm_frlg_vermilion_city_3_000:
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte		        An2 , v127
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Cs3 , v120
	.byte	W06
	.byte		        Fs3 , v127
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_3_000
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        En3 , v127
	.byte	W06
	.byte		        Fs3 , v120
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		        An2 , v127
	.byte	W06
	.byte		        Bn2 , v120
	.byte	W06
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		        Fs3 , v127
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        An2 , v120
	.byte	W06
	.byte		        Dn3 , v127
	.byte	W06
	.byte		        Cs3 , v120
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Fs3 , v127
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		N12   , An3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Cs3 , v120
	.byte	W03
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        An2 , v127
	.byte	W06
	.byte		        As2 , v120
	.byte	W06
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        Dn3 , v120
	.byte	W03
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N12   , Bn2 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En3 , v120
	.byte	W12
	.byte		        An2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Cs3 , v127
	.byte	W03
	.byte		        Dn3 , v120
	.byte	W03
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N12   , Bn2 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		        An2 , v127
	.byte	W06
	.byte		        Bn2 , v120
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        An2 , v120
	.byte	W03
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N12   , En2 , v127
	.byte	W12
	.byte		        An2 , v120
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 , v024
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_vermilion_city_4:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_4_B1:
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v-1
	.byte		VOL   , 49*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N12   , Dn1 , v120
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Dn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Dn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Dn1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Fs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Gs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Cs2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Fs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , An1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cs2 
	.byte	W12
	.byte		N24   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , En2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06   , En1 
	.byte		N03   , An1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N12   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N18   , Gn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		N24   
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N06   
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 
	.byte	W09
	.byte		        Gn1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N24   , Cs1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Gn1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_4_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_vermilion_city_5:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_5_B1:
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 34*bgm_frlg_vermilion_city_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N48   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
bgm_frlg_vermilion_city_5_000:
	.byte		N36   , En4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte	PEND
bgm_frlg_vermilion_city_5_001:
	.byte		MOD   , 0
	.byte		N48   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte	PEND
bgm_frlg_vermilion_city_5_002:
	.byte		N36   , En4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte	PEND
	.byte		N48   
	.byte	W48
	.byte		MOD   , 0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_5_000
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_5_001
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_5_002
	.byte		MOD   , 0
	.byte		N24   , En4 , v127
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , En5 , v080
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N24   , Dn5 , v127
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , En4 , v120
	.byte	W12
	.byte		N06   , Fs4 , v127
	.byte	W12
	.byte		N12   , Fs4 , v120
	.byte	W12
	.byte		N06   , Gn4 , v127
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 , v120
	.byte	W06
	.byte		        An4 , v127
	.byte	W12
	.byte		N12   , An4 , v120
	.byte	W12
	.byte		N48   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , En5 , v084
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N12   , Dn5 , v127
	.byte	W24
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W48
	.byte		N36   
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , Cs5 , v120
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N48   , An4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		        5
	.byte	W84
	.byte		        0
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_vermilion_city_6:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_6_B1:
	.byte		VOICE , 24
	.byte		VOL   , 41*bgm_frlg_vermilion_city_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-30
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 42*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		N03   , En3 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		N01   , En3 , v052
	.byte	W06
	.byte		N03   , En4 , v084
	.byte	W06
	.byte		        Cs3 
	.byte		N01   , En3 
	.byte	W03
	.byte		N03   , Ds3 , v088
	.byte	W03
	.byte		        En3 , v120
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte	W06
	.byte		N03   , Bn2 , v084
	.byte	W03
	.byte		        Dn3 , v088
	.byte	W03
	.byte		        En3 , v120
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N01   , En4 , v116
	.byte	W06
	.byte		N06   , En3 , v052
	.byte	W06
	.byte		N03   , Bn2 , v072
	.byte		N03   , En3 
	.byte	W03
	.byte		        Dn3 , v080
	.byte	W03
	.byte		        En3 , v120
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N04   , An3 , v068
	.byte	W03
	.byte		N01   , En4 
	.byte	W03
	.byte		N03   , Gn4 , v096
	.byte	W06
	.byte		N06   , Gn3 , v084
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_vermilion_city_7:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_7_B1:
	.byte		VOICE , 0
	.byte		VOL   , 72*bgm_frlg_vermilion_city_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N06   , En1 , v100
	.byte		N48   , Gn2 , v120
	.byte	W12
	.byte		N06   , En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v076
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
bgm_frlg_vermilion_city_7_000:
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v076
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v076
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_7_000
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_7_000
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_7_000
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v076
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v056
	.byte	W06
	.byte		N03   , En1 , v076
	.byte		N06   , Dn2 , v120
	.byte	W03
	.byte		N03   , En1 , v068
	.byte	W03
	.byte		N03   
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        En1 , v100
	.byte		N06   , An1 , v120
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Gn1 , v120
	.byte	W06
	.byte		        En1 , v100
	.byte		N06   , Fn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En1 , v048
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_vermilion_city_mvl/mxv
	.byte		N06   , Cn1 , v120
	.byte		N48   , Gn2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , Bn2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v084
	.byte	W12
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   , Bn0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn2 , v084
	.byte	W06
	.byte		N03   , Gn1 , v120
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v084
	.byte	W12
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   , Bn0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , An2 
	.byte	W06
	.byte		N06   , Cn1 , v096
	.byte	W06
	.byte		        En1 , v076
	.byte	W12
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   , Bn0 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W18
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		        Bn0 , v080
	.byte		N06   , En1 , v076
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v048
	.byte	W06
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        En1 , v024
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_vermilion_city_8:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_8_B1:
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 43*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N02   , Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
bgm_frlg_vermilion_city_8_000:
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_8_000
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v024
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v036
	.byte	W18
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W18
bgm_frlg_vermilion_city_8_001:
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v056
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_8_001
	.byte	PATT
	 .word	bgm_frlg_vermilion_city_8_001
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v056
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W06
	.byte		        Cn5 , v024
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_frlg_vermilion_city_9:
	.byte	KEYSH , bgm_frlg_vermilion_city_key+0
bgm_frlg_vermilion_city_9_B1:
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 43*bgm_frlg_vermilion_city_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N12   , Gn5 , v096
	.byte	W48
	.byte		N12   
	.byte	W36
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	W12
	.byte		        Gn5 , v052
	.byte	W24
	.byte		        Gn5 , v068
	.byte	W24
	.byte		        Gn5 , v080
	.byte	W24
	.byte		        Gn5 , v104
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		        Gn5 , v120
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_vermilion_city_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_vermilion_city:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_vermilion_city_pri	@ Priority
	.byte	bgm_frlg_vermilion_city_rev	@ Reverb.

	.word	bgm_frlg_vermilion_city_grp

	.word	bgm_frlg_vermilion_city_1
	.word	bgm_frlg_vermilion_city_2
	.word	bgm_frlg_vermilion_city_3
	.word	bgm_frlg_vermilion_city_4
	.word	bgm_frlg_vermilion_city_5
	.word	bgm_frlg_vermilion_city_6
	.word	bgm_frlg_vermilion_city_7
	.word	bgm_frlg_vermilion_city_8
	.word	bgm_frlg_vermilion_city_9

	.end
