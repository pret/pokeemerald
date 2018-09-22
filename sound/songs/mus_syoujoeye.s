	.include "MPlayDef.s"

	.equ	mus_syoujoeye_grp, voicegroup027
	.equ	mus_syoujoeye_pri, 0
	.equ	mus_syoujoeye_rev, reverb_set+50
	.equ	mus_syoujoeye_mvl, 127
	.equ	mus_syoujoeye_key, 0
	.equ	mus_syoujoeye_tbs, 1
	.equ	mus_syoujoeye_exg, 0
	.equ	mus_syoujoeye_cmp, 1

	.section .rodata
	.global	mus_syoujoeye
	.align	2

@********************** Track  1 **********************@

mus_syoujoeye_1:
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte	TEMPO , 144*mus_syoujoeye_tbs/2
	.byte		VOICE , 13
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		N06   , Gs4 , v100
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W03
	.byte		        Ds5 , v076
	.byte	W03
	.byte		        Ds5 , v072
	.byte	W03
	.byte		        Ds5 , v068
	.byte	W03
	.byte		        Ds5 , v064
	.byte	W03
	.byte		        Ds5 , v060
	.byte	W03
	.byte		        Ds5 , v056
	.byte	W03
	.byte		        Ds5 , v052
	.byte	W03
	.byte		        Ds5 , v048
	.byte	W03
	.byte		        Ds5 , v044
	.byte	W03
	.byte		        Ds5 , v040
	.byte	W03
	.byte		        Ds5 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Ds5 , v040
	.byte	W03
	.byte		        Ds5 , v044
	.byte	W03
	.byte		        Ds5 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Ds5 , v052
	.byte	W03
	.byte		        Ds5 , v056
	.byte	W03
	.byte		        Ds5 , v060
	.byte	W03
	.byte		        Ds5 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Ds5 , v060
	.byte	W03
	.byte		        Ds5 , v056
	.byte	W03
	.byte		        Ds5 , v052
	.byte	W03
	.byte		        Ds5 , v048
	.byte	W03
	.byte		        Ds5 , v040
	.byte	W03
	.byte		        Ds5 , v036
	.byte	W15
mus_syoujoeye_1_B1:
mus_syoujoeye_1_000:
	.byte		N12   , Gs4 , v100
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W18
	.byte		        Gs4 
	.byte	W24
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W18
	.byte		        Cn5 
	.byte	W06
	.byte	PEND
	.byte		N12   , Cs5 
	.byte	W18
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W18
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		        Gs4 , v048
	.byte	W03
	.byte		        Gs4 , v040
	.byte	W03
	.byte		        Gs4 , v036
	.byte	W18
	.byte		        As4 , v100
	.byte	W03
	.byte		        As4 , v068
	.byte	W03
	.byte		N03   
	.byte	W12
	.byte		N06   , Gs4 , v100
	.byte	W06
	.byte		        Fs4 
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        Fs4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W12
	.byte		N06   , Fn4 , v100
	.byte	W06
	.byte		        Fs4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W15
	.byte		        Fs4 , v100
	.byte	W03
	.byte		        Fs4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W15
	.byte		        Fn4 , v100
	.byte	W03
	.byte		        Fn4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W15
	.byte		        Ds4 , v100
	.byte	W03
	.byte		        Ds4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W15
	.byte	PATT
	 .word	mus_syoujoeye_1_000
	.byte		N12   , Cs5 , v100
	.byte	W18
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W18
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		        Gs4 , v048
	.byte	W03
	.byte		        Gs4 , v040
	.byte	W03
	.byte		        Gs4 , v036
	.byte	W18
	.byte		N06   , As4 , v100
	.byte	W18
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W18
	.byte		N03   , Fs5 
	.byte	W03
	.byte		        Fs5 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W12
	.byte		N06   , Fn5 , v100
	.byte	W06
	.byte		        Fs5 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W03
	.byte		        Ds5 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W15
	.byte		        Fn5 , v100
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W15
	.byte		        Cs5 , v100
	.byte	W03
	.byte		        Cs5 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W36
	.byte	W03
	.byte	GOTO
	 .word	mus_syoujoeye_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_syoujoeye_2:
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte		PAN   , c_v-6
	.byte	W24
	.byte		VOICE , 38
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte		N36   , Gs0 , v127
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        Gs1 
	.byte	W06
	.byte		        Gs0 
	.byte	W18
	.byte		        Cn1 
	.byte	W06
mus_syoujoeye_2_B1:
mus_syoujoeye_2_000:
	.byte		N36   , Cs1 , v127
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N18   , Gs1 
	.byte	W18
	.byte		N06   , Cs1 
	.byte	W06
	.byte	PEND
