#ifndef GUARD_DATA_ITEM_ICON_TABLE_H
#define GUARD_DATA_ITEM_ICON_TABLE_H

#include "global.h"
#include "graphics.h"

const u32 *const gItemIconTable[][2] = 
{
    gItemIcon_QuestionMark,    gItemIconPalette_QuestionMark,
// Pokeballs
    gItemIcon_MasterBall,     gItemIconPalette_MasterBall,
    gItemIcon_UltraBall,      gItemIconPalette_UltraBall,
    gItemIcon_GreatBall,      gItemIconPalette_GreatBall,
    gItemIcon_PokeBall,       gItemIconPalette_PokeBall,
    gItemIcon_SafariBall,     gItemIconPalette_SafariBall,
    gItemIcon_NetBall,        gItemIconPalette_NetBall,
    gItemIcon_DiveBall,       gItemIconPalette_DiveBall,
    gItemIcon_NestBall,       gItemIconPalette_NestBall,
    gItemIcon_RepeatBall,     gItemIconPalette_RepeatBall,
    gItemIcon_TimerBall,      gItemIconPalette_RepeatBall,
    gItemIcon_LuxuryBall,     gItemIconPalette_LuxuryBall,
    gItemIcon_PremierBall,    gItemIconPalette_LuxuryBall,
// Medicine
    gItemIcon_Potion,         gItemIconPalette_Potion,
    gItemIcon_Antidote,       gItemIconPalette_Antidote,
    gItemIcon_StatusHeal,     gItemIconPalette_BurnHeal,
    gItemIcon_StatusHeal,     gItemIconPalette_IceHeal,
    gItemIcon_StatusHeal,     gItemIconPalette_Awakening,
    gItemIcon_StatusHeal,     gItemIconPalette_ParalyzeHeal,
    gItemIcon_LargePotion,    gItemIconPalette_FullRestore,
    gItemIcon_LargePotion,    gItemIconPalette_MaxPotion,
    gItemIcon_Potion,         gItemIconPalette_HyperPotion,
    gItemIcon_Potion,         gItemIconPalette_SuperPotion,
    gItemIcon_FullHeal,       gItemIconPalette_FullHeal,
    gItemIcon_Revive,         gItemIconPalette_Revive,
    gItemIcon_MaxRevive,      gItemIconPalette_Revive,
    gItemIcon_FreshWater,     gItemIconPalette_FreshWater,
    gItemIcon_SodaPop,        gItemIconPalette_SodaPop,
    gItemIcon_Lemonade,       gItemIconPalette_Lemonade,
    gItemIcon_MoomooMilk,     gItemIconPalette_MoomooMilk,
    gItemIcon_Powder,         gItemIconPalette_EnergyPowder,
    gItemIcon_EnergyRoot,     gItemIconPalette_EnergyRoot,
    gItemIcon_Powder,         gItemIconPalette_HealPowder,
    gItemIcon_RevivalHerb,    gItemIconPalette_RevivalHerb,
    gItemIcon_Ether,          gItemIconPalette_Ether,
    gItemIcon_Ether,          gItemIconPalette_MaxEther,
    gItemIcon_Ether,          gItemIconPalette_Elixir,
    gItemIcon_Ether,          gItemIconPalette_MaxElixir,
    gItemIcon_LavaCookie,     gItemIconPalette_LavaCookieAndLetter,
    gItemIcon_Flute,          gItemIconPalette_BlueFlute,
    gItemIcon_Flute,          gItemIconPalette_YellowFlute,
    gItemIcon_Flute,          gItemIconPalette_RedFlute,
    gItemIcon_Flute,          gItemIconPalette_BlackFlute,
    gItemIcon_Flute,          gItemIconPalette_WhiteFlute,
    gItemIcon_BerryJuice,     gItemIconPalette_BerryJuice,
    gItemIcon_SacredAsh,      gItemIconPalette_SacredAsh,
// Collectibles
    gItemIcon_Powder,        gItemIconPalette_ShoalSalt,
    gItemIcon_ShoalShell,    gItemIconPalette_Shell,
    gItemIcon_Shard,         gItemIconPalette_RedShard,
    gItemIcon_Shard,         gItemIconPalette_BlueShard,
    gItemIcon_Shard,         gItemIconPalette_YellowShard,
    gItemIcon_Shard,         gItemIconPalette_GreenShard,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Vitamins
    gItemIcon_HPUp,         gItemIconPalette_HPUp,
    gItemIcon_Vitamin,      gItemIconPalette_Protein,
    gItemIcon_Vitamin,      gItemIconPalette_Iron,
    gItemIcon_Vitamin,      gItemIconPalette_Carbos,
    gItemIcon_Vitamin,      gItemIconPalette_Calcium,
    gItemIcon_RareCandy,    gItemIconPalette_RareCandy,
    gItemIcon_PPUp,         gItemIconPalette_PPUp,
    gItemIcon_Vitamin,      gItemIconPalette_Zinc,
    gItemIcon_PPMax,        gItemIconPalette_PPMax,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Battle items
    gItemIcon_BattleStatItem,    gItemIconPalette_GuardSpec,
    gItemIcon_BattleStatItem,    gItemIconPalette_DireHit,
    gItemIcon_BattleStatItem,    gItemIconPalette_XAttack,
    gItemIcon_BattleStatItem,    gItemIconPalette_XDefend,
    gItemIcon_BattleStatItem,    gItemIconPalette_XSpeed,
    gItemIcon_BattleStatItem,    gItemIconPalette_XAccuracy,
    gItemIcon_BattleStatItem,    gItemIconPalette_XSpecial,
    gItemIcon_PokeDoll,          gItemIconPalette_PokeDoll,
    gItemIcon_FluffyTail,        gItemIconPalette_FluffyTail,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Field items
    gItemIcon_Repel,         gItemIconPalette_SuperRepel,
    gItemIcon_Repel,         gItemIconPalette_MaxRepel,
    gItemIcon_EscapeRope,    gItemIconPalette_EscapeRope,
    gItemIcon_Repel,         gItemIconPalette_Repel,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Evolution stones
    gItemIcon_SunStone,      gItemIconPalette_SunStone,
    gItemIcon_MoonStone,     gItemIconPalette_MoonStone,
    gItemIcon_FireStone,     gItemIconPalette_FireStone,
    gItemIcon_ThunderStone,  gItemIconPalette_ThunderStone,
    gItemIcon_WaterStone,    gItemIconPalette_WaterStone,
    gItemIcon_LeafStone,     gItemIconPalette_LeafStone,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Valuables
    gItemIcon_TinyMushroom,    gItemIconPalette_Mushroom,
    gItemIcon_BigMushroom,     gItemIconPalette_Mushroom,
    gItemIcon_QuestionMark,    gItemIconPalette_QuestionMark,
    gItemIcon_Pearl,           gItemIconPalette_Pearl,
    gItemIcon_BigPearl,        gItemIconPalette_Pearl,
    gItemIcon_Stardust,        gItemIconPalette_Star,
    gItemIcon_StarPiece,       gItemIconPalette_Star,
    gItemIcon_Nugget,          gItemIconPalette_Nugget,
    gItemIcon_HeartScale,      gItemIconPalette_HeartScale,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Mail
    gItemIcon_OrangeMail,     gItemIconPalette_OrangeMail,
    gItemIcon_HarborMail,     gItemIconPalette_HarborMail,
    gItemIcon_GlitterMail,    gItemIconPalette_GlitterMail,
    gItemIcon_MechMail,       gItemIconPalette_MechMail,
    gItemIcon_WoodMail,       gItemIconPalette_WoodMail,
    gItemIcon_WaveMail,       gItemIconPalette_WaveMail,
    gItemIcon_BeadMail,       gItemIconPalette_BeadMail,
    gItemIcon_ShadowMail,     gItemIconPalette_ShadowMail,
    gItemIcon_TropicMail,     gItemIconPalette_TropicMail,
    gItemIcon_DreamMail,      gItemIconPalette_DreamMail,
    gItemIcon_FabMail,        gItemIconPalette_FabMail,
    gItemIcon_RetroMail,      gItemIconPalette_RetroMail,
// Berries
    gItemIcon_CheriBerry,     gItemIconPalette_CheriBerry,
    gItemIcon_ChestoBerry,    gItemIconPalette_ChestoBerry,
    gItemIcon_PechaBerry,     gItemIconPalette_PechaBerry,
    gItemIcon_RawstBerry,     gItemIconPalette_RawstBerry,
    gItemIcon_AspearBerry,    gItemIconPalette_AspearBerry,
    gItemIcon_LeppaBerry,     gItemIconPalette_LeppaBerry,
    gItemIcon_OranBerry,      gItemIconPalette_OranBerry,
    gItemIcon_PersimBerry,    gItemIconPalette_PersimBerry,
    gItemIcon_LumBerry,       gItemIconPalette_LumBerry,
    gItemIcon_SitrusBerry,    gItemIconPalette_SitrusBerry,
    gItemIcon_FigyBerry,      gItemIconPalette_FigyBerry,
    gItemIcon_WikiBerry,      gItemIconPalette_WikiBerry,
    gItemIcon_MagoBerry,      gItemIconPalette_MagoBerry,
    gItemIcon_AguavBerry,     gItemIconPalette_AguavBerry,
    gItemIcon_IapapaBerry,    gItemIconPalette_IapapaBerry,
    gItemIcon_RazzBerry,      gItemIconPalette_RazzBerry,
    gItemIcon_BlukBerry,      gItemIconPalette_BlukBerry,
    gItemIcon_NanabBerry,     gItemIconPalette_NanabBerry,
    gItemIcon_WepearBerry,    gItemIconPalette_WepearBerry,
    gItemIcon_PinapBerry,     gItemIconPalette_PinapBerry,
    gItemIcon_PomegBerry,     gItemIconPalette_PomegBerry,
    gItemIcon_KelpsyBerry,    gItemIconPalette_KelpsyBerry,
    gItemIcon_QualotBerry,    gItemIconPalette_QualotBerry,
    gItemIcon_HondewBerry,    gItemIconPalette_HondewBerry,
    gItemIcon_GrepaBerry,     gItemIconPalette_GrepaBerry,
    gItemIcon_TamatoBerry,    gItemIconPalette_TamatoBerry,
    gItemIcon_CornnBerry,     gItemIconPalette_CornnBerry,
    gItemIcon_MagostBerry,    gItemIconPalette_MagostBerry,
    gItemIcon_RabutaBerry,    gItemIconPalette_RabutaBerry,
    gItemIcon_NomelBerry,     gItemIconPalette_NomelBerry,
    gItemIcon_SpelonBerry,    gItemIconPalette_SpelonBerry,
    gItemIcon_PamtreBerry,    gItemIconPalette_PamtreBerry,
    gItemIcon_WatmelBerry,    gItemIconPalette_WatmelBerry,
    gItemIcon_DurinBerry,     gItemIconPalette_DurinBerry,
    gItemIcon_BelueBerry,     gItemIconPalette_BelueBerry,
    gItemIcon_LiechiBerry,    gItemIconPalette_LiechiBerry,
    gItemIcon_GanlonBerry,    gItemIconPalette_GanlonBerry,
    gItemIcon_SalacBerry,     gItemIconPalette_SalacBerry,
    gItemIcon_PetayaBerry,    gItemIconPalette_PetayaBerry,
    gItemIcon_ApicotBerry,    gItemIconPalette_ApicotBerry,
    gItemIcon_LansatBerry,    gItemIconPalette_LansatBerry,
    gItemIcon_StarfBerry,     gItemIconPalette_StarfBerry,
    gItemIcon_EnigmaBerry,    gItemIconPalette_EnigmaBerry,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Hold items
    gItemIcon_BrightPowder,    gItemIconPalette_BrightPowder,
    gItemIcon_InBattleHerb,    gItemIconPalette_WhiteHerb,
    gItemIcon_MachoBrace,      gItemIconPalette_MachoBrace,
    gItemIcon_ExpShare,        gItemIconPalette_ExpShare,
    gItemIcon_QuickClaw,       gItemIconPalette_QuickClaw,
    gItemIcon_SootheBell,      gItemIconPalette_SootheBell,
    gItemIcon_InBattleHerb,    gItemIconPalette_MentalHerb,
    gItemIcon_ChoiceBand,      gItemIconPalette_ChoiceBand,
    gItemIcon_KingsRock,       gItemIconPalette_KingsRock,
    gItemIcon_SilverPowder,    gItemIconPalette_SilverPowder,
    gItemIcon_AmuletCoin,      gItemIconPalette_AmuletCoin,
    gItemIcon_CleanseTag,      gItemIconPalette_CleanseTag,
    gItemIcon_SoulDew,         gItemIconPalette_SoulDew,
    gItemIcon_DeepSeaTooth,    gItemIconPalette_DeepSeaTooth,
    gItemIcon_DeepSeaScale,    gItemIconPalette_DeepSeaScale,
    gItemIcon_SmokeBall,       gItemIconPalette_SmokeBall,
    gItemIcon_Everstone,       gItemIconPalette_Everstone,
    gItemIcon_FocusBand,       gItemIconPalette_FocusBand,
    gItemIcon_LuckyEgg,        gItemIconPalette_LuckyEgg,
    gItemIcon_ScopeLens,       gItemIconPalette_ScopeLens,
    gItemIcon_MetalCoat,       gItemIconPalette_MetalCoat,
    gItemIcon_Leftovers,       gItemIconPalette_Leftovers,
    gItemIcon_DragonScale,     gItemIconPalette_DragonScale,
    gItemIcon_LightBall,       gItemIconPalette_LightBall,
    gItemIcon_SoftSand,        gItemIconPalette_SoftSand,
    gItemIcon_HardStone,       gItemIconPalette_HardStone,
    gItemIcon_MiracleSeed,     gItemIconPalette_MiracleSeed,
    gItemIcon_BlackGlasses,    gItemIconPalette_BlackTypeEnhancingItem,
    gItemIcon_BlackBelt,       gItemIconPalette_BlackTypeEnhancingItem,
    gItemIcon_Magnet,          gItemIconPalette_Magnet,
    gItemIcon_MysticWater,     gItemIconPalette_MysticWater,
    gItemIcon_SharpBeak,       gItemIconPalette_SharpBeak,
    gItemIcon_PoisonBarb,      gItemIconPalette_PoisonBarb,
    gItemIcon_NeverMeltIce,    gItemIconPalette_NeverMeltIce,
    gItemIcon_SpellTag,        gItemIconPalette_SpellTag,
    gItemIcon_TwistedSpoon,    gItemIconPalette_TwistedSpoon,
    gItemIcon_Charcoal,        gItemIconPalette_Charcoal,
    gItemIcon_DragonFang,      gItemIconPalette_DragonFang,
    gItemIcon_SilkScarf,       gItemIconPalette_SilkScarf,
    gItemIcon_UpGrade,         gItemIconPalette_UpGrade,
    gItemIcon_ShellBell,       gItemIconPalette_Shell,
    gItemIcon_SeaIncense,      gItemIconPalette_SeaIncense,
    gItemIcon_LaxIncense,      gItemIconPalette_LaxIncense,
    gItemIcon_LuckyPunch,      gItemIconPalette_LuckyPunch,
    gItemIcon_MetalPowder,     gItemIconPalette_MetalPowder,
    gItemIcon_ThickClub,       gItemIconPalette_ThickClub,
    gItemIcon_Stick,           gItemIconPalette_Stick,
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// Contest hold items
    gItemIcon_Scarf, gItemIconPalette_RedScarf,
    gItemIcon_Scarf, gItemIconPalette_BlueScarf,
    gItemIcon_Scarf, gItemIconPalette_PinkScarf,
    gItemIcon_Scarf, gItemIconPalette_GreenScarf,
    gItemIcon_Scarf, gItemIconPalette_YellowScarf,
// Key items
    gItemIcon_MachBike,         gItemIconPalette_MachBike,
    gItemIcon_CoinCase,         gItemIconPalette_CoinCase,
    gItemIcon_Itemfinder,       gItemIconPalette_Itemfinder,
    gItemIcon_OldRod,           gItemIconPalette_OldRod,
    gItemIcon_GoodRod,          gItemIconPalette_GoodRod,
    gItemIcon_SuperRod,         gItemIconPalette_SuperRod,
    gItemIcon_SSTicket,         gItemIconPalette_SSTicket,
    gItemIcon_ContestPass,      gItemIconPalette_ContestPass,
    gItemIcon_QuestionMark,     gItemIconPalette_QuestionMark,
    gItemIcon_WailmerPail,      gItemIconPalette_WailmerPail,
    gItemIcon_DevonGoods,       gItemIconPalette_DevonGoods,
    gItemIcon_SootSack,         gItemIconPalette_SootSack,
    gItemIcon_BasementKey,      gItemIconPalette_OldKey,
    gItemIcon_AcroBike,         gItemIconPalette_AcroBike,
    gItemIcon_PokeblockCase,    gItemIconPalette_PokeblockCase,
    gItemIcon_Letter,           gItemIconPalette_LavaCookieAndLetter,
    gItemIcon_EonTicket,        gItemIconPalette_EonTicket,
    gItemIcon_Orb,              gItemIconPalette_RedOrb,
    gItemIcon_Orb,              gItemIconPalette_BlueOrb,
    gItemIcon_Scanner,          gItemIconPalette_Scanner,
    gItemIcon_GoGoggles,        gItemIconPalette_GoGoggles,
    gItemIcon_Meteorite,        gItemIconPalette_Meteorite,
    gItemIcon_Room1Key,         gItemIconPalette_Key,
    gItemIcon_Room2Key,         gItemIconPalette_Key,
    gItemIcon_Room4Key,         gItemIconPalette_Key,
    gItemIcon_Room6Key,         gItemIconPalette_Key,
    gItemIcon_StorageKey,       gItemIconPalette_OldKey,
    gItemIcon_RootFossil,       gItemIconPalette_HoennFossil,
    gItemIcon_ClawFossil,       gItemIconPalette_HoennFossil,
    gItemIcon_DevonScope,       gItemIconPalette_DevonScope,
// TMs/HMs
    gItemIcon_TM, gItemIconPalette_FightingTMHM,    // TM01
    gItemIcon_TM, gItemIconPalette_DragonTMHM,      // TM02
    gItemIcon_TM, gItemIconPalette_WaterTMHM,       // TM03
    gItemIcon_TM, gItemIconPalette_PsychicTMHM,     // TM04
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM05
    gItemIcon_TM, gItemIconPalette_PoisonTMHM,      // TM06
    gItemIcon_TM, gItemIconPalette_IceTMHM,         // TM07
    gItemIcon_TM, gItemIconPalette_FightingTMHM,    // TM08
    gItemIcon_TM, gItemIconPalette_GrassTMHM,       // TM09
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM10
    gItemIcon_TM, gItemIconPalette_FireTMHM,        // TM11
    gItemIcon_TM, gItemIconPalette_DarkTMHM,        // TM12
    gItemIcon_TM, gItemIconPalette_IceTMHM,         // TM13
    gItemIcon_TM, gItemIconPalette_IceTMHM,         // TM14
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM15
    gItemIcon_TM, gItemIconPalette_PsychicTMHM,     // TM16
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM17
    gItemIcon_TM, gItemIconPalette_WaterTMHM,       // TM18
    gItemIcon_TM, gItemIconPalette_GrassTMHM,       // TM19
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM20
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM21
    gItemIcon_TM, gItemIconPalette_GrassTMHM,       // TM22
    gItemIcon_TM, gItemIconPalette_SteelTMHM,       // TM23
    gItemIcon_TM, gItemIconPalette_ElectricTMHM,    // TM24
    gItemIcon_TM, gItemIconPalette_ElectricTMHM,    // TM25
    gItemIcon_TM, gItemIconPalette_GroundTMHM,      // TM26
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM27
    gItemIcon_TM, gItemIconPalette_GroundTMHM,      // TM28
    gItemIcon_TM, gItemIconPalette_PsychicTMHM,     // TM29
    gItemIcon_TM, gItemIconPalette_GhostTMHM,       // TM30
    gItemIcon_TM, gItemIconPalette_FightingTMHM,    // TM31
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM32
    gItemIcon_TM, gItemIconPalette_PsychicTMHM,     // TM33
    gItemIcon_TM, gItemIconPalette_ElectricTMHM,    // TM34
    gItemIcon_TM, gItemIconPalette_FireTMHM,        // TM35
    gItemIcon_TM, gItemIconPalette_PoisonTMHM,      // TM36
    gItemIcon_TM, gItemIconPalette_RockTMHM,        // TM37
    gItemIcon_TM, gItemIconPalette_FireTMHM,        // TM38
    gItemIcon_TM, gItemIconPalette_RockTMHM,        // TM39
    gItemIcon_TM, gItemIconPalette_FlyingTMHM,      // TM40
    gItemIcon_TM, gItemIconPalette_DarkTMHM,        // TM41
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM42
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM43
    gItemIcon_TM, gItemIconPalette_PsychicTMHM,     // TM44
    gItemIcon_TM, gItemIconPalette_NormalTMHM,      // TM45
    gItemIcon_TM, gItemIconPalette_DarkTMHM,        // TM46
    gItemIcon_TM, gItemIconPalette_SteelTMHM,       // TM47
    gItemIcon_TM, gItemIconPalette_PsychicTMHM,     // TM48
    gItemIcon_TM, gItemIconPalette_DarkTMHM,        // TM49
    gItemIcon_TM, gItemIconPalette_FireTMHM,        // TM50
    gItemIcon_HM, gItemIconPalette_NormalTMHM,      // HM01
    gItemIcon_HM, gItemIconPalette_FlyingTMHM,      // HM02
    gItemIcon_HM, gItemIconPalette_WaterTMHM,       // HM03
    gItemIcon_HM, gItemIconPalette_NormalTMHM,      // HM04
    gItemIcon_HM, gItemIconPalette_NormalTMHM,      // HM05
    gItemIcon_HM, gItemIconPalette_FightingTMHM,    // HM06
    gItemIcon_HM, gItemIconPalette_WaterTMHM,       // HM07
    gItemIcon_HM, gItemIconPalette_WaterTMHM,       // HM08
// ????????
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
    gItemIcon_QuestionMark, gItemIconPalette_QuestionMark,
// FireRed/LeafGreen key items
    gItemIcon_OaksParcel,      gItemIconPalette_OaksParcel,
    gItemIcon_PokeFlute,       gItemIconPalette_PokeFlute,
    gItemIcon_SecretKey,       gItemIconPalette_SecretKey,
    gItemIcon_BikeVoucher,     gItemIconPalette_BikeVoucher,
    gItemIcon_GoldTeeth,       gItemIconPalette_GoldTeeth,
    gItemIcon_OldAmber,        gItemIconPalette_OldAmber,
    gItemIcon_CardKey,         gItemIconPalette_CardKey,
    gItemIcon_LiftKey,         gItemIconPalette_Key,
    gItemIcon_HelixFossil,     gItemIconPalette_KantoFossil,
    gItemIcon_DomeFossil,      gItemIconPalette_KantoFossil,
    gItemIcon_SilphScope,      gItemIconPalette_SilphScope,
    gItemIcon_Bicycle,         gItemIconPalette_Bicycle,
    gItemIcon_TownMap,         gItemIconPalette_TownMap,
    gItemIcon_VSSeeker,        gItemIconPalette_VSSeeker,
    gItemIcon_FameChecker,     gItemIconPalette_FameChecker,
    gItemIcon_TMCase,          gItemIconPalette_TMCase,
    gItemIcon_BerryPouch,      gItemIconPalette_BerryPouch,
    gItemIcon_TeachyTV,        gItemIconPalette_TeachyTV,
    gItemIcon_TriPass,         gItemIconPalette_TriPass,
    gItemIcon_RainbowPass,     gItemIconPalette_RainbowPass,
    gItemIcon_Tea,             gItemIconPalette_Tea,
    gItemIcon_MysticTicket,    gItemIconPalette_MysticTicket,
    gItemIcon_AuroraTicket,    gItemIconPalette_AuroraTicket,
    gItemIcon_PowderJar,       gItemIconPalette_PowderJar,
    gItemIcon_Gem,             gItemIconPalette_Ruby,
    gItemIcon_Gem,             gItemIconPalette_Sapphire,
// Emerald-only key items
    gItemIcon_MagmaEmblem,     gItemIconPalette_MagmaEmblem,
    gItemIcon_OldSeaMap,       gItemIconPalette_OldSeaMap,
// Return to field arrow
    gItemIcon_ReturnToFieldArrow, gItemIconPalette_ReturnToFieldArrow,
};
#endif // GUARD_DATA_ITEM_ICON_TABLE_H
