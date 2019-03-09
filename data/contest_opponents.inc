    .macro aiPool rank:req, cool:req, beauty:req, cute:req, smart:req, tough:req
    .byte ((\tough) << 6) | ((\smart) << 5) | ((\cute) << 4) | ((\beauty) << 3) | ((\cool) << 2) | \rank
    .byte 0 @ padding
    .endm

    .macro gfxId id
    .byte \id
    .2byte 0 @ padding
    .endm

    .macro unk2C
    .4byte 0, 0, 0
    .endm

@todo: cleanup
	.2byte SPECIES_POOCHYENA
	.string "POOCHY$    "
	.string "JIMMY$  "
	gfxId 7
	.4byte 0xc000fff
	aiPool 0, 1, 0, 0, 0, 1
	.2byte 46
	.2byte 44
	.2byte 36
	.2byte 336
	.byte 10
	.byte 4
	.byte 10
	.byte 3
	.byte 4
	.byte 50
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ILLUMISE
	.string "MUSILLE$   "
	.string "EDITH$  "
	gfxId 8
	.4byte 0x82000fff
	aiPool 0, 0, 0, 1, 0, 0
	.2byte 156
	.2byte 263
	.2byte 33
	.2byte 343
	.byte 10
	.byte 10
	.byte 6
	.byte 1
	.byte 2
	.byte 60
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DUSTOX
	.string "DUSTER$    "
	.string "EVAN$   "
	gfxId 11
	.4byte 0x21000fff
	aiPool 0, 0, 1, 0, 0, 0
	.2byte 318
	.2byte 236
	.2byte 113
	.2byte 16
	.byte 2
	.byte 10
	.byte 10
	.byte 12
	.byte 4
	.byte 70
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SEEDOT
	.string "DOTS$      "
	.string "KELSEY$ "
	gfxId 16
	.4byte 0x20800fff
	aiPool 0, 0, 0, 0, 1, 1
	.2byte 117
	.2byte 235
	.2byte 331
	.2byte 74
	.byte 3
	.byte 3
	.byte 5
	.byte 2
	.byte 7
	.byte 80
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_TAILLOW
	.string "TATAY$     "
	.string "MADISON$"
	gfxId 18
	.4byte 0x80400fff
	aiPool 0, 1, 0, 0, 0, 0
	.2byte 17
	.2byte 97
	.2byte 332
	.2byte 45
	.byte 1
	.byte 3
	.byte 3
	.byte 5
	.byte 4
	.byte 90
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_NINCADA
	.string "NINDA$     "
	.string "RAYMOND$"
	gfxId 44
	.4byte 0x10200fff
	aiPool 0, 0, 0, 0, 1, 0
	.2byte 141
	.2byte 206
	.2byte 154
	.2byte 170
	.byte 5
	.byte 2
	.byte 10
	.byte 7
	.byte 8
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SHROOMISH
	.string "SMISH$     "
	.string "GRANT$  "
	gfxId 35
	.4byte 0x20100fff
	aiPool 0, 0, 0, 0, 1, 0
	.2byte 78
	.2byte 73
	.2byte 72
	.2byte 213
	.byte 3
	.byte 3
	.byte 10
	.byte 2
	.byte 2
	.byte 50
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SPHEAL
	.string "SLEAL$     "
	.string "PAIGE$  "
	gfxId 26
	.4byte 0x8080fff
	aiPool 0, 0, 1, 1, 0, 0
	.2byte 62
	.2byte 55
	.2byte 45
	.2byte 317
	.byte 3
	.byte 5
	.byte 1
	.byte 10
	.byte 10
	.byte 60
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SLAKOTH
	.string "SLOKTH$    "
	.string "ALEC$   "
	gfxId 31
	.4byte 0x40040fff
	aiPool 0, 0, 1, 1, 0, 1
	.2byte 70
	.2byte 68
	.2byte 281
	.2byte 227
	.byte 10
	.byte 4
	.byte 4
	.byte 5
	.byte 18
	.byte 70
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_WHISMUR
	.string "WHIRIS$    "
	.string "SYDNEY$ "
	gfxId 47
	.4byte 0x80020fff
	aiPool 0, 1, 0, 0, 1, 0
	.2byte 310
	.2byte 103
	.2byte 253
	.2byte 304
	.byte 2
	.byte 2
	.byte 7
	.byte 2
	.byte 7
	.byte 80
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MAKUHITA
	.string "MAHITA$    "
	.string "MORRIS$ "
	gfxId 38
	.4byte 0x8010fff
	aiPool 0, 1, 0, 0, 0, 1
	.2byte 69
	.2byte 233
	.2byte 33
	.2byte 179
	.byte 9
	.byte 1
	.byte 1
	.byte 8
	.byte 1
	.byte 90
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ARON
	.string "RONAR$     "
	.string "MARIAH$ "
	gfxId 10
	.4byte 0x8008fff
	aiPool 0, 1, 0, 0, 0, 1
	.2byte 232
	.2byte 334
	.2byte 29
	.2byte 36
	.byte 5
	.byte 10
	.byte 2
	.byte 10
	.byte 2
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_CROBAT
	.string "BATRO$     "
	.string "RUSSELL$"
	gfxId 33
	.4byte 0x90004fff
	aiPool 0, 0, 1, 1, 1, 0
	.2byte 114
	.2byte 212
	.2byte 109
	.2byte 141
	.byte 4
	.byte 2
	.byte 2
	.byte 2
	.byte 10
	.byte 50
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_GULPIN
	.string "GULIN$     "
	.string "MELANIE$"
	gfxId 6
	.4byte 0x40002fff
	aiPool 0, 0, 0, 1, 0, 0
	.2byte 124
	.2byte 133
	.2byte 92
	.2byte 281
	.byte 1
	.byte 10
	.byte 1
	.byte 10
	.byte 5
	.byte 60
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MANECTRIC
	.string "RIKELEC$   "
	.string "CHANCE$ "
	gfxId 15
	.4byte 0x80001fff
	aiPool 0, 1, 1, 0, 0, 0
	.2byte 209
	.2byte 86
	.2byte 87
	.2byte 46
	.byte 20
	.byte 10
	.byte 1
	.byte 1
	.byte 1
	.byte 70
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BULBASAUR
	.string "BULBY$     "
	.string "AGATHA$ "
	gfxId 20
	.4byte 0xc000fff
	aiPool 0, 0, 0, 1, 1, 0
	.2byte 45
	.2byte 73
	.2byte 33
	.2byte 230
	.byte 5
	.byte 3
	.byte 10
	.byte 10
	.byte 4
	.byte 50
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BUTTERFREE
	.string "FUTTERBE$  "
	.string "BEAU$   "
	gfxId 40
	.4byte 0x82000fff
	aiPool 0, 0, 1, 0, 1, 0
	.2byte 48
	.2byte 18
	.2byte 318
	.2byte 219
	.byte 3
	.byte 10
	.byte 2
	.byte 10
	.byte 4
	.byte 60
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_PIDGEOTTO
	.string "PIDEOT$    "
	.string "KAY$    "
	gfxId 34
	.4byte 0x21000fff
	aiPool 0, 1, 1, 0, 0, 0
	.2byte 119
	.2byte 98
	.2byte 332
	.2byte 297
	.byte 10
	.byte 8
	.byte 4
	.byte 2
	.byte 3
	.byte 70
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DIGLETT
	.string "DIGLE$     "
	.string "CALE$   "
	gfxId 55
	.4byte 0x20800fff
	aiPool 0, 0, 0, 0, 1, 1
	.2byte 91
	.2byte 89
	.2byte 90
	.2byte 222
	.byte 4
	.byte 2
	.byte 3
	.byte 5
	.byte 10
	.byte 80
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_POLIWAG
	.string "WAGIL$     "
	.string "CAITLIN$"
	gfxId 53
	.4byte 0x80400fff
	aiPool 0, 0, 1, 0, 0, 1
	.2byte 56
	.2byte 240
	.2byte 34
	.2byte 58
	.byte 2
	.byte 10
	.byte 5
	.byte 3
	.byte 10
	.byte 90
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_TOTODILE
	.string "TOTDIL$    "
	.string "COLBY$  "
	gfxId 5
	.4byte 0x10200fff
	aiPool 0, 1, 1, 0, 0, 0
	.2byte 99
	.2byte 103
	.2byte 57
	.2byte 59
	.byte 6
	.byte 10
	.byte 2
	.byte 1
	.byte 5
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LEDYBA
	.string "BALEDY$    "
	.string "KYLIE$  "
	gfxId 45
	.4byte 0x20100fff
	aiPool 0, 1, 0, 1, 0, 0
	.2byte 226
	.2byte 97
	.2byte 129
	.2byte 213
	.byte 8
	.byte 6
	.byte 8
	.byte 6
	.byte 2
	.byte 90
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DELIBIRD
	.string "BIRDLY$    "
	.string "LIAM$   "
	gfxId 66
	.4byte 0x8080fff
	aiPool 0, 0, 0, 1, 1, 1
	.2byte 217
	.2byte 263
	.2byte 264
	.2byte 216
	.byte 4
	.byte 3
	.byte 10
	.byte 5
	.byte 3
	.byte 80
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LARVITAR
	.string "TARVITAR$  "
	.string "MILO$   "
	gfxId 39
	.4byte 0x40040fff
	aiPool 0, 0, 0, 0, 0, 1
	.2byte 37
	.2byte 259
	.2byte 242
	.2byte 91
	.byte 8
	.byte 5
	.byte 5
	.byte 8
	.byte 10
	.byte 70
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ROSELIA
	.string "RELIA$     "
	.string "KARINA$ "
	gfxId 32
	.4byte 0x24000fff
	aiPool 1, 0, 1, 0, 1, 0
	.2byte 80
	.2byte 345
	.2byte 320
	.2byte 275
	.byte 50
	.byte 15
	.byte 75
	.byte 10
	.byte 20
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DODRIO
	.string "DUODO$     "
	.string "BOBBY$  "
	gfxId 51
	.4byte 0x82000fff
	aiPool 1, 1, 1, 1, 1, 1
	.2byte 64
	.2byte 31
	.2byte 216
	.2byte 45
	.byte 15
	.byte 21
	.byte 15
	.byte 85
	.byte 35
	.byte 110
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_TRAPINCH
	.string "PINCHIN$   "
	.string "CLAIRE$ "
	gfxId 8
	.4byte 0x81000fff
	aiPool 1, 0, 0, 1, 1, 1
	.2byte 44
	.2byte 28
	.2byte 91
	.2byte 185
	.byte 75
	.byte 25
	.byte 25
	.byte 10
	.byte 25
	.byte 120
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_CACNEA
	.string "NACAC$     "
	.string "WILLIE$ "
	gfxId 11
	.4byte 0x80800fff
	aiPool 1, 1, 0, 0, 1, 0
	.2byte 191
	.2byte 43
	.2byte 40
	.2byte 28
	.byte 10
	.byte 30
	.byte 25
	.byte 65
	.byte 25
	.byte 130
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SANDSLASH
	.string "SHRAND$    "
	.string "CASSIDY$"
	gfxId 18
	.4byte 0x10400fff
	aiPool 1, 1, 0, 0, 0, 1
	.2byte 163
	.2byte 111
	.2byte 129
	.2byte 154
	.byte 30
	.byte 90
	.byte 30
	.byte 10
	.byte 100
	.byte 140
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BALTOY
	.string "TOYBAL$    "
	.string "MORGAN$ "
	gfxId 44
	.4byte 0x8200fff
	aiPool 1, 0, 1, 0, 1, 0
	.2byte 120
	.2byte 317
	.2byte 60
	.2byte 93
	.byte 50
	.byte 40
	.byte 10
	.byte 35
	.byte 35
	.byte 150
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MEDICHAM
	.string "CHAMCHAM$  "
	.string "SUMMER$ "
	gfxId 26
	.4byte 0x10100fff
	aiPool 1, 1, 1, 0, 0, 1
	.2byte 179
	.2byte 9
	.2byte 7
	.2byte 8
	.byte 40
	.byte 20
	.byte 40
	.byte 40
	.byte 40
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SPINDA
	.string "SPININ$    "
	.string "MILES$  "
	gfxId 31
	.4byte 0x80080fff
	aiPool 1, 0, 0, 1, 1, 0
	.2byte 298
	.2byte 244
	.2byte 95
	.2byte 253
	.byte 25
	.byte 75
	.byte 25
	.byte 10
	.byte 25
	.byte 110
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SWABLU
	.string "SWABY$     "
	.string "AUDREY$ "
	gfxId 47
	.4byte 0xa0040fff
    aiPool 1, 0, 1, 0, 1, 0
	.2byte 119
	.2byte 195
	.2byte 219
	.2byte 54
	.byte 30
	.byte 30
	.byte 40
	.byte 30
	.byte 25
	.byte 120
    unk2C
	.4byte 0x0
	.4byte 0xffff
    
	.2byte SPECIES_SPOINK
	.string "POINKER$   "
	.string "AVERY$  "
	gfxId 38
	.4byte 0x80020fff
	aiPool 1, 0, 0, 1, 1, 0
	.2byte 150
	.2byte 109
	.2byte 173
	.2byte 156
	.byte 40
	.byte 10
	.byte 30
	.byte 40
	.byte 30
	.byte 130
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_KECLEON
	.string "KECON$     "
	.string "ARIANA$ "
	gfxId 10
	.4byte 0x80010fff
	aiPool 1, 0, 0, 0, 1, 1
	.2byte 168
	.2byte 103
	.2byte 246
	.2byte 20
	.byte 10
	.byte 10
	.byte 40
	.byte 75
	.byte 35
	.byte 140
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_GOLDEEN
	.string "GOLDEN$    "
	.string "ASHTON$ "
	gfxId 33
	.4byte 0x80008fff
	aiPool 1, 1, 1, 0, 0, 0
	.2byte 30
	.2byte 31
	.2byte 32
	.2byte 39
	.byte 70
	.byte 30
	.byte 5
	.byte 30
	.byte 25
	.byte 150
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BARBOACH
	.string "BOBOACH$   "
	.string "SANDRA$ "
	gfxId 6
	.4byte 0x80004fff
	aiPool 1, 0, 0, 1, 1, 1
	.2byte 300
	.2byte 346
	.2byte 89
	.2byte 248
	.byte 45
	.byte 45
	.byte 60
	.byte 25
	.byte 15
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SKARMORY
	.string "CORPY$     "
	.string "CARSON$ "
	gfxId 35
	.4byte 0x8002fff
	aiPool 1, 1, 1, 0, 0, 1
	.2byte 129
	.2byte 104
	.2byte 97
	.2byte 15
	.byte 40
	.byte 30
	.byte 25
	.byte 60
	.byte 20
	.byte 110
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LOTAD
	.string "TADO$      "
	.string "KATRINA$"
	gfxId 16
	.4byte 0x8001fff
	aiPool 1, 0, 1, 1, 1, 0
	.2byte 310
	.2byte 45
	.2byte 240
	.2byte 352
	.byte 15
	.byte 15
	.byte 30
	.byte 15
	.byte 75
	.byte 120
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SLOWBRO
	.string "BROWLO$    "
	.string "LUKE$   "
	gfxId 17
	.4byte 0xc000fff
	aiPool 1, 0, 0, 1, 1, 0
	.2byte 281
	.2byte 50
	.2byte 45
	.2byte 93
	.byte 20
	.byte 40
	.byte 40
	.byte 30
	.byte 20
	.byte 100
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_FARFETCHD
	.string "FETCHIN$   "
	.string "RAUL$   "
	gfxId 66
	.4byte 0x82000fff
	aiPool 1, 1, 0, 1, 0, 0
	.2byte 263
	.2byte 210
	.2byte 19
	.2byte 216
	.byte 40
	.byte 10
	.byte 40
	.byte 20
	.byte 20
	.byte 110
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SEEL
	.string "SEELEY$    "
	.string "JADA$   "
	gfxId 20
	.4byte 0x21000fff
	aiPool 1, 0, 1, 1, 0, 0
	.2byte 213
	.2byte 58
	.2byte 219
	.2byte 45
	.byte 10
	.byte 30
	.byte 40
	.byte 20
	.byte 20
	.byte 120
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DROWZEE
	.string "DROWZIN$   "
	.string "ZEEK$   "
	gfxId 37
	.4byte 0x20800fff
	aiPool 1, 0, 1, 1, 1, 1
	.2byte 50
	.2byte 248
	.2byte 237
	.2byte 216
	.byte 10
	.byte 40
	.byte 50
	.byte 30
	.byte 45
	.byte 130
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_HITMONCHAN
	.string "HITEMON$   "
	.string "DIEGO$  "
	gfxId 21
	.4byte 0x80400fff
	aiPool 1, 1, 0, 0, 0, 1
	.2byte 327
	.2byte 197
	.2byte 279
	.2byte 5
	.byte 45
	.byte 20
	.byte 10
	.byte 20
	.byte 45
	.byte 140
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BLISSEY
	.string "BLISS$     "
	.string "ALIYAH$ "
	gfxId 85
	.4byte 0x10200fff
	aiPool 1, 0, 1, 1, 0, 1
	.2byte 47
	.2byte 135
	.2byte 121
	.2byte 38
	.byte 20
	.byte 35
	.byte 40
	.byte 20
	.byte 20
	.byte 150
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ELEKID
	.string "KIDLEK$    "
	.string "NATALIA$"
	gfxId 18
	.4byte 0x20100fff
	aiPool 1, 1, 0, 1, 0, 0
	.2byte 351
	.2byte 98
	.2byte 103
	.2byte 213
	.byte 40
	.byte 10
	.byte 40
	.byte 25
	.byte 25
	.byte 140
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SNUBBULL
	.string "SNUBBINS$  "
	.string "DEVIN$  "
	gfxId 48
	.4byte 0x8080fff
	aiPool 1, 0, 0, 1, 0, 1
	.2byte 184
	.2byte 269
	.2byte 39
	.2byte 44
	.byte 20
	.byte 20
	.byte 20
	.byte 20
	.byte 20
	.byte 130
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MISDREAVUS
	.string "DREAVIS$   "
	.string "TYLOR$  "
	gfxId 40
	.4byte 0x40040fff
	aiPool 1, 0, 1, 0, 1, 0
	.2byte 195
	.2byte 212
	.2byte 109
	.2byte 220
	.byte 10
	.byte 35
	.byte 10
	.byte 45
	.byte 20
	.byte 120
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LAIRON
	.string "LAIRN$     "
	.string "RONNIE$ "
	gfxId 55
	.4byte 0x84000fff
	aiPool 2, 0, 0, 0, 1, 1
	.2byte 319
	.2byte 232
	.2byte 106
	.2byte 36
	.byte 30
	.byte 50
	.byte 35
	.byte 100
	.byte 90
	.byte 200
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SHIFTRY
	.string "SHIFTY$    "
	.string "CLAUDIA$"
	gfxId 8
	.4byte 0x82000fff
	aiPool 2, 1, 1, 0, 0, 0
	.2byte 74
	.2byte 13
	.2byte 153
	.2byte 326
	.byte 75
	.byte 75
	.byte 65
	.byte 35
	.byte 70
	.byte 210
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_NINJASK
	.string "NINAS$     "
	.string "ELIAS$  "
	gfxId 11
	.4byte 0x81000fff
	aiPool 2, 0, 0, 1, 1, 1
	.2byte 103
	.2byte 154
	.2byte 28
	.2byte 226
	.byte 30
	.byte 50
	.byte 95
	.byte 70
	.byte 70
	.byte 220
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SWELLOW
	.string "WELOW$     "
	.string "JADE$   "
	gfxId 18
	.4byte 0x80800fff
	aiPool 2, 1, 1, 0, 0, 0
	.2byte 97
	.2byte 332
	.2byte 17
	.2byte 19
	.byte 65
	.byte 85
	.byte 35
	.byte 75
	.byte 40
	.byte 230
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MIGHTYENA
	.string "YENA$      "
	.string "FRANCIS$"
	gfxId 44
	.4byte 0x80400fff
	aiPool 2, 0, 0, 0, 1, 1
	.2byte 269
	.2byte 168
	.2byte 316
	.2byte 36
	.byte 40
	.byte 80
	.byte 35
	.byte 70
	.byte 70
	.byte 240
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BEAUTIFLY
	.string "TIFLY$     "
	.string "ALISHA$ "
	gfxId 26
	.4byte 0x80200fff
	aiPool 2, 0, 1, 0, 1, 0
	.2byte 234
	.2byte 318
	.2byte 78
	.2byte 290
	.byte 40
	.byte 70
	.byte 25
	.byte 80
	.byte 100
	.byte 250
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SEAKING
	.string "KINGSEA$   "
	.string "SAUL$   "
	gfxId 31
	.4byte 0x80100fff
	aiPool 2, 1, 0, 1, 1, 1
	.2byte 175
	.2byte 48
	.2byte 30
	.2byte 31
	.byte 80
	.byte 60
	.byte 30
	.byte 70
	.byte 90
	.byte 200
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_CASTFORM
	.string "CASTER$    "
	.string "FELICIA$"
	gfxId 47
	.4byte 0x80080fff
	aiPool 2, 1, 1, 1, 1, 1
	.2byte 241
	.2byte 311
	.2byte 201
	.2byte 216
	.byte 70
	.byte 80
	.byte 80
	.byte 50
	.byte 65
	.byte 210
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MACHOKE
	.string "CHOKEM$    "
	.string "EMILIO$ "
	gfxId 38
	.4byte 0x80040fff
	aiPool 2, 1, 0, 0, 0, 1
	.2byte 69
	.2byte 116
	.2byte 2
	.2byte 184
	.byte 70
	.byte 85
	.byte 25
	.byte 60
	.byte 50
	.byte 220
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LOMBRE
	.string "LOMBE$     "
	.string "KARLA$  "
	gfxId 10
	.4byte 0x80020fff
	aiPool 2, 0, 1, 1, 1, 0
	.2byte 213
	.2byte 148
	.2byte 253
	.2byte 45
	.byte 40
	.byte 60
	.byte 90
	.byte 45
	.byte 70
	.byte 230
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SEVIPER
	.string "VIPES$     "
	.string "DARRYL$ "
	gfxId 33
	.4byte 0x80010fff
	aiPool 2, 0, 0, 0, 1, 1
	.2byte 305
	.2byte 137
	.2byte 35
	.2byte 103
	.byte 35
	.byte 50
	.byte 90
	.byte 40
	.byte 100
	.byte 240
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_WAILMER
	.string "MERAIL$    "
	.string "SELENA$ "
	gfxId 22
	.4byte 0x80008fff
	aiPool 2, 0, 1, 1, 0, 0
	.2byte 352
	.2byte 156
	.2byte 323
	.2byte 150
	.byte 30
	.byte 100
	.byte 100
	.byte 50
	.byte 30
	.byte 250
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MAGIKARP
	.string "KARPAG$    "
	.string "NOEL$   "
	gfxId 35
	.4byte 0x80004fff
	aiPool 2, 0, 0, 1, 0, 1
	.2byte 33
	.2byte 150
	.2byte 175
	.2byte 33
	.byte 30
	.byte 30
	.byte 160
	.byte 50
	.byte 160
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LUNATONE
	.string "LUNONE$    "
	.string "LACEY$  "
	gfxId 16
	.4byte 0x80002fff
	aiPool 2, 0, 1, 0, 1, 0
	.2byte 153
	.2byte 248
	.2byte 94
	.2byte 93
	.byte 50
	.byte 70
	.byte 60
	.byte 70
	.byte 50
	.byte 210
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ABSOL
	.string "ABSO$      "
	.string "CORBIN$ "
	gfxId 39
	.4byte 0x80001fff
	aiPool 2, 1, 1, 0, 0, 0
	.2byte 195
	.2byte 258
	.2byte 63
	.2byte 163
	.byte 95
	.byte 80
	.byte 85
	.byte 35
	.byte 35
	.byte 220
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_EXEGGUTOR
	.string "EGGSOR$    "
	.string "GRACIE$ "
	gfxId 32
	.4byte 0xc000fff
	aiPool 2, 0, 0, 0, 1, 1
	.2byte 23
	.2byte 95
	.2byte 121
	.2byte 285
	.byte 40
	.byte 50
	.byte 60
	.byte 100
	.byte 80
	.byte 200
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_CUBONE
	.string "CUBIN$     "
	.string "COLTIN$ "
	gfxId 65
	.4byte 0x82000fff
	aiPool 2, 0, 0, 1, 0, 1
	.2byte 125
	.2byte 155
	.2byte 198
	.2byte 45
	.byte 40
	.byte 35
	.byte 85
	.byte 35
	.byte 100
	.byte 210
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_HITMONLEE
	.string "HITMON$    "
	.string "ELLIE$  "
	gfxId 22
	.4byte 0x21000fff
	aiPool 2, 1, 0, 0, 0, 1
	.2byte 179
	.2byte 279
	.2byte 116
	.2byte 25
	.byte 85
	.byte 30
	.byte 25
	.byte 50
	.byte 100
	.byte 220
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SQUIRTLE
	.string "SURTLE$    "
	.string "MARCUS$ "
	gfxId 49
	.4byte 0x20800fff
	aiPool 2, 0, 0, 1, 0, 1
	.2byte 39
	.2byte 145
	.2byte 264
	.2byte 110
	.byte 30
	.byte 35
	.byte 100
	.byte 40
	.byte 95
	.byte 230
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_KANGASKHAN
	.string "KHANKAN$   "
	.string "KIARA$  "
	gfxId 14
	.4byte 0x80400fff
	aiPool 2, 1, 0, 0, 0, 1
	.2byte 5
	.2byte 99
	.2byte 264
	.2byte 39
	.byte 100
	.byte 50
	.byte 30
	.byte 50
	.byte 100
	.byte 240
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_PINECO
	.string "PINOC$     "
	.string "BRYCE$  "
	gfxId 36
	.4byte 0x10200fff
	aiPool 2, 0, 1, 0, 1, 0
	.2byte 153
	.2byte 191
	.2byte 113
	.2byte 202
	.byte 80
	.byte 80
	.byte 80
	.byte 80
	.byte 80
	.byte 250
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DUNSPARCE
	.string "DILTOT$    "
	.string "JAMIE$  "
	gfxId 34
	.4byte 0x20100fff
	aiPool 2, 0, 0, 1, 0, 1
	.2byte 180
	.2byte 281
	.2byte 111
	.2byte 36
	.byte 40
	.byte 35
	.byte 100
	.byte 40
	.byte 110
	.byte 240
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_HOUNDOOM
	.string "DOOMOND$   "
	.string "JORGE$  "
	gfxId 48
	.4byte 0x8080fff
	aiPool 2, 1, 1, 0, 0, 0
	.2byte 46
	.2byte 53
	.2byte 185
	.2byte 241
	.byte 100
	.byte 100
	.byte 30
	.byte 25
	.byte 80
	.byte 230
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MILTANK
	.string "MILKAN$    "
	.string "DEVON$  "
	gfxId 25
	.4byte 0x40040fff
	aiPool 2, 0, 1, 1, 0, 0
	.2byte 208
	.2byte 215
	.2byte 111
	.2byte 59
	.byte 50
	.byte 110
	.byte 100
	.byte 35
	.byte 40
	.byte 220
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_GYARADOS
	.string "RADOS$     "
	.string "JUSTINA$"
	gfxId 32
	.4byte 0x84000fff
	aiPool 3, 1, 1, 0, 0, 1
	.2byte 63
	.2byte 56
	.2byte 240
	.2byte 44
	.byte 160
	.byte 200
	.byte 20
	.byte 40
	.byte 160
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LOUDRED
	.string "LOUDERD$   "
	.string "RALPH$  "
	gfxId 21
	.4byte 0x82000fff
	aiPool 3, 1, 0, 0, 0, 1
	.2byte 304
	.2byte 23
	.2byte 46
	.2byte 336
	.byte 170
	.byte 50
	.byte 55
	.byte 150
	.byte 160
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SKITTY
	.string "SITTY$     "
	.string "ROSA$   "
	gfxId 8
	.4byte 0x81000fff
	aiPool 3, 0, 1, 1, 1, 0
	.2byte 213
	.2byte 274
	.2byte 185
	.2byte 39
	.byte 40
	.byte 200
	.byte 150
	.byte 185
	.byte 60
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SLAKING
	.string "SLING$     "
	.string "KEATON$ "
	gfxId 11
	.4byte 0x80800fff
	aiPool 3, 0, 0, 1, 1, 1
	.2byte 343
	.2byte 68
	.2byte 227
	.2byte 303
	.byte 85
	.byte 85
	.byte 170
	.byte 110
	.byte 150
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ALTARIA
	.string "TARIA$     "
	.string "MAYRA$  "
	gfxId 18
	.4byte 0x80400fff
	aiPool 3, 1, 1, 0, 0, 0
	.2byte 349
	.2byte 63
	.2byte 195
	.2byte 219
	.byte 170
	.byte 150
	.byte 30
	.byte 30
	.byte 90
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_KIRLIA
	.string "LIRKI$     "
	.string "LAMAR$  "
	gfxId 15
	.4byte 0x80200fff
	aiPool 3, 1, 0, 0, 1, 0
	.2byte 351
	.2byte 247
	.2byte 285
	.2byte 216
	.byte 230
	.byte 60
	.byte 60
	.byte 230
	.byte 80
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_BELLOSSOM
	.string "BLOSSOM$   "
	.string "AUBREY$ "
	gfxId 26
	.4byte 0x80100fff
	aiPool 3, 0, 1, 1, 1, 0
	.2byte 80
	.2byte 230
	.2byte 78
	.2byte 148
	.byte 35
	.byte 200
	.byte 150
	.byte 130
	.byte 40
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SABLEYE
	.string "EYESAB$    "
	.string "NIGEL$  "
	gfxId 31
	.4byte 0x80080fff
	aiPool 3, 0, 0, 1, 1, 1
	.2byte 212
	.2byte 185
	.2byte 282
	.2byte 109
	.byte 25
	.byte 35
	.byte 230
	.byte 150
	.byte 160
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_NATU
	.string "UTAN$      "
	.string "CAMILLE$"
	gfxId 47
	.4byte 0x80040fff
	aiPool 3, 0, 0, 1, 1, 1
	.2byte 101
	.2byte 248
	.2byte 109
	.2byte 94
	.byte 35
	.byte 35
	.byte 150
	.byte 130
	.byte 170
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SHARPEDO
	.string "PEDOS$     "
	.string "DEON$   "
	gfxId 38
	.4byte 0x80020fff
	aiPool 3, 1, 0, 1, 0, 1
	.2byte 97
	.2byte 207
	.2byte 269
	.2byte 36
	.byte 140
	.byte 70
	.byte 140
	.byte 75
	.byte 100
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_LUVDISC
	.string "LUVIS$     "
	.string "JANELLE$"
	gfxId 10
	.4byte 0x80010fff
	aiPool 3, 0, 0, 1, 0, 1
	.2byte 186
	.2byte 213
	.2byte 36
	.2byte 204
	.byte 50
	.byte 100
	.byte 220
	.byte 40
	.byte 190
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_HERACROSS
	.string "HEROSS$    "
	.string "HEATH$  "
	gfxId 33
	.4byte 0x80008fff
	aiPool 3, 1, 0, 0, 0, 1
	.2byte 70
	.2byte 203
	.2byte 179
	.2byte 317
	.byte 170
	.byte 70
	.byte 110
	.byte 240
	.byte 140
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ELECTRODE
	.string "RODLECT$   "
	.string "SASHA$  "
	gfxId 6
	.4byte 0x80004fff
	aiPool 3, 1, 1, 0, 0, 0
	.2byte 153
	.2byte 113
	.2byte 129
	.2byte 148
	.byte 200
	.byte 200
	.byte 30
	.byte 35
	.byte 50
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_PICHU
	.string "CHUPY$     "
	.string "FRANKIE$"
	gfxId 35
	.4byte 0x80002fff
	aiPool 3, 0, 1, 1, 1, 0
	.2byte 186
	.2byte 213
	.2byte 156
	.2byte 39
	.byte 25
	.byte 150
	.byte 180
	.byte 115
	.byte 120
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_WOBBUFFET
	.string "WOBET$     "
	.string "HELEN$  "
	gfxId 16
	.4byte 0x80001fff
	aiPool 3, 1, 1, 0, 1, 1
	.2byte 68
	.2byte 243
	.2byte 219
	.2byte 194
	.byte 60
	.byte 230
	.byte 50
	.byte 220
	.byte 210
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_GENGAR
	.string "GAREN$     "
	.string "CAMILE$ "
	gfxId 40
	.4byte 0xc000fff
	aiPool 3, 1, 0, 0, 0, 1
	.2byte 194
	.2byte 109
	.2byte 122
	.2byte 188
	.byte 200
	.byte 100
	.byte 50
	.byte 80
	.byte 180
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_PORYGON
	.string "GONPOR$    "
	.string "MARTIN$ "
	gfxId 46
	.4byte 0x82000fff
	aiPool 3, 1, 1, 1, 1, 1
	.2byte 176
	.2byte 160
	.2byte 216
	.2byte 278
	.byte 130
	.byte 130
	.byte 130
	.byte 130
	.byte 130
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_DRAGONITE
	.string "DRITE$     "
	.string "SERGIO$ "
	gfxId 7
	.4byte 0x21000fff
	aiPool 3, 1, 0, 0, 0, 1
	.2byte 200
	.2byte 21
	.2byte 239
	.2byte 89
	.byte 150
	.byte 140
	.byte 50
	.byte 120
	.byte 150
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_MEOWTH
	.string "MEOWY$     "
	.string "KAILEY$ "
	gfxId 6
	.4byte 0x20800fff
	aiPool 3, 0, 0, 1, 1, 0
	.2byte 45
	.2byte 269
	.2byte 6
	.2byte 44
	.byte 125
	.byte 110
	.byte 180
	.byte 170
	.byte 80
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_JYNX
	.string "NYX$       "
	.string "PERLA$  "
	gfxId 45
	.4byte 0x80400fff
	aiPool 3, 0, 1, 0, 1, 0
	.2byte 195
	.2byte 212
	.2byte 142
	.2byte 313
	.byte 100
	.byte 150
	.byte 100
	.byte 150
	.byte 120
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_TOGEPI
	.string "GEPITO$    "
	.string "CLARA$  "
	gfxId 20
	.4byte 0x10200fff
	aiPool 3, 0, 0, 1, 0, 0
	.2byte 45
	.2byte 281
	.2byte 227
	.2byte 266
	.byte 80
	.byte 120
	.byte 200
	.byte 120
	.byte 80
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_ESPEON
	.string "SPEON$     "
	.string "JAKOB$  "
	gfxId 37
	.4byte 0x20100fff
	aiPool 3, 1, 1, 0, 0, 0
	.2byte 129
	.2byte 98
	.2byte 234
	.2byte 39
	.byte 180
	.byte 150
	.byte 100
	.byte 80
	.byte 150
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_SLOWKING
	.string "SLOWGO$    "
	.string "TREY$   "
	gfxId 49
	.4byte 0x8080fff
	aiPool 3, 0, 0, 1, 0, 1
	.2byte 263
	.2byte 174
	.2byte 281
	.2byte 264
	.byte 100
	.byte 80
	.byte 200
	.byte 110
	.byte 170
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

	.2byte SPECIES_URSARING
	.string "URSING$    "
	.string "LANE$   "
	gfxId 44
	.4byte 0x40040fff
	aiPool 3, 1, 0, 0, 0, 1
	.2byte 37
	.2byte 332
	.2byte 313
	.2byte 43
	.byte 180
	.byte 140
	.byte 30
	.byte 80
	.byte 190
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

