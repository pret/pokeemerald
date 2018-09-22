	.include "MPlayDef.s"

	.equ	mus_minamo_grp, voicegroup054
	.equ	mus_minamo_pri, 0
	.equ	mus_minamo_rev, reverb_set+50
	.equ	mus_minamo_mvl, 127
	.equ	mus_minamo_key, 0
	.equ	mus_minamo_tbs, 1
	.equ	mus_minamo_exg, 0
	.equ	mus_minamo_cmp, 1

	.section .rodata
	.global	mus_minamo
	.align	2

@********************** Track  1 **********************@

mus_minamo_1:
	.byte	KEYSH , mus_minamo_key+0
mus_minamo_1_B1:
	.byte	TEMPO , 80*mus_minamo_tbs/2
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		PAN   , c_v-44
	.byte		VOL   , 58*mus_minamo_mvl/mxv
	.byte	W24
	.byte	TEMPO , 92*mus_minamo_tbs/2
	.byte	W72
	.byte	W48
	.byte	TEMPO , 80*mus_minamo_tbs/2
	.byte	W36
	.byte	TEMPO , 92*mus_minamo_tbs/2
	.byte	W12
	.byte	W96
	.byte	W48
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v036
	.byte	W03
	.byte		        En4 , v112
	.byte	W03
	.byte		N06   , En4 , v036
	.byte	W21
	.byte	W24
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v036
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v036
	.byte	W21
	.byte		VOICE , 73
	.byte	W12
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Fs4 , v036
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v036
	.byte	W03
	.byte		        En4 , v112
	.byte	W03
	.byte		        En4 , v036
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v036
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		N06   , Cs4 , v036
	.byte	W15
	.byte		        Gs3 , v112
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N15   , Ds4 
	.byte	W15
	.byte		N06   , Ds4 , v036
	.byte	W09
	.byte		        Gs4 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W03
	.byte		N21   , Gs4 
	.byte	W09
	.byte		MOD   , 7
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        En4 , v036
	.byte	W24
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , As3 , v036
	.byte	W24
	.byte		N12   , Fs3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		N44   , Ds4 
	.byte	W21
	.byte		VOL   , 52*mus_minamo_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 48*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        42*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        40*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        36*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        34*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        31*mus_minamo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		N06   , Ds4 , v036
	.byte	W24
	.byte	W96
	.byte	W48
	.byte	TEMPO , 76*mus_minamo_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 53*mus_minamo_mvl/mxv
	.byte		N12   , Cs3 , v112
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W09
	.byte	TEMPO , 86*mus_minamo_tbs/2
	.byte	W03
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	TEMPO , 92*mus_minamo_tbs/2
	.byte		VOL   , 56*mus_minamo_mvl/mxv
	.byte		N02   , Fs3 
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		        As4 
	.byte	W02
	.byte		N12   , Cs5 
	.byte	W12
	.byte		VOICE , 73
	.byte		N06   , Cs5 , v036
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		VOICE , 73
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v036
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v036
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v036
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W12
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		N03   , Fn5 , v112
	.byte	W03
	.byte		N06   , Fn5 , v036
	.byte	W09
	.byte		N03   , Fn5 , v112
	.byte	W03
	.byte		N06   , Fn5 , v036
	.byte	W09
	.byte		VOICE , 48
	.byte		VOL   , 42*mus_minamo_mvl/mxv
	.byte	W09
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v036
	.byte	W06
	.byte		N24   , Fs3 , v112
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N06   , Fs3 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		        As2 
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v036
	.byte	W06
	.byte		N24   , En3 , v112
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , An2 , v112
	.byte	W03
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v036
	.byte	W03
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte	TEMPO , 88*mus_minamo_tbs/2
	.byte		N30   , Ds3 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte	TEMPO , 86*mus_minamo_tbs/2
	.byte		        0
	.byte	W06
	.byte		N06   , Ds3 , v036
	.byte	W06
	.byte	TEMPO , 74*mus_minamo_tbs/2
	.byte		N12   , Fs3 , v112
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte	TEMPO , 92*mus_minamo_tbs/2
	.byte		VOICE , 60
	.byte		N36   , Bn3 
	.byte	W24
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N30   , Gs4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	TEMPO , 90*mus_minamo_tbs/2
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N03   , En4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte	TEMPO , 74*mus_minamo_tbs/2
	.byte		        Cn4 
	.byte	W12
	.byte	TEMPO , 68*mus_minamo_tbs/2
	.byte		        Bn3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_minamo_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_minamo_2:
	.byte	KEYSH , mus_minamo_key+0
