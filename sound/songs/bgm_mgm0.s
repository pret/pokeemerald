	.include "MPlayDef.s"

	.equ	bgm_mgm0_grp, voicegroup_868F87C
	.equ	bgm_mgm0_pri, 0
	.equ	bgm_mgm0_rev, reverb_set+50
	.equ	bgm_mgm0_mvl, 127
	.equ	bgm_mgm0_key, 0
	.equ	bgm_mgm0_tbs, 1
	.equ	bgm_mgm0_exg, 0
	.equ	bgm_mgm0_cmp, 1

	.section .rodata
	.global	bgm_mgm0
	.align	2

@********************** Track  1 **********************@

bgm_mgm0_1:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte	TEMPO , 148*bgm_mgm0_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 52*bgm_mgm0_mvl/mxv
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v060
	.byte	W06
bgm_mgm0_1_B1:
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v052
	.byte	W06
	.byte		        Fs5 , v092
	.byte	W06
	.byte		        Fs5 , v052
	.byte	W06
	.byte		        Fs5 , v108
	.byte	W12
	.byte		        Fs5 , v096
	.byte	W12
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v084
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v080
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		N12   , An5 
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 
	.byte	W12
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v096
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v080
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v080
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v096
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v080
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v080
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v104
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v048
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W12
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W12
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
bgm_mgm0_1_000:
	.byte		N03   , Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W12
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v084
	.byte	W12
	.byte	PEND
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W12
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W12
	.byte		        Fs5 , v084
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte	PATT
	 .word	bgm_mgm0_1_000
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W30
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v060
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		N12   , An5 
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W30
	.byte		VOICE , 126
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v072
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v052
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v092
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 
	.byte	W06
	.byte		        Fs5 , v056
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v060
	.byte	W06
	.byte		        Fs5 , v044
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		N12   , An5 
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , Fs5 
	.byte	W08
	.byte		N01   , Fs5 , v064
	.byte	W08
	.byte		        Fs5 , v088
	.byte	W16
	.byte		        Fs5 , v112
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , An5 , v096
	.byte	W12
	.byte	GOTO
	 .word	bgm_mgm0_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_mgm0_2:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*bgm_mgm0_mvl/mxv
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		        En5 
	.byte	W06
bgm_mgm0_2_B1:
	.byte		N06   , Fn5 , v112
	.byte	W06
	.byte		N03   , En5 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W12
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W84
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W24
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W84
	.byte		VOICE , 60
	.byte		VOL   , 48*bgm_mgm0_mvl/mxv
	.byte		N48   , An3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		VOL   , 52*bgm_mgm0_mvl/mxv
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		VOL   , 56*bgm_mgm0_mvl/mxv
	.byte		N48   , Fn4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
bgm_mgm0_2_000:
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte	PEND
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		VOL   , 46*bgm_mgm0_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte	PATT
	 .word	bgm_mgm0_2_000
	.byte		N03   , An4 , v112
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte	W02
	.byte		N04   
	.byte	W08
	.byte		        As4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N03   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte	GOTO
	 .word	bgm_mgm0_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_mgm0_3:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 72*bgm_mgm0_mvl/mxv
	.byte	W12
bgm_mgm0_3_B1:
	.byte		BEND  , c_v+0
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N06   , An0 , v127
	.byte	W12
	.byte		N03   , An0 , v112
	.byte	W12
	.byte		N06   , An0 , v127
	.byte	W06
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 , v127
	.byte	W06
	.byte		N03   , Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 , v080
	.byte	W12
	.byte		N06   , An0 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N09   , Dn1 , v127
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , Dn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Fn1 , v096
	.byte	W12
	.byte		N24   , Dn1 , v127
	.byte	W06
	.byte		BEND  , c_v+8
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   , En2 , v084
	.byte	W06
	.byte		N03   , Fn2 , v112
	.byte	W06
	.byte		N06   , Cs2 , v080
	.byte	W06
	.byte		N03   , Dn2 , v112
	.byte	W06
	.byte		N06   , Gs1 , v084
	.byte	W06
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N06   , Fn1 , v084
	.byte	W06
	.byte		N03   , Gn1 , v112
	.byte	W06
	.byte		N06   , Fn1 , v127
	.byte	W06
	.byte		N03   , Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 , v080
	.byte	W12
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cs1 , v127
	.byte	W06
	.byte		N03   , Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Fn1 , v080
	.byte	W12
	.byte		N24   , Dn1 , v127
	.byte	W06
	.byte		BEND  , c_v+8
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   , Gn1 , v096
	.byte	W06
	.byte		        Dn1 , v084
	.byte	W06
	.byte		N03   , Gn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		VOL   , 54*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N15   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		VOL   , 58*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N15   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		VOL   , 62*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N15   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		VOL   , 72*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N15   , Dn1 , v127
	.byte	W18
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v112
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N09   , Gs1 , v108
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , Fs1 , v127
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W30
	.byte		        Fs1 , v127
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W54
bgm_mgm0_3_000:
	.byte		N03   , Fs1 , v127
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W90
	.byte	PEND
	.byte		        Fs1 , v127
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W30
	.byte		        Fs1 , v127
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W54
	.byte	PATT
	 .word	bgm_mgm0_3_000
	.byte	GOTO
	 .word	bgm_mgm0_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_mgm0_4:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 63*bgm_mgm0_mvl/mxv
	.byte		PAN   , c_v-21
	.byte	W12
