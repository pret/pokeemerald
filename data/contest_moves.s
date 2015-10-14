	.align 2, 0

gContestMoves: ; 858C2B4
; -
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Pound
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_POUND ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Karate Chop
	.byte 0x25 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Double Slap
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_POUND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Comet Punch
	.byte 0x23 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mega Punch
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Pay Day
	.byte 0x2e ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fire Punch
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_FIRE_PUNCH ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH, COMBO_STARTER_ICE_PUNCH, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Ice Punch
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_ICE_PUNCH ; combo starter ID
	.byte COMBO_STARTER_THUNDER_PUNCH, COMBO_STARTER_FIRE_PUNCH, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thunder Punch
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_THUNDER_PUNCH ; combo starter ID
	.byte COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Scratch
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_SCRATCH ; combo starter ID
	.byte COMBO_STARTER_LEER, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Vice Grip
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_VICE_GRIP ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Guillotine
	.byte 0x2d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_VICE_GRIP, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Razor Wind
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Swords Dance
	.byte 0x26 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_SWORDS_DANCE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Cut
	.byte 0x2d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWORDS_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Gust
	.byte 0x2b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Wing Attack
	.byte 0x23 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Whirlwind
	.byte 0x2b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fly
	.byte 0x05 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bind
	.byte 0x2f ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_VICE_GRIP, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Slam
	.byte 0x13 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_POUND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Vine Whip
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Stomp
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, COMBO_STARTER_LEER, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Double Kick
	.byte 0x23 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mega Kick
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Jump Kick
	.byte 0x01 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_MIND_READER, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rolling Kick
	.byte 0x0d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sand-Attack
	.byte 0x11 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_SAND_ATTACK ; combo starter ID
	.byte COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Headbutt
	.byte 0x0a ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Horn Attack
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_HORN_ATTACK ; combo starter ID
	.byte COMBO_STARTER_LEER, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fury Attack
	.byte 0x11 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Horn Drill
	.byte 0x2d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_HORN_ATTACK, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Tackle
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_LEER, COMBO_STARTER_HARDEN, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Body Slam
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Wrap
	.byte 0x2f ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Take Down
	.byte 0x01 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thrash
	.byte 0x12 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Double-Edge
	.byte 0x01 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Tail Whip
	.byte 0x1e ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Poison Sting
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Twineedle
	.byte 0x0a ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Pin Missile
	.byte 0x11 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Leer
	.byte 0x2f ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_LEER ; combo starter ID
	.byte COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bite
	.byte 0x0d ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Growl
	.byte 0x1e ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Roar
	.byte 0x2b ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sing
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_SING ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Supersonic
	.byte 0x2b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sonic Boom
	.byte 0x23 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Disable
	.byte 0x1a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Acid
	.byte 0x0c ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Ember
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Flamethrower
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mist
	.byte 0x05 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Water Gun
	.byte 0x00 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT, COMBO_STARTER_MUD_SPORT, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hydro Pump
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Surf
	.byte 0x25 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_SURF ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_DIVE, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Ice Beam
	.byte 0x13 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Blizzard
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_POWDER_SNOW, COMBO_STARTER_HAIL, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Psybeam
	.byte 0x2b ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bubble Beam
	.byte 0x0d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Aurora Beam
	.byte 0x13 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hyper Beam
	.byte 0x12 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Peck
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_PECK ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Drill Peck
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_PECK, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Submission
	.byte 0x01 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_MIND_READER, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Low Kick
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Counter
	.byte 0x04 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_TAUNT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Seismic Toss
	.byte 0x13 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FAKE_OUT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Strength
	.byte 0x13 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Absorb
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mega Drain
	.byte 0x0c ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Leech Seed
	.byte 0x0b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Growth
	.byte 0x26 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_GROWTH ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Razor Leaf
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Solar Beam
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_GROWTH, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Poison Powder
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWEET_SCENT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Stun Spore
	.byte 0x2d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWEET_SCENT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sleep Powder
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWEET_SCENT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Petal Dance
	.byte 0x12 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; String Shot
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_STRING_SHOT ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dragon Rage
	.byte 0x21 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_DRAGON_RAGE ; combo starter ID
	.byte COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fire Spin
	.byte 0x2f ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thunder Shock
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thunderbolt
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thunder Wave
	.byte 0x2d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thunder
	.byte 0x0b ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_LOCK_ON, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rock Throw
	.byte 0x23 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_ROCK_THROW ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Earthquake
	.byte 0x0d ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_EARTHQUAKE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fissure
	.byte 0x2d ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_EARTHQUAKE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dig
	.byte 0x05 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Toxic
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Confusion
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_CONFUSION ; combo starter ID
	.byte COMBO_STARTER_PSYCHIC, COMBO_STARTER_KINESIS, COMBO_STARTER_CALM_MIND, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Psychic
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_PSYCHIC ; combo starter ID
	.byte COMBO_STARTER_KINESIS, COMBO_STARTER_CONFUSION, COMBO_STARTER_CALM_MIND, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hypnosis
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_HYPNOSIS ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Meditate
	.byte 0x26 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Agility
	.byte 0x28 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_DOUBLE_TEAM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Quick Attack
	.byte 0x28 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_DOUBLE_TEAM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rage
	.byte 0x03 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_RAGE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Teleport
	.byte 0x05 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_PSYCHIC, COMBO_STARTER_KINESIS, COMBO_STARTER_CONFUSION ; moves this move can follow to make a combo
	.byte 0 ; padding

