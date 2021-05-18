	.align 2
voicegroup192:: @ HGSS main
	voice_keysplit voicegroup193, KeySplitTable40    @ piano
	voice_keysplit voicegroup193, KeySplitTable41    @ piano 2
	voice_keysplit voicegroup193, KeySplitTable42    @ piano octave
	voice_keysplit voicegroup193, KeySplitTable43    @ rhodes 1
	voice_keysplit voicegroup193, KeySplitTable44    @ rhodes 2
	voice_keysplit voicegroup193, KeySplitTable45    @ vibraphone
	voice_keysplit voicegroup193, KeySplitTable46    @ marimba
	voice_keysplit voicegroup193, KeySplitTable47    @ xylophone
	voice_keysplit voicegroup193, KeySplitTable48    @ tubular bell
	voice_keysplit voicegroup193, KeySplitTable49    @ glockenspiel
	voice_keysplit voicegroup193, KeySplitTable50    @ music box
	voice_keysplit voicegroup193, KeySplitTable51    @ drawbar organ
	voice_keysplit voicegroup193, KeySplitTable52    @ jazz organ
	voice_keysplit voicegroup193, KeySplitTable53    @ accordion
	voice_keysplit voicegroup193, KeySplitTable54    @ nylon guitar
	voice_keysplit voicegroup193, KeySplitTable55    @ martin guitar
	voice_keysplit voicegroup193, KeySplitTable56    @ distortion guitar 1
	voice_keysplit voicegroup193, KeySplitTable57    @ distortion guitar 2
	voice_keysplit voicegroup193, KeySplitTable58    @ clean guitar
	voice_keysplit voicegroup007, KeySplitTable59    @ upright bass
	voice_keysplit voicegroup193, KeySplitTable60    @ fingered bass
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 192
	voice_keysplit voicegroup193, KeySplitTable61    @ synth bass
	voice_keysplit voicegroup193, KeySplitTable62    @ strings
	voice_keysplit voicegroup193, KeySplitTable63    @ violin
	voice_keysplit voicegroup193, KeySplitTable64    @ cello
	voice_keysplit voicegroup006, KeySplitTable65    @ pizzicato
	voice_keysplit voicegroup007, KeySplitTable66    @ harp
	voice_keysplit voicegroup006, KeySplitTable67    @ timpani
	voice_keysplit voicegroup006, KeySplitTable68    @ trumpets
	voice_keysplit voicegroup006, KeySplitTable69    @ trombones
	voice_keysplit voicegroup007, KeySplitTable70    @ french horn solo
	voice_keysplit voicegroup006, KeySplitTable71    @ french horns
	voice_keysplit voicegroup006, KeySplitTable72    @ oboe
	voice_keysplit voicegroup006, KeySplitTable73    @ clarinet
	voice_keysplit voicegroup193, KeySplitTable74    @ flute
	voice_keysplit voicegroup006, KeySplitTable75    @ bassoon
	voice_keysplit voicegroup006, KeySplitTable76    @ orchestra hit
	voice_keysplit voicegroup006, KeySplitTable77    @ square wave
	voice_keysplit_all voicegroup008				 @ drums
	voice_keysplit_all voicegroup009				 @ taiko drums
	voice_directsound 60, 0, DirectSoundWaveData_dp_woodbass_d3_16, 255, 251, 0, 171
	voice_keysplit voicegroup006, KeySplitTable78    @ koto
	voice_square_2_alt 60, 0, 2, 0, 2, 2, 1
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_wind, 67, 243, 155, 224
	voice_directsound 60, 0, DirectSoundWaveData_dp_explosion, 67, 255, 0, 245
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_square_wave, 255, 250, 0, 171 @ 1 octave too low
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_bubbles, 255, 0, 255, 0
	voice_square_2_alt 60, 0, 2, 0, 2, 2, 0 @  duplicated in BATTLE4 and DUNGEON4 as program 66
	voice_square_2_alt 60, 0, 2, 0, 7, 0, 0
	voice_square_2_alt 60, 0, 2, 0, 5, 0, 2
	voice_square_2_alt 60, 0, 2, 0, 2, 6, 2
	voice_square_2_alt 60, 0, 2, 0, 2, 6, 1
	voice_noise_alt 60, 0, 0, 1, 0, 3, 1
	voice_noise_alt 60, 0, 0, 0, 3, 0, 1
	voice_directsound 60, 0, DirectSoundWaveData_dp_whistle_c5_16, 255, 246, 78, 192
	voice_directsound 60, 0, DirectSoundWaveData_dp_reverscyn_16, 255, 0, 255, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_org5_c3_16, 255, 167, 235, 171
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq37half, 0, 2, 11, 1
	voice_square_2_alt 60, 0, 0, 0, 2, 11, 1 @ END OF BASIC BANK
	voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitmajor60, 255, 197, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitminor60, 255, 197, 255, 171
	voice_keysplit_all voicegroup007				 @ shift all D's up to D#
	voice_keysplit voicegroup193, KeySplitTable26    @ DPPt timpani
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass1_c2_16, 255, 1, 255, 192
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass2_c1_16, 255, 0, 255, 220
	voice_directsound 60, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 197, 255, 171
	voice_keysplit voicegroup006, KeySplitTable79    @ shamisen
	voice_directsound 60, 0, DirectSoundWaveData_hg_hyoshigi, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_hg_ecruteaklow, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_hg_tsuzumi, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_hg_jinglebell, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_hg_hoohclap, 255, 0, 255, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_tenorchoir48, 255, 197, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sopranochoir60, 255, 197, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_bw_031choirc5, 255, 197, 255, 171 @ 1 octave too low
	voice_directsound 60, 0, DirectSoundWaveData_dp_reverscyn_16, 255, 197, 255, 171 @ 1 octave too high
	voice_directsound 60, 0, DirectSoundWaveData_dp_spearpillarwind60, 255, 0, 255, 1
	voice_directsound 60, 0, DirectSoundWaveData_dp_altosax_c3_16, 255, 216, 252, 192
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171
	voice_keysplit voicegroup006, KeySplitTable80    @ piano (national park)
	voice_directsound 60, 0, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 1
	voice_keysplit voicegroup193, KeySplitTable29    @ dp trumpets (arceus)
	voice_keysplit voicegroup193, KeySplitTable30    @ dp trombone (arceus)
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 6, 2									 @ double up of 051
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 2, 0									 @ double up of 048
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq50half, 0, 2, 2, 0 @ triple up of 048 (half volume)
	voice_directsound 60, 0, DirectSoundWaveData_puresquare_50, 255, 242, 25, 0  @ 4x and up of 048
	voice_square_1_alt 60, 0, 0, 2, 0, 7, 0, 0									 @ double up of 049
	voice_square_1_alt 60, 0, 2, 0, 0, 2, 6, 1									 @ double up of 052

