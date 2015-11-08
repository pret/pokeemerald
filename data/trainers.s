	.align 2, 0

gTrainers: ; 8310030
; NONE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 0 ; party size
	.4byte NULL

; SAWYER_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Sawyer1

; GRUNT_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt1

; GRUNT_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt2

; GRUNT_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt3

; GRUNT_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt4

; GRUNT_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt5

; GRUNT_6
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt6

; GRUNT_7
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt7

; GABRIELLE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Gabrielle1

; GRUNT_8
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt8

; MARCEL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "MARCEL$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Marcel

; ALBERTO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ALBERTO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Alberto

; ED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "ED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ed

; GRUNT_9
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt9

; DECLAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DECLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Declan

; GRUNT_10
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt10

; GRUNT_11
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt11

; GRUNT_12
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt12

; GRUNT_13
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Grunt13

; GRUNT_14
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt14

; GRUNT_15
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt15

; GRUNT_16
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt16

; GRUNT_17
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt17

; GRUNT_18
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt18

; GRUNT_19
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt19

; GRUNT_20
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt20

; GRUNT_21
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt21

; GRUNT_22
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt22

; FREDRICK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "FREDRICK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Fredrick

; MATT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AQUA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_ADMIN_M
	.charmapstr "MATT$", 12
	.2byte ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Matt

; ZANDER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "ZANDER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Zander

; SHELLY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AQUA_ADMIN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_ADMIN_F
	.charmapstr "SHELLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelly1

; SHELLY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AQUA_ADMIN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_ADMIN_F
	.charmapstr "SHELLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelly2

; ARCHIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AQUA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_LEADER_ARCHIE
	.charmapstr "ARCHIE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Archie

; LEAH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "LEAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Leah

; DAISY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "DAISY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Daisy

; ROSE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Rose1

; FELIX
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "FELIX$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Felix

; VIOLET
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "VIOLET$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Violet

; ROSE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Rose2

; ROSE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Rose3

; ROSE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Rose4

; ROSE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "ROSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Rose5

; DUSTY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dusty1

; CHIP
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "CHIP$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Chip

; FOSTER
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "FOSTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Foster

; DUSTY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dusty2

; DUSTY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dusty3

; DUSTY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dusty4

; DUSTY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "DUSTY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dusty5

; GABBY_AND_TY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER ; gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.charmapstr "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GabbyAndTy1

; GABBY_AND_TY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER ; gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.charmapstr "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GabbyAndTy2

; GABBY_AND_TY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER ; gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.charmapstr "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GabbyAndTy3

; GABBY_AND_TY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER ; gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.charmapstr "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GabbyAndTy4

; GABBY_AND_TY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER ; gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.charmapstr "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GabbyAndTy5

; GABBY_AND_TY_6
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_INTERVIEWER
	.byte TRAINER_ENCOUNTER_MUSIC_INTERVIEWER ; gender flag and encounter music
	.byte TRAINER_PIC_INTERVIEWER
	.charmapstr "GABBY & TY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GabbyAndTy6

; LOLA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lola1

; AUSTINA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "AUSTINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Austina

; GWEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "GWEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Gwen

; LOLA_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lola2

; LOLA_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lola3

; LOLA_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lola4

; LOLA_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "LOLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lola5

; RICKY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ricky1

; SIMON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "SIMON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Simon

; CHARLIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "CHARLIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Charlie

; RICKY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ricky2

; RICKY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ricky3

; RICKY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ricky4

; RICKY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "RICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ricky5

; RANDALL
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "RANDALL$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Randall

; PARKER
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "PARKER$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Parker

; GEORGE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "GEORGE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_George

; BERKE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "BERKE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Berke

; BRAXTON
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "BRAXTON$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Braxton

; VINCENT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "VINCENT$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Vincent

; LEROY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "LEROY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Leroy

; WILTON_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "WILTON$", 12
	.2byte ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wilton1

; EDGAR
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "EDGAR$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edgar

; ALBERT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "ALBERT$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Albert

; SAMUEL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "SAMUEL$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Samuel

; VITO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "VITO$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Vito

; OWEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "OWEN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Owen

; WILTON_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "WILTON$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wilton2

; WILTON_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "WILTON$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wilton3

; WILTON_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "WILTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wilton4

; WILTON_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "WILTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wilton5

; WARREN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "WARREN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Warren

; MARY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "MARY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Mary

; ALEXIA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "ALEXIA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Alexia

; JODY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "JODY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jody

; WENDY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "WENDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wendy

; KEIRA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "KEIRA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Keira

; BROOKE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "BROOKE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brooke1

; JENNIFER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "JENNIFER$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jennifer

; HOPE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "HOPE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Hope

; SHANNON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "SHANNON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Shannon

; MICHELLE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "MICHELLE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Michelle

; CAROLINE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CAROLINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Caroline

; JULIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "JULIE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Julie

; BROOKE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "BROOKE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brooke2

; BROOKE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "BROOKE$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brooke3

; BROOKE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "BROOKE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brooke4

; BROOKE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "BROOKE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brooke5

; PATRICIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "PATRICIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Patricia

; KINDRA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "KINDRA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Kindra

; TAMMY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "TAMMY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tammy

; VALERIE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Valerie1

; TASHA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "TASHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tasha

; VALERIE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Valerie2

; VALERIE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Valerie3

; VALERIE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Valerie4

; VALERIE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "VALERIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Valerie5

; CINDY_1
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cindy1

; DAPHNE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "DAPHNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Daphne

; GRUNT_23
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Grunt23

; CINDY_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cindy2

; BRIANNA
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "BRIANNA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brianna

