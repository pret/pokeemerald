#ifndef GUARD_CONSTANTS_M4A_CONSTANTS_INC
#define GUARD_CONSTANTS_M4A_CONSTANTS_INC

	.equiv ID_NUMBER, 0x68736d53

	.equiv PCM_DMA_BUF_SIZE, 1584
	.equiv MAX_DIRECTSOUND_CHANNELS, 15

	.equiv C_V, 0x40

	.equiv TONEDATA_TYPE_CGB, 0x07
	.equiv TONEDATA_TYPE_FIX, 0x08
	.equiv TONEDATA_TYPE_REV, 0x10
	.equiv TONEDATA_TYPE_CMP, 0x20
	.equiv TONEDATA_TYPE_SPL, 0x40 @ key split
	.equiv TONEDATA_TYPE_RHY, 0x80 @ rhythm

	.equiv TONEDATA_P_S_PAN,  0xc0

	.equiv SOUND_CHANNEL_SF_START,       0x80
	.equiv SOUND_CHANNEL_SF_STOP,        0x40
	.equiv SOUND_CHANNEL_SF_SPECIAL,     0x20
	.equiv SOUND_CHANNEL_SF_LOOP,        0x10
	.equiv SOUND_CHANNEL_SF_IEC,         0x04
	.equiv SOUND_CHANNEL_SF_ENV,         0x03
	.equiv SOUND_CHANNEL_SF_ENV_ATTACK,  0x03
	.equiv SOUND_CHANNEL_SF_ENV_DECAY,   0x02
	.equiv SOUND_CHANNEL_SF_ENV_SUSTAIN, 0x01
	.equiv SOUND_CHANNEL_SF_ENV_RELEASE, 0x00
	.equiv SOUND_CHANNEL_SF_ON, (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_STOP | SOUND_CHANNEL_SF_IEC | SOUND_CHANNEL_SF_ENV)

	.equiv CGB_CHANNEL_MO_PIT, 0x02
	.equiv CGB_CHANNEL_MO_VOL, 0x01

	.equiv WAVE_DATA_FLAG_LOOP, 0xC0

	.equiv MPT_FLG_VOLSET, 0x01
	.equiv MPT_FLG_VOLCHG, 0x03
	.equiv MPT_FLG_PITSET, 0x04
	.equiv MPT_FLG_PITCHG, 0x0C
	.equiv MPT_FLG_START,  0x40
	.equiv MPT_FLG_EXIST,  0x80

	.macro struct_begin
	.struct 0
	.endm

	.macro struct_field name, size
