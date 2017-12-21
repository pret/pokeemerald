	.include "MPlayDef.s"

	.equ	bgm_frlg_battle_leader_grp, voicegroup_86A8CBC
	.equ	bgm_frlg_battle_leader_pri, 0
	.equ	bgm_frlg_battle_leader_rev, reverb_set+50
	.equ	bgm_frlg_battle_leader_mvl, 127
	.equ	bgm_frlg_battle_leader_key, 0
	.equ	bgm_frlg_battle_leader_tbs, 1
	.equ	bgm_frlg_battle_leader_exg, 0
	.equ	bgm_frlg_battle_leader_cmp, 1

	.section .rodata
	.global	bgm_frlg_battle_leader
	.align	2

@********************** Track  1 **********************@

bgm_frlg_battle_leader_1:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte	TEMPO , 186*bgm_frlg_battle_leader_tbs/2
	.byte		VOICE , 17
	.byte		PAN   , c_v-30
	.byte		VOL   , 66*bgm_frlg_battle_leader_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W36
	.byte		N06   , An3 , v127
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
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
	.byte		PAN   , c_v+0
	.byte		N06   , Fs3 
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
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 47
	.byte		VOL   , 90*bgm_frlg_battle_leader_mvl/mxv
	.byte	W48
bgm_frlg_battle_leader_1_B1:
	.byte		VOICE , 87
	.byte		MOD   , 8
	.byte		PAN   , c_v+63
	.byte		VOL   , 60*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , An3 , v127
	.byte	W96
	.byte		PAN   , c_v-64
	.byte		N06   
	.byte	W48
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N24   , As3 
	.byte	W36
	.byte		PAN   , c_v-64
	.byte		N06   , Dn3 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N06   , Dn3 , v120
	.byte	W72
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v127
	.byte	W48
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		PAN   , c_v-64
	.byte		N06   , An3 
	.byte	W96
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W48
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N36   , As3 
	.byte	W36
	.byte		PAN   , c_v+63
	.byte		N06   , An3 
	.byte	W96
	.byte		PAN   , c_v-64
	.byte		N06   
	.byte	W48
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W36
	.byte		VOICE , 4
	.byte		PAN   , c_v+48
	.byte		VOL   , 49*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , An2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+46
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+40
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+24
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-8
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-24
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-39
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-24
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-10
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+41
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , An2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-41
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-24
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-8
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+25
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+41
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+10
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-10
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-25
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-39
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn4 , v096
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Cn4 , v084
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Gn4 , v064
	.byte	W06
	.byte		VOICE , 62
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Dn2 , v120
	.byte	W12
	.byte		        Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N18   , Fn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 61*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N18   , Gn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 61*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N18   , Fn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 61*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En2 
	.byte	W06
	.byte		MOD   , 9
	.byte	W06
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        Fn2 , v120
	.byte	W06
	.byte		        Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N18   , Fn2 , v127
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 61*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N18   , Gn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 61*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N18   , Fn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 61*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N09   , En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N09   , Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 70*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 4
	.byte		PAN   , c_v+48
	.byte		VOL   , 46*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+40
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+8
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-8
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-24
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-41
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 24
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+2
	.byte		N06   , Ds2 , v096
	.byte	W06
	.byte		        En2 , v100
	.byte	W06
	.byte		PAN   , c_v-36
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		PAN   , c_v-26
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		PAN   , c_v+8
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+0
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		N06   , Ds3 , v127
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-40
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-25
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-9
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+10
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+25
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+40
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Ds3 , v120
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En3 , v104
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        Gn3 , v088
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		PAN   , c_v-15
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		PAN   , c_v+44
	.byte		N06   , Ds3 , v088
	.byte	W06
	.byte		        Dn3 , v096
	.byte	W06
	.byte		        Cs3 , v108
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		VOICE , 5
	.byte		PAN   , c_v+32
	.byte		VOL   , 66*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , En2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		PAN   , c_v-41
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Cn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		VOL   , 75*bgm_frlg_battle_leader_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v+39
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Cn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		VOICE , 4
	.byte		PAN   , c_v+40
	.byte		MOD   , 0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v-40
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v-14
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W03
	.byte		PAN   , c_v+36
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-36
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N36   , En3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W96
	.byte	W48
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
bgm_frlg_battle_leader_1_000:
	.byte		MOD   , 0
	.byte		N24   , Fs3 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte	PEND
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_battle_leader_1_000
	.byte		MOD   , 0
	.byte		N24   , An3 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_battle_leader_2:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 53*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Gs4 , v127
	.byte	W06
	.byte		        Gn4 , v096
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W24
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
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
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 , v100
	.byte	W06
	.byte		        En3 , v108
	.byte	W06
	.byte		        Fn3 , v116
	.byte	W06
	.byte		        En3 , v127
	.byte	W06
