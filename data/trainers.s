	.align 2, 0

gTrainers:: @ 8310030
@ NONE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 0 @ party size
	.4byte NULL

@ SAWYER_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Sawyer1

@ GRUNT_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt1

@ GRUNT_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt2

@ GRUNT_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt3

@ GRUNT_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt4

@ GRUNT_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt5

@ GRUNT_6
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt6

@ GRUNT_7
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt7

@ GABRIELLE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Gabrielle1

@ GRUNT_8
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt8

@ MARCEL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "MARCEL$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Marcel

@ ALBERTO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ALBERTO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Alberto

@ ED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "ED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ed

@ GRUNT_9
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt9

@ DECLAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DECLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Declan

@ GRUNT_10
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt10

@ GRUNT_11
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt11

@ GRUNT_12
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt12

@ GRUNT_13
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Grunt13

@ GRUNT_14
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt14

@ GRUNT_15
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt15

@ GRUNT_16
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt16

@ GRUNT_17
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt17

@ GRUNT_18
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt18

@ GRUNT_19
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt19

@ GRUNT_20
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt20

@ GRUNT_21
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt21

@ GRUNT_22
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt22

@ FREDRICK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "FREDRICK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Fredrick

@ MATT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AQUA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_ADMIN_M
	.string "MATT$", 12
	.2byte ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Matt

@ ZANDER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "ZANDER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Zander

@ SHELLY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AQUA_ADMIN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_ADMIN_F
	.string "SHELLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelly1

@ SHELLY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AQUA_ADMIN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_ADMIN_F
	.string "SHELLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelly2

@ ARCHIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AQUA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_LEADER_ARCHIE
	.string "ARCHIE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Archie

@ LEAH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "LEAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Leah

@ DAISY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "DAISY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Daisy

@ ROSE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Rose1

@ FELIX
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "FELIX$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Felix

@ VIOLET
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "VIOLET$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Violet

@ ROSE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Rose2

@ ROSE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Rose3

@ ROSE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Rose4

@ ROSE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Rose5

@ DUSTY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dusty1

@ CHIP
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "CHIP$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Chip

@ FOSTER
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "FOSTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Foster

@ DUSTY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dusty2

@ DUSTY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dusty3

@ DUSTY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dusty4

@ DUSTY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dusty5

@ GABBY_AND_TY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER @ gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.string "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GabbyAndTy1

@ GABBY_AND_TY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER @ gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.string "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GabbyAndTy2

@ GABBY_AND_TY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER @ gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.string "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GabbyAndTy3

@ GABBY_AND_TY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER @ gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.string "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GabbyAndTy4

@ GABBY_AND_TY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER @ gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.string "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GabbyAndTy5

@ GABBY_AND_TY_6
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER @ gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.string "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GabbyAndTy6

@ LOLA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lola1

@ AUSTINA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "AUSTINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Austina

@ GWEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "GWEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Gwen

@ LOLA_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lola2

@ LOLA_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lola3

@ LOLA_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lola4

@ LOLA_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lola5

@ RICKY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ricky1

@ SIMON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "SIMON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Simon

@ CHARLIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "CHARLIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Charlie

@ RICKY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ricky2

@ RICKY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ricky3

@ RICKY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ricky4

@ RICKY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ricky5

@ RANDALL
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "RANDALL$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Randall

@ PARKER
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "PARKER$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Parker

@ GEORGE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "GEORGE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_George

@ BERKE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "BERKE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Berke

@ BRAXTON
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "BRAXTON$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Braxton

@ VINCENT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "VINCENT$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Vincent

@ LEROY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "LEROY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Leroy

@ WILTON_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "WILTON$", 12
	.2byte ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wilton1

@ EDGAR
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "EDGAR$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edgar

@ ALBERT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "ALBERT$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Albert

@ SAMUEL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "SAMUEL$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Samuel

@ VITO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "VITO$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Vito

@ OWEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "OWEN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Owen

@ WILTON_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "WILTON$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wilton2

@ WILTON_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "WILTON$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wilton3

@ WILTON_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "WILTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wilton4

@ WILTON_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "WILTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wilton5

@ WARREN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "WARREN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Warren

@ MARY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "MARY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Mary

@ ALEXIA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "ALEXIA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Alexia

@ JODY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "JODY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jody

@ WENDY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "WENDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wendy

@ KEIRA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "KEIRA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Keira

@ BROOKE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "BROOKE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brooke1

@ JENNIFER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "JENNIFER$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jennifer

@ HOPE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "HOPE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Hope

@ SHANNON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "SHANNON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Shannon

@ MICHELLE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "MICHELLE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Michelle

@ CAROLINE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CAROLINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Caroline

@ JULIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "JULIE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Julie

@ BROOKE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "BROOKE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brooke2

@ BROOKE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "BROOKE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brooke3

@ BROOKE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "BROOKE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brooke4

@ BROOKE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "BROOKE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brooke5

@ PATRICIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "PATRICIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Patricia

@ KINDRA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "KINDRA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Kindra

