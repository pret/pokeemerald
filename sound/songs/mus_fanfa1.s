	.include "MPlayDef.s"

	.equ	mus_fanfa1_grp, voicegroup012
	.equ	mus_fanfa1_pri, 5
	.equ	mus_fanfa1_rev, reverb_set+50
	.equ	mus_fanfa1_mvl, 127
	.equ	mus_fanfa1_key, 0
	.equ	mus_fanfa1_tbs, 1
	.equ	mus_fanfa1_exg, 0
	.equ	mus_fanfa1_cmp, 1

	.section .rodata
	.global	mus_fanfa1
	.align	2

@********************** Track  1 **********************@

mus_fanfa1_1:
	.byte	KEYSH , mus_fanfa1_key+0
	.byte	TEMPO , 174*mus_fanfa1_tbs/2
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_fanfa1_mvl/mxv
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

mus_fanfa1_2:
	.byte	KEYSH , mus_fanfa1_key+0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_fanfa1_mvl/mxv
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

mus_fanfa1_3:
	.byte	KEYSH , mus_fanfa1_key+0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_fanfa1_mvl/mxv
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

mus_fanfa1_4:
	.byte	KEYSH , mus_fanfa1_key+0
	.byte		VOICE , 84
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_fanfa1_mvl/mxv
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
	.byte		VOL   , 71*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        48*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        25*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        10*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        0*mus_fanfa1_mvl/mxv
	.byte	W36
	.byte	W03
	.byte	FINE

@********************** Track  5 **********************@

mus_fanfa1_5:
	.byte	KEYSH , mus_fanfa1_key+0
	.byte		VOICE , 85
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_fanfa1_mvl/mxv
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
	.byte		VOL   , 71*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        48*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        25*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        10*mus_fanfa1_mvl/mxv
	.byte	W03
	.byte		        0*mus_fanfa1_mvl/mxv
	.byte	W36
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

mus_fanfa1:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_fanfa1_pri	@ Priority
	.byte	mus_fanfa1_rev	@ Reverb.

	.word	mus_fanfa1_grp

	.word	mus_fanfa1_1
	.word	mus_fanfa1_2
	.word	mus_fanfa1_3
	.word	mus_fanfa1_4
	.word	mus_fanfa1_5

	.end
