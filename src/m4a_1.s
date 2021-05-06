	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	.text

	thumb_func_start umul3232H32
umul3232H32:
	adr r2, __umul3232H32
	bx r2
	.arm
__umul3232H32:
	umull r2, r3, r0, r1
	add r0, r3, 0
	bx lr
	thumb_func_end umul3232H32

	thumb_func_start SoundMain
SoundMain:
	ldr r0, lt_SOUND_INFO_PTR
	ldr r0, [r0]
	ldr r2, lt_ID_NUMBER
	ldr r3, [r0, o_SoundInfo_ident]
	cmp r2, r3
	beq SoundMain_1
	bx lr @ Exit the function if ident doesn't match ID_NUMBER.
SoundMain_1:
	adds r3, 1
	str r3, [r0, o_SoundInfo_ident]
	push {r4-r7,lr}
	mov r1, r8
	mov r2, r9
	mov r3, r10
	mov r4, r11
	push {r0-r4}
	sub sp, 0x18
	ldrb r1, [r0, o_SoundInfo_maxLines]
	cmp r1, 0 @ if maxLines is 0, there is no maximum
	beq SoundMain_3
	ldr r2, lt_REG_VCOUNT
	ldrb r2, [r2]
	cmp r2, VCOUNT_VBLANK
	bhs SoundMain_2
	adds r2, TOTAL_SCANLINES
SoundMain_2:
	adds r1, r2
SoundMain_3:
	str r1, [sp, 0x14]
	ldr r3, [r0, o_SoundInfo_MPlayMainHead]
	cmp r3, 0
	beq SoundMain_4
	ldr r0, [r0, o_SoundInfo_musicPlayerHead]
	bl call_r3
	ldr r0, [sp, 0x18]
SoundMain_4:
	ldr r3, [r0, o_SoundInfo_CgbSound]
	bl call_r3
	ldr r0, [sp, 0x18]
	ldr r3, [r0, o_SoundInfo_pcmSamplesPerVBlank]
	mov r8, r3
	ldr r5, lt_o_SoundInfo_pcmBuffer
	adds r5, r0
	ldrb r4, [r0, o_SoundInfo_pcmDmaCounter]
	subs r7, r4, 1
	bls SoundMain_5
	ldrb r1, [r0, o_SoundInfo_pcmDmaPeriod]
	subs r1, r7
	mov r2, r8
	muls r2, r1
	adds r5, r2
SoundMain_5:
	str r5, [sp, 0x8]
	ldr r6, lt_PCM_DMA_BUF_SIZE
	ldr r3, lt_SoundMainRAM_Buffer
	bx r3

	.align 2, 0
lt_SOUND_INFO_PTR: .word SOUND_INFO_PTR
lt_ID_NUMBER:  .word ID_NUMBER
lt_SoundMainRAM_Buffer: .word SoundMainRAM_Buffer + 1
lt_REG_VCOUNT: .word REG_VCOUNT
lt_o_SoundInfo_pcmBuffer: .word o_SoundInfo_pcmBuffer
lt_PCM_DMA_BUF_SIZE:  .word PCM_DMA_BUF_SIZE

	.equ POKE_INIT, 1
	.equ DMA_FIX, 0
	.equ ENABLE_DECOMPRESSION, 1

	@ Stack variables
	.equ ARG_FRAME_LENGTH, 0x0 @ TODO: actually use this variable
	.equ ARG_REMAIN_CHN, 0x4  @ This is the channel count variable
	.equ ARG_BUFFER_POS, 0x8  @ stores the current output buffer pointer
	.equ ARG_LOOP_START_POS, 0xC  @ stores wave loop start position in channel loop
	.equ ARG_LOOP_LENGTH, 0x10 @ End position
	.equ ARG_BUFFER_POS_INDEX_HINT, 0x14
	.equ ARG_PCM_STRUCT, 0x18 @ pointer to engine the main work area

	@ Channel struct
	.equ CHN_STATUS, 0x0  @ [byte] Channel status bitfield
	.equ CHN_MODE, 0x1  @ [byte] Channel mode bitfield
	.equ CHN_VOL_1, 0x2 @ [byte] Volume right
	.equ CHN_VOL_2, 0x3 @ [byte] Volume left
	.equ CHN_ATTACK, 0x4  @ [byte] Wave attack summand
	.equ CHN_DECAY, 0x5 @ [byte] Wave decay factor
	.equ CHN_SUSTAIN, 0x6 @ [byte] Wave sustain level
	.equ CHN_RELEASE, 0x7 @ [byte] Wave release factor
	.equ CHN_ADSR_LEVEL, 0x9  @ [byte] Current envelope level
	.equ CHN_ECHO_VOL, 0xA  @ [byte] Pseudo echo volume
	.equ CHN_ECHO_REMAIN, 0xB @ [byte] Pseudo echo length
	.equ CHN_SAMPLE_COUNTDOWN, 0x18  @ [word] Sample countdown in mixing loop
	.equ CHN_FINE_POSITION, 0x1C  @ [word] Inter sample position (23 bits)
	.equ CHN_FREQUENCY, 0x20  @ [word] Sample rate (in Hz)
	.equ CHN_WAVE_OFFSET, 0x24 @ [word] Wave header pointer
	.equ CHN_POSITION_ABS, 0x28 @ [word] Points to the current position in the wave data (relative offset for compressed samples)
	.equ CHN_BLOCK_COUNT, 0x3C @ [word] Only used for compressed samples: contains the value of the block that is currently decoded

	@ Wave header struct
	.equ WAVE_LOOP_FLAG, 0x3  @ [byte] 0x0 = oneshot @ 0x40 = looped
	.equ WAVE_FREQ, 0x4 @ [word] pitch Adjustment value = mid-C samplerate * 1024
	.equ WAVE_LOOP_START, 0x8 @ [word] Loop start position
	.equ WAVE_LENGTH, 0xC @ [word] Loop end / wave end position
	.equ WAVE_DATA, 0x10  @ [byte array] Actual wave data

	@ Pulse wave synth configuration offset
	.equ SYNTH_BASE_WAVE_DUTY, 0x1 @ [byte]
	.equ SYNTH_WIDTH_CHANGE_1, 0x2 @ [byte]
	.equ SYNTH_MOD_AMOUNT, 0x3 @ [byte]
	.equ SYNTH_WIDTH_CHANGE_2, 0x4 @ [byte]

	@ CHN_STATUS flags - 0x0 = OFF
	.equ FLAG_CHN_INIT, 0x80  @ [bit] Write this value to init a channel
	.equ FLAG_CHN_RELEASE, 0x40 @ [bit] Write this value to release (fade out) the channel
	.equ FLAG_CHN_COMP, 0x20  @ [bit] Is wave being played compressed (yes/no)
	.equ FLAG_CHN_LOOP, 0x10  @ [bit] Loop (yes/no)
	.equ FLAG_CHN_ECHO, 0x4 @ [bit] Echo phase
	.equ FLAG_CHN_ATTACK, 0x3 @ [bit] Attack phase
	.equ FLAG_CHN_DECAY, 0x2  @ [bit] Decay phase
	.equ FLAG_CHN_SUSTAIN, 0x1 @ [bit] Sustain phase

	@ CHN_MODE flags
	.equ MODE_FIXED_FREQ, 0x8 @ [bit] Set to disable resampling (i.e. playback with output rate)
	.equ MODE_REVERSE, 0x10 @ [bit] Set to reverse sample playback
	.equ MODE_COMP, 0x30  @ [bit] Is wave being played compressed or reversed (TODO: rename flag)
	.equ MODE_SYNTH, 0x40 @ [bit] READ ONLY, indicates synthzied output

	@ Variables of the engine work area
	.equ VAR_REVERB, 0x5  @ [byte] 0-127 = Reverb level
	.equ VAR_MAX_CHN, 0x6 @ [byte] Maximum channels to process
	.equ VAR_MASTER_VOL, 0x7  @ [byte] PCM master volume
	.equ VAR_DEF_PITCH_FAC, 0x18  @ [word] This value gets multiplied with the samplerate for the inter sample distance
	.equ VAR_FIRST_CHN, 0x50  @ [CHN struct] Relative offset to channel array

	@ Just some more defines
	.equ REG_DMA3_SRC, 0x040000D4
	.equ ARM_OP_LEN, 0x4

	.syntax divided

	thumb_func_start SoundMainRAM