; NAOMI
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "NAOMI$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Naomi

; CINDY_3
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cindy3

; CINDY_4
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cindy4

; CINDY_5
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cindy5

; CINDY_6
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "CINDY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cindy6

; MELISSA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "MELISSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Melissa

; SHEILA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "SHEILA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Sheila

; SHIRLEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "SHIRLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Shirley

; JESSICA_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jessica1

; CONNIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "CONNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Connie

; BRIDGET
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "BRIDGET$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Bridget

; OLIVIA
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "OLIVIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Olivia

; TIFFANY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "TIFFANY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tiffany

; JESSICA_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jessica2

; JESSICA_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jessica3

; JESSICA_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jessica4

; JESSICA_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "JESSICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jessica5

; WINSTON_1
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Winston1

; MOLLIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "MOLLIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Mollie

; GARRET
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "GARRET$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Garret

; WINSTON_2
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Winston2

; WINSTON_3
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Winston3

; WINSTON_4
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Winston4

; WINSTON_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "WINSTON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Winston5

; STEVE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Steve1

; THALIA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Thalia1

; MARK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "MARK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Mark

; GRUNT_24
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt24

; STEVE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Steve2

; STEVE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Steve3

; STEVE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Steve4

; STEVE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "STEVE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Steve5

; LUIS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "LUIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Luis

; DOMINIK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DOMINIK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dominik

; DOUGLAS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DOUGLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Douglas

; DARRIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DARRIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Darrin

; TONY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tony1

; JEROME
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "JEROME$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jerome

; MATTHEW
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "MATTHEW$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Matthew

; DAVID
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DAVID$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_David

; SPENCER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "SPENCER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Spencer

; ROLAND
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "ROLAND$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Roland

; NOLEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "NOLEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Nolen

; STAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "STAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Stan

; BARRY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "BARRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Barry

; DEAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DEAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dean

; RODNEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "RODNEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Rodney

; RICHARD
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "RICHARD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Richard

; HERMAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "HERMAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Herman

; SANTIAGO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "SANTIAGO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Santiago

; GILBERT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "GILBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Gilbert

; FRANKLIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "FRANKLIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Franklin

; KEVIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "KEVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kevin

; JACK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "JACK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jack

; DUDLEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "DUDLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dudley

; CHAD
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "CHAD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Chad

; TONY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tony2

; TONY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tony3

; TONY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tony4

; TONY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "TONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tony5

; TAKAO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "TAKAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Takao

; HITOSHI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "HITOSHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Hitoshi

; KIYO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KIYO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kiyo

; KOICHI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KOICHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Koichi

; NOB_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Nob1

; NOB_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Nob2

; NOB_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Nob3

; NOB_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Nob4

; NOB_5
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "NOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Nob5

; YUJI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "YUJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Yuji

; DAISUKE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "DAISUKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Daisuke

; ATSUSHI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "ATSUSHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Atsushi

; KIRK
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "KIRK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Kirk

; GRUNT_25
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt25

; GRUNT_26
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt26

; SHAWN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "SHAWN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shawn

; FERNANDO_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Fernando1

; DALTON_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Dalton1

; DALTON_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dalton2

; DALTON_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dalton3

; DALTON_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dalton4

; DALTON_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "DALTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dalton5

; COLE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "COLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cole

; JEFF
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "JEFF$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jeff

; AXLE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "AXLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Axle

; JACE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "JACE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jace

; KEEGAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "KEEGAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Keegan

; BERNIE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bernie1

; BERNIE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bernie2

; BERNIE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bernie3

; BERNIE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bernie4

; BERNIE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "BERNIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bernie5

; DREW
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "DREW$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Drew

; BEAU
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "BEAU$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Beau

; LARRY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "LARRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Larry

; SHANE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "SHANE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shane

; JUSTIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "JUSTIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Justin

; ETHAN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ethan1

; AUTUMN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "AUTUMN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Autumn

; TRAVIS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "TRAVIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Travis

; ETHAN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ethan2

; ETHAN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ethan3

; ETHAN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ethan4

; ETHAN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "ETHAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ethan5

; BRENT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "BRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brent

; DONALD
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "DONALD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Donald

; TAYLOR
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "TAYLOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Taylor

; JEFFREY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jeffrey1

; DEREK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "DEREK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Derek

; JEFFREY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jeffrey2

; JEFFREY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jeffrey3

; JEFFREY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Jeffrey4

; JEFFREY_5
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "JEFFREY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Jeffrey5

; EDWARD
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "EDWARD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Edward

; PRESTON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "PRESTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Preston

; VIRGIL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "VIRGIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Virgil

; BLAKE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "BLAKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Blake

; WILLIAM
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "WILLIAM$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_William

; JOSHUA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "JOSHUA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Joshua

; CAMERON_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cameron1

; CAMERON_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cameron2

; CAMERON_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cameron3

; CAMERON_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cameron4

; CAMERON_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "CAMERON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cameron5

; JACLYN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "JACLYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jaclyn

; HANNAH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "HANNAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Hannah

; SAMANTHA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "SAMANTHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Samantha

; MAURA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "MAURA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Maura

; KAYLA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "KAYLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Kayla

; ALEXIS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "ALEXIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Alexis

; JACKI_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jacki1

; JACKI_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jacki2

; JACKI_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jacki3

; JACKI_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jacki4

; JACKI_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "JACKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jacki5

; WALTER_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Walter1

; MICAH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "MICAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Micah

; THOMAS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "THOMAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Thomas

; WALTER_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Walter2

; WALTER_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Walter3

; WALTER_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Walter4

; WALTER_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "WALTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Walter5

