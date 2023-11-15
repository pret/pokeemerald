#ifndef GUARD_GBA_IO_REG_H
#define GUARD_GBA_IO_REG_H

#define REG_BASE 0x4000000 // I/O register base address

// I/O register offsets

#define REG_OFFSET_DISPCNT     0x0
#define REG_OFFSET_DISPSTAT    0x4
#define REG_OFFSET_VCOUNT      0x6
#define REG_OFFSET_BG0CNT      0x8
#define REG_OFFSET_BG1CNT      0xa
#define REG_OFFSET_BG2CNT      0xc
#define REG_OFFSET_BG3CNT      0xe
#define REG_OFFSET_BG0HOFS     0x10
#define REG_OFFSET_BG0VOFS     0x12
#define REG_OFFSET_BG1HOFS     0x14
#define REG_OFFSET_BG1VOFS     0x16
#define REG_OFFSET_BG2HOFS     0x18
#define REG_OFFSET_BG2VOFS     0x1a
#define REG_OFFSET_BG3HOFS     0x1c
#define REG_OFFSET_BG3VOFS     0x1e
#define REG_OFFSET_BG2PA       0x20
#define REG_OFFSET_BG2PB       0x22
#define REG_OFFSET_BG2PC       0x24
#define REG_OFFSET_BG2PD       0x26
#define REG_OFFSET_BG2X        0x28
#define REG_OFFSET_BG2X_L      0x28
#define REG_OFFSET_BG2X_H      0x2a
#define REG_OFFSET_BG2Y        0x2c
#define REG_OFFSET_BG2Y_L      0x2c
#define REG_OFFSET_BG2Y_H      0x2e
#define REG_OFFSET_BG3PA       0x30
#define REG_OFFSET_BG3PB       0x32
#define REG_OFFSET_BG3PC       0x34
#define REG_OFFSET_BG3PD       0x36
#define REG_OFFSET_BG3X        0x38
#define REG_OFFSET_BG3X_L      0x38
#define REG_OFFSET_BG3X_H      0x3a
#define REG_OFFSET_BG3Y        0x3c
#define REG_OFFSET_BG3Y_L      0x3c
#define REG_OFFSET_BG3Y_H      0x3e
#define REG_OFFSET_WIN0H       0x40
#define REG_OFFSET_WIN1H       0x42
#define REG_OFFSET_WIN0V       0x44
#define REG_OFFSET_WIN1V       0x46
#define REG_OFFSET_WININ       0x48
#define REG_OFFSET_WINOUT      0x4a
#define REG_OFFSET_MOSAIC      0x4c
#define REG_OFFSET_BLDCNT      0x50
#define REG_OFFSET_BLDALPHA    0x52
#define REG_OFFSET_BLDY        0x54

#define REG_OFFSET_SOUND1CNT_L 0x60
#define REG_OFFSET_NR10        0x60
#define REG_OFFSET_SOUND1CNT_H 0x62
#define REG_OFFSET_NR11        0x62
#define REG_OFFSET_NR12        0x63
#define REG_OFFSET_SOUND1CNT_X 0x64
#define REG_OFFSET_NR13        0x64
#define REG_OFFSET_NR14        0x65
#define REG_OFFSET_SOUND2CNT_L 0x68
#define REG_OFFSET_NR21        0x68
#define REG_OFFSET_NR22        0x69
#define REG_OFFSET_SOUND2CNT_H 0x6c
#define REG_OFFSET_NR23        0x6c
#define REG_OFFSET_NR24        0x6d
#define REG_OFFSET_SOUND3CNT_L 0x70
#define REG_OFFSET_NR30        0x70
#define REG_OFFSET_SOUND3CNT_H 0x72
#define REG_OFFSET_NR31        0x72
#define REG_OFFSET_NR32        0x73
#define REG_OFFSET_SOUND3CNT_X 0x74
#define REG_OFFSET_NR33        0x74
#define REG_OFFSET_NR34        0x75
#define REG_OFFSET_SOUND4CNT_L 0x78
#define REG_OFFSET_NR41        0x78
#define REG_OFFSET_NR42        0x79
#define REG_OFFSET_SOUND4CNT_H 0x7c
#define REG_OFFSET_NR43        0x7c
#define REG_OFFSET_NR44        0x7d
#define REG_OFFSET_SOUNDCNT_L  0x80
#define REG_OFFSET_NR50        0x80
#define REG_OFFSET_NR51        0x81
#define REG_OFFSET_SOUNDCNT_H  0x82
#define REG_OFFSET_SOUNDCNT_X  0x84
#define REG_OFFSET_NR52        0x84
#define REG_OFFSET_SOUNDBIAS   0x88
#define REG_OFFSET_SOUNDBIAS_L 0x88
#define REG_OFFSET_SOUNDBIAS_H 0x89
#define REG_OFFSET_WAVE_RAM0   0x90
#define REG_OFFSET_WAVE_RAM1   0x94
#define REG_OFFSET_WAVE_RAM2   0x98
#define REG_OFFSET_WAVE_RAM3   0x9c
#define REG_OFFSET_FIFO_A      0xa0
#define REG_OFFSET_FIFO_B      0xa4

#define REG_OFFSET_DMA0        0xb0
#define REG_OFFSET_DMA0SAD     0xb0
#define REG_OFFSET_DMA0SAD_L   0xb0
#define REG_OFFSET_DMA0SAD_H   0xb2
#define REG_OFFSET_DMA0DAD     0xb4
#define REG_OFFSET_DMA0DAD_L   0xb4
#define REG_OFFSET_DMA0DAD_H   0xb6
#define REG_OFFSET_DMA0CNT     0xb8
#define REG_OFFSET_DMA0CNT_L   0xb8
#define REG_OFFSET_DMA0CNT_H   0xba
#define REG_OFFSET_DMA1        0xbc
#define REG_OFFSET_DMA1SAD     0xbc
#define REG_OFFSET_DMA1SAD_L   0xbc
#define REG_OFFSET_DMA1SAD_H   0xbe
#define REG_OFFSET_DMA1DAD     0xc0
#define REG_OFFSET_DMA1DAD_L   0xc0
#define REG_OFFSET_DMA1DAD_H   0xc2
#define REG_OFFSET_DMA1CNT     0xc4
#define REG_OFFSET_DMA1CNT_L   0xc4
#define REG_OFFSET_DMA1CNT_H   0xc6
#define REG_OFFSET_DMA2        0xc8
#define REG_OFFSET_DMA2SAD     0xc8
#define REG_OFFSET_DMA2SAD_L   0xc8
#define REG_OFFSET_DMA2SAD_H   0xca
#define REG_OFFSET_DMA2DAD     0xcc
#define REG_OFFSET_DMA2DAD_L   0xcc
#define REG_OFFSET_DMA2DAD_H   0xce
#define REG_OFFSET_DMA2CNT     0xd0
#define REG_OFFSET_DMA2CNT_L   0xd0
#define REG_OFFSET_DMA2CNT_H   0xd2
#define REG_OFFSET_DMA3        0xd4
#define REG_OFFSET_DMA3SAD     0xd4
#define REG_OFFSET_DMA3SAD_L   0xd4
#define REG_OFFSET_DMA3SAD_H   0xd6
#define REG_OFFSET_DMA3DAD     0xd8
#define REG_OFFSET_DMA3DAD_L   0xd8
#define REG_OFFSET_DMA3DAD_H   0xda
#define REG_OFFSET_DMA3CNT     0xdc
#define REG_OFFSET_DMA3CNT_L   0xdc
#define REG_OFFSET_DMA3CNT_H   0xde