\name:
	.struct \name + \size
	.endm

	struct_begin
	struct_field o_WaveData_type, 2
	struct_field o_WaveData_d1, 1
	struct_field o_WaveData_flags, 1
	struct_field o_WaveData_freq, 4
	struct_field o_WaveData_loopStart, 4
	struct_field o_WaveData_size, 4
	struct_field o_WaveData_data, 0
	struct_field WaveData_size, 0

	struct_begin
	struct_field o_ToneData_type, 1
	struct_field o_ToneData_key, 1
	struct_field o_ToneData_length, 1
	struct_field o_ToneData_pan_sweep, 1
	struct_field o_ToneData_wav, 4
	struct_field o_ToneData_attack, 1
	struct_field o_ToneData_decay, 1
	struct_field o_ToneData_sustain, 1
	struct_field o_ToneData_release, 1
	struct_field ToneData_size, 0

	struct_begin
	struct_field o_SoundInfo_ident, 4
	struct_field o_SoundInfo_pcmDmaCounter, 1
	struct_field o_SoundInfo_reverb, 1
	struct_field o_SoundInfo_maxChans, 1
	struct_field o_SoundInfo_masterVolume, 1
	struct_field o_SoundInfo_freq, 1
	struct_field o_SoundInfo_mode, 1
	struct_field o_SoundInfo_c15, 1
	struct_field o_SoundInfo_pcmDmaPeriod, 1
	struct_field o_SoundInfo_maxLines, 1
	struct_field o_SoundInfo_gap, 3
	struct_field o_SoundInfo_pcmSamplesPerVBlank, 4
	struct_field o_SoundInfo_pcmFreq, 4
	struct_field o_SoundInfo_divFreq, 4
	struct_field o_SoundInfo_cgbChans, 4
	struct_field o_SoundInfo_MPlayMainHead, 4
	struct_field o_SoundInfo_musicPlayerHead, 4
	struct_field o_SoundInfo_CgbSound, 4
	struct_field o_SoundInfo_CgbOscOff, 4
	struct_field o_SoundInfo_MidiKeyToCgbFreq, 4
	struct_field o_SoundInfo_MPlayJumpTable, 4
	struct_field o_SoundInfo_plynote, 4
	struct_field o_SoundInfo_ExtVolPit, 4
	struct_field o_SoundInfo_gap2, 16
	struct_field o_SoundInfo_chans, MAX_DIRECTSOUND_CHANNELS * 64
	struct_field o_SoundInfo_pcmBuffer, PCM_DMA_BUF_SIZE * 2
	struct_field SoundInfo_size, 0

	struct_begin
	struct_field o_SoundChannel_statusFlags, 1
	struct_field o_SoundChannel_type, 1
	struct_field o_SoundChannel_rightVolume, 1
	struct_field o_SoundChannel_leftVolume, 1
	struct_field o_SoundChannel_attack, 1
	struct_field o_SoundChannel_decay, 1
	struct_field o_SoundChannel_sustain, 1
	struct_field o_SoundChannel_release, 1
	struct_field o_SoundChannel_key, 1
	struct_field o_SoundChannel_envelopeVolume, 1
	struct_field o_SoundChannel_envelopeVolumeRight, 1
	struct_field o_SoundChannel_envelopeVolumeLeft, 1
	struct_field o_SoundChannel_pseudoEchoVolume, 1
	struct_field o_SoundChannel_pseudoEchoLength, 1
	struct_field o_SoundChannel_dummy1, 1
	struct_field o_SoundChannel_dummy2, 1
	struct_field o_SoundChannel_gateTime, 1
	struct_field o_SoundChannel_midiKey, 1
	struct_field o_SoundChannel_velocity, 1
	struct_field o_SoundChannel_priority, 1
	struct_field o_SoundChannel_rhythmPan, 1
	struct_field o_SoundChannel_dummy3, 3
	struct_field o_SoundChannel_count, 4
	struct_field o_SoundChannel_fw, 4
	struct_field o_SoundChannel_frequency, 4
	struct_field o_SoundChannel_wav, 4
	struct_field o_SoundChannel_currentPointer, 4
	struct_field o_SoundChannel_track, 4
	struct_field o_SoundChannel_prevChannelPointer, 4
	struct_field o_SoundChannel_nextChannelPointer, 4
	struct_field o_SoundChannel_dummy4, 4
	struct_field o_SoundChannel_xpi, 2
	struct_field o_SoundChannel_xpc, 2
	struct_field SoundChannel_size, 0

	struct_begin
	struct_field o_MusicPlayerTrack_flags, 1
	struct_field o_MusicPlayerTrack_wait, 1
	struct_field o_MusicPlayerTrack_patternLevel, 1
	struct_field o_MusicPlayerTrack_repN, 1
	struct_field o_MusicPlayerTrack_gateTime, 1
	struct_field o_MusicPlayerTrack_key, 1
	struct_field o_MusicPlayerTrack_velocity, 1
	struct_field o_MusicPlayerTrack_runningStatus, 1
	struct_field o_MusicPlayerTrack_keyM, 1
	struct_field o_MusicPlayerTrack_pitM, 1
	struct_field o_MusicPlayerTrack_keyShift, 1
	struct_field o_MusicPlayerTrack_keyShiftX, 1
	struct_field o_MusicPlayerTrack_tune, 1
	struct_field o_MusicPlayerTrack_pitX, 1
	struct_field o_MusicPlayerTrack_bend, 1
	struct_field o_MusicPlayerTrack_bendRange, 1
	struct_field o_MusicPlayerTrack_volMR, 1
	struct_field o_MusicPlayerTrack_volML, 1
	struct_field o_MusicPlayerTrack_vol, 1
	struct_field o_MusicPlayerTrack_volX, 1
	struct_field o_MusicPlayerTrack_pan, 1
	struct_field o_MusicPlayerTrack_panX, 1
	struct_field o_MusicPlayerTrack_modM, 1
	struct_field o_MusicPlayerTrack_mod, 1
	struct_field o_MusicPlayerTrack_modT, 1
	struct_field o_MusicPlayerTrack_lfoSpeed, 1
	struct_field o_MusicPlayerTrack_lfoSpeedC, 1
	struct_field o_MusicPlayerTrack_lfoDelay, 1
	struct_field o_MusicPlayerTrack_lfoDelayC, 1
	struct_field o_MusicPlayerTrack_priority, 1
	struct_field o_MusicPlayerTrack_pseudoEchoVolume, 1
	struct_field o_MusicPlayerTrack_pseudoEchoLength, 1
	struct_field o_MusicPlayerTrack_chan, 4
	struct_field o_MusicPlayerTrack_ToneData_type, 1
	struct_field o_MusicPlayerTrack_ToneData_key, 1
	struct_field o_MusicPlayerTrack_ToneData_length, 1
	struct_field o_MusicPlayerTrack_ToneData_pan_sweep, 1
	struct_field o_MusicPlayerTrack_ToneData_wav, 4
	struct_field o_MusicPlayerTrack_ToneData_attack, 1
	struct_field o_MusicPlayerTrack_ToneData_decay, 1
	struct_field o_MusicPlayerTrack_ToneData_sustain, 1
	struct_field o_MusicPlayerTrack_ToneData_release, 1
	struct_field o_MusicPlayerTrack_gap, 10
	struct_field o_MusicPlayerTrack_unk_3A, 2
	struct_field o_MusicPlayerTrack_unk_3C, 4
	struct_field o_MusicPlayerTrack_cmdPtr, 4
	struct_field o_MusicPlayerTrack_patternStack, 12
	struct_field MusicPlayerTrack_size, 0

	.equiv o_MusicPlayerTrack_ToneData_keySplitTable, o_MusicPlayerTrack_ToneData_attack

	struct_begin
	struct_field o_MusicPlayerInfo_songHeader, 4
	struct_field o_MusicPlayerInfo_status, 4
	struct_field o_MusicPlayerInfo_trackCount, 1
	struct_field o_MusicPlayerInfo_priority, 1
	struct_field o_MusicPlayerInfo_cmd, 1
	struct_field o_MusicPlayerInfo_unk_B, 1
	struct_field o_MusicPlayerInfo_clock, 4
	struct_field o_MusicPlayerInfo_gap, 8
	struct_field o_MusicPlayerInfo_memAccArea, 4
	struct_field o_MusicPlayerInfo_tempoD, 2
	struct_field o_MusicPlayerInfo_tempoU, 2
	struct_field o_MusicPlayerInfo_tempoI, 2
	struct_field o_MusicPlayerInfo_tempoC, 2
	struct_field o_MusicPlayerInfo_fadeOI, 2
	struct_field o_MusicPlayerInfo_fadeOC, 2
	struct_field o_MusicPlayerInfo_fadeOV, 2
	struct_field o_MusicPlayerInfo_padding, 2
	struct_field o_MusicPlayerInfo_tracks, 4
	struct_field o_MusicPlayerInfo_tone, 4
	struct_field o_MusicPlayerInfo_ident, 4
	struct_field o_MusicPlayerInfo_func, 4
	struct_field o_MusicPlayerInfo_intp, 4
	struct_field MusicPlayerInfo_size, 0

	struct_begin
	struct_field o_CgbChannel_statusFlags, 1
	struct_field o_CgbChannel_type, 1
	struct_field o_CgbChannel_rightVolume, 1
	struct_field o_CgbChannel_leftVolume, 1
	struct_field o_CgbChannel_attack, 1
	struct_field o_CgbChannel_decay, 1
	struct_field o_CgbChannel_sustain, 1
	struct_field o_CgbChannel_release, 1
	struct_field o_CgbChannel_key, 1
	struct_field o_CgbChannel_envelopeVolume, 1
	struct_field o_CgbChannel_envelopeGoal, 1
	struct_field o_CgbChannel_envelopeCounter, 1
	struct_field o_CgbChannel_pseudoEchoVolume, 1
	struct_field o_CgbChannel_pseudoEchoLength, 1
	struct_field o_CgbChannel_dummy1, 1
	struct_field o_CgbChannel_dummy2, 1
	struct_field o_CgbChannel_gateTime, 1
	struct_field o_CgbChannel_midiKey, 1
	struct_field o_CgbChannel_velocity, 1
	struct_field o_CgbChannel_priority, 1
	struct_field o_CgbChannel_rhythmPan, 1
	struct_field o_CgbChannel_dummy3, 3
	struct_field o_CgbChannel_dummy5, 1
	struct_field o_CgbChannel_sustainGoal, 1
	struct_field o_CgbChannel_n4, 1
	struct_field o_CgbChannel_pan, 1
	struct_field o_CgbChannel_panMask, 1
	struct_field o_CgbChannel_modify, 1
	struct_field o_CgbChannel_length, 1
	struct_field o_CgbChannel_sweep, 1
	struct_field o_CgbChannel_frequency, 4
	struct_field o_CgbChannel_wavePointer, 4
	struct_field o_CgbChannel_currentPointer, 4
	struct_field o_CgbChannel_track, 4
	struct_field o_CgbChannel_prevChannelPointer, 4
	struct_field o_CgbChannel_nextChannelPointer, 4
	struct_field o_CgbChannel_dummy4, 8
	struct_field CgbChannel_size, 0

#endif  @ GUARD_CONSTANTS_M4A_CONSTANTS_INC
