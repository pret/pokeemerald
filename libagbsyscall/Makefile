TOOLCHAIN := $(DEVKITARM)
COMPARE ?= 0

ifeq ($(CC),)
HOSTCC := gcc
else
HOSTCC := $(CC)
endif

ifeq ($(CXX),)
HOSTCXX := g++
else
HOSTCXX := $(CXX)
endif

ifneq (,$(wildcard $(TOOLCHAIN)/base_tools))
include $(TOOLCHAIN)/base_tools
else
export PATH := $(TOOLCHAIN)/bin:$(PATH)
PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
export CC := $(PREFIX)gcc
export AS := $(PREFIX)as
endif
export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
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
