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
