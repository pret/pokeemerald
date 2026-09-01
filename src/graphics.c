#include "global.h"
#include "graphics.h"

const u32 gBattleTextboxTiles[] = INCGFX_U32("graphics/battle_interface/textbox.png", ".4bpp.smol");
const u16 gBattleTextboxPalette[] = INCBIN_U16("graphics/battle_interface/textbox.gbapal");
const u32 gBattleTextboxTilemap[] = INCGFX_U32("graphics/battle_interface/textbox_map.bin", ".smolTM");

const u32 gUnusedGfx_OldCharmap[] = INCGFX_U32("graphics/unused/old_charmap.png", ".4bpp.smol"); // japanese table and bunch of stuff
const u32 gUnusedTimemap_OldCharmap[] = INCGFX_U32("graphics/unused/old_charmap.bin", ".smolTM");
const u16 gUnusedPal_OldCharmap[] = INCGFX_U16("graphics/unused/old_charmap.png", ".gbapal");

const u32 gSmokescreenImpactTiles[] = INCGFX_U32("graphics/battle_anims/sprites/smokescreen_impact.png", ".4bpp.smol");
const u16 gSmokescreenImpactPalette[] = INCGFX_U16("graphics/battle_anims/sprites/smokescreen_impact.png", ".gbapal");

#include "data/graphics/pokeballs.h"

const u32 gBlankGfxCompressed[] = INCGFX_U32("graphics/interface/blank.png", ".4bpp.smol");