bgm_mgm0_4_B1:
	.byte		N03   , Fn2 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W36
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		        An1 
	.byte	W36
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		N03   , Dn3 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		VOL   , 42*bgm_mgm0_mvl/mxv
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		VOL   , 51*bgm_mgm0_mvl/mxv
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		VOL   , 60*bgm_mgm0_mvl/mxv
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		VOL   , 64*bgm_mgm0_mvl/mxv
	.byte	W48
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte	W96
	.byte	W48
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte	W96
	.byte	GOTO
	 .word	bgm_mgm0_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_mgm0_5:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 57*bgm_mgm0_mvl/mxv
	.byte		PAN   , c_v+31
	.byte	W12
bgm_mgm0_5_B1:
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W96
	.byte	W48
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 47
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		N06   , Dn2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		VOL   , 44*bgm_mgm0_mvl/mxv
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		VOL   , 51*bgm_mgm0_mvl/mxv
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		VOL   , 58*bgm_mgm0_mvl/mxv
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W18
	.byte		N06   
	.byte	W12
bgm_mgm0_5_000:
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
	.byte	PEND
bgm_mgm0_5_001:
	.byte		N03   , Fs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W90
	.byte	PEND
	.byte	PATT
	 .word	bgm_mgm0_5_000
	.byte	PATT
	 .word	bgm_mgm0_5_001
	.byte	GOTO
	 .word	bgm_mgm0_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_mgm0_6:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-58
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        An2 
	.byte	W06
bgm_mgm0_6_B1:
	.byte		BEND  , c_v+0
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		N09   , Cn3 
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
bgm_mgm0_6_000:
	.byte		VOL   , 6*bgm_mgm0_mvl/mxv
	.byte		N96   , Fn4 , v112
	.byte	W05
	.byte		VOL   , 8*bgm_mgm0_mvl/mxv
	.byte	W07
	.byte		        9*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        10*bgm_mgm0_mvl/mxv
	.byte	W06
	.byte		        13*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        13*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        15*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        17*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        19*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        20*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        24*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        24*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        28*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mgm0_mvl/mxv
	.byte	W07
	.byte		        34*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        38*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        40*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        42*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        44*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        47*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        49*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        51*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        53*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        54*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        56*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte	PEND
	.byte		        36*bgm_mgm0_mvl/mxv
	.byte		N03   , Gn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N06   , An3 
	.byte	W12
	.byte	PATT
	 .word	bgm_mgm0_6_000
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		N03   , Gn4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , En5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W12
	.byte		BEND  , c_v+2
	.byte		N03   , Dn5 , v092
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
bgm_mgm0_6_001:
	.byte		N03   , Dn5 , v092
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte	PEND
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte	PATT
	 .word	bgm_mgm0_6_001
bgm_mgm0_6_002:
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte	PEND
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W42
	.byte	PATT
	 .word	bgm_mgm0_6_002
	.byte		N03   , Fs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N03   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_mgm0_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_mgm0_7:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