; SIDNEY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR ; gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_SIDNEY
	.charmapstr "SIDNEY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xf ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Sidney

; PHOEBE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR ; gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_PHOEBE
	.charmapstr "PHOEBE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Phoebe

; GLACIA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR ; gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_GLACIA
	.charmapstr "GLACIA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Glacia

; DRAKE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_ELITE_FOUR
	.byte TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR ; gender flag and encounter music
	.byte TRAINER_PIC_ELITE_FOUR_DRAKE
	.charmapstr "DRAKE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Drake

; ROXANNE_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.charmapstr "ROXANNE$", 12
	.2byte ITEM_POTION, ITEM_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Roxanne1

; BRAWLY_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.charmapstr "BRAWLY$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brawly1

; WATTSON_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.charmapstr "WATTSON$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Wattson1

; FLANNERY_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.charmapstr "FLANNERY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Flannery1

; NORMAN_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.charmapstr "NORMAN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Norman1

; WINONA_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.charmapstr "WINONA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x17 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Winona1

; TATE_AND_LIZA_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.charmapstr "TATE&LIZA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_TateAndLiza1

; JUAN_1
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.charmapstr "JUAN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Juan1

; JERRY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jerry1

; TED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "TED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ted

; PAUL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "PAUL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Paul

; JERRY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jerry2

; JERRY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jerry3

; JERRY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jerry4

; JERRY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_M
	.charmapstr "JERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jerry5

; KAREN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.charmapstr "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Karen1

; GEORGIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.charmapstr "GEORGIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Georgia

; KAREN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.charmapstr "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Karen2

; KAREN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.charmapstr "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Karen3

; KAREN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.charmapstr "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Karen4

; KAREN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SCHOOL_KID
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_SCHOOL_KID_F
	.charmapstr "KAREN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Karen5

; KATE_AND_JOY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "KATE & JOY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KateAndJoy

; ANNA_AND_MEG_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AnnaAndMeg1

; ANNA_AND_MEG_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AnnaAndMeg2

; ANNA_AND_MEG_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AnnaAndMeg3

; ANNA_AND_MEG_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AnnaAndMeg4

; ANNA_AND_MEG_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "ANNA & MEG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AnnaAndMeg5

; VICTOR
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "VICTOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Victor

; MIGUEL_1
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Miguel1

; COLTON
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "COLTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Colton

; MIGUEL_2
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Miguel2

; MIGUEL_3
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Miguel3

; MIGUEL_4
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Miguel4

; MIGUEL_5
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "MIGUEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Miguel5

; VICTORIA
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "VICTORIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Victoria

; VANESSA
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "VANESSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Vanessa

; BETHANY
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "BETHANY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Bethany

; ISABEL_1
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Isabel1

; ISABEL_2
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Isabel2

; ISABEL_3
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Isabel3

; ISABEL_4
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Isabel4

; ISABEL_5
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "ISABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Isabel5

; TIMOTHY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Timothy1

; TIMOTHY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Timothy2

; TIMOTHY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Timothy3

; TIMOTHY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Timothy4

; TIMOTHY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "TIMOTHY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Timothy5

; VICKY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "VICKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Vicky

; SHELBY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelby1

; SHELBY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelby2

; SHELBY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelby3

; SHELBY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelby4

; SHELBY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "SHELBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shelby5

; CALVIN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Calvin1

; BILLY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "BILLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Billy

; JOSH
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "JOSH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Josh

; TOMMY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "TOMMY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tommy

; JOEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "JOEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Joey

; BEN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "BEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ben

; QUINCY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "QUINCY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Quincy

; KATELYNN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "KATELYNN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Katelynn

; JAYLEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "JAYLEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jaylen

; DILLON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "DILLON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dillon

; CALVIN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Calvin2

; CALVIN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Calvin3

; CALVIN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Calvin4

; CALVIN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "CALVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Calvin5

; EDDIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "EDDIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Eddie

; ALLEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "ALLEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Allen

; TIMMY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "TIMMY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Timmy

; WALLACE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_CHAMPION
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CHAMPION_WALLACE
	.charmapstr "WALLACE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Wallace

; ANDREW
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ANDREW$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Andrew

; IVAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "IVAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ivan

; CLAUDE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "CLAUDE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Claude

; ELLIOT_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Elliot1

; NED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "NED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Ned

; DALE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "DALE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Dale

; NOLAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "NOLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Nolan

; BARNY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "BARNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Barny

; WADE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "WADE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Wade

; CARTER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "CARTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Carter

; ELLIOT_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Elliot2

; ELLIOT_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Elliot3

; ELLIOT_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Elliot4

; ELLIOT_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ELLIOT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Elliot5

; RONALD
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "RONALD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Ronald

; JACOB
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "JACOB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jacob

; ANTHONY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "ANTHONY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Anthony

; BENJAMIN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Benjamin1

; BENJAMIN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Benjamin2

; BENJAMIN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Benjamin3

; BENJAMIN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Benjamin4

; BENJAMIN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "BENJAMIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Benjamin5

; ABIGAIL_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Abigail1

; JASMINE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "JASMINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jasmine

; ABIGAIL_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Abigail2

; ABIGAIL_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Abigail3

; ABIGAIL_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Abigail4

; ABIGAIL_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "ABIGAIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Abigail5

; DYLAN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.charmapstr "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dylan1

; DYLAN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.charmapstr "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dylan2

; DYLAN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.charmapstr "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dylan3

; DYLAN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.charmapstr "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dylan4

; DYLAN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_M
	.charmapstr "DYLAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dylan5

; MARIA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Maria1

; MARIA_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Maria2