// New Battle anims Particles
const u32 gBattleAnimSpriteGfx_WhiteStreak[] = INCGFX_U32("graphics/battle_anims/sprites/white_streak.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WhiteStreak[] = INCGFX_U16("graphics/battle_anims/sprites/white_streak.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleJab[] = INCGFX_U32("graphics/battle_anims/sprites/purple_jab.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleJab[] = INCGFX_U16("graphics/battle_anims/sprites/purple_jab.png", ".gbapal");

const u16 gBattleAnimSpritePal_ToxicSpikes[] = INCGFX_U16("graphics/battle_anims/sprites/toxic_spikes.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_EnergyBall[] = INCGFX_U32("graphics/battle_anims/sprites/energy_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_EnergyBall[] = INCGFX_U16("graphics/battle_anims/sprites/energy_ball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MegaStone[] = INCGFX_U32("graphics/battle_anims/sprites/mega_stone.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MegaStone[] = INCGFX_U16("graphics/battle_anims/sprites/mega_stone.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MegaParticles[] = INCGFX_U32("graphics/battle_anims/sprites/mega_particles.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MegaParticles[] = INCGFX_U16("graphics/battle_anims/sprites/mega_particles.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MegaSymbol[] = INCGFX_U32("graphics/battle_anims/sprites/mega_symbol.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MegaSymbol[] = INCGFX_U16("graphics/battle_anims/sprites/mega_symbol.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_AlphaSymbol[] = INCGFX_U32("graphics/battle_anims/sprites/alpha_symbol.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AlphaSymbol[] = INCGFX_U16("graphics/battle_anims/sprites/alpha_symbol.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_OmegaSymbol[] = INCGFX_U32("graphics/battle_anims/sprites/omega_symbol.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_OmegaSymbol[] = INCGFX_U16("graphics/battle_anims/sprites/omega_symbol.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TeraSymbol[] = INCGFX_U32("graphics/battle_anims/sprites/tera_symbol.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TeraSymbol[] = INCGFX_U16("graphics/battle_anims/sprites/tera_symbol.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_FlashCannonBall[] = INCGFX_U32("graphics/battle_anims/sprites/flash_cannon_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_FlashCannonBall[] = INCGFX_U16("graphics/battle_anims/sprites/flash_cannon_ball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WaterGun[] = INCGFX_U32("graphics/battle_anims/sprites/water_gun.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WaterGun[] = INCGFX_U16("graphics/battle_anims/sprites/water_gun.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Punishment[] = INCGFX_U32("graphics/battle_anims/sprites/punishment.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Punishment[] = INCGFX_U16("graphics/battle_anims/sprites/punishment.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_QuickGuard[] = INCGFX_U32("graphics/battle_anims/sprites/quick_guard.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_QuickGuard[] = INCGFX_U16("graphics/battle_anims/sprites/quick_guard.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_AlphaStone[] = INCGFX_U32("graphics/battle_anims/sprites/alpha_stone.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AlphaStone[] = INCGFX_U16("graphics/battle_anims/sprites/alpha_stone.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TeraCrystal[] = INCGFX_U32("graphics/battle_anims/sprites/tera_crystal.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TeraCrystal[] = INCGFX_U16("graphics/battle_anims/sprites/tera_crystal.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TeraShatter[] = INCGFX_U32("graphics/battle_anims/sprites/tera_shatter.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TeraShatter[] = INCGFX_U16("graphics/battle_anims/sprites/tera_shatter.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Anchor[] = INCGFX_U32("graphics/battle_anims/sprites/anchor.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Apple[] = INCGFX_U32("graphics/battle_anims/sprites/apple.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Apple[] = INCGFX_U16("graphics/battle_anims/sprites/apple.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Arrows[] = INCGFX_U32("graphics/battle_anims/sprites/arrows.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_AssuranceHand[] = INCGFX_U32("graphics/battle_anims/sprites/assurance_hand.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AssuranceHand[] = INCGFX_U16("graphics/battle_anims/sprites/assurance_hand.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_AuraSphere[] = INCGFX_U32("graphics/battle_anims/sprites/aura_sphere.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AuraSphere[] = INCGFX_U16("graphics/battle_anims/sprites/aura_sphere.png", ".gbapal");

const u16 gBattleAnimSpritePal_AvalancheRocks[] = INCGFX_U16("graphics/battle_anims/sprites/avalanche_rocks.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewPokeball[] = INCGFX_U32("graphics/battle_anims/sprites/baton_pass_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewPokeball[] = INCGFX_U16("graphics/battle_anims/sprites/baton_pass_ball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Beam[] = INCGFX_U32("graphics/battle_anims/sprites/beam.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Beam[] = INCGFX_U16("graphics/battle_anims/sprites/beam.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BerryEaten[] = INCGFX_U32("graphics/battle_anims/sprites/berry_eaten.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BerryEaten[] = INCGFX_U16("graphics/battle_anims/sprites/berry_eaten.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BerryNormal[] = INCGFX_U32("graphics/battle_anims/sprites/berry_normal.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BerryNormal[] = INCGFX_U16("graphics/battle_anims/sprites/berry_normal.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BigRock[] = INCGFX_U32("graphics/battle_anims/sprites/big_rock.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BigRock[] = INCGFX_U16("graphics/battle_anims/sprites/big_rock.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BlacephalonHead[] = INCGFX_U32("graphics/battle_anims/sprites/blacephalon_head.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlacephalonHead[] = INCGFX_U16("graphics/battle_anims/sprites/blacephalon_head.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BloodMoon[] = INCGFX_U32("graphics/battle_anims/sprites/blood_moon.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BloodMoon[] = INCGFX_U16("graphics/battle_anims/sprites/blood_moon.png", ".gbapal");

const u16 gBattleAnimSpritePal_BlueFlare[] = INCGFX_U16("graphics/battle_anims/sprites/blue_flare.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_Branch[] = INCGFX_U32("graphics/battle_anims/sprites/branch.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Branch[] = INCGFX_U16("graphics/battle_anims/sprites/branch.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Brine[] = INCGFX_U32("graphics/battle_anims/sprites/brine.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Brine[] = INCGFX_U16("graphics/battle_anims/sprites/brine.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ChainLink[] = INCGFX_U32("graphics/battle_anims/sprites/chain_link.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ChainLink[] = INCGFX_U16("graphics/battle_anims/sprites/chain_link.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Chop[] = INCGFX_U32("graphics/battle_anims/sprites/chop.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Chop[] = INCGFX_U16("graphics/battle_anims/sprites/chop.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Cacoon[] = INCGFX_U32("graphics/battle_anims/sprites/cacoon.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Cacoon[] = INCGFX_U16("graphics/battle_anims/sprites/cacoon.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Confide[] = INCGFX_U32("graphics/battle_anims/sprites/confide.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Confide[] = INCGFX_U16("graphics/battle_anims/sprites/confide.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_CraftyShield[] = INCGFX_U32("graphics/battle_anims/sprites/crafty_shield.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_CraftyShield[] = INCGFX_U16("graphics/battle_anims/sprites/crafty_shield.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewNail[] = INCGFX_U32("graphics/battle_anims/sprites/curse_nail.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewNail[] = INCGFX_U16("graphics/battle_anims/sprites/curse_nail.png", ".gbapal");

const u16 gBattleAnimSpritePal_DracoMeteor[] = INCGFX_U16("graphics/battle_anims/sprites/draco_meteor.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_DragonPulseRing[] = INCGFX_U32("graphics/battle_anims/sprites/dragon_pulse_ring.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_DragonPulseRing[] = INCGFX_U16("graphics/battle_anims/sprites/dragon_pulse_ring.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_DreepyMissile[] = INCGFX_U32("graphics/battle_anims/sprites/dreepy_missile.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_DreepyMissile[] = INCGFX_U16("graphics/battle_anims/sprites/dreepy_missile.pal", ".gbapal");
const u32 gBattleAnimSpriteGfx_DreepyMissileShiny[] = INCGFX_U32("graphics/battle_anims/sprites/dreepy_missile.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_DreepyMissileShiny[] = INCGFX_U16("graphics/battle_anims/sprites/dreepy_missile_shiny.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_Drill[] = INCGFX_U32("graphics/battle_anims/sprites/drill.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Drill[] = INCGFX_U16("graphics/battle_anims/sprites/drill.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewEmbers[] = INCGFX_U32("graphics/battle_anims/sprites/embers.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewEmbers[] = INCGFX_U16("graphics/battle_anims/sprites/embers.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_FairyLockChains[] = INCGFX_U32("graphics/battle_anims/sprites/fairy_lock_chains.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Fishies[] = INCGFX_U32("graphics/battle_anims/sprites/fishies.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Fishies[] = INCGFX_U16("graphics/battle_anims/sprites/fishies.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewFly[] = INCGFX_U32("graphics/battle_anims/sprites/fly.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewFly[] = INCGFX_U16("graphics/battle_anims/sprites/fly.png", ".gbapal");

const u16 gBattleAnimSpritePal_FusionFlare[] = INCGFX_U16("graphics/battle_anims/sprites/fusion_flare.pal", ".gbapal");

const u16 gBattleAnimSpritePal_GarbagePoisonPillar[] = INCGFX_U16("graphics/battle_anims/sprites/garbage_poison_column.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_Gear[] = INCGFX_U32("graphics/battle_anims/sprites/gear.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Gear[] = INCGFX_U16("graphics/battle_anims/sprites/gear.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GigavoltHavocSpear[] = INCGFX_U32("graphics/battle_anims/sprites/gigavolt_havoc_spear.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GigavoltHavocSpear[] = INCGFX_U16("graphics/battle_anims/sprites/gigavolt_havoc_spear.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GoldenApple[] = INCGFX_U32("graphics/battle_anims/sprites/golden_apple.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GoldenApple[] = INCGFX_U16("graphics/battle_anims/sprites/golden_apple.png", ".gbapal");

const u16 gBattleAnimSpritePal_GreenDrake[] = INCGFX_U16("graphics/battle_anims/sprites/green_drake.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewGreenStar[] = INCGFX_U32("graphics/battle_anims/sprites/green_star_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewGreenStar[] = INCGFX_U16("graphics/battle_anims/sprites/green_star_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HeartStamp[] = INCGFX_U32("graphics/battle_anims/sprites/heart_stamp.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HeartStamp[] = INCGFX_U16("graphics/battle_anims/sprites/heart_stamp.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ZygardeHexes[] = INCGFX_U32("graphics/battle_anims/sprites/hexes.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ZygardeHexes[] = INCGFX_U16("graphics/battle_anims/sprites/hexes.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HoopaHand[] = INCGFX_U32("graphics/battle_anims/sprites/hoopa_hand.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HoopaHand[] = INCGFX_U16("graphics/battle_anims/sprites/hoopa_hand.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HoopaRing[] = INCGFX_U32("graphics/battle_anims/sprites/hoopa_ring.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HoopaRing[] = INCGFX_U16("graphics/battle_anims/sprites/hoopa_ring.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewHornHit[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewHornHit[] = INCGFX_U16("graphics/battle_anims/sprites/horn_hit_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HornLeech[] = INCGFX_U32("graphics/battle_anims/sprites/horn_leech.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HornLeech[] = INCGFX_U16("graphics/battle_anims/sprites/horn_leech.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HorseshoeFist[] = INCGFX_U32("graphics/battle_anims/sprites/horseshoe_fist.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HorseshoeFist[] = INCGFX_U16("graphics/battle_anims/sprites/horseshoe_fist.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HydroPump[] = INCGFX_U32("graphics/battle_anims/sprites/hydro_pump.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HydroPump[] = INCGFX_U16("graphics/battle_anims/sprites/hydro_pump.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_IceRock[] = INCGFX_U32("graphics/battle_anims/sprites/ice_rock.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_IceRock[] = INCGFX_U16("graphics/battle_anims/sprites/ice_rock.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_LargeSpike[] = INCGFX_U32("graphics/battle_anims/sprites/large_spike.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_LargeSpike[] = INCGFX_U16("graphics/battle_anims/sprites/large_spike.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewLeaf[] = INCGFX_U32("graphics/battle_anims/sprites/leaves.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewLeaf[] = INCGFX_U16("graphics/battle_anims/sprites/leaves.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewLeechSeed[] = INCGFX_U32("graphics/battle_anims/sprites/leech_seed.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewLeechSeed[] = INCGFX_U16("graphics/battle_anims/sprites/leech_seed.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_LightningRain[] = INCGFX_U32("graphics/battle_anims/sprites/lightning_rain.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_LightningRain[] = INCGFX_U16("graphics/battle_anims/sprites/lightning_rain.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewEye[] = INCGFX_U32("graphics/battle_anims/sprites/mean_look.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewEye[] = INCGFX_U16("graphics/battle_anims/sprites/mean_look.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MetalBits[] = INCGFX_U32("graphics/battle_anims/sprites/metal_bits.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_MudBomb[] = INCGFX_U32("graphics/battle_anims/sprites/mud_bomb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MudBomb[] = INCGFX_U16("graphics/battle_anims/sprites/mud_bomb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Mushroom[] = INCGFX_U32("graphics/battle_anims/sprites/mushroom.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Mushroom[] = INCGFX_U16("graphics/battle_anims/sprites/mushroom.png", ".gbapal");

const u16 gBattleAnimSpritePal_NaturalGiftRing[] = INCGFX_U16("graphics/battle_anims/sprites/natural_gift_ring.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_NecrozmaStar[] = INCGFX_U32("graphics/battle_anims/sprites/necrozma_star.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NecrozmaStar[] = INCGFX_U16("graphics/battle_anims/sprites/necrozma_star.png", ".gbapal");

const u16 gBattleAnimSpritePal_NewImpact[] = INCGFX_U16("graphics/battle_anims/sprites/impact_new.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_Obstruct[] = INCGFX_U32("graphics/battle_anims/sprites/obstruct.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Obstruct[] = INCGFX_U16("graphics/battle_anims/sprites/obstruct.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_OmegaStone[] = INCGFX_U32("graphics/battle_anims/sprites/omega_stone.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_OmegaStone[] = INCGFX_U16("graphics/battle_anims/sprites/omega_stone.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PinkDiamond[] = INCGFX_U32("graphics/battle_anims/sprites/pink_diamond.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PinkDiamond[] = INCGFX_U16("graphics/battle_anims/sprites/pink_diamond.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PoisonColumn[] = INCGFX_U32("graphics/battle_anims/sprites/poison_column.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PoisonColumn[] = INCGFX_U16("graphics/battle_anims/sprites/poison_column.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PowerTrick[] = INCGFX_U32("graphics/battle_anims/sprites/power_trick.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PowerTrick[] = INCGFX_U16("graphics/battle_anims/sprites/power_trick.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleChain[] = INCGFX_U32("graphics/battle_anims/sprites/purple_chain.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleChain[] = INCGFX_U16("graphics/battle_anims/sprites/purple_chain.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleDrake[] = INCGFX_U32("graphics/battle_anims/sprites/purple_drake.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleDrake[] = INCGFX_U16("graphics/battle_anims/sprites/purple_drake.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RazorShell[] = INCGFX_U32("graphics/battle_anims/sprites/razor_shell.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RazorShell[] = INCGFX_U16("graphics/battle_anims/sprites/razor_shell.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RedExplosion[] = INCGFX_U32("graphics/battle_anims/sprites/red_explosion.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RedExplosion[] = INCGFX_U16("graphics/battle_anims/sprites/red_explosion.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RocksSmall[] = INCGFX_U32("graphics/battle_anims/sprites/rock_small.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_NewRocks[] = INCGFX_U32("graphics/battle_anims/sprites/rocks_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewRocks[] = INCGFX_U16("graphics/battle_anims/sprites/rocks_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ShellLeft[] = INCGFX_U32("graphics/battle_anims/sprites/shell_left.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ShellLeft[] = INCGFX_U16("graphics/battle_anims/sprites/shell_left.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ShellRight[] = INCGFX_U32("graphics/battle_anims/sprites/shell_right.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_SpacialRendSlices[] = INCGFX_U16("graphics/battle_anims/sprites/spacial_rend_slices.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewSpikes[] = INCGFX_U32("graphics/battle_anims/sprites/spikes_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewSpikes[] = INCGFX_U16("graphics/battle_anims/sprites/spikes_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SpiritShackleArrow[] = INCGFX_U32("graphics/battle_anims/sprites/spirit_shackle_arrow.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SpiritShackleArrow[] = INCGFX_U16("graphics/battle_anims/sprites/spirit_shackle_arrow.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SteamEruption[] = INCGFX_U32("graphics/battle_anims/sprites/steam_eruption.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SteamEruption[] = INCGFX_U16("graphics/battle_anims/sprites/steam_eruption.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Steamroller[] = INCGFX_U32("graphics/battle_anims/sprites/steamroller.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Steamroller[] = INCGFX_U16("graphics/battle_anims/sprites/steamroller.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_StonePillar[] = INCGFX_U32("graphics/battle_anims/sprites/stone_pillar.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_StonePillar[] = INCGFX_U16("graphics/battle_anims/sprites/stone_pillar.png", ".gbapal");

const u16 gBattleAnimSpritePal_Poltergeist[] = INCGFX_U16("graphics/battle_anims/sprites/poltergeist.pal", ".gbapal");

const u16 gBattleAnimSpritePal_SteelBeam[] = INCGFX_U16("graphics/battle_anims/sprites/steel_beam.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_StraightBeam[] = INCGFX_U32("graphics/battle_anims/sprites/straight_beam.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_StraightBeam[] = INCGFX_U16("graphics/battle_anims/sprites/straight_beam.png", ".gbapal");

const u16 gBattleAnimSpritePal_NewSurf[] = INCGFX_U16("graphics/battle_anims/sprites/surf_new.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewSword[] = INCGFX_U32("graphics/battle_anims/sprites/sword_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewSword[] = INCGFX_U16("graphics/battle_anims/sprites/sword_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewTeeth[] = INCGFX_U32("graphics/battle_anims/sprites/teeth_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewTeeth[] = INCGFX_U16("graphics/battle_anims/sprites/teeth_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_NewHandsAndFeet[] = INCGFX_U32("graphics/battle_anims/sprites/hands_and_feet_new.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_NewHandsAndFeet[] = INCGFX_U16("graphics/battle_anims/sprites/hands_and_feet_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Tornado[] = INCGFX_U32("graphics/battle_anims/sprites/tornado.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Tornado[] = INCGFX_U16("graphics/battle_anims/sprites/tornado.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ZMoveSymbol[] = INCGFX_U32("graphics/battle_anims/sprites/z_move_symbol.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ZMoveSymbol[] = INCGFX_U16("graphics/battle_anims/sprites/z_move_symbol.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Teapot[] = INCGFX_U32("graphics/battle_anims/sprites/new/teapot.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Teapot[] = INCGFX_U16("graphics/battle_anims/sprites/new/teapot.pal", ".gbapal");

// Battle anims
const u32 gBattleAnimSpriteGfx_Bubble[] = INCGFX_U32("graphics/battle_anims/sprites/bubble.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Bone[] = INCGFX_U32("graphics/battle_anims/sprites/bone.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_AirWave[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Orb[] = INCGFX_U32("graphics/battle_anims/sprites/orb.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Sword[] = INCGFX_U32("graphics/battle_anims/sprites/sword.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Seed[] = INCGFX_U32("graphics/battle_anims/sprites/seed.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_SeedBrown[] = INCGFX_U32("graphics/battle_anims/sprites/seed_new.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_RainDrops[] = INCGFX_U16("graphics/battle_anims/sprites/rain_drops.png", ".gbapal");
const u16 gBattleAnimSpritePal_Bone[] = INCGFX_U16("graphics/battle_anims/sprites/bone.png", ".gbapal");
const u16 gBattleAnimSpritePal_AirWave[] = INCGFX_U16("graphics/battle_anims/sprites/air_wave.png", ".gbapal");
const u16 gBattleAnimSpritePal_Orb[] = INCGFX_U16("graphics/battle_anims/sprites/orb.png", ".gbapal");
const u16 gBattleAnimSpritePal_Sword[] = INCGFX_U16("graphics/battle_anims/sprites/sword.png", ".gbapal");
const u16 gBattleAnimSpritePal_Seed[] = INCGFX_U16("graphics/battle_anims/sprites/seed.png", ".gbapal");
const u16 gBattleAnimSpritePal_SeedBrown[] = INCGFX_U16("graphics/battle_anims/sprites/seed_new.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Needle[] = INCGFX_U32("graphics/battle_anims/sprites/needle.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Needle[] = INCGFX_U16("graphics/battle_anims/sprites/needle.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Explosion6[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_6.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Explosion6[] = INCGFX_U16("graphics/battle_anims/sprites/explosion_6.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PinkOrb[] = INCGFX_U32("graphics/battle_anims/sprites/pink_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PinkOrb[] = INCGFX_U16("graphics/battle_anims/sprites/pink_orb.png", ".gbapal");

const u16 gBattleAnimSpritePal_IceCube[] = INCGFX_U16("graphics/battle_anims/sprites/ice_cube.pal", ".gbapal");
const u32 gBattleAnimSpriteGfx_IceCube[] = INCGFX_U32("graphics/battle_anims/sprites/ice_cube.4bpp", ".smol");

const u32 gBattleAnimSpriteGfx_Gust[] = INCGFX_U32("graphics/battle_anims/sprites/gust.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Gust[] = INCGFX_U16("graphics/battle_anims/sprites/gust.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Spark2[] = INCGFX_U32("graphics/battle_anims/sprites/spark_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Spark2[] = INCGFX_U16("graphics/battle_anims/sprites/spark_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Orange[] = INCGFX_U32("graphics/battle_anims/sprites/orange.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Orange[] = INCGFX_U16("graphics/battle_anims/sprites/orange.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Spikes[] = INCGFX_U32("graphics/battle_anims/sprites/spikes.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Spikes[] = INCGFX_U16("graphics/battle_anims/sprites/spikes.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_YellowBall[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_YellowBall[] = INCGFX_U16("graphics/battle_anims/sprites/yellow_ball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TiedBag[] = INCGFX_U32("graphics/battle_anims/sprites/tied_bag.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TiedBag[] = INCGFX_U16("graphics/battle_anims/sprites/tied_bag.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BlackSmoke[] = INCGFX_U32("graphics/battle_anims/sprites/black_smoke.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlackSmoke[] = INCGFX_U16("graphics/battle_anims/sprites/black_smoke.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BlackBall[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlackBall[] = INCGFX_U16("graphics/battle_anims/sprites/black_ball.pal", ".gbapal");

const u16 gBattleAnimSpritePal_Glass[] = INCGFX_U16("graphics/battle_anims/sprites/glass.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Glass[] = INCGFX_U32("graphics/battle_anims/sprites/glass.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_HornHit[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HornHit[] = INCGFX_U16("graphics/battle_anims/sprites/horn_hit.png", ".gbapal");

const u16 gBattleAnimSpritePal_BlueShards[] = INCGFX_U16("graphics/battle_anims/sprites/blue_shards.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_BlueShards[] = INCGFX_U32("graphics/battle_anims/sprites/blue_shards.png", ".4bpp.smol");

const u16 gBattleAnimUnusedPal_MusicNotes[] = INCGFX_U16("graphics/battle_anims/unused/music_notes.pal", ".gbapal");
const u32 gBattleAnimUnusedGfx_MusicNotes[] = INCGFX_U32("graphics/battle_anims/unused/music_notes.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Hit[] = INCGFX_U16("graphics/battle_anims/sprites/hit.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Hit[] = INCGFX_U32("graphics/battle_anims/sprites/hit.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Hit2[] = INCGFX_U16("graphics/battle_anims/sprites/hit_2.pal", ".gbapal");

const u16 gBattleAnimSpritePal_WavingHand[] = INCGFX_U16("graphics/battle_anims/sprites/waving_hand.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_WavingHand[] = INCGFX_U32("graphics/battle_anims/sprites/waving_hand.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Feint[] = INCGFX_U32("graphics/battle_anims/sprites/feint_punch.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Feint[] = INCGFX_U16("graphics/battle_anims/sprites/feint_punch.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TrumpCard[] = INCGFX_U32("graphics/battle_anims/sprites/trump_cards.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TrumpCard[] = INCGFX_U16("graphics/battle_anims/sprites/trump_cards.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TrumpCardParticles[] = INCGFX_U32("graphics/battle_anims/sprites/trump_card_particles.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TrumpCardParticles[] = INCGFX_U16("graphics/battle_anims/sprites/trump_card_particles.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Acupressure[] = INCGFX_U32("graphics/battle_anims/sprites/acupressure.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Acupressure[] = INCGFX_U16("graphics/battle_anims/sprites/acupressure.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WringOut[] = INCGFX_U32("graphics/battle_anims/sprites/wring_out.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WringOut[] = INCGFX_U16("graphics/battle_anims/sprites/wring_out.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ClosingEye[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ClosingEye[] = INCGFX_U16("graphics/battle_anims/sprites/closing_eye.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BlueStar[] = INCGFX_U32("graphics/battle_anims/sprites/blue_star.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlueStar[] = INCGFX_U16("graphics/battle_anims/sprites/blue_star.png", ".gbapal");

const u16 gBattleAnimSpritePal_BubbleBurst[] = INCGFX_U16("graphics/battle_anims/sprites/bubble_burst.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_BubbleBurst[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_HitDuplicate[] = INCGFX_U32("graphics/battle_anims/sprites/hit_duplicate.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HitDuplicate[] = INCGFX_U16("graphics/battle_anims/sprites/hit_duplicate.png", ".gbapal");

const u16 gBattleAnimSpritePal_Leer[] = INCGFX_U16("graphics/battle_anims/sprites/leer.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Leer[] = INCGFX_U32("graphics/battle_anims/sprites/leer.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_BlueBurst[] = INCGFX_U16("graphics/battle_anims/sprites/blue_burst.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_BlueBurst[] = INCGFX_U32("graphics/battle_anims/sprites/blue_burst.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_SmallEmber[] = INCGFX_U32("graphics/battle_anims/sprites/small_ember.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SmallEmber[] = INCGFX_U16("graphics/battle_anims/sprites/small_ember.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GraySmoke[] = INCGFX_U32("graphics/battle_anims/sprites/gray_smoke.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GraySmoke[] = INCGFX_U16("graphics/battle_anims/sprites/gray_smoke.png", ".gbapal");

const u16 gBattleAnimSpritePal_Fire[] = INCGFX_U16("graphics/battle_anims/sprites/fire.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Fire[] = INCGFX_U32("graphics/battle_anims/sprites/fire.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_SpinningFire[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_fire.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_FirePlume[] = INCGFX_U32("graphics/battle_anims/sprites/fire_plume.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Lightning2[] = INCGFX_U16("graphics/battle_anims/sprites/lightning_2.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Lightning2[] = INCGFX_U32("graphics/battle_anims/sprites/lightning_2.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Lightning[] = INCGFX_U32("graphics/battle_anims/sprites/lightning.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_ColoredOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/colored_orbs.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ColoredOrbs[] = INCGFX_U16("graphics/battle_anims/sprites/colored_orbs.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WorrySeed[] = INCGFX_U32("graphics/battle_anims/sprites/worry_seed.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WorrySeed[] = INCGFX_U16("graphics/battle_anims/sprites/worry_seed.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SmallCloud[] = INCGFX_U32("graphics/battle_anims/sprites/small_cloud.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SmallCloud[] = INCGFX_U16("graphics/battle_anims/sprites/small_cloud.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_AttackOrder[] = INCGFX_U32("graphics/battle_anims/sprites/attack_order.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AttackOrder[] = INCGFX_U16("graphics/battle_anims/sprites/attack_order.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_DragonPulse[] = INCGFX_U32("graphics/battle_anims/sprites/dragon_pulse.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_DragonPulse[] = INCGFX_U16("graphics/battle_anims/sprites/dragon_pulse.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WoodHammer[] = INCGFX_U32("graphics/battle_anims/sprites/wood_hammer.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WoodHammer[] = INCGFX_U16("graphics/battle_anims/sprites/wood_hammer.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PsychoCut[] = INCGFX_U32("graphics/battle_anims/sprites/psycho_cut.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PsychoCut[] = INCGFX_U16("graphics/battle_anims/sprites/psycho_cut.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PowerGem[] = INCGFX_U32("graphics/battle_anims/sprites/power_gem.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PowerGem[] = INCGFX_U16("graphics/battle_anims/sprites/power_gem.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_StoneEdge[] = INCGFX_U32("graphics/battle_anims/sprites/stone_edge.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_StoneEdge[] = INCGFX_U16("graphics/battle_anims/sprites/stone_edge.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_StealthRock[] = INCGFX_U32("graphics/battle_anims/sprites/stealth_rock.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_StealthRock[] = INCGFX_U16("graphics/battle_anims/sprites/stealth_rock.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PoisonJab[] = INCGFX_U32("graphics/battle_anims/sprites/poison_jab.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PoisonJab[] = INCGFX_U16("graphics/battle_anims/sprites/poison_jab.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SpinningBall[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SpinningBall[] = INCGFX_U16("graphics/battle_anims/unused/spinning_ball.png", ".gbapal");
const u16 gBattleAnimSpritePal_SpinningBall2[] = INCGFX_U16("graphics/battle_anims/unused/spinning_ball_2.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_WoodHammerHammer[] = INCGFX_U32("graphics/battle_anims/sprites/wood_hammer_hammer.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WoodHammerHammer[] = INCGFX_U16("graphics/battle_anims/sprites/wood_hammer_hammer.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Snowflakes[] = INCGFX_U32("graphics/battle_anims/sprites/snowflakes.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Snowflakes[] = INCGFX_U16("graphics/battle_anims/sprites/snowflakes.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SyrupBlob[] = INCGFX_U32("graphics/battle_anims/sprites/syrup_bomb_blob.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_SyrupShell[] = INCGFX_U32("graphics/battle_anims/sprites/syrup_bomb_shell.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_SyrupSplat[] = INCGFX_U32("graphics/battle_anims/sprites/syrup_bomb_splat.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SyrupRed[] = INCGFX_U16("graphics/battle_anims/sprites/syrup_red.pal", ".gbapal");
const u16 gBattleAnimSpritePal_SyrupYellow[] = INCGFX_U16("graphics/battle_anims/sprites/syrup_yellow.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_IvyCudgel[] = INCGFX_U32("graphics/battle_anims/sprites/cudgel.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_IvyCudgelGrass[] = INCGFX_U16("graphics/pokemon/ogerpon/normal.pal", ".gbapal");
const u16 gBattleAnimSpritePal_IvyCudgelFire[] = INCGFX_U16("graphics/pokemon/ogerpon/hearthflame/normal.pal", ".gbapal");
const u16 gBattleAnimSpritePal_IvyCudgelRock[] = INCGFX_U16("graphics/pokemon/ogerpon/cornerstone/normal.pal", ".gbapal");
const u16 gBattleAnimSpritePal_IvyCudgelWater[] = INCGFX_U16("graphics/pokemon/ogerpon/wellspring/normal.pal", ".gbapal");

// old battle interface data, unused

const u32 gOldBattleInterfaceGfx[] = INCGFX_U32("graphics/unused/obi1.4bpp", ".smol");
const u16 gOldBattleInterfacePal_1_2_3[] = INCBIN_U16("graphics/unused/obi_palpak1.gbapal"); // palettes 1-3
const u16 gOldBattleInterfacePal4[] = INCGFX_U16("graphics/unused/old_pal4.pal", ".gbapal"); // 4 is by itself
const u16 gOldBattleInterfacePal_5_6_7[] = INCBIN_U16("graphics/unused/obi_palpak3.gbapal"); // palettes 5-7
const u32 gOldBattleInterfaceGfx2[] = INCGFX_U32("graphics/unused/obi2.4bpp", ".smol");
const u32 gOldBattleInterfaceTilemap[] = INCGFX_U32("graphics/unused/old_battle_interface_tilemap.bin", ".smolTM");

const u16 gBattleAnimSpritePal_ClawSlash2[] = INCGFX_U16("graphics/battle_anims/sprites/claw_slash_2.png", ".gbapal");
const u16 gBattleAnimSpritePal_ClawSlash[] = INCGFX_U16("graphics/battle_anims/sprites/claw_slash.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ClawSlash2[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash_2.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_ClawSlash[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Scratch3[] = INCGFX_U32("graphics/battle_anims/sprites/scratch_3.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Scratch2[] = INCGFX_U32("graphics/battle_anims/sprites/scratch_2.png", ".4bpp.smol");

const u32 gUnusedHpBar_Gfx[] = INCGFX_U32("graphics/battle_interface/hpbar_unused.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_BubbleBurst2[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst_2.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_BubbleBurst2[] = INCGFX_U16("graphics/battle_anims/sprites/bubble_burst_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_IceChunk[] = INCGFX_U32("graphics/battle_anims/sprites/ice_chunk.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_IceChunk[] = INCGFX_U16("graphics/battle_anims/sprites/ice_chunk.png", ".gbapal");

const u16 gBattleAnimSpritePal_Glass2[] = INCGFX_U16("graphics/battle_anims/sprites/glass_2.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Glass2[] = INCGFX_U32("graphics/battle_anims/sprites/glass_2.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_PinkHeart2[] = INCGFX_U16("graphics/battle_anims/sprites/pink_heart_2.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_PinkHeart2[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart_2.png", ".4bpp.smol");

const u32 gBattleInterfaceGfx_UnusedWindow1[] = INCGFX_U32("graphics/battle_interface/unused_window.png", ".4bpp.smol");
const u16 gBattleInterfacePal_UnusedWindow1[] = INCGFX_U16("graphics/battle_interface/unused_window.png", ".gbapal");

const u32 gBattleInterfaceGfx_BattleBar[] = INCGFX_U32("graphics/battle_interface/battle_bar.4bpp", ".smol");

const u32 gBattleAnimSpriteGfx_SapDrip[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SapDrip[] = INCGFX_U16("graphics/battle_anims/sprites/sap_drip.png", ".gbapal");

const u16 gBattleAnimSpritePal_SapDrip2[] = INCGFX_U16("graphics/battle_anims/sprites/sap_drip_2.pal", ".gbapal");

const u32 gBattleInterfaceGfx_UnusedWindow2[] = INCGFX_U32("graphics/battle_interface/unused_window2.png", ".4bpp.smol");
const u32 gBattleInterfaceGfx_UnusedWindow2Bar[] = INCGFX_U32("graphics/battle_interface/unused_window2bar.png", ".4bpp.smol", "-num_tiles 5 -Wnum_tiles");

const u32 gBattleAnimSpriteGfx_Sparkle1[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_1.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Sparkle1[] = INCGFX_U16("graphics/battle_anims/sprites/sparkle_1.png", ".gbapal");

const u16 gBattleAnimSpritePal_Sparkle2[] = INCGFX_U16("graphics/battle_anims/sprites/sparkle_2.pal", ".gbapal");
const u16 gBattleAnimSpritePal_HumanoidFoot[] = INCGFX_U16("graphics/battle_anims/sprites/humanoid_foot.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HumanoidFoot[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_foot.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_MonsterFoot[] = INCGFX_U32("graphics/battle_anims/sprites/monster_foot.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_HumanoidHand[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_hand.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_LineSketch[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_LineSketch[] = INCGFX_U16("graphics/battle_anims/unused/line_sketch.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_YellowUnk[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_YellowUnk[] = INCGFX_U16("graphics/battle_anims/sprites/yellow_unk.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SlamHit[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SlamHit[] = INCGFX_U16("graphics/battle_anims/sprites/slam_hit.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RedFist[] = INCGFX_U32("graphics/battle_anims/sprites/red_fist.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Ring[] = INCGFX_U32("graphics/battle_anims/sprites/ring.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Ring[] = INCGFX_U16("graphics/battle_anims/sprites/ring.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Rocks[] = INCGFX_U32("graphics/battle_anims/sprites/rocks.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Rocks[] = INCGFX_U16("graphics/battle_anims/sprites/rocks.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Z[] = INCGFX_U32("graphics/battle_anims/sprites/z.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Z[] = INCGFX_U16("graphics/battle_anims/sprites/z.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_YellowUnk2[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_YellowUnk2[] = INCGFX_U16("graphics/battle_anims/sprites/yellow_unk_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_AirSlash[] = INCGFX_U32("graphics/battle_anims/sprites/air_slash.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AirSlash[] = INCGFX_U16("graphics/battle_anims/sprites/air_slash.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SpinningGreenOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_green_orbs.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SpinningGreenOrbs[] = INCGFX_U16("graphics/battle_anims/sprites/spinning_green_orbs.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Leaf[] = INCGFX_U32("graphics/battle_anims/sprites/leaf.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Leaf[] = INCGFX_U16("graphics/battle_anims/sprites/leaf.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MetronomeSmallHand[] = INCGFX_U32("graphics/battle_anims/unused/metronome_hand_small.png", ".4bpp.smol"); // unused, was for metronome at one point

const u16 gBattleAnimSpritePal_Clapping[] = INCGFX_U16("graphics/battle_anims/sprites/clapping.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PoisonPowder[] = INCGFX_U32("graphics/battle_anims/sprites/poison_powder.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PoisonPowder[] = INCGFX_U16("graphics/battle_anims/sprites/poison_powder.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BrownTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/brown_triangle.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BrownTriangle[] = INCGFX_U16("graphics/battle_anims/sprites/brown_triangle.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Sparkle3[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_3.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Sparkle3[] = INCGFX_U16("graphics/battle_anims/sprites/sparkle_3.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Sparkle4[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_4.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_MusicNotes[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MusicNotes[] = INCGFX_U16("graphics/battle_anims/sprites/music_notes.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Duck[] = INCGFX_U32("graphics/battle_anims/sprites/duck.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Duck[] = INCGFX_U16("graphics/battle_anims/sprites/duck.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Alert[] = INCGFX_U32("graphics/battle_anims/sprites/alert.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Alert[] = INCGFX_U16("graphics/battle_anims/sprites/alert.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Shock4[] = INCGFX_U32("graphics/battle_anims/sprites/shock_4.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Shock4[] = INCGFX_U16("graphics/battle_anims/sprites/shock_4.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Shock[] = INCGFX_U32("graphics/battle_anims/sprites/shock.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Bell2[] = INCGFX_U32("graphics/battle_anims/sprites/bell_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Bell2[] = INCGFX_U16("graphics/battle_anims/sprites/bell_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PinkGlove[] = INCGFX_U32("graphics/battle_anims/sprites/pink_glove.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PinkGlove[] = INCGFX_U16("graphics/battle_anims/sprites/pink_glove.png", ".gbapal");

const u16 gBattleAnimUnused_Unknown1[] = INCBIN_U16("graphics/battle_anims/unused/unknown_1.bin");
const u16 gBattleAnimUnused_Unknown2[] = INCBIN_U16("graphics/battle_anims/unused/unknown_2.bin");
const u16 gBattleAnimUnused_Unknown3[] = INCBIN_U16("graphics/battle_anims/unused/unknown_3.bin");

const u32 gBattleAnimUnusedGfx_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.png", ".8bpp.smol");
const u16 gBattleAnimUnusedPal_LineSketch2[] = INCGFX_U16("graphics/battle_anims/unused/line_sketch_2.pal", ".gbapal");
const u32 gBattleAnimUnusedTilemap_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_BlueLines[] = INCGFX_U32("graphics/battle_anims/sprites/blue_lines.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlueLines[] = INCGFX_U16("graphics/battle_anims/sprites/blue_lines.png", ".gbapal");

const u16 gBattleAnimSpritePal_Impact3[] = INCGFX_U16("graphics/battle_anims/sprites/impact_3.png", ".gbapal");
const u16 gBattleAnimSpritePal_Impact2[] = INCGFX_U16("graphics/battle_anims/sprites/impact_2.png", ".gbapal");
const u16 gBattleAnimSpritePal_Reticle[] = INCGFX_U16("graphics/battle_anims/sprites/reticle.png", ".gbapal");
const u16 gBattleAnimSpritePal_Breath[] = INCGFX_U16("graphics/battle_anims/sprites/breath.png", ".gbapal");
const u16 gBattleAnimSpritePal_Snowball[] = INCGFX_U16("graphics/battle_anims/sprites/snowball.png", ".gbapal");
const u16 gBattleAnimSpritePal_Vine[] = INCGFX_U16("graphics/battle_anims/sprites/vine.png", ".gbapal");
const u16 gBattleAnimSpritePal_Sword2[] = INCGFX_U16("graphics/battle_anims/sprites/sword_2.png", ".gbapal");
const u16 gBattleAnimSpritePal_RedTube[] = INCGFX_U16("graphics/battle_anims/sprites/red_tube.png", ".gbapal");
const u16 gBattleAnimSpritePal_Amnesia[] = INCGFX_U16("graphics/battle_anims/sprites/amnesia.png", ".gbapal");
const u16 gBattleAnimSpritePal_String2[] = INCGFX_U16("graphics/battle_anims/sprites/string_2.png", ".gbapal");

const u32 gBattleAnimUnused_Unknown4[] = INCGFX_U32("graphics/battle_anims/unused/unknown_4.bin", ".smolTM");

const u16 gBattleAnimSpritePal_Pencil2[] = INCGFX_U16("graphics/battle_anims/sprites/pencil_2.png", ".gbapal");
const u16 gBattleAnimSpritePal_Petal[] = INCGFX_U16("graphics/battle_anims/sprites/petal.png", ".gbapal");
const u16 gBattleAnimSpritePal_BentSpoon[] = INCGFX_U16("graphics/battle_anims/sprites/bent_spoon.png", ".gbapal");
const u16 gBattleAnimSpritePal_Coin[] = INCGFX_U16("graphics/battle_anims/sprites/coin.png", ".gbapal");
const u16 gBattleAnimSpritePal_CrackedEgg[] = INCGFX_U16("graphics/battle_anims/sprites/cracked_egg.png", ".gbapal");
const u16 gBattleAnimSpritePal_FreshEgg[] = INCGFX_U16("graphics/battle_anims/sprites/fresh_egg.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Impact3[] = INCGFX_U32("graphics/battle_anims/sprites/impact_3.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Impact2[] = INCGFX_U32("graphics/battle_anims/sprites/impact_2.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Reticle[] = INCGFX_U32("graphics/battle_anims/sprites/reticle.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Breath[] = INCGFX_U32("graphics/battle_anims/sprites/breath.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Snowball[] = INCGFX_U32("graphics/battle_anims/sprites/snowball.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Vine[] = INCGFX_U32("graphics/battle_anims/sprites/vine.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Sword2[] = INCGFX_U32("graphics/battle_anims/sprites/sword_2.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Clapping[] = INCGFX_U32("graphics/battle_anims/sprites/clapping.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_RedTube[] = INCGFX_U32("graphics/battle_anims/sprites/red_tube.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Amnesia[] = INCGFX_U32("graphics/battle_anims/sprites/amnesia.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_String2[] = INCGFX_U32("graphics/battle_anims/sprites/string_2.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Pencil2[] = INCGFX_U32("graphics/battle_anims/sprites/pencil_2.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Petal[] = INCGFX_U32("graphics/battle_anims/sprites/petal.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_BentSpoon[] = INCGFX_U32("graphics/battle_anims/sprites/bent_spoon.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Web[] = INCGFX_U32("graphics/battle_anims/sprites/web.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Coin[] = INCGFX_U32("graphics/battle_anims/sprites/coin.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_CrackedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/cracked_egg.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_HatchedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/hatched_egg.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_FreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/fresh_egg.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Fangs[] = INCGFX_U32("graphics/battle_anims/sprites/fangs.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Fangs[] = INCGFX_U16("graphics/battle_anims/sprites/fangs.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Explosion2[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Explosion2[] = INCGFX_U16("graphics/battle_anims/sprites/explosion_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Explosion3[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_3.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_WaterDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WaterDroplet[] = INCGFX_U16("graphics/battle_anims/sprites/water_droplet.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WaterDroplet2[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet_2.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Seed2[] = INCGFX_U32("graphics/battle_anims/sprites/seed_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Seed2[] = INCGFX_U16("graphics/battle_anims/sprites/seed_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Sprout[] = INCGFX_U32("graphics/battle_anims/sprites/sprout.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_RedWand[] = INCGFX_U32("graphics/battle_anims/sprites/red_wand.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RedWand[] = INCGFX_U16("graphics/battle_anims/sprites/red_wand.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleGreenUnk[] = INCGFX_U32("graphics/battle_anims/sprites/purple_green_unk.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleGreenUnk[] = INCGFX_U16("graphics/battle_anims/sprites/purple_green_unk.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WaterColumn[] = INCGFX_U32("graphics/battle_anims/sprites/water_column.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WaterColumn[] = INCGFX_U16("graphics/battle_anims/sprites/water_column.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MudUnk[] = INCGFX_U32("graphics/battle_anims/sprites/mud_unk.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MudUnk[] = INCGFX_U16("graphics/battle_anims/sprites/mud_unk.png", ".gbapal");

const u32 gUnusedTilemap_BlueFrame[] = INCGFX_U32("graphics/unused/blue_frame.bin", ".smolTM"); // P1, P2, P3 and P4 tilemaps?
const u32 gUnusedTilemap_RedYellowGreenFrame[] = INCGFX_U32("graphics/unused/redyellowgreen_frame.bin", ".smolTM");
const u32 gUnusedGfx_ColorFrames[] = INCGFX_U32("graphics/unused/color_frames.png", ".4bpp.smol", "-num_tiles 353 -Wnum_tiles");
const u16 gUnusedPal_ColorFrames[] = INCGFX_U16("graphics/unused/color_frames.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RainDrops[] = INCGFX_U32("graphics/battle_anims/sprites/rain_drops.png", ".4bpp.smol");

const u32 gBattleAnimUnusedGfx_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.png", ".8bpp.smol");
const u32 gBattleAnimUnusedTilemap_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.bin", ".smolTM");
const u16 gBattleAnimUnusedPal_WaterSplash[] = INCGFX_U16("graphics/battle_anims/unused/water_splash.png", ".gbapal");

const u32 gUnusedGfx_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.png", ".4bpp.smol");
const u16 gUnusedPal_BasicFrame[] = INCGFX_U16("graphics/unused/basic_frame.png", ".gbapal");
const u32 gUnusedTilemap_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.bin", ".smolTM");

// Battle Interface

const u16 gBattleInterface_BallStatusBarPal[] = INCGFX_U16("graphics/battle_interface/ball_status_bar.png", ".gbapal");

const u16 gBattleInterface_BallDisplayPal[] = INCGFX_U16("graphics/battle_interface/ball_display.png", ".gbapal");

const u8 gHealthboxElementsGfxTable[][32] = INCBIN_U8("graphics/battle_interface/hpbar.4bpp",
                                                  "graphics/battle_interface/expbar.4bpp",
                                                  "graphics/battle_interface/status.4bpp",
                                                  "graphics/battle_interface/misc.4bpp",
                                                  "graphics/battle_interface/hpbar_anim.4bpp",
                                                  "graphics/battle_interface/misc_frameend.4bpp",
                                                  "graphics/battle_interface/ball_display.4bpp",
                                                  "graphics/battle_interface/ball_caught_indicator.4bpp",
                                                  "graphics/battle_interface/status2.4bpp", // these three duplicate sets of graphics are for the opponent/partner Pokémon
                                                  "graphics/battle_interface/status3.4bpp",
                                                  "graphics/battle_interface/status4.4bpp",
                                                  "graphics/battle_interface/healthbox_doubles_player_frameend.4bpp",
                                                  "graphics/battle_interface/healthbox_doubles_player_frameend_bar.4bpp",
                                                  "graphics/battle_interface/healthbox_doubles_opponent_frameend.4bpp",
                                                  "graphics/battle_interface/healthbox_doubles_opponent_frameend_bar.4bpp");
const u32 gBattleInterfaceGfx_UnusedWindow3[] = INCGFX_U32("graphics/battle_interface/unused_window3.png", ".4bpp.smol");
const u32 gBattleInterfaceGfx_UnusedWindow4[] = INCGFX_U32("graphics/battle_interface/unused_window4.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_FurySwipes[] = INCGFX_U32("graphics/battle_anims/sprites/fury_swipes.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_FurySwipes[] = INCGFX_U16("graphics/battle_anims/sprites/fury_swipes.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Vine2[] = INCGFX_U32("graphics/battle_anims/sprites/vine_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Vine2[] = INCGFX_U16("graphics/battle_anims/sprites/vine_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Teeth[] = INCGFX_U32("graphics/battle_anims/sprites/teeth.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Teeth[] = INCGFX_U16("graphics/battle_anims/sprites/teeth.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Bone2[] = INCGFX_U32("graphics/battle_anims/sprites/bone_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Bone2[] = INCGFX_U16("graphics/battle_anims/sprites/bone_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WhiteBag[] = INCGFX_U32("graphics/battle_anims/sprites/white_bag.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WhiteBag[] = INCGFX_U16("graphics/battle_anims/sprites/white_bag.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Unknown[] = INCGFX_U32("graphics/battle_anims/sprites/unknown.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Unknown[] = INCGFX_U16("graphics/battle_anims/sprites/unknown.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleCoral[] = INCGFX_U32("graphics/battle_anims/sprites/purple_coral.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleCoral[] = INCGFX_U16("graphics/battle_anims/sprites/purple_coral.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/purple_droplet.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Shock2[] = INCGFX_U32("graphics/battle_anims/sprites/shock_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Shock2[] = INCGFX_U16("graphics/battle_anims/sprites/shock_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ClosingEye2[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ClosingEye2[] = INCGFX_U16("graphics/battle_anims/sprites/closing_eye_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MetalBall[] = INCGFX_U32("graphics/battle_anims/sprites/metal_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MetalBall[] = INCGFX_U16("graphics/battle_anims/sprites/metal_ball.png", ".gbapal");

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gBattleAnimSpriteGfx_MonsterDoll[] = INCGFX_U32("graphics/battle_anims/sprites/monster_doll.png", ".4bpp.smol");
    const u16 gBattleAnimSpritePal_MonsterDoll[] = INCGFX_U16("graphics/battle_anims/sprites/monster_doll.png", ".gbapal");
#else
    const u32 gBattleAnimSpriteGfx_MonsterDoll[] = INCGFX_U32("graphics/battle_anims/sprites/monster_doll_gba.png", ".4bpp.smol");
    const u16 gBattleAnimSpritePal_MonsterDoll[] = INCGFX_U16("graphics/battle_anims/sprites/monster_doll_gba.png", ".gbapal");
#endif //P_GBA_STYLE_SPECIES_GFX

const u32 gBattleAnimSpriteGfx_Whirlwind[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Whirlwind[] = INCGFX_U16("graphics/battle_anims/sprites/whirlwind.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Whirlwind2[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_2.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Explosion4[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_4.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Explosion4[] = INCGFX_U16("graphics/battle_anims/sprites/explosion_4.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Explosion5[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_5.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Tongue[] = INCGFX_U32("graphics/battle_anims/sprites/tongue.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Tongue[] = INCGFX_U16("graphics/battle_anims/sprites/tongue.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Smoke[] = INCGFX_U32("graphics/battle_anims/sprites/smoke.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Smoke[] = INCGFX_U16("graphics/battle_anims/sprites/smoke.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Smoke2[] = INCGFX_U32("graphics/battle_anims/sprites/smoke_2.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_BlueFlames[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlueFlames[] = INCGFX_U16("graphics/battle_anims/sprites/blue_flames.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BlueFlames2[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames_2.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_TatsugiriCurly[] = INCGFX_U32("graphics/battle_anims/sprites/tatsugiri_curly.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TatsugiriCurly[] = INCGFX_U16("graphics/battle_anims/sprites/tatsugiri_curly.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TatsugiriDroopy[] = INCGFX_U32("graphics/battle_anims/sprites/tatsugiri_droopy.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TatsugiriDroopy[] = INCGFX_U16("graphics/battle_anims/sprites/tatsugiri_droopy.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TatsugiriStretchy[] = INCGFX_U32("graphics/battle_anims/sprites/tatsugiri_stretchy.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TatsugiriStretchy[] = INCGFX_U16("graphics/battle_anims/sprites/tatsugiri_stretchy.png", ".gbapal");

// Contest
const u32 gJPContestGfx1[] = INCGFX_U32("graphics/contest/japanese/composite_1.4bpp", ".smol");
const u16 gJPContestPal[] = INCGFX_U16("graphics/contest/japanese/palette.pal", ".gbapal");
const u32 gJPContestBgTilemap[] = INCGFX_U32("graphics/contest/japanese/bg.bin", ".smolTM");
const u32 gJPContestWindowsTilemap[] = INCGFX_U32("graphics/contest/japanese/windows.bin", ".smolTM");
const u32 gJPContestGfx2[] = INCGFX_U32("graphics/contest/japanese/composite_2.4bpp", ".smol");

const u16 gContestInterfaceAudiencePalette[] = INCGFX_U16("graphics/contest/interface.png", ".gbapal");
const u32 gContestAudienceTilemap[] = INCGFX_U32("graphics/contest/audience.bin", ".smolTM");
const u32 gContestInterfaceTilemap[] = INCGFX_U32("graphics/contest/interface.bin", ".smolTM");
const u32 gJPContestInterfaceTilemap[] = INCGFX_U32("graphics/contest/japanese/interface.bin", ".smolTM");
const u32 gJPContestAudienceTilemap[] = INCGFX_U32("graphics/contest/japanese/audience.bin", ".smolTM");
const u32 gContestCurtainTilemap[] = INCGFX_U32("graphics/contest/curtain.bin", ".smolTM");

const u32 gContestInterfaceGfx[] = INCGFX_U32("graphics/contest/interface.png", ".4bpp.smol");
const u32 gContestAudienceGfx[] = INCGFX_U32("graphics/contest/audience.png", ".4bpp.smol");
const u32 gContestFaces_Gfx[] = INCGFX_U32("graphics/contest/faces.png", ".4bpp.smol");
const u32 gContestJudgeSymbolsGfx[] = INCGFX_U32("graphics/contest/judge_symbols.png", ".4bpp.smol");
const u16 gContestJudgeSymbolsPal[] = INCGFX_U16("graphics/contest/judge_symbols.png", ".gbapal");
const u8 gContestSliderHeart_Gfx[] = INCGFX_U8("graphics/contest/slider_heart.png", ".4bpp");

// JP equivalent of the Applause meter
const u32 gJPContestVoltageGfx[] = INCGFX_U32("graphics/contest/japanese/voltage.png", ".4bpp.smol", "-num_tiles 36 -Wnum_tiles");
const u16 gJPContestVoltagePal[] = INCGFX_U16("graphics/contest/japanese/voltage.png", ".gbapal");

// Contest results
const u32 gContestResults_Gfx[]                  = INCGFX_U32("graphics/contest/results_screen/tiles.png", ".4bpp.smol");
const u32 gContestResults_WinnerBanner_Tilemap[] = INCGFX_U32("graphics/contest/results_screen/winner_banner.bin", ".smolTM");
const u32 gContestResults_Interface_Tilemap[]    = INCGFX_U32("graphics/contest/results_screen/interface.bin", ".smolTM");
const u32 gContestResults_Bg_Tilemap[]           = INCGFX_U32("graphics/contest/results_screen/bg.bin", ".smolTM");
const u16 gContestResults_Pal[]                  = INCGFX_U16("graphics/contest/results_screen/tiles.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Impact[] = INCGFX_U32("graphics/battle_anims/sprites/impact.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Impact[] = INCGFX_U16("graphics/battle_anims/sprites/impact.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Particles[] = INCGFX_U32("graphics/battle_anims/sprites/particles.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Particles2[] = INCGFX_U32("graphics/battle_anims/sprites/particles2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Particles2[] = INCGFX_U16("graphics/battle_anims/sprites/particles2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_CircleImpact[] = INCGFX_U32("graphics/battle_anims/sprites/circle_impact.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_CircleImpact[] = INCGFX_U16("graphics/battle_anims/sprites/circle_impact.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Scratch[] = INCGFX_U32("graphics/battle_anims/sprites/scratch.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_SharpTeeth[] = INCGFX_U32("graphics/battle_anims/sprites/sharp_teeth.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SharpTeeth[] = INCGFX_U16("graphics/battle_anims/sprites/sharp_teeth.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Clamp[] = INCGFX_U32("graphics/battle_anims/sprites/clamp.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Cut[] = INCGFX_U32("graphics/battle_anims/sprites/cut.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_RainbowRings[] = INCGFX_U32("graphics/battle_anims/sprites/rainbow_rings.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RainbowRings[] = INCGFX_U16("graphics/battle_anims/sprites/rainbow_rings.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_IceCrystals[] = INCGFX_U32("graphics/battle_anims/sprites/ice_crystals.4bpp", ".smol");
const u16 gBattleAnimSpritePal_IceCrystals[] = INCGFX_U16("graphics/battle_anims/sprites/ice_crystals.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_IceSpikes[] = INCGFX_U32("graphics/battle_anims/sprites/ice_spikes.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_OldBeatUp[] = INCGFX_U32("graphics/battle_anims/unused/old_beatup.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_OldBeatUp[] = INCGFX_U16("graphics/battle_anims/unused/old_beatup.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Orbs[] = INCGFX_U32("graphics/battle_anims/sprites/orbs.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Orbs[] = INCGFX_U16("graphics/battle_anims/sprites/orbs.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WaterOrb[] = INCGFX_U32("graphics/battle_anims/sprites/water_orb.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_WaterImpact[] = INCGFX_U32("graphics/battle_anims/sprites/water_impact.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WaterImpact[] = INCGFX_U16("graphics/battle_anims/sprites/water_impact.png", ".gbapal");

const u16 gBattleAnimSpritePal_BrownOrb[] = INCGFX_U16("graphics/battle_anims/sprites/brown_orb.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_MudSand[] = INCGFX_U32("graphics/battle_anims/sprites/mud_sand.4bpp", ".smol");
const u16 gBattleAnimSpritePal_MudSand[] = INCGFX_U16("graphics/battle_anims/sprites/mud_sand.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_PoisonBubble[] = INCGFX_U32("graphics/battle_anims/sprites/poison_bubble.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PoisonBubble[] = INCGFX_U16("graphics/battle_anims/sprites/poison_bubble.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ToxicBubble[] = INCGFX_U32("graphics/battle_anims/sprites/toxic_bubble.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_HornHit2[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HornHit2[] = INCGFX_U16("graphics/battle_anims/sprites/horn_hit_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_AirWave2[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_AirWave2[] = INCGFX_U16("graphics/battle_anims/sprites/air_wave_2.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SmallBubbles[] = INCGFX_U32("graphics/battle_anims/sprites/small_bubbles.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SmallBubbles[] = INCGFX_U16("graphics/battle_anims/sprites/small_bubbles.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RoundShadow[] = INCGFX_U32("graphics/battle_anims/sprites/round_shadow.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RoundShadow[] = INCGFX_U16("graphics/battle_anims/sprites/round_shadow.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Sunlight[] = INCGFX_U32("graphics/battle_anims/sprites/sunlight.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Sunlight[] = INCGFX_U16("graphics/battle_anims/sprites/sunlight.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Spore[] = INCGFX_U32("graphics/battle_anims/sprites/spore.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Spore[] = INCGFX_U16("graphics/battle_anims/sprites/spore.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Flower[] = INCGFX_U32("graphics/battle_anims/sprites/flower.4bpp", ".smol");
const u16 gBattleAnimSpritePal_Flower[] = INCGFX_U16("graphics/battle_anims/sprites/flower.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_RazorLeaf[] = INCGFX_U32("graphics/battle_anims/sprites/razor_leaf.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RazorLeaf[] = INCGFX_U16("graphics/battle_anims/sprites/razor_leaf.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MistCloud[] = INCGFX_U32("graphics/battle_anims/sprites/mist_cloud.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MistCloud[] = INCGFX_U16("graphics/battle_anims/sprites/mist_cloud.png", ".gbapal");

const u32 gBattleAnimUnusedGfx_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.png", ".4bpp.smol");
const u16 gBattleAnimUnusedPal_Lights[] = INCGFX_U16("graphics/battle_anims/unused/lights.png", ".gbapal");
const u32 gBattleAnimUnusedTilemap_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_WhirlwindLines[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_lines.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WhirlwindLines[] = INCGFX_U16("graphics/battle_anims/sprites/whirlwind_lines.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GoldRing[] = INCGFX_U32("graphics/battle_anims/sprites/gold_ring.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GoldRing[] = INCGFX_U16("graphics/battle_anims/sprites/gold_ring.png", ".gbapal");

const u16 gBattleAnimSpritePal_BlueRing2[] = INCGFX_U16("graphics/battle_anims/sprites/blue_ring_2.pal", ".gbapal");
const u16 gBattleAnimSpritePal_PurpleRing[] = INCGFX_U16("graphics/battle_anims/sprites/purple_ring.pal", ".gbapal");
const u16 gBattleAnimSpritePal_BlueRing[] = INCGFX_U16("graphics/battle_anims/sprites/blue_ring.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_GreenLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/green_light_wall.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GreenLightWall[] = INCGFX_U16("graphics/battle_anims/sprites/green_light_wall.png", ".gbapal");

const u16 gBattleAnimSpritePal_BlueLightWall[] = INCGFX_U16("graphics/battle_anims/sprites/blue_light_wall.pal", ".gbapal");
const u16 gBattleAnimSpritePal_RedLightWall[] = INCGFX_U16("graphics/battle_anims/sprites/red_light_wall.pal", ".gbapal");
const u16 gBattleAnimSpritePal_GrayLightWall[] = INCGFX_U16("graphics/battle_anims/sprites/gray_light_wall.pal", ".gbapal");
const u16 gBattleAnimSpritePal_OrangeLightWall[] = INCGFX_U16("graphics/battle_anims/sprites/orange_light_wall.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_BlackBall2[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BlackBall2[] = INCGFX_U16("graphics/battle_anims/sprites/black_ball_2.png", ".gbapal");

const u16 gBattleAnimSpritePal_PurpleGasCloud[] = INCGFX_U16("graphics/battle_anims/sprites/purple_gas_cloud.pal", ".gbapal");

const u32 gContestJudgeGfx[] = INCGFX_U32("graphics/contest/judge.png", ".4bpp.smol");
const u16 gContest2Pal[] = INCGFX_U16("graphics/contest/judge.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Spark[] = INCGFX_U32("graphics/battle_anims/sprites/spark.4bpp", ".smol");
const u16 gBattleAnimSpritePal_Spark[] = INCGFX_U16("graphics/battle_anims/sprites/spark.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_SparkH[] = INCGFX_U32("graphics/battle_anims/sprites/spark_h.png", ".4bpp.smol");

const u32 gBattleAnimBgImage_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Dark[] = INCGFX_U16("graphics/battle_anims/backgrounds/dark.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.bin", ".smolTM");

const u32 gMetalShineGfx[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.png", ".4bpp.smol");
const u16 gMetalShinePalette[] = INCGFX_U16("graphics/battle_anims/masks/metal_shine.png", ".gbapal");
const u32 gMetalShineTilemap[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.bin", ".smolTM");

const u32 gUnusedGfx_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.png", ".4bpp.smol"); // ghost
const u16 gUnusedPal_Goosuto[] = INCGFX_U16("graphics/battle_anims/unused/goosuto.png", ".gbapal");
const u32 gUnusedTilemap_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_YellowStar[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_star.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_YellowStar[] = INCGFX_U16("graphics/battle_anims/sprites/yellow_star.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_LargeFreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/large_fresh_egg.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_LargeFreshEgg[] = INCGFX_U16("graphics/battle_anims/sprites/large_fresh_egg.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ShadowBall[] = INCGFX_U32("graphics/battle_anims/sprites/shadow_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ShadowBall[] = INCGFX_U16("graphics/battle_anims/sprites/shadow_ball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Lick[] = INCGFX_U32("graphics/battle_anims/sprites/lick.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Lick[] = INCGFX_U16("graphics/battle_anims/sprites/lick.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_VoidLines[] = INCGFX_U32("graphics/battle_anims/sprites/void_lines.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_VoidLines[] = INCGFX_U16("graphics/battle_anims/sprites/void_lines.png", ".gbapal");

const u16 gBattleAnimSpritePal_String[] = INCGFX_U16("graphics/battle_anims/sprites/string.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_String[] = INCGFX_U32("graphics/battle_anims/sprites/string.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_WebThread[] = INCGFX_U32("graphics/battle_anims/sprites/web_thread.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_SpiderWeb[] = INCGFX_U32("graphics/battle_anims/sprites/spider_web.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Lightbulb[] = INCGFX_U32("graphics/battle_anims/sprites/lightbulb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Lightbulb[] = INCGFX_U16("graphics/battle_anims/sprites/lightbulb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Slash[] = INCGFX_U32("graphics/battle_anims/sprites/slash.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Slash[] = INCGFX_U16("graphics/battle_anims/sprites/slash.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_FocusEnergy[] = INCGFX_U32("graphics/battle_anims/sprites/focus_energy.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_FocusEnergy[] = INCGFX_U16("graphics/battle_anims/sprites/focus_energy.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SphereToCube[] = INCGFX_U32("graphics/battle_anims/sprites/sphere_to_cube.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SphereToCube[] = INCGFX_U16("graphics/battle_anims/sprites/sphere_to_cube.png", ".gbapal");

const u32 gBattleAnimBgImage_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Psychic[] = INCGFX_U16("graphics/battle_anims/backgrounds/psychic.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_Eye[] = INCGFX_U32("graphics/battle_anims/sprites/eye.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Eye[] = INCGFX_U16("graphics/battle_anims/sprites/eye.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Tendrils[] = INCGFX_U32("graphics/battle_anims/sprites/tendrils.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Tendrils[] = INCGFX_U16("graphics/battle_anims/sprites/tendrils.png", ".gbapal");

const u32 gHealthboxSinglesPlayerGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_singles_player.png", ".4bpp.smol", "-mwidth 8 -mheight 8");
const u32 gHealthboxSinglesOpponentGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_singles_opponent.png", ".4bpp.smol", "-mwidth 8 -mheight 4");
const u32 gHealthboxSinglesOpponentLargeGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_singles_opponent_large.png", ".4bpp.smol", "-mwidth 8 -mheight 8");
const u32 gHealthboxDoublesPlayerGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_doubles_player.png", ".4bpp.smol", "-mwidth 8 -mheight 4");
const u32 gHealthboxDoublesOpponentGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_doubles_opponent.png", ".4bpp.smol", "-mwidth 8 -mheight 4");
const u32 gHealthboxSafariGfx[] = INCGFX_U32("graphics/battle_interface/healthbox_safari.png", ".4bpp.smol", "-mwidth 8 -mheight 8");

const u32 gUnusedGfx_Shadow[] = INCGFX_U32("graphics/unused/shadow.png", ".4bpp.smol");
const u16 gUnusedPal_Shadow[] = INCGFX_U16("graphics/unused/shadow.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_LockOn[] = INCGFX_U32("graphics/battle_anims/sprites/lock_on.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_LockOn[] = INCGFX_U16("graphics/battle_anims/sprites/lock_on.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_OpeningEye[] = INCGFX_U32("graphics/battle_anims/sprites/opening_eye.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_OpeningEye[] = INCGFX_U16("graphics/battle_anims/sprites/opening_eye.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RoundWhiteHalo[] = INCGFX_U32("graphics/battle_anims/sprites/round_white_halo.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RoundWhiteHalo[] = INCGFX_U16("graphics/battle_anims/sprites/round_white_halo.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TealAlert[] = INCGFX_U32("graphics/battle_anims/sprites/teal_alert.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TealAlert[] = INCGFX_U16("graphics/battle_anims/sprites/teal_alert.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_FangAttack[] = INCGFX_U32("graphics/battle_anims/sprites/fang_attack.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_FangAttack[] = INCGFX_U16("graphics/battle_anims/sprites/fang_attack.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleHandOutline[] = INCGFX_U32("graphics/battle_anims/sprites/purple_hand_outline.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleHandOutline[] = INCGFX_U16("graphics/battle_anims/sprites/purple_hand_outline.png", ".gbapal");

const u32 gBattleAnimMaskImage_Curse[] = INCGFX_U32("graphics/battle_anims/masks/curse.png", ".4bpp.smol");
const u32 gBattleAnimMaskTilemap_Curse[] = INCGFX_U32("graphics/battle_anims/masks/curse.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_Pencil[] = INCGFX_U32("graphics/battle_anims/sprites/pencil.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Pencil[] = INCGFX_U16("graphics/battle_anims/sprites/pencil.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Spiral[] = INCGFX_U32("graphics/battle_anims/sprites/spiral.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Spiral[] = INCGFX_U16("graphics/battle_anims/sprites/spiral.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Moon[] = INCGFX_U32("graphics/battle_anims/sprites/moon.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Moon[] = INCGFX_U16("graphics/battle_anims/sprites/moon.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GreenSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/green_sparkle.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GreenSparkle[] = INCGFX_U16("graphics/battle_anims/sprites/green_sparkle.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SnoreZ[] = INCGFX_U32("graphics/battle_anims/sprites/snore_z.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SnoreZ[] = INCGFX_U16("graphics/battle_anims/sprites/snore_z.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Explosion[] = INCGFX_U32("graphics/battle_anims/sprites/explosion.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Explosion[] = INCGFX_U16("graphics/battle_anims/sprites/explosion.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Nail[] = INCGFX_U32("graphics/battle_anims/sprites/nail.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Nail[] = INCGFX_U16("graphics/battle_anims/sprites/nail.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GhostlySpirit[] = INCGFX_U32("graphics/battle_anims/sprites/ghostly_spirit.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GhostlySpirit[] = INCGFX_U16("graphics/battle_anims/sprites/ghostly_spirit.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WarmRock[] = INCGFX_U32("graphics/battle_anims/sprites/warm_rock.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WarmRock[] = INCGFX_U16("graphics/battle_anims/sprites/warm_rock.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PunchImpact[] = INCGFX_U32("graphics/battle_anims/sprites/punch_impact.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PunchImpact[] = INCGFX_U16("graphics/battle_anims/sprites/punch_impact.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_BreakingEgg[] = INCGFX_U32("graphics/battle_anims/sprites/breaking_egg.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BreakingEgg[] = INCGFX_U16("graphics/battle_anims/sprites/breaking_egg.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_ThinRing[] = INCGFX_U32("graphics/battle_anims/sprites/thin_ring.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ThinRing[] = INCGFX_U16("graphics/battle_anims/sprites/thin_ring.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MusicNotes2[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes_2.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MusicNotes2[] = INCGFX_U16("graphics/battle_anims/sprites/music_notes_2.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_Bell[] = INCGFX_U32("graphics/battle_anims/sprites/bell.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Bell[] = INCGFX_U16("graphics/battle_anims/sprites/bell.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SpeedDust[] = INCGFX_U32("graphics/battle_anims/sprites/speed_dust.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SpeedDust[] = INCGFX_U16("graphics/battle_anims/sprites/speed_dust.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TornMetal[] = INCGFX_U32("graphics/battle_anims/sprites/torn_metal.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_ThoughtBubble[] = INCGFX_U32("graphics/battle_anims/sprites/thought_bubble.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_ThoughtBubble[] = INCGFX_U16("graphics/battle_anims/sprites/thought_bubble.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Finger[] = INCGFX_U32("graphics/battle_anims/sprites/finger.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Finger[] = INCGFX_U16("graphics/battle_anims/sprites/finger.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MagentaHeart[] = INCGFX_U32("graphics/battle_anims/sprites/magenta_heart.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_PinkHeart[] = INCGFX_U16("graphics/battle_anims/sprites/pink_heart.pal", ".gbapal");
const u16 gBattleAnimSpritePal_MagentaHeart[] = INCGFX_U16("graphics/battle_anims/sprites/magenta_heart.png", ".gbapal");
const u16 gBattleAnimSpritePal_RedHeart[] = INCGFX_U16("graphics/battle_anims/sprites/red_heart.pal", ".gbapal");

const u32 gBattleAnimBgImage_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Attract[] = INCGFX_U16("graphics/battle_anims/backgrounds/attract.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_RedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RedOrb[] = INCGFX_U16("graphics/battle_anims/sprites/red_orb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_CircleOfLight[] = INCGFX_U32("graphics/battle_anims/sprites/circle_of_light.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_ElectricOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/electric_orbs.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Electricity[] = INCGFX_U32("graphics/battle_anims/sprites/electricity.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_ElectricOrbs[] = INCGFX_U16("graphics/battle_anims/sprites/electric_orbs.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Finger2[] = INCGFX_U32("graphics/battle_anims/sprites/finger_2.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_MovementWaves[] = INCGFX_U32("graphics/battle_anims/sprites/movement_waves.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MovementWaves[] = INCGFX_U16("graphics/battle_anims/sprites/movement_waves.png", ".gbapal");

const u16 gBattleAnimBgPalette_ScaryFace[] = INCGFX_U16("graphics/battle_anims/backgrounds/scary_face.png", ".gbapal");
const u32 gBattleAnimBgImage_ScaryFace[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_EyeSparkle[] = INCGFX_U16("graphics/battle_anims/sprites/eye_sparkle.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_EyeSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/eye_sparkle.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Anger[] = INCGFX_U32("graphics/battle_anims/sprites/anger.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Anger[] = INCGFX_U16("graphics/battle_anims/sprites/anger.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Conversion[] = INCGFX_U32("graphics/battle_anims/sprites/conversion.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Conversion[] = INCGFX_U16("graphics/battle_anims/sprites/conversion.png", ".gbapal");

const u16 gBattleAnimSpritePal_Angel[] = INCGFX_U16("graphics/battle_anims/sprites/angel.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Angel[] = INCGFX_U32("graphics/battle_anims/sprites/angel.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Devil[] = INCGFX_U16("graphics/battle_anims/sprites/devil.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Devil[] = INCGFX_U32("graphics/battle_anims/sprites/devil.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Swipe[] = INCGFX_U32("graphics/battle_anims/sprites/swipe.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Swipe[] = INCGFX_U16("graphics/battle_anims/sprites/swipe.png", ".gbapal");

const u16 gBattleAnimSpritePal_Roots[] = INCGFX_U16("graphics/battle_anims/sprites/roots.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Roots[] = INCGFX_U32("graphics/battle_anims/sprites/roots.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_ItemBag[] = INCGFX_U16("graphics/battle_anims/sprites/item_bag.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_ItemBag[] = INCGFX_U32("graphics/battle_anims/sprites/item_bag.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_TriAttackTriangle[] = INCGFX_U16("graphics/battle_anims/sprites/tri_attack_triangle.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_TriAttackTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/tri_attack_triangle.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_LetterZ[] = INCGFX_U16("graphics/battle_anims/sprites/letter_z.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_LetterZ[] = INCGFX_U32("graphics/battle_anims/sprites/letter_z.png", ".4bpp.smol");

const u16 gBattleAnimBgPalette_Impact[] = INCGFX_U16("graphics/battle_anims/backgrounds/impact.png", ".gbapal");
const u32 gBattleAnimBgImage_Impact[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact.png", ".4bpp.smol");
const u32 gBattleAnimBgTilemap_ImpactOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_opponent.bin", ".smolTM");

const u32 gBattleAnimBgTilemap_ImpactPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_player.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_ImpactContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_contests.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_JaggedMusicNote[] = INCGFX_U32("graphics/battle_anims/sprites/jagged_music_note.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_JaggedMusicNote[] = INCGFX_U16("graphics/battle_anims/sprites/jagged_music_note.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Spotlight[] = INCGFX_U32("graphics/battle_anims/sprites/spotlight.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Pokeball[] = INCGFX_U32("graphics/battle_anims/sprites/pokeball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Pokeball[] = INCGFX_U16("graphics/battle_anims/sprites/pokeball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RapidSpin[] = INCGFX_U32("graphics/battle_anims/sprites/rapid_spin.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RapidSpin[] = INCGFX_U16("graphics/battle_anims/sprites/rapid_spin.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MilkBottle[] = INCGFX_U32("graphics/battle_anims/sprites/milk_bottle.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MilkBottle[] = INCGFX_U16("graphics/battle_anims/sprites/milk_bottle.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_WispFire[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_fire.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_WispOrb[] = INCGFX_U16("graphics/battle_anims/sprites/wisp_orb.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_WispOrb[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_orb.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_GoldStars[] = INCGFX_U32("graphics/battle_anims/sprites/gold_stars.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GoldStars[] = INCGFX_U16("graphics/battle_anims/sprites/gold_stars.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_EclipsingOrb[] = INCGFX_U32("graphics/battle_anims/sprites/eclipsing_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_EclipsingOrb[] = INCGFX_U16("graphics/battle_anims/sprites/eclipsing_orb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PinkPetal[] = INCGFX_U32("graphics/battle_anims/sprites/pink_petal.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PinkPetal[] = INCGFX_U16("graphics/battle_anims/sprites/pink_petal.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GrayOrb[] = INCGFX_U32("graphics/battle_anims/sprites/gray_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GrayOrb[] = INCGFX_U16("graphics/battle_anims/sprites/gray_orb.png", ".gbapal");

const u16 gBattleAnimSpritePal_BlueOrb[] = INCGFX_U16("graphics/battle_anims/sprites/blue_orb.pal", ".gbapal");
const u16 gBattleAnimSpritePal_RedOrb2[] = INCGFX_U16("graphics/battle_anims/sprites/red_orb_2.pal", ".gbapal");

const u32 gBattleAnimBgImage_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Drill[] = INCGFX_U16("graphics/battle_anims/backgrounds/drill.png", ".gbapal");

const u16 gBattleAnimBgPalette_Sky[] = INCGFX_U16("graphics/battle_anims/backgrounds/sky.pal", ".gbapal");

const u32 gBattleAnimBgTilemap_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_DrillContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill_contests.bin", ".smolTM");

const u32 gBattleAnimBgImage_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Aurora[] = INCGFX_U16("graphics/battle_anims/backgrounds/aurora.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.bin", ".smolTM");

const u32 gBattleAnimBgTilemap_HighspeedOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed_opponent.bin", ".smolTM");
const u16 gBattleAnimBgPalette_Highspeed[] = INCGFX_U16("graphics/battle_anims/backgrounds/highspeed.png", ".gbapal");

const u16 gBattleAnimBgPalette_Bug[] = INCGFX_U16("graphics/battle_anims/backgrounds/bug.pal", ".gbapal");

const u32 gBattleAnimBgImage_Highspeed[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed.png", ".4bpp.smol");
const u32 gBattleAnimBgTilemap_HighspeedPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed_player.bin", ".smolTM");

const u32 gBattleAnimMaskImage_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.png", ".4bpp.smol");
const u16 gBattleAnimMaskPalette_LightBeam[] = INCGFX_U16("graphics/battle_anims/masks/light_beam.png", ".gbapal");
const u32 gBattleAnimMaskTilemap_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.bin", ".smolTM");

const u32 gBattleAnimBgTilemap_GuillotineOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_opponent.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_GuillotinePlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_player.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_GuillotineContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_contests.bin", ".smolTM");

const u32 gBattleAnimBgImage_Guillotine[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Guillotine[] = INCGFX_U16("graphics/battle_anims/backgrounds/guillotine.png", ".gbapal");

const u32 gBattleAnimBgImage_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Thunder[] = INCGFX_U16("graphics/battle_anims/backgrounds/thunder.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_PainSplit[] = INCGFX_U32("graphics/battle_anims/sprites/pain_split.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PainSplit[] = INCGFX_U16("graphics/battle_anims/sprites/pain_split.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HandsAndFeet[] = INCGFX_U32("graphics/battle_anims/sprites/hands_and_feet.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HandsAndFeet[] = INCGFX_U16("graphics/battle_anims/sprites/hands_and_feet.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Confetti[] = INCGFX_U32("graphics/battle_anims/sprites/confetti.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Confetti[] = INCGFX_U16("graphics/battle_anims/sprites/confetti.png", ".gbapal");

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gBattleAnimSpriteGfx_Substitute[] = INCGFX_U32("graphics/battle_anims/sprites/substitute.png", ".4bpp.smol");
    const u32 gBattleAnimSpriteGfx_SubstituteBack[] = INCGFX_U32("graphics/battle_anims/sprites/substitute_back.png", ".4bpp.smol");
    const u16 gBattleAnimSpritePal_Substitute[] = INCGFX_U16("graphics/battle_anims/sprites/substitute.png", ".gbapal");
#else
    const u32 gBattleAnimSpriteGfx_Substitute[] = INCGFX_U32("graphics/battle_anims/sprites/substitute_gba.png", ".4bpp.smol");
    const u32 gBattleAnimSpriteGfx_SubstituteBack[] = INCGFX_U32("graphics/battle_anims/sprites/substitute_back_gba.png", ".4bpp.smol");
    const u16 gBattleAnimSpritePal_Substitute[] = INCGFX_U16("graphics/battle_anims/sprites/substitute_gba.png", ".gbapal");
#endif //P_GBA_STYLE_SPECIES_GFX

const u32 gBattleAnimSpriteGfx_GreenStar[] = INCGFX_U32("graphics/battle_anims/sprites/green_star.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GreenStar[] = INCGFX_U16("graphics/battle_anims/sprites/green_star.png", ".gbapal");

const u32 gConfetti_Gfx[] = INCGFX_U32("graphics/misc/confetti.png", ".4bpp.smol");
const u16 gConfetti_Pal[] = INCGFX_U16("graphics/misc/confetti.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PinkCloud[] = INCGFX_U32("graphics/battle_anims/sprites/pink_cloud.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PinkCloud[] = INCGFX_U16("graphics/battle_anims/sprites/pink_cloud.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SweatDrop[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_drop.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SweatDrop[] = INCGFX_U16("graphics/battle_anims/sprites/sweat_drop.png", ".gbapal");

const u32 gStatAnim_Gfx[]              = INCGFX_U32("graphics/battle_anims/stat_change/tiles.png", ".4bpp.smol");
const u32 gStatAnim_Increase_Tilemap[] = INCGFX_U32("graphics/battle_anims/stat_change/increase.bin", ".smolTM");
const u32 gStatAnim_Decrease_Tilemap[] = INCGFX_U32("graphics/battle_anims/stat_change/decrease.bin", ".smolTM");
const u16 gStatAnim_Defense_Pal[]      = INCGFX_U16("graphics/battle_anims/stat_change/defense.pal", ".gbapal");
const u16 gStatAnim_Attack_Pal[]       = INCGFX_U16("graphics/battle_anims/stat_change/attack.pal", ".gbapal");
const u16 gStatAnim_Accuracy_Pal[]     = INCGFX_U16("graphics/battle_anims/stat_change/accuracy.pal", ".gbapal");
const u16 gStatAnim_Speed_Pal[]        = INCGFX_U16("graphics/battle_anims/stat_change/speed.pal", ".gbapal");
const u16 gStatAnim_Multiple_Pal[]     = INCGFX_U16("graphics/battle_anims/stat_change/multiple.pal", ".gbapal");
const u16 gStatAnim_Evasion_Pal[]      = INCGFX_U16("graphics/battle_anims/stat_change/evasion.pal", ".gbapal");
const u16 gStatAnim_SpAttack_Pal[]     = INCGFX_U16("graphics/battle_anims/stat_change/sp_attack.pal", ".gbapal");
const u16 gStatAnim_SpDefense_Pal[]    = INCGFX_U16("graphics/battle_anims/stat_change/sp_defense.pal", ".gbapal");

const u32 gCureBubblesGfx[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.png", ".4bpp.smol");
const u16 gCureBubblesPal[] = INCGFX_U16("graphics/battle_anims/masks/cure_bubbles.png", ".gbapal");
const u32 gCureBubblesTilemap[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.bin", ".smolTM");

const u16 gBattleAnimSpritePal_PurpleScratch[] = INCGFX_U16("graphics/battle_anims/sprites/purple_scratch.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_PurpleScratch[] = INCGFX_U32("graphics/battle_anims/sprites/purple_scratch.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_PurpleSwipe[] = INCGFX_U32("graphics/battle_anims/sprites/purple_swipe.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_GuardRing[] = INCGFX_U32("graphics/battle_anims/sprites/guard_ring.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GuardRing[] = INCGFX_U16("graphics/battle_anims/sprites/guard_ring.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TagHand[] = INCGFX_U32("graphics/battle_anims/sprites/tag_hand.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_NoiseLine[] = INCGFX_U32("graphics/battle_anims/sprites/noise_line.png", ".4bpp.smol");

const u32 UnusedLevelupAnimationGfx[] = INCGFX_U32("graphics/battle_anims/masks/unused_level_up.png", ".4bpp.smol", "-num_tiles 14 -Wnum_tiles");
const u32 UnusedLevelupAnimationTilemap[] = INCGFX_U32("graphics/battle_anims/masks/unused_level_up.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_SmallRedEye[] = INCGFX_U32("graphics/battle_anims/sprites/small_red_eye.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SmallRedEye[] = INCGFX_U16("graphics/battle_anims/sprites/small_red_eye.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_HollowOrb[] = INCGFX_U32("graphics/battle_anims/sprites/hollow_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_HollowOrb[] = INCGFX_U16("graphics/battle_anims/sprites/hollow_orb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_XSign[] = INCGFX_U32("graphics/battle_anims/sprites/x_sign.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_BluegreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/bluegreen_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_BluegreenOrb[] = INCGFX_U16("graphics/battle_anims/sprites/bluegreen_orb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PinkVioletOrb[] = INCGFX_U32("graphics/battle_anims/sprites/pinkvio_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PinkVioletOrb[] = INCGFX_U16("graphics/battle_anims/sprites/pinkvio_orb.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PawPrint[] = INCGFX_U32("graphics/battle_anims/sprites/paw_print.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PawPrint[] = INCGFX_U16("graphics/battle_anims/sprites/paw_print.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_PurpleFlame[] = INCGFX_U32("graphics/battle_anims/sprites/purple_flame.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_PurpleFlame[] = INCGFX_U16("graphics/battle_anims/sprites/purple_flame.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RedBall[] = INCGFX_U32("graphics/battle_anims/sprites/red_ball.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RedBall[] = INCGFX_U16("graphics/battle_anims/sprites/red_ball.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SmellingsaltEffect[] = INCGFX_U32("graphics/battle_anims/sprites/smellingsalt_effect.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SmellingsaltEffect[] = INCGFX_U16("graphics/battle_anims/sprites/smellingsalt_effect.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_MagnifyingGlass[] = INCGFX_U32("graphics/battle_anims/sprites/magnifying_glass.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MagnifyingGlass[] = INCGFX_U16("graphics/battle_anims/sprites/magnifying_glass.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Meteor[] = INCGFX_U32("graphics/battle_anims/sprites/meteor.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Meteor[] = INCGFX_U16("graphics/battle_anims/sprites/meteor.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_FlatRock[] = INCGFX_U32("graphics/battle_anims/sprites/flat_rock.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_FlatRock[] = INCGFX_U16("graphics/battle_anims/sprites/flat_rock.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_TeraStarstormBeam[] = INCGFX_U32("graphics/battle_anims/sprites/starstorm_beam.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_TeraStarstormBeam[] = INCGFX_U16("graphics/battle_anims/sprites/starstorm_beam.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SaltParticle[] = INCGFX_U32("graphics/battle_anims/sprites/salt_particle.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_SaltParticle[] = INCGFX_U16("graphics/battle_anims/sprites/salt_particle.png", ".gbapal");

const u16 gBattleAnimUnusedPal_Unknown2[] = INCGFX_U16("graphics/battle_anims/unused/unknown_2.pal", ".gbapal");

#include "data/graphics/trainers.h"

const u32 gBattleVSFrame_Gfx[] = INCGFX_U32("graphics/battle_transitions/vs_frame.png", ".4bpp.smol", "-num_tiles 16 -Wnum_tiles");
const u32 gBattleVSFrame_Tilemap[] = INCGFX_U32("graphics/battle_transitions/vs_frame.bin", ".smolTM");
const u16 gBattleVSFrame_Pal[] = INCGFX_U16("graphics/battle_transitions/vs_frame.png", ".gbapal");

const u32 gVsLettersGfx[] = INCGFX_U32("graphics/battle_transitions/vs.png", ".4bpp.smol");

#include "data/graphics/battle_environment.h"

// Battle Dome
const u32 gDomeTourneyTree_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.png", ".4bpp.smol");
const u32 gDomeTourneyLine_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_line.png", ".4bpp.smol"); // the red glow mask for the tourney advancement lines
const u32 gDomeTourneyTree_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.bin", ".smolTM");
const u32 gDomeTourneyLineDown_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_line_down_map.bin", ".smolTM");
const u32 gDomeTourneyLineUp_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_line_up_map.bin", ".smolTM");
const u32 gDomeTourneyInfoCard_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card.png", ".4bpp.smol");
const u32 gDomeTourneyInfoCard_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card_tilemap.bin", ".smolTM");
const u32 gDomeTourneyInfoCardBg_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card_bg.bin", ".smolTM");
const u32 gDomeTourneyTreeButtons_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_buttons.png", ".4bpp.smol"); // exit/cancel and Poké Ball buttons
const u16 gDomeTourneyTree_Pal[] = INCGFX_U16("graphics/battle_frontier/tourney_tree.png", ".gbapal");
const u16 gDomeTourneyTreeButtons_Pal[] = INCGFX_U16("graphics/battle_frontier/tourney_buttons.pal", ".gbapal");
const u16 gDomeTourneyMatchCardBg_Pal[] = INCGFX_U16("graphics/battle_frontier/tourney_match_card_bg.pal", ".gbapal");

const u32 gBattleArenaJudgmentSymbolsGfx[] = INCGFX_U32("graphics/battle_frontier/arena_judgment_symbols.png", ".4bpp.smol");
const u16 gBattleArenaJudgmentSymbolsPalette[] = INCGFX_U16("graphics/battle_frontier/arena_judgment_symbols.png", ".gbapal");

const u16 gBattleWindowTextPalette[] = INCGFX_U16("graphics/battle_interface/text.pal", ".gbapal");
const u16 gPPTextPalette[] = INCGFX_U16("graphics/battle_interface/text_pp.pal", ".gbapal");

const u16 gTilesetAnims_BattleDomePals0_0[] = INCGFX_U16("graphics/battle_frontier/dome_anim1.pal", ".gbapal");
const u16 gTilesetAnims_BattleDomePals0_1[] = INCGFX_U16("graphics/battle_frontier/dome_anim2.pal", ".gbapal");
const u16 gTilesetAnims_BattleDomePals0_2[] = INCGFX_U16("graphics/battle_frontier/dome_anim3.pal", ".gbapal");
const u16 gTilesetAnims_BattleDomePals0_3[] = INCGFX_U16("graphics/battle_frontier/dome_anim4.pal", ".gbapal");

static const u16 sUnused0[] = {0x13F, 0x119, 0x113, 0x10E};

const u16 gBattlePyramidFloor_Pal[][16] = INCGFX_U16("graphics/battle_frontier/pyramid_floor.pal", ".gbapal");

const u32 gMultiBattleIntroBg_Opponent_Tilemap[] = INCGFX_U32("graphics/battle_frontier/multi_battle_intro_bg_opponent.bin", ".smolTM");
const u32 gMultiBattleIntroBg_Player_Tilemap[] = INCGFX_U32("graphics/battle_frontier/multi_battle_intro_bg_player.bin", ".smolTM");

#include "data/graphics/intro_scene.h"

const u32 gBattleAnimSpriteGfx_FlyingDirt[] = INCGFX_U32("graphics/battle_anims/sprites/flying_dirt.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_FlyingDirt[] = INCGFX_U16("graphics/battle_anims/sprites/flying_dirt.png", ".gbapal");

const u32 gBattleAnimBgTilemap_Sandstorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/sandstorm_brew.bin", ".smolTM");
const u32 gBattleAnimBgImage_Sandstorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/sandstorm_brew.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Windstorm[] = INCGFX_U16("graphics/battle_anims/backgrounds/windstorm_brew.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_MetalSoundWaves[] = INCGFX_U32("graphics/battle_anims/sprites/metal_sound_waves.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_MetalSoundWaves[] = INCGFX_U16("graphics/battle_anims/sprites/metal_sound_waves.png", ".gbapal");

const u32 gBattleAnimBgImage_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Ice[] = INCGFX_U16("graphics/battle_anims/backgrounds/ice.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_IcicleSpear[] = INCGFX_U32("graphics/battle_anims/sprites/icicle_spear.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_IcicleSpear[] = INCGFX_U16("graphics/battle_anims/sprites/icicle_spear.png", ".gbapal");

const u32 gContestNextTurnGfx[] = INCGFX_U32("graphics/contest/nextturn.png", ".4bpp.smol");
const u8 gContestNextTurnNumbersGfx[] = INCGFX_U8("graphics/contest/nextturn_numbers.png", ".4bpp");
const u8 gContestNextTurnRandomGfx[] = INCGFX_U8("graphics/contest/nextturn_random.png", ".4bpp");

const u32 gBattleAnimSpriteGfx_GlowyRedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_red_orb.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GlowyRedOrb[] = INCGFX_U16("graphics/battle_anims/sprites/glowy_red_orb.png", ".gbapal");
const u16 gBattleAnimSpritePal_GlowyGreenOrb[] = INCGFX_U16("graphics/battle_anims/sprites/glowy_green_orb.pal", ".gbapal");
const u16 gBattleAnimSpritePal_SleepPowder[] = INCGFX_U16("graphics/battle_anims/sprites/sleep_powder.pal", ".gbapal");
const u16 gBattleAnimSpritePal_StunSpore[] = INCGFX_U16("graphics/battle_anims/sprites/stun_spore.pal", ".gbapal");

const u32 gContestApplauseGfx[] = INCGFX_U32("graphics/contest/applause.png", ".4bpp.smol");
const u8 gContestApplauseMeterGfx[] = INCGFX_U8("graphics/contest/applause_meter.png", ".4bpp");

const u16 gContestPal[] = INCGFX_U16("graphics/contest/nextturn.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Splash[] = INCGFX_U32("graphics/battle_anims/sprites/splash.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Splash[] = INCGFX_U16("graphics/battle_anims/sprites/splash.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_SweatBead[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_bead.png", ".4bpp.smol");

const u32 gBattleAnimSpriteGfx_Pokeblock[] = INCGFX_U32("graphics/battle_anims/sprites/pokeblock.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Pokeblock[] = INCGFX_U16("graphics/battle_anims/sprites/pokeblock.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_Gem1[] = INCGFX_U32("graphics/battle_anims/sprites/gem_1.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Gem2[] = INCGFX_U32("graphics/battle_anims/sprites/gem_2.png", ".4bpp.smol");
const u32 gBattleAnimSpriteGfx_Gem3[] = INCGFX_U32("graphics/battle_anims/sprites/gem_3.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Gem1[] = INCGFX_U16("graphics/battle_anims/sprites/gem_1.png", ".gbapal");

const u32 gBattleAnimBgImage_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_InAir[] = INCGFX_U16("graphics/battle_anims/backgrounds/in_air.png", ".gbapal");
const u32 gBattleAnimBgTilemap_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_Protect[] = INCGFX_U32("graphics/battle_anims/sprites/protect.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Protect[] = INCGFX_U16("graphics/battle_anims/sprites/protect.png", ".gbapal");

const u16 gBattleAnimBackgroundImageMuddyWater_Pal[] = INCGFX_U16("graphics/battle_anims/backgrounds/water_muddy.pal", ".gbapal");

const u32 gEnemyMonShadow_Gfx[] = INCGFX_U32("graphics/battle_interface/enemy_mon_shadow.png", ".4bpp.smol");
const u32 gEnemyMonShadowsSized_Gfx[] = INCGFX_U32("graphics/battle_interface/enemy_mon_shadows_sized.png", ".4bpp.smol");

const u32 gBattleInterface_BallStatusBarGfx[] = INCGFX_U32("graphics/battle_interface/ball_status_bar.png", ".4bpp.smol");

const u32 gBattleAnimBgImage_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Ghost[] = INCGFX_U16("graphics/battle_anims/backgrounds/ghost.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.bin", ".smolTM");

const u16 gBattleAnimSpritePal_WhipHit[] = INCGFX_U16("graphics/battle_anims/sprites/whip_hit.pal", ".gbapal");

const u16 gBattleAnimBgPalette_SolarBeam[] = INCGFX_U16("graphics/battle_anims/backgrounds/solarbeam.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_SolarBeam[] = INCGFX_U32("graphics/battle_anims/backgrounds/solarbeam.bin", ".smolTM"); // Unused

const u16 gBattleAnimBgPalette_MagmaStorm[] = INCGFX_U16("graphics/battle_anims/backgrounds/magma_storm.pal", ".gbapal");

//new battle bgs

const u32 gBattleAnimBgImage_Hurricane[] = INCGFX_U32("graphics/battle_anims/backgrounds/hurricane.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Hurricane[] = INCGFX_U16("graphics/battle_anims/backgrounds/hurricane.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_Hurricane[] = INCGFX_U32("graphics/battle_anims/backgrounds/hurricane.bin", ".smolTM");

const u16 gBattleAnimBgPalette_RockWrecker[] = INCGFX_U16("graphics/battle_anims/backgrounds/rock_wrecker.pal", ".gbapal");

const u32 gBattleAnimBgTilemap_GigaImpactPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/giga_impact_player.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_GigaImpactOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/giga_impact_opponent.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_GigaImpactContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/giga_impact_contest.bin", ".smolTM");
const u32 gBattleAnimBgImage_GigaImpact[] = INCGFX_U32("graphics/battle_anims/backgrounds/giga_impact.png", ".4bpp.smol");
const u32 gBattleAnimBgImage_GigaImpactContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/giga_impact_contest.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_GigaImpact[] = INCGFX_U16("graphics/battle_anims/backgrounds/giga_impact.pal", ".gbapal");

const u32 gBattleAnimBgImage_SpacialRend[] = INCGFX_U32("graphics/battle_anims/backgrounds/spacial_rend.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_SpacialRend[] = INCGFX_U16("graphics/battle_anims/backgrounds/spacial_rend.pal", ".gbapal");

const u16 gBattleAnimBgPalette_SludgeWave[] = INCGFX_U16("graphics/battle_anims/backgrounds/sludge_wave.pal", ".gbapal");

const u32 gBattleAnimBgImage_Aeroblast[] = INCGFX_U32("graphics/battle_anims/backgrounds/aeroblast_tiles.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Aeroblast[] = INCGFX_U16("graphics/battle_anims/backgrounds/aeroblast.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_Aeroblast[] = INCGFX_U32("graphics/battle_anims/backgrounds/aeroblast_map.bin", ".smolTM");

const u16 gBattleAnimBgPalette_AuraSphere[] = INCGFX_U16("graphics/battle_anims/backgrounds/aura_sphere.pal", ".gbapal");

const u32 gBattleAnimBgImage_BlackholeEclipse[] = INCGFX_U32("graphics/battle_anims/backgrounds/blackhole_eclipse.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_BlackholeEclipse[] = INCGFX_U16("graphics/battle_anims/backgrounds/blackhole_eclipse.png", ".gbapal");
const u32 gBattleAnimBgTilemap_BlackholeEclipse[] = INCGFX_U32("graphics/battle_anims/backgrounds/blackhole_eclipse.bin", ".smolTM");

const u32 gBattleAnimBgImage_BloomDoom[] = INCGFX_U32("graphics/battle_anims/backgrounds/bloom_doom.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_BloomDoom[] = INCGFX_U16("graphics/battle_anims/backgrounds/bloom_doom.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_BloomDoom[] = INCGFX_U32("graphics/battle_anims/backgrounds/bloom_doom.bin", ".smolTM");

const u32 gBattleAnimBgImage_BoltStrike[] = INCGFX_U32("graphics/battle_anims/backgrounds/bolt_strike.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_BoltStrike[] = INCGFX_U16("graphics/battle_anims/backgrounds/bolt_strike.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_BoltStrike[] = INCGFX_U32("graphics/battle_anims/backgrounds/bolt_strike.bin", ".smolTM");

const u32 gBattleAnimBgImage_ClangorousSoulblaze[] = INCGFX_U32("graphics/battle_anims/backgrounds/clangorous_soulblaze.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_ClangorousSoulblaze[] = INCGFX_U16("graphics/battle_anims/backgrounds/clangorous_soulblaze.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_ClangorousSoulblaze[] = INCGFX_U32("graphics/battle_anims/backgrounds/clangorous_soulblaze.bin", ".smolTM");

const u16 gBattleAnimBgPalette_DynamaxCannon[] = INCGFX_U16("graphics/battle_anims/backgrounds/dynamax_cannon.pal", ".gbapal");

const u32 gBattleAnimBgImage_Fire1[] = INCGFX_U32("graphics/battle_anims/backgrounds/fire1.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Fire1[] = INCGFX_U16("graphics/battle_anims/backgrounds/fire1.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_Fire1[] = INCGFX_U32("graphics/battle_anims/backgrounds/fire1.bin", ".smolTM");

const u16 gBattleAnimBgPalette_Fire2[] = INCGFX_U16("graphics/battle_anims/backgrounds/fire2.pal", ".gbapal");

const u32 gBattleAnimBgImage_FocusBlast[] = INCGFX_U32("graphics/battle_anims/backgrounds/focus_blast.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_FocusBlast[] = INCGFX_U16("graphics/battle_anims/backgrounds/focus_blast.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_FocusBlast[] = INCGFX_U32("graphics/battle_anims/backgrounds/focus_blast.bin", ".smolTM");

const u16 gBattleAnimBgPalette_GarbageFalls[] = INCGFX_U16("graphics/battle_anims/backgrounds/garbage_falls.pal", ".gbapal");

const u16 gBattleAnimBgPalette_GunkShot[] = INCGFX_U16("graphics/battle_anims/backgrounds/gunk_shot.pal", ".gbapal");

const u32 gBattleAnimBgImage_HydroCannon[] = INCGFX_U32("graphics/battle_anims/backgrounds/hydro_cannon.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_HydroCannon[] = INCGFX_U16("graphics/battle_anims/backgrounds/hydro_cannon.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_HydroCannon[] = INCGFX_U32("graphics/battle_anims/backgrounds/hydro_cannon.bin", ".smolTM");
const u16 gBattleAnimBgPalette_Chloroblast[] = INCGFX_U16("graphics/battle_anims/backgrounds/chloroblast.pal", ".gbapal");

const u32 gBattleAnimBgImage_HydroPump[] = INCGFX_U32("graphics/battle_anims/backgrounds/hydro_pump.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_HydroPump[] = INCGFX_U16("graphics/battle_anims/backgrounds/hydro_pump.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_HydroPump[] = INCGFX_U32("graphics/battle_anims/backgrounds/hydro_pump.bin", ".smolTM");

const u16 gBattleAnimBgPalette_HyperBeam[] = INCGFX_U16("graphics/battle_anims/backgrounds/hyper_beam.pal", ".gbapal");

const u16 gBattleAnimBgPalette_HyperspaceFury[] = INCGFX_U16("graphics/battle_anims/backgrounds/hyperspace_fury.pal", ".gbapal");

const u32 gBattleAnimBgImage_InfernoOverdrive[] = INCGFX_U32("graphics/battle_anims/backgrounds/inferno_overdrive.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_InfernoOverdrive[] = INCGFX_U16("graphics/battle_anims/backgrounds/inferno_overdrive.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_InfernoOverdrive[] = INCGFX_U32("graphics/battle_anims/backgrounds/inferno_overdrive.bin", ".smolTM");

const u32 gBattleAnimBgImage_LeafStorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/leaf_storm.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_LeafStorm[] = INCGFX_U16("graphics/battle_anims/backgrounds/leaf_storm.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_LeafStorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/leaf_storm.bin", ".smolTM");

const u32 gBattleAnimBgImage_MaliciousMoonsault[] = INCGFX_U32("graphics/battle_anims/backgrounds/malicious_moonsault.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_MaliciousMoonsault[] = INCGFX_U16("graphics/battle_anims/backgrounds/malicious_moonsault.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_MaliciousMoonsault[] = INCGFX_U32("graphics/battle_anims/backgrounds/malicious_moonsault.bin", ".smolTM");

const u32 gBattleAnimBgImage_MaxLightning[] = INCGFX_U32("graphics/battle_anims/backgrounds/max_lightning.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_MaxLightning[] = INCGFX_U16("graphics/battle_anims/backgrounds/max_lightning.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_MaxLightning[] = INCGFX_U32("graphics/battle_anims/backgrounds/max_lightning.bin", ".smolTM");

const u32 gBattleAnimBgImage_NeverendingNightmare[] = INCGFX_U32("graphics/battle_anims/backgrounds/neverending_nightmare.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_NeverendingNightmare[] = INCGFX_U16("graphics/battle_anims/backgrounds/neverending_nightmare.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_NeverendingNightmare[] = INCGFX_U32("graphics/battle_anims/backgrounds/neverending_nightmare.bin", ".smolTM");

#if B_NEW_TERRAIN_BACKGROUNDS
const u32 gBattleAnimBgImage_ElectricTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_electric_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_ElectricTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/new_electric_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_ElectricTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_electric_terrain.bin", ".smolTM");

const u32 gBattleAnimBgImage_GrassyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_grassy_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_GrassyTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/new_grassy_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_GrassyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_grassy_terrain.bin", ".smolTM");

const u32 gBattleAnimBgImage_MistyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_misty_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_MistyTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/new_misty_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_MistyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_misty_terrain.bin", ".smolTM");

const u32 gBattleAnimBgImage_PsychicTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_psychic_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_PsychicTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/new_psychic_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_PsychicTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/new_psychic_terrain.bin", ".smolTM");
#else
const u32 gBattleAnimBgImage_PsychicTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_PsychicTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/psychic_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_PsychicTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic_terrain.bin", ".smolTM");

const u32 gBattleAnimBgImage_ElectricTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/electric_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_ElectricTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/electric_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_ElectricTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/electric_terrain.bin", ".smolTM");

const u32 gBattleAnimBgImage_GrassyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/grassy_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_GrassyTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/grassy_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_GrassyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/grassy_terrain.bin", ".smolTM");

const u32 gBattleAnimBgImage_MistyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/misty_terrain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_MistyTerrain[] = INCGFX_U16("graphics/battle_anims/backgrounds/misty_terrain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_MistyTerrain[] = INCGFX_U32("graphics/battle_anims/backgrounds/misty_terrain.bin", ".smolTM");
#endif

const u32 gBattleAnimBgImage_Nightmare[] = INCGFX_U32("graphics/battle_anims/backgrounds/nightmare.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Nightmare[] = INCGFX_U16("graphics/battle_anims/backgrounds/nightmare.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_Nightmare[] = INCGFX_U32("graphics/battle_anims/backgrounds/nightmare.bin", ".smolTM");

const u16 gBattleAnimBgPalette_PoisonFalls[] = INCGFX_U16("graphics/battle_anims/backgrounds/poison_falls.pal", ".gbapal");

const u16 gBattleAnimBgPalette_PsychicNew[] = INCGFX_U16("graphics/battle_anims/backgrounds/psychic_new.pal", ".gbapal");

const u32 gBattleAnimBgImage_ShatteredPsyche[] = INCGFX_U32("graphics/battle_anims/backgrounds/shattered_psyche.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_ShatteredPsyche[] = INCGFX_U16("graphics/battle_anims/backgrounds/shattered_psyche.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_ShatteredPsyche[] = INCGFX_U32("graphics/battle_anims/backgrounds/shattered_psyche.bin", ".smolTM");

const u32 gBattleAnimBgImage_RockField[] = INCGFX_U32("graphics/battle_anims/backgrounds/rock_field.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_RockDay[] = INCGFX_U16("graphics/battle_anims/backgrounds/rock_day.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_RockField[] = INCGFX_U32("graphics/battle_anims/backgrounds/rock_field.bin", ".smolTM");

const u16 gBattleAnimBgPalette_RockAfternoon[] = INCGFX_U16("graphics/battle_anims/backgrounds/rock_afternoon.pal", ".gbapal");

const u16 gBattleAnimBgPalette_RockNight[] = INCGFX_U16("graphics/battle_anims/backgrounds/rock_night.pal", ".gbapal");

const u32 gBattleAnimBgImage_SnuggleForever[] = INCGFX_U32("graphics/battle_anims/backgrounds/snuggle_forever.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_SnuggleForever[] = INCGFX_U16("graphics/battle_anims/backgrounds/snuggle_forever.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_SnuggleForever[] = INCGFX_U32("graphics/battle_anims/backgrounds/snuggle_forever.bin", ".smolTM");

const u32 gBattleAnimBgImage_SoulStealing7StarStrike[] = INCGFX_U32("graphics/battle_anims/backgrounds/soulstealing_7star_strike.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_SoulStealing7StarStrike[] = INCGFX_U16("graphics/battle_anims/backgrounds/soulstealing_7star_strike.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_SoulStealing7StarStrike[] = INCGFX_U32("graphics/battle_anims/backgrounds/soulstealing_7star_strike.bin", ".smolTM");

const u16 gBattleAnimBgPalette_TectonicRage[] = INCGFX_U16("graphics/battle_anims/backgrounds/tectonic_rage.pal", ".gbapal");

const u32 gBattleAnimBgImage_TrickRoom[] = INCGFX_U32("graphics/battle_anims/backgrounds/trick_room.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_TrickRoom[] = INCGFX_U16("graphics/battle_anims/backgrounds/trick_room.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_TrickRoom[] = INCGFX_U32("graphics/battle_anims/backgrounds/trick_room.bin", ".smolTM");

const u16 gBattleAnimBgPalette_MagicRoom[] = INCGFX_U16("graphics/battle_anims/backgrounds/magic_room.pal", ".gbapal");

const u16 gBattleAnimBgPalette_WonderRoom[] = INCGFX_U16("graphics/battle_anims/backgrounds/wonder_room.pal", ".gbapal");

const u32 gBattleAnimBgImage_TwinkleTackle[] = INCGFX_U32("graphics/battle_anims/backgrounds/twinkle_tackle.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_TwinkleTackle[] = INCGFX_U16("graphics/battle_anims/backgrounds/twinkle_tackle.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_TwinkleTackle[] = INCGFX_U32("graphics/battle_anims/backgrounds/twinkle_tackle.bin", ".smolTM");

const u32 gBattleAnimBgImage_WaterPulse[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_pulse.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_WaterPulse[] = INCGFX_U16("graphics/battle_anims/backgrounds/water_pulse.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_WaterPulse[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_pulse.bin", ".smolTM");

const u32 gBattleAnimBgImage_Waterfall[] = INCGFX_U32("graphics/battle_anims/backgrounds/waterfall.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Waterfall[] = INCGFX_U16("graphics/battle_anims/backgrounds/waterfall.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_Waterfall[] = INCGFX_U32("graphics/battle_anims/backgrounds/waterfall.bin", ".smolTM");

const u16 gBattleAnimBgPalette_DarkVoid[] = INCGFX_U16("graphics/battle_anims/backgrounds/dark_void.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_DarkVoid[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark_void.bin", ".smolTM");

const u32 gBattleAnimBgImage_ZMoveActivate[] = INCGFX_U32("graphics/battle_anims/backgrounds/zmove_activate.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_ZMoveActivate[] = INCGFX_U16("graphics/battle_anims/backgrounds/zmove_activate.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_ZMoveActivate[] = INCGFX_U32("graphics/battle_anims/backgrounds/zmove_activate.bin", ".smolTM");

const u32 gBattleAnimBgImage_ZMoveMountain[] = INCGFX_U32("graphics/battle_anims/backgrounds/zmove_mountain.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_ZMoveMountain[] = INCGFX_U16("graphics/battle_anims/backgrounds/zmove_mountain.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_ZMoveMountain[] = INCGFX_U32("graphics/battle_anims/backgrounds/zmove_mountain.bin", ".smolTM");

const u16 gBattleAnimBgPalette_SteelBeam[] = INCGFX_U16("graphics/battle_anims/backgrounds/steel_beam.pal", ".gbapal");

// misc
const u32 gBerryBlenderCenter_Gfx[] = INCGFX_U32("graphics/berry_blender/center.png", ".8bpp.smol");
const u32 gBerryBlenderOuter_Gfx[] = INCGFX_U32("graphics/berry_blender/outer.png", ".4bpp.smol");
const u32 gBerryBlenderOuter_Tilemap[] = INCGFX_U32("graphics/berry_blender/outer_map.bin", ".smolTM");

const u16 gBattleAnimBgPalette_Cosmic[] = INCGFX_U16("graphics/battle_anims/backgrounds/cosmic.png", ".gbapal");
const u32 gBattleAnimBgImage_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.png", ".4bpp.smol");
const u32 gBattleAnimBgTilemap_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.bin", ".smolTM");

const u16 gBattleAnimSpritePal_SlamHit2[] = INCGFX_U16("graphics/battle_anims/sprites/slam_hit_2.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_SlamHit2[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit_2.png", ".4bpp.smol");

const u32 gBattleAnimFogTilemap[] = INCGFX_U32("graphics/battle_anims/backgrounds/fog.bin", ".smolTM");

const u16 gBattleAnimSpritePal_WeatherBall[] = INCGFX_U16("graphics/battle_anims/sprites/weather_ball.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_WeatherBall[] = INCGFX_U32("graphics/battle_anims/sprites/weather_ball.png", ".4bpp.smol");

const u32 gBattleAnimBgTilemap_ScaryFacePlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_player.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_ScaryFaceOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_opponent.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_ScaryFaceContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_contest.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_Hail[] = INCGFX_U32("graphics/battle_anims/sprites/hail.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Hail[] = INCGFX_U16("graphics/battle_anims/sprites/hail.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_GreenSpike[] = INCGFX_U32("graphics/battle_anims/sprites/green_spike.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_GreenSpike[] = INCGFX_U16("graphics/battle_anims/sprites/green_spike.png", ".gbapal");
const u16 gBattleAnimSpritePal_WhiteCircleOfLight[] = INCGFX_U16("graphics/battle_anims/sprites/white_circle_of_light.pal", ".gbapal");
const u16 gBattleAnimSpritePal_GlowyBlueOrb[] = INCGFX_U16("graphics/battle_anims/sprites/glowy_blue_orb.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_Recycle[] = INCGFX_U32("graphics/battle_anims/sprites/recycle.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Recycle[] = INCGFX_U16("graphics/battle_anims/sprites/recycle.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_RedParticles[] = INCGFX_U32("graphics/battle_anims/sprites/red_particles.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_RedParticles[] = INCGFX_U16("graphics/battle_anims/sprites/red_particles.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_DirtMound[] = INCGFX_U32("graphics/battle_anims/sprites/dirt_mound.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_DirtMound[] = INCGFX_U16("graphics/battle_anims/sprites/dirt_mound.png", ".gbapal");

const u32 gBattleAnimBgImage_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Fissure[] = INCGFX_U16("graphics/battle_anims/backgrounds/fissure.png", ".gbapal");
const u32 gBattleAnimBgTilemap_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.bin", ".smolTM");

const u32 gBattleAnimSpriteGfx_Bird[] = INCGFX_U32("graphics/battle_anims/sprites/bird.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_Bird[] = INCGFX_U16("graphics/battle_anims/sprites/bird.png", ".gbapal");

const u32 gBattleAnimSpriteGfx_CrossImpact[] = INCGFX_U32("graphics/battle_anims/sprites/cross_impact.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_CrossImpact[] = INCGFX_U16("graphics/battle_anims/sprites/cross_impact.png", ".gbapal");

const u32 gBattleAnimBgImage_Surf[] = INCGFX_U32("graphics/battle_anims/backgrounds/water.png", ".4bpp.smol");
const u16 gBattleAnimBgPalette_Surf[] = INCGFX_U16("graphics/battle_anims/backgrounds/water.png", ".gbapal");

const u32 gBattleAnimBgTilemap_SurfOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_opponent.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_SurfPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_player.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_SurfContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_contest.bin", ".smolTM");

const u16 gBattleAnimSpritePal_Slash2[] = INCGFX_U16("graphics/battle_anims/sprites/slash_2.pal", ".gbapal");

const u32 gBattleAnimSpriteGfx_WhiteShadow[] = INCGFX_U32("graphics/battle_anims/sprites/white_shadow.png", ".4bpp.smol");
const u16 gBattleAnimSpritePal_WhiteShadow[] = INCGFX_U16("graphics/battle_anims/sprites/white_shadow.png", ".gbapal");

// Pledge Effect field status - Rainbow
const u32 gBattleAnimBgImage_RainbowPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/rainbow_player_tile.png", ".4bpp.smol");
const u32 gBattleAnimBgImage_RainbowOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/rainbow_opponent_tile.png", ".4bpp.smol");
const u16 gBattleAnimBGPalette_Rainbow[] = INCGFX_U16("graphics/battle_anims/backgrounds/rainbow_player_tile.png", ".gbapal");
const u32 gBattleAnimBgTilemap_RainbowPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/rainbow_player_tile.bin", ".smolTM");
const u32 gBattleAnimBgTilemap_RainbowOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/rainbow_opponent_tile.bin", ".smolTM");

// Pledge Effect field status - Swamp
const u32 gBattleAnimBgImage_Swamp[] = INCGFX_U32("graphics/battle_anims/backgrounds/swampswizzle.png", ".4bpp.smol");
const u16 gBattleAnimBGPalette_Swamp[] = INCGFX_U16("graphics/battle_anims/backgrounds/swampswizzle.pal", ".gbapal");
const u32 gBattleAnimBgTilemap_Swamp[] = INCGFX_U32("graphics/battle_anims/backgrounds/swampswizzle.bin", ".smolTM");

const u32 gPartyMenuBg_Gfx[] = INCGFX_U32("graphics/party_menu/bg.png", ".4bpp.smol", "-num_tiles 62 -Wnum_tiles");
const u16 gPartyMenuBg_Pal[] = INCGFX_U16("graphics/party_menu/bg.png", ".gbapal");
const u32 gPartyMenuBg_Tilemap[] = INCGFX_U32("graphics/party_menu/bg.bin", ".smolTM");

const u32 gPartyMenuPokeball_Gfx[] = INCGFX_U32("graphics/party_menu/pokeball.png", ".4bpp.smol");
const u32 gPartyMenuPokeballSmall_Gfx[] = INCGFX_U32("graphics/party_menu/pokeball_small.png", ".4bpp.smol"); //unused
const u16 gPartyMenuPokeball_Pal[] = INCGFX_U16("graphics/party_menu/pokeball.png", ".gbapal");

const u32 gStatusGfx_Icons[] = INCGFX_U32("graphics/interface/status_icons.png", ".4bpp.smol");
const u16 gStatusPal_Icons[] = INCGFX_U16("graphics/interface/status_icons.png", ".gbapal");

const u16 gCategoryIcons_Pal[] = INCGFX_U16("graphics/interface/category_icons.png", ".gbapal");
const u32 gCategoryIcons_Gfx[] = INCGFX_U32("graphics/interface/category_icons.png", ".4bpp.smol");

const u32 gMoveTypes_Gfx[] = INCGFX_U32("graphics/types/move_types.4bpp", ".smol");
const u16 gMoveTypes_Pal[] = INCBIN_U16("graphics/types/move_types.gbapal");

const u32 gSummaryMoveSelect_Gfx[] = INCGFX_U32("graphics/summary_screen/move_select.png", ".4bpp.smol");
const u16 gSummaryMoveSelect_Pal[] = INCGFX_U16("graphics/summary_screen/move_select.png", ".gbapal");

#if P_SUMMARY_SCREEN_IV_EV_TILESET
const u32 gSummaryScreen_Gfx[]                = INCGFX_U32("graphics/summary_screen/iv_ev_tiles.png", ".4bpp.smol");
#else
const u32 gSummaryScreen_Gfx[]                = INCGFX_U32("graphics/summary_screen/tiles.png", ".4bpp.smol");
#endif // P_SUMMARY_SCREEN_IV_EV_TILESET
const u16 gSummaryScreen_Pal[]                = INCGFX_U16("graphics/summary_screen/tiles.png", ".gbapal");
const u32 gSummaryPage_Info_Tilemap[]         = INCGFX_U32("graphics/summary_screen/page_info.bin", ".smolTM");
const u32 gSummaryPage_Skills_Tilemap[]       = INCGFX_U32("graphics/summary_screen/page_skills.bin", ".smolTM");
const u32 gSummaryPage_BattleMoves_Tilemap[]  = INCGFX_U32("graphics/summary_screen/page_battle_moves.bin", ".smolTM");
const u32 gSummaryPage_ContestMoves_Tilemap[] = INCGFX_U32("graphics/summary_screen/page_contest_moves.bin", ".smolTM");
const u32 gSummaryPage_InfoEgg_Tilemap[]      = INCGFX_U32("graphics/summary_screen/page_info_egg.bin", ".smolTM");

const u32 gBagMaleTiles[] = INCGFX_U32("graphics/bag/bag_male.png", ".4bpp.smol");
const u32 gBagFemaleTiles[] = INCGFX_U32("graphics/bag/bag_female.png", ".4bpp.smol");
const u16 gBagPalette[] = INCGFX_U16("graphics/bag/bag.pal", ".gbapal");

const u16 gBagScreenMale_Pal[] = INCGFX_U16("graphics/bag/menu_male.pal", ".gbapal");
const u16 gBagScreenFemale_Pal[] = INCGFX_U16("graphics/bag/menu_female.pal", ".gbapal");

const u32 gBagScreen_Gfx[] = INCGFX_U32("graphics/bag/menu.png", ".4bpp.smol", "-num_tiles 53 -Wnum_tiles");
const u32 gBagScreen_GfxTileMap[] = INCGFX_U32("graphics/bag/menu.bin", ".smolTM");

const u32 gBattlePyramidBag_Gfx[]          = INCGFX_U32("graphics/bag/bag_pyramid.png", ".4bpp.smol");
const u16 gBattlePyramidBag_Pal[]          = INCGFX_U16("graphics/bag/bag_pyramid.pal", ".gbapal"); // female palette is first and male is second.
const u32 gBattlePyramidBagTilemap[]       = INCGFX_U32("graphics/bag/menu_pyramid.bin", ".smolTM");
const u16 gBattlePyramidBagInterface_Pal[] = INCGFX_U16("graphics/bag/menu_pyramid.pal", ".gbapal");

const u32 gSwapLineGfx[] = INCGFX_U32("graphics/interface/swap_line.png", ".4bpp.smol");
const u16 gSwapLinePal[] = INCGFX_U16("graphics/interface/swap_line.png", ".gbapal");

const u32 gShopMenu_Gfx[] = INCGFX_U32("graphics/shop/menu.png", ".4bpp.smol");
const u16 gShopMenu_Pal[] = INCGFX_U16("graphics/shop/menu.png", ".gbapal");
const u32 gShopMenu_Tilemap[] = INCGFX_U32("graphics/shop/menu.bin", ".smolTM");
const u32 gShopMenuMoney_Gfx[] = INCGFX_U32("graphics/shop/money.png", ".4bpp.smol");

// Pokeblock

const u32 gMenuPokeblock_Gfx[] = INCGFX_U32("graphics/pokeblock/menu.png", ".4bpp.smol");
const u16 gMenuPokeblock_Pal[] = INCGFX_U16("graphics/pokeblock/menu.pal", ".gbapal");

const u32 gMenuPokeblockDevice_Gfx[] = INCGFX_U32("graphics/pokeblock/device.png", ".4bpp.smol");
const u16 gMenuPokeblockDevice_Pal[] = INCGFX_U16("graphics/pokeblock/device.png", ".gbapal");

const u32 gMenuPokeblock_Tilemap[] = INCGFX_U32("graphics/pokeblock/menu.bin", ".smolTM");

const u32 gPokeblock_Gfx[] = INCGFX_U32("graphics/pokeblock/pokeblock.png", ".4bpp.smol");
const u16 gPokeblockRed_Pal[] = INCGFX_U16("graphics/pokeblock/red.pal", ".gbapal");
const u16 gPokeblockBlue_Pal[] = INCGFX_U16("graphics/pokeblock/blue.pal", ".gbapal");
const u16 gPokeblockPink_Pal[] = INCGFX_U16("graphics/pokeblock/pink.pal", ".gbapal");
const u16 gPokeblockGreen_Pal[] = INCGFX_U16("graphics/pokeblock/green.pal", ".gbapal");
const u16 gPokeblockYellow_Pal[] = INCGFX_U16("graphics/pokeblock/yellow.pal", ".gbapal");
const u16 gPokeblockPurple_Pal[] = INCGFX_U16("graphics/pokeblock/purple.pal", ".gbapal");
const u16 gPokeblockIndigo_Pal[] = INCGFX_U16("graphics/pokeblock/indigo.pal", ".gbapal");
const u16 gPokeblockBrown_Pal[] = INCGFX_U16("graphics/pokeblock/brown.pal", ".gbapal");
const u16 gPokeblockLiteBlue_Pal[] = INCGFX_U16("graphics/pokeblock/liteblue.pal", ".gbapal");
const u16 gPokeblockOlive_Pal[] = INCGFX_U16("graphics/pokeblock/olive.pal", ".gbapal");
const u16 gPokeblockGray_Pal[] = INCGFX_U16("graphics/pokeblock/gray.pal", ".gbapal");
const u16 gPokeblockBlack_Pal[] = INCGFX_U16("graphics/pokeblock/black.pal", ".gbapal");
const u16 gPokeblockWhite_Pal[] = INCGFX_U16("graphics/pokeblock/white.pal", ".gbapal");
const u16 gPokeblockGold_Pal[] = INCGFX_U16("graphics/pokeblock/gold.pal", ".gbapal");

const u32 gPokeblockFeedBg_Tilemap[] = INCGFX_U32("graphics/pokeblock/feeding_bg.bin", ".smolTM");

#include "data/graphics/berries.h"
#include "data/graphics/rayquaza_scene.h"
#include "data/graphics/items.h"
#include "data/graphics/decorations.h"

const u16 gBattleAnimSpritePal_Shock3[] = INCGFX_U16("graphics/battle_anims/sprites/shock_3.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Shock3[] = INCGFX_U32("graphics/battle_anims/sprites/shock_3.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_WhiteFeather[] = INCGFX_U16("graphics/battle_anims/sprites/white_feather.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_WhiteFeather[] = INCGFX_U32("graphics/battle_anims/sprites/white_feather.png", ".4bpp.smol");

const u16 gBattleAnimSpritePal_Sparkle6[] = INCGFX_U16("graphics/battle_anims/sprites/sparkle_6.png", ".gbapal");
const u32 gBattleAnimSpriteGfx_Sparkle6[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_6.png", ".4bpp.smol");

const u16 gCableCarBg_Pal[]    = INCGFX_U16("graphics/cable_car/bg.png", ".gbapal");
const u16 gCableCar_Pal[]      = INCGFX_U16("graphics/cable_car/cable_car.png", ".gbapal");
const u32 gCableCarBg_Gfx[]    = INCGFX_U32("graphics/cable_car/bg.png", ".4bpp.smol");
const u32 gCableCar_Gfx[]      = INCGFX_U32("graphics/cable_car/cable_car.png", ".4bpp.smol");
const u32 gCableCarDoor_Gfx[]  = INCGFX_U32("graphics/cable_car/door.png", ".4bpp.smol");
const u32 gCableCarCable_Gfx[] = INCGFX_U32("graphics/cable_car/cable.png", ".4bpp.smol");

// Roulette
const u32 gRouletteMenu_Gfx[] = INCGFX_U32("graphics/roulette/window.png", ".4bpp.smol");
const u32 gRouletteWheel_Gfx[] = INCGFX_U32("graphics/roulette/wheel.png", ".8bpp.smol");
const u32 gRouletteCenter_Gfx[] = INCGFX_U32("graphics/roulette/center.png", ".4bpp.smol");
const u32 gRouletteHeaders_Gfx[] = INCGFX_U32("graphics/roulette/headers.png", ".4bpp.smol");
const u32 gRouletteCredit_Gfx[] = INCGFX_U32("graphics/roulette/credit.png", ".4bpp.smol");
const u32 gRouletteNumbers_Gfx[] = INCGFX_U32("graphics/roulette/numbers.png", ".4bpp.smol");
const u32 gRouletteMultiplier_Gfx[] = INCGFX_U32("graphics/roulette/multiplier.png", ".4bpp.smol");

#include "data/graphics/mail.h"

const u16 gFrontierFactoryMenu_Pal[] = INCGFX_U16("graphics/battle_frontier/factory_screen/menu.png", ".gbapal");
const u16 gFrontierFactoryMenu_Gfx[] = INCGFX_U16("graphics/battle_frontier/factory_screen/menu.png", ".4bpp");
const u16 gFrontierFactoryMenu_Tilemap[] = INCBIN_U16("graphics/battle_frontier/factory_screen/menu.bin");

const u32 gFrontierPassMedals_Gfx[] = INCGFX_U32("graphics/frontier_pass/medals.png", ".4bpp.smol");

const u16 gFrontierPassCursor_Pal[] = INCGFX_U16("graphics/frontier_pass/cursor.png", ".gbapal");

const u16 gFrontierPassMapCursor_Pal[] = INCGFX_U16("graphics/frontier_pass/map_cursor.png", ".gbapal");

const u16 gFrontierPassMedalsSilver_Pal[] = INCGFX_U16("graphics/frontier_pass/silver.pal", ".gbapal");
const u16 gFrontierPassMedalsGold_Pal[] = INCGFX_U16("graphics/frontier_pass/gold.pal", ".gbapal");

// Pokédex
const u16 gPokedexBgHoenn_Pal[] = INCGFX_U16("graphics/pokedex/bg_hoenn.pal", ".gbapal");
const u16 gPokedexSearchResults_Pal[] = INCGFX_U16("graphics/pokedex/search_results_bg.pal", ".gbapal");
const u16 gPokedexBgNational_Pal[] = INCGFX_U16("graphics/pokedex/bg_national.pal", ".gbapal");
const u32 gPokedexMenu_Gfx[] = INCGFX_U32("graphics/pokedex/menu.png", ".4bpp.smol");
const u32 gPokedexInterface_Gfx[] = INCGFX_U32("graphics/pokedex/interface.png", ".4bpp.smol");
const u32 gUnused_PokedexNoBall[] = INCGFX_U32("graphics/pokedex/noball_unused.png", ".4bpp.smol");
const u32 gPokedexStartMenuMain_Tilemap[] = INCGFX_U32("graphics/pokedex/start_menu_main.bin", ".smolTM");
const u32 gPokedexStartMenuSearchResults_Tilemap[] = INCGFX_U32("graphics/pokedex/start_menu_search_results.bin", ".smolTM");
const u32 gPokedexList_Tilemap[] = INCGFX_U32("graphics/pokedex/list.bin", ".smolTM");
const u32 gPokedexListUnderlay_Tilemap[] = INCGFX_U32("graphics/pokedex/list_underlay.bin", ".smolTM");
const u32 gPokedexSizeScreen_Tilemap[] = INCGFX_U32("graphics/pokedex/size_screen.bin", ".smolTM");
const u32 gPokedexScreenSelectBarMain_Tilemap[] = INCGFX_U32("graphics/pokedex/screen_select_bar_main.bin", ".smolTM");
const u32 gPokedexScreenSelectBarSubmenu_Tilemap[] = INCGFX_U32("graphics/pokedex/screen_select_bar_submenu.bin", ".smolTM");
const u32 gPokedexInfoScreen_Tilemap[] = INCGFX_U32("graphics/pokedex/info_screen.bin", ".smolTM");
const u32 gPokedexCryScreen_Tilemap[] = INCGFX_U32("graphics/pokedex/cry_screen.bin", ".smolTM");
const u16 gPokedexSearchMenu_Pal[] = INCGFX_U16("graphics/pokedex/search_menu.pal", ".gbapal");
const u32 gPokedexSearchMenu_Gfx[] = INCGFX_U32("graphics/pokedex/search_menu.png", ".4bpp.smol");
const u32 gPokedexSearchMenuNational_Tilemap[] = INCGFX_U32("graphics/pokedex/search_menu_national.bin", ".smolTM");
const u32 gPokedexSearchMenuHoenn_Tilemap[] = INCGFX_U32("graphics/pokedex/search_menu_hoenn.bin", ".smolTM");

const u16 gSummaryScreen_MoveEffect_Battle_Tilemap[] = INCBIN_U16("graphics/summary_screen/effect_battle.bin");
const u16 gSummaryScreen_MoveEffect_Contest_Tilemap[] = INCBIN_U16("graphics/summary_screen/effect_contest.bin");
const u16 gSummaryScreen_MoveEffect_Cancel_Tilemap[] = INCBIN_U16("graphics/summary_screen/effect_cancel.bin");

const u16 gIntroCopyright_Pal[] = INCGFX_U16("graphics/intro/copyright.png", ".gbapal");
const u32 gIntroCopyright_Gfx[] = INCGFX_U32("graphics/intro/copyright.png", ".4bpp.smol");
const u32 gIntroCopyright_Tilemap[] = INCGFX_U32("graphics/intro/copyright.bin", ".smolTM");

const u16 gPokedexAreaScreenAreaUnknown_Pal[] = INCGFX_U16("graphics/pokedex/area_unknown.png", ".gbapal");
const u32 gPokedexAreaScreenAreaUnknown_Gfx[] = INCGFX_U32("graphics/pokedex/area_unknown.png", ".4bpp.smol");

const u16 gMenuInfoElements1_Pal[] = INCGFX_U16("graphics/interface/menu_info1.pal", ".gbapal");
const u16 gMenuInfoElements2_Pal[] = INCGFX_U16("graphics/interface/menu_info2.pal", ".gbapal");
const u16 gMenuInfoElements3_Pal[] = INCGFX_U16("graphics/interface/menu_info3.pal", ".gbapal");
const u8 gMenuInfoElements_Gfx[] = INCGFX_U8("graphics/interface/menu_info.png", ".4bpp");

const u8 gBagMenuHMIcon_Gfx[] = INCGFX_U8("graphics/bag/hm.png", ".4bpp");

// contest results screen

const u16 gContestResultsTitle_Normal_Tilemap[] = INCBIN_U16("graphics/contest/results_screen/title_normal.bin");
const u16 gContestResultsTitle_Super_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_super.bin");
const u16 gContestResultsTitle_Hyper_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_hyper.bin");
const u16 gContestResultsTitle_Master_Tilemap[] = INCBIN_U16("graphics/contest/results_screen/title_master.bin");
const u16 gContestResultsTitle_Link_Tilemap[]   = INCBIN_U16("graphics/contest/results_screen/title_link.bin");
const u16 gContestResultsTitle_Cool_Tilemap[]   = INCBIN_U16("graphics/contest/results_screen/title_cool.bin");
const u16 gContestResultsTitle_Beauty_Tilemap[] = INCBIN_U16("graphics/contest/results_screen/title_beauty.bin");
const u16 gContestResultsTitle_Cute_Tilemap[]   = INCBIN_U16("graphics/contest/results_screen/title_cute.bin");
const u16 gContestResultsTitle_Smart_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_smart.bin");
const u16 gContestResultsTitle_Tough_Tilemap[]  = INCBIN_U16("graphics/contest/results_screen/title_tough.bin");
const u16 gContestResultsTitle_Tilemap[]        = INCBIN_U16("graphics/contest/results_screen/title.bin");

// PokéNav

const u16 gPokenavCondition_Pal[] = INCGFX_U16("graphics/pokenav/condition/graph.png", ".gbapal");
const u32 gPokenavCondition_Gfx[] = INCGFX_U32("graphics/pokenav/condition/graph.png", ".4bpp.smol");
const u32 gPokenavCondition_Tilemap[] = INCGFX_U32("graphics/pokenav/condition/graph.bin", ".smolTM");

const u16 gPokenavOptions_Tilemap[] = INCBIN_U16("graphics/pokenav/options/options.bin");
const u32 gPokenavOptions_Gfx[] = INCGFX_U32("graphics/pokenav/options/options.4bpp", ".smol");
const u16 gPokenavOptions_Pal[] = INCGFX_U16("graphics/pokenav/options/options.pal", ".gbapal");

const u16 gPokenavHeader_Pal[] = INCGFX_U16("graphics/pokenav/header.png", ".gbapal");
const u32 gPokenavHeader_Gfx[] = INCGFX_U32("graphics/pokenav/header.png", ".4bpp.smol", "-num_tiles 53 -Wnum_tiles"); // TODO: use width 9 and makefile rule for cleanliness, make wasnt behaving, didnt want to apply num_tiles to this
const u32 gPokenavHeader_Tilemap[] = INCGFX_U32("graphics/pokenav/header.bin", ".smolTM");

const u16 gPokenavLeftHeader_Pal[] = INCGFX_U16("graphics/pokenav/left_headers/palette.pal", ".gbapal");
const u32 gPokenavLeftHeaderBeauty_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/beauty.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderSmart_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/smart.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderCondition_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/condition.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderCute_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/cute.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderMatchCall_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/match_call.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderMainMenu_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/main_menu.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderHoennMap_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/hoenn_map.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderRibbons_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/ribbons.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderSearch_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/search.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderTough_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/tough.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderCool_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/cool.png", ".4bpp.smol");
const u32 gPokenavLeftHeaderParty_Gfx[] = INCGFX_U32("graphics/pokenav/left_headers/party.png", ".4bpp.smol");

const u16 gPokenavMessageBox_Pal[] = INCGFX_U16("graphics/pokenav/message.png", ".gbapal");
const u32 gPokenavMessageBox_Gfx[] = INCGFX_U32("graphics/pokenav/message.png", ".4bpp.smol");
const u32 gPokenavMessageBox_Tilemap[] = INCGFX_U32("graphics/pokenav/message.bin", ".smolTM");

const u16 gRegionMapCityZoomTiles_Pal[] = INCGFX_U16("graphics/pokenav/region_map/zoom_tiles.png", ".gbapal");
const u32 gRegionMapCityZoomText_Gfx[] = INCGFX_U32("graphics/pokenav/region_map/city_zoom_text.png", ".4bpp.smol");

const u16 gPokenavConditionCancel_Pal[] = INCGFX_U16("graphics/pokenav/condition/cancel.pal", ".gbapal");
const u8 gPokenavConditionCancel_Gfx[] = INCGFX_U8("graphics/pokenav/condition/cancel.png", ".4bpp");

const u16 gMonMarkingsMenu_Pal[] = INCGFX_U16("graphics/interface/mon_markings_menu.png", ".gbapal");
const u8 gMonMarkingsMenu_Gfx[] = INCGFX_U8("graphics/interface/mon_markings_menu.png", ".4bpp");

const u16 gBerryBlenderMiscPalette[] = INCGFX_U16("graphics/berry_blender/misc.pal", ".gbapal");
const u16 gBerryBlenderArrowPalette[] = INCGFX_U16("graphics/berry_blender/arrow.png", ".gbapal");
const u8 gBerryBlenderBetaArrow_Gfx[] = INCGFX_U8("graphics/berry_blender/arrow_old.png", ".4bpp"); //unused
const u8 gBerryBlenderScoreSymbols_Gfx[] = INCGFX_U8("graphics/berry_blender/score_symbols.png", ".4bpp");
const u8 gBerryBlenderParticles_Gfx[] = INCGFX_U8("graphics/berry_blender/particles.png", ".4bpp");
static const u8 sEmpty0[0x120] = {0};
const u8 gBerryBlenderCountdownNumbers_Gfx[] = INCGFX_U8("graphics/berry_blender/countdown_numbers.png", ".4bpp");
const u8 gBerryBlenderStart_Gfx[] = INCGFX_U8("graphics/berry_blender/start.png", ".4bpp");
static const u8 sEmpty1[0x200] = {0};
const u8 gBerryBlenderPlayerArrow_Gfx[] = INCGFX_U8("graphics/berry_blender/arrow.png", ".4bpp");
static const u8 sEmpty2[0x2C0] = {0};

const u16 gEasyChatRectangleCursor_Pal[] = INCGFX_U16("graphics/easy_chat/rectangle_cursor.png", ".gbapal");
const u32 gEasyChatRectangleCursor_Gfx[] = INCGFX_U32("graphics/easy_chat/rectangle_cursor.png", ".4bpp.smol");

const u16 gEasyChatButtonWindow_Pal[] = INCGFX_U16("graphics/easy_chat/button_window.png", ".gbapal");
const u32 gEasyChatButtonWindow_Gfx[] = INCGFX_U32("graphics/easy_chat/button_window.png", ".4bpp.smol");

const u32 gEasyChatMode_Gfx[] = INCGFX_U32("graphics/easy_chat/mode.png", ".4bpp.smol");
const u16 gEasyChatMode_Pal[] = INCGFX_U16("graphics/easy_chat/mode.png", ".gbapal");

const u32 gEasyChatWindow_Gfx[] = INCGFX_U32("graphics/easy_chat/window.png", ".4bpp.smol"); // uses mode pal
const u32 gEasyChatWindow_Tilemap[] = INCGFX_U32("graphics/easy_chat/window.bin", ".smolTM");

const u16 gWallClockMale_Pal[]      = INCGFX_U16("graphics/wallclock/male.pal", ".gbapal");
const u16 gWallClockFemale_Pal[]    = INCGFX_U16("graphics/wallclock/female.pal", ".gbapal");
const u32 gWallClock_Gfx[]          = INCGFX_U32("graphics/wallclock/clock.png", ".4bpp.smol");
const u32 gWallClockStart_Tilemap[] = INCGFX_U32("graphics/wallclock/clock_start.bin", ".smolTM");
const u32 gWallClockView_Tilemap[]  = INCGFX_U32("graphics/wallclock/clock_view.bin", ".smolTM");

const u16 gUsePokeblockCondition_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/condition.png", ".gbapal");
const u32 gUsePokeblockCondition_Gfx[] = INCGFX_U32("graphics/pokeblock/use_screen/condition.png", ".4bpp.smol");

const u16 gUsePokeblockUpDown_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/updown.png", ".gbapal");
const u8 gUsePokeblockUpDown_Gfx[] = INCGFX_U8("graphics/pokeblock/use_screen/updown.png", ".4bpp");

const u16 gUsePokeblockGraph_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/graph.png", ".gbapal");
const u32 gUsePokeblockGraph_Gfx[] = INCGFX_U32("graphics/pokeblock/use_screen/graph.png", ".4bpp.smol");

const u32 gUsePokeblockGraph_Tilemap[] = INCGFX_U32("graphics/pokeblock/use_screen/graph.bin", ".smolTM");
const u16 gUsePokeblockNatureWin_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/nature.pal", ".gbapal");

#include "data/graphics/slot_machine.h"

// trainer card

const u16 gHoennTrainerCardGreen_Pal[] = INCGFX_U16("graphics/trainer_card/green.pal", ".gbapal");
const u32 gHoennTrainerCard_Gfx[] = INCGFX_U32("graphics/trainer_card/tiles.png", ".4bpp.smol");
const u32 gHoennTrainerCardBg_Tilemap[] = INCGFX_U32("graphics/trainer_card/bg.bin", ".smolTM");
const u32 gHoennTrainerCardFront_Tilemap[] = INCGFX_U32("graphics/trainer_card/front.bin", ".smolTM");
const u32 gHoennTrainerCardBack_Tilemap[] = INCGFX_U32("graphics/trainer_card/back.bin", ".smolTM");
const u32 gHoennTrainerCardFrontLink_Tilemap[] = INCGFX_U32("graphics/trainer_card/front_link.bin", ".smolTM");

const u16 gKantoTrainerCardBlue_Pal[] = INCGFX_U16("graphics/trainer_card/frlg/blue.pal", ".gbapal");
const u32 gKantoTrainerCard_Gfx[] = INCGFX_U32("graphics/trainer_card/frlg/tiles.png", ".4bpp.smol");
const u32 gKantoTrainerCardBg_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/bg.bin", ".smolTM");
const u32 gKantoTrainerCardFront_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/front.bin", ".smolTM");
const u32 gKantoTrainerCardBack_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/back.bin", ".smolTM");
const u32 gKantoTrainerCardFrontLink_Tilemap[] = INCGFX_U32("graphics/trainer_card/frlg/front_link.bin", ".smolTM");

// Pokémon storage system

const u32 gStorageSystemMenu_Gfx[] = INCGFX_U32("graphics/pokemon_storage/menu.png", ".4bpp.smol");
const u16 gStorageSystemPartyMenu_Pal[] = INCGFX_U16("graphics/pokemon_storage/party_menu.pal", ".gbapal");
const u32 gStorageSystemPartyMenu_Tilemap[] = INCGFX_U32("graphics/pokemon_storage/party_menu.bin", ".smolTM");

// naming screen

const u16 gNamingScreenMenu_Pal[6][16] =
{
    INCGFX_U16("graphics/naming_screen/menu.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/page_swap_upper.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/page_swap_lower.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/page_swap_others.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/buttons.pal", ".gbapal"),
    INCGFX_U16("graphics/naming_screen/cursor.pal", ".gbapal"),
};
const u32 gNamingScreenMenu_Gfx[]                = INCGFX_U32("graphics/naming_screen/menu.png", ".4bpp.smol");
const u32 gNamingScreenPageSwapFrame_Gfx[]       = INCGFX_U32("graphics/naming_screen/page_swap_frame.png", ".4bpp");
const u32 gNamingScreenBackButton_Gfx[]          = INCGFX_U32("graphics/naming_screen/back_button.png", ".4bpp");
const u32 gNamingScreenOKButton_Gfx[]            = INCGFX_U32("graphics/naming_screen/ok_button.png", ".4bpp");
const u32 gNamingScreenPageSwapUpper_Gfx[]       = INCGFX_U32("graphics/naming_screen/page_swap_upper.png", ".4bpp");
const u32 gNamingScreenPageSwapLower_Gfx[]       = INCGFX_U32("graphics/naming_screen/page_swap_lower.png", ".4bpp");
const u32 gNamingScreenPageSwapOthers_Gfx[]      = INCGFX_U32("graphics/naming_screen/page_swap_others.png", ".4bpp");
const u32 gNamingScreenCursor_Gfx[]              = INCGFX_U32("graphics/naming_screen/cursor.png", ".4bpp", "-num_tiles 5 -Wnum_tiles");
const u32 gNamingScreenCursorSquished_Gfx[]      = INCGFX_U32("graphics/naming_screen/cursor_squished.png", ".4bpp", "-num_tiles 5 -Wnum_tiles");
const u32 gNamingScreenCursorFilled_Gfx[]        = INCGFX_U32("graphics/naming_screen/cursor_filled.png", ".4bpp", "-num_tiles 5 -Wnum_tiles");
const u32 gNamingScreenPageSwapButton_Gfx[]      = INCGFX_U32("graphics/naming_screen/page_swap_button.png", ".4bpp");
const u32 gNamingScreenInputArrow_Gfx[]          = INCGFX_U32("graphics/naming_screen/input_arrow.png", ".4bpp");
const u32 gNamingScreenUnderscore_Gfx[]          = INCGFX_U32("graphics/naming_screen/underscore.png", ".4bpp");
const u32 gNamingScreenBackground_Tilemap[]      = INCGFX_U32("graphics/naming_screen/background.bin", ".smolTM");
const u32 gNamingScreenKeyboardUpper_Tilemap[]   = INCGFX_U32("graphics/naming_screen/keyboard_upper.bin", ".smolTM");
const u32 gNamingScreenKeyboardLower_Tilemap[]   = INCGFX_U32("graphics/naming_screen/keyboard_lower.bin", ".smolTM");
const u32 gNamingScreenKeyboardSymbols_Tilemap[] = INCGFX_U32("graphics/naming_screen/keyboard_symbols.bin", ".smolTM");

// union room chat
const u16 gUnionRoomChat_Background_Pal[] = INCGFX_U16("graphics/union_room_chat/background.png", ".gbapal");
const u32 gUnionRoomChat_Background_Gfx[] = INCGFX_U32("graphics/union_room_chat/background.png", ".4bpp.smol");
const u32 gUnionRoomChat_Background_Tilemap[] = INCGFX_U32("graphics/union_room_chat/background.bin", ".smolTM");
const u16 gUnionRoomChat_InputText_Pal[] = INCGFX_U16("graphics/union_room_chat/input_text.pal", ".gbapal");
const u16 gUnionRoomChat_Keyboard_Pal[] = INCGFX_U16("graphics/union_room_chat/keyboard.png", ".gbapal");
const u32 gUnionRoomChat_Keyboard_Gfx[] = INCGFX_U32("graphics/union_room_chat/keyboard.png", ".4bpp.smol");
const u32 gUnionRoomChat_Keyboard_Tilemap[] = INCGFX_U32("graphics/union_room_chat/keyboard.bin", ".smolTM");
const u32 gUnionRoomChat_RButtonLabels[] = INCGFX_U32("graphics/union_room_chat/r_button_labels.png", ".4bpp.smol");

const u16 ALIGNED(4) gTilesetPalettes_General[][16] =
{
    INCGFX_U16("data/tilesets/primary/general/palettes/00.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/01.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/02.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/03.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/04.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/05.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/06.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/07.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/08.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/09.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/10.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/11.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/12.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/13.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/14.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/15.pal", ".gbapal"),
};

const u32 gTilesetTiles_General[] = INCGFX_U32("data/tilesets/primary/general/tiles.png", ".4bpp.smol");

// trade/egg hatch

const u16 gTradeGba_Pal[] = INCGFX_U16("graphics/trade/gba.pal", ".gbapal");
const u16 gTradeGba2_Pal[] = INCGFX_U16("graphics/trade/gba_pal2.pal", ".gbapal");
const u8 gTradeGba_Gfx[] = INCGFX_U8("graphics/trade/gba.png", ".4bpp");

static const u16 sEmptyPal[16] = {0};

#include "data/graphics/berry_fix.h"

// Trade
const u16 gTradeMenu_Pal[] = INCGFX_U16("graphics/trade/menu.pal", ".gbapal");
const u16 gTradeCursor_Pal[] = INCGFX_U16("graphics/trade/cursor.pal", ".gbapal");
const u8 gTradeMenu_Gfx[] = INCGFX_U8("graphics/trade/menu.png", ".4bpp");
const u8 gTradeCursor_Gfx[] = INCGFX_U8("graphics/trade/cursor.png", ".4bpp");
const u16 gTradeUnused_Tilemap[] = INCBIN_U16("graphics/trade/unused.bin");
const u16 gTradeMenu_Tilemap[] = INCBIN_U16("graphics/trade/menu.bin");
const u16 gTradeMenuMonBox_Tilemap[] = INCBIN_U16("graphics/trade/menu_mon_box.bin");

const u16 gMessageBox_Pal[] = INCGFX_U16("graphics/text_window/message_box.png", ".gbapal");
const u8 gMessageBox_Gfx[] = INCGFX_U8("graphics/text_window/message_box.png", ".4bpp");
const u8 gSignpostWindow_Gfx[] = INCGFX_U8("graphics/text_window/signpost.png", ".4bpp");

const u32 gWallpaperIcon_Cross[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/cross.png", ".4bpp.smol");
const u32 gWallpaperIcon_Bolt[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/bolt.png", ".4bpp.smol");
const u32 gWallpaperIcon_Plusle[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/plusle.png", ".4bpp.smol");

const u16 gWallpaperPalettes_Horizontal[][16] =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/horizontal/bg.png", ".gbapal"),
};

const u32 gWallpaperTiles_Horizontal[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/horizontal/tiles.4bpp", ".smol");
const u32 gWallpaperTilemap_Horizontal[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/horizontal/tilemap.bin", ".smolTM");

const u16 gWallpaperPalettes_Ribbon[][16] =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/ribbon/frame.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/ribbon/bg.png", ".gbapal"),
};

const u32 gWallpaperTiles_Ribbon[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/ribbon/tiles.4bpp", ".smol");
const u32 gWallpaperTilemap_Ribbon[] = INCGFX_U32("graphics/pokemon_storage/wallpapers/ribbon/tilemap.bin", ".smolTM");

const u16 gPokenavRibbonsSummaryBg_Pal[] = INCGFX_U16("graphics/pokenav/ribbons/summary_bg.png", ".gbapal");
const u32 gPokenavRibbonsSummaryBg_Gfx[] = INCGFX_U32("graphics/pokenav/ribbons/summary_bg.png", ".4bpp.smol");
const u32 gPokenavRibbonsSummaryBg_Tilemap[] = INCGFX_U32("graphics/pokenav/ribbons/summary_bg.bin", ".smolTM");

const u16 gMonIconPalettes[][16] =
{
    INCGFX_U16("graphics/pokemon/icon_palettes/pal0.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/pal1.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/pal2.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/pal3.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/pal4.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/pal5.pal", ".gbapal"),
};

const u16 gTitleScreenBgPalettes[]         = INCBIN_U16("graphics/title_screen/pokemon_logo.gbapal",
                                                        "graphics/title_screen/rayquaza_and_clouds.gbapal");
const u16 gTitleScreenEmeraldVersionPal[]  = INCGFX_U16("graphics/title_screen/emerald_version.png", ".gbapal");
const u32 gTitleScreenCloudsTilemap[]      = INCGFX_U32("graphics/title_screen/clouds.bin", ".smolTM");
const u32 gTitleScreenPokemonLogoGfx[]     = INCGFX_U32("graphics/title_screen/pokemon_logo.png", ".8bpp.smol");
const u32 gTitleScreenEmeraldVersionGfx[]  = INCGFX_U32("graphics/title_screen/emerald_version.png", ".8bpp.smol", "-mwidth 8 -mheight 4");
const u16 gTitleScreenPressStartPal[]      = INCGFX_U16("graphics/title_screen/press_start.png", ".gbapal");
const u32 gTitleScreenPressStartGfx[]      = INCGFX_U32("graphics/title_screen/press_start.png", ".4bpp.smol", "-mwidth 4 -mheight 1 -num_tiles 48 -Wnum_tiles");
const u32 gTitleScreenPokemonLogoTilemap[] = INCGFX_U32("graphics/title_screen/pokemon_logo.bin", ".smolTM");

const u16 gFrontierPassBg_Pal[][16]                      = INCGFX_U16("graphics/frontier_pass/bg.png", ".gbapal"); // 8 x 16
const u32 gFrontierPassBg_Gfx[]                          = INCGFX_U32("graphics/frontier_pass/bg.png", ".4bpp.smol");
const u32 gFrontierPassMapAndCard_Gfx[]                  = INCGFX_U32("graphics/frontier_pass/map_and_card.png", ".8bpp.smol");
const u32 gFrontierPassBg_Tilemap[]                      = INCGFX_U32("graphics/frontier_pass/bg.bin", ".smolTM");
const u32 gFrontierPassCancelButton_Tilemap[]            = INCBIN_U32("graphics/frontier_pass/cancel.bin");
const u32 gFrontierPassCancelButtonHighlighted_Tilemap[] = INCBIN_U32("graphics/frontier_pass/cancel_highlighted.bin");

// Berry Crush
const u16 gBerryCrush_Crusher_Pal[] = INCGFX_U16("graphics/berry_crush/crusher.png", ".gbapal");
const u32 gBerryCrush_Crusher_Gfx[] = INCGFX_U32("graphics/berry_crush/crusher.png", ".4bpp.smol");
const u32 gBerryCrush_TextWindows_Tilemap[] = INCGFX_U32("graphics/berry_crush/text_windows.bin", ".smolTM");

const u32 gBattleIcons_Gfx1[] = INCGFX_U32("graphics/types/battle_icons1.png", ".4bpp.smol");
const u32 gBattleIcons_Gfx2[] = INCGFX_U32("graphics/types/battle_icons2.png", ".4bpp.smol");
const u16 gBattleIcons_Pal1[] = INCGFX_U16("graphics/types/battle_icons1.pal", ".gbapal");
const u16 gBattleIcons_Pal2[] = INCGFX_U16("graphics/types/battle_icons2.pal", ".gbapal");

const u16 gGhostPalette[] = INCGFX_U16("graphics/pokemon/ghost/front.png", ".gbapal");
const u32 gGhostFrontPic[] = INCGFX_U32("graphics/pokemon/ghost/front.png", ".4bpp.smol");
