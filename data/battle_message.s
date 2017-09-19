	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gText_Buffer36:: @ 85C9B78
	.string "{STRING 36}$"

gText_PkmnGainedEXP:: @ 85C9B7B
	.string "{STRING 0} gained{PLAYER}\n{STRING 52} EXP. Points!\p$"

gText_EmptyString4:: @ 85C9B98
	.string "$"

gText_ABoosted:: @ 85C9B99
	.string " a boosted$"

gText_PkmnGrewToLv:: @ 85C9BA4
	.string "{STRING 0} grew to\nLV. {PLAYER}!{UNKNOWN_A}\p$"

gText_PkmnLearnedMove:: @ 85C9BBA
	.string "{STRING 0} learned\n{PLAYER}!{UNKNOWN_A}\p$"

gText_TryToLearnMove1:: @ 85C9BCC
	.string "{STRING 0} is trying to\nlearn {PLAYER}.\p$"

gText_TryToLearnMove2:: @ 85C9BE7
	.string "But, {STRING 0} can’t learn\nmore than four moves.\p$"

gText_TryToLearnMove3:: @ 85C9C12
	.string "Delete a move to make\nroom for {PLAYER}?$"

gText_PkmnForgotMove:: @ 85C9C35
	.string "{STRING 0} forgot\n{PLAYER}.\p$"

gText_StopLearningMove:: @ 85C9C44
	.string "{PAUSE 32}Stop learning\n{PLAYER}?$"

gText_DidNotLearnMove:: @ 85C9C59
	.string "{STRING 0} did not learn\n{PLAYER}.\p$"

gText_UseNextPkmn:: @ 85C9C6F
	.string "Use next POKéMON?$"

gText_AttackMissed:: @ 85C9C81
	.string "{STRING 15}’s\nattack missed!$"

gText_PkmnProtectedItself:: @ 85C9C95
	.string "{STRING 16}\nprotected itself!$"

gText_AvoidedDamage:: @ 85C9CAA
	.string "{STRING 16} avoided\ndamage with {STRING 25}!$"

gText_PkmnMakesGroundMiss:: @ 85C9CC5
	.string "{STRING 16} makes GROUND\nmoves miss with {STRING 25}!$"

gText_PkmnAvoidedAttack:: @ 85C9CE9
	.string "{STRING 16} avoided\nthe attack!$"

gText_ItDoesntAffect:: @ 85C9D00
	.string "It doesn’t affect\n{STRING 16}…$"

gText_PkmnFainted:: @ 85C9D16
	.string "{STRING 15}\nfainted!\p$"

gText_PkmnFainted2:: @ 85C9D23
	.string "{STRING 16}\nfainted!\p$"

gText_PlayerGotMoney:: @ 85C9D30
	.string "{STRING 35} got ¥{STRING 0}\nfor winning!\p$"

gText_PlayerWhiteout:: @ 85C9D49
	.string "{STRING 35} is out of\nusable POKéMON!\p$"

gText_PlayerWhiteout2:: @ 85C9D67
	.string "{STRING 35} whited out!{PAUSE_UNTIL_PRESS}$"

gText_PreventsEscape:: @ 85C9D78
	.string "{STRING 19} prevents\nescape with {STRING 26}!\p$"

gText_CantEscape2:: @ 85C9D95
	.string "Can’t escape!\p$"

gText_PkmnCantEscape2:: @ 85C9DA4
	.string "{STRING 15} can’t escape!$"

gText_HitXTimes:: @ 85C9DB5
	.string "Hit {STRING 0} time(s)!$"

gText_PkmnFellAsleep:: @ 85C9DC5
	.string "{STRING 17}\nfell asleep!$"

gText_PkmnMadeSleep:: @ 85C9DD5
	.string "{STRING 19}’s {STRING 26}\nmade {STRING 17} sleep!$"

gText_PkmnAlreadyAsleep:: @ 85C9DEC
	.string "{STRING 16} is\nalready asleep!$"

gText_PkmnAlreadyAsleep2:: @ 85C9E02
	.string "{STRING 15} is\nalready asleep!$"

gText_PkmnWasntAffected:: @ 85C9E18
	.string "{STRING 16}\nwasn’t affected!$"

gText_PkmnWasPoisoned:: @ 85C9E2C
	.string "{STRING 17}\nwas poisoned!$"

gText_PkmnPoisonedBy:: @ 85C9E3D
	.string "{STRING 19}’s {STRING 26}\npoisoned {STRING 17}!$"

gText_PkmnHurtByPoison:: @ 85C9E52
	.string "{STRING 15} is hurt\nby poison!$"

gText_PkmnAlreadyPoisoned:: @ 85C9E68
	.string "{STRING 16} is already\npoisoned.$"

gText_PkmnBadlyPoisoned:: @ 85C9E80
	.string "{STRING 17} is badly\npoisoned!$"

gText_PkmnEnergyDrained:: @ 85C9E96
	.string "{STRING 16} had its\nenergy drained!$"

gText_PkmnWasBurned:: @ 85C9EB1
	.string "{STRING 17} was burned!$"

gText_PkmnBurnedBy:: @ 85C9EC0
	.string "{STRING 19}’s {STRING 26}\nburned {STRING 17}!$"

gText_PkmnHurtByBurn:: @ 85C9ED3
	.string "{STRING 15} is hurt\nby its burn!$"

gText_PkmnAlreadyHasBurn:: @ 85C9EEB
	.string "{STRING 16} already\nhas a burn.$"

gText_PkmnWasFrozen:: @ 85C9F02
	.string "{STRING 17} was\nfrozen solid!$"

gText_PkmnFrozenBy:: @ 85C9F17
	.string "{STRING 19}’s {STRING 26}\nfroze {STRING 17} solid!$"

gText_PkmnIsFrozen:: @ 85C9F2F
	.string "{STRING 15} is\nfrozen solid!$"

gText_PkmnWasDefrosted:: @ 85C9F43
	.string "{STRING 16} was\ndefrosted!$"

gText_PkmnWasDefrosted2:: @ 85C9F55
	.string "{STRING 15} was\ndefrosted!$"

gText_PkmnWasDefrostedBy:: @ 85C9F67
	.string "{STRING 15} was\ndefrosted by {STRING 20}!$"

gText_PkmnWasParalyzed:: @ 85C9F7F
	.string "{STRING 17} is paralyzed!\nIt may be unable to move!$"

gText_PkmnWasParalyzedBy:: @ 85C9FAA
	.string "{STRING 19}’s {STRING 26}\nparalyzed {STRING 17}!\lIt may be unable to move!$"

gText_PkmnIsParalyzed:: @ 85C9FDA
	.string "{STRING 15} is paralyzed!\nIt can’t move!$"

gText_PkmnIsAlreadyParalyzed:: @ 85C9FFA
	.string "{STRING 16} is\nalready paralyzed!$"

gText_PkmnHealedParalysis:: @ 85CA013
	.string "{STRING 16} was\nhealed of paralysis!$"

gText_PkmnDreamEaten:: @ 85CA02F
	.string "{STRING 16}’s\ndream was eaten!$"

gText_StatsWontIncrease:: @ 85CA045
	.string "{STRING 15}’s {STRING 0}\nwon’t go higher!$"

gText_StatsWontDecrease:: @ 85CA05E
	.string "{STRING 16}’s {STRING 0}\nwon’t go lower!$"

gText_TeamStoppedWorking:: @ 85CA076
	.string "Your team’s {STRING 0}\nstopped working!$"

gText_FoeStoppedWorking:: @ 85CA096
	.string "The foe’s {STRING 0}\nstopped working!$"

gText_PkmnIsConfused:: @ 85CA0B4
	.string "{STRING 15} is\nconfused!$"

gText_PkmnHealedConfusion:: @ 85CA0C4
	.string "{STRING 15} snapped\nout of confusion!$"

gText_PkmnWasConfused:: @ 85CA0E1
	.string "{STRING 17} became\nconfused!$"

gText_PkmnAlreadyConfused:: @ 85CA0F5
	.string "{STRING 16} is\nalready confused!$"

gText_PkmnFellInLove:: @ 85CA10D
	.string "{STRING 16}\nfell in love!$"

gText_PkmnInLove:: @ 85CA11E
	.string "{STRING 15} is in love\nwith {STRING 19}!$"

gText_PkmnImmobilizedByLove:: @ 85CA135
	.string "{STRING 15} is\nimmobilized by love!$"

gText_PkmnBlownAway:: @ 85CA150
	.string "{STRING 16} was\nblown away!$"

gText_PkmnChangedType:: @ 85CA163
	.string "{STRING 15} transformed\ninto the {STRING 0} type!$"

gText_PkmnFlinched:: @ 85CA184
	.string "{STRING 15} flinched!$"

gText_PkmnRegainedHealth:: @ 85CA191
	.string "{STRING 16} regained\nhealth!$"

gText_PkmnHPFull:: @ 85CA1A5
	.string "{STRING 16}’s\nHP is full!$"

gText_PkmnRaisedSpDef:: @ 85CA1B6
	.string "{STRING 42}’s {STRING 20}\nraised SP. DEF!$"

gText_PkmnRaisedSpDefALittle:: @ 85CA1CE
	.string "{STRING 42}’s {STRING 20}\nraised SP. DEF a little!$"

gText_PkmnRaisedDef:: @ 85CA1EF
	.string "{STRING 42}’s {STRING 20}\nraised DEFENSE!$"

gText_PkmnRaisedDefALittle:: @ 85CA207
	.string "{STRING 42}’s {STRING 20}\nraised DEFENSE a little!$"

gText_PkmnCoveredByVeil:: @ 85CA228
	.string "{STRING 42}’s party is covered\nby a veil!$"

gText_PkmnUsedSafeguard:: @ 85CA249
	.string "{STRING 16}’s party is protected\nby SAFEGUARD!$"

gText_PkmnSafeguardExpired:: @ 85CA26F
	.string "{STRING 44}’s party is no longer\nprotected by SAFEGUARD!$"

gText_PkmnWentToSleep:: @ 85CA29F
	.string "{STRING 15} went\nto sleep!$"

gText_PkmnSleptHealthy:: @ 85CA2B1
	.string "{STRING 15} slept and\nbecame healthy!$"

