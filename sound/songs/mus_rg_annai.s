	.include "MPlayDef.s"

	.equ	mus_rg_annai_grp, voicegroup131
	.equ	mus_rg_annai_pri, 0
	.equ	mus_rg_annai_rev, reverb_set+50
	.equ	mus_rg_annai_mvl, 127
	.equ	mus_rg_annai_key, 0
	.equ	mus_rg_annai_tbs, 1
	.equ	mus_rg_annai_exg, 0
	.equ	mus_rg_annai_cmp, 1

	.section .rodata
	.global	mus_rg_annai
	.align	2

@********************** Track  1 **********************@

mus_rg_annai_1:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte	TEMPO , 146*mus_rg_annai_tbs/2
	.byte		VOICE , 24
	.byte		PAN   , c_v+32
	.byte		VOL   , 45*mus_rg_annai_mvl/mxv
	.byte		N06   , Bn3 , v127
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N60   , Bn3 
	.byte	W48
mus_rg_annai_1_000:
	.byte	W12
	.byte		N03   , En3 , v127
	.byte	W12
	.byte		N03   
	.byte	W36
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	PEND
mus_rg_annai_1_001:
	.byte	W12
	.byte		N03   , En3 , v127
	.byte	W12
	.byte		N03   
	.byte	W36
	.byte		        Dn3 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_annai_1_000
mus_rg_annai_1_002:
	.byte	W12
	.byte		N03   , En3 , v127
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	PEND
mus_rg_annai_1_B1:
	.byte	PATT
	 .word	mus_rg_annai_1_000
	.byte	PATT
	 .word	mus_rg_annai_1_001
	.byte	PATT
	 .word	mus_rg_annai_1_000
	.byte	PATT
	 .word	mus_rg_annai_1_002
	.byte	GOTO
	 .word	mus_rg_annai_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_annai_2:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 2
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*mus_rg_annai_mvl/mxv
	.byte		N06   , En6 , v127
	.byte	W12
	.byte		        Dn6 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        Dn6 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        En5 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        En6 
	.byte	W48
	.byte		        An5 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        En6 
	.byte	W24
	.byte		        Dn6 
	.byte	W12
	.byte		        Fs6 
	.byte	W12
	.byte		        An6 
	.byte	W24
	.byte		        An5 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        En6 
	.byte	W24
	.byte		        Dn6 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        Bn5 
	.byte	W24
	.byte		        An5 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        En6 
	.byte	W24
	.byte		        Dn6 
	.byte	W12
	.byte		        Fs6 
	.byte	W12
	.byte		        An6 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs6 
	.byte	W12
	.byte		        En6 
	.byte	W12
	.byte		        Fs6 
	.byte	W12
	.byte		        Gs6 
	.byte	W12
	.byte		        An6 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
mus_rg_annai_2_B1:
mus_rg_annai_2_000:
	.byte		N12   , An5 , v127
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		N18   , En6 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn6 
	.byte	W12
	.byte		        Fs6 
	.byte	W12
	.byte		N18   , An6 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		N12   , An5 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		N24   , En6 
	.byte	W24
	.byte		N06   , Dn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N06   , Gs5 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_annai_2_000
	.byte		N12   , Gs6 , v127
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		N12   , An6 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_annai_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_annai_3:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 39*mus_rg_annai_mvl/mxv
	.byte	W96
	.byte		N06   , En3 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W48
mus_rg_annai_3_000:
	.byte	W12
	.byte		N06   , An3 , v127
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	mus_rg_annai_3_000
	.byte	W12
	.byte		N06   , Bn3 , v127
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W24
mus_rg_annai_3_B1:
	.byte		N03   , Cs5 , v096
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Fs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        En5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Cs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Fs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_annai_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_annai_4:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 68*mus_rg_annai_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		N24   , En3 , v084
	.byte	W24
	.byte		N03   , Ds3 , v060
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N12   , An1 , v120
	.byte	W48
	.byte		        En1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W72
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N12   , An1 
	.byte	W48
	.byte		        Dn2 
	.byte	W24
	.byte		N06   , An1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
mus_rg_annai_4_B1:
	.byte		N06   , Cs2 , v120
	.byte	W12
	.byte		        An1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_annai_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_annai_5:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+62
	.byte		VOL   , 32*mus_rg_annai_mvl/mxv
	.byte		N06   , En4 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N03   , En3 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W48
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
mus_rg_annai_5_B1:
mus_rg_annai_5_000:
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_annai_5_000
	.byte		N03   , Gs4 , v127
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_annai_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_annai_6:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_rg_annai_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte		N06   , En3 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W48
mus_rg_annai_6_000:
	.byte	W12
	.byte		N06   , An3 , v127
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	mus_rg_annai_6_000
	.byte	W12
	.byte		N06   , Bn3 , v127
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W24
mus_rg_annai_6_B1:
	.byte		N03   , Cs5 , v096
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Fs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        En5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Cs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Fs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_annai_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_annai_7:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*mus_rg_annai_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
mus_rg_annai_7_B1:
	.byte		N12   , En1 , v127
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , En1 , v127
	.byte	W18
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , En1 , v127
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , En1 , v127
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , En1 , v127
	.byte	W18
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , En1 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_annai_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_annai_8:
	.byte	KEYSH , mus_rg_annai_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_rg_annai_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Cn5 , v127
	.byte	W03
	.byte		        Cn5 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
mus_rg_annai_8_B1:
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cn5 , v127
	.byte	W18
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn5 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cn5 , v127
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn5 , v127
	.byte	W06
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn5 , v127
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn5 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cn5 , v127
	.byte	W18
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , Cn5 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_annai_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_annai:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_annai_pri	@ Priority
	.byte	mus_rg_annai_rev	@ Reverb.

	.word	mus_rg_annai_grp

	.word	mus_rg_annai_1
	.word	mus_rg_annai_2
	.word	mus_rg_annai_3
	.word	mus_rg_annai_4
	.word	mus_rg_annai_5
	.word	mus_rg_annai_6
	.word	mus_rg_annai_7
	.word	mus_rg_annai_8

	.end