@ TAMMY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "TAMMY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tammy

@ VALERIE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Valerie1

@ TASHA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "TASHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tasha

@ VALERIE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Valerie2

@ VALERIE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Valerie3

@ VALERIE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Valerie4

@ VALERIE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Valerie5

@ CINDY_1
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cindy1

@ DAPHNE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "DAPHNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Daphne

@ GRUNT_23
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Grunt23

@ CINDY_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cindy2

@ BRIANNA
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "BRIANNA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brianna

@ NAOMI
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "NAOMI$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Naomi

@ CINDY_3
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cindy3

@ CINDY_4
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cindy4

@ CINDY_5
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cindy5

@ CINDY_6
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cindy6

@ MELISSA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "MELISSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Melissa

@ SHEILA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "SHEILA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Sheila

@ SHIRLEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "SHIRLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Shirley

@ JESSICA_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jessica1

@ CONNIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "CONNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Connie

@ BRIDGET
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "BRIDGET$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Bridget

@ OLIVIA
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "OLIVIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Olivia

@ TIFFANY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "TIFFANY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tiffany

@ JESSICA_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jessica2

@ JESSICA_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jessica3

@ JESSICA_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jessica4

@ JESSICA_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jessica5

@ WINSTON_1
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Winston1

@ MOLLIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "MOLLIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Mollie

@ GARRET
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "GARRET$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Garret

@ WINSTON_2
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Winston2

@ WINSTON_3
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Winston3

@ WINSTON_4
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Winston4

@ WINSTON_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Winston5

@ STEVE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Steve1

@ THALIA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Thalia1

@ MARK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "MARK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Mark

@ GRUNT_24
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt24

@ STEVE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Steve2

@ STEVE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Steve3

@ STEVE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Steve4

@ STEVE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Steve5

@ LUIS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "LUIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Luis

@ DOMINIK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DOMINIK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dominik

@ DOUGLAS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DOUGLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Douglas

@ DARRIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DARRIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Darrin

@ TONY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tony1

@ JEROME
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "JEROME$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jerome

@ MATTHEW
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "MATTHEW$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Matthew

@ DAVID
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DAVID$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_David

@ SPENCER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "SPENCER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Spencer

@ ROLAND
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "ROLAND$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Roland

@ NOLEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "NOLEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Nolen

@ STAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "STAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Stan

@ BARRY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "BARRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Barry

@ DEAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DEAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dean

@ RODNEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "RODNEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Rodney

@ RICHARD
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "RICHARD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Richard

@ HERMAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "HERMAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Herman

@ SANTIAGO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "SANTIAGO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Santiago

@ GILBERT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "GILBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Gilbert

@ FRANKLIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "FRANKLIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Franklin

@ KEVIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "KEVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kevin

@ JACK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "JACK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jack

@ DUDLEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "DUDLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dudley

@ CHAD
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "CHAD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Chad

@ TONY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tony2

@ TONY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tony3

@ TONY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tony4

@ TONY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tony5

@ TAKAO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "TAKAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Takao

@ HITOSHI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "HITOSHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Hitoshi

@ KIYO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KIYO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kiyo

@ KOICHI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KOICHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Koichi

@ NOB_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Nob1

@ NOB_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Nob2

@ NOB_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Nob3

@ NOB_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Nob4

@ NOB_5
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Nob5

@ YUJI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "YUJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Yuji

@ DAISUKE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "DAISUKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Daisuke

@ ATSUSHI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "ATSUSHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Atsushi

@ KIRK
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "KIRK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Kirk

@ GRUNT_25
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt25

@ GRUNT_26
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt26

@ SHAWN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "SHAWN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shawn

@ FERNANDO_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Fernando1

@ DALTON_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Dalton1

@ DALTON_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dalton2

@ DALTON_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dalton3

@ DALTON_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dalton4

@ DALTON_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dalton5

@ COLE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "COLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cole

@ JEFF
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "JEFF$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jeff

@ AXLE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "AXLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Axle

@ JACE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "JACE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jace

@ KEEGAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "KEEGAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Keegan

@ BERNIE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bernie1

@ BERNIE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bernie2

@ BERNIE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bernie3

@ BERNIE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bernie4

@ BERNIE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bernie5

@ DREW
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "DREW$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Drew

@ BEAU
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "BEAU$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Beau

@ LARRY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "LARRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Larry

@ SHANE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "SHANE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shane

@ JUSTIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "JUSTIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Justin

@ ETHAN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ethan1

@ AUTUMN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "AUTUMN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Autumn

@ TRAVIS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "TRAVIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Travis

@ ETHAN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ethan2

@ ETHAN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ethan3

@ ETHAN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ethan4

@ ETHAN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ethan5

@ BRENT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "BRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brent

@ DONALD
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "DONALD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Donald

@ TAYLOR
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "TAYLOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Taylor

@ JEFFREY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jeffrey1

@ DEREK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "DEREK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Derek

@ JEFFREY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jeffrey2

@ JEFFREY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jeffrey3