gText_PkmnWhippedWhirlwind:: @ 85CA2CE
	.string "{STRING 15} whipped\nup a whirlwind!$"

gText_PkmnTookSunlight:: @ 85CA2E9
	.string "{STRING 15} took\nin sunlight!$"

gText_PkmnLoweredHead:: @ 85CA2FE
	.string "{STRING 15} lowered\nits head!$"

gText_PkmnIsGlowing:: @ 85CA313
	.string "{STRING 15} is glowing!$"

gText_PkmnFlewHigh:: @ 85CA322
	.string "{STRING 15} flew\nup high!$"

gText_PkmnDugHole:: @ 85CA333
	.string "{STRING 15} dug a hole!$"

gText_PkmnHidUnderwater:: @ 85CA342
	.string "{STRING 15} hid\nunderwater!$"

gText_PkmnSprangUp:: @ 85CA355
	.string "{STRING 15} sprang up!$"

gText_PkmnSqueezedByBind:: @ 85CA363
	.string "{STRING 16} was squeezed by\n{STRING 15}’s BIND!$"

gText_PkmnTrappedInVortex:: @ 85CA381
	.string "{STRING 16} was trapped\nin the vortex!$"

gText_PkmnTrappedBySandTomb:: @ 85CA39F
	.string "{STRING 16} was trapped\nby SAND TOMB!$"

gText_PkmnWrappedBy:: @ 85CA3BC
	.string "{STRING 16} was WRAPPED by\n{STRING 15}!$"

gText_PkmnClamped:: @ 85CA3D2
	.string "{STRING 15} CLAMPED\n{STRING 16}!$"

gText_PkmnHurtBy:: @ 85CA3E1
	.string "{STRING 15} is hurt\nby {STRING 0}!$"

gText_PkmnFreedFrom:: @ 85CA3F3
	.string "{STRING 15} was freed\nfrom {STRING 0}!$"

gText_PkmnCrashed:: @ 85CA409
	.string "{STRING 15} kept going\nand crashed!$"

gText_PkmnShroudedInMist:: @ 85CA424
	.string "{STRING 42} became\nshrouded in MIST!$"

gText_PkmnProtectedByMist:: @ 85CA440
	.string "{STRING 19} is protected\nby MIST!$"

gText_PkmnGettingPumped:: @ 85CA459
	.string "{STRING 15} is getting\npumped!$"

gText_PkmnHitWithRecoil:: @ 85CA46F
	.string "{STRING 15} is hit\nwith recoil!$"

gText_PkmnProtectedItself2:: @ 85CA486
	.string "{STRING 15} protected\nitself!$"

gText_PkmnBuffetedBySandstorm:: @ 85CA49B
	.string "{STRING 15} is buffeted\nby the sandstorm!$"

gText_PkmnPeltedByHail:: @ 85CA4BC
	.string "{STRING 15} is pelted\nby HAIL!$"

gText_PkmnsXWoreOff:: @ 85CA4D2
	.string "{STRING 40}’s {STRING 0}\nwore off!$"

gText_PkmnSeeded:: @ 85CA4E4
	.string "{STRING 16} was seeded!$"

gText_PkmnEvadedAttack:: @ 85CA4F3
	.string "{STRING 16} evaded\nthe attack!$"

gText_PkmnSappedByLeechSeed:: @ 85CA509
	.string "{STRING 15}’s health is\nsapped by LEECH SEED!$"

gText_PkmnFastAsleep:: @ 85CA52E
	.string "{STRING 15} is fast\nasleep.$"

gText_PkmnWokeUp:: @ 85CA541
	.string "{STRING 15} woke up!$"

gText_PkmnUproarKeptAwake:: @ 85CA54D
	.string "But {STRING 19}’s UPROAR\nkept it awake!$"

gText_PkmnWokeUpInUproar:: @ 85CA56C
	.string "{STRING 15} woke up\nin the UPROAR!$"

gText_PkmnCausedUproar:: @ 85CA586
	.string "{STRING 15} caused\nan UPROAR!$"

gText_PkmnMakingUproar:: @ 85CA59B
	.string "{STRING 15} is making\nan UPROAR!$"

gText_PkmnCalmedDown:: @ 85CA5B3
	.string "{STRING 15} calmed down.$"

gText_PkmnCantSleepInUproar:: @ 85CA5C3
	.string "But {STRING 16} can’t\nsleep in an UPROAR!$"

gText_PkmnStockpiled:: @ 85CA5E4
	.string "{STRING 15} STOCKPILED\n{STRING 0}!$"

gText_PkmnCantStockpile:: @ 85CA5F6
	.string "{STRING 15} can’t\nSTOCKPILE any more!$"

gText_PkmnCantSleepInUproar2:: @ 85CA613
	.string "But {STRING 16} can’t\nsleep in an UPROAR!$"

gText_UproarKeptPkmnAwake:: @ 85CA634
	.string "But the UPROAR kept\n{STRING 16} awake!$"

gText_PkmnStayedAwakeUsing:: @ 85CA652
	.string "{STRING 16} stayed awake\nusing its {STRING 25}!$"

gText_PkmnStoringEnergy:: @ 85CA670
	.string "{STRING 15} is storing\nenergy!$"

gText_PkmnUnleashedEnergy:: @ 85CA686
	.string "{STRING 15} unleashed\nenergy!$"

gText_PkmnFatigueConfusion:: @ 85CA69B
	.string "{STRING 15} became\nconfused due to fatigue!$"

gText_PkmnPickedUpItem:: @ 85CA6BE
	.string "{STRING 35} picked up\n¥{STRING 0}!\p$"

gText_PkmnUnaffected:: @ 85CA6D1
	.string "{STRING 16} is\nunaffected!$"

gText_PkmnTransformedInto:: @ 85CA6E3
	.string "{STRING 15} transformed\ninto {STRING 0}!$"

gText_PkmnMadeSubstitute:: @ 85CA6FB
	.string "{STRING 15} made\na SUBSTITUTE!$"

gText_PkmnHasSubstitute:: @ 85CA711
	.string "{STRING 15} already\nhas a SUBSTITUTE!$"

gText_SubstituteDamaged:: @ 85CA72E
	.string "The SUBSTITUTE took damage\nfor {STRING 16}!\p$"

gText_PkmnSubstituteFaded:: @ 85CA752
	.string "{STRING 16}’s\nSUBSTITUTE faded!\p$"

gText_PkmnMustRecharge:: @ 85CA76A
	.string "{STRING 15} must\nrecharge!$"

gText_PkmnRageBuilding:: @ 85CA76C
	.string "{STRING 16}’s RAGE\nis building!$"

gText_PkmnMoveWasDisabled:: @ 85CA793
	.string "{STRING 16}’s {STRING 0}\nwas disabled!$"

gText_PkmnMoveDisabledNoMore:: @ 85CA7A9
	.string "{STRING 15} is disabled\nno more!$"

gText_PkmnGotEncore:: @ 85CA7C1
	.string "{STRING 16} got\nan ENCORE!$"

gText_PkmnEncoreEnded:: @ 85CA7D3
	.string "{STRING 15}’s ENCORE\nended!$"

gText_PkmnTookAim:: @ 85CA7E6
	.string "{STRING 15} took aim\nat {STRING 16}!$"

gText_PkmnSketchedMove:: @ 85CA7F9
	.string "{STRING 15} SKETCHED\n{STRING 0}!$"

gText_PkmnTryingToTakeFoe:: @ 85CA809
	.string "{STRING 15} is trying\nto take its foe with it!$"

gText_PkmnTookFoe:: @ 85CA82F
	.string "{STRING 16} took\n{STRING 15} with it!$"

gText_PkmnReducedPP:: @ 85CA843
	.string "Reduced {STRING 16}’s\n{STRING 0} by {PLAYER}!$"

gText_PkmnStoleItem:: @ 85CA85A
	.string "{STRING 15} stole\n{STRING 16}’s {STRING 22}!$"

gText_PkmnCantEscape:: @ 85CA86C
	.string "{STRING 16} can’t\nescape now!$"

gText_PkmnFellIntoNightmare:: @ 85CA881
	.string "{STRING 16} fell into\na NIGHTMARE!$"

gText_PkmnLockedInNightmare:: @ 85CA89B
	.string "{STRING 15} is locked\nin a NIGHTMARE!$"

gText_PkmnLaidCurse:: @ 85CA8B8
	.string "{STRING 15} cut its own HP and\nlaid a CURSE on {STRING 16}!$"

gText_PkmnAfflictedByCurse:: @ 85CA8E2
	.string "{STRING 15} is afflicted\nby the CURSE!$"

gText_SpikesScattered:: @ 85CA900
	.string "SPIKES were scattered all around\nthe opponent’s side!$"

gText_PkmnHurtBySpikes:: @ 85CA936
	.string "{STRING 19} is hurt\nby SPIKES!$"

gText_PkmnIdentified:: @ 85CA94C
	.string "{STRING 15} identified\n{STRING 16}!$"

gText_PkmnPerishCountFell:: @ 85CA95E
	.string "{STRING 15}’s PERISH count\nfell to {STRING 0}!$"

gText_PkmnBracedItself:: @ 85CA97C
	.string "{STRING 15} braced\nitself!$"

gText_PkmnEnduredHit:: @ 85CA98E
	.string "{STRING 16} ENDURED\nthe hit!$"

gText_MagnitudeStrength:: @ 85CA9A2
	.string "MAGNITUDE {STRING 0}!$"

gText_PkmnCutHPMaxedAttack:: @ 85CA9B0
	.string "{STRING 15} cut its own HP\nand maximized ATTACK!$"

gText_PkmnCopiedStatChanges:: @ 85CA9D8
	.string "{STRING 15} copied\n{STRING 16}’s stat changes!$"

gText_PkmnGotFree:: @ 85CA9F5
	.string "{STRING 15} got free of\n{STRING 16}’s {STRING 0}!$"

gText_PkmnShedLeechSeed:: @ 85CAA0D
	.string "{STRING 15} shed\nLEECH SEED!$"

gText_PkmnBlewAwaySpikes:: @ 85CAA21
	.string "{STRING 15} blew away\nSPIKES!$"

gText_PkmnFledFromBattle:: @ 85CAA36
	.string "{STRING 15} fled from\nbattle!$"

