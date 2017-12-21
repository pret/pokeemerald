	.include "MPlayDef.s"

	.equ	bgm_battle_legendary_grp, voicegroup_8699254
	.equ	bgm_battle_legendary_pri, 1
	.equ	bgm_battle_legendary_rev, reverb_set+50
	.equ	bgm_battle_legendary_mvl, 127
	.equ	bgm_battle_legendary_key, 0
	.equ	bgm_battle_legendary_tbs, 1
	.equ	bgm_battle_legendary_exg, 0
	.equ	bgm_battle_legendary_cmp, 1

	.section .rodata
	.global	bgm_battle_legendary
	.align	2

@********************** Track  1 **********************@

bgm_battle_legendary_1:
	.byte	KEYSH , bgm_battle_legendary_key+0
	.byte	TEMPO , 196*bgm_battle_legendary_tbs/2
	.byte		VOICE , 14
	.byte		LFOS  , 18
	.byte		PAN   , c_v+16
	.byte		VOL   , 80*bgm_battle_legendary_mvl/mxv
	.byte		N48   , Cn2 , v112
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte		N48   
	.byte	W96
bgm_battle_legendary_1_000:
	.byte		VOICE , 47
	.byte		PAN   , c_v-32
	.byte		N24   , Gn1 , v096
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	PEND
bgm_battle_legendary_1_001:
	.byte		N36   , Gn1 , v096
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_battle_legendary_1_002:
	.byte		N12   , Gn1 , v096
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	PEND
bgm_battle_legendary_1_003:
	.byte		N24   , Gn1 , v096
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	PEND
bgm_battle_legendary_1_B1:
	.byte		VOICE , 56
	.byte		PAN   , c_v+10
	.byte		N12   , Cn4 , v100
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W24
bgm_battle_legendary_1_004:
	.byte	W24
	.byte		N72   , Gn3 , v100
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PEND
bgm_battle_legendary_1_005:
	.byte		MOD   , 0
	.byte		N12   , Cn4 , v100
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N72   , Ds4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PATT
	 .word	bgm_battle_legendary_1_005
	.byte	PATT
	 .word	bgm_battle_legendary_1_004
	.byte	PATT
	 .word	bgm_battle_legendary_1_005
	.byte	W24
	.byte		N72   , En4 , v100
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v096
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W24
	.byte	W24
	.byte		N72   , Cn4 
	.byte	W72
	.byte		N12   , Fn4 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W24
	.byte	W24
	.byte		N72   , Gs4 
	.byte	W72
bgm_battle_legendary_1_006:
	.byte		N48   , Gn3 , v096
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte	PEND
	.byte		N96   , Gs3 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle_legendary_1_006
	.byte		N96   , Gs4 , v096
	.byte	W96
	.byte	PATT
	 .word	bgm_battle_legendary_1_006
	.byte		N96   , Gs3 , v096
	.byte	W96
	.byte	PATT
	 .word	bgm_battle_legendary_1_006
	.byte		N96   , Gs4 , v096
	.byte	W96
	.byte		VOICE , 60
	.byte		N48   , Ds4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N96   , Bn3 
	.byte	W96
	.byte		N48   , As3 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
	.byte		N96   , Bn4 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle_legendary_1_000
	.byte	PATT
	 .word	bgm_battle_legendary_1_001
	.byte	PATT
	 .word	bgm_battle_legendary_1_002
	.byte	PATT
	 .word	bgm_battle_legendary_1_003
	.byte	PATT
	 .word	bgm_battle_legendary_1_003
	.byte	PATT
	 .word	bgm_battle_legendary_1_001
	.byte	PATT
	 .word	bgm_battle_legendary_1_002
	.byte	PATT
	 .word	bgm_battle_legendary_1_003
	.byte	GOTO
	 .word	bgm_battle_legendary_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle_legendary_2:
	.byte	KEYSH , bgm_battle_legendary_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 18
	.byte		PAN   , c_v-16
	.byte		VOL   , 80*bgm_battle_legendary_mvl/mxv
	.byte		N48   , Cn3 , v108
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_legendary_2_B1:
	.byte		VOICE , 56
	.byte		PAN   , c_v-10
	.byte		N12   , Gn4 , v100
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Gs4 
	.byte	W24
bgm_battle_legendary_2_000:
	.byte	W24
	.byte		N72   , Dn4 , v100
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PEND
bgm_battle_legendary_2_001:
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v100
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Gs4 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N72   , As4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PATT
	 .word	bgm_battle_legendary_2_001
	.byte	PATT
	 .word	bgm_battle_legendary_2_000
	.byte	PATT
	 .word	bgm_battle_legendary_2_001
	.byte	W24
	.byte		N72   , Bn4 , v100
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		N12   , Cn5 , v096
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs5 
	.byte	W24
	.byte	W24
	.byte		N72   , Gn4 
	.byte	W72
	.byte		N12   , Cn5 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs5 
	.byte	W24
	.byte	W24
	.byte		N72   , Ds5 
	.byte	W72
	.byte		VOICE , 73
	.byte		N36   , Cn5 , v108
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W24
bgm_battle_legendary_2_002:
	.byte		N96   , Cs4 , v108
	.byte	W36
	.byte		MOD   , 8
	.byte	W60
	.byte	PEND