@ JEFFREY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Jeffrey4

@ JEFFREY_5
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Jeffrey5

@ EDWARD
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "EDWARD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Edward

@ PRESTON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "PRESTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Preston

@ VIRGIL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "VIRGIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Virgil

@ BLAKE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "BLAKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Blake

@ WILLIAM
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "WILLIAM$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_William

@ JOSHUA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "JOSHUA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Joshua

@ CAMERON_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cameron1

@ CAMERON_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cameron2

@ CAMERON_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cameron3

@ CAMERON_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cameron4

@ CAMERON_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cameron5

@ JACLYN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "JACLYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jaclyn

@ HANNAH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "HANNAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Hannah

@ SAMANTHA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "SAMANTHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Samantha

@ MAURA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "MAURA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Maura

@ KAYLA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "KAYLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Kayla

@ ALEXIS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "ALEXIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Alexis

@ JACKI_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jacki1

@ JACKI_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jacki2

@ JACKI_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jacki3

@ JACKI_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jacki4

@ JACKI_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jacki5

@ WALTER_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Walter1

@ MICAH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "MICAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Micah

@ THOMAS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "THOMAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Thomas

@ WALTER_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Walter2

@ WALTER_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Walter3

@ WALTER_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Walter4

@ WALTER_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Walter5

@ SIDNEY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR @ gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_SIDNEY
	.string "SIDNEY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xf @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Sidney

@ PHOEBE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR @ gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_PHOEBE
	.string "PHOEBE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Phoebe

@ GLACIA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR @ gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_GLACIA
	.string "GLACIA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Glacia

@ DRAKE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR @ gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_DRAKE
	.string "DRAKE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Drake

@ ROXANNE_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.string "ROXANNE$", 12
	.2byte ITEM_POTION, ITEM_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Roxanne1

@ BRAWLY_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.string "BRAWLY$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brawly1

@ WATTSON_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.string "WATTSON$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Wattson1

@ FLANNERY_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.string "FLANNERY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Flannery1

@ NORMAN_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.string "NORMAN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Norman1

@ WINONA_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.string "WINONA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x17 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Winona1

@ TATE_AND_LIZA_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.string "TATE&LIZA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_TateAndLiza1

@ JUAN_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.string "JUAN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Juan1

@ JERRY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jerry1

@ TED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "TED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ted

@ PAUL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "PAUL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Paul

@ JERRY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jerry2

@ JERRY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jerry3

@ JERRY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jerry4

@ JERRY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.string "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jerry5

@ KAREN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.string "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Karen1

@ GEORGIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.string "GEORGIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Georgia

@ KAREN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.string "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Karen2

@ KAREN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.string "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Karen3

@ KAREN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.string "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Karen4

@ KAREN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.string "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Karen5

@ KATE_AND_JOY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "KATE & JOY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KateAndJoy

@ ANNA_AND_MEG_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AnnaAndMeg1

@ ANNA_AND_MEG_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AnnaAndMeg2

@ ANNA_AND_MEG_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AnnaAndMeg3

@ ANNA_AND_MEG_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AnnaAndMeg4

@ ANNA_AND_MEG_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AnnaAndMeg5

@ VICTOR
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "VICTOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Victor

@ MIGUEL_1
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Miguel1

@ COLTON
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "COLTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Colton

@ MIGUEL_2
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Miguel2

@ MIGUEL_3
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Miguel3

@ MIGUEL_4
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Miguel4

@ MIGUEL_5
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Miguel5

@ VICTORIA
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "VICTORIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Victoria

@ VANESSA
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "VANESSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Vanessa

@ BETHANY
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "BETHANY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Bethany

@ ISABEL_1
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Isabel1

@ ISABEL_2
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Isabel2

@ ISABEL_3
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Isabel3

@ ISABEL_4
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Isabel4

@ ISABEL_5
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Isabel5

@ TIMOTHY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Timothy1

@ TIMOTHY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Timothy2

@ TIMOTHY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Timothy3

@ TIMOTHY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Timothy4

@ TIMOTHY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Timothy5

@ VICKY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "VICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Vicky

@ SHELBY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelby1

@ SHELBY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelby2

@ SHELBY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelby3

@ SHELBY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelby4

@ SHELBY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shelby5

@ CALVIN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Calvin1

@ BILLY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "BILLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Billy

@ JOSH
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "JOSH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Josh

@ TOMMY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "TOMMY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tommy

@ JOEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "JOEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Joey

@ BEN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "BEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ben

@ QUINCY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "QUINCY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Quincy

@ KATELYNN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "KATELYNN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Katelynn

@ JAYLEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "JAYLEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jaylen

@ DILLON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "DILLON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dillon

@ CALVIN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Calvin2

@ CALVIN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Calvin3

@ CALVIN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Calvin4

@ CALVIN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Calvin5

@ EDDIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "EDDIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Eddie

@ ALLEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "ALLEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Allen

@ TIMMY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "TIMMY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Timmy

@ WALLACE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_CHAMPION
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CHAMPION_WALLACE
	.string "WALLACE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Wallace