#define REG_OFFSET_TMCNT       0x100
#define REG_OFFSET_TMCNT_L     0x100
#define REG_OFFSET_TMCNT_H     0x102
#define REG_OFFSET_TM0CNT      0x100
#define REG_OFFSET_TM0CNT_L    0x100
#define REG_OFFSET_TM0CNT_H    0x102
#define REG_OFFSET_TM1CNT      0x104
#define REG_OFFSET_TM1CNT_L    0x104
#define REG_OFFSET_TM1CNT_H    0x106
#define REG_OFFSET_TM2CNT      0x108
#define REG_OFFSET_TM2CNT_L    0x108
#define REG_OFFSET_TM2CNT_H    0x10a
#define REG_OFFSET_TM3CNT      0x10c
#define REG_OFFSET_TM3CNT_L    0x10c
#define REG_OFFSET_TM3CNT_H    0x10e

#define REG_OFFSET_SIOCNT      0x128
#define REG_OFFSET_SIODATA8    0x12a
#define REG_OFFSET_SIODATA32   0x120
#define REG_OFFSET_SIOMLT_SEND 0x12a
#define REG_OFFSET_SIOMLT_RECV 0x120
#define REG_OFFSET_SIOMULTI0   0x120
#define REG_OFFSET_SIOMULTI1   0x122
#define REG_OFFSET_SIOMULTI2   0x124
#define REG_OFFSET_SIOMULTI3   0x126

#define REG_OFFSET_KEYINPUT    0x130
#define REG_OFFSET_KEYCNT      0x132

#define REG_OFFSET_RCNT        0x134

#define REG_OFFSET_JOYCNT      0x140
#define REG_OFFSET_JOYSTAT     0x158
#define REG_OFFSET_JOY_RECV    0x150
#define REG_OFFSET_JOY_RECV_L  0x150
#define REG_OFFSET_JOY_RECV_H  0x152
#define REG_OFFSET_JOY_TRANS   0x154
#define REG_OFFSET_JOY_TRANS_L 0x154
#define REG_OFFSET_JOY_TRANS_H 0x156

#define REG_OFFSET_IME         0x208
#define REG_OFFSET_IE          0x200
#define REG_OFFSET_IF          0x202

#define REG_OFFSET_WAITCNT     0x204

// I/O register addresses

#define REG_ADDR_DISPCNT     (REG_BASE + REG_OFFSET_DISPCNT)
#define REG_ADDR_DISPSTAT    (REG_BASE + REG_OFFSET_DISPSTAT)
#define REG_ADDR_VCOUNT      (REG_BASE + REG_OFFSET_VCOUNT)
#define REG_ADDR_BG0CNT      (REG_BASE + REG_OFFSET_BG0CNT)
#define REG_ADDR_BG1CNT      (REG_BASE + REG_OFFSET_BG1CNT)
#define REG_ADDR_BG2CNT      (REG_BASE + REG_OFFSET_BG2CNT)
#define REG_ADDR_BG3CNT      (REG_BASE + REG_OFFSET_BG3CNT)
#define REG_ADDR_BG0HOFS     (REG_BASE + REG_OFFSET_BG0HOFS)
#define REG_ADDR_BG0VOFS     (REG_BASE + REG_OFFSET_BG0VOFS)
#define REG_ADDR_BG1HOFS     (REG_BASE + REG_OFFSET_BG1HOFS)
#define REG_ADDR_BG1VOFS     (REG_BASE + REG_OFFSET_BG1VOFS)
#define REG_ADDR_BG2HOFS     (REG_BASE + REG_OFFSET_BG2HOFS)
#define REG_ADDR_BG2VOFS     (REG_BASE + REG_OFFSET_BG2VOFS)
#define REG_ADDR_BG3HOFS     (REG_BASE + REG_OFFSET_BG3HOFS)
#define REG_ADDR_BG3VOFS     (REG_BASE + REG_OFFSET_BG3VOFS)
#define REG_ADDR_BG2PA       (REG_BASE + REG_OFFSET_BG2PA)
#define REG_ADDR_BG2PB       (REG_BASE + REG_OFFSET_BG2PB)
#define REG_ADDR_BG2PC       (REG_BASE + REG_OFFSET_BG2PC)
#define REG_ADDR_BG2PD       (REG_BASE + REG_OFFSET_BG2PD)
#define REG_ADDR_BG2X        (REG_BASE + REG_OFFSET_BG2X)
#define REG_ADDR_BG2X_L      (REG_BASE + REG_OFFSET_BG2X_L)
#define REG_ADDR_BG2X_H      (REG_BASE + REG_OFFSET_BG2X_H)
#define REG_ADDR_BG2Y        (REG_BASE + REG_OFFSET_BG2Y)
#define REG_ADDR_BG2Y_L      (REG_BASE + REG_OFFSET_BG2Y_L)
#define REG_ADDR_BG2Y_H      (REG_BASE + REG_OFFSET_BG2Y_H)
#define REG_ADDR_BG3PA       (REG_BASE + REG_OFFSET_BG3PA)
#define REG_ADDR_BG3PB       (REG_BASE + REG_OFFSET_BG3PB)
#define REG_ADDR_BG3PC       (REG_BASE + REG_OFFSET_BG3PC)
#define REG_ADDR_BG3PD       (REG_BASE + REG_OFFSET_BG3PD)
#define REG_ADDR_BG3X        (REG_BASE + REG_OFFSET_BG3X)
#define REG_ADDR_BG3X_L      (REG_BASE + REG_OFFSET_BG3X_L)
#define REG_ADDR_BG3X_H      (REG_BASE + REG_OFFSET_BG3X_H)
#define REG_ADDR_BG3Y        (REG_BASE + REG_OFFSET_BG3Y)
#define REG_ADDR_BG3Y_L      (REG_BASE + REG_OFFSET_BG3Y_L)
#define REG_ADDR_BG3Y_H      (REG_BASE + REG_OFFSET_BG3Y_H)
#define REG_ADDR_WIN0H       (REG_BASE + REG_OFFSET_WIN0H)
#define REG_ADDR_WIN1H       (REG_BASE + REG_OFFSET_WIN1H)
#define REG_ADDR_WIN0V       (REG_BASE + REG_OFFSET_WIN0V)
#define REG_ADDR_WIN1V       (REG_BASE + REG_OFFSET_WIN1V)
#define REG_ADDR_WININ       (REG_BASE + REG_OFFSET_WININ)
#define REG_ADDR_WINOUT      (REG_BASE + REG_OFFSET_WINOUT)
#define REG_ADDR_MOSAIC      (REG_BASE + REG_OFFSET_MOSAIC)
#define REG_ADDR_BLDCNT      (REG_BASE + REG_OFFSET_BLDCNT)
#define REG_ADDR_BLDALPHA    (REG_BASE + REG_OFFSET_BLDALPHA)
#define REG_ADDR_BLDY        (REG_BASE + REG_OFFSET_BLDY)