bgm_frlg_battle_leader_2_B1:
	.byte		VOICE , 29
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Dn4 , v127
	.byte	W24
	.byte		        Dn4 , v032
	.byte	W24
	.byte		        Dn4 , v016
	.byte	W24
	.byte		        Dn4 , v008
	.byte	W24
	.byte		        Dn4 , v127
	.byte	W24
	.byte		        Dn4 , v064
	.byte	W24
	.byte		        Dn4 , v048
	.byte	W12
	.byte		N24   , Ds4 , v127
	.byte	W24
	.byte		N06   , Fn4 , v120
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Dn4 , v127
	.byte	W24
	.byte		        Dn3 , v108
	.byte	W24
	.byte		        Dn4 , v016
	.byte	W24
	.byte		        Dn4 , v008
	.byte	W24
	.byte		        Dn4 , v127
	.byte	W24
	.byte		        Dn4 , v032
	.byte	W24
	.byte		        Dn4 , v016
	.byte	W12
	.byte		N36   , Cs4 , v127
	.byte	W36
bgm_frlg_battle_leader_2_000:
	.byte		N06   , Dn4 , v127
	.byte	W24
	.byte		        Dn4 , v032
	.byte	W24
	.byte		        Dn4 , v016
	.byte	W24
	.byte		        Dn4 , v008
	.byte	W24
	.byte	PEND
	.byte		        Dn4 , v127
	.byte	W24
	.byte		        Dn4 , v032
	.byte	W24
	.byte		        Dn4 , v016
	.byte	W12
	.byte		N36   , Ds4 , v127
	.byte	W36
	.byte	PATT
	 .word	bgm_frlg_battle_leader_2_000
	.byte		N06   , Dn4 , v127
	.byte	W24
	.byte		        Dn4 , v032
	.byte	W24
	.byte		        Dn4 , v016
	.byte	W12
	.byte		N36   , En4 , v127
	.byte	W36
	.byte		VOICE , 48
	.byte		VOL   , 62*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W15
	.byte		MOD   , 2
	.byte	W09
	.byte		N12   , Fs4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N48   , Cn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W36
	.byte		        0
	.byte		N48   , En4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W36
	.byte		        0
	.byte		N60   , Gn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 , v120
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 84*bgm_frlg_battle_leader_mvl/mxv
	.byte		N18   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		N03   , Gn5 
	.byte	W03
	.byte		        Fs5 , v108
	.byte	W03
	.byte		MOD   , 0
	.byte		N21   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W09
	.byte		N03   , Fn5 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N09   , Gn5 
	.byte	W09
	.byte		N03   , Gs5 
	.byte	W03
	.byte		N24   , An5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N09   , Dn5 
	.byte	W09
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N09   , En5 
	.byte	W09
	.byte		N03   , Fn5 
	.byte	W03
	.byte		N12   , Fs5 
	.byte	W12
	.byte		N44   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W09
	.byte		N03   , Ds5 
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 82*bgm_frlg_battle_leader_mvl/mxv
	.byte		N44   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W09
	.byte		N03   , Cs5 
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 82*bgm_frlg_battle_leader_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 84*bgm_frlg_battle_leader_mvl/mxv
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 82*bgm_frlg_battle_leader_mvl/mxv
	.byte		N12   , En5 
	.byte	W12
	.byte		VOICE , 17
	.byte		VOL   , 86*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W12
	.byte		        Fn4 , v127
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W30
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	W24
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W18
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W30
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W30
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		VOL   , 60*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 24
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N96   , An3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte	W48
	.byte		MOD   , 0
	.byte		VOL   , 59*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        En3 , v100
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
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		VOICE , 30
	.byte		N06   , An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N24   , Dn4 , v092
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N96   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W84
	.byte		        0
	.byte		BEND  , c_v+0
	.byte		N96   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		VOL   , 58*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		VOL   , 52*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W06
	.byte		VOL   , 36*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		VOL   , 23*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		        17*bgm_frlg_battle_leader_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		VOL   , 9*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 60*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N06   , Cn2 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Cn4 
	.byte	W72
	.byte		N06   , Cn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , En4 
	.byte	W72
	.byte		N96   , Fs4 
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		VOICE , 60
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Cn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , En4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N48   , Cn5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Gn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 55*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , Dn5 , v120
	.byte	W60
	.byte		MOD   , 5
	.byte	W36
	.byte	W48
	.byte		VOL   , 54*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		VOL   , 49*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		        44*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W06
	.byte		VOL   , 41*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		        38*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		VOL   , 33*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		        26*bgm_frlg_battle_leader_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		VOL   , 21*bgm_frlg_battle_leader_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N24   , Fs3 , v127
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N96   , Dn5 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 63*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   , An4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 63*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   , Cn5 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 63*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_battle_leader_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , En5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		N36   , Cn5 
	.byte	W36
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_battle_leader_3:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-63
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte	W72
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   , En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
bgm_frlg_battle_leader_3_B1:
bgm_frlg_battle_leader_3_000:
	.byte		PAN   , c_v-63
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
bgm_frlg_battle_leader_3_001:
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N36   , Ds1 
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_000
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N36   , Gs1 
	.byte	W36
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_001
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_000
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N36   , En1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_000
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
bgm_frlg_battle_leader_3_002:
	.byte		PAN   , c_v-63
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_002
bgm_frlg_battle_leader_3_003:
	.byte		PAN   , c_v-63
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_003
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_002
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_002
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+3
	.byte		N06   , Dn2 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Fn4 , v076
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W72
bgm_frlg_battle_leader_3_004:
	.byte		N06   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W72
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_004
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_004
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_004
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_004
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_004
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_004
	.byte		N06   , Cn3 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N96   , Fs3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N96   , Dn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N48   , En3 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 39*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_battle_leader_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_frlg_battle_leader_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
