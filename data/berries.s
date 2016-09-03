	.align 2, 0

gBerries: @ 858A670
	.string "CHERI$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 20 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Cheri
	.4byte gBerryDescriptionPart2_Cheri
	.byte 3 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "CHESTO$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 80 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Chesto
	.4byte gBerryDescriptionPart2_Chesto
	.byte 3 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "PECHA$", 7
	.byte BERRY_FIRMNESS_VERY_SOFT
	.2byte 40 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Pecha
	.4byte gBerryDescriptionPart2_Pecha
	.byte 3 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "RAWST$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 32 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Rawst
	.4byte gBerryDescriptionPart2_Rawst
	.byte 3 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "ASPEAR$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 50 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Aspear
	.4byte gBerryDescriptionPart2_Aspear
	.byte 3 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 10 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "LEPPA$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 28 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Leppa
	.4byte gBerryDescriptionPart2_Leppa
	.byte 4 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "ORAN$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 35 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Oran
	.4byte gBerryDescriptionPart2_Oran
	.byte 3 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "PERSIM$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 47 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Persim
	.4byte gBerryDescriptionPart2_Persim
	.byte 3 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "LUM$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 34 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Lum
	.4byte gBerryDescriptionPart2_Lum
	.byte 12 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "SITRUS$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 95 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Sitrus
	.4byte gBerryDescriptionPart2_Sitrus
	.byte 6 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "FIGY$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 100 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Figy
	.4byte gBerryDescriptionPart2_Figy
	.byte 6 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "WIKI$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 115 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Wiki
	.4byte gBerryDescriptionPart2_Wiki
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "MAGO$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 126 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Mago
	.4byte gBerryDescriptionPart2_Mago
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "AGUAV$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 64 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Aguav
	.4byte gBerryDescriptionPart2_Aguav
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "IAPAPA$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 223 @ size (in millimeters)
	.byte 3 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Iapapa
	.4byte gBerryDescriptionPart2_Iapapa
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 10 @ sour
	.byte 25 @ smoothness
	.byte 0 @ padding

	.string "RAZZ$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 120 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 3 @ min yield
	.4byte gBerryDescriptionPart1_Razz
	.4byte gBerryDescriptionPart2_Razz
	.byte 1 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "BLUK$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 108 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 3 @ min yield
	.4byte gBerryDescriptionPart1_Bluk
	.4byte gBerryDescriptionPart2_Bluk
	.byte 1 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "NANAB$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 77 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 3 @ min yield
	.4byte gBerryDescriptionPart1_Nanab
	.4byte gBerryDescriptionPart2_Nanab
	.byte 1 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "WEPEAR$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 74 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 3 @ min yield
	.4byte gBerryDescriptionPart1_Wepear
	.4byte gBerryDescriptionPart2_Wepear
	.byte 1 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "PINAP$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 80 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 3 @ min yield
	.4byte gBerryDescriptionPart1_Pinap
	.4byte gBerryDescriptionPart2_Pinap
	.byte 1 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "POMEG$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 135 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Pomeg
	.4byte gBerryDescriptionPart2_Pomeg
	.byte 3 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "KELPSY$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 150 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Kelpsy
	.4byte gBerryDescriptionPart2_Kelpsy
	.byte 3 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "QUALOT$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 110 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Qualot
	.4byte gBerryDescriptionPart2_Qualot
	.byte 3 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "HONDEW$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 162 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Hondew
	.4byte gBerryDescriptionPart2_Hondew
	.byte 3 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "GREPA$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 149 @ size (in millimeters)
	.byte 6 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Grepa
	.4byte gBerryDescriptionPart2_Grepa
	.byte 3 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 10 @ sour
	.byte 20 @ smoothness
	.byte 0 @ padding

	.string "TAMATO$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 200 @ size (in millimeters)
	.byte 4 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Tamato
	.4byte gBerryDescriptionPart2_Tamato
	.byte 6 @ stage duration (in hours)
	.byte 20 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "CORNN$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 75 @ size (in millimeters)
	.byte 4 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Cornn
	.4byte gBerryDescriptionPart2_Cornn
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 20 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "MAGOST$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 140 @ size (in millimeters)
	.byte 4 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Magost
	.4byte gBerryDescriptionPart2_Magost
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 20 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "RABUTA$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 226 @ size (in millimeters)
	.byte 4 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Rabuta
	.4byte gBerryDescriptionPart2_Rabuta
	.byte 6 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 20 @ bitter
	.byte 10 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "NOMEL$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 285 @ size (in millimeters)
	.byte 4 @ max yield
	.byte 2 @ min yield
	.4byte gBerryDescriptionPart1_Nomel
	.4byte gBerryDescriptionPart2_Nomel
	.byte 6 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 20 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "SPELON$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 133 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Spelon
	.4byte gBerryDescriptionPart2_Spelon
	.byte 18 @ stage duration (in hours)
	.byte 40 @ spicy
	.byte 10 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 70 @ smoothness
	.byte 0 @ padding

	.string "PAMTRE$", 7
	.byte BERRY_FIRMNESS_VERY_SOFT
	.2byte 244 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Pamtre
	.4byte gBerryDescriptionPart2_Pamtre
	.byte 18 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 40 @ dry
	.byte 10 @ sweet
	.byte 0 @ bitter
	.byte 0 @ sour
	.byte 70 @ smoothness
	.byte 0 @ padding

	.string "WATMEL$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 250 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Watmel
	.4byte gBerryDescriptionPart2_Watmel
	.byte 18 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 40 @ sweet
	.byte 10 @ bitter
	.byte 0 @ sour
	.byte 70 @ smoothness
	.byte 0 @ padding

	.string "DURIN$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 280 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Durin
	.4byte gBerryDescriptionPart2_Durin
	.byte 18 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 40 @ bitter
	.byte 10 @ sour
	.byte 70 @ smoothness
	.byte 0 @ padding

	.string "BELUE$", 7
	.byte BERRY_FIRMNESS_VERY_SOFT
	.2byte 300 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Belue
	.4byte gBerryDescriptionPart2_Belue
	.byte 18 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 40 @ sour
	.byte 70 @ smoothness
	.byte 0 @ padding

	.string "LIECHI$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 111 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Liechi
	.4byte gBerryDescriptionPart2_Liechi
	.byte 24 @ stage duration (in hours)
	.byte 40 @ spicy
	.byte 0 @ dry
	.byte 40 @ sweet
	.byte 0 @ bitter
	.byte 10 @ sour
	.byte 80 @ smoothness
	.byte 0 @ padding

	.string "GANLON$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 33 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Ganlon
	.4byte gBerryDescriptionPart2_Ganlon
	.byte 24 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 40 @ dry
	.byte 0 @ sweet
	.byte 40 @ bitter
	.byte 0 @ sour
	.byte 80 @ smoothness
	.byte 0 @ padding

	.string "SALAC$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 95 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Salac
	.4byte gBerryDescriptionPart2_Salac
	.byte 24 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 0 @ dry
	.byte 40 @ sweet
	.byte 0 @ bitter
	.byte 40 @ sour
	.byte 80 @ smoothness
	.byte 0 @ padding

	.string "PETAYA$", 7
	.byte BERRY_FIRMNESS_VERY_HARD
	.2byte 237 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Petaya
	.4byte gBerryDescriptionPart2_Petaya
	.byte 24 @ stage duration (in hours)
	.byte 40 @ spicy
	.byte 0 @ dry
	.byte 0 @ sweet
	.byte 40 @ bitter
	.byte 0 @ sour
	.byte 80 @ smoothness
	.byte 0 @ padding

	.string "APICOT$", 7
	.byte BERRY_FIRMNESS_HARD
	.2byte 75 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Apicot
	.4byte gBerryDescriptionPart2_Apicot
	.byte 24 @ stage duration (in hours)
	.byte 0 @ spicy
	.byte 40 @ dry
	.byte 0 @ sweet
	.byte 0 @ bitter
	.byte 40 @ sour
	.byte 80 @ smoothness
	.byte 0 @ padding

	.string "LANSAT$", 7
	.byte BERRY_FIRMNESS_SOFT
	.2byte 97 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Lansat
	.4byte gBerryDescriptionPart2_Lansat
	.byte 24 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "STARF$", 7
	.byte BERRY_FIRMNESS_SUPER_HARD
	.2byte 153 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Starf
	.4byte gBerryDescriptionPart2_Starf
	.byte 24 @ stage duration (in hours)
	.byte 10 @ spicy
	.byte 10 @ dry
	.byte 10 @ sweet
	.byte 10 @ bitter
	.byte 10 @ sour
	.byte 30 @ smoothness
	.byte 0 @ padding

	.string "ENIGMA$", 7
	.byte BERRY_FIRMNESS_UNKNOWN
	.2byte 0 @ size (in millimeters)
	.byte 2 @ max yield
	.byte 1 @ min yield
	.4byte gBerryDescriptionPart1_Enigma
	.4byte gBerryDescriptionPart2_Enigma
	.byte 24 @ stage duration (in hours)
	.byte 40 @ spicy
	.byte 40 @ dry
	.byte 40 @ sweet
	.byte 40 @ bitter
	.byte 40 @ sour
	.byte 40 @ smoothness
	.byte 0 @ padding