@ ANDREW
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ANDREW$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Andrew

@ IVAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "IVAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ivan

@ CLAUDE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "CLAUDE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Claude

@ ELLIOT_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Elliot1

@ NED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "NED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Ned

@ DALE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "DALE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Dale

@ NOLAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "NOLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Nolan

@ BARNY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "BARNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Barny

@ WADE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "WADE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Wade

@ CARTER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "CARTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Carter

@ ELLIOT_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Elliot2

@ ELLIOT_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Elliot3

@ ELLIOT_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Elliot4

@ ELLIOT_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Elliot5

@ RONALD
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "RONALD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Ronald

@ JACOB
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "JACOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jacob

@ ANTHONY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "ANTHONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Anthony

@ BENJAMIN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Benjamin1

@ BENJAMIN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Benjamin2

@ BENJAMIN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Benjamin3

@ BENJAMIN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Benjamin4

@ BENJAMIN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Benjamin5

@ ABIGAIL_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Abigail1

@ JASMINE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "JASMINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jasmine

@ ABIGAIL_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Abigail2

@ ABIGAIL_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Abigail3

@ ABIGAIL_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Abigail4

@ ABIGAIL_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Abigail5

@ DYLAN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.string "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dylan1

@ DYLAN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.string "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dylan2

@ DYLAN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.string "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dylan3

@ DYLAN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.string "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dylan4

@ DYLAN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.string "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dylan5

@ MARIA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Maria1

@ MARIA_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Maria2

@ MARIA_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Maria3

@ MARIA_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Maria4

@ MARIA_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Maria5

@ CAMDEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "CAMDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Camden

@ DEMETRIUS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "DEMETRIUS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Demetrius

@ ISAIAH_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isaiah1

@ PABLO_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Pablo1

@ CHASE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "CHASE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Chase

@ ISAIAH_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isaiah2

@ ISAIAH_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isaiah3

@ ISAIAH_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isaiah4

@ ISAIAH_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isaiah5

@ ISOBEL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "ISOBEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isobel

@ DONNY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "DONNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Donny

@ TALIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "TALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Talia

@ KATELYN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Katelyn1

@ ALLISON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "ALLISON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Allison

@ KATELYN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Katelyn2

@ KATELYN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Katelyn3

@ KATELYN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Katelyn4

@ KATELYN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Katelyn5

@ NICOLAS_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.string "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Nicolas1

@ NICOLAS_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.string "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Nicolas2

@ NICOLAS_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.string "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Nicolas3

@ NICOLAS_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.string "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Nicolas4

@ NICOLAS_5
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.string "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Nicolas5

@ AARON
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.string "AARON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Aaron

@ PERRY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "PERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Perry

@ HUGH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "HUGH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Hugh

@ PHIL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "PHIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Phil

@ JARED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "JARED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jared

@ HUMBERTO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "HUMBERTO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Humberto

@ PRESLEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "PRESLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Presley

@ EDWARDO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "EDWARDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edwardo

@ COLIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "COLIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Colin

@ ROBERT_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Robert1

@ BENNY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "BENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Benny

@ CHESTER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "CHESTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Chester

@ ROBERT_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Robert2

@ ROBERT_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Robert3

@ ROBERT_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Robert4

@ ROBERT_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Robert5

@ ALEX
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ALEX$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Alex

@ BECK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "BECK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Beck

@ YASU
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "YASU$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Yasu

@ TAKASHI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "TAKASHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Takashi

@ DIANNE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "DIANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Dianne

@ JANI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "JANI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jani

@ LAO_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Lao1

@ LUNG
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "LUNG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lung

@ LAO_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Lao2

@ LAO_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Lao3

@ LAO_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Lao4

@ LAO_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Lao5

@ JOCELYN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "JOCELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jocelyn

@ LAURA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "LAURA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Laura

@ CYNDY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cyndy1

@ CORA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CORA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cora

@ PAULA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "PAULA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Paula

@ CYNDY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cyndy2

@ CYNDY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cyndy3

@ CYNDY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cyndy4

@ CYNDY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cyndy5

@ MADELINE_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Madeline1

@ CLARISSA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "CLARISSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Clarissa

@ ANGELICA
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "ANGELICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Angelica

@ MADELINE_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Madeline2

@ MADELINE_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Madeline3

@ MADELINE_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Madeline4

@ MADELINE_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Madeline5

@ BEVERLY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "BEVERLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Beverly

@ IMANI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "IMANI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Imani

@ KYLA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "KYLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kyla

@ DENISE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "DENISE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Denise

@ BETH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "BETH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Beth

@ TARA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "TARA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tara

@ MISSY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "MISSY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Missy

@ ALICE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "ALICE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Alice

@ JENNY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jenny1

@ GRACE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "GRACE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grace

@ TANYA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "TANYA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tanya

@ SHARON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "SHARON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Sharon

@ NIKKI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "NIKKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Nikki

@ BRENDA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "BRENDA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brenda

@ KATIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "KATIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Katie

@ SUSIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "SUSIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Susie

@ KARA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "KARA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kara

@ DANA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "DANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Dana

@ SIENNA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "SIENNA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Sienna

@ DEBRA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "DEBRA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Debra

@ LINDA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "LINDA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Linda

@ KAYLEE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "KAYLEE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Kaylee

@ LAUREL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "LAUREL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Laurel

@ CARLEE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "CARLEE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Carlee

@ JENNY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jenny2

@ JENNY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jenny3

@ JENNY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jenny4

@ JENNY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jenny5

@ HEIDI
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "HEIDI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Heidi

@ BECKY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "BECKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Becky

@ CAROL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "CAROL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Carol

@ NANCY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "NANCY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Nancy

@ MARTHA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "MARTHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Martha

@ DIANA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Diana1

@ CEDRIC
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "CEDRIC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cedric

@ IRENE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "IRENE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Irene

@ DIANA_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Diana2

@ DIANA_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Diana3

@ DIANA_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Diana4

@ DIANA_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Diana5

@ AMY_AND_LIV_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AmyAndLiv1

@ AMY_AND_LIV_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AmyAndLiv2

@ GINA_AND_MIA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "GINA & MIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GinaAndMia1

@ MIU_AND_YUKI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "MIU & YUKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_MiuAndYuki

@ AMY_AND_LIV_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AmyAndLiv3

@ GINA_AND_MIA_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "GINA & MIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_GinaAndMia2

@ AMY_AND_LIV_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AmyAndLiv4

@ AMY_AND_LIV_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AmyAndLiv5

@ AMY_AND_LIV_6
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_AmyAndLiv6

@ HUEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "HUEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Huey

@ EDMOND
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "EDMOND$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Edmond

@ ERNEST_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ernest1

@ DWAYNE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "DWAYNE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Dwayne

@ PHILLIP
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "PHILLIP$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Phillip

@ LEONARD
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "LEONARD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Leonard

@ DUNCAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "DUNCAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Duncan

@ ERNEST_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ernest2

@ ERNEST_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ernest3

@ ERNEST_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ernest4

@ ERNEST_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ernest5

@ ELI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "ELI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Eli

@ ANNIKA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.string "ANNIKA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Annika

@ JAZMYN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_2
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "JAZMYN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jazmyn

@ JONAS
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "JONAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jonas

@ KAYLEY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "KAYLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kayley

@ AURON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "AURON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Auron

@ KELVIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "KELVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Kelvin

@ MARLEY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "MARLEY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Marley

@ REYNA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "REYNA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Reyna

@ HUDSON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "HUDSON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Hudson

@ CONOR
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "CONOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Conor

@ EDWIN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edwin1

@ HECTOR
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "HECTOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Hector

@ TABITHA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_ADMIN
	.string "TABITHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Tabitha1

@ EDWIN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edwin2

@ EDWIN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edwin3

@ EDWIN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edwin4

@ EDWIN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.string "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Edwin5

@ WALLY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.string "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wally1

@ BRENDAN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brendan1

@ BRENDAN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brendan2

@ BRENDAN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brendan3

@ BRENDAN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brendan4

@ BRENDAN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brendan5

@ BRENDAN_6
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brendan6

@ BRENDAN_7
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brendan7

@ BRENDAN_8
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brendan8

@ BRENDAN_9
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Brendan9

@ MAY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_May1

@ MAY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_May2

@ MAY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_May3

@ MAY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_May4

@ MAY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_May5

@ MAY_6
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_May6

@ MAY_7
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_May7

@ MAY_8
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_May8

@ MAY_9
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_May9

@ ISAAC_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.string "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Isaac1

@ DAVIS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "DAVIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Davis

@ MITCHELL
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "MITCHELL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Mitchell

@ ISAAC_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.string "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Isaac2

@ ISAAC_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.string "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Isaac3

@ ISAAC_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.string "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Isaac4

@ ISAAC_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.string "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Isaac5

@ LYDIA_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Lydia1

@ HALLE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "HALLE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Halle

@ GARRISON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "GARRISON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Garrison

@ LYDIA_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Lydia2

@ LYDIA_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Lydia3

@ LYDIA_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Lydia4

@ LYDIA_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Lydia5

@ JACKSON_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jackson1

@ LORENZO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "LORENZO$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Lorenzo

@ SEBASTIAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "SEBASTIAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Sebastian

@ JACKSON_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jackson2

@ JACKSON_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jackson3

@ JACKSON_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Jackson4

@ JACKSON_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.string "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jackson5

@ CATHERINE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Catherine1

@ JENNA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "JENNA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jenna

@ SOPHIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "SOPHIA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Sophia

@ CATHERINE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Catherine2

@ CATHERINE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Catherine3

@ CATHERINE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Catherine4

@ CATHERINE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.string "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Catherine5

@ JULIO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.string "JULIO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Julio

@ GRUNT_27
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt27

@ GRUNT_28
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt28

@ GRUNT_29
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt29

@ GRUNT_30
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt30

@ MARC
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "MARC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Marc

@ BRENDEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "BRENDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brenden

@ LILITH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "LILITH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Lilith

@ CRISTIAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "CRISTIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Cristian

@ SYLVIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "SYLVIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Sylvia

@ LEONARDO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "LEONARDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Leonardo

@ ATHENA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "ATHENA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Athena

@ HARRISON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "HARRISON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Harrison

@ GRUNT_31
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt31

@ CLARENCE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "CLARENCE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Clarence

@ TERRY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "TERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Terry

@ NATE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "NATE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Nate

@ KATHLEEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.string "KATHLEEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kathleen

@ CLIFFORD
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "CLIFFORD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Clifford

@ NICHOLAS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "NICHOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Nicholas

@ GRUNT_32
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt32

@ GRUNT_33
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt33

@ GRUNT_34
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt34

@ GRUNT_35
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt35

@ GRUNT_36
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt36

@ MACEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "MACEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Macey

@ BRENDAN_10
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Brendan10

@ BRENDAN_11
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Brendan11

@ PAXTON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.string "PAXTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Paxton

@ ISABELLA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.string "ISABELLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isabella

@ GRUNT_37
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA @ gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt37

@ TABITHA_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_ADMIN
	.string "TABITHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Tabitha2

@ JONATHAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "JONATHAN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jonathan

@ BRENDAN_12
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Brendan12

@ MAY_10
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_May10

@ MAXIE_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_LEADER_MAXIE
	.string "MAXIE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Maxie1

@ MAXIE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_LEADER_MAXIE
	.string "MAXIE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Maxie2

@ TIANA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "TIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Tiana

@ HALEY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Haley1

@ JANICE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "JANICE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Janice

@ VIVI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "VIVI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Vivi

@ HALEY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Haley2

@ HALEY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Haley3

@ HALEY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Haley4

@ HALEY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Haley5

@ SALLY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "SALLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Sally

@ ROBIN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "ROBIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Robin

@ ANDREA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "ANDREA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Andrea

@ CRISSY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.string "CRISSY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Crissy

@ RICK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "RICK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Rick

@ LYLE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "LYLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Lyle

@ JOSE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "JOSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jose

@ DOUG
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "DOUG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Doug

@ GREG
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "GREG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Greg

@ KENT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "KENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kent

@ JAMES_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_James1

@ JAMES_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_James2

@ JAMES_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_James3

@ JAMES_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_James4

@ JAMES_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.string "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_James5

@ BRICE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "BRICE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Brice

@ TRENT_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Trent1

@ LENNY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "LENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lenny

@ LUCAS_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "LUCAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lucas1

@ ALAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "ALAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Alan

@ CLARK
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "CLARK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Clark

@ ERIC
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "ERIC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Eric

@ LUCAS_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "LUCAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Lucas2

@ MIKE_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "MIKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Mike1

@ MIKE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "MIKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Mike2

@ TRENT_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Trent2

@ TRENT_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Trent3

@ TRENT_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Trent4

@ TRENT_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Trent5

@ DEZ_AND_LUKE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "DEZ & LUKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_DezAndLuke

@ LEA_AND_JED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "LEA & JED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LeaAndJed

@ KIRA_AND_DAN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KiraAndDan1

@ KIRA_AND_DAN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KiraAndDan2

@ KIRA_AND_DAN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KiraAndDan3

@ KIRA_AND_DAN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KiraAndDan4

@ KIRA_AND_DAN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KiraAndDan5

@ JOHANNA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "JOHANNA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Johanna

@ GERALD
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "GERALD$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Gerald

@ VIVIAN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "VIVIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Vivian

@ DANIELLE
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "DANIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Danielle

@ HIDEO
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "HIDEO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Hideo

@ KEIGO
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "KEIGO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Keigo

@ RILEY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "RILEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x3 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Riley

@ FLINT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "FLINT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Flint

@ ASHLEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "ASHLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Ashley

@ WALLY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.string "WALLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Wally2

@ WALLY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.string "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wally3

@ WALLY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.string "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wally4

@ WALLY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.string "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wally5

@ WALLY_6
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.string "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wally6

@ BRENDAN_13
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Brendan13

@ BRENDAN_14
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Brendan14

@ BRENDAN_15
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Brendan15

@ MAY_11
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_May11

@ MAY_12
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_May12

@ MAY_13
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_May13

@ JONAH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "JONAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Jonah

@ HENRY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "HENRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Henry

@ ROGER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "ROGER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Roger

@ ALEXA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "ALEXA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Alexa

@ RUBEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "RUBEN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Ruben

@ KOJI_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Koji1

@ WAYNE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "WAYNE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Wayne

@ AIDAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "AIDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Aidan

@ REED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "REED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Reed

@ TISHA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "TISHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tisha

@ TORI_AND_TIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.string "TORI & TIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_ToriAndTia

@ KIM_AND_IRIS
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "KIM & IRIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_KimAndIris

@ TYRA_AND_IVY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.string "TYRA & IVY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_TyraAndIvy