#define REG_ADDR_SOUND1CNT_L (REG_BASE + REG_OFFSET_SOUND1CNT_L)
#define REG_ADDR_NR10        (REG_BASE + REG_OFFSET_NR10)
#define REG_ADDR_SOUND1CNT_H (REG_BASE + REG_OFFSET_SOUND1CNT_H)
#define REG_ADDR_NR11        (REG_BASE + REG_OFFSET_NR11)
#define REG_ADDR_NR12        (REG_BASE + REG_OFFSET_NR12)
#define REG_ADDR_SOUND1CNT_X (REG_BASE + REG_OFFSET_SOUND1CNT_X)
#define REG_ADDR_NR13        (REG_BASE + REG_OFFSET_NR13)
#define REG_ADDR_NR14        (REG_BASE + REG_OFFSET_NR14)
#define REG_ADDR_SOUND2CNT_L (REG_BASE + REG_OFFSET_SOUND2CNT_L)
#define REG_ADDR_NR21        (REG_BASE + REG_OFFSET_NR21)
#define REG_ADDR_NR22        (REG_BASE + REG_OFFSET_NR22)
#define REG_ADDR_SOUND2CNT_H (REG_BASE + REG_OFFSET_SOUND2CNT_H)
#define REG_ADDR_NR23        (REG_BASE + REG_OFFSET_NR23)
#define REG_ADDR_NR24        (REG_BASE + REG_OFFSET_NR24)
#define REG_ADDR_SOUND3CNT_L (REG_BASE + REG_OFFSET_SOUND3CNT_L)
#define REG_ADDR_NR30        (REG_BASE + REG_OFFSET_NR30)
#define REG_ADDR_SOUND3CNT_H (REG_BASE + REG_OFFSET_SOUND3CNT_H)
#define REG_ADDR_NR31        (REG_BASE + REG_OFFSET_NR31)
#define REG_ADDR_NR32        (REG_BASE + REG_OFFSET_NR32)
#define REG_ADDR_SOUND3CNT_X (REG_BASE + REG_OFFSET_SOUND3CNT_X)
#define REG_ADDR_NR33        (REG_BASE + REG_OFFSET_NR33)
#define REG_ADDR_NR34        (REG_BASE + REG_OFFSET_NR34)
#define REG_ADDR_SOUND4CNT_L (REG_BASE + REG_OFFSET_SOUND4CNT_L)
#define REG_ADDR_NR41        (REG_BASE + REG_OFFSET_NR41)
#define REG_ADDR_NR42        (REG_BASE + REG_OFFSET_NR42)
#define REG_ADDR_SOUND4CNT_H (REG_BASE + REG_OFFSET_SOUND4CNT_H)
#define REG_ADDR_NR43        (REG_BASE + REG_OFFSET_NR43)
#define REG_ADDR_NR44        (REG_BASE + REG_OFFSET_NR44)
#define REG_ADDR_SOUNDCNT_L  (REG_BASE + REG_OFFSET_SOUNDCNT_L)
#define REG_ADDR_NR50        (REG_BASE + REG_OFFSET_NR50)
#define REG_ADDR_NR51        (REG_BASE + REG_OFFSET_NR51)
#define REG_ADDR_SOUNDCNT_H  (REG_BASE + REG_OFFSET_SOUNDCNT_H)
#define REG_ADDR_SOUNDCNT_X  (REG_BASE + REG_OFFSET_SOUNDCNT_X)
#define REG_ADDR_NR52        (REG_BASE + REG_OFFSET_NR52)
#define REG_ADDR_SOUNDBIAS   (REG_BASE + REG_OFFSET_SOUNDBIAS)
#define REG_ADDR_SOUNDBIAS_L (REG_BASE + REG_OFFSET_SOUNDBIAS_L)
#define REG_ADDR_SOUNDBIAS_H (REG_BASE + REG_OFFSET_SOUNDBIAS_H)
#define REG_ADDR_WAVE_RAM0   (REG_BASE + REG_OFFSET_WAVE_RAM0)
#define REG_ADDR_WAVE_RAM1   (REG_BASE + REG_OFFSET_WAVE_RAM1)
#define REG_ADDR_WAVE_RAM2   (REG_BASE + REG_OFFSET_WAVE_RAM2)
#define REG_ADDR_WAVE_RAM3   (REG_BASE + REG_OFFSET_WAVE_RAM3)
#define REG_ADDR_FIFO_A      (REG_BASE + REG_OFFSET_FIFO_A)
#define REG_ADDR_FIFO_B      (REG_BASE + REG_OFFSET_FIFO_B)

