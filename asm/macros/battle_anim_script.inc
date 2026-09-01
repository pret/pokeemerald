@ commands

	.macro unloadspritegfx tag:req
	.byte 0x0
	.2byte \tag
	.endm

	.macro unloadspritepal tag:req
	.byte 0x1
	.2byte \tag
	.endm

	.macro createsprite template:req, anim_battler:req, subpriority_offset:req, argv:vararg
	.byte 0x02
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte ANIMSPRITE_IS_TARGET | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	.macro createvisualtask addr:req, priority:req, argv:vararg
	.byte 0x03
	.4byte \addr
	.byte \priority
	.byte (.Lcreatetask_\@_2 - .Lcreatetask_\@_1) / 2
.Lcreatetask_\@_1:
	.2byte \argv
.Lcreatetask_\@_2:
	.endm

	.macro delay frames:req
	.byte 0x4
	.byte \frames
	.endm

	.macro waitforvisualfinish
	.byte 0x5
	.endm

	.macro nop
	.byte 0x6
	.endm

	.macro nop2
	.byte 0x7
	.endm

	.macro end
	.byte 0x8
	.endm

	.macro playse se:req
	.byte 0x9
	.2byte \se
	.endm

	.macro monbg battler:req
	.byte 0xa
	.byte \battler
	.endm

	.macro clearmonbg battler:req
	.byte 0xb
	.byte \battler
	.endm

	.macro setalpha eva:req, evb:req
	.byte 0x0C
	.2byte ((\evb) << 8) | (\eva)
	.endm

	.macro blendoff
	.byte 0xd
	.endm

	.macro call ptr:req
	.byte 0xe
	.4byte \ptr
	.endm

	.macro return
	.byte 0xf
	.endm

	.macro setarg argId:req, value:req
	.byte 0x10
	.byte \argId
	.2byte \value
	.endm

	.macro choosetwoturnanim ptr1:req, ptr2:req
	.byte 0x11
	.4byte \ptr1
	.4byte \ptr2
	.endm

	.macro jumpifmoveturn value:req, ptr:req
	.byte 0x12
	.byte \value
	.4byte \ptr
	.endm

	.macro goto ptr:req
	.byte 0x13
	.4byte \ptr
	.endm

	.macro fadetobg bg:req
	.byte 0x14
	.byte \bg
	.endm

	.macro restorebg
	.byte 0x15
	.endm

	.macro waitbgfadeout
	.byte 0x16
	.endm

	.macro waitbgfadein
	.byte 0x17
	.endm

	.macro changebg bg:req
	.byte 0x18
	.byte \bg
	.endm

	.macro playsewithpan se:req, pan:req
	.byte 0x19
	.2byte \se
	.byte \pan
	.endm

	.macro setpan pan:req
	.byte 0x1a
	.byte \pan
	.endm

	.macro panse se:req, currentPan:req, targetPan:req, incrementPan:req, delay:req
	.byte 0x1b
	.2byte \se
	.byte \currentPan
	.byte \targetPan
	.byte \incrementPan
	.byte \delay
	.endm

	.macro loopsewithpan se:req, pan:req, wait:req, times:req
	.byte 0x1c
	.2byte \se
	.byte \pan
	.byte \wait
	.byte \times
	.endm

	.macro waitplaysewithpan se:req, pan:req, wait:req
	.byte 0x1d
	.2byte \se
	.byte \pan
	.byte \wait
	.endm

	.macro setbldcnt bldcnt:req
	.byte 0x1e
	.2byte \bldcnt
	.endm

	.macro createsoundtask addr:req, argv:vararg
	.byte 0x1F
	.4byte \addr
	.byte (.Lcreatetask_1F_\@_2 - .Lcreatetask_1F_\@_1) / 2
.Lcreatetask_1F_\@_1:
	.2byte \argv