gText_PkmnForesawAttack:: @ 85CAA4B
	.string "{STRING 15} foresaw\nan attack!$"

gText_PkmnTookAttack:: @ 85CAA61
	.string "{STRING 16} took the\n{STRING 0} attack!$"

gText_PkmnChoseXAsDestiny:: @ 85CAA78
	.string "{STRING 15} chose\n{STRING 20} as its destiny!$"

gText_PkmnAttack:: @ 85CAA94
	.string "{STRING 0}’s attack!$"

gText_PkmnCenterAttention:: @ 85CAAA1
	.string "{STRING 15} became the\ncenter of attention!$"

gText_PkmnChargingPower:: @ 85CAAC4
	.string "{STRING 15} began\ncharging power!$"

gText_NaturePowerTurnedInto:: @ 85CAADD
	.string "NATURE POWER turned into\n{STRING 20}!$"

gText_PkmnStatusNormal:: @ 85CAAFA
	.string "{STRING 15}’s status\nreturned to normal!$"

gText_PkmnSubjectedToTorment:: @ 85CAB1A
	.string "{STRING 16} was subjected\nto TORMENT!$"

gText_PkmnTighteningFocus:: @ 85CAB37
	.string "{STRING 15} is tightening\nits focus!$"

gText_PkmnFellForTaunt:: @ 85CAB53
	.string "{STRING 16} fell for\nthe TAUNT!$"

gText_PkmnReadyToHelp:: @ 85CAB6A
	.string "{STRING 15} is ready to\nhelp {STRING 16}!$"

gText_PkmnSwitchedItems:: @ 85CAB82
	.string "{STRING 15} switched\nitems with its opponent!$"

gText_PkmnObtainedX:: @ 85CABA7
	.string "{STRING 15} obtained\n{STRING 0}.$"

gText_PkmnObtainedX2:: @ 85CABB7
	.string "{STRING 16} obtained\n{PLAYER}.$"

gText_PkmnObtainedXYObtainedZ:: @ 85CABC7
	.string "{STRING 15} obtained\n{STRING 0}.\p{STRING 16} obtained\n{PLAYER}.$"

gText_PkmnCopiedFoe:: @ 85CAB82
	.string "{STRING 15} copied\n{STRING 16}’s {STRING 25}!$"

gText_PkmnMadeWish:: @ 85CABFA
	.string "{STRING 15} made a WISH!$"

gText_PkmnWishCameTrue:: @ 85CAC0A
	.string "{STRING 0}’s WISH\ncame true!$"

gText_PkmnPlantedRoots:: @ 85CAC1F
	.string "{STRING 15} planted its roots!$"

gText_PkmnAbsorbedNutrients:: @ 85CAC35
	.string "{STRING 15} absorbed\nnutrients with its roots!$"

gText_PkmnAnchoredItself:: @ 85CAC5B
	.string "{STRING 16} anchored\nitself with its roots!$"

gText_PkmnWasMadeDrowsy:: @ 85CAC7E
	.string "{STRING 15} made\n{STRING 16} drowsy!$"

gText_PkmnKnockedOff:: @ 85CAC91
	.string "{STRING 15} knocked off\n{STRING 16}’s {STRING 22}!$"

gText_PkmnSwappedAbilities:: @ 85CACA9
	.string "{STRING 15} swapped abilities\nwith its opponent!$"

gText_PkmnSealedOpponentMove:: @ 85CACD1
	.string "{STRING 15} sealed the\nopponent’s move(s)!$"

gText_PkmnWantsGrudge:: @ 85CACF3
	.string "{STRING 15} wants the\nopponent to bear a GRUDGE!$"

gText_PkmnLostPPGrudge:: @ 85CAD1B
	.string "{STRING 15}’s {STRING 0} lost\nall its PP due to the GRUDGE!$"

gText_PkmnShroudedItself:: @ 85CAD46
	.string "{STRING 15} shrouded\nitself in {STRING 20}!$"

gText_PkmnMoveBounced:: @ 85CAD60
	.string "{STRING 15}’s {STRING 20}\nwas bounced back by MAGIC COAT!$"

gText_PkmnWaitsForTarget:: @ 85CAD88
	.string "{STRING 15} waits for a target\nto make a move!$"

gText_PkmnSnatchedMove:: @ 85CADAE
	.string "{STRING 16} SNATCHED\n{STRING 19}’s move!$"

gText_ElectricityWeakened:: @ 85CADC5
	.string "Electricity’s power was\nweakened!$"

gText_FireWeakened:: @ 85CADE7
	.string "Fire’s power was\nweakened!$"

gText_XFoundOneY:: @ 85CAE02
	.string "{STRING 15} found\none {STRING 22}!$"

gText_SoothingAroma:: @ 85CAE13
	.string "A soothing aroma wafted\nthrough the area!$"

gText_ItemsCantBeUsedNow:: @ 85CAE3D
	.string "Items can’t be used now.{PAUSE 64}$"

gText_ForXCommaYZ:: @ 85CAE59
	.string "For {STRING 19},\n{STRING 22} {STRING 0}$"

gText_PkmnUsedXToGetPumped:: @ 85CAE67
	.string "{STRING 19} used\n{STRING 22} to get pumped!$"

gText_PkmnLostFocus:: @ 85CAE81
	.string "{STRING 15} lost its\nfocus and couldn’t move!$"

gText_PkmnWasDraggedOut:: @ 85CAEA6
	.string "{STRING 16} was\ndragged out!\p$"

gText_TheWallShattered:: @ 85CAEBB
	.string "The wall shattered!$"

gText_ButNoEffect:: @ 85CAECF
	.string "But it had no effect!$"

gText_PkmnHasNoMovesLeft:: @ 85CAEE5
	.string "{STRING 18} has no\nmoves left!\p$"

gText_PkmnMoveIsDisabled:: @ 85CAEFC
	.string "{STRING 18}’s {STRING 20}\nis disabled!\p$"

gText_PkmnCantUseMoveTorment:: @ 85CAF12
	.string "{STRING 18} can’t use the same\nmove in a row due to the TORMENT!\p$"

gText_PkmnCantUseMoveTaunt:: @ 85CAF4B
	.string "{STRING 18} can’t use\n{STRING 20} after the TAUNT!\p$"

gText_PkmnCantUseMoveSealed:: @ 85CAF6D
	.string "{STRING 18} can’t use the\nsealed {STRING 20}!\p$"

gText_PkmnMadeItRain:: @ 85CAF8A
	.string "{STRING 19}’s {STRING 26}\nmade it rain!$"

gText_PkmnRaisedSpeed:: @ 85CAFA0
	.string "{STRING 19}’s {STRING 26}\nraised its SPEED!$"

gText_PkmnProtectedBy:: @ 85CAFBA
	.string "{STRING 16} was protected\nby {STRING 25}!$"

gText_PkmnPreventsUsage:: @ 85CAFD2
	.string "{STRING 16}’s {STRING 25}\nprevents {STRING 15}\lfrom using {STRING 20}!$"

gText_PkmnRestoredHPUsing:: @ 85CAFF5
	.string "{STRING 16} restored HP\nusing its {STRING 25}!$"

gText_PkmnsXMadeYUseless:: @ 85CB012
	.string "{STRING 16}’s {STRING 25}\nmade {STRING 20} useless!$"

gText_PkmnChangedTypeWith:: @ 85CB02B
	.string "{STRING 16}’s {STRING 25}\nmade it the {STRING 0} type!$"

gText_PkmnPreventsParalysisWith:: @ 85CB048
	.string "{STRING 17}’s {STRING 25}\nprevents paralysis!$"

gText_PkmnPreventsRomanceWith:: @ 85CB064
	.string "{STRING 16}’s {STRING 25}\nprevents romance!$"

gText_PkmnPreventsPoisoningWith:: @ 85CB07E
	.string "{STRING 17}’s {STRING 25}\nprevents poisoning!$"

gText_PkmnPreventsConfusionWith:: @ 85CB09A
	.string "{STRING 16}’s {STRING 25}\nprevents confusion!$"

gText_PkmnRaisedFirePowerWith:: @ 85CB0B6
	.string "{STRING 16}’s {STRING 25}\nraised its FIRE power!$"

gText_PkmnAnchorsItselfWith:: @ 85CB0D5
	.string "{STRING 16} anchors\nitself with {STRING 25}!$"

gText_PkmnCutsAttackWith:: @ 85CB0F0
	.string "{STRING 19}’s {STRING 26}\ncuts {STRING 16}’s ATTACK!$"

gText_PkmnPreventsStatLossWith:: @ 85CB10A
	.string "{STRING 19}’s {STRING 26}\nprevents stat loss!$"

gText_PkmnHurtsWith:: @ 85CB126
	.string "{STRING 16}’s {STRING 25}\nhurt {STRING 15}!$"

gText_PkmnTraced:: @ 85CB137
	.string "{STRING 19} TRACED\n{STRING 0}’s {PLAYER}!$"

gText_PkmnsXPreventsBurns:: @ 85CB14A
	.string "{STRING 17}’s {STRING 27}\nprevents burns!$"

gText_PkmnsXBlocksY:: @ 85CB162
	.string "{STRING 16}’s {STRING 25}\nblocks {STRING 20}!$"

gText_PkmnsXBlocksY2:: @ 85CB175
	.string "{STRING 19}’s {STRING 26}\nblocks {STRING 20}!$"

gText_PkmnsXRestoredHPALittle2:: @ 85CB188
	.string "{STRING 15}’s {STRING 24}\nrestored its HP a little!$"

gText_PkmnsXWhippedUpSandstorm:: @ 85CB1AA
	.string "{STRING 19}’s {STRING 26}\nwhipped up a sandstorm!$"

gText_PkmnsXIntensifiedSun:: @ 85CB1CA
	.string "{STRING 19}’s {STRING 26}\nintensified the sun’s rays!$"

gText_PkmnsXPreventsYLoss:: @ 85CB1EE
	.string "{STRING 19}’s {STRING 26}\nprevents {STRING 0} loss!$"

gText_PkmnsXInfatuatedY:: @ 85CB208
	.string "{STRING 16}’s {STRING 25}\ninfatuated {STRING 15}!$"

