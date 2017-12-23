	.include "MPlayDef.s"

	.equ	se_rg_help_cl_grp, voicegroup_86A0154
	.equ	se_rg_help_cl_pri, 5
	.equ	se_rg_help_cl_rev, reverb_set+50
	.equ	se_rg_help_cl_mvl, 127
	.equ	se_rg_help_cl_key, 0
	.equ	se_rg_help_cl_tbs, 1
	.equ	se_rg_help_cl_exg, 0
	.equ	se_rg_help_cl_cmp, 1

	.section .rodata
	.global	se_rg_help_cl
	.align	2

@********************** Track  1 **********************@

se_rg_help_cl_1:
	.byte	KEYSH , se_rg_help_cl_key+0
	.byte	TEMPO , 420*se_rg_help_cl_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 95*se_rg_help_cl_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N04   , Dn5 , v092
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn5 , v032
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , An4 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , An4 , v032
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 , v092
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Fs4 , v032
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N04   , En4 , v092
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , En4 , v032
	.byte	W06
	.byte		PAN   , c_v-39
	.byte		N04   , Dn4 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn4 , v032
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn4 , v016
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn4 , v012
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn4 , v004
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

se_rg_help_cl:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_help_cl_pri	@ Priority
	.byte	se_rg_help_cl_rev	@ Reverb.

	.word	se_rg_help_cl_grp

	.word	se_rg_help_cl_1

	.end