bgm_battle_legendary_2_003:
	.byte		MOD   , 0
	.byte		N36   , Cn5 , v108
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W24
	.byte	PEND
bgm_battle_legendary_2_004:
	.byte		N96   , Cs5 , v108
	.byte	W36
	.byte		MOD   , 8
	.byte	W60
	.byte	PEND
	.byte		VOICE , 56
	.byte		MOD   , 0
	.byte		N36   , Cn5 
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle_legendary_2_002
	.byte	PATT
	 .word	bgm_battle_legendary_2_003
	.byte	PATT
	 .word	bgm_battle_legendary_2_004
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		N36   , Gn4 , v108
	.byte	W36
	.byte		        As4 
	.byte	W36
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N96   , En5 
	.byte	W96
	.byte		N36   , Ds5 
	.byte	W36
	.byte		        As4 
	.byte	W36
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N96   , En5 
	.byte	W96
	.byte		VOICE , 14
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 
	.byte	W48
	.byte		VOICE , 47
	.byte		N48   , En1 , v100
	.byte	W48
bgm_battle_legendary_2_005:
	.byte		VOICE , 14
	.byte		N24   , Cn4 , v108
	.byte	W48
	.byte		VOICE , 47
	.byte		N48   , Cn1 , v100
	.byte	W48
	.byte	PEND
	.byte		VOICE , 14
	.byte		N24   , Cn4 , v108
	.byte	W48
	.byte		VOICE , 47
	.byte		N48   , En1 , v100
	.byte	W48
	.byte	PATT
	 .word	bgm_battle_legendary_2_005
	.byte		N24   , En1 , v100
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle_legendary_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle_legendary_3:
	.byte	KEYSH , bgm_battle_legendary_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*bgm_battle_legendary_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_legendary_3_B1:
bgm_battle_legendary_3_000:
	.byte		N12   , Gn0 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PEND
bgm_battle_legendary_3_001:
	.byte		N12   , Gn0 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N24   , Fs0 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_legendary_3_000
	.byte	PATT
	 .word	bgm_battle_legendary_3_000
	.byte	PATT
	 .word	bgm_battle_legendary_3_000
	.byte	PATT
	 .word	bgm_battle_legendary_3_001
	.byte	PATT
	 .word	bgm_battle_legendary_3_000
	.byte		N12   , Gn0 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N24   , Bn0 
	.byte	W24
bgm_battle_legendary_3_002:
	.byte		N12   , Cn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PEND
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N24   , Bn0 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
	.byte		N12   , Cn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N24   , Cs1 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
	.byte		N12   , Cs1 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
	.byte		N12   , Cs1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N24   , Bn0 
	.byte	W24
bgm_battle_legendary_3_003:
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
bgm_battle_legendary_3_004:
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_legendary_3_003
	.byte	PATT
	 .word	bgm_battle_legendary_3_004
