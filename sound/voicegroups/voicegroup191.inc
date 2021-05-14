	.align 2
voicegroup191:: @ DPPt main
	voice_directsound 60, 0, DirectSoundWaveData_dp_reverscyn_16, 255, 0, 255, 0
	voice_keysplit_all voicegroup005				 @ drums 1
	voice_keysplit voicegroup005, KeySplitTable6     @ piano
	voice_keysplit voicegroup005, KeySplitTable7     @ piano low
	voice_keysplit voicegroup005, KeySplitTable8     @ ep 1
	voice_keysplit voicegroup005, KeySplitTable9     @ ep 2
	voice_keysplit_all voicegroup006				 @ drums 2
	voice_keysplit voicegroup005, KeySplitTable10    @ clavi
	voice_noise_alt 60, 0, 0, 1, 0, 3, 1
	voice_directsound 60, 0, DirectSoundWaveData_dp_glocken_c6_16, 255, 247, 0, 208
	voice_square_1_alt 60, 0, 0, 1, 1, 2, 6, 2         @ double up of 070
	voice_keysplit voicegroup005, KeySplitTable11    @ vibraphone
	voice_keysplit voicegroup005, KeySplitTable12    @ marimba
	voice_keysplit voicegroup005, KeySplitTable13    @ xylophone
	voice_keysplit voicegroup005, KeySplitTable14    @ tubular bell
	voice_keysplit voicegroup193, KeySplitTable38    @ trinity piano
	voice_keysplit_all voicegroup007				 @ synth kick + snare
	voice_keysplit voicegroup005, KeySplitTable15    @ rotary organ
	voice_keysplit voicegroup005, KeySplitTable16    @ straight organ
	voice_directsound 60, 0, DirectSoundWaveData_dp_org5_c3_16, 255, 175, 235, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 200, 255, 171
	voice_keysplit voicegroup005, KeySplitTable17    @ accordion
	voice_directsound 60, 0, DirectSoundWaveData_dp_harmonica_c3_16, 67, 247, 191, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_fretnoise60, 255, 0, 255, 0
	voice_keysplit voicegroup005, KeySplitTable18    @ acoustic guitar
	voice_directsound 60, 0, DirectSoundWaveData_dp_bluesgt_a2_16, 255, 255, 227, 208
	voice_directsound 60, 0, DirectSoundWaveData_dp_eternaguitar36, 255, 253, 159, 208
	voice_keysplit voicegroup005, KeySplitTable19    @ clean guitar
	voice_directsound 60, 0, DirectSoundWaveData_dp_spearpillarwind60, 255, 0, 255, 1
	voice_keysplit voicegroup005, KeySplitTable20    @ distortion guitar 1
	voice_keysplit voicegroup005, KeySplitTable21    @ power guitar
	voice_square_2_alt 60, 0, 2, 0, 7, 2, 0
	voice_keysplit voicegroup005, KeySplitTable22    @ upright bass 1
	voice_directsound 60, 0, DirectSoundWaveData_dp_sting_bass_e1_16, 255, 251, 0, 208
	voice_directsound 60, 0, DirectSoundWaveData_dp_pickbass_e1_16, 255, 251, 0, 208
	voice_directsound 60, 0, DirectSoundWaveData_dp_fretlessbass_d1_16, 255, 0, 255, 196
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_g1_16, 255, 0, 255, 222
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 216
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass1_c2_16, 255, 1, 255, 196
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass2_c1_16, 255, 0, 255, 222
	voice_keysplit voicegroup193, KeySplitTable23    @ violin
	voice_directsound 60, 0, DirectSoundWaveData_dp_oct_g3_16, 255, 235, 255, 212
	voice_square_2_alt 60, 0, 2, 0, 7, 10, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_wind, 37, 244, 155, 226
	voice_directsound 60, 0, DirectSoundWaveData_dp_explosion, 37, 255, 0, 246
	voice_keysplit voicegroup193, KeySplitTable24    @ pizzicato
	voice_keysplit voicegroup193, KeySplitTable25    @ harp
	voice_keysplit voicegroup193, KeySplitTable26    @ timpani 1
	voice_keysplit voicegroup193, KeySplitTable27    @ strings
	voice_directsound 60, 0, DirectSoundWaveData_dp_octlow_cs2_16, 255, 200, 255, 196
	voice_directsound 60, 0, DirectSoundWaveData_dp_octlowbra_b2_16, 255, 200, 255, 226
	voice_keysplit voicegroup193, KeySplitTable28    @ timpani 2
	voice_square_2_alt 60, 0, 2, 0, 7, 8, 2
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_square_wave, 255, 250, 0, 171 @ shift up by 1 octave
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_bubbles, 254, 0, 255, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_octhit_c2_16, 255, 200, 255, 222
	voice_keysplit voicegroup193, KeySplitTable29    @ trumpets 1
	voice_keysplit voicegroup193, KeySplitTable30    @ trombone
	voice_keysplit voicegroup193, KeySplitTable31    @ tuba
	voice_keysplit voicegroup193, KeySplitTable32    @ trumpets 2
	voice_keysplit voicegroup193, KeySplitTable33    @ french horns
	voice_keysplit voicegroup193, KeySplitTable34    @ distortion guitar 2
	voice_square_2_alt 60, 0, 1, 0, 6, 6, 2
	voice_square_2_alt 60, 0, 0, 0, 6, 6, 2
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass_c1_16, 255, 1, 255, 216
	voice_directsound 60, 0, DirectSoundWaveData_dp_altosax_c3_16, 255, 219, 252, 196
	voice_keysplit voicegroup193, KeySplitTable35    @ upright bass 2
	voice_square_2_alt 60, 0, 2, 0, 6, 6, 2
	voice_directsound 60, 0, DirectSoundWaveData_dp_oboe_c3_16, 255, 243, 127, 216
	voice_noise_alt 60, 0, 0, 0, 3, 0, 1
	voice_square_2_alt 60, 0, 1, 1, 2, 6, 2
	voice_directsound 60, 0, DirectSoundWaveData_dp_sy_clarinet_c3_16, 255, 243, 159, 216
	voice_square_2_alt 60, 0, 2, 0, 3, 6, 0
	voice_keysplit voicegroup193, KeySplitTable36    @ flute
	voice_directsound 60, 0, DirectSoundWaveData_dp_woodpat_c4_16, 100, 247, 78, 136
	voice_directsound 60, 0, DirectSoundWaveData_dp_basschoir36, 255, 200, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_tenorchoir48, 255, 200, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sopranochoir60, 255, 200, 255, 171
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
	voice_keysplit voicegroup193, KeySplitTable39    @ music box (platinum only)
	voice_keysplit voicegroup193, KeySplitTable37    @ banjo

