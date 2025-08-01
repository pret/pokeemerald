	.macro song label:req, music_player:req, unknown:req
	.4byte \label
	.2byte \music_player
	.2byte \unknown
	.endm

	.macro music_player info_struct:req, track_struct:req, num_tracks:req, unknown:req
	.4byte \info_struct
	.4byte \track_struct
	.byte \num_tracks
	.space 1  @ Padding
	.2byte \unknown
	.endm

	.macro voice_group label:req, starting_note
	.align 2
	.ifb \starting_note
		.global voicegroup_\label 
		voicegroup_\label:
	.else
		.set voicegroup_\label, . - \starting_note * 0xC
	.endif
	.endm

	.macro keysplit label:req, starting_note
	.ifb \starting_note
		.global keysplit_\label
		keysplit_\label:
		.set _last_note, 0
	.else
		.set keysplit_\label, . - \starting_note
		.set _last_note, \starting_note
	.endif
	.set _last_split, 0
	.endm

	.macro split index:req, ending_note:req
	.if \ending_note < _last_note
		.if _last_split == 0
			.error "split's ending_note earlier than previous keysplit's starting_note"
		.else
			.error "split's ending_note earlier than previous split's ending_note"
		.endif
	.else
	.rept \ending_note - _last_note
	  .byte \index
	.endr
	.endif
	.set _last_note, \ending_note
	.set _last_split, 1
	.endm