bgm_battle_legendary_3_005:
	.byte		N12   , Ds1 , v112
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
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
bgm_battle_legendary_3_006:
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_legendary_3_005
	.byte	PATT
	 .word	bgm_battle_legendary_3_006
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
bgm_battle_legendary_3_007:
	.byte		N12   , Cn1 , v112
	.byte	W48
	.byte		N48   , Bn0 
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
	.byte		N12   , Cn1 , v112
	.byte	W48
	.byte		N36   , Gs1 
	.byte	W36
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
	.byte	PATT
	 .word	bgm_battle_legendary_3_007
	.byte	PATT
	 .word	bgm_battle_legendary_3_002
	.byte		N12   , Cn1 , v112
	.byte	W48
	.byte		        Gn0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle_legendary_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle_legendary_4:
	.byte	KEYSH , bgm_battle_legendary_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 18
	.byte		PAN   , c_v+4
	.byte		VOL   , 80*bgm_battle_legendary_mvl/mxv
	.byte		N96   , An2 , v096
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_legendary_4_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		N12   , Gn3 , v052
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W24
bgm_battle_legendary_4_000:
	.byte	W24
	.byte		N72   , Dn3 , v052
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PEND
bgm_battle_legendary_4_001:
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v052
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N72   , As3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PATT
	 .word	bgm_battle_legendary_4_001
	.byte	PATT
	 .word	bgm_battle_legendary_4_000
	.byte	PATT
	 .word	bgm_battle_legendary_4_001
	.byte	W24
	.byte		N72   , Bn3 , v052
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
bgm_battle_legendary_4_002:
	.byte		MOD   , 0
	.byte		N12   , Cn4 , v052
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N72   , Gn3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PATT
	 .word	bgm_battle_legendary_4_002
	.byte	W24
	.byte		N72   , Ds4 , v052
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W96
	.byte	W96
	.byte		        0
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		N96   , Cs4 , v060
	.byte	W96
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte		        0
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N48   , As3 
	.byte	W48
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		N96   , Gs4 
	.byte	W96
	.byte		N36   , Gn4 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N48   , As3 
	.byte	W48
	.byte		N96   , En4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle_legendary_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle_legendary_5:
	.byte	KEYSH , bgm_battle_legendary_key+0
	.byte		LFOS  , 18
	.byte		VOL   , 80*bgm_battle_legendary_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_legendary_5_B1:
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		N12   , Cn3 , v052
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W24
bgm_battle_legendary_5_000:
	.byte	W24
	.byte		N12   , Gn2 , v052
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_battle_legendary_5_001:
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cn3 , v052
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_legendary_5_001
	.byte	PATT
	 .word	bgm_battle_legendary_5_000
	.byte	PATT
	 .word	bgm_battle_legendary_5_001
	.byte	W24
	.byte		N12   , En3 , v052
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle_legendary_5_002:
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Fn3 , v052
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        Cn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_legendary_5_002
	.byte	W24
	.byte		N12   , Gs3 , v052
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte		        0
	.byte	W96
	.byte	W96
	.byte		        0
	.byte	W96
	.byte	W96
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		N12   , Bn3 , v060
	.byte	W12
	.byte		        Bn3 , v052
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle_legendary_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle_legendary_6:
	.byte	KEYSH , bgm_battle_legendary_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v-4
	.byte		VOL   , 80*bgm_battle_legendary_mvl/mxv
	.byte		N96   , Gn1 , v112
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		        Cn1 
	.byte	W96
bgm_battle_legendary_6_000:
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N36   , Cn2 , v096
	.byte	W36
	.byte		N36   
	.byte	W36
	.byte		N24   
	.byte	W12
	.byte	PEND
bgm_battle_legendary_6_001:
	.byte	W12
	.byte		N12   , Cn2 , v096
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N48   
	.byte	W24
	.byte	PEND
bgm_battle_legendary_6_002:
	.byte	W24
	.byte		N24   , Cn2 , v096
	.byte	W24
	.byte		N36   
	.byte	W36
	.byte		N24   
	.byte	W12
	.byte	PEND
bgm_battle_legendary_6_003:
	.byte	W12
	.byte		N36   , Cn2 , v096
	.byte	W36
	.byte		N36   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_battle_legendary_6_B1:
bgm_battle_legendary_6_004:
	.byte		PAN   , c_v-16
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PEND
bgm_battle_legendary_6_005:
	.byte		PAN   , c_v-16
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gn1 
	.byte	W12
	.byte	PEND
bgm_battle_legendary_6_006:
	.byte		PAN   , c_v-16
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_005
	.byte	PATT
	 .word	bgm_battle_legendary_6_006
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_005
	.byte	PATT
	 .word	bgm_battle_legendary_6_006
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_005
	.byte	PATT
	 .word	bgm_battle_legendary_6_006
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
	.byte	PATT
	 .word	bgm_battle_legendary_6_005
	.byte	PATT
	 .word	bgm_battle_legendary_6_006
	.byte	PATT
	 .word	bgm_battle_legendary_6_004
bgm_battle_legendary_6_007:
	.byte		PAN   , c_v-16
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Ds2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Ds2 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , As1 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Ds2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_legendary_6_007
	.byte	PATT
	 .word	bgm_battle_legendary_6_000
	.byte	PATT
	 .word	bgm_battle_legendary_6_001
	.byte	PATT
	 .word	bgm_battle_legendary_6_002
bgm_battle_legendary_6_008:
	.byte	W12
	.byte		N36   , Cn2 , v096
	.byte	W36
	.byte		N36   
	.byte	W36
	.byte		N24   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_legendary_6_008
	.byte	PATT
	 .word	bgm_battle_legendary_6_001
	.byte	PATT
	 .word	bgm_battle_legendary_6_002
	.byte	PATT
	 .word	bgm_battle_legendary_6_003
	.byte	GOTO
	 .word	bgm_battle_legendary_6_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle_legendary:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle_legendary_pri	@ Priority
	.byte	bgm_battle_legendary_rev	@ Reverb.

	.word	bgm_battle_legendary_grp

	.word	bgm_battle_legendary_1
	.word	bgm_battle_legendary_2
	.word	bgm_battle_legendary_3
	.word	bgm_battle_legendary_4
	.word	bgm_battle_legendary_5
	.word	bgm_battle_legendary_6

	.end
