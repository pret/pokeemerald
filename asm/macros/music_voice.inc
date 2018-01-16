	.macro voice_directsound base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte 0
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_no_resample base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte 8
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_alt base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte 16
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_directsound base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte \base_midi_key
	.byte 0
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.4byte \sample_data_pointer
	.byte \attack
	.byte \decay
	.byte \sustain
	.byte \release
	.endm

	.macro voice_square_1 sweep, duty_cycle, attack, decay, sustain, release
	_voice_square_1 1, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_1_alt sweep, duty_cycle, attack, decay, sustain, release
	_voice_square_1 9, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_1 type, sweep, duty_cycle, attack, decay, sustain, release
	.byte \type, 60, 0
	.byte \sweep
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_square_2 duty_cycle, attack, decay, sustain, release
	_voice_square_2 2, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_2_alt duty_cycle, attack, decay, sustain, release
	_voice_square_2 10, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_2 type, duty_cycle, attack, decay, sustain, release
	.byte \type, 60, 0, 0
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_programmable_wave wave_samples_pointer, attack, decay, sustain, release
	_voice_programmable_wave 3, \wave_samples_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_programmable_wave_alt wave_samples_pointer, attack, decay, sustain, release
	_voice_programmable_wave 11, \wave_samples_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_programmable_wave type, wave_samples_pointer, attack, decay, sustain, release
	.byte \type, 60, 0, 0
	.4byte \wave_samples_pointer
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_noise period, attack, decay, sustain, release
	_voice_noise 4, \period, \attack, \decay, \sustain, \release
	.endm

	.macro voice_noise_alt period, attack, decay, sustain, release
	_voice_noise 12, \period, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_noise type, period, attack, decay, sustain, release
	.byte \type, 60, 0, 0
	.byte (\period & 0x1)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_keysplit voice_group_pointer, keysplit_table_pointer
	.byte 0x40, 0, 0, 0
	.4byte \voice_group_pointer
	.4byte \keysplit_table_pointer
	.endm

	.macro voice_keysplit_all voice_group_pointer
	.byte 0x80, 0, 0, 0
	.4byte \voice_group_pointer
	.4byte 0
	.endm

	.macro cry sample
	.byte 0x20, 60, 0, 0
	.4byte \sample
	.byte 0xff, 0, 0xff, 0
	.endm

	.macro cry2 sample
	.byte 0x30, 60, 0, 0
	.4byte \sample
	.byte 0xff, 0, 0xff, 0
	.endm
