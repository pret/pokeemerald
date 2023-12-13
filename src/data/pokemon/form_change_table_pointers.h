const struct Fusion *const gFusionTablePointers[NUM_SPECIES] =
{
#if P_FAMILY_KYUREM
    [SPECIES_KYUREM] = sKyuremFusionTable,
#if P_FAMILY_RESHIRAM
    [SPECIES_KYUREM_WHITE] = sKyuremFusionTable,
    [SPECIES_RESHIRAM] = sKyuremFusionTable,
#endif //P_FAMILY_RESHIRAM
#if P_FAMILY_ZEKROM
    [SPECIES_KYUREM_BLACK] = sKyuremFusionTable,
    [SPECIES_ZEKROM] = sKyuremFusionTable,
#endif //P_FAMILY_ZEKROM
#endif //P_FAMILY_KYUREM
#if P_FAMILY_NECROZMA
    [SPECIES_NECROZMA] = sNecrozmaFusionTable,
#if P_FAMILY_COSMOG
    [SPECIES_NECROZMA_DAWN_WINGS] = sNecrozmaFusionTable,
    [SPECIES_SOLGALEO] = sNecrozmaFusionTable,
    [SPECIES_NECROZMA_DUSK_MANE] = sNecrozmaFusionTable,
    [SPECIES_LUNALA] = sNecrozmaFusionTable,
#endif //P_FAMILY_COSMOG
#endif //P_FAMILY_NECROZMA
#if P_FAMILY_CALYREX
    [SPECIES_CALYREX] = sCalyrexFusionTable,
#if P_FAMILY_SPECTRIER
    [SPECIES_CALYREX_SHADOW_RIDER] = sCalyrexFusionTable,
    [SPECIES_SPECTRIER] = sCalyrexFusionTable,
#endif //P_FAMILY_SPECTRIER
#if P_FAMILY_GLASTRIER
    [SPECIES_CALYREX_ICE_RIDER] = sCalyrexFusionTable,
    [SPECIES_GLASTRIER] = sCalyrexFusionTable,
#endif //P_FAMILY_GLASTRIER
#endif //P_FAMILY_CALYREX
};