bgm_frlg_battle_leader_3_005:
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N36   , As2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N36   , Ds2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_battle_leader_3_005
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N36   , An2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_3_B1
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_battle_leader_4:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W96
	.byte	W48
	.byte		N06   , Bn1 , v127
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
bgm_frlg_battle_leader_4_B1:
	.byte		MOD   , 7
	.byte		N06   , Dn2 , v120
	.byte	W84
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Dn2 
	.byte	W60
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		N06   , Dn2 
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W60
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W60
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		        Dn1 , v120
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v120
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N36   , An1 
	.byte	W36
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , An2 
	.byte	W18
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W18
	.byte		N03   , En2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Fn1 
	.byte	W06
	.byte		MOD   , 16
	.byte	W18
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 16
	.byte	W18
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Fn1 
	.byte	W06
	.byte		MOD   , 16
	.byte	W18
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Fn1 
	.byte	W06
	.byte		MOD   , 16
	.byte	W18
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 16
	.byte	W18
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Fn1 
	.byte	W06
	.byte		MOD   , 16
	.byte	W18
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Dn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W78
	.byte		N03   , Cs1 
	.byte	W06
bgm_frlg_battle_leader_4_000:
	.byte		N06   , Dn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W78
	.byte		N03   , Cs1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_4_000