gText_PkmnsXMadeYIneffective:: @ 85CB21F
	.string "{STRING 16}’s {STRING 25}\nmade {STRING 20} ineffective!$"

gText_PkmnsXCuredYProblem:: @ 85CB23C
	.string "{STRING 19}’s {STRING 26}\ncured its {STRING 0} problem!$"

gText_ItSuckedLiquidOoze:: @ 85CB25A
	.string "It sucked up the\nLIQUID OOZE!$"

gText_PkmnTransformed:: @ 85CB278
	.string "{STRING 19} transformed!$"

gText_PkmnsXTookAttack:: @ 85CB288
	.string "{STRING 16}’s {STRING 25}\ntook the attack!$"

gText_PkmnsXPreventsSwitching:: @ 85CB2A1
	.string "{STRING 0}’s {STRING 23}\nprevents switching!\p$"

gText_PreventedFromWorking:: @ 85CB2BE
	.string "{STRING 16}’s {STRING 25}\nprevented {STRING 19}’s\l{STRING 0} from working!$"

gText_PkmnsXMadeItIneffective:: @ 85CB2E6
	.string "{STRING 19}’s {STRING 26}\nmade it ineffective!$"

gText_PkmnsXPreventsFlinching:: @ 85CB303
	.string "{STRING 17}’s {STRING 27}\nprevents flinching!$"

gText_PkmnsXPreventsYsZ:: @ 85CB31F
	.string "{STRING 15}’s {STRING 24}\nprevents {STRING 16}’s\l{STRING 25} from working!$"

gText_PkmnsXCuredItsYProblem:: @ 85CB346
	.string "{STRING 19}’s {STRING 26}\ncured its {STRING 0} problem!$"

gText_PkmnsXHadNoEffectOnY:: @ 85CB364
	.string "{STRING 19}’s {STRING 26}\nhad no effect on {STRING 17}!$"

gText_StatSharply:: @ 85CB381
	.string "sharply $"

gText_StatRose:: @ 85CB38A
	.string "rose!$"

gText_StatHarshly:: @ 85CB390
	.string "harshly $"

gText_StatFell:: @ 85CB399
	.string "fell!$"

gText_PkmnsStatChanged:: @ 85CB39F
	.string "{STRING 15}’s {STRING 0}\n{PLAYER}$"

gText_PkmnsStatChanged2:: @ 85CB3AA
	.string "{STRING 16}’s {STRING 0}\n{PLAYER}$"

gText_UsingXTheYOfZN:: @ 85CB3B5
	.string "Using {STRING 22}, the {STRING 0}\nof {STRING 19} {PLAYER}$"

gText_PkmnsStatChanged3:: @ 85CB3CF
	.string "{STRING 15}’s {STRING 0}\n{PLAYER}$"

gText_PkmnsStatChanged4:: @ 85CB3DA
	.string "{STRING 16}’s {STRING 0}\n{PLAYER}$"

gText_StatsWontIncrease2:: @ 85CB3E5
	.string "{STRING 15}’s stats won’t\ngo any higher!$"

gText_StatsWontDecrease2:: @ 85CB405
	.string "{STRING 16}’s stats won’t\ngo any lower!$"

gText_CriticalHit:: @ 85CB424
	.string "A critical hit!$"

gText_OneHitKO:: @ 85CB434
	.string "It’s a one-hit KO!$"

gText_123Poof:: @ 85CB447
	.string "{PAUSE 32}1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p$"

gText_AndEllipsis:: @ 85CB473
	.string "And…\p$"

gText_HMMovesCantBeForgotten:: @ 85CB479
	.string "HM moves can’t be\nforgotten now.\p$"

gText_NotVeryEffective:: @ 85CB49B
	.string "It’s not very effective…$"

gText_SuperEffective:: @ 85CB4B4
	.string "It’s super effective!$"

gText_GotAwaySafely:: @ 85CB4CA
	.string "{PLAY_SE 0x0011}Got away safely!\p$"

gText_PkmnFledUsingIts:: @ 85CB4E0
	.string "{PLAY_SE 0x0011}{STRING 15} fled\nusing its {STRING 22}!\p$"

gText_PkmnFledUsing:: @ 85CB4FB
	.string "{PLAY_SE 0x0011}{STRING 15} fled\nusing {STRING 24}!\p$"

gText_WildPkmnFled:: @ 85CB512
	.string "{PLAY_SE 0x0011}Wild {STRING 0} fled!$"

gUnknown_085CB524:: @ 85CB524
	.string "Player defeated\n{STRING 32}!$"

gUnknown_085CB538:: @ 85CB538
	.string "Player beat {STRING 32}\nand {STRING 33}!$"

gUnknown_085CB54F:: @ 85CB54F
	.string "Player lost against\n{STRING 32}!$"

gUnknown_085CB567:: @ 85CB567
	.string "Player lost to {STRING 32}\nand {STRING 33}!$"

gUnknown_085CB581:: @ 85CB581
	.string "Player battled to a draw against\n{STRING 32}!$"

gUnknown_085CB5A6:: @ 85CB5A6
	.string "Player battled to a draw against\n{STRING 32} and {STRING 33}!$"

gUnknown_085CB5D2:: @ 85CB5D2
	.string "{PLAY_SE 0x0011}{STRING 32} fled!$"

gUnknown_085CB5DF:: @ 85CB5DF
	.string "{PLAY_SE 0x0011}{STRING 32} and\n{STRING 33} fled!$"

gText_NoRunningFromTrainers:: @ 85CB5F3
	.string "No! There’s no running\nfrom a TRAINER battle!\p$"

gText_CantEscape:: @ 85CB622
	.string "Can’t escape!\p$"

gText_DontLeaveBirch:: @ 85CB631
	.string "PROF. BIRCH: Don’t leave me like this!\p$"

gText_ButNothingHappened:: @ 85CB659
	.string "But nothing happened!$"

gText_ButItFailed:: @ 85CB66F
	.string "But it failed!$"

gText_ItHurtConfusion:: @ 85CB67E
	.string "It hurt itself in its\nconfusion!$"

gText_MirrorMoveFailed:: @ 85CB69F
	.string "The MIRROR MOVE failed!$"

gText_StartedToRain:: @ 85CB6B7
	.string "It started to rain!$"

gText_DownpourStarted:: @ 85CB6CB
	.string "A downpour started!$"

gText_RainContinues:: @ 85CB6DF
	.string "Rain continues to fall.$"

gText_DownpourContinues:: @ 85CB6F7
	.string "The downpour continues.$"

gText_RainStopped:: @ 85CB70F
	.string "The rain stopped.$"

gText_SandstormBrewed:: @ 85CB721
	.string "A sandstorm brewed!$"

gText_SandstormRages:: @ 85CB735
	.string "The sandstorm rages.$"

gText_SandstormSubsided:: @ 85CB74A
	.string "The sandstorm subsided.$"

gText_SunlightGotBright:: @ 85CB762
	.string "The sunlight got bright!$"

gText_SunlightStrong:: @ 85CB77B
	.string "The sunlight is strong.$"

gText_SunlightFaded:: @ 85CB793
	.string "The sunlight faded.$"

gText_StartedHail:: @ 85CB7A7
	.string "It started to hail!$"

gText_HailContinues:: @ 85CB7BB
	.string "Hail continues to fall.$"

gText_HailStopped:: @ 85CB7D3
	.string "The hail stopped.$"

gText_FailedToSpitUp:: @ 85CB7E5
	.string "But it failed to SPIT UP\na thing!$"

gText_FailedToSwallow:: @ 85CB807
	.string "But it failed to SWALLOW\na thing!$"

gText_WindBecameHeatWave:: @ 85CB829
	.string "The wind turned into a\nHEAT WAVE!$"

gText_StatChangesGone:: @ 85CB84B
	.string "All stat changes were\neliminated!$"

gText_CoinsScattered:: @ 85CB86D
	.string "Coins scattered everywhere!$"

gText_TooWeakForSubstitute:: @ 85CB889
	.string "It was too weak to make\na SUBSTITUTE!$"

gText_SharedPain:: @ 85CB8AF
	.string "The battlers shared\ntheir pain!$"

gText_BellChimed:: @ 85CB8CF
	.string "A bell chimed!$"

gText_FaintInThree:: @ 85CB8DE
	.string "All affected POKéMON will\nfaint in three turns!$"

gText_NoPPLeft:: @ 85CB90E
	.string "There’s no PP left for\nthis move!\p$"

gText_ButNoPPLeft:: @ 85CB931
	.string "But there was no PP left\nfor the move!$"

gText_PkmnIgnoresAsleep:: @ 85CB958
	.string "{STRING 15} ignored\norders while asleep!$"

gText_PkmnIgnoredOrders:: @ 85CB978
	.string "{STRING 15} ignored\norders!$"

gText_PkmnBeganToNap:: @ 85CB98B
	.string "{STRING 15} began to nap!$"

gText_PkmnLoafing:: @ 85CB99C
	.string "{STRING 15} is\nloafing around!$"

gText_PkmnWontObey:: @ 85CB9B2
	.string "{STRING 15} won’t\nobey!$"

gText_PkmnTurnedAway:: @ 85CB9C1
	.string "{STRING 15} turned away!$"

gText_PkmnPretendNotNotice:: @ 85CB9D1
	.string "{STRING 15} pretended\nnot to notice!$"

gText_EnemyAboutToSwitchPkmn:: @ 85CB9ED
	.string "{STRING 28} {STRING 29} is\nabout to use {PLAYER}.\pWill {STRING 35} change\nPOKéMON?$"

gText_PkmnLearnedMove2:: @ 85CBA1F
	.string "{STRING 15} learned\n{STRING 0}!$"

gText_PlayerDefeatedXY:: @ 85CBA2E
	.string "Player defeated\n{STRING 28} {STRING 29}!\p$"

gText_CreptCloser:: @ 85CBA46
	.string "{STRING 35} crept closer to\n{RIVAL}!$"

gText_CantGetCloser:: @ 85CBA5D
	.string "{STRING 35} can’t get any closer!$"

gText_PkmnWatchingCarefully:: @ 85CBA76
	.string "{RIVAL} is watching\ncarefully!$"

gText_PkmnCuriousAboutX:: @ 85CBA90
	.string "{RIVAL} is curious about\nthe {STRING 0}!$"