@ MEL_AND_PAUL
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.string "MEL & PAUL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_MelAndPaul

@ JOHN_AND_JAY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.string "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_JohnAndJay1

@ JOHN_AND_JAY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.string "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_JohnAndJay2

@ JOHN_AND_JAY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.string "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_JohnAndJay3

@ JOHN_AND_JAY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.string "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0xb @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_JohnAndJay4

@ JOHN_AND_JAY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.string "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_JohnAndJay5

@ RELI_AND_IAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "RELI & IAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_ReliAndIan

@ LILA_AND_ROY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LilaAndRoy1

@ LILA_AND_ROY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LilaAndRoy2

@ LILA_AND_ROY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LilaAndRoy3

@ LILA_AND_ROY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LilaAndRoy4

@ LILA_AND_ROY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LilaAndRoy5

@ LISA_AND_RAY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.string "LISA & RAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_LisaAndRay

@ CHRIS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "CHRIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Chris

@ DAWSON
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.string "DAWSON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Dawson

@ SARAH
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.string "SARAH$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Sarah

@ DARIAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "DARIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Darian

@ HAILEY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.string "HAILEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Hailey

@ CHANDLER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.string "CHANDLER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Chandler

@ KALEB
	.byte F_TRAINER_PARTY_HELD_ITEM @ party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS @ gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.string "KALEB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Kaleb

@ JOSEPH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "JOSEPH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Joseph

@ ALYSSA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.string "ALYSSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Alyssa

@ MARCOS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "MARCOS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Marcos

@ RHETT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "RHETT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Rhett

@ TYRON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "TYRON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tyron

@ CELINA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "CELINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Celina

@ BIANCA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "BIANCA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Bianca

@ HAYDEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "HAYDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Hayden

@ SOPHIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "SOPHIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Sophie

@ COBY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "COBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Coby

@ LAWRENCE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "LAWRENCE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Lawrence

@ WYATT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.string "WYATT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Wyatt

@ ANGELINA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "ANGELINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Angelina

@ KAI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.string "KAI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Kai

@ CHARLOTTE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "CHARLOTTE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Charlotte

@ DEANDRE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "DEANDRE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Deandre

@ GRUNT_38
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt38

@ GRUNT_39
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt39

@ GRUNT_40
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt40

@ GRUNT_41
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt41

@ GRUNT_42
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Grunt42

@ GRUNT_43
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt43

@ GRUNT_44
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt44

@ GRUNT_45
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt45

@ GRUNT_46
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt46

@ GRUNT_47
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt47

@ GRUNT_48
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt48

@ GRUNT_49
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt49

@ GRUNT_50
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt50

@ GRUNT_51
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt51

@ GRUNT_52
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt52

@ GRUNT_53
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.string "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Grunt53

@ TABITHA_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_ADMIN
	.string "TABITHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Tabitha3

@ DARCY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "DARCY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Darcy

@ MAXIE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA @ gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_LEADER_MAXIE
	.string "MAXIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Maxie3

@ PETE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.string "PETE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Pete

@ ISABELLE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.string "ISABELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Isabelle

@ ANDRES_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Andres1

@ JOSUE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "JOSUE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Josue

@ CAMRON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "CAMRON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Camron

@ CORY_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cory1

@ CAROLINA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CAROLINA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Carolina

@ ELIJAH
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "ELIJAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Elijah

@ CELIA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL @ gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.string "CELIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Celia

@ BRYAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "BRYAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bryan

@ BRANDEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.string "BRANDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Branden

@ BRYANT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "BRYANT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Bryant

@ SHAYLA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.string "SHAYLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Shayla

@ KYRA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "KYRA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Kyra

@ JAIDEN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.string "JAIDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Jaiden

@ ALIX
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "ALIX$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Alix

@ HELENE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "HELENE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Helene

@ MARLENE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "MARLENE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Marlene

@ DEVAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "DEVAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Devan

@ JOHNSON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.string "JOHNSON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Johnson

@ MELINA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.string "MELINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Melina

@ BRANDI
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "BRANDI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brandi

@ AISHA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "AISHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Aisha

@ MAKAYLA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.string "MAKAYLA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Makayla

@ FABIAN
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "FABIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Fabian

@ DAYTON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.string "DAYTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Dayton

@ RACHEL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.string "RACHEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Rachel

@ LEONEL
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.string "LEONEL$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Leonel

@ CALLIE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.string "CALLIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Callie

@ CALE
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "CALE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cale

@ MYLES
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.string "MYLES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Myles

@ PAT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "PAT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Pat

@ CRISTIN_1
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cristin1

@ MAY_14
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_May14

@ MAY_15
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_May15

@ ROXANNE_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.string "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Roxanne2

@ ROXANNE_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.string "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Roxanne3

@ ROXANNE_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.string "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Roxanne4

@ ROXANNE_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.string "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Roxanne5

@ BRAWLY_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.string "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Brawly2

@ BRAWLY_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.string "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Brawly3

@ BRAWLY_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.string "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Brawly4