; Night Shade
	.byte 0x13 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mimic
	.byte 0x20 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Screech
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Double Team
	.byte 0x04 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_DOUBLE_TEAM ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Recover
	.byte 0x13 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Harden
	.byte 0x04 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_HARDEN ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Minimize
	.byte 0x04 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Smokescreen
	.byte 0x10 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SMOG, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Confuse Ray
	.byte 0x2b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Withdraw
	.byte 0x05 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Defense Curl
	.byte 0x04 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_DEFENSE_CURL ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Barrier
	.byte 0x05 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Light Screen
	.byte 0x05 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Haze
	.byte 0x1b ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Reflect
	.byte 0x05 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Focus Energy
	.byte 0x0d ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_FOCUS_ENERGY ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bide
	.byte 0x05 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Metronome
	.byte 0x03 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mirror Move
	.byte 0x20 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Self-Destruct
	.byte 0x02 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Egg Bomb
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SOFT_BOILED, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Lick
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Smog
	.byte 0x0d ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_SMOG ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sludge
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_SLUDGE ; combo starter ID
	.byte COMBO_STARTER_SLUDGE_BOMB, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bone Club
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_BONE_CLUB ; combo starter ID
	.byte COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fire Blast
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Waterfall
	.byte 0x1e ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Clamp
	.byte 0x2f ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Swift
	.byte 0x1d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Skull Bash
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spike Cannon
	.byte 0x11 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Constrict
	.byte 0x0a ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Amnesia
	.byte 0x26 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Kinesis
	.byte 0x2f ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_KINESIS ; combo starter ID
	.byte COMBO_STARTER_PSYCHIC, COMBO_STARTER_CONFUSION, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Soft-Boiled
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_SOFT_BOILED ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hi Jump Kick
	.byte 0x01 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_MIND_READER, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Glare
	.byte 0x0d ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_LEER, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dream Eater
	.byte 0x0b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_HYPNOSIS, COMBO_STARTER_CALM_MIND, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Poison Gas
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Barrage
	.byte 0x23 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Leech Life
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Lovely Kiss
	.byte 0x0d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sky Attack
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Transform
	.byte 0x03 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bubble
	.byte 0x0b ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dizzy Punch
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spore
	.byte 0x0d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Flash
	.byte 0x10 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Psywave
	.byte 0x2d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Splash
	.byte 0x1e ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Acid Armor
	.byte 0x26 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Crabhammer
	.byte 0x25 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Explosion
	.byte 0x02 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fury Swipes
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SCRATCH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bonemerang
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_BONEMERANG ; combo starter ID
	.byte COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rest
	.byte 0x04 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_REST ; combo starter ID
	.byte COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rock Slide
	.byte 0x0d ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ROCK_THROW, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hyper Fang
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sharpen
	.byte 0x26 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Conversion
	.byte 0x23 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Tri Attack
	.byte 0x0b ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_LOCK_ON, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Super Fang
	.byte 0x2d ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SCARY_FACE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Slash
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWORDS_DANCE, COMBO_STARTER_SCRATCH, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Substitute
	.byte 0x04 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Struggle
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sketch
	.byte 0x20 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Triple Kick
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Thief
	.byte 0x1f ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spider Web
	.byte 0x1a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_STRING_SHOT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mind Reader
	.byte 0x2f ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_MIND_READER ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Nightmare
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_HYPNOSIS, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Flame Wheel
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Snore
	.byte 0x00 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_REST, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Curse
	.byte 0x29 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_CURSE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Flail
	.byte 0x21 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ENDURE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Conversion 2
	.byte 0x23 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Aeroblast
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Cotton Spore
	.byte 0x11 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Reversal
	.byte 0x1e ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ENDURE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spite
	.byte 0x21 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CURSE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Powder Snow
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_POWDER_SNOW ; combo starter ID
	.byte COMBO_STARTER_HAIL, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Protect
	.byte 0x05 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_HARDEN, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mach Punch
	.byte 0x28 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Scary Face
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_SCARY_FACE ; combo starter ID
	.byte COMBO_STARTER_RAGE, COMBO_STARTER_LEER, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Faint Attack
	.byte 0x1d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sweet Kiss
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Belly Drum
	.byte 0x26 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_BELLY_DRUM ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sludge Bomb
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_SLUDGE_BOMB ; combo starter ID
	.byte COMBO_STARTER_SLUDGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mud-Slap
	.byte 0x11 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_MUD_SLAP ; combo starter ID
	.byte COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SANDSTORM, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Octazooka
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_LOCK_ON, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spikes
	.byte 0x1a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Zap Cannon
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_LOCK_ON, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Foresight
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Destiny Bond
	.byte 0x02 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Perish Song
	.byte 0x2d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Icy Wind
	.byte 0x0d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Detect
	.byte 0x04 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_TAUNT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bone Rush
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_BONE_RUSH ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Lock-On
	.byte 0x2f ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_LOCK_ON ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Outrage
	.byte 0x12 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sandstorm
	.byte 0x2b ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_SANDSTORM ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Giga Drain
	.byte 0x11 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Endure
	.byte 0x04 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_ENDURE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Charm
	.byte 0x13 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_CHARM ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rollout
	.byte 0x2f ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; False Swipe
	.byte 0x0d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWORDS_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Swagger
	.byte 0x1d ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Milk Drink
	.byte 0x23 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spark
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fury Cutter
	.byte 0x03 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWORDS_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Steel Wing
	.byte 0x23 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mean Look
	.byte 0x1a ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_MEAN_LOOK ; combo starter ID
	.byte COMBO_STARTER_CURSE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Attract
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sleep Talk
	.byte 0x03 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_REST, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Heal Bell
	.byte 0x1e ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Return
	.byte 0x2c ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Present
	.byte 0x03 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Frustration
	.byte 0x2c ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Safeguard
	.byte 0x05 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Pain Split
	.byte 0x0c ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ENDURE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sacred Fire
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Magnitude
	.byte 0x2e ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dynamic Punch
	.byte 0x11 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Megahorn
	.byte 0x23 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dragon Breath
	.byte 0x0d ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_DRAGON_BREATH ; combo starter ID
	.byte COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_DANCE, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Baton Pass
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Encore
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Pursuit
	.byte 0x2d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rapid Spin
	.byte 0x04 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sweet Scent
	.byte 0x0d ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_SWEET_SCENT ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Iron Tail
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Metal Claw
	.byte 0x00 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_METAL_SOUND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Vital Throw
	.byte 0x29 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FAKE_OUT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Morning Sun
	.byte 0x22 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Synthesis
	.byte 0x22 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Moonlight
	.byte 0x22 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hidden Power
	.byte 0x03 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Cross Chop
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Twister
	.byte 0x2b ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rain Dance
	.byte 0x2e ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_RAIN_DANCE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sunny Day
	.byte 0x2e ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_SUNNY_DAY ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Crunch
	.byte 0x0c ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SCARY_FACE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mirror Coat
	.byte 0x04 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_TAUNT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Psych Up
	.byte 0x23 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Extreme Speed
	.byte 0x28 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Ancient Power
	.byte 0x26 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Shadow Ball
	.byte 0x10 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Future Sight
	.byte 0x2f ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_PSYCHIC, COMBO_STARTER_KINESIS, COMBO_STARTER_CONFUSION, COMBO_STARTER_CALM_MIND ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rock Smash
	.byte 0x27 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Whirlpool
	.byte 0x2f ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Beat Up
	.byte 0x2d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fake Out
	.byte 0x13 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_FAKE_OUT ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Uproar
	.byte 0x2b ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Stockpile
	.byte 0x04 ; effect ID
	.byte CONTEST_TOUGH
	.byte COMBO_STARTER_STOCKPILE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Spit Up
	.byte 0x00 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_STOCKPILE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Swallow
	.byte 0x26 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_STOCKPILE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Heat Wave
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hail
	.byte 0x0d ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_HAIL ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Torment
	.byte 0x1a ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Flatter
	.byte 0x1a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Will-O-Wisp
	.byte 0x0c ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Memento
	.byte 0x02 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Facade
	.byte 0x1e ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Focus Punch
	.byte 0x29 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Smelling Salt
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Follow Me
	.byte 0x2f ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Nature Power
	.byte 0x2e ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Charge
	.byte 0x23 ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_CHARGE ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Taunt
	.byte 0x1a ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_TAUNT ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Helping Hand
	.byte 0x1a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Trick
	.byte 0x23 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Role Play
	.byte 0x1f ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Wish
	.byte 0x2f ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Assist
	.byte 0x22 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Ingrain
	.byte 0x05 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Superpower
	.byte 0x01 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_LOCK_ON, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Magic Coat
	.byte 0x05 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Recycle
	.byte 0x03 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Revenge
	.byte 0x29 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Brick Break
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Yawn
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_YAWN ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Knock Off
	.byte 0x0c ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FAKE_OUT, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Endeavor
	.byte 0x1e ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ENDURE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Eruption
	.byte 0x21 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ENDURE, COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_SUNNY_DAY, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Skill Swap
	.byte 0x1f ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Imprison
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Refresh
	.byte 0x26 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_WATER_SPORT, COMBO_STARTER_SING, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Grudge
	.byte 0x21 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CURSE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Snatch
	.byte 0x2d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Secret Power
	.byte 0x27 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dive
	.byte 0x04 ; effect ID
	.byte CONTEST_BEAUTY
	.byte COMBO_STARTER_DIVE ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Arm Thrust
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_FAKE_OUT, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Camouflage
	.byte 0x25 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Tail Glow
	.byte 0x26 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Luster Purge
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mist Ball
	.byte 0x0c ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Feather Dance
	.byte 0x1e ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Teeter Dance
	.byte 0x12 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Blaze Kick
	.byte 0x00 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mud Sport
	.byte 0x00 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_MUD_SPORT ; combo starter ID
	.byte COMBO_STARTER_MUD_SLAP, COMBO_STARTER_WATER_SPORT, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Ice Ball
	.byte 0x2f ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Needle Arm
	.byte 0x0c ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Slack Off
	.byte 0x21 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_YAWN, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hyper Voice
	.byte 0x0d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Poison Fang
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Crush Claw
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SWORDS_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Blast Burn
	.byte 0x12 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Hydro Cannon
	.byte 0x12 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Meteor Mash
	.byte 0x23 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Astonish
	.byte 0x0a ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Weather Ball
	.byte 0x00 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_HAIL, COMBO_STARTER_SANDSTORM ; moves this move can follow to make a combo
	.byte 0 ; padding