; MARIA_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Maria3

; MARIA_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Maria4

; MARIA_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "MARIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Maria5

; CAMDEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "CAMDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Camden

; DEMETRIUS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "DEMETRIUS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Demetrius

; ISAIAH_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isaiah1

; PABLO_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Pablo1

; CHASE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "CHASE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Chase

; ISAIAH_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isaiah2

; ISAIAH_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isaiah3

; ISAIAH_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isaiah4

; ISAIAH_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "ISAIAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isaiah5

; ISOBEL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "ISOBEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isobel

; DONNY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "DONNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Donny

; TALIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "TALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Talia

; KATELYN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Katelyn1

; ALLISON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "ALLISON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Allison

; KATELYN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Katelyn2

; KATELYN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Katelyn3

; KATELYN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Katelyn4

; KATELYN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "KATELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Katelyn5

; NICOLAS_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.charmapstr "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Nicolas1

; NICOLAS_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.charmapstr "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Nicolas2

; NICOLAS_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.charmapstr "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Nicolas3

; NICOLAS_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.charmapstr "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Nicolas4

; NICOLAS_5
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.charmapstr "NICOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Nicolas5

; AARON
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_DRAGON_TAMER
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_DRAGON_TAMER
	.charmapstr "AARON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Aaron

; PERRY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "PERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Perry

; HUGH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "HUGH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Hugh

; PHIL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "PHIL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Phil

; JARED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "JARED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jared

; HUMBERTO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "HUMBERTO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Humberto

; PRESLEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "PRESLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Presley

; EDWARDO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "EDWARDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edwardo

; COLIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "COLIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Colin

; ROBERT_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Robert1

; BENNY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "BENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Benny

; CHESTER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "CHESTER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Chester

; ROBERT_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Robert2

; ROBERT_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Robert3

; ROBERT_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Robert4

; ROBERT_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ROBERT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Robert5

; ALEX
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ALEX$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Alex

; BECK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "BECK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Beck

; YASU
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "YASU$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Yasu

; TAKASHI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "TAKASHI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Takashi

; DIANNE
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "DIANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Dianne

; JANI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "JANI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jani

; LAO_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Lao1

; LUNG
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "LUNG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lung

; LAO_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Lao2

; LAO_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Lao3

; LAO_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Lao4

; LAO_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "LAO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Lao5

; JOCELYN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "JOCELYN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jocelyn

; LAURA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "LAURA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Laura

; CYNDY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cyndy1

; CORA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CORA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cora

; PAULA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "PAULA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Paula

; CYNDY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cyndy2

; CYNDY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cyndy3

; CYNDY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cyndy4

; CYNDY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CYNDY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cyndy5

; MADELINE_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Madeline1

; CLARISSA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "CLARISSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Clarissa

; ANGELICA
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "ANGELICA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Angelica

; MADELINE_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Madeline2

; MADELINE_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Madeline3

; MADELINE_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Madeline4

; MADELINE_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "MADELINE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Madeline5

; BEVERLY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "BEVERLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Beverly

; IMANI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "IMANI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Imani

; KYLA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "KYLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kyla

; DENISE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "DENISE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Denise

; BETH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "BETH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Beth

; TARA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "TARA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tara

; MISSY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "MISSY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Missy

; ALICE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "ALICE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Alice

; JENNY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jenny1

; GRACE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "GRACE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grace

; TANYA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "TANYA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tanya

; SHARON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "SHARON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Sharon

; NIKKI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "NIKKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Nikki

; BRENDA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "BRENDA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brenda

; KATIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "KATIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Katie

; SUSIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "SUSIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Susie

; KARA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "KARA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kara

; DANA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "DANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Dana

; SIENNA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "SIENNA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Sienna

; DEBRA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "DEBRA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Debra

; LINDA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "LINDA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Linda

; KAYLEE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "KAYLEE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Kaylee

; LAUREL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "LAUREL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Laurel

; CARLEE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "CARLEE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Carlee

; JENNY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jenny2

; JENNY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jenny3

; JENNY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jenny4

; JENNY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "JENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jenny5

; HEIDI
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "HEIDI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Heidi

; BECKY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "BECKY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Becky

; CAROL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "CAROL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Carol

; NANCY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "NANCY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Nancy

; MARTHA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "MARTHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Martha

; DIANA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Diana1

; CEDRIC
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "CEDRIC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cedric

; IRENE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "IRENE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Irene

; DIANA_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Diana2

; DIANA_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Diana3

; DIANA_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Diana4

; DIANA_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "DIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Diana5

; AMY_AND_LIV_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AmyAndLiv1

; AMY_AND_LIV_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AmyAndLiv2

; GINA_AND_MIA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "GINA & MIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GinaAndMia1

; MIU_AND_YUKI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "MIU & YUKI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_MiuAndYuki

; AMY_AND_LIV_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AmyAndLiv3

; GINA_AND_MIA_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "GINA & MIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_GinaAndMia2

; AMY_AND_LIV_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AmyAndLiv4

; AMY_AND_LIV_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AmyAndLiv5

; AMY_AND_LIV_6
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "AMY & LIV$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_AmyAndLiv6

; HUEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "HUEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Huey

; EDMOND
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "EDMOND$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Edmond

; ERNEST_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ernest1

; DWAYNE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "DWAYNE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Dwayne

; PHILLIP
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "PHILLIP$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Phillip

; LEONARD
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "LEONARD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Leonard

; DUNCAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "DUNCAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Duncan

; ERNEST_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ernest2

; ERNEST_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ernest3

; ERNEST_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ernest4

; ERNEST_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "ERNEST$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ernest5