bgm_frlg_battle_leader_4_001:
	.byte		N06   , Dn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte		N24   , Cs1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_4_001
	.byte	PATT
	 .word	bgm_frlg_battle_leader_4_001
	.byte		N06   , Dn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte		N12   , An1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W84
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Cn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , En3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		VOICE , 81
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N06   , Fs5 , v064
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N72   , Gn2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N48   , Cn2 
	.byte	W15
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N48   , Gn1 
	.byte	W15
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N24   , Dn1 
	.byte	W36
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W18
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W15
	.byte		N06   , An1 
	.byte	W09
	.byte		        Dn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		        Ds1 
	.byte	W03
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_battle_leader_5:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 77*bgm_frlg_battle_leader_mvl/mxv
	.byte	W72
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Ds3 
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
	.byte		        Fn3 
	.byte	W06
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
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
bgm_frlg_battle_leader_5_B1:
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
	.byte		VOICE , 62
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*bgm_frlg_battle_leader_mvl/mxv
	.byte		N06   , Fn2 , v120
	.byte	W12
	.byte		        Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N09   , An2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N09   , As2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , An2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N09   , Gn2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W06
	.byte		        Fn2 , v127
	.byte	W06
	.byte		        Fn2 , v120
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N12   , An2 , v127
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , As2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , An2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N09   , Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N09   , En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		VOICE , 29
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , An2 , v076
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+63
	.byte		N72   
	.byte	W03
	.byte		BEND  , c_v+59
	.byte	W03
	.byte		        c_v+53
	.byte	W03
	.byte		PAN   , c_v-25
	.byte		BEND  , c_v+45
	.byte	W03
	.byte		        c_v+37
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+27
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+15
	.byte	W03
	.byte		PAN   , c_v+18
	.byte		BEND  , c_v+9
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		PAN   , c_v+47
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-22
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		VOL   , 67*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-35
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		VOL   , 62*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W06
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-54
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte		VOL   , 49*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-63
	.byte	W06
	.byte		VOL   , 72*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 14
	.byte		PAN   , c_v-33
	.byte		BEND  , c_v+0
	.byte		N24   , Fs4 , v120
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte	W24
	.byte		N24   , Dn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-32
	.byte	W48
	.byte		        c_v+32
	.byte	W48
	.byte		        c_v-32
	.byte		VOL   , 77*bgm_frlg_battle_leader_mvl/mxv
	.byte		N24   , Dn5 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Dn5 , v044
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , An4 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , An4 , v044
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cn5 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Cn5 , v044
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Gn4 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Gn4 , v044
	.byte	W24
	.byte		VOL   , 72*bgm_frlg_battle_leader_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_battle_leader_6:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 77*bgm_frlg_battle_leader_mvl/mxv
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v-64
	.byte		N06   , An2 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Dn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   
	.byte	W06