; Aromatherapy
	.byte 0x1e ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Fake Tears
	.byte 0x1e ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Air Cutter
	.byte 0x13 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Overheat
	.byte 0x01 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SUNNY_DAY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Odor Sleuth
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rock Tomb
	.byte 0x2f ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_ROCK_THROW, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Silver Wind
	.byte 0x26 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Metal Sound
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_METAL_SOUND ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Grass Whistle
	.byte 0x0d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Tickle
	.byte 0x1b ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Cosmic Power
	.byte 0x26 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Water Spout
	.byte 0x21 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Signal Beam
	.byte 0x2b ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Shadow Punch
	.byte 0x1d ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Extrasensory
	.byte 0x0c ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sky Uppercut
	.byte 0x13 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_FOCUS_ENERGY, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sand Tomb
	.byte 0x2f ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_SANDSTORM, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Sheer Cold
	.byte 0x2d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Muddy Water
	.byte 0x11 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bullet Seed
	.byte 0x2d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Aerial Ace
	.byte 0x1d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Icicle Spear
	.byte 0x13 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Iron Defense
	.byte 0x05 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Block
	.byte 0x1a ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Howl
	.byte 0x26 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dragon Claw
	.byte 0x13 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_DANCE, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Frenzy Plant
	.byte 0x12 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bulk Up
	.byte 0x26 ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Bounce
	.byte 0x05 ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Mud Shot
	.byte 0x0d ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Poison Tail
	.byte 0x1b ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Covet
	.byte 0x1f ; effect ID
	.byte CONTEST_CUTE
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Volt Tackle
	.byte 0x01 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Magical Leaf
	.byte 0x1d ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_GROWTH, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Water Sport
	.byte 0x00 ; effect ID
	.byte CONTEST_CUTE
	.byte COMBO_STARTER_WATER_SPORT ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_MUD_SPORT, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Calm Mind
	.byte 0x04 ; effect ID
	.byte CONTEST_SMART
	.byte COMBO_STARTER_CALM_MIND ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Leaf Blade
	.byte 0x25 ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Dragon Dance
	.byte 0x26 ; effect ID
	.byte CONTEST_COOL
	.byte COMBO_STARTER_DRAGON_DANCE ; combo starter ID
	.byte COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_BREATH, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Rock Blast
	.byte 0x23 ; effect ID
	.byte CONTEST_TOUGH
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Shock Wave
	.byte 0x1d ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CHARGE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Water Pulse
	.byte 0x2b ; effect ID
	.byte CONTEST_BEAUTY
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_RAIN_DANCE, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Doom Desire
	.byte 0x2f ; effect ID
	.byte CONTEST_COOL
	.byte 0 ; combo starter ID
	.byte 0, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding

; Psycho Boost
	.byte 0x01 ; effect ID
	.byte CONTEST_SMART
	.byte 0 ; combo starter ID
	.byte COMBO_STARTER_CALM_MIND, 0, 0, 0 ; moves this move can follow to make a combo
	.byte 0 ; padding
