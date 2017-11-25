	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"
	.include "constants/battle_constants.inc"
	.include "constants/battle_script_constants.inc"
	.include "constants/battle_text.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattlescriptsForBallThrow:: @ 82DBD08
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD7E
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68
	.4byte BattleScript_82DBD68

	.align 2
gUnknown_082DBD3C:: @ 82DBD3C
	.4byte BattleScript_82DBE12
	.4byte BattleScript_82DBE1C
	.4byte BattleScript_82DBE1C
	.4byte BattleScript_82DBE4B
	.4byte BattleScript_82DBE6F
	.4byte BattleScript_82DBE91

	.align 2
gBattlescriptsForRunningByItem:: @ 82DBD54
	.4byte BattleScript_RunByUsingItem

	.align 2
gBattlescriptsForSafariActions:: @ 82DBD58
	.4byte BattleScript_82DBEBD
	.4byte BattleScript_82DBEC4
	.4byte BattleScript_82DBECD
	.4byte BattleScript_82DBEE3

BattleScript_82DBD68::
	jumpifword COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_WALLY_TUTORIAL, BattleScript_82DBD7A
	printstring STRINGID_PLAYERUSEDITEM
	pokeball_catch_calculation

BattleScript_82DBD7A::
	printstring STRINGID_WALLYUSEDITEM
	pokeball_catch_calculation

BattleScript_82DBD7E::
	printstring STRINGID_PLAYERUSEDITEM
	updatestatusicon ATTACKER
	pokeball_catch_calculation

BattleScript_SuccessBallThrow::
	jumpifhalfword EQUAL, gLastUsedItem, 0x5, BattleScript_82DBD92
	incrementgamestat 0xB
BattleScript_82DBD92::
	printstring STRINGID_GOTCHAPKMNCAUGHT
	trysetcaughtmondexflags BattleScript_82DBDA5
	printstring STRINGID_PKMNDATAADDEDTODEX
	waitstate
	setbyte gBattleCommunication, 0x0
	displaydexinfo
BattleScript_82DBDA5::
	printstring STRINGID_GIVENICKNAMECAPTURED
	waitstate
	setbyte gBattleCommunication, 0x0
	trygivecaughtmonnick BattleScript_82DBDC2
	givecaughtmon
	printfromtable 0x85CC97A
	waitmessage 0x40
	goto BattleScript_82DBDC3

BattleScript_82DBDC2::
	givecaughtmon
BattleScript_82DBDC3::
	setbyte gBattleOutcome, CAUGHT
	finishturn

BattleScript_WallyBallThrow::
	printstring STRINGID_GOTCHAPKMNCAUGHT2
	setbyte gBattleOutcome, CAUGHT
	finishturn

BattleScript_ShakeBallThrow::
	printfromtable 0x85CC912
	waitmessage 0x40
	jumpifword NO_COMMON_BITS, gBattleTypeFlags, BATTLE_TYPE_SAFARI, BattleScript_82DBE01
	jumpifbyte NOT_EQUAL, gNumSafariBalls, 0x0, BattleScript_82DBE01
	printstring STRINGID_OUTOFSAFARIBALLS
	waitmessage 0x40
	setbyte gBattleOutcome, OUT_OF_BALLS
BattleScript_82DBE01::
	finishaction

BattleScript_TrainerBallBlock::
	waitmessage 0x40
	printstring STRINGID_TRAINERBLOCKEDBALL
	waitmessage 0x40
	printstring STRINGID_DONTBEATHIEF
	waitmessage 0x40
	finishaction

BattleScript_82DBE12::
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	end

BattleScript_82DBE1C::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse 0x1
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate ATTACKER
	datahpupdate ATTACKER
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage 0x40
	updatestatusicon ATTACKER
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_82DBE4B::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse 0x1
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable 0x85CC94E
	waitmessage 0x40
	updatestatusicon ATTACKER
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_82DBE6F::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse 0x1
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable 0x85CC89C
	waitmessage 0x40
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_82DBE91::
	printstring STRINGID_EMPTYSTRING3
	pause 0x30
	playse 0x1
	printstring STRINGID_TRAINER1USEDITEM
	waitmessage 0x40
	useitemonopponent
	printfromtable 0x85CC8CC
	waitmessage 0x40
	setbyte sMOVEEND_STATE, 0xF
	moveend 0x1, 0x0
	finishaction

BattleScript_RunByUsingItem::
	playse 0x11
	setbyte gBattleOutcome, RAN
	finishturn

BattleScript_82DBEBD::
	printstring STRINGID_PKMNWATCHINGCAREFULLY
	waitmessage 0x40
	end2

BattleScript_82DBEC4::
	printfromtable 0x85CC944
	waitmessage 0x40
	end2

BattleScript_82DBECD::
	printstring STRINGID_THREWPOKEBLOCKATPKMN
	waitmessage 0x40
	playanimation ATTACKER, ANIM_x4, NULL
	printfromtable 0x85CC948
	waitmessage 0x40
	end2

BattleScript_82DBEE3::
	printstring STRINGID_RETURNMON
	waitmessage 0x40
	returnatktoball
	waitstate
	trainerslidein TARGET
	waitstate
	printstring STRINGID_YOUTHROWABALLNOWRIGHT
	waitmessage 0x40
	end2
