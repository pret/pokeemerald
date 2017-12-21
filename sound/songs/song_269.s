	.include "MPlayDef.s"

	.equ	song_269_grp, voicegroup_86A0154
	.equ	song_269_pri, 5
	.equ	song_269_rev, reverb_set+50
	.equ	song_269_mvl, 127
	.equ	song_269_key, 0
	.equ	song_269_tbs, 1
	.equ	song_269_exg, 0
	.equ	song_269_cmp, 1

	.section .rodata
	.global	song_269
	.align	2

@********************** Track  1 **********************@

song_269_1:
	.byte	KEYSH , song_269_key+0
	.byte	TEMPO , 100*song_269_tbs/2
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 77*song_269_mvl/mxv
	.byte		N03   , Cn5 , v096
	.byte	W06
	.byte		N01   , Gn5 , v064
	.byte	W06
	.byte		N03   , Cn5 , v100
	.byte	W06
	.byte		N01   , Gn5 , v064
	.byte	W06
song_269_1_000:
	.byte		N03   , Cn5 , v096
	.byte	W06
	.byte		N01   , Gn5 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	song_269_1_000
	.byte	FINE

@******************************************************@
	.align	2

song_269:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_269_pri	@ Priority
	.byte	song_269_rev	@ Reverb.

	.word	song_269_grp

	.word	song_269_1

	.end