mus_minamo_2_B1:
	.byte		VOICE , 48
	.byte		VOL   , 85*mus_minamo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		        Fn2 , v112
	.byte	W03
	.byte		        Fn2 , v036
	.byte	W03
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		        Fn2 , v112
	.byte	W03
	.byte		        Fn2 , v036
	.byte	W03
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		        Fn2 , v112
	.byte	W03
	.byte		        Fn2 , v036
	.byte	W03
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v036
	.byte	W06
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        Cs3 , v036
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W03
	.byte		        Cn3 , v036
	.byte	W03
	.byte		N12   , Cs3 , v112
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		N12   , Ds3 , v112
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W03
	.byte		N06   , Fn2 , v036
	.byte	W09
	.byte		N03   , Fn2 , v112
	.byte	W03
	.byte		N06   , Fn2 , v036
	.byte	W09
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v036
	.byte	W03
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N12   , Cs2 , v112
	.byte	W12
mus_minamo_2_000:
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte	PEND
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_minamo_2_000
	.byte		VOICE , 58
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W09
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W09
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N03   , An2 
	.byte	W03
	.byte		        An2 , v036
	.byte	W03
	.byte		N06   , Gs2 , v112
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W09
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        Gn2 , v036
	.byte	W03
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W03
	.byte		N06   , Gn2 , v036
	.byte	W09
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v036
	.byte	W09
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		VOICE , 48
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gn1 , v120
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 , v124
	.byte	W06
	.byte	GOTO
	 .word	mus_minamo_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_minamo_3:
	.byte	KEYSH , mus_minamo_key+0
mus_minamo_3_B1:
	.byte		VOICE , 45
	.byte		PAN   , c_v+44
	.byte		VOL   , 56*mus_minamo_mvl/mxv
	.byte	W09
	.byte		N03   , Gn3 , v064
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Fs3 , v032
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W21
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W09
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W18
	.byte		N03   , Gn3 , v064
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Fs3 , v032
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W21
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W09
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v032
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , An3 , v064
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v032
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		N06   , Gs3 , v032
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W18
	.byte		N03   , Gs3 , v064
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W03
mus_minamo_3_000:
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		N06   , Gn3 , v032
	.byte	W12
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W18
	.byte		N03   , Gn3 , v064
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W03
	.byte		        Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N12   , Fs3 , v112
	.byte	W12
	.byte		N06   , Fs3 , v032
	.byte	W12
	.byte	PEND
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W18
	.byte		N03   , Cs4 , v064
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v032
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte		N06   , Cn4 , v032
	.byte	W12
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		N06   , Cn4 , v032
	.byte	W09
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		N06   , Cn4 , v032
	.byte	W09
	.byte		VOICE , 48
	.byte		VOL   , 42*mus_minamo_mvl/mxv
	.byte	W09
	.byte		N03   , An3 , v064
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v032
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		N06   , Gs3 , v032
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W18
	.byte		N03   , Gs3 , v064
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W03
	.byte	PATT
	 .word	mus_minamo_3_000
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W18
	.byte		N03   , Bn3 , v064
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v032
	.byte	W03
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		N06   , As3 , v032
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		VOICE , 45
	.byte		VOL   , 56*mus_minamo_mvl/mxv
	.byte	W09
	.byte		N03   , Gn3 , v064
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W03
	.byte		        Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W21
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W21
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v032
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W15
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		VOICE , 48
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v032
	.byte	W12
	.byte		N03   , Fn4 , v112
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		VOICE , 48
	.byte		N06   , As3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v064
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Fs3 , v032
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v032
	.byte	W21
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		N06   , Cn4 , v032
	.byte	W09
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		N06   , Cn4 , v032
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v032
	.byte	W12
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		VOICE , 45
	.byte		N03   , Fs5 , v112
	.byte	W03
	.byte		N06   , Fs5 , v032
	.byte	W09
	.byte		N03   , Fs5 , v112
	.byte	W03
	.byte		N06   , Fs5 , v032
	.byte	W09
	.byte	W12
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W21
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		N06   , Cs4 , v032
	.byte	W09
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		N06   , Cs4 , v032
	.byte	W21
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W21
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v032
	.byte	W12
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W09
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W21
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		        An3 , v032
	.byte	W03
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOICE , 48
	.byte		N06   , Ds4 , v032
	.byte	W12
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W21
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		N06   , Cs4 , v032
	.byte	W09
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		N06   , Cs4 , v032
	.byte	W21
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v032
	.byte	W03
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W21
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W21
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte	GOTO
	 .word	mus_minamo_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_minamo_4:
	.byte	KEYSH , mus_minamo_key+0