@ BRAWLY_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.string "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Brawly5

@ WATTSON_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.string "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Wattson2

@ WATTSON_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.string "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wattson3

@ WATTSON_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.string "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Wattson4

@ WATTSON_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.string "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Wattson5

@ FLANNERY_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.string "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Flannery2

@ FLANNERY_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.string "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Flannery3

@ FLANNERY_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.string "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Flannery4

@ FLANNERY_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.string "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Flannery5

@ NORMAN_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.string "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 4 @ party size
	.4byte gTrainerParty_Norman2

@ NORMAN_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.string "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Norman3

@ NORMAN_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.string "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Norman4

@ NORMAN_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.string "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Norman5

@ WINONA_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.string "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x17 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Winona2

@ WINONA_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.string "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x17 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Winona3

@ WINONA_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.string "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x17 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Winona4

@ WINONA_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.string "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x17 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Winona5

@ TATE_AND_LIZA_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.string "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_TateAndLiza2

@ TATE_AND_LIZA_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.string "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_TateAndLiza3

@ TATE_AND_LIZA_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.string "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_TateAndLiza4

@ TATE_AND_LIZA_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.string "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_TateAndLiza5

@ JUAN_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.string "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Juan2

@ JUAN_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.string "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 5 @ party size
	.4byte gTrainerParty_Juan3

@ JUAN_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.string "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Juan4

@ JUAN_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.string "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE @ items
	.4byte TRUE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Juan5

@ ANGELO
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS @ gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.string "ANGELO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Angelo

@ DARIUS
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.string "DARIUS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Darius

@ STEVEN
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_STEVEN
	.string "STEVEN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Steven

@ ANABEL
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SALON_MAIDEN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SALON_MAIDEN_ANABEL
	.string "ANABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Anabel

@ TUCKER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_DOME_ACE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_DOME_ACE_TUCKER
	.string "TUCKER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Tucker

@ SPENSER
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PALACE_MAVEN
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_PALACE_MAVEN_SPENSER
	.string "SPENSER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Spenser

@ GRETA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_ARENA_TYCOON
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_ARENA_TYCOON_GRETA
	.string "GRETA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Greta

@ NOLAND
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_FACTORY_HEAD
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_FACTORY_HEAD_NOLAND
	.string "NOLAND$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Noland

@ LUCY
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PIKE_QUEEN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_PIKE_QUEEN_LUCY
	.string "LUCY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Lucy

@ BRANDON
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PYRAMID_KING
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_PYRAMID_KING_BRANDON
	.string "BRANDON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brandon

@ ANDRES_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Andres2

@ ANDRES_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Andres3

@ ANDRES_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Andres4

@ ANDRES_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.string "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Andres5

@ CORY_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cory2

@ CORY_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cory3

@ CORY_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cory4

@ CORY_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.string "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cory5

@ PABLO_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Pablo2

@ PABLO_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Pablo3

@ PABLO_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Pablo4

@ PABLO_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER @ gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.string "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Pablo5

@ KOJI_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Koji2

@ KOJI_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Koji3

@ KOJI_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Koji4

@ KOJI_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.string "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Koji5

@ CRISTIN_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Cristin2

@ CRISTIN_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cristin3

@ CRISTIN_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cristin4

@ CRISTIN_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL @ gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.string "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Cristin5

@ FERNANDO_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Fernando2

@ FERNANDO_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Fernando3

@ FERNANDO_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Fernando4

@ FERNANDO_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.string "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Fernando5

@ SAWYER_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Sawyer2

@ SAWYER_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Sawyer3

@ SAWYER_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Sawyer4

@ SAWYER_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER @ gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.string "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x7 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Sawyer5

@ GABRIELLE_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Gabrielle2

@ GABRIELLE_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Gabrielle3

@ GABRIELLE_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Gabrielle4

@ GABRIELLE_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.string "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 6 @ party size
	.4byte gTrainerParty_Gabrielle5

@ THALIA_2
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Thalia2

@ THALIA_3
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Thalia3

@ THALIA_4
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Thalia4

@ THALIA_5
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE @ gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.string "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x1 @ AI flags
	.4byte 3 @ party size
	.4byte gTrainerParty_Thalia5

@ MARIELA
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.string "MARIELA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Mariela

@ ALVARO
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE @ gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.string "ALVARO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 2 @ party size
	.4byte gTrainerParty_Alvaro

@ EVERETT
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH @ gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.string "EVERETT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Everett

@ RED
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RED
	.string "RED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Red

@ LEAF
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_LEAF
	.string "LEAF$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Leaf

@ BRENDAN_16
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_4
	.byte TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUBY_SAPPHIRE_BRENDAN
	.string "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_Brendan16

@ MAY_16
	.byte 0 @ party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_4
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE @ gender flag and encounter music
	.byte TRAINER_PIC_RUBY_SAPPHIRE_MAY
	.string "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE @ items
	.4byte FALSE @ is double battle
	.4byte 0x0 @ AI flags
	.4byte 1 @ party size
	.4byte gTrainerParty_May16