bgm_mgm0_7_B1:
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		VOL   , 6*bgm_mgm0_mvl/mxv
	.byte		N96   , An4 
	.byte	W05
	.byte		VOL   , 8*bgm_mgm0_mvl/mxv
	.byte	W07
	.byte		        9*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        10*bgm_mgm0_mvl/mxv
	.byte	W06
	.byte		        13*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        13*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        15*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        17*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        19*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        20*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        24*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        24*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        28*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mgm0_mvl/mxv
	.byte	W07
	.byte		        34*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        38*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        40*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        42*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        44*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        47*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        49*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        51*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        53*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        54*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        56*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        35*bgm_mgm0_mvl/mxv
	.byte		N03   , Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOL   , 6*bgm_mgm0_mvl/mxv
	.byte		N96   , Cn5 
	.byte	W05
	.byte		VOL   , 8*bgm_mgm0_mvl/mxv
	.byte	W07
	.byte		        9*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        10*bgm_mgm0_mvl/mxv
	.byte	W06
	.byte		        13*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        13*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        15*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        17*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        19*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        20*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        24*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        24*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        28*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mgm0_mvl/mxv
	.byte	W07
	.byte		        34*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        38*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        40*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        42*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        44*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        47*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        49*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        51*bgm_mgm0_mvl/mxv
	.byte	W02
	.byte		        53*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        54*bgm_mgm0_mvl/mxv
	.byte	W03
	.byte		        56*bgm_mgm0_mvl/mxv
	.byte	W04
	.byte		        35*bgm_mgm0_mvl/mxv
	.byte		N03   , Dn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W12
bgm_mgm0_7_000:
	.byte		N03   , Dn5 , v092
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte	PEND
bgm_mgm0_7_001:
	.byte		N03   , Dn5 , v092
	.byte	W12
	.byte		        Fn5 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_mgm0_7_000
	.byte	PATT
	 .word	bgm_mgm0_7_001
bgm_mgm0_7_002:
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte	PEND
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_mgm0_7_002
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte	W02
	.byte		N04   , An4 
	.byte	W08
	.byte		        As4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N03   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte	GOTO
	 .word	bgm_mgm0_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_mgm0_8:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_mgm0_mvl/mxv
	.byte	W12
bgm_mgm0_8_B1:
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N48   , An2 , v092
	.byte	W72
	.byte	W96
	.byte	W24
	.byte		N48   
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_mgm0_8_000:
	.byte	W24
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        Cn1 , v084
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	bgm_mgm0_8_000
	.byte	W24
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		        Cn1 , v060
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W24
	.byte	GOTO
	 .word	bgm_mgm0_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_mgm0_9:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*bgm_mgm0_mvl/mxv
	.byte	W12
bgm_mgm0_9_B1:
	.byte	W96
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 41*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N03   , Gn2 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W12
	.byte	W96
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W12
	.byte		VOICE , 29
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N24   , Fn3 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N06   , Cs3 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N24   , Gn3 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N06   , Cs3 
	.byte	W12
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N24   , Fn3 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N06   , Cs3 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 36*bgm_mgm0_mvl/mxv
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   , Bn1 
	.byte	W12
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-18
	.byte	W04
	.byte		        c_v-22
	.byte	W02
	.byte		        c_v-31
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-42
	.byte	W04
	.byte		        c_v+0
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte	W24
	.byte		N72   , As1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W05
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-4
	.byte	W04
	.byte		        c_v-7
	.byte	W02
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-15
	.byte	W04
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-27
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-40
	.byte	W04
	.byte		        c_v-43
	.byte	W02
	.byte		        c_v-50
	.byte	W03
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-54
	.byte	W04
	.byte	GOTO
	 .word	bgm_mgm0_9_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track 10 **********************@

bgm_mgm0_10:
	.byte	KEYSH , bgm_mgm0_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-18
	.byte		VOL   , 46*bgm_mgm0_mvl/mxv
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
bgm_mgm0_10_B1:
	.byte		N03   , Cn5 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , En4 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W84
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_mgm0_10_000:
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte	PEND
	.byte		VOL   , 45*bgm_mgm0_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_mgm0_10_000
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte	W02
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N03   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	GOTO
	 .word	bgm_mgm0_10_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_mgm0:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_mgm0_pri	@ Priority
	.byte	bgm_mgm0_rev	@ Reverb.

	.word	bgm_mgm0_grp

	.word	bgm_mgm0_1
	.word	bgm_mgm0_2
	.word	bgm_mgm0_3
	.word	bgm_mgm0_4
	.word	bgm_mgm0_5
	.word	bgm_mgm0_6
	.word	bgm_mgm0_7
	.word	bgm_mgm0_8
	.word	bgm_mgm0_9
	.word	bgm_mgm0_10

	.end
