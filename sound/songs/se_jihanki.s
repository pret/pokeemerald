	.include "MPlayDef.s"

	.equ	se_jihanki_grp, voicegroup_869D6F4
	.equ	se_jihanki_pri, 4
	.equ	se_jihanki_rev, reverb_set+50
	.equ	se_jihanki_mvl, 127
	.equ	se_jihanki_key, 0
	.equ	se_jihanki_tbs, 1
	.equ	se_jihanki_exg, 0
	.equ	se_jihanki_cmp, 1

	.section .rodata
	.global	se_jihanki
	.align	2

@********************** Track  1 **********************@

se_jihanki_1:
	.byte	KEYSH , se_jihanki_key+0
	.byte	TEMPO , 150*se_jihanki_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 110*se_jihanki_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn4 , v092
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte	W03
	.byte		N02   , En3 , v127
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_jihanki:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_jihanki_pri	@ Priority
	.byte	se_jihanki_rev	@ Reverb.

	.word	se_jihanki_grp

	.word	se_jihanki_1

	.end