mus_syoujoeye_2_001:
	.byte		N36   , Fs1 , v127
	.byte	W42
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        Gs1 
	.byte	W06
	.byte		N18   , Cs2 
	.byte	W18
	.byte		N06   , Cs1 
	.byte	W06
	.byte	PEND
	.byte		N48   , Ds1 
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N06   , Gs1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Ds2 
	.byte	W18
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N06   , Gs0 
	.byte	W06
	.byte		N18   , As0 
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte	PATT
	 .word	mus_syoujoeye_2_000
	.byte	PATT
	 .word	mus_syoujoeye_2_001
	.byte		N18   , Ds1 , v127
	.byte	W18
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N18   , As1 
	.byte	W18
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N18   , Gs1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W48
	.byte	GOTO
	 .word	mus_syoujoeye_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_syoujoeye_3:
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte		PAN   , c_v+16
	.byte	W24
	.byte		VOICE , 1
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Gs2 , v088
	.byte	W18
	.byte		        Gs1 
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N21   , Gs2 
	.byte	W24
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N18   , Ds2 
	.byte	W18
	.byte		N06   , Cn2 
	.byte	W06
mus_syoujoeye_3_B1:
mus_syoujoeye_3_000:
	.byte		N12   , Cs2 , v088
	.byte	W24
	.byte		        Gs2 
	.byte	W18
	.byte		N30   , Fn2 
	.byte	W30
	.byte		N15   , Gs2 
	.byte	W18
	.byte		N06   , Cs2 
	.byte	W06
	.byte	PEND
mus_syoujoeye_3_001:
	.byte		N09   , Fs2 , v088
	.byte	W18
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W18
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N18   , Gs2 
	.byte	W18
	.byte		N06   , Cs2 
	.byte	W06
	.byte	PEND
	.byte		        Cs4 , v096
	.byte	W18
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W18
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		        As3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fs2 , v088
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte	PATT
	 .word	mus_syoujoeye_3_000
	.byte	PATT
	 .word	mus_syoujoeye_3_001
	.byte		N12   , Fs4 , v096
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W18
	.byte		N15   , As4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W18
	.byte		N06   , As4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W24
	.byte		N24   , Gs2 , v088
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W48
	.byte	GOTO
	 .word	mus_syoujoeye_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_syoujoeye_4:
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte		VOICE , 24
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte		PAN   , c_v-48
	.byte		N06   , Gs3 , v052
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W18
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        Fs3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		        Gs2 
	.byte	W06
	.byte		        Fs3 
	.byte	W18
	.byte		        Cn4 
	.byte	W06
mus_syoujoeye_4_B1:
	.byte		N06   , Cn4 , v052
	.byte	W18
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		        Fn3 
	.byte	W06
mus_syoujoeye_4_000:
	.byte		N06   , Fn4 , v052
	.byte	W18
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W18
	.byte		        Fn3 
	.byte	W06
	.byte	PEND
	.byte		        As2 
	.byte	W18
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W18
	.byte		VOICE , 26
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W06
	.byte		VOICE , 24
	.byte		N06   , Ds3 
	.byte	W18
	.byte		        Cs3 
	.byte	W06
	.byte		VOICE , 26
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		VOICE , 24
	.byte		N06   , Cn4 
	.byte	W18
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		        Fn3 
	.byte	W06
	.byte	PATT
	 .word	mus_syoujoeye_4_000
	.byte		VOICE , 26
	.byte		N42   , Cs4 , v052
	.byte	W42
	.byte		N03   
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N18   , As3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		VOICE , 24
	.byte		N06   , Gs3 
	.byte	W18
	.byte		        Fs3 
	.byte	W06
	.byte		VOICE , 26
	.byte		N24   , Cn4 
	.byte	W24
	.byte		VOICE , 24
	.byte		N06   
	.byte	W48
	.byte	GOTO
	 .word	mus_syoujoeye_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_syoujoeye_5:
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte		VOICE , 25
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		N06   , Gs3 , v020
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W03
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte	W03
	.byte		N12   , Ds4 
	.byte	W18
	.byte		BEND  , c_v+0
	.byte		N03   , Ds3 , v052
	.byte	W03
	.byte		N06   , Cn3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte	W03
	.byte		N03   , Ds3 
	.byte	W03
	.byte		N06   , Cn3 
	.byte	W18
	.byte		        Fs3 
	.byte	W06
mus_syoujoeye_5_B1:
	.byte		N06   , Fn3 , v052
	.byte	W21
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Fn3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte	W03
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Fn3 
	.byte	W18
	.byte		        Cn3 
	.byte	W06