.Lcreatetask_1F_\@_2:
	.endm

	.macro waitsound
	.byte 0x20
	.endm

	.macro jumpargeq argId:req, value:req, ptr:req
	.byte 0x21
	.byte \argId
	.2byte \value
	.4byte \ptr
	.endm

	.macro monbg_static battler:req
	.byte 0x22
	.byte \battler
	.endm

	.macro clearmonbg_static battler:req
	.byte 0x23
	.byte \battler
	.endm

	.macro jumpifcontest ptr:req
	.byte 0x24
	.4byte \ptr
	.endm

	.macro fadetobgfromset bgOpponent:req, bgPlayer:req, bgContest:req
	.byte 0x25
	.byte \bgOpponent
	.byte \bgPlayer
	.byte \bgContest
	.endm

	.macro panse_adjustnone se:req, currentPan:req, targetPan:req, incrementPan:req, delay:req
	.byte 0x26
	.2byte \se
	.byte \currentPan
	.byte \targetPan
	.byte \incrementPan
	.byte \delay
	.endm

	.macro panse_adjustall se:req, currentPan:req, targetPan:req, incrementPan:req, delay:req
	.byte 0x27
	.2byte \se
	.byte \currentPan
	.byte \targetPan
	.byte \incrementPan
	.byte \delay
	.endm

	.macro splitbgprio battler:req
	.byte 0x28
	.byte \battler
	.endm

	.macro splitbgprio_all
	.byte 0x29
	.endm

	.macro splitbgprio_foes battler:req
	.byte 0x2a
	.byte \battler
	.endm

	.macro invisible battler:req
	.byte 0x2b
	.byte \battler
	.endm

	.macro visible battler:req
	.byte 0x2c
	.byte \battler
	.endm

	.macro teamattack_moveback battler:req
	.byte 0x2d
	.byte \battler
	.endm

	.macro teamattack_movefwd battler:req
	.byte 0x2e
	.byte \battler
	.endm

	.macro stopsound
	.byte 0x2f
	.endm

	@ same as createvisualtask except takes in battlerargindex, which is the battle anim arg index of the battler to loop through
	.macro createvisualtaskontargets addr:req, priority:req, battlerargindex:req, argv:vararg
	.byte 0x30
	.4byte \addr
	.byte \priority
	.byte \battlerargindex
	.byte (.Lcreatetask_\@_2 - .Lcreatetask_\@_1) / 2	@ num_args
.Lcreatetask_\@_1:
	.2byte \argv
.Lcreatetask_\@_2:
	.endm

	@ same as createsprite except takes in battlerargindex, which is the battle anim arg index of the battler to loop through
	.macro createspriteontargets template:req, anim_battler:req, subpriority_offset:req, battlerargindex:req, argv:vararg
	.byte 0x31
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte ANIMSPRITE_IS_TARGET | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte \battlerargindex
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	@ does not overwrite gBattleAnimArgs[battlerargindex], some sprite templates are too dependent on the value (e.g. heal block)
	.macro createspriteontargets_onpos template:req, anim_battler:req, subpriority_offset:req, battlerargindex:req, argv:vararg
	.byte 0x32
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte ANIMSPRITE_IS_TARGET | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte \battlerargindex
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	.macro jumpifmovetypeequal type:req, jumpInstr:req
	.byte 0x33
	.byte \type
	.4byte \jumpInstr
	.endm

	.macro createdragondartsprite anim_battler:req, subpriority_offset:req, argv:vararg
	.byte 0x34
	.if \anim_battler == ANIM_TARGET
	.byte ANIMSPRITE_IS_TARGET | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	.macro unloadallspritepals
	.byte 0x35
	.endm

@ useful macros
	.macro jumpreteq value:req, ptr:req
	jumpargeq ARG_RET_ID, \value, \ptr
	.endm

	.macro jumprettrue ptr:req
	jumpreteq TRUE, \ptr
	.endm

	.macro jumpretfalse ptr:req
	jumpreteq FALSE, \ptr
	.endm

	.macro jumpifdoublebattle ptr:req
	createvisualtask AnimTask_IsDoubleBattle, 0
	jumprettrue \ptr
	.endm