#define REG_ADDR_DMA0        (REG_BASE + REG_OFFSET_DMA0)
#define REG_ADDR_DMA0SAD     (REG_BASE + REG_OFFSET_DMA0SAD)
#define REG_ADDR_DMA0DAD     (REG_BASE + REG_OFFSET_DMA0DAD)
#define REG_ADDR_DMA0CNT     (REG_BASE + REG_OFFSET_DMA0CNT)
#define REG_ADDR_DMA0CNT_L   (REG_BASE + REG_OFFSET_DMA0CNT_L)
#define REG_ADDR_DMA0CNT_H   (REG_BASE + REG_OFFSET_DMA0CNT_H)
#define REG_ADDR_DMA1        (REG_BASE + REG_OFFSET_DMA1)
#define REG_ADDR_DMA1SAD     (REG_BASE + REG_OFFSET_DMA1SAD)
#define REG_ADDR_DMA1DAD     (REG_BASE + REG_OFFSET_DMA1DAD)
#define REG_ADDR_DMA1CNT     (REG_BASE + REG_OFFSET_DMA1CNT)
#define REG_ADDR_DMA1CNT_L   (REG_BASE + REG_OFFSET_DMA1CNT_L)
#define REG_ADDR_DMA1CNT_H   (REG_BASE + REG_OFFSET_DMA1CNT_H)
#define REG_ADDR_DMA2        (REG_BASE + REG_OFFSET_DMA2)
#define REG_ADDR_DMA2SAD     (REG_BASE + REG_OFFSET_DMA2SAD)
#define REG_ADDR_DMA2DAD     (REG_BASE + REG_OFFSET_DMA2DAD)
#define REG_ADDR_DMA2CNT     (REG_BASE + REG_OFFSET_DMA2CNT)
#define REG_ADDR_DMA2CNT_L   (REG_BASE + REG_OFFSET_DMA2CNT_L)
#define REG_ADDR_DMA2CNT_H   (REG_BASE + REG_OFFSET_DMA2CNT_H)
#define REG_ADDR_DMA3        (REG_BASE + REG_OFFSET_DMA3)
#define REG_ADDR_DMA3SAD     (REG_BASE + REG_OFFSET_DMA3SAD)
#define REG_ADDR_DMA3DAD     (REG_BASE + REG_OFFSET_DMA3DAD)
#define REG_ADDR_DMA3CNT     (REG_BASE + REG_OFFSET_DMA3CNT)
#define REG_ADDR_DMA3CNT_L   (REG_BASE + REG_OFFSET_DMA3CNT_L)
#define REG_ADDR_DMA3CNT_H   (REG_BASE + REG_OFFSET_DMA3CNT_H)

#define REG_ADDR_TMCNT       (REG_BASE + REG_OFFSET_TMCNT)
#define REG_ADDR_TMCNT_L     (REG_BASE + REG_OFFSET_TMCNT_L)
#define REG_ADDR_TMCNT_H     (REG_BASE + REG_OFFSET_TMCNT_H)
#define REG_ADDR_TM0CNT      (REG_BASE + REG_OFFSET_TM0CNT)
#define REG_ADDR_TM0CNT_L    (REG_BASE + REG_OFFSET_TM0CNT_L)
#define REG_ADDR_TM0CNT_H    (REG_BASE + REG_OFFSET_TM0CNT_H)
#define REG_ADDR_TM1CNT      (REG_BASE + REG_OFFSET_TM1CNT)
#define REG_ADDR_TM1CNT_L    (REG_BASE + REG_OFFSET_TM1CNT_L)
#define REG_ADDR_TM1CNT_H    (REG_BASE + REG_OFFSET_TM1CNT_H)
#define REG_ADDR_TM2CNT      (REG_BASE + REG_OFFSET_TM2CNT)
#define REG_ADDR_TM2CNT_L    (REG_BASE + REG_OFFSET_TM2CNT_L)
#define REG_ADDR_TM2CNT_H    (REG_BASE + REG_OFFSET_TM2CNT_H)
#define REG_ADDR_TM3CNT      (REG_BASE + REG_OFFSET_TM3CNT)
#define REG_ADDR_TM3CNT_L    (REG_BASE + REG_OFFSET_TM3CNT_L)
#define REG_ADDR_TM3CNT_H    (REG_BASE + REG_OFFSET_TM3CNT_H)

#define REG_ADDR_SIOCNT      (REG_BASE + REG_OFFSET_SIOCNT)
#define REG_ADDR_SIODATA8    (REG_BASE + REG_OFFSET_SIODATA8)
#define REG_ADDR_SIODATA32   (REG_BASE + REG_OFFSET_SIODATA32)
#define REG_ADDR_SIOMLT_SEND (REG_BASE + REG_OFFSET_SIOMLT_SEND)
#define REG_ADDR_SIOMLT_RECV (REG_BASE + REG_OFFSET_SIOMLT_RECV)
#define REG_ADDR_SIOMULTI0   (REG_BASE + REG_OFFSET_SIOMULTI0)
#define REG_ADDR_SIOMULTI1   (REG_BASE + REG_OFFSET_SIOMULTI1)
#define REG_ADDR_SIOMULTI2   (REG_BASE + REG_OFFSET_SIOMULTI2)
#define REG_ADDR_SIOMULTI3   (REG_BASE + REG_OFFSET_SIOMULTI3)

#define REG_ADDR_KEYINPUT    (REG_BASE + REG_OFFSET_KEYINPUT)
#define REG_ADDR_KEYCNT      (REG_BASE + REG_OFFSET_KEYCNT)

#define REG_ADDR_RCNT        (REG_BASE + REG_OFFSET_RCNT)

#define REG_ADDR_JOYCNT      (REG_BASE + REG_OFFSET_JOYCNT)
#define REG_ADDR_JOYSTAT     (REG_BASE + REG_OFFSET_JOYSTAT)
#define REG_ADDR_JOY_RECV    (REG_BASE + REG_OFFSET_JOY_RECV)
#define REG_ADDR_JOY_RECV_L  (REG_BASE + REG_OFFSET_JOY_RECV_L)
#define REG_ADDR_JOY_RECV_H  (REG_BASE + REG_OFFSET_JOY_RECV_H)
#define REG_ADDR_JOY_TRANS   (REG_BASE + REG_OFFSET_JOY_TRANS)
#define REG_ADDR_JOY_TRANS_L (REG_BASE + REG_OFFSET_JOY_TRANS_L)
#define REG_ADDR_JOY_TRANS_H (REG_BASE + REG_OFFSET_JOY_TRANS_H)

#define REG_ADDR_IME         (REG_BASE + REG_OFFSET_IME)
#define REG_ADDR_IE          (REG_BASE + REG_OFFSET_IE)
#define REG_ADDR_IF          (REG_BASE + REG_OFFSET_IF)

#define REG_ADDR_WAITCNT     (REG_BASE + REG_OFFSET_WAITCNT)

// I/O registers

