const struct Fusion *const gFusionTablePointers[NUM_SPECIES] =
{
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_KYUREM] = sKyuremFusionTable,
    [SPECIES_KYUREM_BLACK] = sKyuremFusionTable,
    [SPECIES_KYUREM_WHITE] = sKyuremFusionTable,
    [SPECIES_RESHIRAM] = sKyuremFusionTable,
    [SPECIES_ZEKROM] = sKyuremFusionTable,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_NECROZMA] = sNecrozmaFusionTable,
    [SPECIES_NECROZMA_DAWN_WINGS] = sNecrozmaFusionTable,
    [SPECIES_NECROZMA_DUSK_MANE] = sNecrozmaFusionTable,
    [SPECIES_SOLGALEO] = sNecrozmaFusionTable,
    [SPECIES_LUNALA] = sNecrozmaFusionTable,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CALYREX] = sCalyrexFusionTable,
    [SPECIES_CALYREX_ICE_RIDER] = sCalyrexFusionTable,
    [SPECIES_CALYREX_SHADOW_RIDER] = sCalyrexFusionTable,
    [SPECIES_SPECTRIER] = sCalyrexFusionTable,
    [SPECIES_GLASTRIER] = sCalyrexFusionTable,
#endif
};