@ createsprite wrappers
@ The arguments are based on the CMD_ARGS of the callback associated with the template.

	.macro simple_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector:req, delay:req, initial_blend_y:req, target_blend_y:req, color:req
	createsprite gSimplePaletteBlendSpriteTemplate, \unused_anim_battler, \unused_subpriority_offset, \selector, \delay, \initial_blend_y, \target_blend_y, \color
	.endm

	.macro complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector:req, delay:req, num_blends:req, color1:req, blend_y1:req, color2:req, blend_y2:req
	createsprite gComplexPaletteBlendSpriteTemplate, \unused_anim_battler, \unused_subpriority_offset, \selector, \delay, \num_blends, \color1, \blend_y1, \color2, \blend_y2
	.endm

	.macro shake_mon_or_platform unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, velocity:req, shake_timer:req, shake_duration:req, type:req, battler_selector
	.if \type == SHAKE_MON_X || \type == SHAKE_MON_Y
	.ifb \battler_selector
	.error "battler_selector required for SHAKE_MON_X or SHAKE_MON_Y"
	.endif
	.else
	.ifnb \battler_selector
	.warning "unused battler_selector in shake_mon_or_platform"
	.endif
	.endif
	.ifb \battler_selector
	createsprite gShakeMonOrPlatformSpriteTemplate, \unused_anim_battler, \unused_subpriority_offset, \velocity, \shake_timer, \shake_duration, \type
	.else
	createsprite gShakeMonOrPlatformSpriteTemplate, \unused_anim_battler, \unused_subpriority_offset, \velocity, \shake_timer, \shake_duration, \type, \battler_selector
	.endif
	.endm

	.macro create_megahorn_horn_sprite anim_battler:req, subpriority_offset:req, x1:req, y1:req, x2:req, y2:req, duration:req
	createsprite gMegahornHornSpriteTemplate, \anim_battler, \subpriority_offset, \x1, \y1, \x2, \y2, \duration
	.endm

	.macro create_leech_life_needle_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req
	createsprite gLeechLifeNeedleSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration
	.endm

	.macro create_web_thread_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, unk2:req, amplitude:req, targets_both:req
	createsprite gWebThreadSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \unk2, \amplitude, \targets_both
	.endm

	.macro create_string_wrap_sprite anim_battler:req, subpriority_offset:req, x:req, y:req
	createsprite gStringWrapSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y
	.endm

	.macro create_linear_stinger_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req
	createsprite gLinearStingerSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration
	.endm

	.macro create_pin_missile_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req, wave_amplitude:req
	createsprite gPinMissileSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration, \wave_amplitude
	.endm

	.macro create_tail_glow_orb_sprite anim_battler:req, subpriority_offset:req, relative_to:req
	createsprite gTailGlowOrbSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to
	.endm

	.macro create_sharp_teeth_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, animation:req, x_velocity:req, y_velocity:req, half_duration:req
	createsprite gSharpTeethSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \animation, 256 * \x_velocity, 256 * \y_velocity, \half_duration
	.endm

	.macro create_clamp_jaw_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, animation:req, x_velocity:req, y_velocity:req, half_duration:req
	createsprite gClampJawSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \animation, 256 * \x_velocity, 256 * \y_velocity, \half_duration
	.endm

	.macro create_tear_drop_sprite anim_battler:req, subpriority_offset:req, relative_to:req, type:req
	createsprite gTearDropSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to, \type
	.endm

	.macro create_claw_slash_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, animation:req
	createsprite gClawSlashSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \animation
	.endm

	.macro create_outrage_flame_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, x_velocity:req, y_velocity:req, flicker_duration:req
	createsprite gOutrageFlameSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, 256 * \x_velocity, 256 * \y_velocity, \flicker_duration
	.endm

	.macro create_dragon_breath_fire_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req
	createsprite gDragonBreathFireSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration
	.endm

	.macro create_dragon_rage_fire_spit_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req
	createsprite gDragonRageFireSpitSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration
	.endm

	.macro create_dragon_rage_fire_plume_sprite anim_battler:req, subpriority_offset:req, relative_to:req, x:req, y:req
	createsprite gDragonRageFirePlumeSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to, \x, \y
	.endm

	.macro create_dragon_dance_orb_sprite anim_battler:req, subpriority_offset:req, angle:req
	createsprite gDragonDanceOrbSpriteTemplate, \anim_battler, \subpriority_offset, 256 * \angle
	.endm

	.macro create_overheat_flame_sprite anim_battler:req, subpriority_offset:req, speed:req, unk1:req, unk2:req, duration:req, y:req
	createsprite gOverheatFlameSpriteTemplate, \anim_battler, \subpriority_offset, \speed, \unk1, \unk2, \duration, \y
	.endm

	.macro create_sleep_powder_particle_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, y_velocity:req, wave_amplitude:req, wave_speed:req
	createsprite gSleepPowderParticleSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, 256 * \y_velocity, \wave_amplitude, \wave_speed
	.endm

	.macro create_stun_spore_particle_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, y_velocity:req, wave_amplitude:req, wave_speed:req
	createsprite gStunSporeParticleSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, 256 * \y_velocity, \wave_amplitude, \wave_speed
	.endm

	.macro create_poison_powder_particle_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, y_velocity:req, wave_amplitude:req, wave_speed:req
	createsprite gPoisonPowderParticleSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, 256 * \y_velocity, \wave_amplitude, \wave_speed
	.endm

	.macro create_magic_powder_particle_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, y_velocity:req, wave_amplitude:req, wave_speed:req
	createsprite gMagicPowderBluePowderTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, 256 * \y_velocity, \wave_amplitude, \wave_speed
	.endm

	.macro create_power_absorption_orb_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req
	createsprite gPowerAbsorptionOrbSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration
	.endm

	.macro create_stockpile_absorption_orb_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req
	createsprite gStockpileAbsorptionOrbSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration
	.endm

	.macro create_solar_beam_big_orb_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, animation:req
	createsprite gSolarBeamBigOrbSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, \animation
	.endm

	.macro create_absorption_orb_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, wave_amplitude:req, wave_period:req
	createsprite gAbsorptionOrbSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \wave_amplitude, \wave_period
	.endm

	.macro create_hyper_beam_orb_sprite anim_battler:req, subpriority_offset:req
	createsprite gHyperBeamOrbSpriteTemplate, \anim_battler, \subpriority_offset
	.endm

	.macro create_leech_seed_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req, wave_amplitude:req
	createsprite gLeechSeedSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration, \wave_amplitude
	.endm

	.macro create_spore_particle_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, wave_offset:req, duration:req, blend:req
	createsprite gSporeParticleSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \wave_offset, \duration, \blend
	.endm

	.macro create_petal_dance_big_flower_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_y:req, duration:req
	createsprite gPetalDanceBigFlowerSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_y, \duration
	.endm

	.macro create_petal_dance_small_flower_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_y:req, duration:req
	createsprite gPetalDanceSmallFlowerSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_y, \duration
	.endm

	.macro create_razor_leaf_particle_sprite anim_battler:req, subpriority_offset:req, upward_delta_x:req, upward_delta_y:req, upward_duration:req
	createsprite gRazorLeafParticleSpriteTemplate, \anim_battler, \subpriority_offset, \upward_delta_x, \upward_delta_y, \upward_duration
	.endm

	.macro create_razor_leaf_cutter_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req, wave_amplitude:req, target_both:req
	createsprite gRazorLeafCutterSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration, \wave_amplitude, \target_both
	.endm

	.macro create_swift_star_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, target_x:req, target_y:req, duration:req, wave_amplitude:req, target_both:req
	createsprite gSwiftStarSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \target_x, \target_y, \duration, \wave_amplitude, \target_both
	.endm

	.macro create_twister_leaf_sprite anim_battler:req, subpriority_offset:req, duration:req, distance_y:req, wave_period:req, wave_amplitude:req, speed_up_on_frame:req
	createsprite gTwisterLeafSpriteTemplate, \anim_battler, \subpriority_offset, \duration, \distance_y, \wave_period, \wave_amplitude, \speed_up_on_frame
	.endm

	.macro create_constrict_binding_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, affine_animation:req, squeezes:req
	createsprite gConstrictBindingSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \affine_animation, \squeezes
	.endm

	.macro create_mimic_orb_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req
	createsprite gMimicOrbSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y
	.endm

	.macro create_ingrain_root_sprite anim_battler:req, subpriority_offset:req, offset_x:req, offset_y:req, subpriority:req, animation:req, duration:req
	createsprite gIngrainRootSpriteTemplate, \anim_battler, \subpriority_offset, \offset_x, \offset_y, \subpriority - 30, \animation, \duration
	.endm

	.macro create_frenzy_plant_root_sprite anim_battler:req, subpriority_offset:req, interpolate_percent:req, offset_x:req, offset_y:req, subpriority:req, animation:req, duration:req
	createsprite gFrenzyPlantRootSpriteTemplate, \anim_battler, \subpriority_offset, \interpolate_percent, \offset_x, \offset_y, \subpriority - 30, \animation, \duration
	.endm

	.macro create_ingrain_orb_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, velocity_x:req, wave_amplitude:req, duration:req
	createsprite gIngrainOrbSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \velocity_x, \wave_amplitude, \duration
	.endm

	.macro create_present_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, unk2:req, unk3:req, unk4:req
	createsprite gPresentSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \unk2, \unk3, \unk4
	.endm

	.macro create_present_heal_particle_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, velocity_y:req, unused3=1
	createsprite gPresentHealParticleSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \velocity_y, \unused3
	.endm

	.macro create_item_steal_sprite anim_battler:req, subpriority_offset:req, initial_x:req, initial_y:req, unk2, unk3, unk4
	createsprite gItemStealSpriteTemplate, \anim_battler, \subpriority_offset, \initial_x, \initial_y, \unk2, \unk3, \unk4
	.endm

	.macro create_trick_bag_sprite anim_battler:req, subpriority_offset:req, initial_y:req, wave_offset:req
	createsprite gTrickBagSpriteTemplate, \anim_battler, \subpriority_offset, \initial_y, \wave_offset
	.endm

	.macro create_confusion_duck_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, wave_offset:req, wave_period:req, duration:req
	createsprite gConfusionDuckSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \wave_offset, \wave_period, \duration
	.endm

	.macro create_basic_hitsplat_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, relative_to:req, animation:req
	createsprite gBasicHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \relative_to, \animation
	.endm

	.macro create_persist_hitsplat_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, relative_to:req, animation:req, duration:req
	createsprite gPersistHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \relative_to, \animation, \duration
	.endm

	.macro create_handle_invert_hitsplat_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, relative_to:req, animation:req
	createsprite gHandleInvertHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \relative_to, \animation
	.endm

	.macro create_random_pos_hitsplat_sprite anim_battler:req, subpriority_offset:req, relative_to:req, animation
	.ifnb \animation
	createsprite gRandomPosHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to, \animation
	.else
	createsprite gRandomPosHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to, -1
	.endif
	.endm

	.macro create_mon_edge_hitsplat_sprite anim_battler:req, subpriority_offset:req, relative_to:req, x:req, y:req, animation:req
	createsprite gMonEdgeHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to, \x, \y, \animation
	.endm

	.macro create_cross_impact_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, relative_to:req, duration:req
	createsprite gCrossImpactSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \relative_to, \duration
	.endm

	.macro create_flashing_hitsplat_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, relative_to:req, animation:req
	createsprite gFlashingHitSplatSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \relative_to, \animation
	.endm

	.macro create_fist_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, initPosition=ANIM_TARGET
	createsprite gFistFootSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, \initPosition, 0
	.endm

	.macro create_wide_foot_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, initPosition=ANIM_TARGET
	createsprite gFistFootSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, \initPosition, 1
	.endm

	.macro create_narrow_foot_sprite anim_battler:req, subpriority_offset:req, x:req, y:req, duration:req, initPosition=ANIM_TARGET
	createsprite gFistFootSpriteTemplate, \anim_battler, \subpriority_offset, \x, \y, \duration, \initPosition, 2
	.endm

	.macro create_electric_puff_sprite anim_battler:req, subpriority_offset:req, relative_to:req, x:req, y:req
	createsprite gElectricPuffSpriteTemplate, \anim_battler, \subpriority_offset, \relative_to, \x, \y
	.endm