#define REG_DISPCNT     (*(vu16 *)REG_ADDR_DISPCNT)
#define REG_DISPSTAT    (*(vu16 *)REG_ADDR_DISPSTAT)
#define REG_VCOUNT      (*(vu16 *)REG_ADDR_VCOUNT)
#define REG_BG0CNT      (*(vu16 *)REG_ADDR_BG0CNT)
#define REG_BG1CNT      (*(vu16 *)REG_ADDR_BG1CNT)
#define REG_BG2CNT      (*(vu16 *)REG_ADDR_BG2CNT)
#define REG_BG3CNT      (*(vu16 *)REG_ADDR_BG3CNT)
#define REG_BG0HOFS     (*(vu16 *)REG_ADDR_BG0HOFS)
#define REG_BG0VOFS     (*(vu16 *)REG_ADDR_BG0VOFS)
#define REG_BG1HOFS     (*(vu16 *)REG_ADDR_BG1HOFS)
#define REG_BG1VOFS     (*(vu16 *)REG_ADDR_BG1VOFS)
#define REG_BG2HOFS     (*(vu16 *)REG_ADDR_BG2HOFS)
#define REG_BG2VOFS     (*(vu16 *)REG_ADDR_BG2VOFS)
#define REG_BG3HOFS     (*(vu16 *)REG_ADDR_BG3HOFS)
#define REG_BG3VOFS     (*(vu16 *)REG_ADDR_BG3VOFS)
#define REG_BG2PA       (*(vu16 *)REG_ADDR_BG2PA)
#define REG_BG2PB       (*(vu16 *)REG_ADDR_BG2PB)
#define REG_BG2PC       (*(vu16 *)REG_ADDR_BG2PC)
#define REG_BG2PD       (*(vu16 *)REG_ADDR_BG2PD)
#define REG_BG2X        (*(vu32 *)REG_ADDR_BG2X)
#define REG_BG2X_L      (*(vu16 *)REG_ADDR_BG2X_L)
#define REG_BG2X_H      (*(vu16 *)REG_ADDR_BG2X_H)
#define REG_BG2Y        (*(vu32 *)REG_ADDR_BG2Y)
#define REG_BG2Y_L      (*(vu16 *)REG_ADDR_BG2Y_L)
#define REG_BG2Y_H      (*(vu16 *)REG_ADDR_BG2Y_H)
#define REG_BG3PA       (*(vu16 *)REG_ADDR_BG3PA)
#define REG_BG3PB       (*(vu16 *)REG_ADDR_BG3PB)
#define REG_BG3PC       (*(vu16 *)REG_ADDR_BG3PC)
#define REG_BG3PD       (*(vu16 *)REG_ADDR_BG3PD)
#define REG_BG3X        (*(vu32 *)REG_ADDR_BG3X)
#define REG_BG3X_L      (*(vu16 *)REG_ADDR_BG3X_L)
#define REG_BG3X_H      (*(vu16 *)REG_ADDR_BG3X_H)
#define REG_BG3Y        (*(vu32 *)REG_ADDR_BG3Y)
#define REG_BG3Y_L      (*(vu16 *)REG_ADDR_BG3Y_L)
#define REG_BG3Y_H      (*(vu16 *)REG_ADDR_BG3Y_H)
#define REG_WIN0H       (*(vu16 *)REG_ADDR_WIN0H)
#define REG_WIN1H       (*(vu16 *)REG_ADDR_WIN1H)
#define REG_WIN0V       (*(vu16 *)REG_ADDR_WIN0V)
#define REG_WIN1V       (*(vu16 *)REG_ADDR_WIN1V)
#define REG_WININ       (*(vu16 *)REG_ADDR_WININ)
#define REG_WINOUT      (*(vu16 *)REG_ADDR_WINOUT)
#define REG_MOSAIC      (*(vu16 *)REG_ADDR_MOSAIC)
#define REG_BLDCNT      (*(vu16 *)REG_ADDR_BLDCNT)
#define REG_BLDALPHA    (*(vu16 *)REG_ADDR_BLDALPHA)
#define REG_BLDY        (*(vu16 *)REG_ADDR_BLDY)

#define REG_SOUND1CNT_L (*(vu16 *)REG_ADDR_SOUND1CNT_L)
#define REG_NR10        (*(vu8  *)REG_ADDR_NR10)
#define REG_SOUND1CNT_H (*(vu16 *)REG_ADDR_SOUND1CNT_H)
#define REG_NR11        (*(vu8  *)REG_ADDR_NR11)
#define REG_NR12        (*(vu8  *)REG_ADDR_NR12)
#define REG_SOUND1CNT_X (*(vu16 *)REG_ADDR_SOUND1CNT_X)
#define REG_NR13        (*(vu8  *)REG_ADDR_NR13)
#define REG_NR14        (*(vu8  *)REG_ADDR_NR14)
#define REG_SOUND2CNT_L (*(vu16 *)REG_ADDR_SOUND2CNT_L)
#define REG_NR21        (*(vu8  *)REG_ADDR_NR21)
#define REG_NR22        (*(vu8  *)REG_ADDR_NR22)
#define REG_SOUND2CNT_H (*(vu16 *)REG_ADDR_SOUND2CNT_H)
#define REG_NR23        (*(vu8  *)REG_ADDR_NR23)
#define REG_NR24        (*(vu8  *)REG_ADDR_NR24)
#define REG_SOUND3CNT_L (*(vu16 *)REG_ADDR_SOUND3CNT_L)
#define REG_NR30        (*(vu8  *)REG_ADDR_NR30)
#define REG_SOUND3CNT_H (*(vu16 *)REG_ADDR_SOUND3CNT_H)
#define REG_NR31        (*(vu8  *)REG_ADDR_NR31)
#define REG_NR32        (*(vu8  *)REG_ADDR_NR32)
#define REG_SOUND3CNT_X (*(vu16 *)REG_ADDR_SOUND3CNT_X)
#define REG_NR33        (*(vu8  *)REG_ADDR_NR33)
#define REG_NR34        (*(vu8  *)REG_ADDR_NR34)
#define REG_SOUND4CNT_L (*(vu16 *)REG_ADDR_SOUND4CNT_L)
#define REG_NR41        (*(vu8  *)REG_ADDR_NR41)
#define REG_NR42        (*(vu8  *)REG_ADDR_NR42)
#define REG_SOUND4CNT_H (*(vu16 *)REG_ADDR_SOUND4CNT_H)
#define REG_NR43        (*(vu8  *)REG_ADDR_NR43)
#define REG_NR44        (*(vu8  *)REG_ADDR_NR44)
#define REG_SOUNDCNT_L  (*(vu16 *)REG_ADDR_SOUNDCNT_L)
#define REG_NR50        (*(vu8  *)REG_ADDR_NR50)
#define REG_NR51        (*(vu8  *)REG_ADDR_NR51)
#define REG_SOUNDCNT_H  (*(vu16 *)REG_ADDR_SOUNDCNT_H)
#define REG_SOUNDCNT_X  (*(vu16 *)REG_ADDR_SOUNDCNT_X)
#define REG_NR52        (*(vu8  *)REG_ADDR_NR52)
#define REG_SOUNDBIAS   (*(vu16 *)REG_ADDR_SOUNDBIAS)
#define REG_SOUNDBIAS_L (*(vu8  *)REG_ADDR_SOUNDBIAS_L)
#define REG_SOUNDBIAS_H (*(vu8  *)REG_ADDR_SOUNDBIAS_H)
#define REG_WAVE_RAM0   (*(vu32 *)REG_ADDR_WAVE_RAM0)
#define REG_WAVE_RAM1   (*(vu32 *)REG_ADDR_WAVE_RAM1)
#define REG_WAVE_RAM2   (*(vu32 *)REG_ADDR_WAVE_RAM2)
#define REG_WAVE_RAM3   (*(vu32 *)REG_ADDR_WAVE_RAM3)
#define REG_FIFO_A      (*(vu32 *)REG_ADDR_FIFO_A)
#define REG_FIFO_B      (*(vu32 *)REG_ADDR_FIFO_B)