bgm_frlg_battle_leader_6_B1:
	.byte		VOICE , 47
	.byte		VOL   , 79*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N48   , Dn3 , v112
	.byte	W84
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N48   , Dn3 
	.byte	W60
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N48   , Dn2 
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	W60
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 90*bgm_frlg_battle_leader_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N36   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Dn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Dn3 
	.byte	W12
	.byte		PAN   , c_v+34
	.byte		N12   , An2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+34
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-33
	.byte		N12   , Dn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Dn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N36   , En2 
	.byte	W36
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		VOL   , 58*bgm_frlg_battle_leader_mvl/mxv
	.byte		N24   , Dn4 , v120
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W15
	.byte		MOD   , 2
	.byte	W09
	.byte		N12   , Dn4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 2
	.byte	W24
	.byte		N06   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N60   , En4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		VOL   , 43*bgm_frlg_battle_leader_mvl/mxv
	.byte		N18   , An4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N21   , Gn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N21   , An4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N09   , Dn5 
	.byte	W09
	.byte		N03   , En5 
	.byte	W03
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N12   , An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N09   , En4 
	.byte	W09
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N44   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		N03   , Cs5 
	.byte	W03
	.byte		MOD   , 0
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N48   , Gn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		        0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24   , An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N96   , An3 
	.byte	W96
	.byte		N48   , Dn4 
	.byte	W48
	.byte		BEND  , c_v-3
	.byte		N48   , Fs4 
	.byte	W12
	.byte		VOL   , 34*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W12
	.byte		VOL   , 21*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W12
	.byte		VOL   , 10*bgm_frlg_battle_leader_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W09
	.byte		VOL   , 43*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte		VOL   , 90*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+26
	.byte		N06   , En3 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N60   , Gn1 
	.byte	W60
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+26
	.byte		N48   
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N48   , Gn1 
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N06   , Dn2 
	.byte	W36
	.byte		        An1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W36
	.byte		        An1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte		VOICE , 83
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N72   , An4 
	.byte	W72
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N32   , En4 
	.byte	W32
	.byte	W01
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N48   , An4 
	.byte	W48
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N24   , Cn5 
	.byte	W36
	.byte		N36   , Gn4 
	.byte	W36
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_battle_leader_7:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 88
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 26*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N06   , Gs5 , v127
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W24
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
bgm_frlg_battle_leader_7_B1:
	.byte		BEND  , c_v+0
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
	.byte		VOICE , 89
	.byte		VOL   , 56*bgm_frlg_battle_leader_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   , Dn2 , v120
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , En2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , En2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N12   , Dn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N12   , Cn2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N12   , En2 
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		BEND  , c_v+0
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
	.byte		VOICE , 88
	.byte	W24
	.byte		N72   , Cn4 , v064
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N48   , Gn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , En4 
	.byte	W21
	.byte		        Cn4 
	.byte	W24
	.byte	W03
	.byte		TIE   , Fs4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W72
	.byte	W48
	.byte		BEND  , c_v-3
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v-6
	.byte	W15
	.byte		        c_v-8
	.byte	W09
	.byte		EOT   
	.byte		VOICE , 88
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N48   
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_battle_leader_8:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 77*bgm_frlg_battle_leader_mvl/mxv
	.byte	W96
	.byte	W96
bgm_frlg_battle_leader_8_B1:
	.byte		N06   , Cs1 , v120
	.byte		N48   , Cs2 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v120
	.byte		N48   , Bn2 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        En1 , v120
	.byte		N24   , An2 
	.byte	W24
	.byte		N06   , Fn1 
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        En1 
	.byte		N24   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        En1 , v120
	.byte		N48   , An2 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W03
	.byte		VOL   , 89*bgm_frlg_battle_leader_mvl/mxv
	.byte	W21
	.byte		N06   
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte		N06   , Fn1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		N06   
	.byte		N48   , Cn3 
	.byte	W12
	.byte		N06   , Cn1 
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N48   , Cs2 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
bgm_frlg_battle_leader_8_000:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_8_000
	.byte		N06   , Cn1 , v120
	.byte		N06   , An4 , v036
	.byte	W12
	.byte		        Cs1 , v120
	.byte		N06   , An4 , v036
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N06   , An4 , v036
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , Gs4 , v036
	.byte	W06
	.byte		        Cs1 , v120
	.byte		N06   , An4 , v036
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N06   , An4 , v036
	.byte	W12
	.byte		        Cs1 , v120
	.byte		N06   , Gs4 , v036
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , An4 , v036
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N06   , Gs4 , v036
	.byte	W06
	.byte		        Cs1 , v120
	.byte		N06   , An4 , v036
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_leader_8_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_8_000
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte		N48   , Cn3 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Dn1 , v096
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        En1 
	.byte		N48   , Cs2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W78
	.byte		        Cn1 , v084
	.byte	W06
bgm_frlg_battle_leader_8_001:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W78
	.byte		        Cn1 , v084
	.byte	W06
	.byte	PEND