mus_syoujoeye_5_000:
	.byte		N06   , Cs4 , v052
	.byte	W21
	.byte		N03   , As3 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte	W03
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Fn3 
	.byte	W18
	.byte		        Cn3 
	.byte	W06
	.byte	PEND
	.byte		        Fs2 
	.byte	W18
	.byte		        Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W18
	.byte		VOICE , 27
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		VOICE , 25
	.byte		N06   , Cn3 
	.byte	W18
	.byte		        As2 
	.byte	W06
	.byte		VOICE , 27
	.byte		N24   , Gs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		VOICE , 25
	.byte		N06   , Fn3 
	.byte	W21
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Fn3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte	W03
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Fn3 
	.byte	W18
	.byte		        Cn3 
	.byte	W06
	.byte	PATT
	 .word	mus_syoujoeye_5_000
	.byte		VOICE , 27
	.byte		N42   , As3 , v052
	.byte	W42
	.byte		N03   
	.byte	W24
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N18   
	.byte	W18
	.byte		N06   , As2 
	.byte	W06
	.byte		VOICE , 25
	.byte		N06   , Fs3 
	.byte	W21
	.byte		N03   , Gs3 
	.byte	W03
	.byte		VOICE , 27
	.byte		N24   , Fs3 
	.byte	W24
	.byte		VOICE , 25
	.byte		N06   , Fn3 
	.byte	W48
	.byte	GOTO
	 .word	mus_syoujoeye_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_syoujoeye_6:
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte	W24
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte	W96
mus_syoujoeye_6_B1:
	.byte	W92
	.byte	W01
	.byte		VOICE , 73
	.byte		N03   , An5 , v048
	.byte	W03
	.byte		N12   , As5 
	.byte	W18
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W18
	.byte		N36   , Fn5 
	.byte	W14
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W16
	.byte		VOICE , 81
	.byte		N30   , Ds2 , v064
	.byte	W42
	.byte		N24   , Fs2 
	.byte	W30
	.byte		N18   , Ds2 
	.byte	W24
	.byte		N06   
	.byte	W21
	.byte		VOICE , 73
	.byte		N03   , An4 , v048
	.byte	W03
	.byte		N12   , As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte	W92
	.byte	W01
	.byte		N03   , An5 
	.byte	W03
	.byte		N12   , As5 
	.byte	W18
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        As5 
	.byte	W18
	.byte		N36   , Fn5 
	.byte	W14
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W16
	.byte		VOICE , 81
	.byte		N06   , Ds2 , v064
	.byte	W18
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W18
	.byte		N15   , Ds2 
	.byte	W24
	.byte		N06   , As2 
	.byte	W06
	.byte		N15   , Ds2 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W21
	.byte		VOICE , 73
	.byte		N03   , Gn5 , v048
	.byte	W03
	.byte		N12   , Gs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W48
	.byte	GOTO
	 .word	mus_syoujoeye_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_syoujoeye_7:
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte		PAN   , c_v+47
	.byte	W24
	.byte		VOICE , 127
	.byte		VOL   , 75*mus_syoujoeye_mvl/mxv
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		VOICE , 126
	.byte		N09   , Gs4 , v040
	.byte	W18
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v052
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gs4 , v040
	.byte	W24
mus_syoujoeye_7_B1:
mus_syoujoeye_7_000:
	.byte		VOICE , 127
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		N06   
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		VOICE , 126
	.byte		N12   , Gs4 , v040
	.byte	W24
	.byte		VOICE , 127
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		VOICE , 126
	.byte		N12   , Gs4 , v040
	.byte	W24
	.byte		VOICE , 127
	.byte		N12   , Gs4 , v052
	.byte	W72
	.byte		VOICE , 126
	.byte		N12   , Gs4 , v040
	.byte	W24
	.byte	PATT
	 .word	mus_syoujoeye_7_000
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		VOICE , 126
	.byte		N09   , Gs4 , v040
	.byte	W18
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v052
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		VOICE , 126
	.byte		N09   , Gs4 , v040
	.byte	W18
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v052
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		VOICE , 126
	.byte		N09   , Gs4 , v040
	.byte	W18
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v052
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_syoujoeye_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_syoujoeye_8:
	.byte	KEYSH , mus_syoujoeye_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_syoujoeye_mvl/mxv
	.byte	W24
	.byte	W66
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
mus_syoujoeye_8_B1:
mus_syoujoeye_8_000:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte	PEND
mus_syoujoeye_8_001:
	.byte		N06   , Cn1 , v120
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte	PEND
	.byte		N06   
	.byte	W24
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W30
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_syoujoeye_8_000
	.byte	PATT
	 .word	mus_syoujoeye_8_001
	.byte		N06   , Cn1 , v120
	.byte	W42
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		        En1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte	GOTO
	 .word	mus_syoujoeye_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_syoujoeye:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_syoujoeye_pri	@ Priority
	.byte	mus_syoujoeye_rev	@ Reverb.

	.word	mus_syoujoeye_grp

	.word	mus_syoujoeye_1
	.word	mus_syoujoeye_2
	.word	mus_syoujoeye_3
	.word	mus_syoujoeye_4
	.word	mus_syoujoeye_5
	.word	mus_syoujoeye_6
	.word	mus_syoujoeye_7
	.word	mus_syoujoeye_8

	.end