#define REG_DMA0SAD     (*(vu32 *)REG_ADDR_DMA0SAD)
#define REG_DMA0DAD     (*(vu32 *)REG_ADDR_DMA0DAD)
#define REG_DMA0CNT     (*(vu32 *)REG_ADDR_DMA0CNT)
#define REG_DMA0CNT_L   (*(vu16 *)REG_ADDR_DMA0CNT_L)
#define REG_DMA0CNT_H   (*(vu16 *)REG_ADDR_DMA0CNT_H)

#define REG_DMA1SAD     (*(vu32 *)REG_ADDR_DMA1SAD)
#define REG_DMA1DAD     (*(vu32 *)REG_ADDR_DMA1DAD)
#define REG_DMA1CNT     (*(vu32 *)REG_ADDR_DMA1CNT)
#define REG_DMA1CNT_L   (*(vu16 *)REG_ADDR_DMA1CNT_L)
#define REG_DMA1CNT_H   (*(vu16 *)REG_ADDR_DMA1CNT_H)

#define REG_DMA2SAD     (*(vu32 *)REG_ADDR_DMA2SAD)
#define REG_DMA2DAD     (*(vu32 *)REG_ADDR_DMA2DAD)
#define REG_DMA2CNT     (*(vu32 *)REG_ADDR_DMA2CNT)
#define REG_DMA2CNT_L   (*(vu16 *)REG_ADDR_DMA2CNT_L)
#define REG_DMA2CNT_H   (*(vu16 *)REG_ADDR_DMA2CNT_H)

#define REG_DMA3SAD     (*(vu32 *)REG_ADDR_DMA3SAD)
#define REG_DMA3DAD     (*(vu32 *)REG_ADDR_DMA3DAD)
#define REG_DMA3CNT     (*(vu32 *)REG_ADDR_DMA3CNT)
#define REG_DMA3CNT_L   (*(vu16 *)REG_ADDR_DMA3CNT_L)
#define REG_DMA3CNT_H   (*(vu16 *)REG_ADDR_DMA3CNT_H)

#define REG_TMCNT(n)    (*(vu32 *)(REG_ADDR_TMCNT + ((n) * 4)))
#define REG_TMCNT_L(n)  (*(vu16 *)(REG_ADDR_TMCNT_L + ((n) * 4)))
#define REG_TMCNT_H(n)  (*(vu16 *)(REG_ADDR_TMCNT_H + ((n) * 4)))
#define REG_TM0CNT      (*(vu32 *)REG_ADDR_TM0CNT)
#define REG_TM0CNT_L    (*(vu16 *)REG_ADDR_TM0CNT_L)
#define REG_TM0CNT_H    (*(vu16 *)REG_ADDR_TM0CNT_H)
#define REG_TM1CNT      (*(vu32 *)REG_ADDR_TM1CNT)
#define REG_TM1CNT_L    (*(vu16 *)REG_ADDR_TM1CNT_L)
#define REG_TM1CNT_H    (*(vu16 *)REG_ADDR_TM1CNT_H)
#define REG_TM2CNT      (*(vu32 *)REG_ADDR_TM2CNT)
#define REG_TM2CNT_L    (*(vu16 *)REG_ADDR_TM2CNT_L)
#define REG_TM2CNT_H    (*(vu16 *)REG_ADDR_TM2CNT_H)
#define REG_TM3CNT      (*(vu32 *)REG_ADDR_TM3CNT)
#define REG_TM3CNT_L    (*(vu16 *)REG_ADDR_TM3CNT_L)
#define REG_TM3CNT_H    (*(vu16 *)REG_ADDR_TM3CNT_H)

#define REG_SIOCNT      (*(vu16 *)REG_ADDR_SIOCNT)
#define REG_SIODATA8    (*(vu16 *)REG_ADDR_SIODATA8)
#define REG_SIODATA32   (*(vu32 *)REG_ADDR_SIODATA32)
#define REG_SIOMLT_SEND (*(vu16 *)REG_ADDR_SIOMLT_SEND)
#define REG_SIOMLT_RECV (*(vu64 *)REG_ADDR_SIOMLT_RECV)
#define REG_SIOMULTI(n) (*(vu16 *)(REG_ADDR_SIOMULTI0 + (n) * 2))
#define REG_SIOMULTI0   (*(vu16 *)REG_ADDR_SIOMULTI0)
#define REG_SIOMULTI1   (*(vu16 *)REG_ADDR_SIOMULTI1)
#define REG_SIOMULTI2   (*(vu16 *)REG_ADDR_SIOMULTI2)
#define REG_SIOMULTI3   (*(vu16 *)REG_ADDR_SIOMULTI3)

#define REG_KEYINPUT    (*(vu16 *)REG_ADDR_KEYINPUT)
#define REG_KEYCNT      (*(vu16 *)REG_ADDR_KEYCNT)

#define REG_RCNT        (*(vu16 *)REG_ADDR_RCNT)

#define REG_IME         (*(vu16 *)REG_ADDR_IME)
#define REG_IE          (*(vu16 *)REG_ADDR_IE)
#define REG_IF          (*(vu16 *)REG_ADDR_IF)

#define REG_WAITCNT     (*(vu16 *)REG_ADDR_WAITCNT)

// I/O register fields

// DISPCNT
#define DISPCNT_MODE_0          0x0000 // BG0: text, BG1: text, BG2: text,   BG3: text
#define DISPCNT_MODE_1          0x0001 // BG0: text, BG1: text, BG2: affine, BG3: off
#define DISPCNT_MODE_2          0x0002 // BG0: off,  BG1: off,  BG2: affine, BG3: affine
#define DISPCNT_MODE_3          0x0003 // Bitmap mode, 240x160, BGR555 color
#define DISPCNT_MODE_4          0x0004 // Bitmap mode, 240x160, 256 color palette
#define DISPCNT_MODE_5          0x0005 // Bitmap mode, 160x128, BGR555 color
#define DISPCNT_HBLANK_INTERVAL 0x0020 // Allow access to OAM during H-Blank
#define DISPCNT_OBJ_1D_MAP      0x0040
#define DISPCNT_FORCED_BLANK    0x0080
#define DISPCNT_BG0_ON          0x0100
#define DISPCNT_BG1_ON          0x0200
#define DISPCNT_BG2_ON          0x0400
#define DISPCNT_BG3_ON          0x0800
#define DISPCNT_BG_ALL_ON       0x0F00
#define DISPCNT_OBJ_ON          0x1000
#define DISPCNT_WIN0_ON         0x2000
#define DISPCNT_WIN1_ON         0x4000
#define DISPCNT_OBJWIN_ON       0x8000

