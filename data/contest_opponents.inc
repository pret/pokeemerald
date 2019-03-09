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
	.2byte MOVE_ROAR
	.2byte MOVE_BITE
	.2byte MOVE_TAKE_DOWN
	.2byte MOVE_HOWL
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
	.2byte MOVE_REST
	.2byte MOVE_FACADE
	.2byte MOVE_TACKLE
	.2byte MOVE_COVET
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
	.2byte MOVE_SILVER_WIND
	.2byte MOVE_MOONLIGHT
	.2byte MOVE_LIGHT_SCREEN
	.2byte MOVE_GUST
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
	.2byte MOVE_BIDE
	.2byte MOVE_SYNTHESIS
	.2byte MOVE_BULLET_SEED
	.2byte MOVE_GROWTH
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
	.2byte MOVE_WING_ATTACK
	.2byte MOVE_AGILITY
	.2byte MOVE_AERIAL_ACE
	.2byte MOVE_GROWL
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
	.2byte MOVE_LEECH_LIFE
	.2byte MOVE_FALSE_SWIPE
	.2byte MOVE_FURY_SWIPES
	.2byte MOVE_MIND_READER
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
	.2byte MOVE_STUN_SPORE
	.2byte MOVE_LEECH_SEED
	.2byte MOVE_MEGA_DRAIN
	.2byte MOVE_ATTRACT
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
	.2byte MOVE_AURORA_BEAM
	.2byte MOVE_WATER_GUN
	.2byte MOVE_GROWL
	.2byte MOVE_ROCK_TOMB
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
	.2byte MOVE_STRENGTH
	.2byte MOVE_COUNTER
	.2byte MOVE_YAWN
	.2byte MOVE_ENCORE
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
	.2byte MOVE_ASTONISH
	.2byte MOVE_SCREECH
	.2byte MOVE_UPROAR
	.2byte MOVE_HYPER_VOICE
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
	.2byte MOVE_SEISMIC_TOSS
	.2byte MOVE_VITAL_THROW
	.2byte MOVE_TACKLE
	.2byte MOVE_REVERSAL
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
	.2byte MOVE_METAL_CLAW
	.2byte MOVE_IRON_DEFENSE
	.2byte MOVE_HEADBUTT
	.2byte MOVE_TAKE_DOWN
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
	.2byte MOVE_HAZE
	.2byte MOVE_MEAN_LOOK
	.2byte MOVE_CONFUSE_RAY
	.2byte MOVE_LEECH_LIFE
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
	.2byte MOVE_SLUDGE
	.2byte MOVE_AMNESIA
	.2byte MOVE_TOXIC
	.2byte MOVE_YAWN
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
	.2byte MOVE_SPARK
	.2byte MOVE_THUNDER_WAVE
	.2byte MOVE_THUNDER
	.2byte MOVE_ROAR
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
	.2byte MOVE_GROWL
	.2byte MOVE_LEECH_SEED
	.2byte MOVE_TACKLE
	.2byte MOVE_SWEET_SCENT
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
	.2byte MOVE_SUPERSONIC
	.2byte MOVE_WHIRLWIND
	.2byte MOVE_SILVER_WIND
	.2byte MOVE_SAFEGUARD
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
	.2byte MOVE_MIRROR_MOVE
	.2byte MOVE_QUICK_ATTACK
	.2byte MOVE_AERIAL_ACE
	.2byte MOVE_FEATHER_DANCE
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
	.2byte MOVE_DIG
	.2byte MOVE_EARTHQUAKE
	.2byte MOVE_FISSURE
	.2byte MOVE_MAGNITUDE
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
	.2byte MOVE_HYDRO_PUMP
	.2byte MOVE_RAIN_DANCE
	.2byte MOVE_BODY_SLAM
	.2byte MOVE_ICE_BEAM
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
	.2byte MOVE_RAGE
	.2byte MOVE_SCREECH
	.2byte MOVE_SURF
	.2byte MOVE_BLIZZARD
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
	.2byte MOVE_BATON_PASS
	.2byte MOVE_AGILITY
	.2byte MOVE_SWIFT
	.2byte MOVE_ATTRACT
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
	.2byte MOVE_PRESENT
	.2byte MOVE_FACADE
	.2byte MOVE_FOCUS_PUNCH
	.2byte MOVE_RETURN
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
	.2byte MOVE_THRASH
	.2byte MOVE_TORMENT
	.2byte MOVE_CRUNCH
	.2byte MOVE_DIG
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
	.2byte MOVE_PETAL_DANCE
	.2byte MOVE_MAGICAL_LEAF
	.2byte MOVE_GRASS_WHISTLE
	.2byte MOVE_INGRAIN
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
	.2byte MOVE_PECK
	.2byte MOVE_FURY_ATTACK
	.2byte MOVE_RETURN
	.2byte MOVE_GROWL
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
	.2byte MOVE_BITE
	.2byte MOVE_SAND_ATTACK
	.2byte MOVE_DIG
	.2byte MOVE_FAINT_ATTACK
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
	.2byte MOVE_SPIKES
	.2byte MOVE_LEER
	.2byte MOVE_POISON_STING
	.2byte MOVE_SAND_ATTACK
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
	.2byte MOVE_SLASH
	.2byte MOVE_DEFENSE_CURL
	.2byte MOVE_SWIFT
	.2byte MOVE_FURY_SWIPES
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
	.2byte MOVE_SELF_DESTRUCT
	.2byte MOVE_ROCK_TOMB
	.2byte MOVE_PSYBEAM
	.2byte MOVE_CONFUSION
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
	.2byte MOVE_REVERSAL
	.2byte MOVE_THUNDER_PUNCH
	.2byte MOVE_FIRE_PUNCH
	.2byte MOVE_ICE_PUNCH
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
	.2byte MOVE_TEETER_DANCE
	.2byte MOVE_PSYCH_UP
	.2byte MOVE_HYPNOSIS
	.2byte MOVE_UPROAR
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
	.2byte MOVE_MIRROR_MOVE
	.2byte MOVE_PERISH_SONG
	.2byte MOVE_SAFEGUARD
	.2byte MOVE_MIST
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
	.2byte MOVE_THIEF
	.2byte MOVE_SCREECH
	.2byte MOVE_ANCIENT_POWER
	.2byte MOVE_BIND
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
	.2byte MOVE_HORN_ATTACK
	.2byte MOVE_FURY_ATTACK
	.2byte MOVE_HORN_DRILL
	.2byte MOVE_TAIL_WHIP
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
	.2byte MOVE_MUD_SPORT
	.2byte MOVE_WATER_SPORT
	.2byte MOVE_EARTHQUAKE
	.2byte MOVE_FUTURE_SIGHT
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
	.2byte MOVE_SWIFT
	.2byte MOVE_DOUBLE_TEAM
	.2byte MOVE_AGILITY
	.2byte MOVE_CUT
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
	.2byte MOVE_ASTONISH
	.2byte MOVE_GROWL
	.2byte MOVE_RAIN_DANCE
	.2byte MOVE_WATER_PULSE
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
	.2byte MOVE_YAWN
	.2byte MOVE_DISABLE
	.2byte MOVE_GROWL
	.2byte MOVE_CONFUSION
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
	.2byte MOVE_FACADE
	.2byte MOVE_FURY_CUTTER
	.2byte MOVE_FLY
	.2byte MOVE_RETURN
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
	.2byte MOVE_ATTRACT
	.2byte MOVE_ICE_BEAM
	.2byte MOVE_SAFEGUARD
	.2byte MOVE_GROWL
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
	.2byte MOVE_DISABLE
	.2byte MOVE_FUTURE_SIGHT
	.2byte MOVE_HIDDEN_POWER
	.2byte MOVE_RETURN
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
	.2byte MOVE_SKY_UPPERCUT
	.2byte MOVE_DETECT
	.2byte MOVE_REVENGE
	.2byte MOVE_MEGA_PUNCH
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
	.2byte MOVE_SING
	.2byte MOVE_SOFT_BOILED
	.2byte MOVE_EGG_BOMB
	.2byte MOVE_DOUBLE_EDGE
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
	.2byte MOVE_SHOCK_WAVE
	.2byte MOVE_QUICK_ATTACK
	.2byte MOVE_SCREECH
	.2byte MOVE_ATTRACT
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
	.2byte MOVE_SCARY_FACE
	.2byte MOVE_TAUNT
	.2byte MOVE_TAIL_WHIP
	.2byte MOVE_BITE
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
	.2byte MOVE_PERISH_SONG
	.2byte MOVE_MEAN_LOOK
	.2byte MOVE_CONFUSE_RAY
	.2byte MOVE_PAIN_SPLIT
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
	.2byte MOVE_METAL_SOUND
	.2byte MOVE_METAL_CLAW
	.2byte MOVE_HARDEN
	.2byte MOVE_TAKE_DOWN
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
	.2byte MOVE_GROWTH
	.2byte MOVE_RAZOR_WIND
	.2byte MOVE_EXPLOSION
	.2byte MOVE_EXTRASENSORY
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
	.2byte MOVE_SCREECH
	.2byte MOVE_FURY_SWIPES
	.2byte MOVE_SAND_ATTACK
	.2byte MOVE_BATON_PASS
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
	.2byte MOVE_AGILITY
	.2byte MOVE_AERIAL_ACE
	.2byte MOVE_WING_ATTACK
	.2byte MOVE_FLY
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
	.2byte MOVE_TAUNT
	.2byte MOVE_THIEF
	.2byte MOVE_ODOR_SLEUTH
	.2byte MOVE_TAKE_DOWN
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
	.2byte MOVE_MORNING_SUN
	.2byte MOVE_SILVER_WIND
	.2byte MOVE_STUN_SPORE
	.2byte MOVE_SECRET_POWER
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
	.2byte MOVE_FLAIL
	.2byte MOVE_SUPERSONIC
	.2byte MOVE_HORN_ATTACK
	.2byte MOVE_FURY_ATTACK
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
	.2byte MOVE_SUNNY_DAY
	.2byte MOVE_WEATHER_BALL
	.2byte MOVE_SANDSTORM
	.2byte MOVE_RETURN
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
	.2byte MOVE_SEISMIC_TOSS
	.2byte MOVE_FOCUS_ENERGY
	.2byte MOVE_KARATE_CHOP
	.2byte MOVE_SCARY_FACE
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
	.2byte MOVE_ATTRACT
	.2byte MOVE_FLASH
	.2byte MOVE_UPROAR
	.2byte MOVE_GROWL
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
	.2byte MOVE_POISON_FANG
	.2byte MOVE_GLARE
	.2byte MOVE_WRAP
	.2byte MOVE_SCREECH
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
	.2byte MOVE_WATER_PULSE
	.2byte MOVE_REST
	.2byte MOVE_WATER_SPOUT
	.2byte MOVE_SPLASH
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
	.2byte MOVE_TACKLE
	.2byte MOVE_SPLASH
	.2byte MOVE_FLAIL
	.2byte MOVE_TACKLE
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
	.2byte MOVE_EXPLOSION
	.2byte MOVE_FUTURE_SIGHT
	.2byte MOVE_PSYCHIC
	.2byte MOVE_CONFUSION
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
	.2byte MOVE_PERISH_SONG
	.2byte MOVE_HAIL
	.2byte MOVE_HYPER_BEAM
	.2byte MOVE_SLASH
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
	.2byte MOVE_STOMP
	.2byte MOVE_HYPNOSIS
	.2byte MOVE_EGG_BOMB
	.2byte MOVE_SKILL_SWAP
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
	.2byte MOVE_BONE_CLUB
	.2byte MOVE_BONEMERANG
	.2byte MOVE_BONE_RUSH
	.2byte MOVE_GROWL
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
	.2byte MOVE_REVERSAL
	.2byte MOVE_REVENGE
	.2byte MOVE_FOCUS_ENERGY
	.2byte MOVE_MEGA_KICK
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
	.2byte MOVE_TAIL_WHIP
	.2byte MOVE_BUBBLE
	.2byte MOVE_FOCUS_PUNCH
	.2byte MOVE_WITHDRAW
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
	.2byte MOVE_MEGA_PUNCH
	.2byte MOVE_RAGE
	.2byte MOVE_FOCUS_PUNCH
	.2byte MOVE_TAIL_WHIP
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
	.2byte MOVE_EXPLOSION
	.2byte MOVE_SPIKES
	.2byte MOVE_LIGHT_SCREEN
	.2byte MOVE_GIGA_DRAIN
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
	.2byte MOVE_SPITE
	.2byte MOVE_YAWN
	.2byte MOVE_DEFENSE_CURL
	.2byte MOVE_TAKE_DOWN
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
	.2byte MOVE_ROAR
	.2byte MOVE_FLAMETHROWER
	.2byte MOVE_FAINT_ATTACK
	.2byte MOVE_SUNNY_DAY
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
	.2byte MOVE_MILK_DRINK
	.2byte MOVE_HEAL_BELL
	.2byte MOVE_DEFENSE_CURL
	.2byte MOVE_BLIZZARD
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
	.2byte MOVE_HYPER_BEAM
	.2byte MOVE_HYDRO_PUMP
	.2byte MOVE_RAIN_DANCE
	.2byte MOVE_BITE
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
	.2byte MOVE_HYPER_VOICE
	.2byte MOVE_STOMP
	.2byte MOVE_ROAR
	.2byte MOVE_HOWL
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
	.2byte MOVE_ATTRACT
	.2byte MOVE_ASSIST
	.2byte MOVE_FAINT_ATTACK
	.2byte MOVE_TAIL_WHIP
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
	.2byte MOVE_COVET
	.2byte MOVE_COUNTER
	.2byte MOVE_ENCORE
	.2byte MOVE_SLACK_OFF
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
	.2byte MOVE_DRAGON_DANCE
	.2byte MOVE_HYPER_BEAM
	.2byte MOVE_PERISH_SONG
	.2byte MOVE_SAFEGUARD
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
	.2byte MOVE_SHOCK_WAVE
	.2byte MOVE_SHADOW_BALL
	.2byte MOVE_SKILL_SWAP
	.2byte MOVE_RETURN
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
	.2byte MOVE_PETAL_DANCE
	.2byte MOVE_SWEET_SCENT
	.2byte MOVE_STUN_SPORE
	.2byte MOVE_FLASH
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
	.2byte MOVE_MEAN_LOOK
	.2byte MOVE_FAINT_ATTACK
	.2byte MOVE_KNOCK_OFF
	.2byte MOVE_CONFUSE_RAY
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
	.2byte MOVE_NIGHT_SHADE
	.2byte MOVE_FUTURE_SIGHT
	.2byte MOVE_CONFUSE_RAY
	.2byte MOVE_PSYCHIC
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
	.2byte MOVE_AGILITY
	.2byte MOVE_SWAGGER
	.2byte MOVE_TAUNT
	.2byte MOVE_TAKE_DOWN
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
	.2byte MOVE_SWEET_KISS
	.2byte MOVE_ATTRACT
	.2byte MOVE_TAKE_DOWN
	.2byte MOVE_CHARM
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
	.2byte MOVE_STRENGTH
	.2byte MOVE_ENDURE
	.2byte MOVE_REVERSAL
	.2byte MOVE_ROCK_TOMB
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
	.2byte MOVE_EXPLOSION
	.2byte MOVE_LIGHT_SCREEN
	.2byte MOVE_SWIFT
	.2byte MOVE_FLASH
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
	.2byte MOVE_SWEET_KISS
	.2byte MOVE_ATTRACT
	.2byte MOVE_REST
	.2byte MOVE_TAIL_WHIP
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
	.2byte MOVE_COUNTER
	.2byte MOVE_MIRROR_COAT
	.2byte MOVE_SAFEGUARD
	.2byte MOVE_DESTINY_BOND
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
	.2byte MOVE_DESTINY_BOND
	.2byte MOVE_CONFUSE_RAY
	.2byte MOVE_LICK
	.2byte MOVE_SLUDGE_BOMB
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
	.2byte MOVE_CONVERSION_2
	.2byte MOVE_CONVERSION
	.2byte MOVE_RETURN
	.2byte MOVE_RECYCLE
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
	.2byte MOVE_OUTRAGE
	.2byte MOVE_SLAM
	.2byte MOVE_TWISTER
	.2byte MOVE_EARTHQUAKE
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
	.2byte MOVE_GROWL
	.2byte MOVE_TAUNT
	.2byte MOVE_PAY_DAY
	.2byte MOVE_BITE
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
	.2byte MOVE_PERISH_SONG
	.2byte MOVE_MEAN_LOOK
	.2byte MOVE_LOVELY_KISS
	.2byte MOVE_FAKE_TEARS
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
	.2byte MOVE_GROWL
	.2byte MOVE_YAWN
	.2byte MOVE_ENCORE
	.2byte MOVE_FOLLOW_ME
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
	.2byte MOVE_SWIFT
	.2byte MOVE_QUICK_ATTACK
	.2byte MOVE_MORNING_SUN
	.2byte MOVE_TAIL_WHIP
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
	.2byte MOVE_FACADE
	.2byte MOVE_CURSE
	.2byte MOVE_YAWN
	.2byte MOVE_FOCUS_PUNCH
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
	.2byte MOVE_THRASH
	.2byte MOVE_AERIAL_ACE
	.2byte MOVE_FAKE_TEARS
	.2byte MOVE_LEER
	.byte 180
	.byte 140
	.byte 30
	.byte 80
	.byte 190
	.byte 255
    unk2C
	.4byte 0x0
	.4byte 0xffff

