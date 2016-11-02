	.equiv ID_NUMBER, 0x68736d53

	.equiv PCM_DMA_BUF_SIZE, 1584

	.equiv TONEDATA_TYPE_CGB, 0x07
	.equiv TONEDATA_TYPE_FIX, 0x08
	.equiv TONEDATA_TYPE_SPL, 0x40 @ key split
	.equiv TONEDATA_TYPE_RHY, 0x80 @ rhythm

	.macro struct_begin
	.struct 0
	.endm

	.macro struct_field name, size
\name:
	.struct \name + \size
	.endm

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
	struct_field o_SoundInfo_func, 4
	struct_field o_SoundInfo_intp, 4
	struct_field o_SoundInfo_CgbSound, 4
	struct_field o_SoundInfo_CgbOscOff, 4
	struct_field o_SoundInfo_MidiKeyToCgbFreq, 4
	struct_field o_SoundInfo_MPlayJumpTable, 4
	struct_field o_SoundInfo_plynote, 4
	struct_field o_SoundInfo_ExtVolPit, 4
	struct_field o_SoundInfo_gap2, 16
	struct_field o_SoundInfo_chans, 768
	struct_field o_SoundInfo_pcmBuffer, PCM_DMA_BUF_SIZE * 2
	struct_field SoundInfo_size, 0

	struct_begin
	struct_field o_SoundChannel_status, 1
	struct_field o_SoundChannel_type, 1
	struct_field o_SoundChannel_rightVolume, 1
	struct_field o_SoundChannel_leftVolume, 1
	struct_field o_SoundChannel_attack, 1
	struct_field o_SoundChannel_decay, 1
	struct_field o_SoundChannel_sustain, 1
	struct_field o_SoundChannel_release, 1
	struct_field o_SoundChannel_ky, 1
	struct_field o_SoundChannel_ev, 1
	struct_field o_SoundChannel_er, 1
	struct_field o_SoundChannel_el, 1
	struct_field o_SoundChannel_iev, 1
	struct_field o_SoundChannel_iel, 1
	struct_field o_SoundChannel_d1, 1
	struct_field o_SoundChannel_d2, 1
	struct_field o_SoundChannel_gt, 1
	struct_field o_SoundChannel_mk, 1
	struct_field o_SoundChannel_ve, 1
	struct_field o_SoundChannel_pr, 1
	struct_field o_SoundChannel_rp, 1
	struct_field o_SoundChannel_d3, 3
	struct_field o_SoundChannel_ct, 4
	struct_field o_SoundChannel_fw, 4
	struct_field o_SoundChannel_freq, 4
	struct_field o_SoundChannel_wav, 4
	struct_field o_SoundChannel_cp, 4
	struct_field o_SoundChannel_track, 4
	struct_field o_SoundChannel_pp, 4
	struct_field o_SoundChannel_np, 4
	struct_field o_SoundChannel_d4, 4
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
	struct_field o_MusicPlayerTrack_echoVolume, 1
	struct_field o_MusicPlayerTrack_echoLength, 1
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
	struct_field o_CgbChannel_sf, 1
	struct_field o_CgbChannel_ty, 1
	struct_field o_CgbChannel_rightVolume, 1
	struct_field o_CgbChannel_leftVolume, 1
	struct_field o_CgbChannel_at, 1
	struct_field o_CgbChannel_de, 1
	struct_field o_CgbChannel_su, 1
	struct_field o_CgbChannel_re, 1
	struct_field o_CgbChannel_ky, 1
	struct_field o_CgbChannel_ev, 1
	struct_field o_CgbChannel_eg, 1
	struct_field o_CgbChannel_ec, 1
	struct_field o_CgbChannel_echoVolume, 1
	struct_field o_CgbChannel_echoLength, 1
	struct_field o_CgbChannel_d1, 1
	struct_field o_CgbChannel_d2, 1
	struct_field o_CgbChannel_gt, 1
	struct_field o_CgbChannel_mk, 1
	struct_field o_CgbChannel_ve, 1
	struct_field o_CgbChannel_pr, 1
	struct_field o_CgbChannel_rp, 1
	struct_field o_CgbChannel_d3, 3
	struct_field o_CgbChannel_d5, 1
	struct_field o_CgbChannel_sg, 1
	struct_field o_CgbChannel_n4, 1
	struct_field o_CgbChannel_pan, 1
	struct_field o_CgbChannel_panMask, 1
	struct_field o_CgbChannel_mo, 1
	struct_field o_CgbChannel_le, 1
	struct_field o_CgbChannel_sw, 1
	struct_field o_CgbChannel_fr, 4
	struct_field o_CgbChannel_wp, 4
	struct_field o_CgbChannel_cp, 4
	struct_field o_CgbChannel_tp, 4
	struct_field o_CgbChannel_pp, 4
	struct_field o_CgbChannel_np, 4
	struct_field o_CgbChannel_d4, 8
	struct_field CgbChannel_size, 0