gText_PkmnEnthralledByX:: @ 85CBAAC
	.string "{RIVAL} is enthralled by\nthe {STRING 0}!$"

gText_PkmnIgnoredX:: @ 85CBAC8
	.string "{RIVAL} completely ignored\nthe {STRING 0}!$"

gText_ThrewPokeblockAtPkmn:: @ 85CBAE6
	.string "{STRING 35} threw a {POKEBLOCK}\nat the {RIVAL}!$"

gText_OutOfSafariBalls:: @ 85CBB02
	.string "{PLAY_SE 0x0049}ANNOUNCER: You’re out of\nSAFARI BALLS! Game over!\p$"

	.string "{RIVAL} appeared!\p$"

gUnknown_085CBB47:: @ 85CBB47
	.string "Wild {RIVAL} appeared!\p$"

gUnknown_085CBB5A:: @ 85CBB5A
	.string "Wild {RIVAL} appeared!\p$"

gUnknown_085CBB6D:: @ 85CBB6D
	.string "Wild {RIVAL} appeared!{PAUSE 127}$"

gUnknown_085CBB82:: @ 85CBB82
	.string "Wild {RIVAL} and\n{AQUA} appeared!\p$"

gUnknown_085CBB9C:: @ 85CBB9C
	.string "{STRING 28} {STRING 29}\nwould like to battle!\p$"

gUnknown_085CBBB9:: @ 85CBBB9
	.string "{STRING 32}\nwants to battle!$"

gUnknown_085CBBCD:: @ 85CBBCD
	.string "{STRING 32} and {STRING 33}\nwant to battle!$"

gUnknown_085CBBE7:: @ 85CBBE7
	.string "{STRING 28} {STRING 29} sent\nout {RIVAL}!$"

gUnknown_085CBBFA:: @ 85CBBFA
	.string "{STRING 28} {STRING 29} sent\nout {RIVAL} and {AQUA}!$"

gUnknown_085CBC14:: @ 85CBC14
	.string "{STRING 28} {STRING 29} sent\nout {STRING 0}!$"

gUnknown_085CBC27:: @ 85CBC27
	.string "{STRING 32} sent out\n{RIVAL}!$"

gUnknown_085CBC37:: @ 85CBC37
	.string "{STRING 32} sent out\n{RIVAL} and {AQUA}!$"

gUnknown_085CBC4E:: @ 85CBC4E
	.string "{STRING 32} sent out {STRING 10}!\n{STRING 33} sent out {STRING 12}!$"

gUnknown_085CBC6E:: @ 85CBC6E
	.string "{STRING 32} sent out\n{STRING 0}!$"

gUnknown_085CBC7E:: @ 85CBC7E
	.string "{STRING 34} sent out\n{STRING 0}!$"

gUnknown_085CBC8E:: @ 85CBC8E
	.string "Go! {STRING 5}!$"

gUnknown_085CBC96:: @ 85CBC96
	.string "Go! {STRING 5} and\n{VERSION}!$"

gUnknown_085CBCA5:: @ 85CBCA5
	.string "Go! {STRING 0}!$"

gUnknown_085CBCAD:: @ 85CBCAD
	.string "Do it! {STRING 0}!$"

gUnknown_085CBCB8:: @ 85CBCB8
	.string "Go for it, {STRING 0}!$"

gUnknown_085CBCC7:: @ 85CBCC7
	.string "Your foe’s weak!\nGet ’em, {STRING 0}!$"

gUnknown_085CBCE5:: @ 85CBCE5
	.string "{STRING 31} sent out {STRING 11}!\nGo! {STRING 9}!$"

gUnknown_085CBCFD:: @ 85CBCFD
	.string "{STRING 0}, that’s enough!\nCome back!$"

gUnknown_085CBD1B:: @ 85CBD1B
	.string "{STRING 0}, come back!$"

gUnknown_085CBD2A:: @ 85CBD2A
	.string "{STRING 0}, OK!\nCome back!$"

gUnknown_085CBD3D:: @ 85CBD3D
	.string "{STRING 0}, good!\nCome back!$"

gUnknown_085CBD52:: @ 85CBD52
	.string "{STRING 28} {STRING 29}\nwithdrew {STRING 0}!$"

gUnknown_085CBD65:: @ 85CBD65
	.string "{STRING 32} withdrew\n{STRING 0}!$"

gUnknown_085CBD75:: @ 85CBD75
	.string "{STRING 34} withdrew\n{STRING 0}!$"

gUnknown_085CBD85:: @ 85CBD85
	.string "Wild $"

gUnknown_085CBD8B:: @ 85CBD8B
	.string "Foe $"

	.string "$"

gUnknown_085CBD91:: @ 85CBD91
	.string "Foe$"

gUnknown_085CBD95:: @ 85CBD95
	.string "Ally$"

gUnknown_085CBD9A:: @ 85CBD9A
	.string "Foe$"

gUnknown_085CBD9E:: @ 85CBD9E
	.string "Ally$"

gUnknown_085CBDA3:: @ 85CBDA3
	.string "Foe$"

gUnknown_085CBDA7:: @ 85CBDA7
	.string "Ally$"

gUnknown_085CBDAC:: @ 85CBDAC
	.string "{STRING 15} used\n{PLAYER}$"

gUnknown_085CBDB7:: @ 85CBDB7
	.string "!$"

gUnknown_085CBDB9:: @ 85CBDB9
	.string "!$"

gUnknown_085CBDBB:: @ 85CBDBB
	.string "!$"

gUnknown_085CBDBD:: @ 85CBDBD
	.string "!$"

gUnknown_085CBDBF:: @ 85CBDBF
	.string "!$"

gUnknown_085CBDC1:: @ 85CBDC1
	.string "HP$"

gUnknown_085CBDC4:: @ 85CBDC4
	.string "ATTACK$"

gUnknown_085CBDCB:: @ 85CBDCB
	.string "DEFENSE$"

gUnknown_085CBDD3:: @ 85CBDD3
	.string "SPEED$"

gUnknown_085CBDD9:: @ 85CBDD9
	.string "SP. ATK$"

gUnknown_085CBDE1:: @ 85CBDE1
	.string "SP. DEF$"

gUnknown_085CBDE9:: @ 85CBDE9
	.string "accuracy$"

gUnknown_085CBDF2:: @ 85CBDF2
	.string "evasiveness$"

	.align 2
gStatNamesTable:: @ 85CBE00
	.4byte gUnknown_085CBDC1
	.4byte gUnknown_085CBDC4
	.4byte gUnknown_085CBDCB
	.4byte gUnknown_085CBDD3
	.4byte gUnknown_085CBDD9
	.4byte gUnknown_085CBDE1
	.4byte gUnknown_085CBDE9
	.4byte gUnknown_085CBDF2

gUnknown_085CBE20:: @ 85CBE20
	.string "was too spicy!$"

gUnknown_085CBE2F:: @ 85CBE2F
	.string "was too dry!$"

gUnknown_085CBE3C:: @ 85CBE3C
	.string "was too sweet!$"

gUnknown_085CBE4B:: @ 85CBE4B
	.string "was too bitter!$"

gUnknown_085CBE5B:: @ 85CBE5B
	.string "was too sour!$"

	.align 2
gUnknown_085CBE6C:: @ 85CBE6C
	.4byte gUnknown_085CBE20
	.4byte gUnknown_085CBE2F
	.4byte gUnknown_085CBE3C
	.4byte gUnknown_085CBE4B
	.4byte gUnknown_085CBE5B

gText_XUsedY:: @ 85CBE80
	.string "{STRING 35} used\n{STRING 22}!$"

gText_WallyUsedY:: @ 85CBE8C
	.string "WALLY used\n{STRING 22}!$"

gText_XYUsedZ:: @ 85CBE9B
	.string "{STRING 28} {STRING 29}\nused {STRING 22}!$"

gText_TrainerBlockedBall:: @ 85CBEAA
	.string "The TRAINER blocked the BALL!$"

gText_DontBeAThief:: @ 85CBEC8
	.string "Don’t be a thief!$"

gText_ItDodgedBall:: @ 85CBEDA
	.string "It dodged the thrown BALL!\nThis POKéMON can’t be caught!$"

gText_YouMissedPkmn:: @ 85CBF13
	.string "You missed the POKéMON!$"

gText_PkmnBrokeFree:: @ 85CBF2B
	.string "Oh, no!\nThe POKéMON broke free!$"

gText_ItAppearedCaught:: @ 85CBF4B
	.string "Aww!\nIt appeared to be caught!$"

gText_AarghAlmostHadIt:: @ 85CBF6A
	.string "Aargh!\nAlmost had it!$"

gText_ShootSoClose:: @ 85CBF80
	.string "Shoot!\nIt was so close, too!$"

gText_GotchaPkmnCaught:: @ 85CBF9D
	.string "Gotcha!\n{RIVAL} was caught!{UNKNOWN_A}{PLAY_BGM BGM_KACHI22}\p$"

gText_GotchaPkmnCaught2:: @ 85CBFBB
	.string "Gotcha!\n{RIVAL} was caught!{UNKNOWN_A}{PLAY_BGM BGM_KACHI22}{PAUSE 127}$"

gText_GiveNicknameCaptured:: @ 85CBFDB
	.string "Give a nickname to the\ncaptured {RIVAL}?$"

gText_PkmnSentToPC:: @ 85CBFFF
	.string "{RIVAL} was sent to\n{STRING 39} PC.$"

gUnknown_085CC015:: @ 85CC015
	.string "someone’s$"

gUnknown_085CC01F:: @ 85CC01F
	.string "LANETTE’s$"

gText_PkmnDataAddedToDex:: @ 85CC029
	.string "{RIVAL}’s data was\nadded to the POKéDEX.\p$"

gText_ItIsRaining:: @ 85CC04E
	.string "It is raining.$"

gText_SandstormIsRaging:: @ 85CC05D
	.string "A sandstorm is raging.$"

gText_BoxIsFull:: @ 85CC074
	.string "The BOX is full!\nYou can’t catch any more!\p$"

gUnknown_085CC0A0:: @ 85CC0A0
	.string "ENIGMA BERRY$"

gUnknown_085CC0AD:: @ 85CC0AD
	.string " BERRY$"