mus_minamo_4_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 8*mus_minamo_mvl/mxv
	.byte		TIE   , Fs4 , v112
	.byte	W02
	.byte		VOL   , 9*mus_minamo_mvl/mxv
	.byte	W12
	.byte		        10*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        14*mus_minamo_mvl/mxv
	.byte	W07
	.byte		        18*mus_minamo_mvl/mxv
	.byte	W05
	.byte		        20*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        21*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        23*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        24*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        26*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        29*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        30*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        32*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        34*mus_minamo_mvl/mxv
	.byte	W07
	.byte		        35*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        36*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        38*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        41*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        42*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        44*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        48*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        51*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        52*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        56*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        58*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        59*mus_minamo_mvl/mxv
	.byte	W04
	.byte	W02
	.byte		        62*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        62*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        59*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        58*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        54*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        51*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        49*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        48*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        44*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        41*mus_minamo_mvl/mxv
	.byte	W01
	.byte		EOT   
	.byte		N06   , En4 
	.byte	W02
	.byte		VOL   , 40*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        38*mus_minamo_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W02
	.byte		VOL   , 35*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        34*mus_minamo_mvl/mxv
	.byte	W01
	.byte		N06   , En4 
	.byte	W02
	.byte		VOL   , 32*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        29*mus_minamo_mvl/mxv
	.byte		TIE   , Fs4 
	.byte	W02
	.byte		VOL   , 24*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        23*mus_minamo_mvl/mxv
	.byte	W09
	.byte		        21*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        20*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        21*mus_minamo_mvl/mxv
	.byte	W06
	.byte		        20*mus_minamo_mvl/mxv
	.byte	W15
	.byte		        26*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        29*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        30*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        32*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        34*mus_minamo_mvl/mxv
	.byte	W07
	.byte		        35*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        36*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        38*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        41*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        42*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        44*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        48*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        51*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        52*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        56*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        58*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        59*mus_minamo_mvl/mxv
	.byte	W06
	.byte		        62*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        62*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        59*mus_minamo_mvl/mxv
	.byte	W01
	.byte		        68*mus_minamo_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N15   , Ds4 
	.byte	W15
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Cn4 , v076
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		N06   , Bn3 , v036
	.byte	W24
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N15   , Ds4 
	.byte	W15
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Cn4 , v076
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		N06   , Bn3 , v036
	.byte	W24
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N24   , As3 
	.byte	W24
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		VOL   , 61*mus_minamo_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W03
	.byte		VOL   , 62*mus_minamo_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W02
	.byte		VOL   , 63*mus_minamo_mvl/mxv
	.byte	W01
	.byte		        68*mus_minamo_mvl/mxv
	.byte	W09
	.byte	W12
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		VOL   , 34*mus_minamo_mvl/mxv
	.byte		N48   , Ds4 
	.byte	W02
	.byte		VOL   , 39*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        44*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        50*mus_minamo_mvl/mxv
	.byte	W04
	.byte		        53*mus_minamo_mvl/mxv
	.byte	W02
	.byte		        57*mus_minamo_mvl/mxv
	.byte	W03
	.byte		        61*mus_minamo_mvl/mxv
	.byte	W01
	.byte		        68*mus_minamo_mvl/mxv
	.byte	W30
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N15   , Ds4 
	.byte	W15
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Cn4 , v076
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		N06   , Bn3 , v036
	.byte	W24
	.byte		        As3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N15   , Ds4 
	.byte	W15
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Cn4 , v076
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		N06   , Bn3 , v036
	.byte	W24
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , As3 , v036
	.byte	W24
	.byte		N12   , Fs3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N06   , Ds4 , v036
	.byte	W24
	.byte		VOICE , 45
	.byte		VOL   , 76*mus_minamo_mvl/mxv
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v036
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v036
	.byte	W06
	.byte		        Cs5 , v104
	.byte	W06
	.byte		        Cs5 , v036
	.byte	W06
	.byte		        As4 , v104
	.byte	W06
	.byte		        As4 , v036
	.byte	W06
	.byte		        Gs4 , v112
	.byte	W06
	.byte		        Gs4 , v036
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v036
	.byte	W06
	.byte		        Gs4 , v112
	.byte	W06
	.byte		        Gs4 , v036
	.byte	W06
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v036
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v036
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 65*mus_minamo_mvl/mxv
	.byte		N12   , Cs4 , v112
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs5 , v036
	.byte	W12
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs5 , v036
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs5 , v036
	.byte	W12
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        En5 , v036
	.byte	W06
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte		N06   , Fs4 , v036
	.byte	W09
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v036
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N30   , Gs4 
	.byte	W30
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N30   , As3 
	.byte	W30
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N30   , Fs4 
	.byte	W24
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N30   , En4 
	.byte	W30
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W36
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Fs5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N30   , En5 
	.byte	W30
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v036
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v036
	.byte	W06
	.byte		N48   , Bn4 , v112
	.byte	W48
	.byte		N12   , An4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	GOTO
	 .word	mus_minamo_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_minamo_5:
	.byte	KEYSH , mus_minamo_key+0