// DISPSTAT
#define DISPSTAT_VBLANK      0x0001 // in V-Blank
#define DISPSTAT_HBLANK      0x0002 // in H-Blank
#define DISPSTAT_VCOUNT      0x0004 // V-Count match
#define DISPSTAT_VBLANK_INTR 0x0008 // V-Blank interrupt enabled
#define DISPSTAT_HBLANK_INTR 0x0010 // H-Blank interrupt enabled
#define DISPSTAT_VCOUNT_INTR 0x0020 // V-Count interrupt enabled

// BGCNT
#define BGCNT_PRIORITY(n)          (n) // Values 0 - 3. Lower priority BGs will be drawn on top of higher priority BGs.
#define BGCNT_CHARBASE(n)   ((n) << 2) // Values 0 - 3. Base block for tile pixel data.
#define BGCNT_MOSAIC            0x0040
#define BGCNT_16COLOR           0x0000 // 4 bits per pixel
#define BGCNT_256COLOR          0x0080 // 8 bits per pixel
#define BGCNT_SCREENBASE(n) ((n) << 8) // Values 0 - 31. Base block for tile map.
#define BGCNT_WRAP              0x2000 // Only affects affine BGs. Text BGs wrap by default.
#define BGCNT_TXT256x256        0x0000 // Internal screen size size of text mode BG in pixels.
#define BGCNT_TXT512x256        0x4000
#define BGCNT_TXT256x512        0x8000
#define BGCNT_TXT512x512        0xC000
#define BGCNT_AFF128x128        0x0000 // Internal screen size size of affine mode BG in pixels.
#define BGCNT_AFF256x256        0x4000
#define BGCNT_AFF512x512        0x8000
#define BGCNT_AFF1024x1024      0xC000

// WININ/OUT
#define WININ_WIN0_BG0      (1 << 0)
#define WININ_WIN0_BG1      (1 << 1)
#define WININ_WIN0_BG2      (1 << 2)
#define WININ_WIN0_BG3      (1 << 3)
#define WININ_WIN0_BG_ALL   (WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3)
#define WININ_WIN0_OBJ      (1 << 4)
#define WININ_WIN0_CLR      (1 << 5)
#define WININ_WIN0_ALL      (WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR)
#define WININ_WIN1_BG0      (1 << 8)
#define WININ_WIN1_BG1      (1 << 9)
#define WININ_WIN1_BG2      (1 << 10)
#define WININ_WIN1_BG3      (1 << 11)
#define WININ_WIN1_BG_ALL   (WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_BG3)
#define WININ_WIN1_OBJ      (1 << 12)
#define WININ_WIN1_CLR      (1 << 13)
#define WININ_WIN1_ALL      (WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR)

#define WINOUT_WIN01_BG0    (1 << 0)
#define WINOUT_WIN01_BG1    (1 << 1)
#define WINOUT_WIN01_BG2    (1 << 2)
#define WINOUT_WIN01_BG3    (1 << 3)
#define WINOUT_WIN01_BG_ALL (WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3)
#define WINOUT_WIN01_OBJ    (1 << 4)
#define WINOUT_WIN01_CLR    (1 << 5)
#define WINOUT_WIN01_ALL    (WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR)
#define WINOUT_WINOBJ_BG0   (1 << 8)
#define WINOUT_WINOBJ_BG1   (1 << 9)
#define WINOUT_WINOBJ_BG2   (1 << 10)
#define WINOUT_WINOBJ_BG3   (1 << 11)
#define WINOUT_WINOBJ_BG_ALL (WINOUT_WINOBJ_BG0 | WINOUT_WINOBJ_BG1 | WINOUT_WINOBJ_BG2 | WINOUT_WINOBJ_BG3)
#define WINOUT_WINOBJ_OBJ   (1 << 12)
#define WINOUT_WINOBJ_CLR   (1 << 13)
#define WINOUT_WINOBJ_ALL   (WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR)

#define WIN_RANGE(a, b) (((a) << 8) | (b))
#define WIN_RANGE2(a, b) ((b) | ((a) << 8))

// BLDCNT
// Bits 0-5 select layers for the 1st target
#define BLDCNT_TGT1_BG0      (1 << 0)
#define BLDCNT_TGT1_BG1      (1 << 1)
#define BLDCNT_TGT1_BG2      (1 << 2)
#define BLDCNT_TGT1_BG3      (1 << 3)
#define BLDCNT_TGT1_BG_ALL   (BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3)
#define BLDCNT_TGT1_OBJ      (1 << 4)
#define BLDCNT_TGT1_BD       (1 << 5)
#define BLDCNT_TGT1_ALL      (BLDCNT_TGT1_BG_ALL | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD)
// Bits 6-7 select the special effect
#define BLDCNT_EFFECT_NONE      (0 << 6)   // no special effect
#define BLDCNT_EFFECT_BLEND     (1 << 6)   // 1st+2nd targets mixed (controlled by BLDALPHA)
#define BLDCNT_EFFECT_LIGHTEN   (2 << 6)   // 1st target becomes whiter (controlled by BLDY)
#define BLDCNT_EFFECT_DARKEN    (3 << 6)   // 1st target becomes blacker (controlled by BLDY)
// Bits 8-13 select layers for the 2nd target
#define BLDCNT_TGT2_BG0      (1 << 8)
#define BLDCNT_TGT2_BG1      (1 << 9)
#define BLDCNT_TGT2_BG2      (1 << 10)
#define BLDCNT_TGT2_BG3      (1 << 11)
#define BLDCNT_TGT2_BG_ALL   (BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3)
#define BLDCNT_TGT2_OBJ      (1 << 12)
#define BLDCNT_TGT2_BD       (1 << 13)
#define BLDCNT_TGT2_ALL      (BLDCNT_TGT2_BG_ALL | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD)

// BLDALPHA
#define BLDALPHA_BLEND(target1, target2) (((target2) << 8) | (target1))

// SOUNDCNT_H
#define SOUND_CGB_MIX_QUARTER 0x0000
#define SOUND_CGB_MIX_HALF    0x0001
#define SOUND_CGB_MIX_FULL    0x0002
#define SOUND_A_MIX_HALF      0x0000
#define SOUND_A_MIX_FULL      0x0004
#define SOUND_B_MIX_HALF      0x0000
#define SOUND_B_MIX_FULL      0x0008
#define SOUND_ALL_MIX_FULL    0x000E
#define SOUND_A_RIGHT_OUTPUT  0x0100
#define SOUND_A_LEFT_OUTPUT   0x0200
#define SOUND_A_TIMER_0       0x0000
#define SOUND_A_TIMER_1       0x0400
#define SOUND_A_FIFO_RESET    0x0800
#define SOUND_B_RIGHT_OUTPUT  0x1000
#define SOUND_B_LEFT_OUTPUT   0x2000
#define SOUND_B_TIMER_0       0x0000
#define SOUND_B_TIMER_1       0x4000
#define SOUND_B_FIFO_RESET    0x8000