; ELI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "ELI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Eli

; ANNIKA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_F
	.charmapstr "ANNIKA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Annika

; JAZMYN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_2
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "JAZMYN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jazmyn

; JONAS
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "JONAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jonas

; KAYLEY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "KAYLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kayley

; AURON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "AURON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Auron

; KELVIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "KELVIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Kelvin

; MARLEY
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "MARLEY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Marley

; REYNA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "REYNA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Reyna

; HUDSON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "HUDSON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Hudson

; CONOR
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "CONOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Conor

; EDWIN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edwin1

; HECTOR
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "HECTOR$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Hector

; TABITHA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_ADMIN
	.charmapstr "TABITHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Tabitha1

; EDWIN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edwin2

; EDWIN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edwin3

; EDWIN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edwin4

; EDWIN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COLLECTOR
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_COLLECTOR
	.charmapstr "EDWIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Edwin5

; WALLY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.charmapstr "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wally1

; BRENDAN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brendan1

; BRENDAN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brendan2

; BRENDAN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brendan3

; BRENDAN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brendan4

; BRENDAN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brendan5

; BRENDAN_6
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brendan6

; BRENDAN_7
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brendan7

; BRENDAN_8
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brendan8

; BRENDAN_9
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Brendan9

; MAY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_May1

; MAY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_May2

; MAY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_May3

; MAY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_May4

; MAY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_May5

; MAY_6
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_May6

; MAY_7
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_May7

; MAY_8
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_May8

; MAY_9
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_May9

; ISAAC_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.charmapstr "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Isaac1

; DAVIS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "DAVIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Davis

; MITCHELL
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "MITCHELL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Mitchell

; ISAAC_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.charmapstr "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Isaac2

; ISAAC_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.charmapstr "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Isaac3

; ISAAC_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.charmapstr "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Isaac4

; ISAAC_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.charmapstr "ISAAC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Isaac5

; LYDIA_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Lydia1

; HALLE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "HALLE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Halle

; GARRISON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "GARRISON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Garrison

; LYDIA_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Lydia2

; LYDIA_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Lydia3

; LYDIA_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Lydia4

; LYDIA_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "LYDIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Lydia5

; JACKSON_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jackson1

; LORENZO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "LORENZO$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Lorenzo

; SEBASTIAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "SEBASTIAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Sebastian

; JACKSON_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jackson2

; JACKSON_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jackson3

; JACKSON_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Jackson4

; JACKSON_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_M
	.charmapstr "JACKSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jackson5

; CATHERINE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Catherine1

; JENNA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "JENNA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jenna

; SOPHIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "SOPHIA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Sophia

; CATHERINE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Catherine2

; CATHERINE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Catherine3

; CATHERINE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Catherine4

; CATHERINE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_RANGER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_RANGER_F
	.charmapstr "CATHERINE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Catherine5

; JULIO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_M
	.charmapstr "JULIO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Julio

; GRUNT_27
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt27

; GRUNT_28
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt28

; GRUNT_29
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt29

; GRUNT_30
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt30

; MARC
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "MARC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Marc

; BRENDEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "BRENDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brenden

; LILITH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "LILITH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Lilith

; CRISTIAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "CRISTIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Cristian

; SYLVIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "SYLVIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Sylvia

; LEONARDO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "LEONARDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Leonardo

; ATHENA
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "ATHENA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Athena

; HARRISON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "HARRISON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Harrison

; GRUNT_31
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt31

; CLARENCE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "CLARENCE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Clarence

; TERRY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "TERRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Terry

; NATE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "NATE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Nate

; KATHLEEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HEX_MANIAC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_HEX_MANIAC
	.charmapstr "KATHLEEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kathleen

; CLIFFORD
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "CLIFFORD$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Clifford

; NICHOLAS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "NICHOLAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Nicholas

; GRUNT_32
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt32

; GRUNT_33
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt33

; GRUNT_34
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt34

; GRUNT_35
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt35

; GRUNT_36
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt36

; MACEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "MACEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Macey

; BRENDAN_10
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Brendan10

; BRENDAN_11
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Brendan11

; PAXTON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_M
	.charmapstr "PAXTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Paxton

; ISABELLA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.charmapstr "ISABELLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isabella

; GRUNT_37
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_AQUA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA ; gender flag and encounter music
	.byte TRAINER_PIC_AQUA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt37

; TABITHA_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_ADMIN
	.charmapstr "TABITHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Tabitha2

; JONATHAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "JONATHAN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jonathan

; BRENDAN_12
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Brendan12

; MAY_10
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_May10

; MAXIE_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_LEADER_MAXIE
	.charmapstr "MAXIE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Maxie1

; MAXIE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_LEADER_MAXIE
	.charmapstr "MAXIE$", 12
	.2byte ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Maxie2

; TIANA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "TIANA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Tiana

; HALEY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Haley1

; JANICE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "JANICE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Janice

; VIVI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_WINSTRATE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "VIVI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Vivi

; HALEY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Haley2

; HALEY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Haley3

; HALEY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Haley4

; HALEY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "HALEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Haley5

; SALLY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "SALLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Sally

; ROBIN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "ROBIN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Robin

; ANDREA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "ANDREA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Andrea

; CRISSY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_LASS
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LASS
	.charmapstr "CRISSY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Crissy

; RICK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "RICK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Rick

; LYLE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "LYLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Lyle

; JOSE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "JOSE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jose

; DOUG
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "DOUG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Doug

; GREG
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "GREG$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Greg

; KENT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "KENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kent

; JAMES_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_James1

; JAMES_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_James2

; JAMES_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_James3

; JAMES_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_James4

