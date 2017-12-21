	.include "MPlayDef.s"

	.equ	bgm_fanfa1_grp, voicegroup_8677B28
	.equ	bgm_fanfa1_pri, 5
	.equ	bgm_fanfa1_rev, reverb_set+50
	.equ	bgm_fanfa1_mvl, 127
	.equ	bgm_fanfa1_key, 0
	.equ	bgm_fanfa1_tbs, 1
	.equ	bgm_fanfa1_exg, 0
	.equ	bgm_fanfa1_cmp, 1

	.section .rodata
	.global	bgm_fanfa1
	.align	2

@********************** Track  1 **********************@

bgm_fanfa1_1:
	.byte	KEYSH , bgm_fanfa1_key+0
	.byte	TEMPO , 174*bgm_fanfa1_tbs/2
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*bgm_fanfa1_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W08
	.byte		N04   , Bn3 , v100
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   , Gs4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W54
	.byte	FINE

@********************** Track  2 **********************@

bgm_fanfa1_2:
	.byte	KEYSH , bgm_fanfa1_key+0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*bgm_fanfa1_mvl/mxv
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N04   , En4 , v100
	.byte	W08
	.byte		PAN   , c_v+16
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N24   , Bn4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W54
	.byte	FINE

@********************** Track  3 **********************@

bgm_fanfa1_3:
	.byte	KEYSH , bgm_fanfa1_key+0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*bgm_fanfa1_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W08
	.byte		N04   , Gs3 , v068
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   , En4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W54
	.byte	FINE

@********************** Track  4 **********************@

bgm_fanfa1_4:
	.byte	KEYSH , bgm_fanfa1_key+0
	.byte		VOICE , 84
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*bgm_fanfa1_mvl/mxv
	.byte	W08
	.byte		N04   , Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		N24   , Gs4 , v048
	.byte	W10
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 71*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        48*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        25*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        10*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        0*bgm_fanfa1_mvl/mxv
	.byte	W36
	.byte	W03
	.byte	FINE

@********************** Track  5 **********************@

bgm_fanfa1_5:
	.byte	KEYSH , bgm_fanfa1_key+0
	.byte		VOICE , 85
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*bgm_fanfa1_mvl/mxv
	.byte	W08
	.byte		N04   , En4 , v048
	.byte	W04
	.byte		        En4 , v020
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        En4 , v020
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        En4 , v020
	.byte	W04
	.byte		N24   , Bn4 , v048
	.byte	W10
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 71*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        48*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        25*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        10*bgm_fanfa1_mvl/mxv
	.byte	W03
	.byte		        0*bgm_fanfa1_mvl/mxv
	.byte	W36
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

bgm_fanfa1:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_fanfa1_pri	@ Priority
	.byte	bgm_fanfa1_rev	@ Reverb.

	.word	bgm_fanfa1_grp

	.word	bgm_fanfa1_1
	.word	bgm_fanfa1_2
	.word	bgm_fanfa1_3
	.word	bgm_fanfa1_4
	.word	bgm_fanfa1_5

	.end