gText_PkmnsXCuredParalysis:: @ 85CC0B4
	.string "{STRING 19}’s {STRING 22}\ncured paralysis!$"

gText_PkmnsXCuredPoison:: @ 85CC0CD
	.string "{STRING 19}’s {STRING 22}\ncured poison!$"

gText_PkmnsXHealedBurn:: @ 85CC0E3
	.string "{STRING 19}’s {STRING 22}\nhealed its burn!$"

gText_PkmnsXDefrostedIt:: @ 85CC0FC
	.string "{STRING 19}’s {STRING 22}\ndefrosted it!$"

gText_PkmnsXWokeIt:: @ 85CC112
	.string "{STRING 19}’s {STRING 22}\nwoke it from its sleep!$"

gText_PkmnsXSnappedOut:: @ 85CC132
	.string "{STRING 19}’s {STRING 22}\nsnapped it out of confusion!$"

gText_PkmnsXCuredProblem:: @ 85CC157
	.string "{STRING 19}’s {STRING 22}\ncured its {STRING 0} problem!$"

gText_PkmnsXNormalizedStatus:: @ 85CC175
	.string "{STRING 19}’s {STRING 22}\nnormalized its status!$"

gText_PkmnsXRestoredHealth:: @ 85CC194
	.string "{STRING 19}’s {STRING 22}\nrestored health!$"

gText_PkmnsXRestoredPP:: @ 85CC1AD
	.string "{STRING 19}’s {STRING 22}\nrestored {STRING 0}’s PP!$"

gText_PkmnsXRestoredStatus:: @ 85CC1C7
	.string "{STRING 19}’s {STRING 22}\nrestored its status!$"

gText_PkmnsXRestoredHPALittle:: @ 85CC1E4
	.string "{STRING 19}’s {STRING 22}\nrestored its HP a little!$"

gText_XAllowsOnlyY:: @ 85CC206
	.string "{STRING 22} allows the\nuse of only {STRING 20}!\p$"

gText_PkmnHungOnWithX:: @ 85CC225
	.string "{STRING 16} hung on\nusing its {STRING 22}!$"

gText_EmptyString3:: @ 85CC23E
	.string "$"

gText_YouThrowABallNowRight:: @ 85CC23F
	.string "You throw a BALL now, right?\nI… I’ll do my best!$"

	.align 2