; JAMES_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_CATCHER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_CATCHER
	.charmapstr "JAMES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_James5

; BRICE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "BRICE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Brice

; TRENT_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Trent1

; LENNY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "LENNY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lenny

; LUCAS_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "LUCAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lucas1

; ALAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "ALAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Alan

; CLARK
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "CLARK$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Clark

; ERIC
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "ERIC$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Eric

; LUCAS_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "LUCAS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Lucas2

; MIKE_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "MIKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Mike1

; MIKE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "MIKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Mike2

; TRENT_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Trent2

; TRENT_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Trent3

; TRENT_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Trent4

; TRENT_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "TRENT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Trent5

; DEZ_AND_LUKE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "DEZ & LUKE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_DezAndLuke

; LEA_AND_JED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "LEA & JED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LeaAndJed

; KIRA_AND_DAN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KiraAndDan1

; KIRA_AND_DAN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KiraAndDan2

; KIRA_AND_DAN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KiraAndDan3

; KIRA_AND_DAN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KiraAndDan4

; KIRA_AND_DAN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "KIRA & DAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KiraAndDan5

; JOHANNA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "JOHANNA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Johanna

; GERALD
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "GERALD$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Gerald

; VIVIAN
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "VIVIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Vivian

; DANIELLE
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "DANIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Danielle

; HIDEO
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "HIDEO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Hideo

; KEIGO
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "KEIGO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Keigo

; RILEY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "RILEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x3 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Riley

; FLINT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "FLINT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Flint

; ASHLEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "ASHLEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Ashley

; WALLY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.charmapstr "WALLY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Wally2

; WALLY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.charmapstr "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wally3

; WALLY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.charmapstr "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wally4

; WALLY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.charmapstr "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wally5

; WALLY_6
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_WALLY
	.charmapstr "WALLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wally6

; BRENDAN_13
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Brendan13

; BRENDAN_14
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Brendan14

; BRENDAN_15
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Brendan15

; MAY_11
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_May11

; MAY_12
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_May12

; MAY_13
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_May13

; JONAH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "JONAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Jonah

; HENRY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "HENRY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Henry

; ROGER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "ROGER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Roger

; ALEXA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "ALEXA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Alexa

; RUBEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "RUBEN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Ruben

; KOJI_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Koji1

; WAYNE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "WAYNE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Wayne

; AIDAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "AIDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Aidan

; REED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "REED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Reed

; TISHA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "TISHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tisha

; TORI_AND_TIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TWINS
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_TWINS
	.charmapstr "TORI & TIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_ToriAndTia

; KIM_AND_IRIS
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "KIM & IRIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_KimAndIris

; TYRA_AND_IVY
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_SR_AND_JR
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_SR_AND_JR
	.charmapstr "TYRA & IVY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_TyraAndIvy

; MEL_AND_PAUL
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNG_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNG_COUPLE
	.charmapstr "MEL & PAUL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_MelAndPaul

; JOHN_AND_JAY_1
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.charmapstr "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_JohnAndJay1

; JOHN_AND_JAY_2
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.charmapstr "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_JohnAndJay2

; JOHN_AND_JAY_3
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.charmapstr "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_JohnAndJay3

; JOHN_AND_JAY_4
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.charmapstr "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0xb ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_JohnAndJay4

; JOHN_AND_JAY_5
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_OLD_COUPLE
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_OLD_COUPLE
	.charmapstr "JOHN & JAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_JohnAndJay5

; RELI_AND_IAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "RELI & IAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_ReliAndIan

; LILA_AND_ROY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LilaAndRoy1

; LILA_AND_ROY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LilaAndRoy2

; LILA_AND_ROY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LilaAndRoy3

; LILA_AND_ROY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LilaAndRoy4

; LILA_AND_ROY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "LILA & ROY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LilaAndRoy5

; LISA_AND_RAY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SIS_AND_BRO
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SIS_AND_BRO
	.charmapstr "LISA & RAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_LisaAndRay

; CHRIS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "CHRIS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Chris

; DAWSON
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_RICH_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_RICH_BOY
	.charmapstr "DAWSON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Dawson

; SARAH
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LADY
	.charmapstr "SARAH$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Sarah

; DARIAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "DARIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Darian

; HAILEY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_F
	.charmapstr "HAILEY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Hailey

; CHANDLER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TUBER_2
	.byte TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_TUBER_M
	.charmapstr "CHANDLER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Chandler

; KALEB
	.byte F_TRAINER_PARTY_HELD_ITEM ; party type flags
	.byte TRAINER_CLASS_NAME_POKEFAN
	.byte TRAINER_ENCOUNTER_MUSIC_TWINS ; gender flag and encounter music
	.byte TRAINER_PIC_WINSTRATE_M
	.charmapstr "KALEB$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Kaleb

; JOSEPH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "JOSEPH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Joseph

; ALYSSA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_CYCLING_TRIATHLETE_F
	.charmapstr "ALYSSA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Alyssa

; MARCOS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "MARCOS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Marcos

; RHETT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "RHETT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Rhett

; TYRON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "TYRON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tyron

; CELINA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "CELINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Celina

; BIANCA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "BIANCA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Bianca

; HAYDEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "HAYDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Hayden

; SOPHIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "SOPHIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Sophie

; COBY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "COBY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Coby

; LAWRENCE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "LAWRENCE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Lawrence

; WYATT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_POKEMANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMANIAC
	.charmapstr "WYATT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Wyatt

; ANGELINA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "ANGELINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Angelina

; KAI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FISHERMAN
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_FISHERMAN
	.charmapstr "KAI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Kai

; CHARLOTTE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "CHARLOTTE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Charlotte

