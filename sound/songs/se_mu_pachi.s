	.include "MPlayDef.s"

	.equ	se_mu_pachi_grp, voicegroup127
	.equ	se_mu_pachi_pri, 4
	.equ	se_mu_pachi_rev, reverb_set+50
	.equ	se_mu_pachi_mvl, 127
	.equ	se_mu_pachi_key, 0
	.equ	se_mu_pachi_tbs, 1
	.equ	se_mu_pachi_exg, 0
	.equ	se_mu_pachi_cmp, 1

	.section .rodata
	.global	se_mu_pachi
	.align	2

@********************** Track  1 **********************@

se_mu_pachi_1:
	.byte	KEYSH , se_mu_pachi_key+0
	.byte	TEMPO , 150*se_mu_pachi_tbs/2
	.byte		VOICE , 122
	.byte		VOL   , 100*se_mu_pachi_mvl/mxv
	.byte		N01   , Ds3 , v127
	.byte	W02
	.byte		VOICE , 126
	.byte		N01   , Gs4 
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        Gs4 , v088
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_mu_pachi:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_mu_pachi_pri	@ Priority
	.byte	se_mu_pachi_rev	@ Reverb.

	.word	se_mu_pachi_grp

	.word	se_mu_pachi_1

	.end