@ createvisualtask wrappers
@ The arguments are based on the CMD_ARGS of the task.

	.macro metallic_shine priority=5, permanent:req, color
	.ifb \color
	createvisualtask AnimTask_MetallicShine, \priority, \permanent, FALSE, RGB_BLACK
	.else
	createvisualtask AnimTask_MetallicShine, \priority, \permanent, TRUE, \color
	.endif
	.endm

	.macro set_grayscale_pal priority=5, battler:req
	createvisualtask AnimTask_SetGrayscaleOrOriginalPal, \priority, \battler, FALSE
	.endm

	.macro set_original_pal priority=5, battler:req
	createvisualtask AnimTask_SetGrayscaleOrOriginalPal, \priority, \battler, TRUE
	.endm

	.macro attacker_fade_to_invisible priority=2, step_delay:req
	createvisualtask AnimTask_AttackerFadeToInvisible, \priority, \step_delay
	.endm

	.macro attacker_fade_from_invisible priority=2, step_delay:req
	createvisualtask AnimTask_AttackerFadeFromInvisible, \priority, \step_delay
	.endm

	.macro shrink_target_copy priority=5, unk0:req, unk1:req
	createvisualtask AnimTask_ShrinkTargetCopy, \priority, \unk0, \unk1
	.endm

	.macro create_leaf_blade_task priority=5
	createvisualtask AnimTask_LeafBlade, \priority
	.endm

	.macro blend_color_cycle priority=2, selector:req, delay:req, num_blends:req, initial_blend_y:req, target_blend_y:req, color:req
	createvisualtask AnimTask_BlendColorCycle, \priority, \selector, \delay, \num_blends, \initial_blend_y, \target_blend_y, \color
	.endm

	.macro blend_color_cycleexclude priority=2, unk0:req, delay:req, num_blends:req, initial_blend_y:req, target_blend_y:req, color:req
	createvisualtask AnimTask_BlendColorCycleExclude, \priority, \unk0, \delay, \num_blends, \initial_blend_y, \target_blend_y, \color
	.endm

	.macro blend_color_cyclebytag priority=2, tag:req, delay:req, num_blends:req, initial_blend_y:req, target_blend_y:req, color:req
	createvisualtask AnimTask_BlendColorCycleByTag, \priority, \tag, \delay, \num_blends, \initial_blend_y, \target_blend_y, \color
	.endm

	.macro flash_anim_tag_with_color priority=2, tag:req, delay:req, num_blends:req, color1:req, blend_y1:req, color2:req, blend_y2:req
	createvisualtask AnimTask_FlashAnimTagWithColor, \priority, \tag, \delay, \num_blends, \color1, \blend_y1, \color2, \blend_y2
	.endm

	@ NOTE: This function is different on expansion compared to pret
	.macro invert_screen_color priority=2, scenery:req
	@ NOTE: These generate 0x000 or 0x101 to match, but the code checks for '& 0x100'.
	createvisualtask AnimTask_InvertScreenColor, \priority, \scenery
	.endm

	.macro tint_palettes priority=2, scenery:req, attacker:req, target:req, duration:req, color:req
	createvisualtask AnimTask_TintPalettes, \priority, \scenery << 8, \attacker << 8, \target << 8, \duration, \color & 0x1F, (\color >> 5) & 0x1F, (\color >> 10) & 0x1F
	.endm

	.macro shake_battle_platforms priority=2, x_offset:req, y_offset:req, shakes:req, delay:req
	createvisualtask AnimTask_ShakeBattlePlatforms, \priority, \x_offset, \y_offset, \shakes, \delay
	.endm

	.macro create_surf_wave priority=2, palette:req
	createvisualtask AnimTask_CreateSurfWave, \priority, \palette
	.endm

