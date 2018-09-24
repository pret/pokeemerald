	.include "MPlayDef.s"

	.equ	mus_rg_deoeye_grp, voicegroup184
	.equ	mus_rg_deoeye_pri, 0
	.equ	mus_rg_deoeye_rev, reverb_set+50
	.equ	mus_rg_deoeye_mvl, 127
	.equ	mus_rg_deoeye_key, 0
	.equ	mus_rg_deoeye_tbs, 1
	.equ	mus_rg_deoeye_exg, 0
	.equ	mus_rg_deoeye_cmp, 1

	.section .rodata
	.global	mus_rg_deoeye
	.align	2

@********************** Track  1 **********************@

mus_rg_deoeye_1:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_1_B1:
	.byte	TEMPO , 128*mus_rg_deoeye_tbs/2
	.byte		VOICE , 38
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_rg_deoeye_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 2
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
mus_rg_deoeye_1_000:
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_deoeye_1_000
	.byte	PATT
	 .word	mus_rg_deoeye_1_000
mus_rg_deoeye_1_001:
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v120
	.byte	W12
	.byte		        Ds1 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_deoeye_1_001
	.byte	PATT
	 .word	mus_rg_deoeye_1_001
	.byte	PATT
	 .word	mus_rg_deoeye_1_001
	.byte	GOTO
	 .word	mus_rg_deoeye_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_deoeye_2:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_2_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 76*mus_rg_deoeye_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+3
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-3
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , En1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En1 , v020
	.byte	W06
