	.macro voice_directsound base_midi_key:req, pan:req, sample_data_pointer:req, attack:req, decay:req, sustain:req, release:req
	.byte 0
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_no_resample base_midi_key:req, pan:req, sample_data_pointer:req, attack:req, decay:req, sustain:req, release:req
	.byte 8
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_alt base_midi_key:req, pan:req, sample_data_pointer:req, attack:req, decay:req, sustain:req, release:req
	.byte 16
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_directsound base_midi_key:req, pan:req, sample_data_pointer:req, attack:req, decay:req, sustain:req, release:req
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

	.macro voice_square_1 base_midi_key:req, pan:req, sweep:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_square_1 1, \base_midi_key, \pan, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_1_alt base_midi_key:req, pan:req, sweep:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_square_1 9, \base_midi_key, \pan, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_1 type:req, base_midi_key:req, pan:req, sweep:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte \sweep
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_square_2 base_midi_key:req, pan:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_square_2 2, \base_midi_key, \pan, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_2_alt base_midi_key:req, pan:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	_voice_square_2 10, \base_midi_key, \pan, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_2 type:req, base_midi_key:req, pan:req, duty_cycle:req, attack:req, decay:req, sustain:req, release:req
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte 0
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_programmable_wave base_midi_key:req, pan:req, wave_samples_pointer:req, attack:req, decay:req, sustain:req, release:req
	_voice_programmable_wave 3, \base_midi_key, \pan, \wave_samples_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_programmable_wave_alt base_midi_key:req, pan:req, wave_samples_pointer:req, attack:req, decay:req, sustain:req, release:req
	_voice_programmable_wave 11, \base_midi_key, \pan, \wave_samples_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_programmable_wave type:req, base_midi_key:req, pan:req, wave_samples_pointer:req, attack:req, decay:req, sustain:req, release:req
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte 0
	.4byte \wave_samples_pointer
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_noise base_midi_key:req, pan:req, period:req, attack:req, decay:req, sustain:req, release:req
	_voice_noise 4, \base_midi_key, \pan, \period, \attack, \decay, \sustain, \release
	.endm

	.macro voice_noise_alt base_midi_key:req, pan:req, period:req, attack:req, decay:req, sustain:req, release:req
	_voice_noise 12, \base_midi_key, \pan, \period, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_noise type:req, base_midi_key:req, pan:req, period:req, attack:req, decay:req, sustain:req, release:req
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte 0
	.byte (\period & 0x1)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	.endm

	.macro voice_keysplit voice_group_pointer:req, keysplit_table_pointer:req
	.byte 0x40, 0, 0, 0
	.4byte \voice_group_pointer
	.4byte \keysplit_table_pointer
	.endm

	.macro voice_keysplit_all voice_group_pointer:req
	.byte 0x80, 0, 0, 0
	.4byte \voice_group_pointer
	.4byte 0
	.endm

	.macro cry sample:req
	.byte 0x20, 60, 0, 0
	.4byte \sample
	.byte 0xff, 0, 0xff, 0
	.endm

	.macro cry_reverse sample:req
	.byte 0x30, 60, 0, 0
	.4byte \sample
	.byte 0xff, 0, 0xff, 0
	.endm

	.macro cry_uncomp sample @ not compressed
	.byte 0x0, 60, 0, 0
	.4byte \sample
	.byte 0xff, 0, 0xff, 0
	.endm

	.macro cry_reverse_uncomp sample @ not compressed
	.byte 0x10, 60, 0, 0
	.4byte \sample
	.byte 0xff, 0, 0xff, 0
	.endm
