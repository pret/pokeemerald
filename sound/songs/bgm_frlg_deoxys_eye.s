	.include "MPlayDef.s"

	.equ	bgm_frlg_deoxys_eye_grp, voicegroup_86B2244
	.equ	bgm_frlg_deoxys_eye_pri, 0
	.equ	bgm_frlg_deoxys_eye_rev, reverb_set+50
	.equ	bgm_frlg_deoxys_eye_mvl, 127
	.equ	bgm_frlg_deoxys_eye_key, 0
	.equ	bgm_frlg_deoxys_eye_tbs, 1
	.equ	bgm_frlg_deoxys_eye_exg, 0
	.equ	bgm_frlg_deoxys_eye_cmp, 1

	.section .rodata
	.global	bgm_frlg_deoxys_eye
	.align	2

@********************** Track  1 **********************@

bgm_frlg_deoxys_eye_1:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_1_B1:
	.byte	TEMPO , 128*bgm_frlg_deoxys_eye_tbs/2
	.byte		VOICE , 38
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_frlg_deoxys_eye_mvl/mxv
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
bgm_frlg_deoxys_eye_1_000:
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
	 .word	bgm_frlg_deoxys_eye_1_000
	.byte	PATT
	 .word	bgm_frlg_deoxys_eye_1_000
bgm_frlg_deoxys_eye_1_001:
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
	 .word	bgm_frlg_deoxys_eye_1_001
	.byte	PATT
	 .word	bgm_frlg_deoxys_eye_1_001
	.byte	PATT
	 .word	bgm_frlg_deoxys_eye_1_001
	.byte	GOTO
	 .word	bgm_frlg_deoxys_eye_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_deoxys_eye_2:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_2_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 76*bgm_frlg_deoxys_eye_mvl/mxv
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
bgm_frlg_deoxys_eye_2_000:
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
	 .word	bgm_frlg_deoxys_eye_2_000
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
	 .word	bgm_frlg_deoxys_eye_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_deoxys_eye_3:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_3_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 56*bgm_frlg_deoxys_eye_mvl/mxv
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
bgm_frlg_deoxys_eye_3_000:
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
	 .word	bgm_frlg_deoxys_eye_3_000
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
	 .word	bgm_frlg_deoxys_eye_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_deoxys_eye_4:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_4_B1:
	.byte		VOICE , 85
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 29*bgm_frlg_deoxys_eye_mvl/mxv
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
	 .word	bgm_frlg_deoxys_eye_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_deoxys_eye_5:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_5_B1:
	.byte		VOICE , 31
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		VOL   , 24*bgm_frlg_deoxys_eye_mvl/mxv
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
	.byte		VOL   , 65*bgm_frlg_deoxys_eye_mvl/mxv
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
	 .word	bgm_frlg_deoxys_eye_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_deoxys_eye_6:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_6_B1:
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*bgm_frlg_deoxys_eye_mvl/mxv
	.byte		N48   , Fn3 , v127
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        22*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_deoxys_eye_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 56*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        22*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_deoxys_eye_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W24
	.byte		VOL   , 62*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        55*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        50*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        39*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        24*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        18*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        13*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        8*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_deoxys_eye_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_deoxys_eye_7:
	.byte	KEYSH , bgm_frlg_deoxys_eye_key+0
bgm_frlg_deoxys_eye_7_B1:
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 56*bgm_frlg_deoxys_eye_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N48   , Fn3 , v064
	.byte	W24
	.byte		VOL   , 34*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        28*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        22*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		VOL   , 56*bgm_frlg_deoxys_eye_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 34*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        28*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        22*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		VOL   , 56*bgm_frlg_deoxys_eye_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W48
	.byte		VOL   , 38*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        22*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        17*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        11*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W06
	.byte		        5*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W12
	.byte		        0*bgm_frlg_deoxys_eye_mvl/mxv
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_deoxys_eye_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_deoxys_eye:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_deoxys_eye_pri	@ Priority
	.byte	bgm_frlg_deoxys_eye_rev	@ Reverb.

	.word	bgm_frlg_deoxys_eye_grp

	.word	bgm_frlg_deoxys_eye_1
	.word	bgm_frlg_deoxys_eye_2
	.word	bgm_frlg_deoxys_eye_3
	.word	bgm_frlg_deoxys_eye_4
	.word	bgm_frlg_deoxys_eye_5
	.word	bgm_frlg_deoxys_eye_6
	.word	bgm_frlg_deoxys_eye_7

	.end