gUnknown_085CC270:: @ 85CC270
	.4byte gText_Buffer36
	.4byte gText_PkmnGainedEXP
	.4byte gText_PkmnGrewToLv
	.4byte gText_PkmnLearnedMove
	.4byte gText_TryToLearnMove1
	.4byte gText_TryToLearnMove2
	.4byte gText_TryToLearnMove3
	.4byte gText_PkmnForgotMove
	.4byte gText_StopLearningMove
	.4byte gText_DidNotLearnMove
	.4byte gText_PkmnLearnedMove2
	.4byte gText_AttackMissed
	.4byte gText_PkmnProtectedItself
	.4byte gText_StatsWontIncrease2
	.4byte gText_AvoidedDamage
	.4byte gText_ItDoesntAffect
	.4byte gText_PkmnFainted
	.4byte gText_PkmnFainted2
	.4byte gText_PlayerGotMoney
	.4byte gText_PlayerWhiteout
	.4byte gText_PlayerWhiteout2
	.4byte gText_PreventsEscape
	.4byte gText_HitXTimes
	.4byte gText_PkmnFellAsleep
	.4byte gText_PkmnMadeSleep
	.4byte gText_PkmnAlreadyAsleep
	.4byte gText_PkmnAlreadyAsleep2
	.4byte gText_PkmnWasntAffected
	.4byte gText_PkmnWasPoisoned
	.4byte gText_PkmnPoisonedBy
	.4byte gText_PkmnHurtByPoison
	.4byte gText_PkmnAlreadyPoisoned
	.4byte gText_PkmnBadlyPoisoned
	.4byte gText_PkmnEnergyDrained
	.4byte gText_PkmnWasBurned
	.4byte gText_PkmnBurnedBy
	.4byte gText_PkmnHurtByBurn
	.4byte gText_PkmnWasFrozen
	.4byte gText_PkmnFrozenBy
	.4byte gText_PkmnIsFrozen
	.4byte gText_PkmnWasDefrosted
	.4byte gText_PkmnWasDefrosted2
	.4byte gText_PkmnWasDefrostedBy
	.4byte gText_PkmnWasParalyzed
	.4byte gText_PkmnWasParalyzedBy
	.4byte gText_PkmnIsParalyzed
	.4byte gText_PkmnIsAlreadyParalyzed
	.4byte gText_PkmnHealedParalysis
	.4byte gText_PkmnDreamEaten
	.4byte gText_StatsWontIncrease
	.4byte gText_StatsWontDecrease
	.4byte gText_TeamStoppedWorking
	.4byte gText_FoeStoppedWorking
	.4byte gText_PkmnIsConfused
	.4byte gText_PkmnHealedConfusion
	.4byte gText_PkmnWasConfused
	.4byte gText_PkmnAlreadyConfused
	.4byte gText_PkmnFellInLove
	.4byte gText_PkmnInLove
	.4byte gText_PkmnImmobilizedByLove
	.4byte gText_PkmnBlownAway
	.4byte gText_PkmnChangedType
	.4byte gText_PkmnFlinched
	.4byte gText_PkmnRegainedHealth
	.4byte gText_PkmnHPFull
	.4byte gText_PkmnRaisedSpDef
	.4byte gText_PkmnRaisedDef
	.4byte gText_PkmnCoveredByVeil
	.4byte gText_PkmnUsedSafeguard
	.4byte gText_PkmnSafeguardExpired
	.4byte gText_PkmnWentToSleep
	.4byte gText_PkmnSleptHealthy
	.4byte gText_PkmnWhippedWhirlwind
	.4byte gText_PkmnTookSunlight
	.4byte gText_PkmnLoweredHead
	.4byte gText_PkmnIsGlowing
	.4byte gText_PkmnFlewHigh
	.4byte gText_PkmnDugHole
	.4byte gText_PkmnSqueezedByBind
	.4byte gText_PkmnTrappedInVortex
	.4byte gText_PkmnWrappedBy
	.4byte gText_PkmnClamped
	.4byte gText_PkmnHurtBy
	.4byte gText_PkmnFreedFrom
	.4byte gText_PkmnCrashed
	.4byte gText_PkmnShroudedInMist
	.4byte gText_PkmnProtectedByMist
	.4byte gText_PkmnGettingPumped
	.4byte gText_PkmnHitWithRecoil
	.4byte gText_PkmnProtectedItself2
	.4byte gText_PkmnBuffetedBySandstorm
	.4byte gText_PkmnPeltedByHail
	.4byte gText_PkmnSeeded
	.4byte gText_PkmnEvadedAttack
	.4byte gText_PkmnSappedByLeechSeed
	.4byte gText_PkmnFastAsleep
	.4byte gText_PkmnWokeUp
	.4byte gText_PkmnUproarKeptAwake
	.4byte gText_PkmnWokeUpInUproar
	.4byte gText_PkmnCausedUproar
	.4byte gText_PkmnMakingUproar
	.4byte gText_PkmnCalmedDown
	.4byte gText_PkmnCantSleepInUproar
	.4byte gText_PkmnStockpiled
	.4byte gText_PkmnCantStockpile
	.4byte gText_PkmnCantSleepInUproar2
	.4byte gText_UproarKeptPkmnAwake
	.4byte gText_PkmnStayedAwakeUsing
	.4byte gText_PkmnStoringEnergy
	.4byte gText_PkmnUnleashedEnergy
	.4byte gText_PkmnFatigueConfusion
	.4byte gText_PkmnPickedUpItem
	.4byte gText_PkmnUnaffected
	.4byte gText_PkmnTransformedInto
	.4byte gText_PkmnMadeSubstitute
	.4byte gText_PkmnHasSubstitute
	.4byte gText_SubstituteDamaged
	.4byte gText_PkmnSubstituteFaded
	.4byte gText_PkmnMustRecharge
	.4byte gText_PkmnRageBuilding
	.4byte gText_PkmnMoveWasDisabled
	.4byte gText_PkmnMoveIsDisabled
	.4byte gText_PkmnMoveDisabledNoMore
	.4byte gText_PkmnGotEncore
	.4byte gText_PkmnEncoreEnded
	.4byte gText_PkmnTookAim
	.4byte gText_PkmnSketchedMove
	.4byte gText_PkmnTryingToTakeFoe
	.4byte gText_PkmnTookFoe
	.4byte gText_PkmnReducedPP
	.4byte gText_PkmnStoleItem
	.4byte gText_PkmnCantEscape
	.4byte gText_PkmnFellIntoNightmare
	.4byte gText_PkmnLockedInNightmare
	.4byte gText_PkmnLaidCurse
	.4byte gText_PkmnAfflictedByCurse
	.4byte gText_SpikesScattered
	.4byte gText_PkmnHurtBySpikes
	.4byte gText_PkmnIdentified
	.4byte gText_PkmnPerishCountFell
	.4byte gText_PkmnBracedItself
	.4byte gText_PkmnEnduredHit
	.4byte gText_MagnitudeStrength
	.4byte gText_PkmnCutHPMaxedAttack
	.4byte gText_PkmnCopiedStatChanges
	.4byte gText_PkmnGotFree
	.4byte gText_PkmnShedLeechSeed
	.4byte gText_PkmnBlewAwaySpikes
	.4byte gText_PkmnFledFromBattle
	.4byte gText_PkmnForesawAttack
	.4byte gText_PkmnTookAttack
	.4byte gText_PkmnAttack
	.4byte gText_PkmnCenterAttention
	.4byte gText_PkmnChargingPower
	.4byte gText_NaturePowerTurnedInto
	.4byte gText_PkmnStatusNormal
	.4byte gText_PkmnHasNoMovesLeft
	.4byte gText_PkmnSubjectedToTorment
	.4byte gText_PkmnCantUseMoveTorment
	.4byte gText_PkmnTighteningFocus
	.4byte gText_PkmnFellForTaunt
	.4byte gText_PkmnCantUseMoveTaunt
	.4byte gText_PkmnReadyToHelp
	.4byte gText_PkmnSwitchedItems
	.4byte gText_PkmnCopiedFoe
	.4byte gText_PkmnMadeWish
	.4byte gText_PkmnWishCameTrue
	.4byte gText_PkmnPlantedRoots
	.4byte gText_PkmnAbsorbedNutrients
	.4byte gText_PkmnAnchoredItself
	.4byte gText_PkmnWasMadeDrowsy
	.4byte gText_PkmnKnockedOff
	.4byte gText_PkmnSwappedAbilities
	.4byte gText_PkmnSealedOpponentMove
	.4byte gText_PkmnCantUseMoveSealed
	.4byte gText_PkmnWantsGrudge
	.4byte gText_PkmnLostPPGrudge
	.4byte gText_PkmnShroudedItself
	.4byte gText_PkmnMoveBounced
	.4byte gText_PkmnWaitsForTarget
	.4byte gText_PkmnSnatchedMove
	.4byte gText_PkmnMadeItRain
	.4byte gText_PkmnRaisedSpeed
	.4byte gText_PkmnProtectedBy
	.4byte gText_PkmnPreventsUsage
	.4byte gText_PkmnRestoredHPUsing
	.4byte gText_PkmnChangedTypeWith
	.4byte gText_PkmnPreventsParalysisWith
	.4byte gText_PkmnPreventsRomanceWith
	.4byte gText_PkmnPreventsPoisoningWith
	.4byte gText_PkmnPreventsConfusionWith
	.4byte gText_PkmnRaisedFirePowerWith
	.4byte gText_PkmnAnchorsItselfWith
	.4byte gText_PkmnCutsAttackWith
	.4byte gText_PkmnPreventsStatLossWith
	.4byte gText_PkmnHurtsWith
	.4byte gText_PkmnTraced
	.4byte gText_StatSharply
	.4byte gText_StatRose
	.4byte gText_StatHarshly
	.4byte gText_StatFell
	.4byte gText_PkmnsStatChanged
	.4byte gText_PkmnsStatChanged2
	.4byte gText_PkmnsStatChanged3
	.4byte gText_PkmnsStatChanged4
	.4byte gText_CriticalHit
	.4byte gText_OneHitKO
	.4byte gText_123Poof
	.4byte gText_AndEllipsis
	.4byte gText_NotVeryEffective
	.4byte gText_SuperEffective
	.4byte gText_GotAwaySafely
	.4byte gText_WildPkmnFled
	.4byte gText_NoRunningFromTrainers
	.4byte gText_CantEscape
	.4byte gText_DontLeaveBirch
	.4byte gText_ButNothingHappened
	.4byte gText_ButItFailed
	.4byte gText_ItHurtConfusion
	.4byte gText_MirrorMoveFailed
	.4byte gText_StartedToRain
	.4byte gText_DownpourStarted
	.4byte gText_RainContinues
	.4byte gText_DownpourContinues
	.4byte gText_RainStopped
	.4byte gText_SandstormBrewed
	.4byte gText_SandstormRages
	.4byte gText_SandstormSubsided
	.4byte gText_SunlightGotBright
	.4byte gText_SunlightStrong
	.4byte gText_SunlightFaded
	.4byte gText_StartedHail
	.4byte gText_HailContinues
	.4byte gText_HailStopped
	.4byte gText_FailedToSpitUp
	.4byte gText_FailedToSwallow
	.4byte gText_WindBecameHeatWave
	.4byte gText_StatChangesGone
	.4byte gText_CoinsScattered
	.4byte gText_TooWeakForSubstitute
	.4byte gText_SharedPain
	.4byte gText_BellChimed
	.4byte gText_FaintInThree
	.4byte gText_NoPPLeft
	.4byte gText_ButNoPPLeft
	.4byte gText_XUsedY
	.4byte gText_WallyUsedY
	.4byte gText_TrainerBlockedBall
	.4byte gText_DontBeAThief
	.4byte gText_ItDodgedBall
	.4byte gText_YouMissedPkmn
	.4byte gText_PkmnBrokeFree
	.4byte gText_ItAppearedCaught
	.4byte gText_AarghAlmostHadIt
	.4byte gText_ShootSoClose
	.4byte gText_GotchaPkmnCaught
	.4byte gText_GotchaPkmnCaught2
	.4byte gText_GiveNicknameCaptured
	.4byte gText_PkmnSentToPC
	.4byte gText_PkmnDataAddedToDex
	.4byte gText_ItIsRaining
	.4byte gText_SandstormIsRaging
	.4byte gText_CantEscape2
	.4byte gText_PkmnIgnoresAsleep
	.4byte gText_PkmnIgnoredOrders
	.4byte gText_PkmnBeganToNap
	.4byte gText_PkmnLoafing
	.4byte gText_PkmnWontObey
	.4byte gText_PkmnTurnedAway
	.4byte gText_PkmnPretendNotNotice
	.4byte gText_EnemyAboutToSwitchPkmn
	.4byte gText_CreptCloser
	.4byte gText_CantGetCloser
	.4byte gText_PkmnWatchingCarefully
	.4byte gText_PkmnCuriousAboutX
	.4byte gText_PkmnEnthralledByX
	.4byte gText_PkmnIgnoredX
	.4byte gText_ThrewPokeblockAtPkmn
	.4byte gText_OutOfSafariBalls
	.4byte gText_PkmnsXCuredParalysis
	.4byte gText_PkmnsXCuredPoison
	.4byte gText_PkmnsXHealedBurn
	.4byte gText_PkmnsXDefrostedIt
	.4byte gText_PkmnsXWokeIt
	.4byte gText_PkmnsXSnappedOut
	.4byte gText_PkmnsXCuredProblem
	.4byte gText_PkmnsXRestoredHealth
	.4byte gText_PkmnsXRestoredPP
	.4byte gText_PkmnsXRestoredStatus
	.4byte gText_PkmnsXRestoredHPALittle
	.4byte gText_XAllowsOnlyY
	.4byte gText_PkmnHungOnWithX
	.4byte gText_EmptyString3
	.4byte gText_PkmnsXPreventsBurns
	.4byte gText_PkmnsXBlocksY
	.4byte gText_PkmnsXRestoredHPALittle2
	.4byte gText_PkmnsXWhippedUpSandstorm
	.4byte gText_PkmnsXPreventsYLoss
	.4byte gText_PkmnsXInfatuatedY
	.4byte gText_PkmnsXMadeYIneffective
	.4byte gText_PkmnsXCuredYProblem
	.4byte gText_ItSuckedLiquidOoze
	.4byte gText_PkmnTransformed
	.4byte gText_ElectricityWeakened
	.4byte gText_FireWeakened
	.4byte gText_PkmnHidUnderwater
	.4byte gText_PkmnSprangUp
	.4byte gText_HMMovesCantBeForgotten
	.4byte gText_XFoundOneY
	.4byte gText_PlayerDefeatedXY
	.4byte gText_SoothingAroma
	.4byte gText_ItemsCantBeUsedNow
	.4byte gText_ForXCommaYZ
	.4byte gText_UsingXTheYOfZN
	.4byte gText_PkmnUsedXToGetPumped
	.4byte gText_PkmnsXMadeYUseless
	.4byte gText_PkmnTrappedBySandTomb
	.4byte gText_EmptyString4
	.4byte gText_ABoosted
	.4byte gText_PkmnsXIntensifiedSun
	.4byte gText_PkmnMakesGroundMiss
	.4byte gText_YouThrowABallNowRight
	.4byte gText_PkmnsXTookAttack
	.4byte gText_PkmnChoseXAsDestiny
	.4byte gText_PkmnLostFocus
	.4byte gText_UseNextPkmn
	.4byte gText_PkmnFledUsingIts
	.4byte gText_PkmnFledUsing
	.4byte gText_PkmnWasDraggedOut
	.4byte gText_PreventedFromWorking
	.4byte gText_PkmnsXNormalizedStatus
	.4byte gText_XYUsedZ
	.4byte gText_BoxIsFull
	.4byte gText_PkmnAvoidedAttack
	.4byte gText_PkmnsXMadeItIneffective
	.4byte gText_PkmnsXPreventsFlinching
	.4byte gText_PkmnAlreadyHasBurn
	.4byte gText_StatsWontDecrease2
	.4byte gText_PkmnsXBlocksY2
	.4byte gText_PkmnsXWoreOff
	.4byte gText_PkmnRaisedDefALittle
	.4byte gText_PkmnRaisedSpDefALittle
	.4byte gText_TheWallShattered
	.4byte gText_PkmnsXPreventsYsZ
	.4byte gText_PkmnsXCuredItsYProblem
	.4byte gText_PkmnCantEscape2
	.4byte gText_PkmnObtainedX
	.4byte gText_PkmnObtainedX2
	.4byte gText_PkmnObtainedXYObtainedZ
	.4byte gText_ButNoEffect
	.4byte gText_PkmnsXHadNoEffectOnY
	.4byte gText_TwoEnemiesDefeated
	.4byte gText_String48
	.4byte gText_PkmnIncapableOfPower
	.4byte gText_GlintAppearsInEye
	.4byte gText_PkmnGettingIntoPosition
	.4byte gText_PkmnBeganGrowlingDeeply
	.4byte gText_PkmnEagerForMore
	.4byte gText_DefeatedOpponentByReferee
	.4byte gText_LostToOpponentByReferee
	.4byte gText_TiedOpponentByReferee
	.4byte gText_QuestionForfeitMatch
	.4byte gText_ForfeitedMatch
	.4byte gText_PkmnTransferredSomeonesPC
	.4byte gText_PkmnTransferredLanettesPC
	.4byte gText_PkmnBoxSomeonesPCFull
	.4byte gText_PkmnBoxLanettesPCFull
	.4byte gText_String37
	.4byte gText_String49

	.align 2
gUnknown_085CC834:: @ 85CC834
	.incbin "baserom.gba", 0x5cc834, 0x14e

gUnknown_085CC982:: @ 85CC982
	.incbin "baserom.gba", 0x5cc982, 0xe

gUnknown_085CC990:: @ 85CC990
	.string "What?\n{STR_VAR_1} is evolving!$"

gUnknown_085CC9A6:: @ 85CC9A6
	.string "Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{UNKNOWN_A}\p$"

