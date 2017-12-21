	.include "MPlayDef.s"

	.equ	se_track_haik_grp, voicegroup_869D0F4
	.equ	se_track_haik_pri, 4
	.equ	se_track_haik_rev, reverb_set+50
	.equ	se_track_haik_mvl, 127
	.equ	se_track_haik_key, 0
	.equ	se_track_haik_tbs, 1
	.equ	se_track_haik_exg, 0
	.equ	se_track_haik_cmp, 1

	.section .rodata
	.global	se_track_haik
	.align	2

@********************** Track  1 **********************@

se_track_haik_1:
	.byte	KEYSH , se_track_haik_key+0
	.byte	TEMPO , 150*se_track_haik_tbs/2
	.byte		VOICE , 120
	.byte		VOL   , 127*se_track_haik_mvl/mxv
	.byte		N06   , Bn3 , v028
	.byte	W03
	.byte	W03
	.byte		N21   , Gs4 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_track_haik:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_track_haik_pri	@ Priority
	.byte	se_track_haik_rev	@ Reverb.

	.word	se_track_haik_grp

	.word	se_track_haik_1

	.end