bgm_frlg_battle_leader_8_002:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte		        Dn1 
	.byte		N24   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte	PEND
	.byte		        En1 
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N06   , En1 
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W78
	.byte		        Cn1 , v084
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_battle_leader_8_001
	.byte	PATT
	 .word	bgm_frlg_battle_leader_8_002
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte		N06   , Cs2 
	.byte	W48
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N06   , An2 
	.byte	W24
	.byte		N48   , Cn3 
	.byte	W48
	.byte		N06   , Fn2 , v068
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte		        Cn1 , v120
	.byte	W42
	.byte		N03   , Cn1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_frlg_battle_leader_9:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
bgm_frlg_battle_leader_9_B1:
bgm_frlg_battle_leader_9_000:
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
bgm_frlg_battle_leader_9_001:
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W48
	.byte	PEND
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_001
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_001
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_frlg_battle_leader_9_002:
	.byte	W24
	.byte		N03   , Cn5 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_002
	.byte	W96
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
bgm_frlg_battle_leader_9_003:
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_003
	.byte	W96
bgm_frlg_battle_leader_9_004:
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_004
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_004
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v028
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_frlg_battle_leader_9_005:
	.byte		N03   , Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v068
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_005
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_005
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_005
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_005
	.byte	PATT
	 .word	bgm_frlg_battle_leader_9_005
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_9_B1
	.byte	FINE

@********************** Track 10 **********************@

bgm_frlg_battle_leader_10:
	.byte	KEYSH , bgm_frlg_battle_leader_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*bgm_frlg_battle_leader_mvl/mxv
	.byte	W96
	.byte		BEND  , c_v-64
	.byte		N96   , Gn2 , v096
	.byte	W06
	.byte		BEND  , c_v-58
	.byte	W06
	.byte		        c_v-48
	.byte	W06
	.byte		        c_v-41
	.byte	W06
	.byte		        c_v-32
	.byte	W06
	.byte		        c_v-25
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-9
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+6
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+22
	.byte	W06
	.byte		        c_v+32
	.byte	W06
	.byte		        c_v+38
	.byte	W06
	.byte		        c_v+48
	.byte	W06
	.byte		        c_v+56
	.byte	W06
bgm_frlg_battle_leader_10_B1:
	.byte		BEND  , c_v+63
	.byte	W96
	.byte	W60
	.byte		N36   , Gn5 , v120
	.byte	W36
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	W60
	.byte		N36   
	.byte	W36
	.byte	W96
	.byte	W60
	.byte		N36   
	.byte	W36
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	W60
	.byte		N36   
	.byte	W36
bgm_frlg_battle_leader_10_000:
	.byte		N09   , Gn5 , v092
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Gn5 , v120
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v068
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_000
bgm_frlg_battle_leader_10_001:
	.byte		N09   , Gn5 , v120
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W36
	.byte		        Gn5 , v120
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W36
	.byte	PEND
	.byte		        Gn5 , v120
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W36
	.byte		        Gn5 , v120
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		N12   , Gn5 , v120
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_frlg_battle_leader_10_002:
	.byte	W24
	.byte		N12   , Gn5 , v096
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_002
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_002
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_002
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_002
	.byte	PATT
	 .word	bgm_frlg_battle_leader_10_002
	.byte	GOTO
	 .word	bgm_frlg_battle_leader_10_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_battle_leader:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_battle_leader_pri	@ Priority
	.byte	bgm_frlg_battle_leader_rev	@ Reverb.

	.word	bgm_frlg_battle_leader_grp

	.word	bgm_frlg_battle_leader_1
	.word	bgm_frlg_battle_leader_2
	.word	bgm_frlg_battle_leader_3
	.word	bgm_frlg_battle_leader_4
	.word	bgm_frlg_battle_leader_5
	.word	bgm_frlg_battle_leader_6
	.word	bgm_frlg_battle_leader_7
	.word	bgm_frlg_battle_leader_8
	.word	bgm_frlg_battle_leader_9
	.word	bgm_frlg_battle_leader_10

	.end