; DEANDRE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "DEANDRE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Deandre

; GRUNT_38
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt38

; GRUNT_39
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt39

; GRUNT_40
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt40

; GRUNT_41
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt41

; GRUNT_42
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Grunt42

; GRUNT_43
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt43

; GRUNT_44
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt44

; GRUNT_45
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt45

; GRUNT_46
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt46

; GRUNT_47
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt47

; GRUNT_48
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt48

; GRUNT_49
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt49

; GRUNT_50
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_M
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt50

; GRUNT_51
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt51

; GRUNT_52
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt52

; GRUNT_53
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TEAM_MAGMA
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_GRUNT_F
	.charmapstr "GRUNT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Grunt53

; TABITHA_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_ADMIN
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_ADMIN
	.charmapstr "TABITHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Tabitha3

; DARCY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "DARCY$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Darcy

; MAXIE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_MAGMA_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MAGMA ; gender flag and encounter music
	.byte TRAINER_PIC_MAGMA_LEADER_MAXIE
	.charmapstr "MAXIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Maxie3

; PETE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_M
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_M
	.charmapstr "PETE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Pete

; ISABELLE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SWIMMER_F
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMER_F
	.charmapstr "ISABELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Isabelle

; ANDRES_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Andres1

; JOSUE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "JOSUE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Josue

; CAMRON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "CAMRON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Camron

; CORY_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cory1

; CAROLINA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CAROLINA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Carolina

; ELIJAH
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "ELIJAH$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Elijah

; CELIA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PICNICKER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL ; gender flag and encounter music
	.byte TRAINER_PIC_PICNICKER
	.charmapstr "CELIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Celia

; BRYAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "BRYAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bryan

; BRANDEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_CAMPER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_CAMPER
	.charmapstr "BRANDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Branden

; BRYANT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "BRYANT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Bryant

; SHAYLA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_AROMA_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_AROMA_LADY
	.charmapstr "SHAYLA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Shayla

; KYRA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "KYRA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Kyra

; JAIDEN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_NINJA_BOY
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_NINJA_BOY
	.charmapstr "JAIDEN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Jaiden

; ALIX
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "ALIX$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Alix

; HELENE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "HELENE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Helene

; MARLENE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "MARLENE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Marlene

; DEVAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "DEVAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Devan

; JOHNSON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_YOUNGSTER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_YOUNGSTER
	.charmapstr "JOHNSON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Johnson

; MELINA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUNNING_TRIATHLETE_F
	.charmapstr "MELINA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Melina

; BRANDI
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "BRANDI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brandi

; AISHA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "AISHA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Aisha

; MAKAYLA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_EXPERT
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_EXPERT_F
	.charmapstr "MAKAYLA$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Makayla

; FABIAN
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "FABIAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Fabian

; DAYTON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_KINDLER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_KINDLER
	.charmapstr "DAYTON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Dayton

; RACHEL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PARASOL_LADY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_PARASOL_LADY
	.charmapstr "RACHEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Rachel

; LEONEL
	.byte F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_M
	.charmapstr "LEONEL$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Leonel

; CALLIE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BATTLE_GIRL
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BATTLE_GIRL
	.charmapstr "CALLIE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Callie

; CALE
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "CALE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cale

; MYLES
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_M
	.charmapstr "MYLES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Myles

; PAT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "PAT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Pat

; CRISTIN_1
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cristin1

; MAY_14
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_May14

; MAY_15
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_May15

; ROXANNE_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.charmapstr "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Roxanne2

; ROXANNE_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.charmapstr "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Roxanne3

; ROXANNE_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.charmapstr "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Roxanne4

; ROXANNE_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_ROXANNE
	.charmapstr "ROXANNE$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Roxanne5

; BRAWLY_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.charmapstr "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Brawly2

; BRAWLY_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.charmapstr "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Brawly3

; BRAWLY_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.charmapstr "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Brawly4

; BRAWLY_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_BRAWLY
	.charmapstr "BRAWLY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Brawly5

; WATTSON_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.charmapstr "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Wattson2

; WATTSON_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.charmapstr "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wattson3

; WATTSON_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.charmapstr "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Wattson4

; WATTSON_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WATTSON
	.charmapstr "WATTSON$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Wattson5

; FLANNERY_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.charmapstr "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Flannery2

; FLANNERY_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.charmapstr "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Flannery3

; FLANNERY_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.charmapstr "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Flannery4

; FLANNERY_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_FLANNERY
	.charmapstr "FLANNERY$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Flannery5

; NORMAN_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.charmapstr "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 4 ; party size
	.4byte gTrainerParty_Norman2

; NORMAN_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.charmapstr "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Norman3

; NORMAN_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.charmapstr "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Norman4

; NORMAN_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_NORMAN
	.charmapstr "NORMAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Norman5

; WINONA_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.charmapstr "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x17 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Winona2

; WINONA_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.charmapstr "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x17 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Winona3

; WINONA_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.charmapstr "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x17 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Winona4

; WINONA_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_WINONA
	.charmapstr "WINONA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x17 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Winona5

; TATE_AND_LIZA_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.charmapstr "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_TateAndLiza2

; TATE_AND_LIZA_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.charmapstr "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_TateAndLiza3

; TATE_AND_LIZA_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.charmapstr "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_TateAndLiza4

; TATE_AND_LIZA_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_TATE_AND_LIZA
	.charmapstr "TATE&LIZA$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_TateAndLiza5

; JUAN_2
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.charmapstr "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Juan2

; JUAN_3
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.charmapstr "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 5 ; party size
	.4byte gTrainerParty_Juan3