@ Common Steps
	.macro create_powder_particles sound_effect=SE_M_POISON_POWDER, anim_battler:req, sprite:req
	loopsewithpan \sound_effect, SOUND_PAN_TARGET, 10, 6
	\sprite \anim_battler, 2, x=-30, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	\sprite \anim_battler, 2, x=10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	\sprite \anim_battler, 2, x=-25, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=3
	delay 15
	\sprite \anim_battler, 2, x=-5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	\sprite \anim_battler, 2, x=5, y=-22, duration=117, y_velocity=96/256, wave_amplitude=5, wave_speed=1
	\sprite \anim_battler, 2, x=0, y=-22, duration=117, y_velocity=69/256, wave_amplitude=-5, wave_speed=1
	\sprite \anim_battler, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	delay 30
	\sprite \anim_battler, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	\sprite \anim_battler, 2, x=15, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	\sprite \anim_battler, 2, x=-10, y=-22, duration=117, y_velocity=96/256, wave_amplitude=7, wave_speed=2
	\sprite \anim_battler, 2, x=-5, y=-22, duration=117, y_velocity=90/256, wave_amplitude=-8, wave_speed=0
	delay 20
	\sprite \anim_battler, 2, x=-10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	\sprite \anim_battler, 2, x=0, y=-22, duration=117, y_velocity=89/256, wave_amplitude=5, wave_speed=2
	\sprite \anim_battler, 2, x=20, y=-22, duration=117, y_velocity=112/256, wave_amplitude=-8, wave_speed=2
	\sprite \anim_battler, 2, x=5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	waitforvisualfinish
	.endm

	.macro create_particle_ring sprite:req, anim_battler:req
	createsprite \sprite, \anim_battler, 2, 26, 0
	createsprite \sprite, \anim_battler, 2, 26, 42
	createsprite \sprite, \anim_battler, 2, 26, 84
	createsprite \sprite, \anim_battler, 2, 26, 126
	createsprite \sprite, \anim_battler, 2, 26, 168
	createsprite \sprite, \anim_battler, 2, 26, 210
	.endm

	.macro create_scattered_particle_ring sprite:req, anim_battler:req
	createsprite \sprite, \anim_battler, 2, 0
	createsprite \sprite, \anim_battler, 2, 32
	createsprite \sprite, \anim_battler, 2, 64
	createsprite \sprite, \anim_battler, 2, 96
	createsprite \sprite, \anim_battler, 2, 128
	createsprite \sprite, \anim_battler, 2, 160
	createsprite \sprite, \anim_battler, 2, 192
	createsprite \sprite, \anim_battler, 2, 224
	.endm

	.macro create_flying_sand_crescents anim_battler:req, unknown:req
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 10, 2304, 96, \unknown
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 90, 2048, 96, \unknown
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 50, 2560, 96, \unknown
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 20, 2304, 96, \unknown
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 70, 1984, 96, \unknown
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 0, 2816, 96, \unknown
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, \anim_battler, 40, 60, 2560, 96, \unknown
	.endm

	.macro create_overheat_flames anim_battler:req, y:req
	create_overheat_flame_sprite \anim_battler, 2, speed=1, unk1=0, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 2, speed=1, unk1=32, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 2, speed=1, unk1=64, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 2, speed=1, unk1=96, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 2, speed=1, unk1=128, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 66, speed=1, unk1=160, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 66, speed=1, unk1=192, unk2=30, duration=25, y=\y
	create_overheat_flame_sprite \anim_battler, 66, speed=1, unk1=224, unk2=30, duration=25, y=\y
	.endm

	.macro create_razor_leaf_cutters anim_battler=ANIM_TARGET, target_both:req
	create_razor_leaf_cutter_sprite \anim_battler, 3, initial_x=20, initial_y=-10, target_x=20, target_y=0, duration=22, wave_amplitude=20, target_both=\target_both
	create_razor_leaf_cutter_sprite \anim_battler, 3, initial_x=20, initial_y=-10, target_x=20, target_y=0, duration=22, wave_amplitude=-20, target_both=\target_both
	.endm

	.macro create_syrup_bomb_projectile anim_battler:req, sprite:req
	playsewithpan SE_M_BUBBLE3, SOUND_PAN_ATTACKER
	createsprite \sprite, \anim_battler, 2, 20, 0, 40, 0
	delay 3
	.endm

	.macro create_syrup_bomb anim_battler:req, projectile_sprite:req, blend_color:req, shell_sprite:req, particle_sprite:req
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	create_syrup_bomb_projectile anim_battler=\anim_battler, sprite=\projectile_sprite
	createvisualtask AnimTask_ShakeMon2, 5, \anim_battler, 3, 0, 15, 1
	blend_color_cycle selector=F_PAL_TARGET, delay=1, num_blends=2, initial_blend_y=0, target_blend_y=12, color=\blend_color
	createsprite \particle_sprite, \anim_battler, 2, 42, 27, 20
	createsprite \particle_sprite, \anim_battler, 2, -27, 44, 20
	createsprite \particle_sprite, \anim_battler, 2, 39, -28, 20
	createsprite \particle_sprite, \anim_battler, 2, -42, -42, 20
	playsewithpan SE_M_DIG, SOUND_PAN_TARGET
	delay 5
	createsprite \shell_sprite, \anim_battler, 1, \anim_battler, 100
	createsprite \particle_sprite, \anim_battler, 2, 0, 40, 20
	createsprite \particle_sprite, \anim_battler, 2, -8, -44, 20
	createsprite \particle_sprite, \anim_battler, 2, -46, -28, 20
	createsprite \particle_sprite, \anim_battler, 2, 46, 9, 20
	playsewithpan SE_M_DIG, SOUND_PAN_TARGET
	delay 5
	waitsound
	waitforvisualfinish
	.endm

	.macro create_syrup_bomb_speed_drop anim_battler:req, blend_color:req, sprite:req
	loopsewithpan SE_M_TOXIC, SOUND_PAN_TARGET, 13, 6
	createvisualtask AnimTask_ShakeMon2, 5, \anim_battler, 3, 0, 15, 1
	blend_color_cycle selector=F_PAL_TARGET, delay=1, num_blends=2, initial_blend_y=0, target_blend_y=12, color=\blend_color
	createsprite \sprite, \anim_battler, 1, \anim_battler, 60
	waitforvisualfinish
	.endm