// SOUNDCNT_X
#define SOUND_1_ON          0x0001
#define SOUND_2_ON          0x0002
#define SOUND_3_ON          0x0004
#define SOUND_4_ON          0x0008
#define SOUND_MASTER_ENABLE 0x0080

// DMA
#define DMA_DEST_INC      0x0000
#define DMA_DEST_DEC      0x0020
#define DMA_DEST_FIXED    0x0040
#define DMA_DEST_RELOAD   0x0060
#define DMA_SRC_INC       0x0000
#define DMA_SRC_DEC       0x0080
#define DMA_SRC_FIXED     0x0100
#define DMA_REPEAT        0x0200
#define DMA_16BIT         0x0000
#define DMA_32BIT         0x0400
#define DMA_DREQ_ON       0x0800
#define DMA_START_NOW     0x0000
#define DMA_START_VBLANK  0x1000
#define DMA_START_HBLANK  0x2000
#define DMA_START_SPECIAL 0x3000
#define DMA_START_MASK    0x3000
#define DMA_INTR_ENABLE   0x4000
#define DMA_ENABLE        0x8000

// timer
#define TIMER_1CLK        0x00
#define TIMER_64CLK       0x01
#define TIMER_256CLK      0x02
#define TIMER_1024CLK     0x03
#define TIMER_COUNTUP     0x04
#define TIMER_INTR_ENABLE 0x40
#define TIMER_ENABLE      0x80

// serial
#define SIO_ID             0x0030 // Communication ID

#define SIO_8BIT_MODE      0x0000 // Normal 8-bit communication mode
#define SIO_32BIT_MODE     0x1000 // Normal 32-bit communication mode
#define SIO_MULTI_MODE     0x2000 // Multi-player communication mode
#define SIO_UART_MODE      0x3000 // UART communication mode

#define SIO_9600_BPS       0x0000 // baud rate   9600 bps
#define SIO_38400_BPS      0x0001 //            38400 bps
#define SIO_57600_BPS      0x0002 //            57600 bps
#define SIO_115200_BPS     0x0003 //           115200 bps

#define SIO_MULTI_SI       0x0004 // Multi-player communication SI terminal
#define SIO_MULTI_SD       0x0008 //                            SD terminal
#define SIO_MULTI_BUSY     0x0080

#define SIO_ERROR          0x0040 // Detect error
#define SIO_START          0x0080 // Start transfer
#define SIO_ENABLE         0x0080 // Enable SIO

#define SIO_INTR_ENABLE    0x4000

#define SIO_MULTI_SI_SHIFT 2
#define SIO_MULTI_SI_MASK  0x1
#define SIO_MULTI_DI_SHIFT 3
#define SIO_MULTI_DI_MASK  0x1

// keys
#define A_BUTTON        0x0001
#define B_BUTTON        0x0002
#define SELECT_BUTTON   0x0004
#define START_BUTTON    0x0008
#define DPAD_RIGHT      0x0010
#define DPAD_LEFT       0x0020
#define DPAD_UP         0x0040
#define DPAD_DOWN       0x0080
#define R_BUTTON        0x0100
#define L_BUTTON        0x0200
#define KEYS_MASK       0x03FF
#define KEY_INTR_ENABLE 0x4000
#define KEY_OR_INTR     0x0000
#define KEY_AND_INTR    0x8000
#define DPAD_ANY        ((DPAD_RIGHT | DPAD_LEFT | DPAD_UP | DPAD_DOWN))
#define JOY_EXCL_DPAD   0x030F

// interrupt flags
#define INTR_FLAG_VBLANK  (1 <<  0)
#define INTR_FLAG_HBLANK  (1 <<  1)
#define INTR_FLAG_VCOUNT  (1 <<  2)
#define INTR_FLAG_TIMER0  (1 <<  3)
#define INTR_FLAG_TIMER1  (1 <<  4)
#define INTR_FLAG_TIMER2  (1 <<  5)
#define INTR_FLAG_TIMER3  (1 <<  6)
#define INTR_FLAG_SERIAL  (1 <<  7)
#define INTR_FLAG_DMA0    (1 <<  8)
#define INTR_FLAG_DMA1    (1 <<  9)
#define INTR_FLAG_DMA2    (1 << 10)
#define INTR_FLAG_DMA3    (1 << 11)
#define INTR_FLAG_KEYPAD  (1 << 12)
#define INTR_FLAG_GAMEPAK (1 << 13)

// WAITCNT
#define WAITCNT_SRAM_4          (0 << 0)
#define WAITCNT_SRAM_3          (1 << 0)
#define WAITCNT_SRAM_2          (2 << 0)
#define WAITCNT_SRAM_8          (3 << 0)
#define WAITCNT_SRAM_MASK       (3 << 0)

#define WAITCNT_WS0_N_4         (0 << 2)
#define WAITCNT_WS0_N_3         (1 << 2)
#define WAITCNT_WS0_N_2         (2 << 2)
#define WAITCNT_WS0_N_8         (3 << 2)
#define WAITCNT_WS0_N_MASK      (3 << 2)

#define WAITCNT_WS0_S_2         (0 << 4)
#define WAITCNT_WS0_S_1         (1 << 4)

#define WAITCNT_WS1_N_4         (0 << 5)
#define WAITCNT_WS1_N_3         (1 << 5)
#define WAITCNT_WS1_N_2         (2 << 5)
#define WAITCNT_WS1_N_8         (3 << 5)
#define WAITCNT_WS1_N_MASK      (3 << 5)

#define WAITCNT_WS1_S_4         (0 << 7)
#define WAITCNT_WS1_S_1         (1 << 7)

#define WAITCNT_WS2_N_4         (0 << 8)
#define WAITCNT_WS2_N_3         (1 << 8)
#define WAITCNT_WS2_N_2         (2 << 8)
#define WAITCNT_WS2_N_8         (3 << 8)
#define WAITCNT_WS2_N_MASK      (3 << 8)

#define WAITCNT_WS2_S_8         (0 << 10)
#define WAITCNT_WS2_S_1         (1 << 10)

#define WAITCNT_PHI_OUT_NONE    (0 << 11)
#define WAITCNT_PHI_OUT_4MHZ    (1 << 11)
#define WAITCNT_PHI_OUT_8MHZ    (2 << 11)
#define WAITCNT_PHI_OUT_16MHZ   (3 << 11)
#define WAITCNT_PHI_OUT_MASK    (3 << 11)

#define WAITCNT_PREFETCH_ENABLE (1 << 14)

#define WAITCNT_AGB (0 << 15)
#define WAITCNT_CGB (1 << 15)

#endif // GUARD_GBA_IO_REG_H
