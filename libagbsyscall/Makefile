TOOLCHAIN := $(DEVKITARM)
COMPARE ?= 0

# don't use dkP's base_tools anymore
# because the redefinition of $(CC) conflicts
# with when we want to use $(CC) to preprocess files
# thus, manually create the variables for the bin
# files, or use arm-none-eabi binaries on the system
# if dkP is not installed on this system

ifneq (,$(TOOLCHAIN))
ifneq ($(wildcard $(TOOLCHAIN)/bin),)
export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif
endif

PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
AS := $(PREFIX)as
LD := $(PREFIX)ld
AR := $(PREFIX)ar

# note: the makefile must be set up so MODERNCC is never called
# if MODERN=0
MODERNCC := $(PREFIX)gcc

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

# use arm-none-eabi-cpp for macOS
# as macOS's default compiler is clang
# and clang's preprocessor will warn on \u
# when preprocessing asm files, expecting a unicode literal
# we can't unconditionally use arm-none-eabi-cpp
# as installations which install binutils-arm-none-eabi
# don't come with it
ifneq ($(MODERN),1)
  ifeq ($(shell uname -s),Darwin)
    CPP := $(PREFIX)cpp
  else
    CPP := $(CC) -E
  endif
else
  CPP := $(PREFIX)cpp
endif

ASFLAGS := -mcpu=arm7tdmi
ARFLAGS := rc

SYSCALLS := ArcTan \
            ArcTan2 \
            BgAffineSet \
            BitUnPack \
            CpuFastSet \
            CpuSet \
            Diff16bitUnFilter \
            Diff8bitUnFilterVram \
            Diff8bitUnFilterWram \
            Div \
            DivArm \
            DivRem \
            DivRemArm \
            HuffUnComp \
            IntrWait \
            LZ77UnCompVram \
            LZ77UnCompWram \
            MidiKey2Freq \
            MultiBoot \
            MusicPlayerContinue \
            MusicPlayerFadeOut \
            MusicPlayerOpen \
            MusicPlayerStart \
            MusicPlayerStop \
            ObjAffineSet \
            RegisterRamReset \
            RLUnCompVram \
            RLUnCompWram \
            SoftReset \
            SoftResetExram \
            SoftResetRom \
            SoundBiasReset \
            SoundBiasSet \
            SoundChannelClear \
            SoundDriverInit \
            SoundDriverMain \
            SoundDriverMode \
            SoundDriverVSync \
            SoundDriverVSyncOff \
            SoundDriverVSyncOn \
            Sqrt \
            VBlankIntrWait

ASM_SRCS := libagbsyscall.s
ASM_OBJS := $(foreach syscall, $(SYSCALLS), $(syscall).o)

LIB := libagbsyscall.a

.PHONY: all clean

all: $(LIB)
	@:

clean:
	rm -f $(LIB) $(ASM_OBJS)

$(LIB): $(ASM_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(ASM_OBJS): libagbsyscall.s
	$(AS) $(ASFLAGS) --defsym L_$(*F)=1 -o $@ $<
