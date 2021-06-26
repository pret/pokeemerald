	.align 2
voicegroup192:: @ 
	voice_directsound 60, 0, DirectSoundWaveData_dp_whistle_c5_16, 255, 247, 78, 196
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq25half, 1, 2, 6, 2   @ triple up of 070
	voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitmajor60, 255, 200, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitminor60, 255, 200, 255, 171
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq50half, 0, 7, 9, 1   @ triple up of 042 / 052
	voice_square_1_alt 60, 0, 0, 2, 0, 7, 9, 1      @ double up of 042 / 052
	voice_square_1_alt 60, 0, 0, 0, 0, 6, 6, 2       @ double up of 063
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq50oct, 0, 7, 2, 0   @ double up of 031 (oct lower)
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq50half, 0, 7, 2, 0   @ double up of 031
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq50oct, 0, 6, 6, 2   @ double up of 067 (oct lower)
	voice_square_1_alt 60, 0, 0, 2, 0, 7, 2, 0       @ double up of 031
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup227, KeySplitTable25    @ music box (platinum only)
	voice_keysplit voicegroup228, KeySplitTable34    @ banjo
	voice_directsound 60, 64, DirectSoundWaveData_dp_sne1_roop, 255, 255, 191, 1
	voice_directsound 60, 64, DirectSoundWaveData_dp_handclup1, 255, 0, 227, 1
	voice_directsound 60, 64, DirectSoundWaveData_dp_sne2_loop, 255, 255, 191, 1
	voice_directsound 48, 64, DirectSoundWaveData_dp_reverscyn_16, 2, 0, 255, 0
	voice_directsound 60, 64, DirectSoundWaveData_dp_bass2, 255, 0, 227, 1
	voice_directsound 60, 64, DirectSoundWaveData_dp_bassdr1, 255, 0, 227, 1
	voice_directsound 60, 64, DirectSoundWaveData_dp_808snare_16, 255, 220, 0, 2
	voice_directsound 60, 64, DirectSoundWaveData_dp_bassdr2_16, 255, 0, 255, 0
	voice_directsound 60, 64, DirectSoundWaveData_dp_bassdr1_16, 255, 0, 255, 171
	voice_directsound 61, 58, DirectSoundWaveData_dp_rim1_roop, 255, 220, 0, 0
	voice_directsound 60, 64, DirectSoundWaveData_dp_oct_snare_16, 255, 0, 255, 0
	voice_directsound 60, 70, DirectSoundWaveData_dp_053clap, 255, 0, 227, 1
	voice_directsound 60, 64, DirectSoundWaveData_dp_093snare, 255, 226, 127, 0
	voice_directsound 29, 30, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 1
	voice_directsound 60, 80, DirectSoundWaveData_dp_closed_hihat_16, 255, 0, 227, 1
	voice_directsound 34, 40, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 1
	voice_directsound 60, 80, DirectSoundWaveData_dp_pedalhight, 255, 0, 235, 0
	voice_directsound 41, 50, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 1
	voice_directsound 60, 80, DirectSoundWaveData_dp_open_hihat_16, 255, 241, 0, 0
	voice_directsound 47, 100, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 1
	voice_directsound 53, 107, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 1
	voice_directsound 57, 64, DirectSoundWaveData_dp_cymbal1_16, 255, 246, 0, 214
	voice_directsound 55, 117, DirectSoundWaveData_dp_tom1_16, 255, 0, 255, 0
	voice_directsound 58, 30, DirectSoundWaveData_dp_ridecynbal, 255, 250, 0, 216
	voice_directsound 59, 20, DirectSoundWaveData_dp_china_cynbal, 255, 250, 0, 226
	voice_directsound 60, 30, DirectSoundWaveData_dp_ridecap, 255, 250, 0, 232
	voice_directsound 60, 58, DirectSoundWaveData_dp_tambourine_16, 255, 0, 255, 1
	voice_directsound 60, 84, DirectSoundWaveData_trinity_cymbal_crash, 255, 250, 0, 226
	voice_directsound 60, 110, DirectSoundWaveData_dp_cawbell_16, 255, 0, 255, 176
	voice_directsound 60, 36, DirectSoundWaveData_dp_cymbal1_16, 255, 250, 0, 216
	voice_directsound 61, 102, DirectSoundWaveData_dp_cymbal1_16, 255, 250, 0, 216
	voice_directsound 60, 86, DirectSoundWaveData_dp_ridecynbal, 255, 250, 0, 216
	voice_directsound 60, 90, DirectSoundWaveData_dp_016bongo, 255, 0, 255, 176
	voice_directsound 57, 90, DirectSoundWaveData_dp_016bongo, 255, 0, 255, 176