gUnknown_085CC9D3:: @ 85CC9D3
	.string "Huh? {STR_VAR_1}\nstopped evolving!\p$"

gUnknown_085CC9EE:: @ 85CC9EE
	.string "……?\p$"

gUnknown_085CC9F3:: @ 85CC9F3
	.string "What will\n{STRING 18} do?$"

gUnknown_085CCA04:: @ 85CCA04
	.string "What will\n{STRING 35} do?$"

gUnknown_085CCA15:: @ 85CCA15
	.string "What will\nWALLY do?$"

gUnknown_085CCA29:: @ 85CCA29
	.string "{PAUSE 16}Link standby…$"

gUnknown_085CCA3A:: @ 85CCA3A
	.incbin "baserom.gba", 0x5cca3a, 0x1a

gUnknown_085CCA54:: @ 85CCA54
	.incbin "baserom.gba", 0x5cca54, 0x1b

gUnknown_085CCA6F:: @ 85CCA6F
	.incbin "baserom.gba", 0x5cca6f, 0x4

gUnknown_085CCA73:: @ 85CCA73
	.incbin "baserom.gba", 0x5cca73, 0x48

gUnknown_085CCABB:: @ 85CCABB
	.incbin "baserom.gba", 0x5ccabb, 0xf

gUnknown_085CCACA:: @ 85CCACA
	.incbin "baserom.gba", 0x5ccaca, 0x62

gUnknown_085CCB2C:: @ 85CCB2C
	.incbin "baserom.gba", 0x5ccb2c, 0x10

gUnknown_085CCB3C:: @ 85CCB3C
	.incbin "baserom.gba", 0x5ccb3c, 0x3d

gUnknown_085CCB79:: @ 85CCB79
	.incbin "baserom.gba", 0x5ccb79, 0x6

gUnknown_085CCB7F:: @ 85CCB7F
	.incbin "baserom.gba", 0x5ccb7f, 0x3

gUnknown_085CCB82:: @ 85CCB82
	.incbin "baserom.gba", 0x5ccb82, 0x2

gUnknown_085CCB84:: @ 85CCB84
	.incbin "baserom.gba", 0x5ccb84, 0x2

gUnknown_085CCB86:: @ 85CCB86
	.incbin "baserom.gba", 0x5ccb86, 0x2

gUnknown_085CCB88:: @ 85CCB88
	.incbin "baserom.gba", 0x5ccb88, 0x4

gUnknown_085CCB8C:: @ 85CCB8C
	.incbin "baserom.gba", 0x5ccb8c, 0x4

gBadEggNickname:: @ 85CCB90
	.incbin "baserom.gba", 0x5ccb90, 0x8

BattleText_Wally:: @ 85CCB98
	.incbin "baserom.gba", 0x5ccb98, 0x6

gUnknown_085CCB9E:: @ 85CCB9E
	.incbin "baserom.gba", 0x5ccb9e, 0x7

gUnknown_085CCBA5:: @ 85CCBA5
	.incbin "baserom.gba", 0x5ccba5, 0x8

gUnknown_085CCBAD:: @ 85CCBAD
	.incbin "baserom.gba", 0x5ccbad, 0x8

gUnknown_085CCBB5:: @ 85CCBB5
	.incbin "baserom.gba", 0x5ccbb5, 0x4

gUnknown_085CCBB9:: @ 85CCBB9
	.incbin "baserom.gba", 0x5ccbb9, 0x3

gUnknown_085CCBBC:: @ 85CCBBC
	.incbin "baserom.gba", 0x5ccbbc, 0x132

gUnknown_085CCCEE:: @ 85CCCEE
	.incbin "baserom.gba", 0x5cccee, 0x32

gUnknown_085CCD20:: @ 85CCD20
	.incbin "baserom.gba", 0x5ccd20, 0x92

gUnknown_085CCDB2:: @ 85CCDB2
	.incbin "baserom.gba", 0x5ccdb2, 0x3

gUnknown_085CCDB5:: @ 85CCDB5
	.incbin "baserom.gba", 0x5ccdb5, 0x3

gUnknown_085CCDB8:: @ 85CCDB8
	.incbin "baserom.gba", 0x5ccdb8, 0x3

gUnknown_085CCDBB:: @ 85CCDBB
	.incbin "baserom.gba", 0x5ccdbb, 0x5

gUnknown_085CCDC0:: @ 85CCDC0
	.incbin "baserom.gba", 0x5ccdc0, 0x6

gUnknown_085CCDC6:: @ 85CCDC6
	.incbin "baserom.gba", 0x5ccdc6, 0x5

gUnknown_085CCDCB:: @ 85CCDCB
	.incbin "baserom.gba", 0x5ccdcb, 0x13

gUnknown_085CCDDE:: @ 85CCDDE
	.incbin "baserom.gba", 0x5ccdde, 0x26

gUnknown_085CCE04:: @ 85CCE04
	.incbin "baserom.gba", 0x5cce04, 0x13

gUnknown_085CCE17:: @ 85CCE17
	.incbin "baserom.gba", 0x5cce17, 0x21

gUnknown_085CCE38:: @ 85CCE38
	.incbin "baserom.gba", 0x5cce38, 0x1b

gText_TwoEnemiesDefeated:: @ 85CCE53
	.string "{STRING 28} {STRING 29} and\n{STRING 46} {STRING 47}\lwere defeated!\p$"

gText_String48:: @ 85CCE73
	.string "{STRING 48}$"

gText_PkmnIncapableOfPower:: @ 85CCE76
	.string "{STRING 15} appears incapable\nof using its power!$"

gText_GlintAppearsInEye:: @ 85CCE9F
	.string "A glint appears in\n{STRING 19}’s eyes!$"

gText_PkmnGettingIntoPosition:: @ 85CCEBD
	.string "{STRING 19} is getting into\nposition!$"

gText_PkmnBeganGrowlingDeeply:: @ 85CCEDA
	.string "{STRING 19} began growling deeply!$"

gText_PkmnEagerForMore:: @ 85CCEF4
	.string "{STRING 19} is eager for more!$"

gUnknown_085CCF0A:: @ 85CCF0A
	.2byte 0x016E, 0x016F, 0x0170, 0x0171

gText_RefIfNothingIsDecided:: @ 85CCF12
	.string "REFEREE: If nothing is decided in\n3 turns, we will go to judging!$"

gText_RefThatsIt:: @ 85CCF54
	.string "REFEREE: That’s it! We will now go to\njudging to determine the winner!$"

gText_RefJudgeMind:: @ 85CCF9B
	.string "REFEREE: Judging category 1, Mind!\nThe POKéMON showing the most guts!\p$"

gText_RefJudgeSkill:: @ 85CCFE2
	.string "REFEREE: Judging category 2, Skill!\nThe POKéMON using moves the best!\p$"

gText_RefJudgeBody:: @ 85CD029
	.string "REFEREE: Judging category 3, Body!\nThe POKéMON with the most vitality!\p$"

gText_RefJudgement1:: @ 85CD071
	.string "REFEREE: Judgment: {STRING 0} to {PLAYER}!\nThe winner is {STRING 35}’s {STRING 5}!\p$"

gText_RefJudgement2:: @ 85CD0A6
	.string "REFEREE: Judgment: {STRING 0} to {PLAYER}!\nThe winner is {STRING 29}’s {RIVAL}!\p$"

gText_RefJudgement3:: @ 85CD0DB
	.string "REFEREE: Judgment: 3 to 3!\nWe have a draw!\p$"

gText_DefeatedOpponentByReferee:: @ 85CD107
	.string "{STRING 5} defeated the opponent\n{RIVAL} in a REFEREE’s decision!$"

gText_LostToOpponentByReferee:: @ 85CD13C
	.string "{STRING 5} lost to the opponent\n{RIVAL} in a REFEREE’s decision!$"

gText_TiedOpponentByReferee:: @ 85CD170
	.string "{STRING 5} tied the opponent\n{RIVAL} in a REFEREE’s decision!$"

gText_RefCommenceBattle:: @ 85CD1A1
	.string "REFEREE: {STRING 5} VS {RIVAL}!\nCommence battling!$"

	.align 2
gUnknown_085CD1C8:: @ 85CD1C8
	.4byte gText_RefIfNothingIsDecided
	.4byte gText_RefThatsIt
	.4byte gText_RefJudgeMind
	.4byte gText_RefJudgeSkill
	.4byte gText_RefJudgeBody
	.4byte gText_RefJudgement1
	.4byte gText_RefJudgement2
	.4byte gText_RefJudgement3
	.4byte gText_RefCommenceBattle

gText_QuestionForfeitMatch:: @ 85CD1EC
	.string "Would you like to forfeit the match\nand quit now?$"

gText_ForfeitedMatch:: @ 85CD21E
	.string "{STRING 35} forfeited the match!$"

gText_String37:: @ 85CD236
	.string "{STRING 37}$"

gText_String49:: @ 85CD239
	.string "{STRING 49}$"

	.string "{PLAY_SE 0x0011}{STRING 28} {STRING 29} fled!$"

	.align 2
gUnknown_085CD24C:: @ 85CD24C
	.incbin "baserom.gba", 0x5cd24c, 0x1b

gUnknown_085CD267:: @ 85CD267
	.incbin "baserom.gba", 0x5cd267, 0x28

gUnknown_085CD28F:: @ 85CD28F
	.incbin "baserom.gba", 0x5cd28f, 0x3c

gUnknown_085CD2CB:: @ 85CD2CB
	.incbin "baserom.gba", 0x5cd2cb, 0x36

gUnknown_085CD301:: @ 85CD301
	.incbin "baserom.gba", 0x5cd301, 0x17

gUnknown_085CD318:: @ 85CD318
	.incbin "baserom.gba", 0x5cd318, 0x1e

gUnknown_085CD336:: @ 85CD336
	.incbin "baserom.gba", 0x5cd336, 0xec

gUnknown_085CD422:: @ 85CD422
	.incbin "baserom.gba", 0x5cd422, 0x23e

gUnknown_085CD660:: @ 85CD660
	.incbin "baserom.gba", 0x5cd660, 0x8

gUnknown_085CD668:: @ 85CD668
	.incbin "baserom.gba", 0x5cd668, 0x4