mus_minamo_5_B1:
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*mus_minamo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
mus_minamo_5_000:
	.byte	W09
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs3 , v036
	.byte	W06
	.byte		N24   , En3 , v112
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte	PEND
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs3 , v036
	.byte	W06
	.byte		N24   , En3 , v112
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N06   , En3 , v036
	.byte	W48
	.byte	W96
	.byte	PATT
	 .word	mus_minamo_5_000
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs3 , v036
	.byte	W06
	.byte		N24   , En3 , v112
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N06   , En3 , v036
	.byte	W36
	.byte		N12   , As2 , v112
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N48   , Fs3 
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N06   , Fs3 , v036
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N36   , Bn2 , v112
	.byte	W24
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N30   , Gs3 
	.byte	W15
	.byte		MOD   , 9
	.byte	W15
	.byte		        0
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn2 , v036
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte	GOTO
	 .word	mus_minamo_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_minamo_6:
	.byte	KEYSH , mus_minamo_key+0
mus_minamo_6_B1:
	.byte		VOICE , 45
	.byte		PAN   , c_v-33
	.byte		VOL   , 66*mus_minamo_mvl/mxv
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		N12   , Ds3 , v112
	.byte	W12
	.byte		N06   , Ds3 , v036
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		N12   , Ds3 , v112
	.byte	W12
	.byte		N06   , Ds3 , v036
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 42*mus_minamo_mvl/mxv
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		N06   , En3 , v036
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W21
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
mus_minamo_6_000:
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		N06   , En3 , v036
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		N12   , Ds3 , v112
	.byte	W12
	.byte		N06   , Ds3 , v036
	.byte	W12
	.byte	PEND
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v036
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v036
	.byte	W03
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		N06   , Gs3 , v036
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W09
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		N06   , En3 , v036
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W21
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte	PATT
	 .word	mus_minamo_6_000
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N12   , Ds3 , v112
	.byte	W12
	.byte		N06   , Ds3 , v036
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v036
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v036
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v036
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v036
	.byte	W15
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W21
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W09
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v036
	.byte	W21
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		N06   , Fn3 , v036
	.byte	W09
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		N06   , Fn3 , v036
	.byte	W80
	.byte	W01
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v036
	.byte	W03
	.byte		N12   , Ds3 , v112
	.byte	W12
	.byte		N06   , Ds3 , v036
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W21
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W56
	.byte	W01
	.byte	W96
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v036
	.byte	W03
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v036
	.byte	W09
mus_minamo_6_001:
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v036
	.byte	W21
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v036
	.byte	W03
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W21
	.byte	PEND
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        As3 , v036
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N06   , Ds3 , v036
	.byte	W21
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v036
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        An3 , v036
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v036
	.byte	W21
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v036
	.byte	W03
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W03
	.byte		N06   , Fs3 , v036
	.byte	W09
	.byte	PATT
	 .word	mus_minamo_6_001
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v036
	.byte	W03
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gn3 , v036
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W21
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , En3 , v036
	.byte	W09
	.byte	GOTO
	 .word	mus_minamo_6_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_minamo:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_minamo_pri	@ Priority
	.byte	mus_minamo_rev	@ Reverb.

	.word	mus_minamo_grp

	.word	mus_minamo_1
	.word	mus_minamo_2
	.word	mus_minamo_3
	.word	mus_minamo_4
	.word	mus_minamo_5
	.word	mus_minamo_6

	.end