; JUAN_4
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.charmapstr "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Juan4

; JUAN_5
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_LEADER
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEADER_JUAN
	.charmapstr "JUAN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE ; items
	.4byte TRUE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Juan5

; ANGELO
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_BUG_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS ; gender flag and encounter music
	.byte TRAINER_PIC_BUG_MANIAC
	.charmapstr "ANGELO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Angelo

; DARIUS
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BIRD_KEEPER
	.byte TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_BIRD_KEEPER
	.charmapstr "DARIUS$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Darius

; STEVEN
	.byte F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_STEVEN
	.charmapstr "STEVEN$", 12
	.2byte ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Steven

; ANABEL
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SALON_MAIDEN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SALON_MAIDEN_ANABEL
	.charmapstr "ANABEL$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Anabel

; TUCKER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_DOME_ACE
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_DOME_ACE_TUCKER
	.charmapstr "TUCKER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Tucker

; SPENSER
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PALACE_MAVEN
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_PALACE_MAVEN_SPENSER
	.charmapstr "SPENSER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Spenser

; GRETA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_ARENA_TYCOON
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_ARENA_TYCOON_GRETA
	.charmapstr "GRETA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Greta

; NOLAND
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_FACTORY_HEAD
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_FACTORY_HEAD_NOLAND
	.charmapstr "NOLAND$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Noland

; LUCY
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PIKE_QUEEN
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_PIKE_QUEEN_LUCY
	.charmapstr "LUCY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Lucy

; BRANDON
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PYRAMID_KING
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_PYRAMID_KING_BRANDON
	.charmapstr "BRANDON$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brandon

; ANDRES_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Andres2

; ANDRES_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Andres3

; ANDRES_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Andres4

; ANDRES_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_RUIN_MANIAC
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_RUIN_MANIAC
	.charmapstr "ANDRES$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Andres5

; CORY_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cory2

; CORY_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cory3

; CORY_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cory4

; CORY_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_SAILOR
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_SAILOR
	.charmapstr "CORY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cory5

; PABLO_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Pablo2

; PABLO_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Pablo3

; PABLO_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Pablo4

; PABLO_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_TRIATHLETE
	.byte TRAINER_ENCOUNTER_MUSIC_SWIMMER ; gender flag and encounter music
	.byte TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.charmapstr "PABLO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Pablo5

; KOJI_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Koji2

; KOJI_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Koji3

; KOJI_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Koji4

; KOJI_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BLACK_BELT
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_BLACK_BELT
	.charmapstr "KOJI$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Koji5

; CRISTIN_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Cristin2

; CRISTIN_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cristin3

; CRISTIN_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cristin4

; CRISTIN_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_COOLTRAINER_1
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL ; gender flag and encounter music
	.byte TRAINER_PIC_COOL_TRAINER_F
	.charmapstr "CRISTIN$", 12
	.2byte ITEM_HYPER_POTION, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Cristin5

; FERNANDO_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Fernando2

; FERNANDO_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Fernando3

; FERNANDO_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Fernando4

; FERNANDO_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GUITARIST
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_GUITARIST
	.charmapstr "FERNANDO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Fernando5

; SAWYER_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Sawyer2

; SAWYER_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Sawyer3

; SAWYER_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Sawyer4

; SAWYER_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_HIKER
	.byte TRAINER_ENCOUNTER_MUSIC_HIKER ; gender flag and encounter music
	.byte TRAINER_PIC_HIKER
	.charmapstr "SAWYER$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x7 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Sawyer5

; GABRIELLE_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Gabrielle2

; GABRIELLE_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Gabrielle3

; GABRIELLE_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Gabrielle4

; GABRIELLE_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_BREEDER
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_POKEMON_BREEDER_F
	.charmapstr "GABRIELLE$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 6 ; party size
	.4byte gTrainerParty_Gabrielle5

; THALIA_2
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Thalia2

; THALIA_3
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Thalia3

; THALIA_4
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Thalia4

; THALIA_5
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_BEAUTY
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE ; gender flag and encounter music
	.byte TRAINER_PIC_BEAUTY
	.charmapstr "THALIA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x1 ; AI flags
	.4byte 3 ; party size
	.4byte gTrainerParty_Thalia5

; MARIELA
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_F
	.charmapstr "MARIELA$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Mariela

; ALVARO
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PSYCHIC
	.byte TRAINER_ENCOUNTER_MUSIC_INTENSE ; gender flag and encounter music
	.byte TRAINER_PIC_PSYCHIC_M
	.charmapstr "ALVARO$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 2 ; party size
	.4byte gTrainerParty_Alvaro

; EVERETT
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_GENTLEMAN
	.byte TRAINER_ENCOUNTER_MUSIC_RICH ; gender flag and encounter music
	.byte TRAINER_PIC_GENTLEMAN
	.charmapstr "EVERETT$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Everett

; RED
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RED
	.charmapstr "RED$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Red

; LEAF
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_3
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_LEAF
	.charmapstr "LEAF$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Leaf

; BRENDAN_16
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_4
	.byte TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUBY_SAPPHIRE_BRENDAN
	.charmapstr "BRENDAN$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_Brendan16

; MAY_16
	.byte 0 ; party type flags
	.byte TRAINER_CLASS_NAME_PKMN_TRAINER_4
	.byte F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE ; gender flag and encounter music
	.byte TRAINER_PIC_RUBY_SAPPHIRE_MAY
	.charmapstr "MAY$", 12
	.2byte ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE ; items
	.4byte FALSE ; is double battle
	.4byte 0x0 ; AI flags
	.4byte 1 ; party size
	.4byte gTrainerParty_May16