SoundMainRAM:
main_mixer:
	@ load Reverb level and check if we need to apply it
	ldrb r3, [r0, #VAR_REVERB]
	lsr	r3, r3, #2
	beq clear_buffer
	adr	r1, do_reverb
	bx r1

	.align 2
	.arm

do_reverb:
	@ Reverb is calculated by the following: new_sample = old_sample * reverb_level / 127
	@ Note that reverb is mono (both sides get mixed together)
	@ Reverb gets applied to the frame we are currently looking at and the one after that,
	@ the magic below simply calculates the pointer for the one after the current one.
	cmp	r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov	r4, r8
	orr	r3, r3, r3, lsl#16			
	stmfd sp!, {r8, lr}
	ldr	lr, hq_buffer
reverb_loop:
	@ This loop does the reverb processing
	ldrsb r0, [r5, r6]
	ldrsb r1, [r5], #1
	ldrsb r2, [r7, r6]
	ldrsb r8, [r7], #1
	ldrsb r9, [r5, r6]
	ldrsb r10, [r5], #1
	ldrsb r11, [r7, r6]
	ldrsb r12, [r7], #1
	add r0, r0, r1
	add r0, r0, r2
	adds r0, r0, r8
	addmi r0, r0, #0x4
	add r1, r9, r10
	add r1, r1, r11
	adds r1, r1, r12
	addmi r1, r1, #0x4
	mul r0, r3, r0
	mul r1, r3, r1
	stmia lr!, {r0, r1}
	subs r4, r4, #2
	bgt reverb_loop
	@ end of loop
	ldmfd sp!, {r8, lr}
	adr r0, (C_setup_channel_state_loop+1)
	bx r0

	.thumb
thumb_func_end SoundMain
clear_buffer:
	@ In case reverb is disabled the buffer gets set to zero
	ldr r3, hq_buffer
	mov r1, r8
	mov r4, #0
	mov r5, #0
	mov r6, #0
	mov r7, #0

	@ Setting the buffer to zero happens in a very efficient loop.
	@ Depending on the alignment of the buffer length, twice or quadruple the amount of bytes,
	@ get cleared at once.
	lsr r1, #3
	bcc C_clear_buffer_align_8
	stmia r3!, {r4, r5, r6, r7}
C_clear_buffer_align_8:
	lsr r1, #1
	bcc C_clear_buffer_align_16
	STMIA R3!, {R4, R5, R6, R7}
	STMIA R3!, {R4, R5, R6, R7}
C_clear_buffer_align_16:
	stmia r3!, {r4, r5, r6, r7}
	stmia r3!, {r4, r5, r6, r7}
	stmia r3!, {r4, r5, r6, r7}
	stmia r3!, {r4, r5, r6, r7}
	sub r1, #1
	bgt C_clear_buffer_align_16
	mov r1, #1
	strb r1, [r2]
	b C_setup_channel_state_loop

	.align  2
is_buffer_init:
	.byte 0x0

	.align 1

C_setup_channel_state_loop:

	@ Before the actual mixing starts,
	@ the volume and envelope calculation take place.

	mov r4, r8  @ r4 = buffer length

	@ This stroes the buffer length to a backup location

	str r4, [sp, #ARG_FRAME_LENGTH]
	@ init channel loop
	ldr r4, [sp, #ARG_PCM_STRUCT] @ r4 = main work area pointer
	ldr r0, [r4, #VAR_DEF_PITCH_FAC] @ r0 = samplingrate pitch factor
	mov r12, r0
	ldrb r0, [r4, #VAR_MAX_CHN]
	add r4, #VAR_FIRST_CHN @ R4 = Base channel Offset (Channel #0)
C_channel_state_loop:
	@ This is the main channel processing loop:
	str r0, [sp, #ARG_REMAIN_CHN]
	ldr r3, [r4, #CHN_WAVE_OFFSET]
	ldrb r6, [r4, #CHN_STATUS] @ r6 will hold the channel status
	movs r0, #0xC7  @ check if any of the channel status flags is set
	tst r0, r6 @ check if none of the flags is set
	beq C_skip_channel
	@ check channel flags
	lsl r0, r6, #25  @ shift over the FLAG_CHN_INIT to CARRY
	bcc C_adsr_echo_check @ continue with normal channel procedure
	@ check leftmost bit
	bmi C_stop_channel @ FLAG_CHN_INIT | FLAG_CHN_RELEASE -> stop directly
	@ channel init procedure
	movs r6, #FLAG_CHN_ATTACK
	movs r0, r3 @ r0 = CHN_WAVE_OFFSET
	add r0, #WAVE_DATA @ r0 = wave data offset

	@ Pokémon games seem to init channels differently than other m4a games
.if POKE_INIT==0
	str r0, [r4, #CHN_POSITION_ABS]
	ldr r0, [r3, #WAVE_LENGTH]
	str r0, [r4, #CHN_SAMPLE_COUNTDOWN]
.else
	ldr r1, [r4, #CHN_SAMPLE_COUNTDOWN]
	add r0, r0, r1
	str r0, [r4, #CHN_POSITION_ABS]
	ldr r0, [r3, #WAVE_LENGTH]
	sub r0, r0, r1
	str r0, [r4, #CHN_SAMPLE_COUNTDOWN]
.endif

	movs r5, #0 @ initial envelope = #0
	strb r5, [r4, #CHN_ADSR_LEVEL]
	str r5, [r4, #CHN_FINE_POSITION]
	ldrb r2, [r3, #WAVE_LOOP_FLAG]
	lsr r0, r2, #6
	beq C_adsr_attack
	@ loop enabled here
	movs r0, #FLAG_CHN_LOOP
	orr r6, r0
	b C_adsr_attack
C_adsr_echo_check:
	@ this is the normal ADSR procedure without init
	ldrb r5, [r4, #CHN_ADSR_LEVEL]
	lsl r0, r6, #29  @ FLAG_CHN_ECHO --> bit 31 (sign bit)
	bpl C_adsr_release_check
	@ pseudo echo handler
	ldrb r0, [r4, #CHN_ECHO_REMAIN]
	sub r0, #1
	strb r0, [r4, #CHN_ECHO_REMAIN]
	bhi C_channel_vol_calc @ continue normal if channel is still on
C_stop_channel:
	movs r0, #0
	strb r0, [r4, #CHN_STATUS]
C_skip_channel:
	@ Go to end of the channel loop
	b C_end_channel_state_loop
C_adsr_release_check:
	lsl r0, r6, #25 @ FLAG_CHN_RELEASE --> bit 31 (sign bit)
	bpl C_adsr_decay_check
	@ release handler
	ldrb r0, [r4, #CHN_RELEASE]
	@sub r0, #0xFF @ Linear decay @ TODO: make option for triggering it
	@sub r0, #1
	@add r5, r5, r0
	mul r5, r5, r0
	lsr r5, #8
	ble C_adsr_released
	@ pseudo echo init handler
	ldrb r0, [r4, #CHN_ECHO_VOL]
	cmp r5, r0
	bhi C_channel_vol_calc
C_adsr_released:
	@ if volume released to #0
	ldrb r5, [r4, #CHN_ECHO_VOL]
	cmp r5, #0
	beq C_stop_channel
	@ pseudo echo volume handler
	movs r0, #FLAG_CHN_ECHO
	orr r6, r0 @ set the echo flag
	b C_adsr_save_and_finalize
C_adsr_decay_check:
	@ check if decay is active
	movs r2, #(FLAG_CHN_DECAY+FLAG_CHN_SUSTAIN)
	and r2, r6
	cmp r2, #FLAG_CHN_DECAY
	bne C_adsr_attack_check  @ Decay not active yet
	@ decay handler
	ldrb r0, [r4, #CHN_DECAY]
	mul r5, r5, r0
	lsr r5, r5, #8
	ldrb r0, [r4, #CHN_SUSTAIN]
	cmp r5, r0
	bhi C_channel_vol_calc @ Sample didn't decay yet
	@ sustain handler
	movs r5, r0 @ Current level = sustain level
	beq C_adsr_released  @ sustain level #0 --> branch
	@ step to next phase otherweise
	b C_adsr_next_state
C_adsr_attack_check:
	@ attack handler
	cmp r2, #FLAG_CHN_ATTACK
	bne C_channel_vol_calc @ If it isn't in attack attack phase, it has to be in sustain (keep vol) --> branch
C_adsr_attack:
	@ apply attack summand
	ldrb r0, [r4, #CHN_ATTACK]
	add r5, r0
	cmp r5, #0xFF
	blo C_adsr_save_and_finalize
	@ cap attack at 0xFF
	movs r5, #0xFF
C_adsr_next_state:
	@ switch to next adsr phase
	sub r6, #1
C_adsr_save_and_finalize:
	@ store channel status
	strb r6, [r4, #CHN_STATUS]
C_channel_vol_calc:
	@ store the calculated ADSR level
	strb r5, [r4, #CHN_ADSR_LEVEL]
	@ apply master volume
	ldr r0, [sp, #ARG_PCM_STRUCT]
	ldrb r0, [r0, #VAR_MASTER_VOL]
	add r0, #1
	mul r5, r0
	@ left side volume
	ldrb r0, [r4, #CHN_VOL_2]
	mul r0, r5
	lsr r0, #13
	mov r10, r0  @ r10 = Left volume
	@ right side volume
	ldrb r0, [r4, #CHN_VOL_1]
	mul r0, r5
	lsr r0, #13
	mov r11, r0  @ r11 = Right volume

	@ Now we get closer to actual mixing:
	@ For looped samples some additional operations are required

	movs r0, #FLAG_CHN_LOOP
	and r0, r6
	beq C_skip_sample_loop_setup
	@ loop setup handler
	add r3, #WAVE_LOOP_START
	ldmia r3!, {r0, r1}  @ r0 = loop start, r1 = loop end
	add r3, r0 @ r3 = loop start position (absolute)
	str r3, [sp, #ARG_LOOP_START_POS]
	sub r0, r1, r0

C_skip_sample_loop_setup:
	@ do the rest of the setup
	str r0, [sp, #ARG_LOOP_LENGTH]  @ if loop is off --> r0 = 0x0
	ldr r5, hq_buffer
	ldr r2, [r4, #CHN_SAMPLE_COUNTDOWN]
	ldr r3, [r4, #CHN_POSITION_ABS]
	ldrb r0, [r4, #CHN_MODE]
	adr r1, C_mixing_setup
	bx r1

	.align 2

hq_buffer:
	.word hq_buffer_ptr

	.arm
	.align 2

C_mixing_setup:
	@ frequency and mixing loading routine
	ldr r8, [sp, #ARG_FRAME_LENGTH]
	orrs r11, r11, r10, lsl#16 @ r11 = 00LL00RR
	beq C_mixing_epilogue @ volume #0 --> branch and skip channel processing
	@ normal processing otherwise
	tst r0, #MODE_FIXED_FREQ
	bne C_setup_fixed_freq_mixing
	tst r0, #MODE_COMP
	bne C_setup_special_mixing  @ compressed? --> branch
	stmfd sp!, {r4, r9, r12}

	@ This mixer supports 4 different kind of synthesized sounds.
	@ They are triggered if there is no samples to play.
	@ This gets checked below:
	movs r2, r2
	orreq r0, r0, #MODE_SYNTH
	streqb  r0, [r4, #CHN_MODE]
	add r4, r4, #CHN_FINE_POSITION
	ldmia r4, {r7, lr} @ r7 = Fine Position, lr = Frequency
	mul r4, lr, r12  @ r4 = inter sample steps = output rate factor * samplerate
	@ now the first samples get loaded
	ldrsb r6, [r3], #1
	ldrsb r12, [r3]
	tst r0, #MODE_SYNTH
	bne C_setup_synth
	@ In case no synth mode should be used, code contiues here
	sub r12, r12, r6 @ r12 = DELTA

	@ Mixing goes with volume ranges 0-127
	@ They come in 0-255 --> divide by 2
	movs r11, r11, lsr#1
	adc r11, r11, #0x8000
	bic r11, r11, #0xff00
	mov r1, r7 @ r1 = inter sample position

	@ There is 2 different mixing codepaths for uncompressed data
	@ Path 1: fast mixing, but doesn't supports loop or stop
	@ Path 2: not so fast but supports sample loops / stop
	@ This checks if there is enough samples aviable for path 1.
	@ Important: r0 is expected to be #0.
	umlal r1, r0, r4, r8
	mov r1, r1, lsr#23
	orr r0, r1, r0, lsl#9
	cmp r2, r0 @ actual comparison
	ble C_setup_unbuffered_mixing @ If not enough samples are available for path 1 --> branch

	@ This is the mixer path 1.
	@ The interesting thing here is that the code will
	@ buffer enough samples on stack if enough space
	@ on stack is available (or goes over the limit of 0x400 bytes)
	sub r2, r2, r0
	ldr r10, upper_stack_bounds
	add r10, r10, r0
	cmp r10, sp
	add r10, r3, r0

	@ r2 = Remaining samples after processing
	@ r10 = Final sample position
	@ sp = Original stack location
	@ These values will get reloaded after channel processing
	@ due to the lack of registers.
	stmfd sp!, {r2, r10}
	cmpcc r0, #0x400 @ > 0x400 bytes --> read directly from ROM rather than buffered
	mov r10, sp
	bcs C_select_highspeed_codepath

	@ The code below inits the DMA to read word aligned
	@ samples from ROM to stack.
	bic r1, r3, #3
	mov r9, #0x04000000
	add r9, r9, #0xD4
	add r0, r0, #7
	mov r0, r0, lsr#2
	sub sp, sp, r0, lsl#2
	and r3, r3, #3
	add r3, r3, sp
	orr lr, r0, #0x84000000
	stmia r9, {r1, sp, lr} @ Actually starts the DMA

	@ Is needed for some games not to break
.if DMA_FIX==1
	mov r0, #0
	mov r1, #0
	mov r2, #0
	stmia r9, {r0, r1, r2}
.endif

C_select_highspeed_codepath:
	stmfd sp!, {r10} @ Save original sp for VLA
	
	@ This code decides which piece of code to load
	@ depending on playback-rate / default-rate ratio.
	@ Modes > 1.0 run with different volume levels.
	@ r4 = inter sample step
	adr r0, high_speed_code_resource @ Loads the base pointer of the code
	subs r4, r4, #0x800000
	movpl r11, r11, lsl#1  @ if >= 1.0* 0-127 --> 0-254 volume level
	addpl r0, r0, #(ARM_OP_LEN*6)  @ 6 instructions further
	subpls  r4, r4, #0x800000 @ if >= 2.0*
	addpl r0, r0, #(ARM_OP_LEN*6)
	addpl r4, r4, #0x800000
	ldr r2, previous_fast_code
	cmp r0, r2 @ Code doesn't need to be reloaded if it's already in place
	beq C_skip_fast_mixing_creation
	@ This loads the needed code to RAM
	str r0, previous_fast_code
	ldmia r0, {r0-r2, r8-r10}  @ load 6 opcodes
	adr lr, fast_mixing_instructions
C_fast_mixing_creation_loop:

	@ Paste code to destination, see below for patterns:
	stmia lr, {r0, r1}
	add lr, lr, #(ARM_OP_LEN*38)
	stmia lr, {r0, r1}
	sub lr, lr, #(ARM_OP_LEN*35)
	stmia lr, {r2, r8-r10}
	add lr, lr, #(ARM_OP_LEN*38)
	stmia lr, {r2, r8-r10}
	sub lr, lr, #(ARM_OP_LEN*32)
	adds r5, r5, #0x40000000  @ do that for 4 blocks
	bcc C_fast_mixing_creation_loop
	ldr r8, [sp]  @ Restore r8 with the frame length
	ldr r8, [r8, #(ARG_FRAME_LENGTH + 0x8 + 0xC)]
C_skip_fast_mixing_creation:
	mov r2, #0xFF000000  @ Load the fine position overflow bitmask
C_fast_mixing_loop:

	@ This is the actual processing and interpolation code loop. 
	@ Nops will be replaced by the code above.
	ldmia r5, {r0, r1, r10, lr} @ load 4 stereo samples to Registers
	mul r9, r7, r12
fast_mixing_instructions:
	nop @ Block #1
	nop
	mlane r0, r11, r9, r0
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	mulne r9, r7, r12
	nop @ Block #2
	nop
	mlane r1, r11, r9, r1
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	mulne r9, r7, r12
	nop @ Block #3
	nop
	mlane r10, r11, r9, r10
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	mulne r9, r7, r12
	nop @ Block #4
	nop
	mlane lr, r11, r9, lr
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	stmia r5!, {r0, r1, r10, lr}  @ Write 4 stereo samples
	ldmia r5, {r0, r1, r10, lr} @ Load the next 4 stereo samples
	mulne r9, r7, r12
	nop @ Block #1
	nop
	mlane r0, r11, r9, r0
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	mulne r9, r7, r12
	nop @ Block #2
	nop
	mlane r1, r11, r9, r1
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	mulne r9, r7, r12
	nop @ Block #3
	nop
	mlane r10, r11, r9, r10
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	mulne r9, r7, r12
	nop @ Block #4
	nop
	mlane lr, r11, r9, lr
	nop
	nop
	nop
	nop
	bic r7, r7, r2, asr#1
	stmia r5!, {r0, r1, r10, lr}  @ write 4 stereo samples
	subs r8, r8, #8
	bgt C_fast_mixing_loop
	@ restore previously saved values
	ldmfd sp, {sp}  @ Reload original stack pointer from VLA
	ldmfd sp!, {r2, r3}
	b C_end_mixing

@ Various variables for the cached mixer
	.align 2

upper_stack_bounds:
	.word 0x03007910
previous_fast_code:
	.word 0x0 @ Mark as invalid initially

@ These instructions are used by the high speed loop self modifying code.
high_speed_code_resource:
	@ Block for Mix Freq < 1.0 * Output Frequency
	mov r9, r9, asr#22
	adds r9, r9, r6, lsl#1
	adds r7, r7, r4
	addpl r6, r12, r6
	ldrplsb r12, [r3, #1]!
	subpls  r12, r12, r6
	@ Block for Mix Freq > 1.0 AND < 2.0 * Output Frequency
	adds r9, r6, r9, asr#23
	add r6, r12, r6
	adds r7, r7, r4
	ldrplsb r6, [r3, #1]!
	ldrsb r12, [r3, #1]!
	subs r12, r12, r6
	@ Block for Mix Freq > 2.0 * Output Frequency
	adds r9, r6, r9, asr#23
	add r7, r7, r4
	add r3, r3, r7, lsr#23
	ldrsb r6, [r3]
	ldrsb r12, [r3, #1]!
	subs r12, r12, r6
@ In case a loop or end occurs during mixing, this code is used
C_setup_unbuffered_mixing:
	add r5, r5, r8, lsl#2 @ r5 = End of HQ buffer
@ This below is the unbuffered mixing loop. r6 = base sample, r12 diff to next
C_unbuffered_mixing_loop:
	mul r9, r7, r12
	mov r9, r9, asr#22
	adds r9, r9, r6, lsl#1
	ldrne r0, [r5, -r8, lsl#2]
	mlane r0, r11, r9, r0
	strne r0, [r5, -r8, lsl#2]
	add r7, r7, r4
	movs r9, r7, lsr#23
	beq C_unbuffered_mixing_skip_load @ Skip the mixing load if it isn't required
	subs r2, r2, r7, lsr#23
	blle C_mixing_loop_or_end
	subs r9, r9, #1
	addeq r6, r12, r6
	@ Return location from loop handler
	ldrnesb r6, [r3, r9]!
	ldrsb r12, [r3, #1]!
	sub r12, r12, r6
	bic r7, r7, #0x3F800000
C_unbuffered_mixing_skip_load:
	subs r8, r8, #1 @ Reduce the sample count for the buffer by #1
	bgt C_unbuffered_mixing_loop
C_end_mixing:
	sub r3, r3, #1 @ Because the mixer always needs 1 byte lookahead, this reverts it
	ldmfd sp!, {r4, r9, r12}
	str r7, [r4, #CHN_FINE_POSITION]
	b C_mixing_end_store
C_mixing_loop_or_end:
	@ This loads the loop information end loops incase it should
	add r3, sp, #ARG_LOOP_START_POS+0xC
	ldmia r3, {r3, r6} @ r3 = Loop Start @ r6 = loop length
	cmp r6, #0 @ Check if loop is enabled @ If loop is enabled r6 is != 0
	rsbne r9, r2, #0 @ Loop wraparound logic
	addne r2, r6, r2
	addne pc, lr, #(ARM_OP_LEN*2)
	ldmfd sp!, {r4, r9, r12}
	b C_mixing_end_and_stop_channel @ R6 == 0 (always)
C_fixed_mixing_loop_or_end:
	ldr r2, [sp, #ARG_LOOP_LENGTH+0x8]
	movs r6, r2 @ Copy it to r6 and check whether loop is disabled
	ldrne r3, [sp, #ARG_LOOP_START_POS+0x8]
	bxne lr @ If it loops, return to mixing function if it doesn't go on end mixing
	ldmfd sp!, {r4, r9}
C_mixing_end_and_stop_channel:
	strb r6, [r4]  @ update channel flag with chn halt
	B C_mixing_epilogue
@ These are used for the fixed freq mixer
fixed_mixing_code_resource:
	movs r6, r10, lsl#24
	movs r6, r6, asr#24
	movs r6, r10, lsl#16
	movs r6, r6, asr#24
	movs r6, r10, lsl#8
	movs r6, r6, asr#24
	movs r6, r10, asr#24
	ldmia r3!, {r10} @ Load chunk of samples
	movs r6, r10, lsl#24
	movs r6, r6, asr#24
	movs r6, r10, lsl#16
	movs r6, r6, asr#24
	movs r6, r10, lsl#8
	movs r6, r6, asr#24
	ldmfd sp!, {r4, r9, r12}
C_setup_fixed_freq_mixing:
	stmfd sp!, {r4, r9}
C_fixed_mixing_length_check:
	mov lr, r2 @ Sample countdown
	cmp r2, r8
	movgt lr, r8 @ Min(buffer_size, sample_countdown)
	sub lr, lr, #1
	movs lr, lr, lsr#2
	beq C_fixed_mixing_process_rest @ <= 3 samples to process
	sub r8, r8, lr, lsl#2 @ Subtract the amount of samples we need to process from the buffer length
	sub r2, r2, lr, lsl#2 @ Subtract the amount of samples we need to process from the remaining samples
	adr r1, fixed_mixing_instructions
	adr r0, fixed_mixing_code_resource
	mov r9, r3, lsl#30
	add r0, r0, r9, lsr#27 @ Alignment * 8 + resource offset = new resource offset
	ldmia r0!, {r6, r7, r9, r10}  @ load and write instructions
	stmia r1, {r6, r7}
	add r1, r1, #0xc
	stmia r1, {r9, r10}
	add r1, r1, #0xc
	ldmia r0, {r6, r7, r9, r10}
	stmia r1, {r6, r7}
	add r1, r1, #0xc
	stmia r1, {r9, r10}
	ldmia r3!, {r10} @ load 4 samples from ROM
C_fixed_mixing_loop:
	ldmia r5, {r0, r1, r7, r9} @ Load 4 samples from hq buffer
fixed_mixing_instructions:
	nop
	nop
	mlane r0, r11, r6, r0  @ add new sample if neccessary
	nop
	nop
	mlane r1, r11, r6, r1
	nop
	nop
	mlane r7, r11, r6, r7
	nop
	nop
	mlane r9, r11, r6, r9
	stmia r5!, {r0, r1, r7, r9} @ Write samples to the mixing buffer
	subs lr, lr, #1
	bne C_fixed_mixing_loop
	sub r3, r3, #4 @ We'll need to load this block again, so rewind a bit
C_fixed_mixing_process_rest:
	mov r1, #4 @ Repeat the loop #4 times to completely get rid of alignment errors
C_fixed_mixing_unaligned_loop:
	ldr r0, [r5]
	ldrsb r6, [r3], #1
	mla r0, r11, r6, r0
	str r0, [r5], #4
	subs r2, r2, #1
	bleq C_fixed_mixing_loop_or_end
	subs r1, r1, #1
	bgt C_fixed_mixing_unaligned_loop
	subs r8, r8, #4
	bgt C_fixed_mixing_length_check @ Repeat the mixing procedure until the buffer is filled
	ldmfd sp!, {r4, r9}
C_mixing_end_store:
	str r2, [r4, #CHN_SAMPLE_COUNTDOWN]
	str r3, [r4, #CHN_POSITION_ABS]
C_mixing_epilogue:
	adr r0, (C_end_channel_state_loop+1)
	bx r0

	.thumb

C_end_channel_state_loop:
	ldr r0, [sp, #ARG_REMAIN_CHN]
	sub r0, #1
	ble C_main_mixer_return
	add r4, #0x40
	b C_channel_state_loop
C_main_mixer_return:
	adr r5, V_noise_shape
	ldrb r4, [r5, #0] @ left noise shape
	lsl r4, r4, #16
	ldrb r5, [r5, #1] @ right noise shape
	lsl r5, r5, #16
	adr r0, C_downsampler
	bx r0
V_noise_shape:
	.byte 0, 0

	.arm
	.align 2

C_downsampler:
	ldr r8, [sp, #ARG_FRAME_LENGTH]
	ldr r9, [sp, #ARG_BUFFER_POS]
	LDR R10, hq_buffer
	mov r11, #0xFF000000
	mov lr, #0xC0000000
C_downsampler_loop:
	ldmia r10, {r0, r1, r2, r3}
	add r12, r4, r0  @ Left sample #1
	adds r4, r12, r12
	eorvs r12, lr, r4, asr#31
	and r4, r12, #0x007F0000
	and r6, r11, r12, lsl#1
	add r0, r5, r0, lsl#16  @ Right
	adds r5, r0, r0
	eorvs r0, lr, r5, asr#31
	and r5, r0, #0x007F0000
	and r7, r11, r0, lsl#1
	add r12, r4, r1  @ Left sample #2
	adds r4, r12, r12
	eorvs r12, lr, r4, asr#31
	and r4, r12, #0x007F0000
	and r12, r11, r12, lsl#1
	orr r6, r12, r6, lsr#8
	add r1, r5, r1, lsl#16  @ Right
	adds r5, r1, r1
	eorvs r1, lr, r5, asr#31
	and r5, r1, #0x007F0000
	and r1, r11, r1, lsl#1
	orr r7, r1, r7, lsr#8
	add r12, r4, r2  @ Left sample #3
	adds r4, r12, r12
	eorvs r12, lr, r4, asr#31
	and r4, r12, #0x007F0000
	and r12, r11, r12, lsl#1
	orr r6, r12, r6, lsr#8
	add r2, r5, r2, lsl#16  @ Right
	adds r5, r2, r2
	eorvs r2, lr, r5, asr#31
	and r5, r2, #0x007F0000
	and r2, r11, r2, lsl#1
	orr r7, r2, r7, lsr#8
	add r12, r4, r3  @ Left sample #4
	adds r4, r12, r12
	eorvs r12, lr, r4, asr#31
	and r4, r12, #0x007F0000
	and r12, r11, r12, lsl#1
	orr r6, r12, r6, lsr#8
	add r3, r5, r3, lsl#16  @ Right
	adds r5, r3, r3
	eorvs r3, lr, r5, asr#31
	and r5, r3, #0x007F0000
	and r3, r11, r3, lsl#1
	orr r7, r3, r7, lsr#8
	mov r0, #0x31
	str r6, [r9, r0, lsl#5]
	str r7, [r9], #4
	mov r0, #0
	mov r1, #0
	mov r2, #0
	mov r3, #0
	stmia r10!, {r0, r1, r2, r3}
	subs r8, #4
	bgt C_downsampler_loop
	adr r1, V_noise_shape
	adr r0, (C_downsampler_return+1)
	bx r0

	.pool

	.align 1
	.thumb

C_downsampler_return:
	lsr r4, #16
	strb r4, [r1, #0]
	lsr r5, #16
	strb r5, [r1, #1]
	ldr r0, [sp, #ARG_PCM_STRUCT]
	ldr r3, mixer_finished_status @ This is used to indicate the interrupt handler that the rendering was finished properly
	str r3, [r0]
	add sp, sp, #0x1C
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
	bx r3

	.align 2

mixer_finished_status:
	.word 0x68736D53

	.arm
	.align 2

C_setup_synth:
	cmp r12, #0
	bne C_check_synth_saw
	@ Modulating pulse wave
	ldrb r6, [r3, #SYNTH_WIDTH_CHANGE_1]
	add r2, r2, r6, lsl#24
	ldrb r6, [r3, #SYNTH_WIDTH_CHANGE_2]
	adds r6, r2, r6, lsl#24
	mvnmi r6, r6
	mov r10, r6, lsr#8
	ldrb r1, [r3, #SYNTH_MOD_AMOUNT]
	ldrb r0, [r3, #SYNTH_BASE_WAVE_DUTY]
	mov r0, r0, lsl#24
	mla r6, r10, r1, r0  @ Calculate the final duty cycle with the offset, and intensity, rotating the duty cycle amount
	stmfd sp!, {r2, r3, r9, r12}
C_synth_pulse_loop:
	ldmia r5, {r0-r3, r9, r10, r12, lr} @ load 8 samples
	cmp r7, r6 @ block #1
	addlo r0, r0, r11, lsl#6
	subhs r0, r0, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #2
	addlo r1, r1, r11, lsl#6
	subhs r1, r1, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #3
	addlo r2, r2, r11, lsl#6
	subhs r2, r2, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #4
	addlo r3, r3, r11, lsl#6
	subhs r3, r3, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #5
	addlo r9, r9, r11, lsl#6
	subhs r9, r9, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #6
	addlo r10, r10, r11, lsl#6
	subhs r10, r10, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #7
	addlo r12, r12, r11, lsl#6
	subhs r12, r12, r11, lsl#6
	adds r7, r7, r4, lsl#3
	cmp r7, r6 @ block #8
	addlo lr, lr, r11, lsl#6
	subhs lr, lr, r11, lsl#6
	adds r7, r7, r4, lsl#3
	stmia r5!, {r0-r3, r9, r10, r12, lr} @ write 8 samples
	subs r8, r8, #8
	bgt C_synth_pulse_loop
	ldmfd sp!, {r2, r3, r9, r12}
	b C_end_mixing
C_check_synth_saw:
	@ This is actually not a true saw wave
	@ but looks pretty similar

	subs r12, r12, #1
	bne C_synth_triangle
	mov r6, #0x300
	mov r11, r11, lsr#1
	bic r11, r11, #0xFF00
	mov r12, #0x70
C_synth_saw_loop:
	ldmia r5, {r0, r1, r10, lr} @ load 4 samples from memory
	adds r7, r7, r4, lsl#3 @ Block #1 (some oscillator type code)
	rsb r9, r12, r7, lsr#24
	mov r6, r7, lsl#1
	sub r9, r9, r6, lsr#27
	adds r2, r9, r2, asr#1
	mlane r0, r11, r2, r0
	adds r7, r7, r4, lsl#3 @ Block #2
	rsb r9, r12, r7, lsr#24
	mov r6, r7, lsl#1
	sub r9, r9, r6, lsr#27
	adds r2, r9, r2, asr#1
	mlane r1, r11, r2, r1
	adds r7, r7, r4, lsl#3 @ Block #3
	rsb r9, r12, r7, lsr#24
	mov r6, r7, lsl#1
	sub r9, r9, r6, lsr#27
	adds r2, r9, r2, asr#1
	mlane r10, r11, r2, r10
	adds r7, r7, r4, lsl#3 @ Block #4
	rsb r9, r12, r7, lsr#24
	mov r6, r7, lsl#1
	sub r9, r9, r6, lsr#27
	adds r2, r9, r2, asr#1
	mlane lr, r11, r2, lr
	stmia r5!, {r0, r1, r10, lr}
	subs r8, r8, #4
	bgt C_synth_saw_loop
	B C_end_mixing
C_synth_triangle:
	mov r6, #0x80
	mov r12, #0x180
C_synth_triangle_loop:
	ldmia r5, {r0, r1, r10, lr} @ load samples from work buffer
	adds r7, r7, r4, lsl#3 @ block #1
	rsbpl r9, r6, r7, asr#23
	submi r9, r12, r7, lsr#23
	mla r0, r11, r9, r0
	adds r7, r7, r4, lsl#3 @ block #2
	rsbpl r9, r6, r7, asr#23
	submi r9, r12, r7, lsr#23
	mla r1, r11, r9, r1
	adds r7, r7, r4, lsl#3 @ block #3
	rsbpl r9, r6, r7, asr#23
	submi r9, r12, r7, lsr#23
	mla r10, r11, r9, r10
	adds r7, r7, r4, lsl#3 @ block #4
	rsbpl r9, r6, r7, asr#23
	submi r9, r12, r7, lsr#23
	mla lr, r11, r9, lr
	stmia r5!, {r0, r1, r10, lr}
	subs r8, r8, #4 @ subtract #4 from the remainging samples
	bgt C_synth_triangle_loop
	b C_end_mixing

.if ENABLE_DECOMPRESSION==1
C_setup_special_mixing:
	ldr r6, [r4, #CHN_WAVE_OFFSET]
	ldrb r0, [r4]
	tst r0, #FLAG_CHN_COMP
	bne C_setup_special_mixing_freq @ skip the setup procedure if it's running in compressed mode already
	orr r0, #FLAG_CHN_COMP
	strb r0, [r4]
	ldrb r0, [r4, #CHN_MODE]
	tst r0, #MODE_REVERSE
	beq C_check_compression  @ reversed mode not enabled?
	ldr r1, [r6, #WAVE_LENGTH]  @ calculate seek position for reverse playback
	add r1, r1, r6, lsl#1 @ I don't actually understand that piece of code myself
	add r1, r1, #0x20
	sub r3, r1, r3
	str r3, [r4, #CHN_POSITION_ABS]
C_check_compression:
	ldrh r0, [r6]
	cmp r0, #0
	beq C_setup_special_mixing_freq
	sub r3, r3, r6
	sub r3, r3, #0x10
	str r3, [r4, #CHN_POSITION_ABS]
C_setup_special_mixing_freq:
	ldr r0, [r6, #WAVE_LOOP_START]
	str r0, [sp, #ARG_LOOP_START_POS]
	STMFD SP!, {R4, R9, R12}
	movs r11, r11, lsr#1
	adc r11, r11, #0x8000
	bic r11, r11, #0xFF00
	ldr r7, [r4, #CHN_FINE_POSITION]
	ldr r1, [r4, #CHN_FREQUENCY]
	ldrb r0, [r4, #CHN_MODE]
	tst r0, #MODE_FIXED_FREQ
	movne r1, #0x800000
	muleq r1, r12, r1  @ default rate factor * frequency = sample steps
	add r5, r5, r8, lsl#2 @ set the buffer pointer to the end of the channel, same as slow mixing mode
	ldrh r0, [r6]
	cmp r0, #0
	beq C_uncompressed_reverse_mixing_check
	mov r0, #0xFF000000  @ --> invalid channel mod
	str r0, [r4, #CHN_BLOCK_COUNT]
	ldrb r0, [r4, #CHN_MODE]
	tst r0, #MODE_REVERSE
	bne C_setup_compressed_reverse_mixing  @ check again of reverse mixing is enabled
	@ Forward compressed mixing
	bl  F_bdpcm_decoder
	mov r6, r12
	add r3, r3, #1
	bl  F_bdpcm_decoder
	sub r12, r12, r6

	@***** MIXING LOOP REGISTER USAGE ***********@
	@ r0: Sample to modify from buffer
	@ r1: Sample steps (moved from r4)
	@ r2: Remaining samples before loop/end
	@ r3: Sample position
	@ r4: Channel pointer
	@ r5: Pointer to the end of buffer
	@ r6: Base sample
	@ r7: Fine position
	@ r8: Remaining samples for current buffer
	@ r9: Interpolated sample
	@ r10: Not used
	@ r11: Volume
	@ r12: Delta sample
	@ lr: Not used
	@********************************************@

C_compressed_mixing_loop:
	mul r9, r7, r12  @ check slow mixing for details, same procedure here
	mov r9, r9, asr#22
	adds r9, r9, r6, lsl#1
	ldrne r0, [r5, -r8, lsl#2]
	mlane r0, r11, r9, r0
	strne r0, [r5, -r8, lsl#2]
	add r7, r7, r1 @ ### changed from r4 to r1
	movs r9, r7, lsr#23
	beq C_compressed_mixing_skip_load
	subs r2, r2, r7, lsr#23
	blle C_mixing_loop_or_end
	subs r9, r9, #1
	addeq r6, r12, r6
	beq C_compressed_mixing_skip_base_load
	add r3, r3, r9 @ equivalent to ldrnesb r6, [r3, r9]!
	bl  F_bdpcm_decoder
	mov r6, r12
C_compressed_mixing_skip_base_load:
	add r3, r3, #1 @ equivalent to ldrsb r12, [r3, #1]!
	bl  F_bdpcm_decoder
	sub r12, r12, r6
	bic r7, r7, #0x3F800000
C_compressed_mixing_skip_load:
	subs r8, r8, #1
	bgt C_compressed_mixing_loop
	B C_end_mixing
C_setup_compressed_reverse_mixing:
	sub r3, r3, #1
	bl  F_bdpcm_decoder
	mov r6, r12
	sub r3, r3, #1
	bl  F_bdpcm_decoder
	sub r12, r12, r6
C_compressed_reverse_mixing_loop:
	mul r9, r7, r12
	mov r9, r9, asr#22
	adds r9, r9, r6, lsl#1
	ldrne r0, [r5, -r8, lsl#2]
	mlane r0, r11, r9, r0
	strne r0, [r5, -r8, lsl#2]
	add r7, r7, r1 @ ### changed from r4 to r1
	movs r9, r7, lsr#23
	beq C_compressed_reverse_mixing_skip_load
	subs r2, r2, r7, lsr#23
	blle C_mixing_loop_or_end
	subs r9, r9, #1
	addeq r6, r12, r6
	beq C_compressed_reverse_mixing_skip_base_load
	sub r3, r3, r9
	bl  F_bdpcm_decoder
	mov r6, r12
C_compressed_reverse_mixing_skip_base_load:
	sub r3, r3, #1
	bl  F_bdpcm_decoder
	sub r12, r12, r6
	bic r7, r7, #0x3F800000
C_compressed_reverse_mixing_skip_load:
	subs r8, r8, #1
	bgt C_compressed_reverse_mixing_loop
	add r3, r3, #3
	b C_end_mixing
C_uncompressed_reverse_mixing_check:
	ldrb r0, [r4, #1]
	tst r0, #MODE_REVERSE @ check if reverse mode is even enabled (consistency)
	beq C_end_mixing
	ldrsb r6, [r3, #-1]!
	ldrsb r12, [r3, #-1]
	sub r12, r12, r6
C_uncompressed_reverse_mixing_loop:
	mul r9, r7, r12
	mov r9, r9, asr#22
	adds r9, r9, r6, lsl#1
	ldrne r0, [r5, -r8, lsl#2]
	mlane r0, r11, r9, r0
	strne r0, [r5, -r8, lsl#2]
	add r7, r7, r1 @ ### changed from r4 to r1
	movs r9, r7, lsr#23
	beq C_uncompressed_reverse_mixing_load_skip
	subs r2, r2, r7, lsr#23
	blle C_mixing_loop_or_end
	movs r9, r9
	addeq r6, r12, r6
	ldrnesb r6, [r3, -r9]!
	ldrsb r12, [r3, #-1]
	sub r12, r12, r6
	bic r7, r7, #0x3F800000
C_uncompressed_reverse_mixing_load_skip:
	subs r8, r8, #1
	bgt C_uncompressed_reverse_mixing_loop
	add r3, r3, #2
	b C_end_mixing
	
	@ This is the main BDPCM Decoder.
	@ It decodes and caches a block of PCM data
	@ and returns them in r12
F_bdpcm_decoder:
	stmfd sp!, {r0, lr}
	mov r0, r3, lsr#6  @ clip off everything but the block offset, each block is 0x40 samples long
	ldr r12, [r4, #CHN_BLOCK_COUNT]
	cmp r0, r12
	beq C_bdpcm_decoder_return @ block already decoded -> skip
	stmfd sp!, {r2, r5-r7}
	str r0, [r4, #CHN_BLOCK_COUNT]
	mov r12, #0x21 @ 1 block = 0x21 bytes, 0x40 decoded samples
	mul r2, r12, r0
	ldr r12, [r4, #CHN_WAVE_OFFSET]
	add r2, r2, r12  @ calc block rom position
	add r2, r2, #0x10
	ldr r5, decoder_buffer
	adr r6, delta_lookup_table
	mov r7, #0x40  @ 1 block  = 0x40 samples
	ldrb lr, [r2], #1
	strb lr, [r5], #1
	ldrb r12, [r2], #1
	b C_bdpcm_decoder_lsb
C_bdpcm_decoder_msb:
	ldrb r12, [r2], #1
	mov r0, r12, lsr#4
	ldrsb r0, [r6, r0]
	add lr, lr, r0
	strb lr, [r5], #1
C_bdpcm_decoder_lsb:
	and r0, r12, #0xf
	ldrsb r0, [r6, r0]
	add lr, lr, r0
	strb lr, [r5], #1
	subs r7, r7, #2
	bgt C_bdpcm_decoder_msb
	ldmfd sp!, {r2, r5-r7}
C_bdpcm_decoder_return:
	ldr r12, decoder_buffer
	and r0, r3, #0x3f
	ldrsb r12, [r12, r0]
	ldmfd sp!, {r0, pc}

	.align 2

decoder_buffer:
	.word gUnknown_03001300

delta_lookup_table:
	.byte 0x0, 0x1, 0x4, 0x9, 0x10, 0x19, 0x24, 0x31, 0xC0, 0xCF, 0xDC, 0xE7, 0xF0, 0xF7, 0xFC, 0xFF

.endif  @ ENABLE_DECOMPRESSION*/

main_mixer_end:
	.syntax unified

	thumb_func_start SoundMainBTM
SoundMainBTM:
	mov r12, r4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	movs r4, 0
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	mov r4, r12
	bx lr
	thumb_func_end SoundMainBTM

	thumb_func_start RealClearChain
RealClearChain:
	ldr r3, [r0, 0x2C]
	cmp r3, 0
	beq _081DD5E2
	ldr r1, [r0, 0x34]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq _081DD5D6
	str r1, [r2, 0x34]
	b _081DD5D8
_081DD5D6:
	str r1, [r3, 0x20]
_081DD5D8:
	cmp r1, 0
	beq _081DD5DE
	str r2, [r1, 0x30]
_081DD5DE:
	movs r1, 0
	str r1, [r0, 0x2C]
_081DD5E2:
	bx lr
	thumb_func_end RealClearChain

	thumb_func_start ply_fine
ply_fine:
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq ply_fine_done
ply_fine_loop:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq ply_fine_ok
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
ply_fine_ok:
	adds r0, r4, 0
	bl RealClearChain
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne ply_fine_loop
ply_fine_done:
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ply_fine

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy:
	mov r12, lr
	movs r1, 0x24
	ldr r2, lt_MPlayJumpTableTemplate
MPlayJumpTableCopy_Loop:
	ldr r3, [r2]
	bl chk_adr_r2
	stm r0!, {r3}
	adds r2, 0x4
	subs r1, 0x1
	bgt MPlayJumpTableCopy_Loop
	bx r12
	thumb_func_end MPlayJumpTableCopy

	.align 2, 0

	.thumb_func
ldrb_r3_r2:
	ldrb r3, [r2]

@ This attempts to protect against reading anything from the BIOS ROM
@ besides the jump table template.
@ It assumes that the jump table template is located at the end of the ROM.
	.thumb_func
chk_adr_r2:
	push {r0}
	lsrs r0, r2, 25
	bne chk_adr_r2_done @ if adr >= 0x2000000 (i.e. not in BIOS ROM), accept it
	ldr r0, lt_MPlayJumpTableTemplate
	cmp r2, r0
	blo chk_adr_r2_reject @ if adr < gMPlayJumpTableTemplate, reject it
	lsrs r0, r2, 14
	beq chk_adr_r2_done @ if adr < 0x40000 (i.e. in BIOS ROM), accept it
chk_adr_r2_reject:
	movs r3, 0
chk_adr_r2_done:
	pop {r0}
	bx lr

	.align 2, 0

lt_MPlayJumpTableTemplate: .word gMPlayJumpTableTemplate

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i:
	ldr r2, [r1, 0x40]
_081DD64A:
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	b chk_adr_r2
	thumb_func_end ld_r3_tp_adr_i

	thumb_func_start ply_goto
ply_goto:
	push {lr}
ply_goto_1:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	ldrb r3, [r2, 0x2]
	orrs r0, r3
	lsls r0, 8
	ldrb r3, [r2, 0x1]
	orrs r0, r3
	lsls r0, 8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0
	thumb_func_end ply_goto

	thumb_func_start ply_patt
ply_patt:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 3
	bhs ply_patt_done
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r2, 0x4
	str r2, [r3, o_MusicPlayerTrack_patternStack]
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	adds r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	b ply_goto
ply_patt_done:
	b ply_fine
	thumb_func_end ply_patt

	thumb_func_start ply_pend
ply_pend:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 0
	beq ply_pend_done
	subs r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r3, o_MusicPlayerTrack_patternStack]
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
ply_pend_done:
	bx lr
	thumb_func_end ply_pend

	thumb_func_start ply_rept
ply_rept:
	push {lr}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0
	bne ply_rept_1
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b ply_goto_1
ply_rept_1:
	ldrb r3, [r1, o_MusicPlayerTrack_repN]
	adds r3, 1
	strb r3, [r1, o_MusicPlayerTrack_repN]
	mov r12, r3
	bl ld_r3_tp_adr_i
	cmp r12, r3
	bhs ply_rept_2
	b ply_goto_1
ply_rept_2:
	movs r3, 0
	strb r3, [r1, o_MusicPlayerTrack_repN]
	adds r2, 5
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0
	thumb_func_end ply_rept

	thumb_func_start ply_prio
ply_prio:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_priority]
	bx r12
	thumb_func_end ply_prio

	thumb_func_start ply_tempo
ply_tempo:
	mov r12, lr
	bl ld_r3_tp_adr_i
	lsls r3, 1
	strh r3, [r0, o_MusicPlayerInfo_tempoD]
	ldrh r2, [r0, o_MusicPlayerInfo_tempoU]
	muls r3, r2
	lsrs r3, 8
	strh r3, [r0, o_MusicPlayerInfo_tempoI]
	bx r12
	thumb_func_end ply_tempo

	thumb_func_start ply_keysh
ply_keysh:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_keyShift]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_keysh

	thumb_func_start ply_voice
ply_voice:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 2
	ldr r3, [r0, o_MusicPlayerInfo_tone]
	adds r2, r3
	ldr r3, [r2]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_type]
	ldr r3, [r2, 0x4]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_wav]
	ldr r3, [r2, 0x8]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_attack]
	bx r12
	thumb_func_end ply_voice

	thumb_func_start ply_vol
ply_vol:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_vol]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_vol

	thumb_func_start ply_pan
ply_pan:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_pan]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_pan

	thumb_func_start ply_bend
ply_bend:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_bend]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_bend

	thumb_func_start ply_bendr
ply_bendr:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_bendRange]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_bendr

	thumb_func_start ply_lfodl
ply_lfodl:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_lfoDelay]
	bx r12
	thumb_func_end ply_lfodl

	thumb_func_start ply_modt
ply_modt:
	mov r12, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, o_MusicPlayerTrack_modT]
	cmp r0, r3
	beq _081DD7AA
	strb r3, [r1, o_MusicPlayerTrack_modT]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xF
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
_081DD7AA:
	bx r12
	thumb_func_end ply_modt

	thumb_func_start ply_tune
ply_tune:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_tune]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_tune

	thumb_func_start ply_port
ply_port:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	ldr r0, =REG_SOUND1CNT_L @ sound register base address
	adds r0, r3
	bl _081DD64A
	strb r3, [r0]
	bx r12
	.pool
	thumb_func_end ply_port

	thumb_func_start m4aSoundVSync
m4aSoundVSync:
	ldr r0, lt2_SOUND_INFO_PTR
	ldr r0, [r0]

	@ Exit the function if ident is not ID_NUMBER or ID_NUMBER+1.
	ldr r2, lt2_ID_NUMBER
	ldr r3, [r0, o_SoundInfo_ident]
	subs r3, r2
	cmp r3, 1
	bhi m4aSoundVSync_Done

	@ Decrement the PCM DMA counter. If it reaches 0, we need to do a DMA.
	ldrb r1, [r0, o_SoundInfo_pcmDmaCounter]
	subs r1, 1
	strb r1, [r0, o_SoundInfo_pcmDmaCounter]
	bgt m4aSoundVSync_Done

	@ Reload the PCM DMA counter.
	ldrb r1, [r0, o_SoundInfo_pcmDmaPeriod]
	strb r1, [r0, o_SoundInfo_pcmDmaCounter]

	ldr r2, =REG_DMA1

	ldr r1, [r2, 0x8] @ DMA1CNT
	lsls r1, 7
	bcc m4aSoundVSync_SkipDMA1 @ branch if repeat bit isn't set

	ldr r1, =((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4
	str r1, [r2, 0x8] @ DMA1CNT

m4aSoundVSync_SkipDMA1:
	ldr r1, [r2, 0xC + 0x8] @ DMA2CNT
	lsls r1, 7
	bcc m4aSoundVSync_SkipDMA2 @ branch if repeat bit isn't set

	ldr r1, =((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4
	str r1, [r2, 0xC + 0x8] @ DMA2CNT

m4aSoundVSync_SkipDMA2:

	@ turn off DMA1/DMA2
	movs r1, DMA_32BIT >> 8
	lsls r1, 8
	strh r1, [r2, 0xA] @ DMA1CNT_H
	strh r1, [r2, 0xC + 0xA] @ DMA2CNT_H

	@ turn on DMA1/DMA2 direct-sound FIFO mode
	movs r1, (DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT) >> 8
	lsls r1, 8 @ LSB is 0, so DMA_SRC_INC is used (destination is always fixed in FIFO mode)
	strh r1, [r2, 0xA] @ DMA1CNT_H
	strh r1, [r2, 0xC + 0xA] @ DMA2CNT_H

m4aSoundVSync_Done:
	bx lr

	.pool
	thumb_func_end m4aSoundVSync

	thumb_func_start MPlayMain
MPlayMain:
	ldr r2, lt2_ID_NUMBER
	ldr r3, [r0, o_MusicPlayerInfo_ident]
	cmp r2, r3
	beq _081DD82E
	bx lr
_081DD82E:
	adds r3, 0x1
	str r3, [r0, o_MusicPlayerInfo_ident]
	push {r0,lr}
	ldr r3, [r0, o_MusicPlayerInfo_func]
	cmp r3, 0
	beq _081DD840
	ldr r0, [r0, o_MusicPlayerInfo_intp]
	bl call_r3
_081DD840:
	pop {r0}
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	adds r7, r0, 0
	ldr r0, [r7, o_MusicPlayerInfo_status]
	cmp r0, 0
	bge _081DD858
	b _081DDA6C
_081DD858:
	ldr r0, lt2_SOUND_INFO_PTR
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, 0
	bl FadeOutBody
	ldr r0, [r7, o_MusicPlayerInfo_status]
	cmp r0, 0
	bge _081DD86C
	b _081DDA6C
_081DD86C:
	ldrh r0, [r7, o_MusicPlayerInfo_tempoC]
	ldrh r1, [r7, o_MusicPlayerInfo_tempoI]
	adds r0, r1
	b _081DD9BC
_081DD874:
	ldrb r6, [r7, o_MusicPlayerInfo_trackCount]
	ldr r5, [r7, o_MusicPlayerInfo_tracks]
	movs r3, 0x1
	movs r4, 0
_081DD87C:
	ldrb r0, [r5]
	movs r1, 0x80
	tst r1, r0
	bne _081DD886
	b _081DD998
_081DD886:
	mov r10, r3
	orrs r4, r3
	mov r11, r4
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq _081DD8BA
_081DD892:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _081DD8AE
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _081DD8B4
	subs r0, 0x1
	strb r0, [r4, 0x10]
	bne _081DD8B4
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
	b _081DD8B4
_081DD8AE:
	adds r0, r4, 0
	bl ClearChain
_081DD8B4:
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _081DD892
_081DD8BA:
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x40
	tst r0, r3
	beq _081DD938
	adds r0, r5, 0
	bl Clear64byte
	movs r0, 0x80
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, o_MusicPlayerTrack_bendRange]
	movs r0, 0x40
	strb r0, [r5, o_MusicPlayerTrack_volX]
	movs r0, 0x16
	strb r0, [r5, o_MusicPlayerTrack_lfoSpeed]
	movs r0, 0x1
	adds r1, r5, 0x6
	strb r0, [r1, o_MusicPlayerTrack_ToneData_type - 0x6]
	b _081DD938
_081DD8E0:
	ldr r2, [r5, o_MusicPlayerTrack_cmdPtr]
	ldrb r1, [r2]
	cmp r1, 0x80
	bhs _081DD8EC
	ldrb r1, [r5, o_MusicPlayerTrack_runningStatus]
	b _081DD8F6
_081DD8EC:
	adds r2, 0x1
	str r2, [r5, o_MusicPlayerTrack_cmdPtr]
	cmp r1, 0xBD
	bcc _081DD8F6
	strb r1, [r5, o_MusicPlayerTrack_runningStatus]
_081DD8F6:
	cmp r1, 0xCF
	bcc _081DD90C
	mov r0, r8
	ldr r3, [r0, o_SoundInfo_plynote]
	adds r0, r1, 0
	subs r0, 0xCF
	adds r1, r7, 0
	adds r2, r5, 0
	bl call_r3
	b _081DD938
_081DD90C:
	cmp r1, 0xB0
	bls _081DD92E
	adds r0, r1, 0
	subs r0, 0xB1
	strb r0, [r7, o_MusicPlayerInfo_cmd]
	mov r3, r8
	ldr r3, [r3, o_SoundInfo_MPlayJumpTable]
	lsls r0, 2
	ldr r3, [r3, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl call_r3
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	cmp r0, 0
	beq _081DD994
	b _081DD938
_081DD92E:
	ldr r0, lt_gClockTable
	subs r1, 0x80
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r5, o_MusicPlayerTrack_wait]
_081DD938:
	ldrb r0, [r5, o_MusicPlayerTrack_wait]
	cmp r0, 0
	beq _081DD8E0
	subs r0, 0x1
	strb r0, [r5, o_MusicPlayerTrack_wait]
	ldrb r1, [r5, o_MusicPlayerTrack_lfoSpeed]
	cmp r1, 0
	beq _081DD994
	ldrb r0, [r5, o_MusicPlayerTrack_mod]
	cmp r0, 0
	beq _081DD994
	ldrb r0, [r5, o_MusicPlayerTrack_lfoDelayC]
	cmp r0, 0
	beq _081DD95A
	subs r0, 0x1
	strb r0, [r5, o_MusicPlayerTrack_lfoDelayC]
	b _081DD994
_081DD95A:
	ldrb r0, [r5, o_MusicPlayerTrack_lfoSpeedC]
	adds r0, r1
	strb r0, [r5, o_MusicPlayerTrack_lfoSpeedC]
	adds r1, r0, 0
	subs r0, 0x40
	lsls r0, 24
	bpl _081DD96E
	lsls r2, r1, 24
	asrs r2, 24
	b _081DD972
_081DD96E:
	movs r0, 0x80
	subs r2, r0, r1
_081DD972:
	ldrb r0, [r5, o_MusicPlayerTrack_mod]
	muls r0, r2
	asrs r2, r0, 6
	ldrb r0, [r5, o_MusicPlayerTrack_modM]
	eors r0, r2
	lsls r0, 24
	beq _081DD994
	strb r2, [r5, o_MusicPlayerTrack_modM]
	ldrb r0, [r5]
	ldrb r1, [r5, o_MusicPlayerTrack_modT]
	cmp r1, 0
	bne _081DD98E
	movs r1, 0xC
	b _081DD990
_081DD98E:
	movs r1, 0x3
_081DD990:
	orrs r0, r1
	strb r0, [r5, o_MusicPlayerTrack_flags]
_081DD994:
	mov r3, r10
	mov r4, r11
_081DD998:
	subs r6, 0x1
	ble _081DD9A4
	movs r0, 0x50
	adds r5, r0
	lsls r3, 1
	b _081DD87C
_081DD9A4:
	ldr r0, [r7, o_MusicPlayerInfo_clock]
	adds r0, 0x1
	str r0, [r7, o_MusicPlayerInfo_clock]
	cmp r4, 0
	bne _081DD9B6
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, o_MusicPlayerInfo_status]
	b _081DDA6C
_081DD9B6:
	str r4, [r7, o_MusicPlayerInfo_status]
	ldrh r0, [r7, o_MusicPlayerInfo_tempoC]
	subs r0, 0x96
_081DD9BC:
	strh r0, [r7, o_MusicPlayerInfo_tempoC]
	cmp r0, 0x96
	bcc _081DD9C4
	b _081DD874
_081DD9C4:
	ldrb r2, [r7, o_MusicPlayerInfo_trackCount]
	ldr r5, [r7, o_MusicPlayerInfo_tracks]
_081DD9C8:
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	movs r1, 0x80
	tst r1, r0
	beq _081DDA62
	movs r1, 0xF
	tst r1, r0
	beq _081DDA62
	mov r9, r2
	adds r0, r7, 0
	adds r1, r5, 0
	bl TrkVolPitSet
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq _081DDA58
_081DD9E6:
	ldrb r1, [r4, o_SoundChannel_statusFlags]
	movs r0, 0xC7
	tst r0, r1
	bne _081DD9F6
	adds r0, r4, 0
	bl ClearChain
	b _081DDA52
_081DD9F6:
	ldrb r0, [r4, o_SoundChannel_type]
	movs r6, 0x7
	ands r6, r0
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x3
	tst r0, r3
	beq _081DDA14
	bl ChnVolSetAsm
	cmp r6, 0
	beq _081DDA14
	ldrb r0, [r4, o_CgbChannel_modify]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, o_CgbChannel_modify]
_081DDA14:
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0xC
	tst r0, r3
	beq _081DDA52
	ldrb r1, [r4, o_CgbChannel_key]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _081DDA28
	movs r2, 0
_081DDA28:
	cmp r6, 0
	beq _081DDA46
	mov r0, r8
	ldr r3, [r0, o_SoundInfo_MidiKeyToCgbFreq]
	adds r1, r2, 0
	ldrb r2, [r5, o_MusicPlayerTrack_pitM]
	adds r0, r6, 0
	bl call_r3
	str r0, [r4, o_CgbChannel_frequency]
	ldrb r0, [r4, o_CgbChannel_modify]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, o_CgbChannel_modify]
	b _081DDA52
_081DDA46:
	adds r1, r2, 0
	ldrb r2, [r5, o_MusicPlayerTrack_pitM]
	ldr r0, [r4, o_SoundChannel_wav]
	bl MidiKeyToFreq
	str r0, [r4, o_SoundChannel_frequency]
_081DDA52:
	ldr r4, [r4, o_SoundChannel_nextChannelPointer]
	cmp r4, 0
	bne _081DD9E6
_081DDA58:
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	movs r1, 0xF0
	ands r0, r1
	strb r0, [r5, o_MusicPlayerTrack_flags]
	mov r2, r9
_081DDA62:
	subs r2, 0x1
	ble _081DDA6C
	movs r0, 0x50
	adds r5, r0
	bgt _081DD9C8
_081DDA6C:
	ldr r0, lt2_ID_NUMBER
	str r0, [r7, o_MusicPlayerInfo_ident]
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}

call_r3:
	bx r3

	.align 2, 0
lt_gClockTable: .word gClockTable
lt2_SOUND_INFO_PTR: .word SOUND_INFO_PTR
lt2_ID_NUMBER:  .word ID_NUMBER
	thumb_func_end MPlayMain

	thumb_func_start TrackStop
TrackStop:
	push {r4-r6,lr}
	adds r5, r1, 0
	ldrb r1, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x80
	tst r0, r1
	beq TrackStop_Done
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq TrackStop_3
	movs r6, 0
TrackStop_Loop:
	ldrb r0, [r4, o_SoundChannel_statusFlags]
	cmp r0, 0
	beq TrackStop_2
	ldrb r0, [r4, o_SoundChannel_type]
	movs r3, 0x7
	ands r0, r3
	beq TrackStop_1
	ldr r3, =SOUND_INFO_PTR
	ldr r3, [r3]
	ldr r3, [r3, o_SoundInfo_CgbOscOff]
	bl call_r3
TrackStop_1:
	strb r6, [r4, o_SoundChannel_statusFlags]
TrackStop_2:
	str r6, [r4, o_SoundChannel_track]
	ldr r4, [r4, o_SoundChannel_nextChannelPointer]
	cmp r4, 0
	bne TrackStop_Loop
TrackStop_3:
	str r4, [r5, o_MusicPlayerTrack_chan]
TrackStop_Done:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TrackStop

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm:
	ldrb r1, [r4, 0x12]
	movs r0, 0x14
	ldrsb r2, [r4, r0]
	movs r3, 0x80
	adds r3, r2
	muls r3, r1
	ldrb r0, [r5, 0x10]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls _081DDAE8
	movs r0, 0xFF
_081DDAE8:
	strb r0, [r4, 0x2]
	movs r3, 0x7F
	subs r3, r2
	muls r3, r1
	ldrb r0, [r5, 0x11]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls _081DDAFC
	movs r0, 0xFF
_081DDAFC:
	strb r0, [r4, 0x3]
	bx lr
	thumb_func_end ChnVolSetAsm

	thumb_func_start ply_note
ply_note:
	push {r4-r7,lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	sub sp, 0x18
	str r1, [sp]
	adds r5, r2, 0
	ldr r1, =SOUND_INFO_PTR
	ldr r1, [r1]
	str r1, [sp, 0x4]
	ldr r1, =gClockTable
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r5, o_MusicPlayerTrack_gateTime]
	ldr r3, [r5, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r3]
	cmp r0, 0x80
	bhs _081DDB46
	strb r0, [r5, o_MusicPlayerTrack_key]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bhs _081DDB44
	strb r0, [r5, o_MusicPlayerTrack_velocity]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bhs _081DDB44
	ldrb r1, [r5, o_MusicPlayerTrack_gateTime]
	adds r1, r0
	strb r1, [r5, o_MusicPlayerTrack_gateTime]
	adds r3, 0x1
_081DDB44:
	str r3, [r5, o_MusicPlayerTrack_cmdPtr]
_081DDB46:
	movs r0, 0
	str r0, [sp, 0x14]
	adds r4, r5, 0
	adds r4, o_MusicPlayerTrack_ToneData_type
	ldrb r2, [r4]
	movs r0, TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL
	tst r0, r2
	beq _081DDB98
	ldrb r3, [r5, o_MusicPlayerTrack_key]
	movs r0, TONEDATA_TYPE_SPL
	tst r0, r2
	beq _081DDB66
	ldr r1, [r5, o_MusicPlayerTrack_ToneData_keySplitTable]
	adds r1, r3
	ldrb r0, [r1]
	b _081DDB68
_081DDB66:
	adds r0, r3, 0
_081DDB68:
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, [r5, o_MusicPlayerTrack_ToneData_wav]
	adds r1, r0
	mov r9, r1
	mov r6, r9
	ldrb r1, [r6]
	movs r0, 0xC0
	tst r0, r1
	beq _081DDB80
	b _081DDCEA
_081DDB80:
	movs r0, 0x80
	tst r0, r2
	beq _081DDB9C
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	beq _081DDB94
	subs r1, 0xC0
	lsls r1, 1
	str r1, [sp, 0x14]
_081DDB94:
	ldrb r3, [r6, 0x1]
	b _081DDB9C
_081DDB98:
	mov r9, r4
	ldrb r3, [r5, 0x5]
_081DDB9C:
	str r3, [sp, 0x8]
	ldr r6, [sp]
	ldrb r1, [r6, 0x9]
	ldrb r0, [r5, 0x1D]
	adds r0, r1
	cmp r0, 0xFF
	bls _081DDBAC
	movs r0, 0xFF
_081DDBAC:
	str r0, [sp, 0x10]
	mov r6, r9
	ldrb r0, [r6]
	movs r6, 0x7
	ands r6, r0
	str r6, [sp, 0xC]
	beq _081DDBEC
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
	cmp r4, 0
	bne _081DDBC4
	b _081DDCEA
_081DDBC4:
	subs r6, 0x1
	lsls r0, r6, 6
	adds r4, r0
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _081DDC40
	movs r0, 0x40
	tst r0, r1
	bne _081DDC40
	ldrb r1, [r4, 0x13]
	ldr r0, [sp, 0x10]
	cmp r1, r0
	bcc _081DDC40
	beq _081DDBE4
	b _081DDCEA
_081DDBE4:
	ldr r0, [r4, 0x2C]
	cmp r0, r5
	bcs _081DDC40
	b _081DDCEA
_081DDBEC:
	ldr r6, [sp, 0x10]
	adds r7, r5, 0
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x4]
	ldrb r3, [r4, 0x6]
	adds r4, 0x50
_081DDBFA:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _081DDC40
	movs r0, 0x40
	tst r0, r1
	beq _081DDC14
	cmp r2, 0
	bne _081DDC18
	adds r2, 0x1
	ldrb r6, [r4, 0x13]
	ldr r7, [r4, 0x2C]
	b _081DDC32
_081DDC14:
	cmp r2, 0
	bne _081DDC34
_081DDC18:
	ldrb r0, [r4, 0x13]
	cmp r0, r6
	bcs _081DDC24
	adds r6, r0, 0
	ldr r7, [r4, 0x2C]
	b _081DDC32
_081DDC24:
	bhi _081DDC34
	ldr r0, [r4, 0x2C]
	cmp r0, r7
	bls _081DDC30
	adds r7, r0, 0
	b _081DDC32
_081DDC30:
	bcc _081DDC34
_081DDC32:
	mov r8, r4
_081DDC34:
	adds r4, 0x40
	subs r3, 0x1
	bgt _081DDBFA
	mov r4, r8
	cmp r4, 0
	beq _081DDCEA
_081DDC40:
	adds r0, r4, 0
	bl ClearChain
	movs r1, 0
	str r1, [r4, 0x30]
	ldr r3, [r5, 0x20]
	str r3, [r4, 0x34]
	cmp r3, 0
	beq _081DDC54
	str r4, [r3, 0x30]
_081DDC54:
	str r4, [r5, 0x20]
	str r5, [r4, 0x2C]
	ldrb r0, [r5, 0x1B]
	strb r0, [r5, 0x1C]
	cmp r0, r1
	beq _081DDC66
	adds r1, r5, 0
	bl clear_modM
_081DDC66:
	ldr r0, [sp]
	adds r1, r5, 0
	bl TrkVolPitSet
	ldr r0, [r5, 0x4]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	strb r0, [r4, 0x13]
	ldr r0, [sp, 0x8]
	strb r0, [r4, 0x8]
	ldr r0, [sp, 0x14]
	strb r0, [r4, 0x14]
	mov r6, r9
	ldrb r0, [r6]
	strb r0, [r4, 0x1]
	ldr r7, [r6, 0x4]
	str r7, [r4, 0x24]
	ldr r0, [r6, 0x8]
	str r0, [r4, 0x4]
	ldrh r0, [r5, 0x1E]
	strh r0, [r4, 0xC]
	bl ChnVolSetAsm
	ldrb r1, [r4, 0x8]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _081DDCA0
	movs r3, 0
_081DDCA0:
	ldr r6, [sp, 0xC]
	cmp r6, 0
	beq _081DDCCE
	mov r6, r9
	ldrb r0, [r6, 0x2]
	strb r0, [r4, 0x1E]
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	bne _081DDCBA
	movs r0, 0x70
	tst r0, r1
	bne _081DDCBC
_081DDCBA:
	movs r1, 0x8
_081DDCBC:
	strb r1, [r4, 0x1F]
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	ldr r0, [sp, 0xC]
	ldr r3, [sp, 0x4]
	ldr r3, [r3, 0x30]
	bl call_r3
	b _081DDCDC
_081DDCCE:
	ldr r0, [r5, o_MusicPlayerTrack_unk_3C]
	str r0, [r4, 0x18]
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	adds r0, r7, 0
	bl MidiKeyToFreq
_081DDCDC:
	str r0, [r4, 0x20]
	movs r0, 0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, 0xF0
	ands r0, r1
	strb r0, [r5]
_081DDCEA:
	add sp, 0x18
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r0}
	bx r0
	.pool
	thumb_func_end ply_note

	thumb_func_start ply_endtie
ply_endtie:
	push {r4,r5}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0x80
	bhs _081DDD16
	strb r3, [r1, o_MusicPlayerTrack_key]
	adds r2, 0x1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b _081DDD18
_081DDD16:
	ldrb r3, [r1, o_MusicPlayerTrack_key]
_081DDD18:
	ldr r1, [r1, o_MusicPlayerTrack_chan]
	cmp r1, 0
	beq _081DDD40
	movs r4, 0x83
	movs r5, 0x40
_081DDD22:
	ldrb r2, [r1, o_SoundChannel_statusFlags]
	tst r2, r4
	beq _081DDD3A
	tst r2, r5
	bne _081DDD3A
	ldrb r0, [r1, o_SoundChannel_midiKey]
	cmp r0, r3
	bne _081DDD3A
	movs r0, 0x40
	orrs r2, r0
	strb r2, [r1, o_SoundChannel_statusFlags]
	b _081DDD40
_081DDD3A:
	ldr r1, [r1, o_SoundChannel_nextChannelPointer]
	cmp r1, 0
	bne _081DDD22
_081DDD40:
	pop {r4,r5}
	bx lr
	thumb_func_end ply_endtie

	thumb_func_start clear_modM
clear_modM:
	movs r2, 0
	strb r2, [r1, o_MusicPlayerTrack_modM]
	strb r2, [r1, o_MusicPlayerTrack_lfoSpeedC]
	ldrb r2, [r1, o_MusicPlayerTrack_modT]
	cmp r2, 0
	bne _081DDD54
	movs r2, 0xC
	b _081DDD56
_081DDD54:
	movs r2, 0x3
_081DDD56:
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx lr
	thumb_func_end clear_modM

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i_unchecked:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r3, r2, 1
	str r3, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	bx lr
	thumb_func_end ld_r3_tp_adr_i

	thumb_func_start ply_lfos
ply_lfos:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_lfoSpeed]
	cmp r3, 0
	bne _081DDD7C
	bl clear_modM
_081DDD7C:
	bx r12
	thumb_func_end ply_lfos

	thumb_func_start ply_mod
ply_mod:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_mod]
	cmp r3, 0
	bne _081DDD90
	bl clear_modM
_081DDD90:
	bx r12
	thumb_func_end ply_mod

	.align 2, 0 @ Don't pad with nop.

    .bss
gUnknown_03001300:
    .space 0x40
    .size gUnknown_03001300, .-gUnknown_03001300

    .global gMPlayTrack_BGM
gMPlayTrack_BGM:
    .space 0x500
    .size gMPlayTrack_BGM, .-gMPlayTrack_BGM

    .global gMPlayTrack_SE1
gMPlayTrack_SE1:
    .space 0xF0
    .size gMPlayTrack_SE1, .-gMPlayTrack_SE1

    .global gMPlayTrack_SE2
gMPlayTrack_SE2:
    .space 0x370
    .size gMPlayTrack_SE2, .-gMPlayTrack_SE2

    .global gMPlayTrack_SE3
gMPlayTrack_SE3:
    .space 0x50
    .size gMPlayTrack_SE3, .-gMPlayTrack_SE3