mus_rg_deoeye_2_000:
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N06   , Ds1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N06   , Ds1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte	PATT
	 .word	mus_rg_deoeye_2_000
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-2
	.byte		N06   , Ds1 , v120
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Ds1 , v020
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_deoeye_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_deoeye_3:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_3_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 56*mus_rg_deoeye_mvl/mxv
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		PAN   , c_v-61
	.byte		N01   , Fs5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W08
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W09
	.byte		PAN   , c_v-62
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W02
	.byte		        Dn5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W09
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N01   , Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W04
mus_rg_deoeye_3_000:
	.byte		PAN   , c_v-62
	.byte	W02
	.byte		N01   , Cs4 , v064
	.byte	W02
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W05
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W06
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W01
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v020
	.byte	W03
	.byte		PAN   , c_v-62
	.byte	W06
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		        Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W02
	.byte		        An4 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W07
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W09
	.byte	PEND
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W05
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Dn5 , v020
	.byte	W11
	.byte		PAN   , c_v-62
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W05
	.byte		N01   , Cs4 , v064
	.byte	W02
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W03
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Gn3 , v020
	.byte	W09
	.byte		        Gn4 , v064
	.byte	W02
	.byte		        Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W01
	.byte		PAN   , c_v-61
	.byte	W01
	.byte		N01   , An4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W07
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W07
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W07
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Cn5 
	.byte	W09
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W09
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W02
	.byte		        Dn5 , v020
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W01
	.byte		N01   , Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W05
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte		N01   , Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W09
	.byte		PAN   , c_v+63
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte		N01   , Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v020
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		        Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W02
	.byte		        An4 , v020
	.byte	W05
	.byte		PAN   , c_v-62
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		PAN   , c_v-61
	.byte		N01   , Fs5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W08
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W09
	.byte		PAN   , c_v-62
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W02
	.byte		        Dn5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W09
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N01   , Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W04
	.byte	PATT
	 .word	mus_rg_deoeye_3_000
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W05
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Dn5 , v020
	.byte	W11
	.byte		PAN   , c_v-62
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W05
	.byte		N01   , Cs4 , v064
	.byte	W02
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_deoeye_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_deoeye_4:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_4_B1:
	.byte		VOICE , 85
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 29*mus_rg_deoeye_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , En2 , v120
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		        c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v-1
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v-32
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v-5
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+32
	.byte		BEND  , c_v-7
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v-6
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v-32
	.byte		BEND  , c_v-5
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v-4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+32
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v-32
	.byte	W12
	.byte		        c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		        c_v+32
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v+4
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v-32
	.byte		BEND  , c_v+5
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v+7
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+32
	.byte		BEND  , c_v+10
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v+9
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v-32
	.byte		BEND  , c_v+7
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v+6
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+32
	.byte		BEND  , c_v+4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		MOD   , 2
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		MOD   , 4
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-16
	.byte	W12
	.byte		MOD   , 7
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		        c_v-16
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		MOD   , 9
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-16
	.byte	W12
	.byte		EOT   
	.byte	GOTO
	 .word	mus_rg_deoeye_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_deoeye_5:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_5_B1:
	.byte		VOICE , 31
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		VOL   , 24*mus_rg_deoeye_mvl/mxv
	.byte	W12
	.byte		TIE   , As3 , v080
	.byte	W06
	.byte	W24
	.byte		PAN   , c_v-16
	.byte	W24
	.byte		        c_v-32
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-26
	.byte	W02
	.byte		        c_v-32
	.byte	W02
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-40
	.byte	W02
	.byte		        c_v-44
	.byte	W02
	.byte		        c_v-47
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-54
	.byte	W02
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v-56
	.byte	W02
	.byte		        c_v-58
	.byte	W01
	.byte		        c_v-59
	.byte	W02
	.byte		        c_v-60
	.byte	W02
	.byte		        c_v-62
	.byte	W03
	.byte		        c_v-63
	.byte	W14
	.byte		PAN   , c_v-64
	.byte	W01
	.byte		BEND  , c_v-63
	.byte	W02
	.byte		        c_v-62
	.byte	W02
	.byte		        c_v-58
	.byte	W03
	.byte		        c_v-54
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-38
	.byte	W03
	.byte		        c_v-34
	.byte	W01
	.byte		        c_v-31
	.byte	W01
	.byte		        c_v-24
	.byte	W02
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-11
	.byte	W01
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v+7
	.byte	W02
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+26
	.byte	W02
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+49
	.byte	W02
	.byte		        c_v+53
	.byte	W01
	.byte		PAN   , c_v-33
	.byte	W01
	.byte		BEND  , c_v+59
	.byte	W01
	.byte		        c_v+63
	.byte	W04
	.byte		PAN   , c_v-16
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+31
	.byte	W06
	.byte		        c_v+48
	.byte	W06
	.byte		        c_v+63
	.byte	W19
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		        c_v+62
	.byte	W01
	.byte		        c_v+61
	.byte	W01
	.byte		        c_v+59
	.byte	W02
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+58
	.byte	W03
	.byte		        c_v+56
	.byte	W01
	.byte		        c_v+53
	.byte	W03
	.byte		        c_v+52
	.byte	W01
	.byte		        c_v+50
	.byte	W02
	.byte		        c_v+42
	.byte	W02
	.byte		PAN   , c_v+32
	.byte	W02
	.byte		BEND  , c_v+40
	.byte	W01
	.byte		        c_v+39
	.byte	W02
	.byte		        c_v+37
	.byte	W03
	.byte		        c_v+34
	.byte	W02
	.byte		        c_v+32
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+29
	.byte	W02
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+25
	.byte	W02
	.byte		        c_v+22
	.byte	W02
	.byte		        c_v+20
	.byte	W01
	.byte		        c_v+18
	.byte	W01
	.byte		        c_v+17
	.byte	W01
	.byte		        c_v+14
	.byte	W02
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v+10
	.byte	W02
	.byte		        c_v+8
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-20
	.byte	W01
	.byte		        c_v-24
	.byte	W02
	.byte		        c_v-26
	.byte	W01
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-32
	.byte	W01
	.byte		        c_v-35
	.byte	W02
	.byte		        c_v-43
	.byte	W02
	.byte		        c_v-44
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-58
	.byte	W02
	.byte		        c_v-60
	.byte	W18
	.byte		        c_v-63
	.byte	W01
	.byte		        c_v-62
	.byte	W01
	.byte		        c_v-58
	.byte	W02
	.byte		        c_v-55
	.byte	W02
	.byte		        c_v-52
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-37
	.byte	W02
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-26
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W07
	.byte		EOT   
	.byte		VOL   , 65*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W09
	.byte		N01   , Gs4 
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W05
	.byte		PAN   , c_v-64
	.byte		N01   , Gs4 , v080
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W20
	.byte		N02   , Cs5 , v088
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W14
	.byte		PAN   , c_v+63
	.byte	W09
	.byte		N02   , En4 , v080
	.byte	W04
	.byte		        En4 , v032
	.byte	W17
	.byte		PAN   , c_v-1
	.byte	W09
	.byte		N02   , Gn4 , v084
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W32
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		N02   , Dn5 , v080
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W20
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N02   , Gs4 , v084
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W08
	.byte	GOTO
	 .word	mus_rg_deoeye_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_deoeye_6:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_6_B1:
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*mus_rg_deoeye_mvl/mxv
	.byte		N48   , Fn3 , v127
	.byte	W24
	.byte		VOL   , 56*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        79*mus_rg_deoeye_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 56*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        79*mus_rg_deoeye_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W24
	.byte		VOL   , 62*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        39*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        24*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        18*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        13*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        8*mus_rg_deoeye_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_deoeye_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_deoeye_7:
	.byte	KEYSH , mus_rg_deoeye_key+0
mus_rg_deoeye_7_B1:
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 56*mus_rg_deoeye_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N48   , Fn3 , v064
	.byte	W24
	.byte		VOL   , 34*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		VOL   , 56*mus_rg_deoeye_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 34*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		VOL   , 56*mus_rg_deoeye_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W48
	.byte		VOL   , 38*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        17*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_deoeye_mvl/mxv
	.byte	W06
	.byte		        5*mus_rg_deoeye_mvl/mxv
	.byte	W12
	.byte		        0*mus_rg_deoeye_mvl/mxv
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_deoeye_7_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_deoeye:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_deoeye_pri	@ Priority
	.byte	mus_rg_deoeye_rev	@ Reverb.

	.word	mus_rg_deoeye_grp

	.word	mus_rg_deoeye_1
	.word	mus_rg_deoeye_2
	.word	mus_rg_deoeye_3
	.word	mus_rg_deoeye_4
	.word	mus_rg_deoeye_5
	.word	mus_rg_deoeye_6
	.word	mus_rg_deoeye_7

	.end
