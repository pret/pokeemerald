	.include "MPlayDef.s"

	.equ	bgm_frlg_healing_test_grp, voicegroup_86A41D4
	.equ	bgm_frlg_healing_test_pri, 0
	.equ	bgm_frlg_healing_test_rev, reverb_set+50
	.equ	bgm_frlg_healing_test_mvl, 127
	.equ	bgm_frlg_healing_test_key, 0
	.equ	bgm_frlg_healing_test_tbs, 1
	.equ	bgm_frlg_healing_test_exg, 0
	.equ	bgm_frlg_healing_test_cmp, 1

	.section .rodata
	.global	bgm_frlg_healing_test
	.align	2

@********************** Track  1 **********************@

bgm_frlg_healing_test_1:
	.byte		VOL   , 90*bgm_frlg_healing_test_mvl/mxv
	.byte	KEYSH , bgm_frlg_healing_test_key+0
	.byte	TEMPO , 146*bgm_frlg_healing_test_tbs/2
	.byte		VOICE , 2
	.byte		N24   , Bn4 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N48   , En5 
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_healing_test_2:
	.byte		VOL   , 90*bgm_frlg_healing_test_mvl/mxv
	.byte	KEYSH , bgm_frlg_healing_test_key+0
	.byte		VOICE , 3
	.byte		N12   , En2 , v092
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N36   , En2 
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_healing_test:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_healing_test_pri	@ Priority
	.byte	bgm_frlg_healing_test_rev	@ Reverb.

	.word	bgm_frlg_healing_test_grp

	.word	bgm_frlg_healing_test_1
	.word	bgm_frlg_healing_test_2

	.end
