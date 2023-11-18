#define PLACEHOLDER_ANIM_SINGLE_FRAME(name)     \
static const union AnimCmd sAnim_##name##_1[] = \
{                                               \
    ANIMCMD_FRAME(0, 1),                        \
    ANIMCMD_END,                                \
}

#define PLACEHOLDER_TWO_FRAME_ANIMATION(name)   \
static const union AnimCmd sAnim_##name##_1[] = \
{                                               \
    ANIMCMD_FRAME(0, 30),                       \
    ANIMCMD_FRAME(1, 30),                       \
    ANIMCMD_FRAME(0, 1),                        \
    ANIMCMD_END,                                \
}

static const union AnimCmd sAnim_None_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bulbasaur_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ivysaur_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Venusaur_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Charmander_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Charmeleon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Charizard_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Squirtle_1[] =
{
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wartortle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blastoise_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Caterpie_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Metapod_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Butterfree_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Weedle_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kakuna_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Beedrill_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pidgey_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pidgeotto_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pidgeot_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rattata_1[] =
{
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Raticate_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spearow_1[] =
{
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Fearow_1[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ekans_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Arbok_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pikachu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pikachu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Raichu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Raichu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandshrew_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandshrew_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandslash_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandslash_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_NidoranF_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nidorina_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nidoqueen_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_NidoranM_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nidorino_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 23),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nidoking_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Clefairy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Clefable_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 48),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vulpix_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vulpix_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ninetales_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ninetales_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jigglypuff_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jigglypuff_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wigglytuff_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wigglytuff_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zubat_1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golbat_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Oddish_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gloom_1[] =
{
    ANIMCMD_FRAME(0, 21),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vileplume_1[] =
{
    ANIMCMD_FRAME(1, 38),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Paras_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Parasect_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Venonat_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 35),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Venomoth_1[] =
{
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Diglett_1[] =
{
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dugtrio_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Meowth_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Persian_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Psyduck_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Psyduck_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golduck_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golduck_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mankey_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Primeape_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Growlithe_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Arcanine_1[] =
{
    ANIMCMD_FRAME(1, 38),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Poliwag_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Poliwhirl_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Poliwrath_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Abra_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kadabra_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Alakazam_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 54),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Machop_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Machoke_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Machamp_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bellsprout_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Weepinbell_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Victreebel_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tentacool_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tentacruel_1[] =
{
    ANIMCMD_FRAME(0, 19),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 19),
    ANIMCMD_FRAME(1, 19),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Geodude_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Graveler_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golem_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 31),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ponyta_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rapidash_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slowpoke_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slowbro_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magnemite_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magneton_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Farfetchd_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Doduo_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dodrio_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seel_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dewgong_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grimer_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grimer_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Muk_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Muk_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shellder_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cloyster_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gastly_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Haunter_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gengar_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Onix_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drowzee_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hypno_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Krabby_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kingler_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Voltorb_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Electrode_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Exeggcute_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Exeggutor_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cubone_1[] =
{
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Marowak_1[] =
{
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hitmonlee_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hitmonchan_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lickitung_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Koffing_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Koffing_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Weezing_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Weezing_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rhyhorn_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rhyhorn_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rhydon_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 48),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rhydon_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chansey_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tangela_1[] =
{
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kangaskhan_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Horsea_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Horsea_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seadra_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seadra_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Goldeen_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seaking_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Staryu_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Staryu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Starmie_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Starmie_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MrMime_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scyther_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jynx_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Electabuzz_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magmar_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pinsir_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pinsir_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tauros_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magikarp_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gyarados_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lapras_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ditto_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Eevee_1[] =
{
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vaporeon_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jolteon_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Flareon_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Porygon_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Omanyte_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Omastar_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kabuto_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kabutops_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Aerodactyl_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Snorlax_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Articuno_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zapdos_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Moltres_1[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dratini_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dragonair_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dragonite_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mewtwo_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mew_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chikorita_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bayleef_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Meganium_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cyndaquil_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Quilava_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Typhlosion_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Totodile_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Croconaw_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Feraligatr_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sentret_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Furret_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hoothoot_1[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Noctowl_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ledyba_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ledian_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spinarak_1[] =
{
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ariados_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Crobat_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chinchou_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chinchou_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lanturn_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lanturn_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pichu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pichu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cleffa_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Igglybuff_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Igglybuff_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Togepi_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Togetic_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Natu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Natu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Xatu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Xatu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mareep_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Flaaffy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ampharos_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bellossom_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Marill_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Azumarill_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sudowoodo_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Politoed_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hoppip_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skiploom_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jumpluff_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Aipom_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sunkern_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sunflora_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Yanma_1[] =
{
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wooper_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Quagsire_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Espeon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Umbreon_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Murkrow_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slowking_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Misdreavus_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Unown_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wobbuffet_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wobbuffet_2[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Girafarig_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Girafarig_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pineco_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Forretress_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dunsparce_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gligar_1[] =
{
    ANIMCMD_FRAME(1, 17),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Steelix_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Snubbull_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Granbull_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Qwilfish_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scizor_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shuckle_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Heracross_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sneasel_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Teddiursa_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ursaring_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slugma_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slugma_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magcargo_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magcargo_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swinub_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Piloswine_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Corsola_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Corsola_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Remoraid_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Octillery_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Delibird_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mantine_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skarmory_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Houndour_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Houndoom_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kingdra_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kingdra_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Phanpy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Phanpy_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Donphan_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Porygon2_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stantler_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Smeargle_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tyrogue_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hitmontop_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Smoochum_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Elekid_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magby_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Miltank_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blissey_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Raikou_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Entei_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Suicune_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Larvitar_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pupitar_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tyranitar_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lugia_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HoOh_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Celebi_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_OldUnownB_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Treecko_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grovyle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sceptile_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 26),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Torchic_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Combusken_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blaziken_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blaziken_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blaziken_3[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(2, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blaziken_4[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mudkip_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 13),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Marshtomp_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swampert_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Poochyena_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mightyena_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zigzagoon_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Linoone_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wurmple_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Silcoon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Silcoon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Beautifly_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Beautifly_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cascoon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cascoon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dustox_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dustox_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lotad_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 55),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lombre_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ludicolo_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seedot_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nuzleaf_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shiftry_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nincada_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ninjask_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shedinja_1[] =
{
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Taillow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swellow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shroomish_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Breloom_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spinda_1[] =
{
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 23),
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 23),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wingull_1[] =
{
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 23),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pelipper_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Surskit_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Surskit_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Masquerain_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Masquerain_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wailmer_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wailord_1[] =
{
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 48),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skitty_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Delcatty_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kecleon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Baltoy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Claydol_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nosepass_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Torkoal_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sableye_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Barboach_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Whiscash_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Luvdisc_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Corphish_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Crawdaunt_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Feebas_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Milotic_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Carvanha_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sharpedo_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Trapinch_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vibrava_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Flygon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Makuhita_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hariyama_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Electrike_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Manectric_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Numel_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Camerupt_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spheal_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 43),
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sealeo_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Walrein_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cacnea_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cacturne_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Snorunt_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Glalie_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lunatone_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lunatone_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Solrock_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Solrock_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Azurill_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spoink_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grumpig_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Plusle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Minun_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mawile_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Meditite_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Medicham_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swablu_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swablu_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Altaria_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Altaria_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wynaut_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Duskull_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dusclops_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Roselia_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slakoth_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vigoroth_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slaking_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gulpin_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swalot_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tropius_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Whismur_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Loudred_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Exploud_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Clamperl_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Huntail_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gorebyss_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Absol_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shuppet_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Banette_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seviper_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zangoose_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Relicanth_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Aron_1[] =
{
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lairon_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 29),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 29),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Aggron_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CastformNormal_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 24),
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 24),
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CastformSunny_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CastformRainy_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CastformSnowy_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 29),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Volbeat_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Illumise_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lileep_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cradily_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Anorith_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Armaldo_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ralts_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kirlia_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 39),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gardevoir_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bagon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shelgon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Salamence_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Beldum_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Metang_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Metagross_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Regirock_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Regirock_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Regice_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Registeel_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Registeel_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kyogre_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kyogre_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Groudon_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Groudon_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rayquaza_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rayquaza_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Latias_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Latias_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Latios_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Latios_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jirachi_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jirachi_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DeoxysNormal_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chimecho_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Egg_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownB_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownC_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownD_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownE_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownF_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownG_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownH_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownI_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownJ_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownK_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownL_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownM_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownN_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownO_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownP_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownQ_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownR_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownS_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownT_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownU_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownV_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownW_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownX_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownY_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownZ_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownEMark_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UnownQMark_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

#if P_GEN_4_POKEMON == TRUE
static const union AnimCmd sAnim_Turtwig_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grotle_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Torterra_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chimchar_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Monferno_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Infernape_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Piplup_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Prinplup_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Empoleon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Starly_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Staravia_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Staraptor_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bidoof_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bibarel_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bibarel_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kricketot_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kricketune_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shinx_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Luxio_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Luxray_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Luxray_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Budew_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Roserade_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cranidos_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rampardos_1[] =
{
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shieldon_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bastiodon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Burmy_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wormadam_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mothim_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Combee_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vespiquen_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pachirisu_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Buizel_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Floatzel_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cherubi_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CherrimOvercast_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CherrimOvercast_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CherrimSunshine_1[] =
{
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shellos_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gastrodon_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ambipom_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drifloon_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drifblim_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Buneary_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lopunny_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mismagius_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Honchkrow_1[] =
{
    ANIMCMD_FRAME(0, 21),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Glameow_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Purugly_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chingling_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stunky_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skuntank_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bronzor_1[] =
{
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bronzong_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bronzong_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bonsly_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MimeJr_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Happiny_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chatot_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Spiritomb_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gible_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gabite_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Garchomp_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Munchlax_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Riolu_1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lucario_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hippopotas_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hippowdon_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skorupi_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drapion_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Croagunk_1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Toxicroak_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Carnivine_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Finneon_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lumineon_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mantyke_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Snover_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Abomasnow_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Weavile_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magnezone_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lickilicky_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rhyperior_1[] =
{
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tangrowth_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Electivire_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magmortar_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Togekiss_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Yanmega_1[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Leafeon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Glaceon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gliscor_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mamoswine_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PORYGON_Z_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gallade_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Probopass_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Probopass_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dusknoir_1[] =
{
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Froslass_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rotom_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rotom_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RotomHeat_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RotomWash_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RotomFrost_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RotomFan_1[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RotomMow_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Uxie_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mesprit_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Azelf_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dialga_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Palkia_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Heatran_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Regigigas_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GiratinaAltered_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cresselia_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Phione_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Manaphy_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Darkrai_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ShayminLand_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Arceus_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};
#endif
#if P_GEN_5_POKEMON == TRUE
static const union AnimCmd sAnim_Victini_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Snivy_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Servine_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Serperior_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Serperior_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tepig_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pignite_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Emboar_1[] =
{
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Oshawott_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dewott_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Samurott_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Patrat_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Watchog_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0 , 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lillipup_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Herdier_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stoutland_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Purrloin_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 54),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Liepard_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pansage_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 13),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Simisage_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pansear_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Simisear_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Simisear_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Panpour_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Simipour_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Munna_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Musharna_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Musharna_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pidove_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tranquill_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Unfezant_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blitzle_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zebstrika_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Roggenrola_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Boldore_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gigalith_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Woobat_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swoobat_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drilbur_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drilbur_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Excadrill_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Audino_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Timburr_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gurdurr_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Conkeldurr_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tympole_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Palpitoad_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 13),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Seismitoad_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Throh_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sawk_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sewaddle_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sewaddle_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swadloon_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Leavanny_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Venipede_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Whirlipede_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scolipede_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cottonee_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Whimsicott_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Petilil_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lilligant_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Basculin_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandile_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Krokorok_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Krookodile_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Krookodile_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Darumaka_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DarmanitanStandardMode_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Maractus_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dwebble_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Crustle_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scraggy_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scrafty_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sigilyph_1[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Yamask_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cofagrigus_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tirtouga_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Carracosta_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Archen_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Archeops_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Trubbish_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Garbodor_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zorua_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zoroark_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Minccino_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cinccino_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gothita_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gothorita_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gothorita_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gothitelle_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Solosis_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Duosion_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Reuniclus_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ducklett_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swanna_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vanillite_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vanillish_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vanilluxe_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Deerling_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sawsbuck_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Emolga_1[] =
{
    ANIMCMD_FRAME(0, 21),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Karrablast_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Escavalier_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Foongus_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Foongus_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Amoonguss_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Frillish_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Jellicent_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Alomomola_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Joltik_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Galvantula_1[] =
{
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ferroseed_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ferrothorn_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ferrothorn_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Klink_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Klang_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Klinklang_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tynamo_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Eelektrik_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Eelektross_1[] =
{
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 24),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Elgyem_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Beheeyem_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Litwick_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lampent_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chandelure_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Axew_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Fraxure_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Haxorus_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cubchoo_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Beartic_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cryogonal_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 48),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cryogonal_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shelmet_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Accelgor_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stunfisk_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mienfoo_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mienshao_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Druddigon_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golett_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golurk_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pawniard_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bisharp_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bouffalant_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rufflet_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Braviary_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vullaby_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mandibuzz_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Heatmor_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Durant_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Deino_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zweilous_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hydreigon_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Larvesta_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Volcarona_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cobalion_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Terrakion_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Terrakion_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Virizion_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TornadusIncarnate_1[] =
{
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ThundurusIncarnate_1[] =
{
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Reshiram_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zekrom_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LandorusIncarnate_1[] =
{
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kyurem_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KeldeoOrdinary_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MeloettaAria_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MeloettaAria_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Genesect_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};
#endif
#if P_GEN_6_POKEMON == TRUE
static const union AnimCmd sAnim_Chespin_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 24),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 24),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Quilladin_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Quilladin_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chesnaught_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Fennekin_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Braixen_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Delphox_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Froakie_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Frogadier_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Greninja_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GreninjaAsh_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bunnelby_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Diggersby_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Fletchling_1[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Fletchinder_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Talonflame_1[] =
{
    ANIMCMD_FRAME(1, 55),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Talonflame_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scatterbug_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spewpa_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vivillon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Litleo_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pyroar_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Flabebe_1[] =
{
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 23),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Flabebe_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Floette_1[] =
{
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Florges_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Florges_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skiddo_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gogoat_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pancham_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pangoro_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Furfrou_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Espurr_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Meowstic_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Honedge_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Doublade_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Doublade_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AegislashShield_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spritzee_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Aromatisse_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Swirlix_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Slurpuff_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Inkay_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Malamar_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Binacle_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Barbaracle_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skrelp_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dragalge_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Clauncher_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Clawitzer_1[] =
{
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Helioptile_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Heliolisk_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tyrunt_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tyrantrum_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Amaura_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Aurorus_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sylveon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hawlucha_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dedenne_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Carbink_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Goomy_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sliggoo_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Goodra_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Klefki_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Phantump_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Trevenant_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pumpkaboo_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gourgeist_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bergmite_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bergmite_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Avalugg_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Noibat_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Noivern_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Xerneas_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Yveltal_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zygarde50_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Diancie_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hoopa_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Volcanion_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};
#endif
#if P_GEN_7_POKEMON == TRUE
static const union AnimCmd sAnim_Rowlet_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dartrix_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Decidueye_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Litten_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Torracat_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Incineroar_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Popplio_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Brionne_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Primarina_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pikipek_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Trumbeak_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Toucannon_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Yungoos_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gumshoos_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grubbin_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Charjabug_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Vikavolt_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Crabrawler_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Crabominable_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Oricorio_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cutiefly_1[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 35),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ribombee_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rockruff_1[] =
{
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LycanrocMidday_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WishiwashiSolo_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mareanie_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Toxapex_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mudbray_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Mudsdale_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dewpider_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Araquanid_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Fomantis_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lurantis_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Morelull_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Shiinotic_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Salandit_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Salazzle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stufful_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bewear_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bounsweet_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Steenee_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tsareena_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Comfey_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Oranguru_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Passimian_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wimpod_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Golisopod_1[] =
{
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandygast_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Palossand_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pyukumuku_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TypeNull_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Silvally_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MiniorMeteor_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Komala_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Turtonator_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Togedemaru_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MimikyuDisguised_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Bruxish_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drampa_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dhelmise_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_JANGMO_O_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HAKAMO_O_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KOMMO_O_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TapuKoko_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TapuLele_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TapuBulu_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TapuFini_1[] =
{
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cosmog_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cosmoem_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Solgaleo_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Lunala_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nihilego_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Buzzwole_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Pheromosa_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Xurkitree_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Celesteela_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kartana_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Guzzlord_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Necrozma_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Magearna_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Marshadow_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 54),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Poipole_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Naganadel_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stakataka_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blacephalon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zeraora_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Meltan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Melmetal_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_8_POKEMON == TRUE
static const union AnimCmd sAnim_Grookey_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Thwackey_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rillaboom_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Scorbunny_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Raboot_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cinderace_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sobble_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drizzile_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Inteleon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Skwovet_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Greedent_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rookidee_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Corvisquire_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Corviknight_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Blipbug_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dottler_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Orbeetle_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Nickit_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Thievul_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Gossifleur_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Eldegoss_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wooloo_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dubwool_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Chewtle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drednaw_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Yamper_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Boltund_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

PLACEHOLDER_TWO_FRAME_ANIMATION(Rolycoly);
PLACEHOLDER_TWO_FRAME_ANIMATION(Carkol);
PLACEHOLDER_TWO_FRAME_ANIMATION(Coalossal);
PLACEHOLDER_TWO_FRAME_ANIMATION(Applin);
PLACEHOLDER_TWO_FRAME_ANIMATION(Flapple);
PLACEHOLDER_TWO_FRAME_ANIMATION(Appletun);

static const union AnimCmd sAnim_Silicobra_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sandaconda_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cramorant_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Arrokuda_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Barraskewda_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Toxel_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Toxtricity_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sizzlipede_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Centiskorch_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Clobbopus_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grapploct_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sinistea_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Polteageist_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hatenna_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hattrem_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Hatterene_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Impidimp_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Morgrem_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Grimmsnarl_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Obstagoon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Perrserker_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cursola_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sirfetchd_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MrRime_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Runerigus_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Milcery_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Alcremie_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Falinks_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

PLACEHOLDER_TWO_FRAME_ANIMATION(Pincurchin);

static const union AnimCmd sAnim_Snom_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Frosmoth_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Stonjourner_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Eiscue_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Indeedee_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Morpeko_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cufant_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Copperajah_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dracozolt_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Arctozolt_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dracovish_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Arctovish_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Duraludon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dreepy_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Drakloak_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dragapult_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zacian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zamazenta_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Eternatus_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kubfu_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Urshifu_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zarude_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Regieleki_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Regidrago_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Glastrier_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Spectrier_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Calyrex_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Wyrdeer_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Kleavor_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ursaluna_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Basculegion_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Sneasler_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Overqwil_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_EnamorusIncarnate_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif

static const union AnimCmd sAnim_VenusaurMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CHARIZARD_MEGA_X_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CHARIZARD_MEGA_Y_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BlastoiseMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BeedrillMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PidgeotMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AlakazamMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SlowbroMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GengarMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KangaskhanMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PinsirMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GyaradosMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AerodactylMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MEWTWO_MEGA_X_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MEWTWO_MEGA_Y_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AmpharosMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SteelixMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ScizorMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HeracrossMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HoundoomMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TyranitarMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SceptileMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BlazikenMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SwampertMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GardevoirMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SableyeMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MawileMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AggronMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MedichamMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ManectricMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SharpedoMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CameruptMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AltariaMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BanetteMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AbsolMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GlalieMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SalamenceMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MetagrossMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LatiasMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LatiosMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KyogrePrimal_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GroudonPrimal_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RayquazaMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

#if P_GEN_4_POKEMON == TRUE
static const union AnimCmd sAnim_LopunnyMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GarchompMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LucarioMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AbomasnowMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GalladeMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_5_POKEMON == TRUE
static const union AnimCmd sAnim_AudinoMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_6_POKEMON == TRUE
static const union AnimCmd sAnim_DiancieMega_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif

static const union AnimCmd sAnim_RattataAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RaticateAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RaichuAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SandshrewAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SandslashAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VulpixAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_NinetalesAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DiglettAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DugtrioAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MeowthAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PersianAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GeodudeAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GravelerAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GolemAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GrimerAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MukAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

PLACEHOLDER_TWO_FRAME_ANIMATION(ExeggutorAlolan);

static const union AnimCmd sAnim_MarowakAlolan_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MeowthGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PonytaGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RapidashGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SlowpokeGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SlowbroGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FarfetchdGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WeezingGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MrMimeGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ArticunoGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ZapdosGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MoltresGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SlowkingGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CorsolaGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ZigzagoonGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LinooneGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

#if P_GEN_5_POKEMON == TRUE
static const union AnimCmd sAnim_DarumakaGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DarmanitanGalarianStandardMode_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_YamaskGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StunfiskGalarian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif

static const union AnimCmd sAnim_GrowlitheHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ArcanineHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VoltorbHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ElectrodeHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TyphlosionHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_QwilfishHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SneaselHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

#if P_GEN_5_POKEMON == TRUE
static const union AnimCmd sAnim_SamurottHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LilligantHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ZoruaHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ZoroarkHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BraviaryHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_6_POKEMON == TRUE
static const union AnimCmd sAnim_SliggooHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GoodraHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AvaluggHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_7_POKEMON == TRUE
static const union AnimCmd sAnim_DecidueyeHisuian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
PLACEHOLDER_ANIM_SINGLE_FRAME(WooperPaldean);
PLACEHOLDER_ANIM_SINGLE_FRAME(TaurosPaldean);

static const union AnimCmd sAnim_VenusaurGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CharizardGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BlastoiseGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ButterfreeGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MeowthGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MachampGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GengarGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KinglerGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LaprasGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_EeveeGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SnorlaxGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

#if P_GEN_5_POKEMON == TRUE
static const union AnimCmd sAnim_GarbodorGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_7_POKEMON == TRUE
static const union AnimCmd sAnim_MelmetalGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif
#if P_GEN_8_POKEMON == TRUE
static const union AnimCmd sAnim_RillaboomGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CinderaceGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_InteleonGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CorviknightGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_OrbeetleGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DrednawGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CoalossalGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FlappleGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AppletunGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SandacondaGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ToxtricityGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CentiskorchGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HattereneGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GrimmsnarlGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AlcremieGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CopperajahGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DuraludonGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UrshifuSingleStrikeStyleGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_UrshifuRapidStrikeStyleGigantamax_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
#endif

static const union AnimCmd sAnim_PikachuCosplay_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuRockStar_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuBelle_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuPopStar_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PIKACHU_PH_D_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuLibre_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuOriginalCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuHoennCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuSinnohCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuUnovaCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuKalosCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuAlolaCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuPartnerCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PikachuWorldCap_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PichuSpikyEared_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_DeoxysAttack_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DeoxysAttack_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DeoxysDefense_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DeoxysDefense_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DeoxysSpeed_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DeoxysSpeed_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};

#if P_GEN_4_POKEMON == TRUE
static const union AnimCmd sAnim_ShayminSky_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DialgaOrigin_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PalkiaOrigin_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GiratinaOrigin_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GiratinaOrigin_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END,
};
#endif
#if P_GEN_5_POKEMON == TRUE
static const union AnimCmd sAnim_DarmanitanZenMode_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_DarmanitanGalarianZenMode_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TornadusTherian_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ThundurusTherian_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LandorusTherian_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KyuremBlack_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KyuremWhite_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KeldeoResolute_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MeloettaPirouette_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};
#endif
#if P_GEN_6_POKEMON == TRUE
static const union AnimCmd sAnim_AegislashBlade_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Zygarde10_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ZygardeComplete_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HoopaUnbound_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};
#endif
#if P_GEN_7_POKEMON == TRUE
static const union AnimCmd sAnim_MiniorCore_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WishiwashiSchool_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MimikyuBusted_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LycanrocMidnight_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LycanrocDusk_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};
#endif

#if P_GEN_8_POKEMON == TRUE
static const union AnimCmd sAnim_EnamorusTherian_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

PLACEHOLDER_ANIM_SINGLE_FRAME(UrsalunaBloodmoon);
#endif
#if P_GEN_9_POKEMON == TRUE
PLACEHOLDER_ANIM_SINGLE_FRAME(Sprigatito);
PLACEHOLDER_ANIM_SINGLE_FRAME(Floragato);
PLACEHOLDER_ANIM_SINGLE_FRAME(Meowscarada);
PLACEHOLDER_ANIM_SINGLE_FRAME(Fuecoco);
PLACEHOLDER_ANIM_SINGLE_FRAME(Crocalor);
PLACEHOLDER_ANIM_SINGLE_FRAME(Skeledirge);
PLACEHOLDER_ANIM_SINGLE_FRAME(Quaxly);
PLACEHOLDER_ANIM_SINGLE_FRAME(Quaxwell);
PLACEHOLDER_ANIM_SINGLE_FRAME(Quaquaval);
PLACEHOLDER_ANIM_SINGLE_FRAME(Lechonk);
PLACEHOLDER_ANIM_SINGLE_FRAME(Oinkologne);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tarountula);
PLACEHOLDER_ANIM_SINGLE_FRAME(Spidops);
PLACEHOLDER_ANIM_SINGLE_FRAME(Nymble);
PLACEHOLDER_ANIM_SINGLE_FRAME(Lokix);
PLACEHOLDER_ANIM_SINGLE_FRAME(Pawmi);
PLACEHOLDER_ANIM_SINGLE_FRAME(Pawmo);
PLACEHOLDER_ANIM_SINGLE_FRAME(Pawmot);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tandemaus);
PLACEHOLDER_ANIM_SINGLE_FRAME(Maushold);
PLACEHOLDER_ANIM_SINGLE_FRAME(Fidough);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dachsbun);
PLACEHOLDER_ANIM_SINGLE_FRAME(Smoliv);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dolliv);
PLACEHOLDER_ANIM_SINGLE_FRAME(Arboliva);
PLACEHOLDER_ANIM_SINGLE_FRAME(Squawkabilly);
PLACEHOLDER_ANIM_SINGLE_FRAME(Nacli);
PLACEHOLDER_ANIM_SINGLE_FRAME(Naclstack);
PLACEHOLDER_ANIM_SINGLE_FRAME(Garganacl);
PLACEHOLDER_ANIM_SINGLE_FRAME(Charcadet);
PLACEHOLDER_ANIM_SINGLE_FRAME(Armarouge);
PLACEHOLDER_ANIM_SINGLE_FRAME(Ceruledge);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tadbulb);
PLACEHOLDER_ANIM_SINGLE_FRAME(Bellibolt);
PLACEHOLDER_ANIM_SINGLE_FRAME(Wattrel);
PLACEHOLDER_ANIM_SINGLE_FRAME(Kilowattrel);
PLACEHOLDER_ANIM_SINGLE_FRAME(Maschiff);
PLACEHOLDER_ANIM_SINGLE_FRAME(Mabosstiff);
PLACEHOLDER_ANIM_SINGLE_FRAME(Shroodle);
PLACEHOLDER_ANIM_SINGLE_FRAME(Grafaiai);
PLACEHOLDER_ANIM_SINGLE_FRAME(Bramblin);
PLACEHOLDER_ANIM_SINGLE_FRAME(Brambleghast);
PLACEHOLDER_ANIM_SINGLE_FRAME(Toedscool);
PLACEHOLDER_ANIM_SINGLE_FRAME(Toedscruel);
PLACEHOLDER_ANIM_SINGLE_FRAME(Klawf);
PLACEHOLDER_ANIM_SINGLE_FRAME(Capsakid);
PLACEHOLDER_ANIM_SINGLE_FRAME(Scovillain);
PLACEHOLDER_ANIM_SINGLE_FRAME(Rellor);
PLACEHOLDER_ANIM_SINGLE_FRAME(Rabsca);
PLACEHOLDER_ANIM_SINGLE_FRAME(Flittle);
PLACEHOLDER_ANIM_SINGLE_FRAME(Espathra);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tinkatink);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tinkatuff);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tinkaton);
PLACEHOLDER_ANIM_SINGLE_FRAME(Wiglett);
PLACEHOLDER_ANIM_SINGLE_FRAME(Wugtrio);
PLACEHOLDER_ANIM_SINGLE_FRAME(Bombirdier);
PLACEHOLDER_ANIM_SINGLE_FRAME(Finizen);
PLACEHOLDER_ANIM_SINGLE_FRAME(Palafin);
PLACEHOLDER_ANIM_SINGLE_FRAME(Varoom);
PLACEHOLDER_ANIM_SINGLE_FRAME(Revavroom);
PLACEHOLDER_ANIM_SINGLE_FRAME(Cyclizar);
PLACEHOLDER_ANIM_SINGLE_FRAME(Orthworm);
PLACEHOLDER_ANIM_SINGLE_FRAME(Glimmet);
PLACEHOLDER_ANIM_SINGLE_FRAME(Glimmora);
PLACEHOLDER_ANIM_SINGLE_FRAME(Greavard);
PLACEHOLDER_ANIM_SINGLE_FRAME(Houndstone);
PLACEHOLDER_ANIM_SINGLE_FRAME(Flamigo);
PLACEHOLDER_ANIM_SINGLE_FRAME(Cetoddle);
PLACEHOLDER_ANIM_SINGLE_FRAME(Cetitan);
PLACEHOLDER_ANIM_SINGLE_FRAME(Veluza);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dondozo);
PLACEHOLDER_ANIM_SINGLE_FRAME(Tatsugiri);
PLACEHOLDER_ANIM_SINGLE_FRAME(Annihilape);
PLACEHOLDER_ANIM_SINGLE_FRAME(Clodsire);
PLACEHOLDER_ANIM_SINGLE_FRAME(Farigiraf);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dudunsparce);
PLACEHOLDER_ANIM_SINGLE_FRAME(Kingambit);
PLACEHOLDER_TWO_FRAME_ANIMATION(GreatTusk);
PLACEHOLDER_ANIM_SINGLE_FRAME(ScreamTail);
PLACEHOLDER_ANIM_SINGLE_FRAME(BruteBonnet);
PLACEHOLDER_ANIM_SINGLE_FRAME(FlutterMane);
PLACEHOLDER_ANIM_SINGLE_FRAME(SlitherWing);
PLACEHOLDER_ANIM_SINGLE_FRAME(SandyShocks);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronTreads);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronBundle);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronHands);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronJugulis);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronMoth);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronThorns);
PLACEHOLDER_TWO_FRAME_ANIMATION(Frigibax);
PLACEHOLDER_ANIM_SINGLE_FRAME(Arctibax);
PLACEHOLDER_ANIM_SINGLE_FRAME(Baxcalibur);
PLACEHOLDER_ANIM_SINGLE_FRAME(Gimmighoul);
PLACEHOLDER_ANIM_SINGLE_FRAME(Gholdengo);
PLACEHOLDER_ANIM_SINGLE_FRAME(WoChien);
PLACEHOLDER_ANIM_SINGLE_FRAME(ChienPao);
PLACEHOLDER_ANIM_SINGLE_FRAME(TingLu);
PLACEHOLDER_ANIM_SINGLE_FRAME(ChiYu);
PLACEHOLDER_ANIM_SINGLE_FRAME(RoaringMoon);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronValiant);
PLACEHOLDER_ANIM_SINGLE_FRAME(Koraidon);
PLACEHOLDER_ANIM_SINGLE_FRAME(Miraidon);
PLACEHOLDER_ANIM_SINGLE_FRAME(WalkingWake);
PLACEHOLDER_ANIM_SINGLE_FRAME(IronLeaves);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dipplin);
PLACEHOLDER_ANIM_SINGLE_FRAME(Sinistcha);
PLACEHOLDER_ANIM_SINGLE_FRAME(Poltchageist);
PLACEHOLDER_ANIM_SINGLE_FRAME(Okidogi);
PLACEHOLDER_ANIM_SINGLE_FRAME(Munkidori);
PLACEHOLDER_ANIM_SINGLE_FRAME(Fezandipiti);
PLACEHOLDER_ANIM_SINGLE_FRAME(Ogerpon);
#endif

#define SINGLE_ANIMATION(name)                      \
static const union AnimCmd *const sAnims_##name[] = \
{                                                   \
    sAnim_GeneralFrame0,                            \
    sAnim_##name##_1,                               \
}

#define DOUBLE_ANIMATION(name)                      \
static const union AnimCmd *const sAnims_##name[] = \
{                                                   \
    sAnim_GeneralFrame0,                            \
    sAnim_##name##_1,                               \
    sAnim_##name##_2,                               \
}

SINGLE_ANIMATION(None);
SINGLE_ANIMATION(Bulbasaur);
SINGLE_ANIMATION(Ivysaur);
SINGLE_ANIMATION(Venusaur);
SINGLE_ANIMATION(Charmander);
SINGLE_ANIMATION(Charmeleon);
SINGLE_ANIMATION(Charizard);
SINGLE_ANIMATION(Squirtle);
SINGLE_ANIMATION(Wartortle);
SINGLE_ANIMATION(Blastoise);
SINGLE_ANIMATION(Caterpie);
SINGLE_ANIMATION(Metapod);
SINGLE_ANIMATION(Butterfree);
SINGLE_ANIMATION(Weedle);
SINGLE_ANIMATION(Kakuna);
SINGLE_ANIMATION(Beedrill);
SINGLE_ANIMATION(Pidgey);
SINGLE_ANIMATION(Pidgeotto);
SINGLE_ANIMATION(Pidgeot);
SINGLE_ANIMATION(Rattata);
SINGLE_ANIMATION(Raticate);
SINGLE_ANIMATION(Spearow);
SINGLE_ANIMATION(Fearow);
SINGLE_ANIMATION(Ekans);
SINGLE_ANIMATION(Arbok);
DOUBLE_ANIMATION(Pikachu);
DOUBLE_ANIMATION(Raichu);
DOUBLE_ANIMATION(Sandshrew);
DOUBLE_ANIMATION(Sandslash);
SINGLE_ANIMATION(NidoranF);
SINGLE_ANIMATION(Nidorina);
SINGLE_ANIMATION(Nidoqueen);
SINGLE_ANIMATION(NidoranM);
SINGLE_ANIMATION(Nidorino);
SINGLE_ANIMATION(Nidoking);
SINGLE_ANIMATION(Clefairy);
SINGLE_ANIMATION(Clefable);
DOUBLE_ANIMATION(Vulpix);
DOUBLE_ANIMATION(Ninetales);
DOUBLE_ANIMATION(Jigglypuff);
DOUBLE_ANIMATION(Wigglytuff);
SINGLE_ANIMATION(Zubat);
SINGLE_ANIMATION(Golbat);
SINGLE_ANIMATION(Oddish);
SINGLE_ANIMATION(Gloom);
SINGLE_ANIMATION(Vileplume);
SINGLE_ANIMATION(Paras);
SINGLE_ANIMATION(Parasect);
SINGLE_ANIMATION(Venonat);
SINGLE_ANIMATION(Venomoth);
SINGLE_ANIMATION(Diglett);
SINGLE_ANIMATION(Dugtrio);
SINGLE_ANIMATION(Meowth);
SINGLE_ANIMATION(Persian);
DOUBLE_ANIMATION(Psyduck);
DOUBLE_ANIMATION(Golduck);
SINGLE_ANIMATION(Mankey);
SINGLE_ANIMATION(Primeape);
SINGLE_ANIMATION(Growlithe);
SINGLE_ANIMATION(Arcanine);
SINGLE_ANIMATION(Poliwag);
SINGLE_ANIMATION(Poliwhirl);
SINGLE_ANIMATION(Poliwrath);
SINGLE_ANIMATION(Abra);
SINGLE_ANIMATION(Kadabra);
SINGLE_ANIMATION(Alakazam);
SINGLE_ANIMATION(Machop);
SINGLE_ANIMATION(Machoke);
SINGLE_ANIMATION(Machamp);
SINGLE_ANIMATION(Bellsprout);
SINGLE_ANIMATION(Weepinbell);
SINGLE_ANIMATION(Victreebel);
SINGLE_ANIMATION(Tentacool);
SINGLE_ANIMATION(Tentacruel);
SINGLE_ANIMATION(Geodude);
SINGLE_ANIMATION(Graveler);
SINGLE_ANIMATION(Golem);
SINGLE_ANIMATION(Ponyta);
SINGLE_ANIMATION(Rapidash);
SINGLE_ANIMATION(Slowpoke);
SINGLE_ANIMATION(Slowbro);
SINGLE_ANIMATION(Magnemite);
SINGLE_ANIMATION(Magneton);
SINGLE_ANIMATION(Farfetchd);
SINGLE_ANIMATION(Doduo);
SINGLE_ANIMATION(Dodrio);
SINGLE_ANIMATION(Seel);
SINGLE_ANIMATION(Dewgong);
DOUBLE_ANIMATION(Grimer);
DOUBLE_ANIMATION(Muk);
SINGLE_ANIMATION(Shellder);
SINGLE_ANIMATION(Cloyster);
SINGLE_ANIMATION(Gastly);
SINGLE_ANIMATION(Haunter);
SINGLE_ANIMATION(Gengar);
SINGLE_ANIMATION(Onix);
SINGLE_ANIMATION(Drowzee);
SINGLE_ANIMATION(Hypno);
SINGLE_ANIMATION(Krabby);
SINGLE_ANIMATION(Kingler);
SINGLE_ANIMATION(Voltorb);
SINGLE_ANIMATION(Electrode);
SINGLE_ANIMATION(Exeggcute);
SINGLE_ANIMATION(Exeggutor);
SINGLE_ANIMATION(Cubone);
SINGLE_ANIMATION(Marowak);
SINGLE_ANIMATION(Hitmonlee);
SINGLE_ANIMATION(Hitmonchan);
SINGLE_ANIMATION(Lickitung);
DOUBLE_ANIMATION(Koffing);
DOUBLE_ANIMATION(Weezing);
DOUBLE_ANIMATION(Rhyhorn);
DOUBLE_ANIMATION(Rhydon);
SINGLE_ANIMATION(Chansey);
SINGLE_ANIMATION(Tangela);
SINGLE_ANIMATION(Kangaskhan);
DOUBLE_ANIMATION(Horsea);
DOUBLE_ANIMATION(Seadra);
SINGLE_ANIMATION(Goldeen);
SINGLE_ANIMATION(Seaking);
DOUBLE_ANIMATION(Staryu);
DOUBLE_ANIMATION(Starmie);
SINGLE_ANIMATION(MrMime);
SINGLE_ANIMATION(Scyther);
SINGLE_ANIMATION(Jynx);
SINGLE_ANIMATION(Electabuzz);
SINGLE_ANIMATION(Magmar);
DOUBLE_ANIMATION(Pinsir);
SINGLE_ANIMATION(Tauros);
SINGLE_ANIMATION(Magikarp);
SINGLE_ANIMATION(Gyarados);
SINGLE_ANIMATION(Lapras);
SINGLE_ANIMATION(Ditto);
SINGLE_ANIMATION(Eevee);
SINGLE_ANIMATION(Vaporeon);
SINGLE_ANIMATION(Jolteon);
SINGLE_ANIMATION(Flareon);
SINGLE_ANIMATION(Porygon);
SINGLE_ANIMATION(Omanyte);
SINGLE_ANIMATION(Omastar);
SINGLE_ANIMATION(Kabuto);
SINGLE_ANIMATION(Kabutops);
SINGLE_ANIMATION(Aerodactyl);
SINGLE_ANIMATION(Snorlax);
SINGLE_ANIMATION(Articuno);
SINGLE_ANIMATION(Zapdos);
SINGLE_ANIMATION(Moltres);
SINGLE_ANIMATION(Dratini);
SINGLE_ANIMATION(Dragonair);
SINGLE_ANIMATION(Dragonite);
SINGLE_ANIMATION(Mewtwo);
SINGLE_ANIMATION(Mew);
SINGLE_ANIMATION(Chikorita);
SINGLE_ANIMATION(Bayleef);
SINGLE_ANIMATION(Meganium);
SINGLE_ANIMATION(Cyndaquil);
SINGLE_ANIMATION(Quilava);
SINGLE_ANIMATION(Typhlosion);
SINGLE_ANIMATION(Totodile);
SINGLE_ANIMATION(Croconaw);
SINGLE_ANIMATION(Feraligatr);
SINGLE_ANIMATION(Sentret);
SINGLE_ANIMATION(Furret);
SINGLE_ANIMATION(Hoothoot);
SINGLE_ANIMATION(Noctowl);
SINGLE_ANIMATION(Ledyba);
SINGLE_ANIMATION(Ledian);
SINGLE_ANIMATION(Spinarak);
SINGLE_ANIMATION(Ariados);
SINGLE_ANIMATION(Crobat);
DOUBLE_ANIMATION(Chinchou);
DOUBLE_ANIMATION(Lanturn);
DOUBLE_ANIMATION(Pichu);
SINGLE_ANIMATION(Cleffa);
DOUBLE_ANIMATION(Igglybuff);
SINGLE_ANIMATION(Togepi);
SINGLE_ANIMATION(Togetic);
DOUBLE_ANIMATION(Natu);
DOUBLE_ANIMATION(Xatu);
SINGLE_ANIMATION(Mareep);
SINGLE_ANIMATION(Flaaffy);
SINGLE_ANIMATION(Ampharos);
SINGLE_ANIMATION(Bellossom);
SINGLE_ANIMATION(Marill);
SINGLE_ANIMATION(Azumarill);
SINGLE_ANIMATION(Sudowoodo);
SINGLE_ANIMATION(Politoed);
SINGLE_ANIMATION(Hoppip);
SINGLE_ANIMATION(Skiploom);
SINGLE_ANIMATION(Jumpluff);
SINGLE_ANIMATION(Aipom);
SINGLE_ANIMATION(Sunkern);
SINGLE_ANIMATION(Sunflora);
SINGLE_ANIMATION(Yanma);
SINGLE_ANIMATION(Wooper);
SINGLE_ANIMATION(Quagsire);
SINGLE_ANIMATION(Espeon);
SINGLE_ANIMATION(Umbreon);
SINGLE_ANIMATION(Murkrow);
SINGLE_ANIMATION(Slowking);
SINGLE_ANIMATION(Misdreavus);
SINGLE_ANIMATION(Unown);
DOUBLE_ANIMATION(Wobbuffet);
DOUBLE_ANIMATION(Girafarig);
SINGLE_ANIMATION(Pineco);
SINGLE_ANIMATION(Forretress);
SINGLE_ANIMATION(Dunsparce);
SINGLE_ANIMATION(Gligar);
SINGLE_ANIMATION(Steelix);
SINGLE_ANIMATION(Snubbull);
SINGLE_ANIMATION(Granbull);
SINGLE_ANIMATION(Qwilfish);
SINGLE_ANIMATION(Scizor);
SINGLE_ANIMATION(Shuckle);
SINGLE_ANIMATION(Heracross);
SINGLE_ANIMATION(Sneasel);
SINGLE_ANIMATION(Teddiursa);
SINGLE_ANIMATION(Ursaring);
DOUBLE_ANIMATION(Slugma);
DOUBLE_ANIMATION(Magcargo);
SINGLE_ANIMATION(Swinub);
SINGLE_ANIMATION(Piloswine);
DOUBLE_ANIMATION(Corsola);
SINGLE_ANIMATION(Remoraid);
SINGLE_ANIMATION(Octillery);
SINGLE_ANIMATION(Delibird);
SINGLE_ANIMATION(Mantine);
SINGLE_ANIMATION(Skarmory);
SINGLE_ANIMATION(Houndour);
SINGLE_ANIMATION(Houndoom);
DOUBLE_ANIMATION(Kingdra);
DOUBLE_ANIMATION(Phanpy);
SINGLE_ANIMATION(Donphan);
SINGLE_ANIMATION(Porygon2);
SINGLE_ANIMATION(Stantler);
SINGLE_ANIMATION(Smeargle);
SINGLE_ANIMATION(Tyrogue);
SINGLE_ANIMATION(Hitmontop);
SINGLE_ANIMATION(Smoochum);
SINGLE_ANIMATION(Elekid);
SINGLE_ANIMATION(Magby);
SINGLE_ANIMATION(Miltank);
SINGLE_ANIMATION(Blissey);
SINGLE_ANIMATION(Raikou);
SINGLE_ANIMATION(Entei);
SINGLE_ANIMATION(Suicune);
SINGLE_ANIMATION(Larvitar);
SINGLE_ANIMATION(Pupitar);
SINGLE_ANIMATION(Tyranitar);
SINGLE_ANIMATION(Lugia);
SINGLE_ANIMATION(HoOh);
SINGLE_ANIMATION(Celebi);
SINGLE_ANIMATION(OldUnownB);
SINGLE_ANIMATION(Treecko);
SINGLE_ANIMATION(Grovyle);
SINGLE_ANIMATION(Sceptile);
SINGLE_ANIMATION(Torchic);
SINGLE_ANIMATION(Combusken);
static const union AnimCmd *const sAnims_Blaziken[] ={
    sAnim_GeneralFrame0,
    sAnim_Blaziken_1,
    sAnim_Blaziken_2,
    sAnim_Blaziken_3,
    sAnim_Blaziken_4,
};
SINGLE_ANIMATION(Mudkip);
SINGLE_ANIMATION(Marshtomp);
SINGLE_ANIMATION(Swampert);
SINGLE_ANIMATION(Poochyena);
SINGLE_ANIMATION(Mightyena);
SINGLE_ANIMATION(Zigzagoon);
SINGLE_ANIMATION(Linoone);
SINGLE_ANIMATION(Wurmple);
DOUBLE_ANIMATION(Silcoon);
DOUBLE_ANIMATION(Beautifly);
DOUBLE_ANIMATION(Cascoon);
DOUBLE_ANIMATION(Dustox);
SINGLE_ANIMATION(Lotad);
SINGLE_ANIMATION(Lombre);
SINGLE_ANIMATION(Ludicolo);
SINGLE_ANIMATION(Seedot);
SINGLE_ANIMATION(Nuzleaf);
SINGLE_ANIMATION(Shiftry);
SINGLE_ANIMATION(Nincada);
SINGLE_ANIMATION(Ninjask);
SINGLE_ANIMATION(Shedinja);
SINGLE_ANIMATION(Taillow);
SINGLE_ANIMATION(Swellow);
SINGLE_ANIMATION(Shroomish);
SINGLE_ANIMATION(Breloom);
SINGLE_ANIMATION(Spinda);
SINGLE_ANIMATION(Wingull);
SINGLE_ANIMATION(Pelipper);
DOUBLE_ANIMATION(Surskit);
DOUBLE_ANIMATION(Masquerain);
SINGLE_ANIMATION(Wailmer);
SINGLE_ANIMATION(Wailord);
SINGLE_ANIMATION(Skitty);
SINGLE_ANIMATION(Delcatty);
SINGLE_ANIMATION(Kecleon);
SINGLE_ANIMATION(Baltoy);
SINGLE_ANIMATION(Claydol);
SINGLE_ANIMATION(Nosepass);
SINGLE_ANIMATION(Torkoal);
SINGLE_ANIMATION(Sableye);
SINGLE_ANIMATION(Barboach);
SINGLE_ANIMATION(Whiscash);
SINGLE_ANIMATION(Luvdisc);
SINGLE_ANIMATION(Corphish);
SINGLE_ANIMATION(Crawdaunt);
SINGLE_ANIMATION(Feebas);
SINGLE_ANIMATION(Milotic);
SINGLE_ANIMATION(Carvanha);
SINGLE_ANIMATION(Sharpedo);
SINGLE_ANIMATION(Trapinch);
SINGLE_ANIMATION(Vibrava);
SINGLE_ANIMATION(Flygon);
SINGLE_ANIMATION(Makuhita);
SINGLE_ANIMATION(Hariyama);
SINGLE_ANIMATION(Electrike);
SINGLE_ANIMATION(Manectric);
SINGLE_ANIMATION(Numel);
SINGLE_ANIMATION(Camerupt);
SINGLE_ANIMATION(Spheal);
SINGLE_ANIMATION(Sealeo);
SINGLE_ANIMATION(Walrein);
SINGLE_ANIMATION(Cacnea);
SINGLE_ANIMATION(Cacturne);
SINGLE_ANIMATION(Snorunt);
SINGLE_ANIMATION(Glalie);
DOUBLE_ANIMATION(Lunatone);
DOUBLE_ANIMATION(Solrock);
SINGLE_ANIMATION(Azurill);
SINGLE_ANIMATION(Spoink);
SINGLE_ANIMATION(Grumpig);
SINGLE_ANIMATION(Plusle);
SINGLE_ANIMATION(Minun);
SINGLE_ANIMATION(Mawile);
SINGLE_ANIMATION(Meditite);
SINGLE_ANIMATION(Medicham);
DOUBLE_ANIMATION(Swablu);
DOUBLE_ANIMATION(Altaria);
SINGLE_ANIMATION(Wynaut);
SINGLE_ANIMATION(Duskull);
SINGLE_ANIMATION(Dusclops);
SINGLE_ANIMATION(Roselia);
SINGLE_ANIMATION(Slakoth);
SINGLE_ANIMATION(Vigoroth);
SINGLE_ANIMATION(Slaking);
SINGLE_ANIMATION(Gulpin);
SINGLE_ANIMATION(Swalot);
SINGLE_ANIMATION(Tropius);
SINGLE_ANIMATION(Whismur);
SINGLE_ANIMATION(Loudred);
SINGLE_ANIMATION(Exploud);
SINGLE_ANIMATION(Clamperl);
SINGLE_ANIMATION(Huntail);
SINGLE_ANIMATION(Gorebyss);
SINGLE_ANIMATION(Absol);
SINGLE_ANIMATION(Shuppet);
SINGLE_ANIMATION(Banette);
SINGLE_ANIMATION(Seviper);
SINGLE_ANIMATION(Zangoose);
SINGLE_ANIMATION(Relicanth);
SINGLE_ANIMATION(Aron);
SINGLE_ANIMATION(Lairon);
SINGLE_ANIMATION(Aggron);
SINGLE_ANIMATION(CastformNormal);
SINGLE_ANIMATION(CastformSunny);
SINGLE_ANIMATION(CastformRainy);
SINGLE_ANIMATION(CastformSnowy);
SINGLE_ANIMATION(Volbeat);
SINGLE_ANIMATION(Illumise);
SINGLE_ANIMATION(Lileep);
SINGLE_ANIMATION(Cradily);
SINGLE_ANIMATION(Anorith);
SINGLE_ANIMATION(Armaldo);
SINGLE_ANIMATION(Ralts);
SINGLE_ANIMATION(Kirlia);
SINGLE_ANIMATION(Gardevoir);
SINGLE_ANIMATION(Bagon);
SINGLE_ANIMATION(Shelgon);
SINGLE_ANIMATION(Salamence);
SINGLE_ANIMATION(Beldum);
SINGLE_ANIMATION(Metang);
SINGLE_ANIMATION(Metagross);
DOUBLE_ANIMATION(Regirock);
SINGLE_ANIMATION(Regice);
DOUBLE_ANIMATION(Registeel);
DOUBLE_ANIMATION(Kyogre);
DOUBLE_ANIMATION(Groudon);
DOUBLE_ANIMATION(Rayquaza);
DOUBLE_ANIMATION(Latias);
DOUBLE_ANIMATION(Latios);
DOUBLE_ANIMATION(Jirachi);
SINGLE_ANIMATION(DeoxysNormal);
SINGLE_ANIMATION(Chimecho);
SINGLE_ANIMATION(Egg);
SINGLE_ANIMATION(UnownB);
SINGLE_ANIMATION(UnownC);
SINGLE_ANIMATION(UnownD);
SINGLE_ANIMATION(UnownE);
SINGLE_ANIMATION(UnownF);
SINGLE_ANIMATION(UnownG);
SINGLE_ANIMATION(UnownH);
SINGLE_ANIMATION(UnownI);
SINGLE_ANIMATION(UnownJ);
SINGLE_ANIMATION(UnownK);
SINGLE_ANIMATION(UnownL);
SINGLE_ANIMATION(UnownM);
SINGLE_ANIMATION(UnownN);
SINGLE_ANIMATION(UnownO);
SINGLE_ANIMATION(UnownP);
SINGLE_ANIMATION(UnownQ);
SINGLE_ANIMATION(UnownR);
SINGLE_ANIMATION(UnownS);
SINGLE_ANIMATION(UnownT);
SINGLE_ANIMATION(UnownU);
SINGLE_ANIMATION(UnownV);
SINGLE_ANIMATION(UnownW);
SINGLE_ANIMATION(UnownX);
SINGLE_ANIMATION(UnownY);
SINGLE_ANIMATION(UnownZ);
SINGLE_ANIMATION(UnownEMark);
SINGLE_ANIMATION(UnownQMark);
#if P_GEN_4_POKEMON == TRUE
SINGLE_ANIMATION(Turtwig);
SINGLE_ANIMATION(Grotle);
SINGLE_ANIMATION(Torterra);
SINGLE_ANIMATION(Chimchar);
SINGLE_ANIMATION(Monferno);
SINGLE_ANIMATION(Infernape);
SINGLE_ANIMATION(Piplup);
SINGLE_ANIMATION(Prinplup);
SINGLE_ANIMATION(Empoleon);
SINGLE_ANIMATION(Starly);
SINGLE_ANIMATION(Staravia);
SINGLE_ANIMATION(Staraptor);
SINGLE_ANIMATION(Bidoof);
DOUBLE_ANIMATION(Bibarel);
SINGLE_ANIMATION(Kricketot);
SINGLE_ANIMATION(Kricketune);
SINGLE_ANIMATION(Shinx);
SINGLE_ANIMATION(Luxio);
DOUBLE_ANIMATION(Luxray);
SINGLE_ANIMATION(Budew);
SINGLE_ANIMATION(Roserade);
SINGLE_ANIMATION(Cranidos);
SINGLE_ANIMATION(Rampardos);
SINGLE_ANIMATION(Shieldon);
SINGLE_ANIMATION(Bastiodon);
SINGLE_ANIMATION(Burmy);
SINGLE_ANIMATION(Wormadam);
SINGLE_ANIMATION(Mothim);
SINGLE_ANIMATION(Combee);
SINGLE_ANIMATION(Vespiquen);
SINGLE_ANIMATION(Pachirisu);
SINGLE_ANIMATION(Buizel);
SINGLE_ANIMATION(Floatzel);
SINGLE_ANIMATION(Cherubi);
DOUBLE_ANIMATION(CherrimOvercast);
SINGLE_ANIMATION(CherrimSunshine);
SINGLE_ANIMATION(Shellos);
SINGLE_ANIMATION(Gastrodon);
SINGLE_ANIMATION(Ambipom);
SINGLE_ANIMATION(Drifloon);
SINGLE_ANIMATION(Drifblim);
SINGLE_ANIMATION(Buneary);
SINGLE_ANIMATION(Lopunny);
SINGLE_ANIMATION(Mismagius);
SINGLE_ANIMATION(Honchkrow);
SINGLE_ANIMATION(Glameow);
SINGLE_ANIMATION(Purugly);
SINGLE_ANIMATION(Chingling);
SINGLE_ANIMATION(Stunky);
SINGLE_ANIMATION(Skuntank);
SINGLE_ANIMATION(Bronzor);
DOUBLE_ANIMATION(Bronzong);
SINGLE_ANIMATION(Bonsly);
SINGLE_ANIMATION(MimeJr);
SINGLE_ANIMATION(Happiny);
SINGLE_ANIMATION(Chatot);
SINGLE_ANIMATION(Spiritomb);
SINGLE_ANIMATION(Gible);
SINGLE_ANIMATION(Gabite);
SINGLE_ANIMATION(Garchomp);
SINGLE_ANIMATION(Munchlax);
SINGLE_ANIMATION(Riolu);
SINGLE_ANIMATION(Lucario);
SINGLE_ANIMATION(Hippopotas);
SINGLE_ANIMATION(Hippowdon);
SINGLE_ANIMATION(Skorupi);
SINGLE_ANIMATION(Drapion);
SINGLE_ANIMATION(Croagunk);
SINGLE_ANIMATION(Toxicroak);
SINGLE_ANIMATION(Carnivine);
SINGLE_ANIMATION(Finneon);
SINGLE_ANIMATION(Lumineon);
SINGLE_ANIMATION(Mantyke);
SINGLE_ANIMATION(Snover);
SINGLE_ANIMATION(Abomasnow);
SINGLE_ANIMATION(Weavile);
SINGLE_ANIMATION(Magnezone);
SINGLE_ANIMATION(Lickilicky);
SINGLE_ANIMATION(Rhyperior);
SINGLE_ANIMATION(Tangrowth);
SINGLE_ANIMATION(Electivire);
SINGLE_ANIMATION(Magmortar);
SINGLE_ANIMATION(Togekiss);
SINGLE_ANIMATION(Yanmega);
SINGLE_ANIMATION(Leafeon);
SINGLE_ANIMATION(Glaceon);
SINGLE_ANIMATION(Gliscor);
SINGLE_ANIMATION(Mamoswine);
SINGLE_ANIMATION(PORYGON_Z);
SINGLE_ANIMATION(Gallade);
DOUBLE_ANIMATION(Probopass);
SINGLE_ANIMATION(Dusknoir);
SINGLE_ANIMATION(Froslass);
DOUBLE_ANIMATION(Rotom);
SINGLE_ANIMATION(RotomHeat);
SINGLE_ANIMATION(RotomFrost);
SINGLE_ANIMATION(RotomFan);
SINGLE_ANIMATION(RotomMow);
SINGLE_ANIMATION(RotomWash);
SINGLE_ANIMATION(Uxie);
SINGLE_ANIMATION(Mesprit);
SINGLE_ANIMATION(Azelf);
SINGLE_ANIMATION(Dialga);
SINGLE_ANIMATION(Palkia);
SINGLE_ANIMATION(Heatran);
SINGLE_ANIMATION(Regigigas);
SINGLE_ANIMATION(GiratinaAltered);
SINGLE_ANIMATION(Cresselia);
SINGLE_ANIMATION(Phione);
SINGLE_ANIMATION(Manaphy);
SINGLE_ANIMATION(Darkrai);
SINGLE_ANIMATION(ShayminLand);
SINGLE_ANIMATION(Arceus);
#endif
#if P_GEN_5_POKEMON == TRUE
SINGLE_ANIMATION(Victini);
SINGLE_ANIMATION(Snivy);
SINGLE_ANIMATION(Servine);
DOUBLE_ANIMATION(Serperior);
SINGLE_ANIMATION(Tepig);
SINGLE_ANIMATION(Pignite);
SINGLE_ANIMATION(Emboar);
SINGLE_ANIMATION(Oshawott);
SINGLE_ANIMATION(Dewott);
SINGLE_ANIMATION(Samurott);
SINGLE_ANIMATION(Patrat);
SINGLE_ANIMATION(Watchog);
SINGLE_ANIMATION(Lillipup);
SINGLE_ANIMATION(Herdier);
SINGLE_ANIMATION(Stoutland);
SINGLE_ANIMATION(Purrloin);
SINGLE_ANIMATION(Liepard);
SINGLE_ANIMATION(Pansage);
SINGLE_ANIMATION(Simisage);
SINGLE_ANIMATION(Pansear);
DOUBLE_ANIMATION(Simisear);
SINGLE_ANIMATION(Panpour);
SINGLE_ANIMATION(Simipour);
SINGLE_ANIMATION(Munna);
DOUBLE_ANIMATION(Musharna);
SINGLE_ANIMATION(Pidove);
SINGLE_ANIMATION(Tranquill);
SINGLE_ANIMATION(Unfezant);
SINGLE_ANIMATION(Blitzle);
SINGLE_ANIMATION(Zebstrika);
SINGLE_ANIMATION(Roggenrola);
SINGLE_ANIMATION(Boldore);
SINGLE_ANIMATION(Gigalith);
SINGLE_ANIMATION(Woobat);
SINGLE_ANIMATION(Swoobat);
DOUBLE_ANIMATION(Drilbur);
SINGLE_ANIMATION(Excadrill);
SINGLE_ANIMATION(Audino);
SINGLE_ANIMATION(Timburr);
SINGLE_ANIMATION(Gurdurr);
SINGLE_ANIMATION(Conkeldurr);
SINGLE_ANIMATION(Tympole);
SINGLE_ANIMATION(Palpitoad);
SINGLE_ANIMATION(Seismitoad);
SINGLE_ANIMATION(Throh);
SINGLE_ANIMATION(Sawk);
DOUBLE_ANIMATION(Sewaddle);
SINGLE_ANIMATION(Swadloon);
SINGLE_ANIMATION(Leavanny);
SINGLE_ANIMATION(Venipede);
SINGLE_ANIMATION(Whirlipede);
SINGLE_ANIMATION(Scolipede);
SINGLE_ANIMATION(Cottonee);
SINGLE_ANIMATION(Whimsicott);
SINGLE_ANIMATION(Petilil);
SINGLE_ANIMATION(Lilligant);
SINGLE_ANIMATION(Basculin);
SINGLE_ANIMATION(Sandile);
SINGLE_ANIMATION(Krokorok);
DOUBLE_ANIMATION(Krookodile);
SINGLE_ANIMATION(Darumaka);
SINGLE_ANIMATION(DarmanitanStandardMode);
SINGLE_ANIMATION(Maractus);
SINGLE_ANIMATION(Dwebble);
SINGLE_ANIMATION(Crustle);
SINGLE_ANIMATION(Scraggy);
SINGLE_ANIMATION(Scrafty);
SINGLE_ANIMATION(Sigilyph);
SINGLE_ANIMATION(Yamask);
SINGLE_ANIMATION(Cofagrigus);
SINGLE_ANIMATION(Tirtouga);
SINGLE_ANIMATION(Carracosta);
SINGLE_ANIMATION(Archen);
SINGLE_ANIMATION(Archeops);
SINGLE_ANIMATION(Trubbish);
SINGLE_ANIMATION(Garbodor);
SINGLE_ANIMATION(Zorua);
SINGLE_ANIMATION(Zoroark);
SINGLE_ANIMATION(Minccino);
SINGLE_ANIMATION(Cinccino);
SINGLE_ANIMATION(Gothita);
DOUBLE_ANIMATION(Gothorita);
SINGLE_ANIMATION(Gothitelle);
SINGLE_ANIMATION(Solosis);
SINGLE_ANIMATION(Duosion);
SINGLE_ANIMATION(Reuniclus);
SINGLE_ANIMATION(Ducklett);
SINGLE_ANIMATION(Swanna);
SINGLE_ANIMATION(Vanillite);
SINGLE_ANIMATION(Vanillish);
SINGLE_ANIMATION(Vanilluxe);
SINGLE_ANIMATION(Deerling);
SINGLE_ANIMATION(Sawsbuck);
SINGLE_ANIMATION(Emolga);
SINGLE_ANIMATION(Karrablast);
SINGLE_ANIMATION(Escavalier);
DOUBLE_ANIMATION(Foongus);
SINGLE_ANIMATION(Amoonguss);
SINGLE_ANIMATION(Frillish);
SINGLE_ANIMATION(Jellicent);
SINGLE_ANIMATION(Alomomola);
SINGLE_ANIMATION(Joltik);
SINGLE_ANIMATION(Galvantula);
SINGLE_ANIMATION(Ferroseed);
DOUBLE_ANIMATION(Ferrothorn);
SINGLE_ANIMATION(Klink);
SINGLE_ANIMATION(Klang);
SINGLE_ANIMATION(Klinklang);
SINGLE_ANIMATION(Tynamo);
SINGLE_ANIMATION(Eelektrik);
SINGLE_ANIMATION(Eelektross);
SINGLE_ANIMATION(Elgyem);
SINGLE_ANIMATION(Beheeyem);
SINGLE_ANIMATION(Litwick);
SINGLE_ANIMATION(Lampent);
SINGLE_ANIMATION(Chandelure);
SINGLE_ANIMATION(Axew);
SINGLE_ANIMATION(Fraxure);
SINGLE_ANIMATION(Haxorus);
SINGLE_ANIMATION(Cubchoo);
SINGLE_ANIMATION(Beartic);
DOUBLE_ANIMATION(Cryogonal);
SINGLE_ANIMATION(Shelmet);
SINGLE_ANIMATION(Accelgor);
SINGLE_ANIMATION(Stunfisk);
SINGLE_ANIMATION(Mienfoo);
SINGLE_ANIMATION(Mienshao);
SINGLE_ANIMATION(Druddigon);
SINGLE_ANIMATION(Golett);
SINGLE_ANIMATION(Golurk);
SINGLE_ANIMATION(Pawniard);
SINGLE_ANIMATION(Bisharp);
SINGLE_ANIMATION(Bouffalant);
SINGLE_ANIMATION(Rufflet);
SINGLE_ANIMATION(Braviary);
SINGLE_ANIMATION(Vullaby);
SINGLE_ANIMATION(Mandibuzz);
SINGLE_ANIMATION(Heatmor);
SINGLE_ANIMATION(Durant);
SINGLE_ANIMATION(Deino);
SINGLE_ANIMATION(Zweilous);
SINGLE_ANIMATION(Hydreigon);
SINGLE_ANIMATION(Larvesta);
SINGLE_ANIMATION(Volcarona);
SINGLE_ANIMATION(Cobalion);
DOUBLE_ANIMATION(Terrakion);
SINGLE_ANIMATION(Virizion);
SINGLE_ANIMATION(TornadusIncarnate);
SINGLE_ANIMATION(ThundurusIncarnate);
SINGLE_ANIMATION(Reshiram);
SINGLE_ANIMATION(Zekrom);
SINGLE_ANIMATION(LandorusIncarnate);
SINGLE_ANIMATION(Kyurem);
SINGLE_ANIMATION(KeldeoOrdinary);
DOUBLE_ANIMATION(MeloettaAria);
SINGLE_ANIMATION(Genesect);
#endif
#if P_GEN_6_POKEMON == TRUE
SINGLE_ANIMATION(Chespin);
DOUBLE_ANIMATION(Quilladin);
SINGLE_ANIMATION(Chesnaught);
SINGLE_ANIMATION(Fennekin);
SINGLE_ANIMATION(Braixen);
SINGLE_ANIMATION(Delphox);
SINGLE_ANIMATION(Froakie);
SINGLE_ANIMATION(Frogadier);
SINGLE_ANIMATION(Greninja);
SINGLE_ANIMATION(GreninjaAsh);
SINGLE_ANIMATION(Bunnelby);
SINGLE_ANIMATION(Diggersby);
SINGLE_ANIMATION(Fletchling);
SINGLE_ANIMATION(Fletchinder);
DOUBLE_ANIMATION(Talonflame);
SINGLE_ANIMATION(Scatterbug);
SINGLE_ANIMATION(Spewpa);
SINGLE_ANIMATION(Vivillon);
SINGLE_ANIMATION(Litleo);
SINGLE_ANIMATION(Pyroar);
DOUBLE_ANIMATION(Flabebe);
SINGLE_ANIMATION(Floette);
DOUBLE_ANIMATION(Florges);
SINGLE_ANIMATION(Skiddo);
SINGLE_ANIMATION(Gogoat);
SINGLE_ANIMATION(Pancham);
SINGLE_ANIMATION(Pangoro);
SINGLE_ANIMATION(Furfrou);
SINGLE_ANIMATION(Espurr);
SINGLE_ANIMATION(Meowstic);
SINGLE_ANIMATION(Honedge);
DOUBLE_ANIMATION(Doublade);
SINGLE_ANIMATION(AegislashShield);
SINGLE_ANIMATION(Spritzee);
SINGLE_ANIMATION(Aromatisse);
SINGLE_ANIMATION(Swirlix);
SINGLE_ANIMATION(Slurpuff);
SINGLE_ANIMATION(Inkay);
SINGLE_ANIMATION(Malamar);
SINGLE_ANIMATION(Binacle);
SINGLE_ANIMATION(Barbaracle);
SINGLE_ANIMATION(Skrelp);
SINGLE_ANIMATION(Dragalge);
SINGLE_ANIMATION(Clauncher);
SINGLE_ANIMATION(Clawitzer);
SINGLE_ANIMATION(Helioptile);
SINGLE_ANIMATION(Heliolisk);
SINGLE_ANIMATION(Tyrunt);
SINGLE_ANIMATION(Tyrantrum);
SINGLE_ANIMATION(Amaura);
SINGLE_ANIMATION(Aurorus);
SINGLE_ANIMATION(Sylveon);
SINGLE_ANIMATION(Hawlucha);
SINGLE_ANIMATION(Dedenne);
SINGLE_ANIMATION(Carbink);
SINGLE_ANIMATION(Goomy);
SINGLE_ANIMATION(Sliggoo);
SINGLE_ANIMATION(Goodra);
SINGLE_ANIMATION(Klefki);
SINGLE_ANIMATION(Phantump);
SINGLE_ANIMATION(Trevenant);
SINGLE_ANIMATION(Pumpkaboo);
SINGLE_ANIMATION(Gourgeist);
DOUBLE_ANIMATION(Bergmite);
SINGLE_ANIMATION(Avalugg);
SINGLE_ANIMATION(Noibat);
SINGLE_ANIMATION(Noivern);
SINGLE_ANIMATION(Xerneas);
SINGLE_ANIMATION(Yveltal);
SINGLE_ANIMATION(Zygarde50);
SINGLE_ANIMATION(Diancie);
SINGLE_ANIMATION(Hoopa);
SINGLE_ANIMATION(Volcanion);
#endif
#if P_GEN_7_POKEMON == TRUE
SINGLE_ANIMATION(Rowlet);
SINGLE_ANIMATION(Dartrix);
SINGLE_ANIMATION(Decidueye);
SINGLE_ANIMATION(Litten);
SINGLE_ANIMATION(Torracat);
SINGLE_ANIMATION(Incineroar);
SINGLE_ANIMATION(Popplio);
SINGLE_ANIMATION(Brionne);
SINGLE_ANIMATION(Primarina);
SINGLE_ANIMATION(Pikipek);
SINGLE_ANIMATION(Trumbeak);
SINGLE_ANIMATION(Toucannon);
SINGLE_ANIMATION(Yungoos);
SINGLE_ANIMATION(Gumshoos);
SINGLE_ANIMATION(Grubbin);
SINGLE_ANIMATION(Charjabug);
SINGLE_ANIMATION(Vikavolt);
SINGLE_ANIMATION(Crabrawler);
SINGLE_ANIMATION(Crabominable);
SINGLE_ANIMATION(Oricorio);
SINGLE_ANIMATION(Cutiefly);
SINGLE_ANIMATION(Ribombee);
SINGLE_ANIMATION(Rockruff);
SINGLE_ANIMATION(LycanrocMidday);
SINGLE_ANIMATION(WishiwashiSolo);
SINGLE_ANIMATION(Mareanie);
SINGLE_ANIMATION(Toxapex);
SINGLE_ANIMATION(Mudbray);
SINGLE_ANIMATION(Mudsdale);
SINGLE_ANIMATION(Dewpider);
SINGLE_ANIMATION(Araquanid);
SINGLE_ANIMATION(Fomantis);
SINGLE_ANIMATION(Lurantis);
SINGLE_ANIMATION(Morelull);
SINGLE_ANIMATION(Shiinotic);
SINGLE_ANIMATION(Salandit);
SINGLE_ANIMATION(Salazzle);
SINGLE_ANIMATION(Stufful);
SINGLE_ANIMATION(Bewear);
SINGLE_ANIMATION(Bounsweet);
SINGLE_ANIMATION(Steenee);
SINGLE_ANIMATION(Tsareena);
SINGLE_ANIMATION(Comfey);
SINGLE_ANIMATION(Oranguru);
SINGLE_ANIMATION(Passimian);
SINGLE_ANIMATION(Wimpod);
SINGLE_ANIMATION(Golisopod);
SINGLE_ANIMATION(Sandygast);
SINGLE_ANIMATION(Palossand);
SINGLE_ANIMATION(Pyukumuku);
SINGLE_ANIMATION(TypeNull);
SINGLE_ANIMATION(Silvally);
SINGLE_ANIMATION(MiniorMeteor);
SINGLE_ANIMATION(Komala);
SINGLE_ANIMATION(Turtonator);
SINGLE_ANIMATION(Togedemaru);
SINGLE_ANIMATION(MimikyuDisguised);
SINGLE_ANIMATION(Bruxish);
SINGLE_ANIMATION(Drampa);
SINGLE_ANIMATION(Dhelmise);
SINGLE_ANIMATION(JANGMO_O);
SINGLE_ANIMATION(HAKAMO_O);
SINGLE_ANIMATION(KOMMO_O);
SINGLE_ANIMATION(TapuKoko);
SINGLE_ANIMATION(TapuLele);
SINGLE_ANIMATION(TapuBulu);
SINGLE_ANIMATION(TapuFini);
SINGLE_ANIMATION(Cosmog);
SINGLE_ANIMATION(Cosmoem);
SINGLE_ANIMATION(Solgaleo);
SINGLE_ANIMATION(Lunala);
SINGLE_ANIMATION(Nihilego);
SINGLE_ANIMATION(Buzzwole);
SINGLE_ANIMATION(Pheromosa);
SINGLE_ANIMATION(Xurkitree);
SINGLE_ANIMATION(Celesteela);
SINGLE_ANIMATION(Kartana);
SINGLE_ANIMATION(Guzzlord);
SINGLE_ANIMATION(Necrozma);
SINGLE_ANIMATION(Magearna);
SINGLE_ANIMATION(Marshadow);
SINGLE_ANIMATION(Poipole);
SINGLE_ANIMATION(Naganadel);
SINGLE_ANIMATION(Stakataka);
SINGLE_ANIMATION(Blacephalon);
SINGLE_ANIMATION(Zeraora);
SINGLE_ANIMATION(Meltan);
SINGLE_ANIMATION(Melmetal);
#endif
#if P_GEN_8_POKEMON == TRUE
SINGLE_ANIMATION(Grookey);
SINGLE_ANIMATION(Thwackey);
SINGLE_ANIMATION(Rillaboom);
SINGLE_ANIMATION(Scorbunny);
SINGLE_ANIMATION(Raboot);
SINGLE_ANIMATION(Cinderace);
SINGLE_ANIMATION(Sobble);
SINGLE_ANIMATION(Drizzile);
SINGLE_ANIMATION(Inteleon);
SINGLE_ANIMATION(Skwovet);
SINGLE_ANIMATION(Greedent);
SINGLE_ANIMATION(Rookidee);
SINGLE_ANIMATION(Corvisquire);
SINGLE_ANIMATION(Corviknight);
SINGLE_ANIMATION(Blipbug);
SINGLE_ANIMATION(Dottler);
SINGLE_ANIMATION(Orbeetle);
SINGLE_ANIMATION(Nickit);
SINGLE_ANIMATION(Thievul);
SINGLE_ANIMATION(Gossifleur);
SINGLE_ANIMATION(Eldegoss);
SINGLE_ANIMATION(Wooloo);
SINGLE_ANIMATION(Dubwool);
SINGLE_ANIMATION(Chewtle);
SINGLE_ANIMATION(Drednaw);
SINGLE_ANIMATION(Yamper);
SINGLE_ANIMATION(Boltund);
SINGLE_ANIMATION(Rolycoly);
SINGLE_ANIMATION(Carkol);
SINGLE_ANIMATION(Coalossal);
SINGLE_ANIMATION(Applin);
SINGLE_ANIMATION(Flapple);
SINGLE_ANIMATION(Appletun);
SINGLE_ANIMATION(Silicobra);
SINGLE_ANIMATION(Sandaconda);
SINGLE_ANIMATION(Cramorant);
SINGLE_ANIMATION(Arrokuda);
SINGLE_ANIMATION(Barraskewda);
SINGLE_ANIMATION(Toxel);
SINGLE_ANIMATION(Toxtricity);
SINGLE_ANIMATION(Sizzlipede);
SINGLE_ANIMATION(Centiskorch);
SINGLE_ANIMATION(Clobbopus);
SINGLE_ANIMATION(Grapploct);
SINGLE_ANIMATION(Sinistea);
SINGLE_ANIMATION(Polteageist);
SINGLE_ANIMATION(Hatenna);
SINGLE_ANIMATION(Hattrem);
SINGLE_ANIMATION(Hatterene);
SINGLE_ANIMATION(Impidimp);
SINGLE_ANIMATION(Morgrem);
SINGLE_ANIMATION(Grimmsnarl);
SINGLE_ANIMATION(Obstagoon);
SINGLE_ANIMATION(Perrserker);
SINGLE_ANIMATION(Cursola);
SINGLE_ANIMATION(Sirfetchd);
SINGLE_ANIMATION(MrRime);
SINGLE_ANIMATION(Runerigus);
SINGLE_ANIMATION(Milcery);
SINGLE_ANIMATION(Alcremie);
SINGLE_ANIMATION(Falinks);
SINGLE_ANIMATION(Pincurchin);
SINGLE_ANIMATION(Snom);
SINGLE_ANIMATION(Frosmoth);
SINGLE_ANIMATION(Stonjourner);
SINGLE_ANIMATION(Eiscue);
SINGLE_ANIMATION(Indeedee);
SINGLE_ANIMATION(Morpeko);
SINGLE_ANIMATION(Cufant);
SINGLE_ANIMATION(Copperajah);
SINGLE_ANIMATION(Dracozolt);
SINGLE_ANIMATION(Arctozolt);
SINGLE_ANIMATION(Dracovish);
SINGLE_ANIMATION(Arctovish);
SINGLE_ANIMATION(Duraludon);
SINGLE_ANIMATION(Dreepy);
SINGLE_ANIMATION(Drakloak);
SINGLE_ANIMATION(Dragapult);
SINGLE_ANIMATION(Zacian);
SINGLE_ANIMATION(Zamazenta);
SINGLE_ANIMATION(Eternatus);
SINGLE_ANIMATION(Kubfu);
SINGLE_ANIMATION(Urshifu);
SINGLE_ANIMATION(Zarude);
SINGLE_ANIMATION(Regieleki);
SINGLE_ANIMATION(Regidrago);
SINGLE_ANIMATION(Glastrier);
SINGLE_ANIMATION(Spectrier);
SINGLE_ANIMATION(Calyrex);
SINGLE_ANIMATION(Wyrdeer);
SINGLE_ANIMATION(Kleavor);
SINGLE_ANIMATION(Ursaluna);
SINGLE_ANIMATION(Basculegion);
SINGLE_ANIMATION(Sneasler);
SINGLE_ANIMATION(Overqwil);
SINGLE_ANIMATION(EnamorusIncarnate);
#endif
#if P_GEN_9_POKEMON == TRUE
SINGLE_ANIMATION(Sprigatito);
SINGLE_ANIMATION(Floragato);
SINGLE_ANIMATION(Meowscarada);
SINGLE_ANIMATION(Fuecoco);
SINGLE_ANIMATION(Crocalor);
SINGLE_ANIMATION(Skeledirge);
SINGLE_ANIMATION(Quaxly);
SINGLE_ANIMATION(Quaxwell);
SINGLE_ANIMATION(Quaquaval);
SINGLE_ANIMATION(Lechonk);
SINGLE_ANIMATION(Oinkologne);
SINGLE_ANIMATION(Tarountula);
SINGLE_ANIMATION(Spidops);
SINGLE_ANIMATION(Nymble);
SINGLE_ANIMATION(Lokix);
SINGLE_ANIMATION(Pawmi);
SINGLE_ANIMATION(Pawmo);
SINGLE_ANIMATION(Pawmot);
SINGLE_ANIMATION(Tandemaus);
SINGLE_ANIMATION(Maushold);
SINGLE_ANIMATION(Fidough);
SINGLE_ANIMATION(Dachsbun);
SINGLE_ANIMATION(Smoliv);
SINGLE_ANIMATION(Dolliv);
SINGLE_ANIMATION(Arboliva);
SINGLE_ANIMATION(Squawkabilly);
SINGLE_ANIMATION(Nacli);
SINGLE_ANIMATION(Naclstack);
SINGLE_ANIMATION(Garganacl);
SINGLE_ANIMATION(Charcadet);
SINGLE_ANIMATION(Armarouge);
SINGLE_ANIMATION(Ceruledge);
SINGLE_ANIMATION(Tadbulb);
SINGLE_ANIMATION(Bellibolt);
SINGLE_ANIMATION(Wattrel);
SINGLE_ANIMATION(Kilowattrel);
SINGLE_ANIMATION(Maschiff);
SINGLE_ANIMATION(Mabosstiff);
SINGLE_ANIMATION(Shroodle);
SINGLE_ANIMATION(Grafaiai);
SINGLE_ANIMATION(Bramblin);
SINGLE_ANIMATION(Brambleghast);
SINGLE_ANIMATION(Toedscool);
SINGLE_ANIMATION(Toedscruel);
SINGLE_ANIMATION(Klawf);
SINGLE_ANIMATION(Capsakid);
SINGLE_ANIMATION(Scovillain);
SINGLE_ANIMATION(Rellor);
SINGLE_ANIMATION(Rabsca);
SINGLE_ANIMATION(Flittle);
SINGLE_ANIMATION(Espathra);
SINGLE_ANIMATION(Tinkatink);
SINGLE_ANIMATION(Tinkatuff);
SINGLE_ANIMATION(Tinkaton);
SINGLE_ANIMATION(Wiglett);
SINGLE_ANIMATION(Wugtrio);
SINGLE_ANIMATION(Bombirdier);
SINGLE_ANIMATION(Finizen);
SINGLE_ANIMATION(Palafin);
SINGLE_ANIMATION(Varoom);
SINGLE_ANIMATION(Revavroom);
SINGLE_ANIMATION(Cyclizar);
SINGLE_ANIMATION(Orthworm);
SINGLE_ANIMATION(Glimmet);
SINGLE_ANIMATION(Glimmora);
SINGLE_ANIMATION(Greavard);
SINGLE_ANIMATION(Houndstone);
SINGLE_ANIMATION(Flamigo);
SINGLE_ANIMATION(Cetoddle);
SINGLE_ANIMATION(Cetitan);
SINGLE_ANIMATION(Veluza);
SINGLE_ANIMATION(Dondozo);
SINGLE_ANIMATION(Tatsugiri);
SINGLE_ANIMATION(Annihilape);
SINGLE_ANIMATION(Clodsire);
SINGLE_ANIMATION(Farigiraf);
SINGLE_ANIMATION(Dudunsparce);
SINGLE_ANIMATION(Kingambit);
SINGLE_ANIMATION(GreatTusk);
SINGLE_ANIMATION(ScreamTail);
SINGLE_ANIMATION(BruteBonnet);
SINGLE_ANIMATION(FlutterMane);
SINGLE_ANIMATION(SlitherWing);
SINGLE_ANIMATION(SandyShocks);
SINGLE_ANIMATION(IronTreads);
SINGLE_ANIMATION(IronBundle);
SINGLE_ANIMATION(IronHands);
SINGLE_ANIMATION(IronJugulis);
SINGLE_ANIMATION(IronMoth);
SINGLE_ANIMATION(IronThorns);
SINGLE_ANIMATION(Frigibax);
SINGLE_ANIMATION(Arctibax);
SINGLE_ANIMATION(Baxcalibur);
SINGLE_ANIMATION(Gimmighoul);
SINGLE_ANIMATION(Gholdengo);
SINGLE_ANIMATION(WoChien);
SINGLE_ANIMATION(ChienPao);
SINGLE_ANIMATION(TingLu);
SINGLE_ANIMATION(ChiYu);
SINGLE_ANIMATION(RoaringMoon);
SINGLE_ANIMATION(IronValiant);
SINGLE_ANIMATION(Koraidon);
SINGLE_ANIMATION(Miraidon);
SINGLE_ANIMATION(WalkingWake);
SINGLE_ANIMATION(IronLeaves);
SINGLE_ANIMATION(Dipplin);
SINGLE_ANIMATION(Sinistcha);
SINGLE_ANIMATION(Poltchageist);
SINGLE_ANIMATION(Okidogi);
SINGLE_ANIMATION(Munkidori);
SINGLE_ANIMATION(Fezandipiti);
SINGLE_ANIMATION(Ogerpon);
#endif
SINGLE_ANIMATION(VenusaurMega);
SINGLE_ANIMATION(CHARIZARD_MEGA_X);
SINGLE_ANIMATION(CHARIZARD_MEGA_Y);
SINGLE_ANIMATION(BlastoiseMega);
SINGLE_ANIMATION(BeedrillMega);
SINGLE_ANIMATION(PidgeotMega);
SINGLE_ANIMATION(AlakazamMega);
SINGLE_ANIMATION(SlowbroMega);
SINGLE_ANIMATION(GengarMega);
SINGLE_ANIMATION(KangaskhanMega);
SINGLE_ANIMATION(PinsirMega);
SINGLE_ANIMATION(GyaradosMega);
SINGLE_ANIMATION(AerodactylMega);
SINGLE_ANIMATION(MEWTWO_MEGA_X);
SINGLE_ANIMATION(MEWTWO_MEGA_Y);
SINGLE_ANIMATION(AmpharosMega);
SINGLE_ANIMATION(SteelixMega);
SINGLE_ANIMATION(ScizorMega);
SINGLE_ANIMATION(HeracrossMega);
SINGLE_ANIMATION(HoundoomMega);
SINGLE_ANIMATION(TyranitarMega);
SINGLE_ANIMATION(SceptileMega);
SINGLE_ANIMATION(BlazikenMega);
SINGLE_ANIMATION(SwampertMega);
SINGLE_ANIMATION(GardevoirMega);
SINGLE_ANIMATION(SableyeMega);
SINGLE_ANIMATION(MawileMega);
SINGLE_ANIMATION(AggronMega);
SINGLE_ANIMATION(MedichamMega);
SINGLE_ANIMATION(ManectricMega);
SINGLE_ANIMATION(SharpedoMega);
SINGLE_ANIMATION(CameruptMega);
SINGLE_ANIMATION(AltariaMega);
SINGLE_ANIMATION(BanetteMega);
SINGLE_ANIMATION(AbsolMega);
SINGLE_ANIMATION(GlalieMega);
SINGLE_ANIMATION(SalamenceMega);
SINGLE_ANIMATION(MetagrossMega);
SINGLE_ANIMATION(LatiasMega);
SINGLE_ANIMATION(LatiosMega);
SINGLE_ANIMATION(KyogrePrimal);
SINGLE_ANIMATION(GroudonPrimal);
SINGLE_ANIMATION(RayquazaMega);
#if P_GEN_4_POKEMON == TRUE
SINGLE_ANIMATION(LopunnyMega);
SINGLE_ANIMATION(GarchompMega);
SINGLE_ANIMATION(LucarioMega);
SINGLE_ANIMATION(AbomasnowMega);
SINGLE_ANIMATION(GalladeMega);
#endif
#if P_GEN_5_POKEMON == TRUE
SINGLE_ANIMATION(AudinoMega);
#endif
#if P_GEN_6_POKEMON == TRUE
SINGLE_ANIMATION(DiancieMega);
#endif
SINGLE_ANIMATION(RattataAlolan);
SINGLE_ANIMATION(RaticateAlolan);
SINGLE_ANIMATION(RaichuAlolan);
SINGLE_ANIMATION(SandshrewAlolan);
SINGLE_ANIMATION(SandslashAlolan);
SINGLE_ANIMATION(VulpixAlolan);
SINGLE_ANIMATION(NinetalesAlolan);
SINGLE_ANIMATION(DiglettAlolan);
SINGLE_ANIMATION(DugtrioAlolan);
SINGLE_ANIMATION(MeowthAlolan);
SINGLE_ANIMATION(PersianAlolan);
SINGLE_ANIMATION(GeodudeAlolan);
SINGLE_ANIMATION(GravelerAlolan);
SINGLE_ANIMATION(GolemAlolan);
SINGLE_ANIMATION(GrimerAlolan);
SINGLE_ANIMATION(MukAlolan);
SINGLE_ANIMATION(ExeggutorAlolan);
SINGLE_ANIMATION(MarowakAlolan);
SINGLE_ANIMATION(MeowthGalarian);
SINGLE_ANIMATION(PonytaGalarian);
SINGLE_ANIMATION(RapidashGalarian);
SINGLE_ANIMATION(SlowpokeGalarian);
SINGLE_ANIMATION(SlowbroGalarian);
SINGLE_ANIMATION(FarfetchdGalarian);
SINGLE_ANIMATION(WeezingGalarian);
SINGLE_ANIMATION(MrMimeGalarian);
SINGLE_ANIMATION(ArticunoGalarian);
SINGLE_ANIMATION(ZapdosGalarian);
SINGLE_ANIMATION(MoltresGalarian);
SINGLE_ANIMATION(SlowkingGalarian);
SINGLE_ANIMATION(CorsolaGalarian);
SINGLE_ANIMATION(ZigzagoonGalarian);
SINGLE_ANIMATION(LinooneGalarian);
#if P_GEN_5_POKEMON == TRUE
SINGLE_ANIMATION(DarumakaGalarian);
SINGLE_ANIMATION(DarmanitanGalarianStandardMode);
SINGLE_ANIMATION(YamaskGalarian);
SINGLE_ANIMATION(StunfiskGalarian);
#endif
SINGLE_ANIMATION(GrowlitheHisuian);
SINGLE_ANIMATION(ArcanineHisuian);
SINGLE_ANIMATION(VoltorbHisuian);
SINGLE_ANIMATION(ElectrodeHisuian);
SINGLE_ANIMATION(TyphlosionHisuian);
SINGLE_ANIMATION(QwilfishHisuian);
SINGLE_ANIMATION(SneaselHisuian);
#if P_GEN_5_POKEMON == TRUE
SINGLE_ANIMATION(SamurottHisuian);
SINGLE_ANIMATION(LilligantHisuian);
SINGLE_ANIMATION(ZoruaHisuian);
SINGLE_ANIMATION(ZoroarkHisuian);
SINGLE_ANIMATION(BraviaryHisuian);
#endif
#if P_GEN_6_POKEMON == TRUE
SINGLE_ANIMATION(SliggooHisuian);
SINGLE_ANIMATION(GoodraHisuian);
SINGLE_ANIMATION(AvaluggHisuian);
#endif
#if P_GEN_7_POKEMON == TRUE
SINGLE_ANIMATION(DecidueyeHisuian);
#endif
SINGLE_ANIMATION(WooperPaldean);
SINGLE_ANIMATION(TaurosPaldean);
SINGLE_ANIMATION(PikachuCosplay);
SINGLE_ANIMATION(PikachuRockStar);
SINGLE_ANIMATION(PikachuBelle);
SINGLE_ANIMATION(PikachuPopStar);
SINGLE_ANIMATION(PIKACHU_PH_D);
SINGLE_ANIMATION(PikachuLibre);
SINGLE_ANIMATION(PikachuOriginalCap);
SINGLE_ANIMATION(PikachuHoennCap);
SINGLE_ANIMATION(PikachuSinnohCap);
SINGLE_ANIMATION(PikachuUnovaCap);
SINGLE_ANIMATION(PikachuKalosCap);
SINGLE_ANIMATION(PikachuAlolaCap);
SINGLE_ANIMATION(PikachuPartnerCap);
SINGLE_ANIMATION(PikachuWorldCap);
SINGLE_ANIMATION(PichuSpikyEared);
DOUBLE_ANIMATION(DeoxysAttack);
DOUBLE_ANIMATION(DeoxysDefense);
DOUBLE_ANIMATION(DeoxysSpeed);
#if P_GEN_4_POKEMON == TRUE
SINGLE_ANIMATION(DialgaOrigin);
SINGLE_ANIMATION(PalkiaOrigin);
DOUBLE_ANIMATION(GiratinaOrigin);
SINGLE_ANIMATION(ShayminSky);
#endif
#if P_GEN_5_POKEMON == TRUE
SINGLE_ANIMATION(DarmanitanZenMode);
SINGLE_ANIMATION(DarmanitanGalarianZenMode);
SINGLE_ANIMATION(TornadusTherian);
SINGLE_ANIMATION(ThundurusTherian);
SINGLE_ANIMATION(LandorusTherian);
SINGLE_ANIMATION(KyuremBlack);
SINGLE_ANIMATION(KyuremWhite);
SINGLE_ANIMATION(KeldeoResolute);
SINGLE_ANIMATION(MeloettaPirouette);
#endif
#if P_GEN_6_POKEMON == TRUE
SINGLE_ANIMATION(AegislashBlade);
SINGLE_ANIMATION(Zygarde10);
SINGLE_ANIMATION(ZygardeComplete);
SINGLE_ANIMATION(HoopaUnbound);
#endif
#if P_GEN_7_POKEMON == TRUE
SINGLE_ANIMATION(MiniorCore);
SINGLE_ANIMATION(WishiwashiSchool);
SINGLE_ANIMATION(MimikyuBusted);
SINGLE_ANIMATION(LycanrocMidnight);
SINGLE_ANIMATION(LycanrocDusk);
#endif
#if P_GEN_8_POKEMON == TRUE
SINGLE_ANIMATION(EnamorusTherian);
SINGLE_ANIMATION(UrsalunaBloodmoon);
#endif
// Gigantamax Forms
SINGLE_ANIMATION(VenusaurGigantamax);
SINGLE_ANIMATION(CharizardGigantamax);
SINGLE_ANIMATION(BlastoiseGigantamax);
SINGLE_ANIMATION(ButterfreeGigantamax);
SINGLE_ANIMATION(PikachuGigantamax);
SINGLE_ANIMATION(MeowthGigantamax);
SINGLE_ANIMATION(MachampGigantamax);
SINGLE_ANIMATION(GengarGigantamax);
SINGLE_ANIMATION(KinglerGigantamax);
SINGLE_ANIMATION(LaprasGigantamax);
SINGLE_ANIMATION(EeveeGigantamax);
SINGLE_ANIMATION(SnorlaxGigantamax);
#if P_GEN_5_POKEMON == TRUE
SINGLE_ANIMATION(GarbodorGigantamax);
#endif
#if P_GEN_7_POKEMON == TRUE
SINGLE_ANIMATION(MelmetalGigantamax);
#endif
#if P_GEN_8_POKEMON == TRUE
SINGLE_ANIMATION(RillaboomGigantamax);
SINGLE_ANIMATION(CinderaceGigantamax);
SINGLE_ANIMATION(InteleonGigantamax);
SINGLE_ANIMATION(CorviknightGigantamax);
SINGLE_ANIMATION(OrbeetleGigantamax);
SINGLE_ANIMATION(DrednawGigantamax);
SINGLE_ANIMATION(CoalossalGigantamax);
SINGLE_ANIMATION(FlappleGigantamax);
SINGLE_ANIMATION(AppletunGigantamax);
SINGLE_ANIMATION(SandacondaGigantamax);
SINGLE_ANIMATION(ToxtricityGigantamax);
SINGLE_ANIMATION(CentiskorchGigantamax);
SINGLE_ANIMATION(HattereneGigantamax);
SINGLE_ANIMATION(GrimmsnarlGigantamax);
SINGLE_ANIMATION(AlcremieGigantamax);
SINGLE_ANIMATION(CopperajahGigantamax);
SINGLE_ANIMATION(DuraludonGigantamax);
SINGLE_ANIMATION(UrshifuSingleStrikeStyleGigantamax);
SINGLE_ANIMATION(UrshifuRapidStrikeStyleGigantamax);
#endif

const union AnimCmd *const *const gMonFrontAnimsPtrTable[NUM_SPECIES + 1] =
{   // Gen 1
    [SPECIES_NONE]                           = sAnims_None,
    [SPECIES_BULBASAUR]                      = sAnims_Bulbasaur,
    [SPECIES_IVYSAUR]                        = sAnims_Ivysaur,
    [SPECIES_VENUSAUR]                       = sAnims_Venusaur,
    [SPECIES_CHARMANDER]                     = sAnims_Charmander,
    [SPECIES_CHARMELEON]                     = sAnims_Charmeleon,
    [SPECIES_CHARIZARD]                      = sAnims_Charizard,
    [SPECIES_SQUIRTLE]                       = sAnims_Squirtle,
    [SPECIES_WARTORTLE]                      = sAnims_Wartortle,
    [SPECIES_BLASTOISE]                      = sAnims_Blastoise,
    [SPECIES_CATERPIE]                       = sAnims_Caterpie,
    [SPECIES_METAPOD]                        = sAnims_Metapod,
    [SPECIES_BUTTERFREE]                     = sAnims_Butterfree,
    [SPECIES_WEEDLE]                         = sAnims_Weedle,
    [SPECIES_KAKUNA]                         = sAnims_Kakuna,
    [SPECIES_BEEDRILL]                       = sAnims_Beedrill,
    [SPECIES_PIDGEY]                         = sAnims_Pidgey,
    [SPECIES_PIDGEOTTO]                      = sAnims_Pidgeotto,
    [SPECIES_PIDGEOT]                        = sAnims_Pidgeot,
    [SPECIES_RATTATA]                        = sAnims_Rattata,
    [SPECIES_RATICATE]                       = sAnims_Raticate,
    [SPECIES_SPEAROW]                        = sAnims_Spearow,
    [SPECIES_FEAROW]                         = sAnims_Fearow,
    [SPECIES_EKANS]                          = sAnims_Ekans,
    [SPECIES_ARBOK]                          = sAnims_Arbok,
    [SPECIES_PIKACHU]                        = sAnims_Pikachu,
    [SPECIES_RAICHU]                         = sAnims_Raichu,
    [SPECIES_SANDSHREW]                      = sAnims_Sandshrew,
    [SPECIES_SANDSLASH]                      = sAnims_Sandslash,
    [SPECIES_NIDORAN_F]                      = sAnims_NidoranF,
    [SPECIES_NIDORINA]                       = sAnims_Nidorina,
    [SPECIES_NIDOQUEEN]                      = sAnims_Nidoqueen,
    [SPECIES_NIDORAN_M]                      = sAnims_NidoranM,
    [SPECIES_NIDORINO]                       = sAnims_Nidorino,
    [SPECIES_NIDOKING]                       = sAnims_Nidoking,
    [SPECIES_CLEFAIRY]                       = sAnims_Clefairy,
    [SPECIES_CLEFABLE]                       = sAnims_Clefable,
    [SPECIES_VULPIX]                         = sAnims_Vulpix,
    [SPECIES_NINETALES]                      = sAnims_Ninetales,
    [SPECIES_JIGGLYPUFF]                     = sAnims_Jigglypuff,
    [SPECIES_WIGGLYTUFF]                     = sAnims_Wigglytuff,
    [SPECIES_ZUBAT]                          = sAnims_Zubat,
    [SPECIES_GOLBAT]                         = sAnims_Golbat,
    [SPECIES_ODDISH]                         = sAnims_Oddish,
    [SPECIES_GLOOM]                          = sAnims_Gloom,
    [SPECIES_VILEPLUME]                      = sAnims_Vileplume,
    [SPECIES_PARAS]                          = sAnims_Paras,
    [SPECIES_PARASECT]                       = sAnims_Parasect,
    [SPECIES_VENONAT]                        = sAnims_Venonat,
    [SPECIES_VENOMOTH]                       = sAnims_Venomoth,
    [SPECIES_DIGLETT]                        = sAnims_Diglett,
    [SPECIES_DUGTRIO]                        = sAnims_Dugtrio,
    [SPECIES_MEOWTH]                         = sAnims_Meowth,
    [SPECIES_PERSIAN]                        = sAnims_Persian,
    [SPECIES_PSYDUCK]                        = sAnims_Psyduck,
    [SPECIES_GOLDUCK]                        = sAnims_Golduck,
    [SPECIES_MANKEY]                         = sAnims_Mankey,
    [SPECIES_PRIMEAPE]                       = sAnims_Primeape,
    [SPECIES_GROWLITHE]                      = sAnims_Growlithe,
    [SPECIES_ARCANINE]                       = sAnims_Arcanine,
    [SPECIES_POLIWAG]                        = sAnims_Poliwag,
    [SPECIES_POLIWHIRL]                      = sAnims_Poliwhirl,
    [SPECIES_POLIWRATH]                      = sAnims_Poliwrath,
    [SPECIES_ABRA]                           = sAnims_Abra,
    [SPECIES_KADABRA]                        = sAnims_Kadabra,
    [SPECIES_ALAKAZAM]                       = sAnims_Alakazam,
    [SPECIES_MACHOP]                         = sAnims_Machop,
    [SPECIES_MACHOKE]                        = sAnims_Machoke,
    [SPECIES_MACHAMP]                        = sAnims_Machamp,
    [SPECIES_BELLSPROUT]                     = sAnims_Bellsprout,
    [SPECIES_WEEPINBELL]                     = sAnims_Weepinbell,
    [SPECIES_VICTREEBEL]                     = sAnims_Victreebel,
    [SPECIES_TENTACOOL]                      = sAnims_Tentacool,
    [SPECIES_TENTACRUEL]                     = sAnims_Tentacruel,
    [SPECIES_GEODUDE]                        = sAnims_Geodude,
    [SPECIES_GRAVELER]                       = sAnims_Graveler,
    [SPECIES_GOLEM]                          = sAnims_Golem,
    [SPECIES_PONYTA]                         = sAnims_Ponyta,
    [SPECIES_RAPIDASH]                       = sAnims_Rapidash,
    [SPECIES_SLOWPOKE]                       = sAnims_Slowpoke,
    [SPECIES_SLOWBRO]                        = sAnims_Slowbro,
    [SPECIES_MAGNEMITE]                      = sAnims_Magnemite,
    [SPECIES_MAGNETON]                       = sAnims_Magneton,
    [SPECIES_FARFETCHD]                      = sAnims_Farfetchd,
    [SPECIES_DODUO]                          = sAnims_Doduo,
    [SPECIES_DODRIO]                         = sAnims_Dodrio,
    [SPECIES_SEEL]                           = sAnims_Seel,
    [SPECIES_DEWGONG]                        = sAnims_Dewgong,
    [SPECIES_GRIMER]                         = sAnims_Grimer,
    [SPECIES_MUK]                            = sAnims_Muk,
    [SPECIES_SHELLDER]                       = sAnims_Shellder,
    [SPECIES_CLOYSTER]                       = sAnims_Cloyster,
    [SPECIES_GASTLY]                         = sAnims_Gastly,
    [SPECIES_HAUNTER]                        = sAnims_Haunter,
    [SPECIES_GENGAR]                         = sAnims_Gengar,
    [SPECIES_ONIX]                           = sAnims_Onix,
    [SPECIES_DROWZEE]                        = sAnims_Drowzee,
    [SPECIES_HYPNO]                          = sAnims_Hypno,
    [SPECIES_KRABBY]                         = sAnims_Krabby,
    [SPECIES_KINGLER]                        = sAnims_Kingler,
    [SPECIES_VOLTORB]                        = sAnims_Voltorb,
    [SPECIES_ELECTRODE]                      = sAnims_Electrode,
    [SPECIES_EXEGGCUTE]                      = sAnims_Exeggcute,
    [SPECIES_EXEGGUTOR]                      = sAnims_Exeggutor,
    [SPECIES_CUBONE]                         = sAnims_Cubone,
    [SPECIES_MAROWAK]                        = sAnims_Marowak,
    [SPECIES_HITMONLEE]                      = sAnims_Hitmonlee,
    [SPECIES_HITMONCHAN]                     = sAnims_Hitmonchan,
    [SPECIES_LICKITUNG]                      = sAnims_Lickitung,
    [SPECIES_KOFFING]                        = sAnims_Koffing,
    [SPECIES_WEEZING]                        = sAnims_Weezing,
    [SPECIES_RHYHORN]                        = sAnims_Rhyhorn,
    [SPECIES_RHYDON]                         = sAnims_Rhydon,
    [SPECIES_CHANSEY]                        = sAnims_Chansey,
    [SPECIES_TANGELA]                        = sAnims_Tangela,
    [SPECIES_KANGASKHAN]                     = sAnims_Kangaskhan,
    [SPECIES_HORSEA]                         = sAnims_Horsea,
    [SPECIES_SEADRA]                         = sAnims_Seadra,
    [SPECIES_GOLDEEN]                        = sAnims_Goldeen,
    [SPECIES_SEAKING]                        = sAnims_Seaking,
    [SPECIES_STARYU]                         = sAnims_Staryu,
    [SPECIES_STARMIE]                        = sAnims_Starmie,
    [SPECIES_MR_MIME]                        = sAnims_MrMime,
    [SPECIES_SCYTHER]                        = sAnims_Scyther,
    [SPECIES_JYNX]                           = sAnims_Jynx,
    [SPECIES_ELECTABUZZ]                     = sAnims_Electabuzz,
    [SPECIES_MAGMAR]                         = sAnims_Magmar,
    [SPECIES_PINSIR]                         = sAnims_Pinsir,
    [SPECIES_TAUROS]                         = sAnims_Tauros,
    [SPECIES_TAUROS_PALDEAN_COMBAT_BREED]    = sAnims_TaurosPaldean,
    [SPECIES_TAUROS_PALDEAN_BLAZE_BREED]     = sAnims_TaurosPaldean,
    [SPECIES_TAUROS_PALDEAN_AQUA_BREED]      = sAnims_TaurosPaldean,
    [SPECIES_MAGIKARP]                       = sAnims_Magikarp,
    [SPECIES_GYARADOS]                       = sAnims_Gyarados,
    [SPECIES_LAPRAS]                         = sAnims_Lapras,
    [SPECIES_DITTO]                          = sAnims_Ditto,
    [SPECIES_EEVEE]                          = sAnims_Eevee,
    [SPECIES_VAPOREON]                       = sAnims_Vaporeon,
    [SPECIES_JOLTEON]                        = sAnims_Jolteon,
    [SPECIES_FLAREON]                        = sAnims_Flareon,
    [SPECIES_PORYGON]                        = sAnims_Porygon,
    [SPECIES_OMANYTE]                        = sAnims_Omanyte,
    [SPECIES_OMASTAR]                        = sAnims_Omastar,
    [SPECIES_KABUTO]                         = sAnims_Kabuto,
    [SPECIES_KABUTOPS]                       = sAnims_Kabutops,
    [SPECIES_AERODACTYL]                     = sAnims_Aerodactyl,
    [SPECIES_SNORLAX]                        = sAnims_Snorlax,
    [SPECIES_ARTICUNO]                       = sAnims_Articuno,
    [SPECIES_ZAPDOS]                         = sAnims_Zapdos,
    [SPECIES_MOLTRES]                        = sAnims_Moltres,
    [SPECIES_DRATINI]                        = sAnims_Dratini,
    [SPECIES_DRAGONAIR]                      = sAnims_Dragonair,
    [SPECIES_DRAGONITE]                      = sAnims_Dragonite,
    [SPECIES_MEWTWO]                         = sAnims_Mewtwo,
    [SPECIES_MEW]                            = sAnims_Mew,
    // Gen 2
    [SPECIES_CHIKORITA]                      = sAnims_Chikorita,
    [SPECIES_BAYLEEF]                        = sAnims_Bayleef,
    [SPECIES_MEGANIUM]                       = sAnims_Meganium,
    [SPECIES_CYNDAQUIL]                      = sAnims_Cyndaquil,
    [SPECIES_QUILAVA]                        = sAnims_Quilava,
    [SPECIES_TYPHLOSION]                     = sAnims_Typhlosion,
    [SPECIES_TOTODILE]                       = sAnims_Totodile,
    [SPECIES_CROCONAW]                       = sAnims_Croconaw,
    [SPECIES_FERALIGATR]                     = sAnims_Feraligatr,
    [SPECIES_SENTRET]                        = sAnims_Sentret,
    [SPECIES_FURRET]                         = sAnims_Furret,
    [SPECIES_HOOTHOOT]                       = sAnims_Hoothoot,
    [SPECIES_NOCTOWL]                        = sAnims_Noctowl,
    [SPECIES_LEDYBA]                         = sAnims_Ledyba,
    [SPECIES_LEDIAN]                         = sAnims_Ledian,
    [SPECIES_SPINARAK]                       = sAnims_Spinarak,
    [SPECIES_ARIADOS]                        = sAnims_Ariados,
    [SPECIES_CROBAT]                         = sAnims_Crobat,
    [SPECIES_CHINCHOU]                       = sAnims_Chinchou,
    [SPECIES_LANTURN]                        = sAnims_Lanturn,
    [SPECIES_PICHU]                          = sAnims_Pichu,
    [SPECIES_CLEFFA]                         = sAnims_Cleffa,
    [SPECIES_IGGLYBUFF]                      = sAnims_Igglybuff,
    [SPECIES_TOGEPI]                         = sAnims_Togepi,
    [SPECIES_TOGETIC]                        = sAnims_Togetic,
    [SPECIES_NATU]                           = sAnims_Natu,
    [SPECIES_XATU]                           = sAnims_Xatu,
    [SPECIES_MAREEP]                         = sAnims_Mareep,
    [SPECIES_FLAAFFY]                        = sAnims_Flaaffy,
    [SPECIES_AMPHAROS]                       = sAnims_Ampharos,
    [SPECIES_BELLOSSOM]                      = sAnims_Bellossom,
    [SPECIES_MARILL]                         = sAnims_Marill,
    [SPECIES_AZUMARILL]                      = sAnims_Azumarill,
    [SPECIES_SUDOWOODO]                      = sAnims_Sudowoodo,
    [SPECIES_POLITOED]                       = sAnims_Politoed,
    [SPECIES_HOPPIP]                         = sAnims_Hoppip,
    [SPECIES_SKIPLOOM]                       = sAnims_Skiploom,
    [SPECIES_JUMPLUFF]                       = sAnims_Jumpluff,
    [SPECIES_AIPOM]                          = sAnims_Aipom,
    [SPECIES_SUNKERN]                        = sAnims_Sunkern,
    [SPECIES_SUNFLORA]                       = sAnims_Sunflora,
    [SPECIES_YANMA]                          = sAnims_Yanma,
    [SPECIES_WOOPER]                         = sAnims_Wooper,
    [SPECIES_WOOPER_PALDEAN]                 = sAnims_WooperPaldean,
    [SPECIES_QUAGSIRE]                       = sAnims_Quagsire,
    [SPECIES_ESPEON]                         = sAnims_Espeon,
    [SPECIES_UMBREON]                        = sAnims_Umbreon,
    [SPECIES_MURKROW]                        = sAnims_Murkrow,
    [SPECIES_SLOWKING]                       = sAnims_Slowking,
    [SPECIES_MISDREAVUS]                     = sAnims_Misdreavus,
    [SPECIES_UNOWN]                          = sAnims_Unown,
    [SPECIES_WOBBUFFET]                      = sAnims_Wobbuffet,
    [SPECIES_GIRAFARIG]                      = sAnims_Girafarig,
    [SPECIES_PINECO]                         = sAnims_Pineco,
    [SPECIES_FORRETRESS]                     = sAnims_Forretress,
    [SPECIES_DUNSPARCE]                      = sAnims_Dunsparce,
    [SPECIES_GLIGAR]                         = sAnims_Gligar,
    [SPECIES_STEELIX]                        = sAnims_Steelix,
    [SPECIES_SNUBBULL]                       = sAnims_Snubbull,
    [SPECIES_GRANBULL]                       = sAnims_Granbull,
    [SPECIES_QWILFISH]                       = sAnims_Qwilfish,
    [SPECIES_SCIZOR]                         = sAnims_Scizor,
    [SPECIES_SHUCKLE]                        = sAnims_Shuckle,
    [SPECIES_HERACROSS]                      = sAnims_Heracross,
    [SPECIES_SNEASEL]                        = sAnims_Sneasel,
    [SPECIES_TEDDIURSA]                      = sAnims_Teddiursa,
    [SPECIES_URSARING]                       = sAnims_Ursaring,
    [SPECIES_SLUGMA]                         = sAnims_Slugma,
    [SPECIES_MAGCARGO]                       = sAnims_Magcargo,
    [SPECIES_SWINUB]                         = sAnims_Swinub,
    [SPECIES_PILOSWINE]                      = sAnims_Piloswine,
    [SPECIES_CORSOLA]                        = sAnims_Corsola,
    [SPECIES_REMORAID]                       = sAnims_Remoraid,
    [SPECIES_OCTILLERY]                      = sAnims_Octillery,
    [SPECIES_DELIBIRD]                       = sAnims_Delibird,
    [SPECIES_MANTINE]                        = sAnims_Mantine,
    [SPECIES_SKARMORY]                       = sAnims_Skarmory,
    [SPECIES_HOUNDOUR]                       = sAnims_Houndour,
    [SPECIES_HOUNDOOM]                       = sAnims_Houndoom,
    [SPECIES_KINGDRA]                        = sAnims_Kingdra,
    [SPECIES_PHANPY]                         = sAnims_Phanpy,
    [SPECIES_DONPHAN]                        = sAnims_Donphan,
    [SPECIES_PORYGON2]                       = sAnims_Porygon2,
    [SPECIES_STANTLER]                       = sAnims_Stantler,
    [SPECIES_SMEARGLE]                       = sAnims_Smeargle,
    [SPECIES_TYROGUE]                        = sAnims_Tyrogue,
    [SPECIES_HITMONTOP]                      = sAnims_Hitmontop,
    [SPECIES_SMOOCHUM]                       = sAnims_Smoochum,
    [SPECIES_ELEKID]                         = sAnims_Elekid,
    [SPECIES_MAGBY]                          = sAnims_Magby,
    [SPECIES_MILTANK]                        = sAnims_Miltank,
    [SPECIES_BLISSEY]                        = sAnims_Blissey,
    [SPECIES_RAIKOU]                         = sAnims_Raikou,
    [SPECIES_ENTEI]                          = sAnims_Entei,
    [SPECIES_SUICUNE]                        = sAnims_Suicune,
    [SPECIES_LARVITAR]                       = sAnims_Larvitar,
    [SPECIES_PUPITAR]                        = sAnims_Pupitar,
    [SPECIES_TYRANITAR]                      = sAnims_Tyranitar,
    [SPECIES_LUGIA]                          = sAnims_Lugia,
    [SPECIES_HO_OH]                          = sAnims_HoOh,
    [SPECIES_CELEBI]                         = sAnims_Celebi,
    // Gen 3
    [SPECIES_TREECKO]                        = sAnims_Treecko,
    [SPECIES_GROVYLE]                        = sAnims_Grovyle,
    [SPECIES_SCEPTILE]                       = sAnims_Sceptile,
    [SPECIES_TORCHIC]                        = sAnims_Torchic,
    [SPECIES_COMBUSKEN]                      = sAnims_Combusken,
    [SPECIES_BLAZIKEN]                       = sAnims_Blaziken,
    [SPECIES_MUDKIP]                         = sAnims_Mudkip,
    [SPECIES_MARSHTOMP]                      = sAnims_Marshtomp,
    [SPECIES_SWAMPERT]                       = sAnims_Swampert,
    [SPECIES_POOCHYENA]                      = sAnims_Poochyena,
    [SPECIES_MIGHTYENA]                      = sAnims_Mightyena,
    [SPECIES_ZIGZAGOON]                      = sAnims_Zigzagoon,
    [SPECIES_LINOONE]                        = sAnims_Linoone,
    [SPECIES_WURMPLE]                        = sAnims_Wurmple,
    [SPECIES_SILCOON]                        = sAnims_Silcoon,
    [SPECIES_BEAUTIFLY]                      = sAnims_Beautifly,
    [SPECIES_CASCOON]                        = sAnims_Cascoon,
    [SPECIES_DUSTOX]                         = sAnims_Dustox,
    [SPECIES_LOTAD]                          = sAnims_Lotad,
    [SPECIES_LOMBRE]                         = sAnims_Lombre,
    [SPECIES_LUDICOLO]                       = sAnims_Ludicolo,
    [SPECIES_SEEDOT]                         = sAnims_Seedot,
    [SPECIES_NUZLEAF]                        = sAnims_Nuzleaf,
    [SPECIES_SHIFTRY]                        = sAnims_Shiftry,
    [SPECIES_NINCADA]                        = sAnims_Nincada,
    [SPECIES_NINJASK]                        = sAnims_Ninjask,
    [SPECIES_SHEDINJA]                       = sAnims_Shedinja,
    [SPECIES_TAILLOW]                        = sAnims_Taillow,
    [SPECIES_SWELLOW]                        = sAnims_Swellow,
    [SPECIES_SHROOMISH]                      = sAnims_Shroomish,
    [SPECIES_BRELOOM]                        = sAnims_Breloom,
    [SPECIES_SPINDA]                         = sAnims_Spinda,
    [SPECIES_WINGULL]                        = sAnims_Wingull,
    [SPECIES_PELIPPER]                       = sAnims_Pelipper,
    [SPECIES_SURSKIT]                        = sAnims_Surskit,
    [SPECIES_MASQUERAIN]                     = sAnims_Masquerain,
    [SPECIES_WAILMER]                        = sAnims_Wailmer,
    [SPECIES_WAILORD]                        = sAnims_Wailord,
    [SPECIES_SKITTY]                         = sAnims_Skitty,
    [SPECIES_DELCATTY]                       = sAnims_Delcatty,
    [SPECIES_KECLEON]                        = sAnims_Kecleon,
    [SPECIES_BALTOY]                         = sAnims_Baltoy,
    [SPECIES_CLAYDOL]                        = sAnims_Claydol,
    [SPECIES_NOSEPASS]                       = sAnims_Nosepass,
    [SPECIES_TORKOAL]                        = sAnims_Torkoal,
    [SPECIES_SABLEYE]                        = sAnims_Sableye,
    [SPECIES_BARBOACH]                       = sAnims_Barboach,
    [SPECIES_WHISCASH]                       = sAnims_Whiscash,
    [SPECIES_LUVDISC]                        = sAnims_Luvdisc,
    [SPECIES_CORPHISH]                       = sAnims_Corphish,
    [SPECIES_CRAWDAUNT]                      = sAnims_Crawdaunt,
    [SPECIES_FEEBAS]                         = sAnims_Feebas,
    [SPECIES_MILOTIC]                        = sAnims_Milotic,
    [SPECIES_CARVANHA]                       = sAnims_Carvanha,
    [SPECIES_SHARPEDO]                       = sAnims_Sharpedo,
    [SPECIES_TRAPINCH]                       = sAnims_Trapinch,
    [SPECIES_VIBRAVA]                        = sAnims_Vibrava,
    [SPECIES_FLYGON]                         = sAnims_Flygon,
    [SPECIES_MAKUHITA]                       = sAnims_Makuhita,
    [SPECIES_HARIYAMA]                       = sAnims_Hariyama,
    [SPECIES_ELECTRIKE]                      = sAnims_Electrike,
    [SPECIES_MANECTRIC]                      = sAnims_Manectric,
    [SPECIES_NUMEL]                          = sAnims_Numel,
    [SPECIES_CAMERUPT]                       = sAnims_Camerupt,
    [SPECIES_SPHEAL]                         = sAnims_Spheal,
    [SPECIES_SEALEO]                         = sAnims_Sealeo,
    [SPECIES_WALREIN]                        = sAnims_Walrein,
    [SPECIES_CACNEA]                         = sAnims_Cacnea,
    [SPECIES_CACTURNE]                       = sAnims_Cacturne,
    [SPECIES_SNORUNT]                        = sAnims_Snorunt,
    [SPECIES_GLALIE]                         = sAnims_Glalie,
    [SPECIES_LUNATONE]                       = sAnims_Lunatone,
    [SPECIES_SOLROCK]                        = sAnims_Solrock,
    [SPECIES_AZURILL]                        = sAnims_Azurill,
    [SPECIES_SPOINK]                         = sAnims_Spoink,
    [SPECIES_GRUMPIG]                        = sAnims_Grumpig,
    [SPECIES_PLUSLE]                         = sAnims_Plusle,
    [SPECIES_MINUN]                          = sAnims_Minun,
    [SPECIES_MAWILE]                         = sAnims_Mawile,
    [SPECIES_MEDITITE]                       = sAnims_Meditite,
    [SPECIES_MEDICHAM]                       = sAnims_Medicham,
    [SPECIES_SWABLU]                         = sAnims_Swablu,
    [SPECIES_ALTARIA]                        = sAnims_Altaria,
    [SPECIES_WYNAUT]                         = sAnims_Wynaut,
    [SPECIES_DUSKULL]                        = sAnims_Duskull,
    [SPECIES_DUSCLOPS]                       = sAnims_Dusclops,
    [SPECIES_ROSELIA]                        = sAnims_Roselia,
    [SPECIES_SLAKOTH]                        = sAnims_Slakoth,
    [SPECIES_VIGOROTH]                       = sAnims_Vigoroth,
    [SPECIES_SLAKING]                        = sAnims_Slaking,
    [SPECIES_GULPIN]                         = sAnims_Gulpin,
    [SPECIES_SWALOT]                         = sAnims_Swalot,
    [SPECIES_TROPIUS]                        = sAnims_Tropius,
    [SPECIES_WHISMUR]                        = sAnims_Whismur,
    [SPECIES_LOUDRED]                        = sAnims_Loudred,
    [SPECIES_EXPLOUD]                        = sAnims_Exploud,
    [SPECIES_CLAMPERL]                       = sAnims_Clamperl,
    [SPECIES_HUNTAIL]                        = sAnims_Huntail,
    [SPECIES_GOREBYSS]                       = sAnims_Gorebyss,
    [SPECIES_ABSOL]                          = sAnims_Absol,
    [SPECIES_SHUPPET]                        = sAnims_Shuppet,
    [SPECIES_BANETTE]                        = sAnims_Banette,
    [SPECIES_SEVIPER]                        = sAnims_Seviper,
    [SPECIES_ZANGOOSE]                       = sAnims_Zangoose,
    [SPECIES_RELICANTH]                      = sAnims_Relicanth,
    [SPECIES_ARON]                           = sAnims_Aron,
    [SPECIES_LAIRON]                         = sAnims_Lairon,
    [SPECIES_AGGRON]                         = sAnims_Aggron,
    [SPECIES_CASTFORM_NORMAL]                = sAnims_CastformNormal,
    [SPECIES_VOLBEAT]                        = sAnims_Volbeat,
    [SPECIES_ILLUMISE]                       = sAnims_Illumise,
    [SPECIES_LILEEP]                         = sAnims_Lileep,
    [SPECIES_CRADILY]                        = sAnims_Cradily,
    [SPECIES_ANORITH]                        = sAnims_Anorith,
    [SPECIES_ARMALDO]                        = sAnims_Armaldo,
    [SPECIES_RALTS]                          = sAnims_Ralts,
    [SPECIES_KIRLIA]                         = sAnims_Kirlia,
    [SPECIES_GARDEVOIR]                      = sAnims_Gardevoir,
    [SPECIES_BAGON]                          = sAnims_Bagon,
    [SPECIES_SHELGON]                        = sAnims_Shelgon,
    [SPECIES_SALAMENCE]                      = sAnims_Salamence,
    [SPECIES_BELDUM]                         = sAnims_Beldum,
    [SPECIES_METANG]                         = sAnims_Metang,
    [SPECIES_METAGROSS]                      = sAnims_Metagross,
    [SPECIES_REGIROCK]                       = sAnims_Regirock,
    [SPECIES_REGICE]                         = sAnims_Regice,
    [SPECIES_REGISTEEL]                      = sAnims_Registeel,
    [SPECIES_KYOGRE]                         = sAnims_Kyogre,
    [SPECIES_GROUDON]                        = sAnims_Groudon,
    [SPECIES_RAYQUAZA]                       = sAnims_Rayquaza,
    [SPECIES_LATIAS]                         = sAnims_Latias,
    [SPECIES_LATIOS]                         = sAnims_Latios,
    [SPECIES_JIRACHI]                        = sAnims_Jirachi,
    [SPECIES_DEOXYS_NORMAL]                  = sAnims_DeoxysNormal,
    [SPECIES_CHIMECHO]                       = sAnims_Chimecho,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_TURTWIG]                        = sAnims_Turtwig,
    [SPECIES_GROTLE]                         = sAnims_Grotle,
    [SPECIES_TORTERRA]                       = sAnims_Torterra,
    [SPECIES_CHIMCHAR]                       = sAnims_Chimchar,
    [SPECIES_MONFERNO]                       = sAnims_Monferno,
    [SPECIES_INFERNAPE]                      = sAnims_Infernape,
    [SPECIES_PIPLUP]                         = sAnims_Piplup,
    [SPECIES_PRINPLUP]                       = sAnims_Prinplup,
    [SPECIES_EMPOLEON]                       = sAnims_Empoleon,
    [SPECIES_STARLY]                         = sAnims_Starly,
    [SPECIES_STARAVIA]                       = sAnims_Staravia,
    [SPECIES_STARAPTOR]                      = sAnims_Staraptor,
    [SPECIES_BIDOOF]                         = sAnims_Bidoof,
    [SPECIES_BIBAREL]                        = sAnims_Bibarel,
    [SPECIES_KRICKETOT]                      = sAnims_Kricketot,
    [SPECIES_KRICKETUNE]                     = sAnims_Kricketune,
    [SPECIES_SHINX]                          = sAnims_Shinx,
    [SPECIES_LUXIO]                          = sAnims_Luxio,
    [SPECIES_LUXRAY]                         = sAnims_Luxray,
    [SPECIES_BUDEW]                          = sAnims_Budew,
    [SPECIES_ROSERADE]                       = sAnims_Roserade,
    [SPECIES_CRANIDOS]                       = sAnims_Cranidos,
    [SPECIES_RAMPARDOS]                      = sAnims_Rampardos,
    [SPECIES_SHIELDON]                       = sAnims_Shieldon,
    [SPECIES_BASTIODON]                      = sAnims_Bastiodon,
    [SPECIES_BURMY_PLANT_CLOAK]              = sAnims_Burmy,
    [SPECIES_WORMADAM_PLANT_CLOAK]           = sAnims_Wormadam,
    [SPECIES_MOTHIM]                         = sAnims_Mothim,
    [SPECIES_COMBEE]                         = sAnims_Combee,
    [SPECIES_VESPIQUEN]                      = sAnims_Vespiquen,
    [SPECIES_PACHIRISU]                      = sAnims_Pachirisu,
    [SPECIES_BUIZEL]                         = sAnims_Buizel,
    [SPECIES_FLOATZEL]                       = sAnims_Floatzel,
    [SPECIES_CHERUBI]                        = sAnims_Cherubi,
    [SPECIES_CHERRIM_OVERCAST]               = sAnims_CherrimOvercast,
    [SPECIES_SHELLOS_WEST_SEA]               = sAnims_Shellos,
    [SPECIES_GASTRODON_WEST_SEA]             = sAnims_Gastrodon,
    [SPECIES_AMBIPOM]                        = sAnims_Ambipom,
    [SPECIES_DRIFLOON]                       = sAnims_Drifloon,
    [SPECIES_DRIFBLIM]                       = sAnims_Drifblim,
    [SPECIES_BUNEARY]                        = sAnims_Buneary,
    [SPECIES_LOPUNNY]                        = sAnims_Lopunny,
    [SPECIES_MISMAGIUS]                      = sAnims_Mismagius,
    [SPECIES_HONCHKROW]                      = sAnims_Honchkrow,
    [SPECIES_GLAMEOW]                        = sAnims_Glameow,
    [SPECIES_PURUGLY]                        = sAnims_Purugly,
    [SPECIES_CHINGLING]                      = sAnims_Chingling,
    [SPECIES_STUNKY]                         = sAnims_Stunky,
    [SPECIES_SKUNTANK]                       = sAnims_Skuntank,
    [SPECIES_BRONZOR]                        = sAnims_Bronzor,
    [SPECIES_BRONZONG]                       = sAnims_Bronzong,
    [SPECIES_BONSLY]                         = sAnims_Bonsly,
    [SPECIES_MIME_JR]                        = sAnims_MimeJr,
    [SPECIES_HAPPINY]                        = sAnims_Happiny,
    [SPECIES_CHATOT]                         = sAnims_Chatot,
    [SPECIES_SPIRITOMB]                      = sAnims_Spiritomb,
    [SPECIES_GIBLE]                          = sAnims_Gible,
    [SPECIES_GABITE]                         = sAnims_Gabite,
    [SPECIES_GARCHOMP]                       = sAnims_Garchomp,
    [SPECIES_MUNCHLAX]                       = sAnims_Munchlax,
    [SPECIES_RIOLU]                          = sAnims_Riolu,
    [SPECIES_LUCARIO]                        = sAnims_Lucario,
    [SPECIES_HIPPOPOTAS]                     = sAnims_Hippopotas,
    [SPECIES_HIPPOWDON]                      = sAnims_Hippowdon,
    [SPECIES_SKORUPI]                        = sAnims_Skorupi,
    [SPECIES_DRAPION]                        = sAnims_Drapion,
    [SPECIES_CROAGUNK]                       = sAnims_Croagunk,
    [SPECIES_TOXICROAK]                      = sAnims_Toxicroak,
    [SPECIES_CARNIVINE]                      = sAnims_Carnivine,
    [SPECIES_FINNEON]                        = sAnims_Finneon,
    [SPECIES_LUMINEON]                       = sAnims_Lumineon,
    [SPECIES_MANTYKE]                        = sAnims_Mantyke,
    [SPECIES_SNOVER]                         = sAnims_Snover,
    [SPECIES_ABOMASNOW]                      = sAnims_Abomasnow,
    [SPECIES_WEAVILE]                        = sAnims_Weavile,
    [SPECIES_MAGNEZONE]                      = sAnims_Magnezone,
    [SPECIES_LICKILICKY]                     = sAnims_Lickilicky,
    [SPECIES_RHYPERIOR]                      = sAnims_Rhyperior,
    [SPECIES_TANGROWTH]                      = sAnims_Tangrowth,
    [SPECIES_ELECTIVIRE]                     = sAnims_Electivire,
    [SPECIES_MAGMORTAR]                      = sAnims_Magmortar,
    [SPECIES_TOGEKISS]                       = sAnims_Togekiss,
    [SPECIES_YANMEGA]                        = sAnims_Yanmega,
    [SPECIES_LEAFEON]                        = sAnims_Leafeon,
    [SPECIES_GLACEON]                        = sAnims_Glaceon,
    [SPECIES_GLISCOR]                        = sAnims_Gliscor,
    [SPECIES_MAMOSWINE]                      = sAnims_Mamoswine,
    [SPECIES_PORYGON_Z]                      = sAnims_PORYGON_Z,
    [SPECIES_GALLADE]                        = sAnims_Gallade,
    [SPECIES_PROBOPASS]                      = sAnims_Probopass,
    [SPECIES_DUSKNOIR]                       = sAnims_Dusknoir,
    [SPECIES_FROSLASS]                       = sAnims_Froslass,
    [SPECIES_ROTOM]                          = sAnims_Rotom,
    [SPECIES_UXIE]                           = sAnims_Uxie,
    [SPECIES_MESPRIT]                        = sAnims_Mesprit,
    [SPECIES_AZELF]                          = sAnims_Azelf,
    [SPECIES_DIALGA]                         = sAnims_Dialga,
    [SPECIES_PALKIA]                         = sAnims_Palkia,
    [SPECIES_HEATRAN]                        = sAnims_Heatran,
    [SPECIES_REGIGIGAS]                      = sAnims_Regigigas,
    [SPECIES_GIRATINA_ALTERED]               = sAnims_GiratinaAltered,
    [SPECIES_CRESSELIA]                      = sAnims_Cresselia,
    [SPECIES_PHIONE]                         = sAnims_Phione,
    [SPECIES_MANAPHY]                        = sAnims_Manaphy,
    [SPECIES_DARKRAI]                        = sAnims_Darkrai,
    [SPECIES_SHAYMIN_LAND]                   = sAnims_ShayminLand,
    [SPECIES_ARCEUS_NORMAL]                  = sAnims_Arceus,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_VICTINI]                        = sAnims_Victini,
    [SPECIES_SNIVY]                          = sAnims_Snivy,
    [SPECIES_SERVINE]                        = sAnims_Servine,
    [SPECIES_SERPERIOR]                      = sAnims_Serperior,
    [SPECIES_TEPIG]                          = sAnims_Tepig,
    [SPECIES_PIGNITE]                        = sAnims_Pignite,
    [SPECIES_EMBOAR]                         = sAnims_Emboar,
    [SPECIES_OSHAWOTT]                       = sAnims_Oshawott,
    [SPECIES_DEWOTT]                         = sAnims_Dewott,
    [SPECIES_SAMUROTT]                       = sAnims_Samurott,
    [SPECIES_PATRAT]                         = sAnims_Patrat,
    [SPECIES_WATCHOG]                        = sAnims_Watchog,
    [SPECIES_LILLIPUP]                       = sAnims_Lillipup,
    [SPECIES_HERDIER]                        = sAnims_Herdier,
    [SPECIES_STOUTLAND]                      = sAnims_Stoutland,
    [SPECIES_PURRLOIN]                       = sAnims_Purrloin,
    [SPECIES_LIEPARD]                        = sAnims_Liepard,
    [SPECIES_PANSAGE]                        = sAnims_Pansage,
    [SPECIES_SIMISAGE]                       = sAnims_Simisage,
    [SPECIES_PANSEAR]                        = sAnims_Pansear,
    [SPECIES_SIMISEAR]                       = sAnims_Simisear,
    [SPECIES_PANPOUR]                        = sAnims_Panpour,
    [SPECIES_SIMIPOUR]                       = sAnims_Simipour,
    [SPECIES_MUNNA]                          = sAnims_Munna,
    [SPECIES_MUSHARNA]                       = sAnims_Musharna,
    [SPECIES_PIDOVE]                         = sAnims_Pidove,
    [SPECIES_TRANQUILL]                      = sAnims_Tranquill,
    [SPECIES_UNFEZANT]                       = sAnims_Unfezant,
    [SPECIES_BLITZLE]                        = sAnims_Blitzle,
    [SPECIES_ZEBSTRIKA]                      = sAnims_Zebstrika,
    [SPECIES_ROGGENROLA]                     = sAnims_Roggenrola,
    [SPECIES_BOLDORE]                        = sAnims_Boldore,
    [SPECIES_GIGALITH]                       = sAnims_Gigalith,
    [SPECIES_WOOBAT]                         = sAnims_Woobat,
    [SPECIES_SWOOBAT]                        = sAnims_Swoobat,
    [SPECIES_DRILBUR]                        = sAnims_Drilbur,
    [SPECIES_EXCADRILL]                      = sAnims_Excadrill,
    [SPECIES_AUDINO]                         = sAnims_Audino,
    [SPECIES_TIMBURR]                        = sAnims_Timburr,
    [SPECIES_GURDURR]                        = sAnims_Gurdurr,
    [SPECIES_CONKELDURR]                     = sAnims_Conkeldurr,
    [SPECIES_TYMPOLE]                        = sAnims_Tympole,
    [SPECIES_PALPITOAD]                      = sAnims_Palpitoad,
    [SPECIES_SEISMITOAD]                     = sAnims_Seismitoad,
    [SPECIES_THROH]                          = sAnims_Throh,
    [SPECIES_SAWK]                           = sAnims_Sawk,
    [SPECIES_SEWADDLE]                       = sAnims_Sewaddle,
    [SPECIES_SWADLOON]                       = sAnims_Swadloon,
    [SPECIES_LEAVANNY]                       = sAnims_Leavanny,
    [SPECIES_VENIPEDE]                       = sAnims_Venipede,
    [SPECIES_WHIRLIPEDE]                     = sAnims_Whirlipede,
    [SPECIES_SCOLIPEDE]                      = sAnims_Scolipede,
    [SPECIES_COTTONEE]                       = sAnims_Cottonee,
    [SPECIES_WHIMSICOTT]                     = sAnims_Whimsicott,
    [SPECIES_PETILIL]                        = sAnims_Petilil,
    [SPECIES_LILLIGANT]                      = sAnims_Lilligant,
    [SPECIES_BASCULIN_RED_STRIPED]           = sAnims_Basculin,
    [SPECIES_SANDILE]                        = sAnims_Sandile,
    [SPECIES_KROKOROK]                       = sAnims_Krokorok,
    [SPECIES_KROOKODILE]                     = sAnims_Krookodile,
    [SPECIES_DARUMAKA]                       = sAnims_Darumaka,
    [SPECIES_DARMANITAN_STANDARD_MODE]       = sAnims_DarmanitanStandardMode,
    [SPECIES_MARACTUS]                       = sAnims_Maractus,
    [SPECIES_DWEBBLE]                        = sAnims_Dwebble,
    [SPECIES_CRUSTLE]                        = sAnims_Crustle,
    [SPECIES_SCRAGGY]                        = sAnims_Scraggy,
    [SPECIES_SCRAFTY]                        = sAnims_Scrafty,
    [SPECIES_SIGILYPH]                       = sAnims_Sigilyph,
    [SPECIES_YAMASK]                         = sAnims_Yamask,
    [SPECIES_COFAGRIGUS]                     = sAnims_Cofagrigus,
    [SPECIES_TIRTOUGA]                       = sAnims_Tirtouga,
    [SPECIES_CARRACOSTA]                     = sAnims_Carracosta,
    [SPECIES_ARCHEN]                         = sAnims_Archen,
    [SPECIES_ARCHEOPS]                       = sAnims_Archeops,
    [SPECIES_TRUBBISH]                       = sAnims_Trubbish,
    [SPECIES_GARBODOR]                       = sAnims_Garbodor,
    [SPECIES_ZORUA]                          = sAnims_Zorua,
    [SPECIES_ZOROARK]                        = sAnims_Zoroark,
    [SPECIES_MINCCINO]                       = sAnims_Minccino,
    [SPECIES_CINCCINO]                       = sAnims_Cinccino,
    [SPECIES_GOTHITA]                        = sAnims_Gothita,
    [SPECIES_GOTHORITA]                      = sAnims_Gothorita,
    [SPECIES_GOTHITELLE]                     = sAnims_Gothitelle,
    [SPECIES_SOLOSIS]                        = sAnims_Solosis,
    [SPECIES_DUOSION]                        = sAnims_Duosion,
    [SPECIES_REUNICLUS]                      = sAnims_Reuniclus,
    [SPECIES_DUCKLETT]                       = sAnims_Ducklett,
    [SPECIES_SWANNA]                         = sAnims_Swanna,
    [SPECIES_VANILLITE]                      = sAnims_Vanillite,
    [SPECIES_VANILLISH]                      = sAnims_Vanillish,
    [SPECIES_VANILLUXE]                      = sAnims_Vanilluxe,
    [SPECIES_DEERLING_SPRING]                = sAnims_Deerling,
    [SPECIES_SAWSBUCK_SPRING]                = sAnims_Sawsbuck,
    [SPECIES_EMOLGA]                         = sAnims_Emolga,
    [SPECIES_KARRABLAST]                     = sAnims_Karrablast,
    [SPECIES_ESCAVALIER]                     = sAnims_Escavalier,
    [SPECIES_FOONGUS]                        = sAnims_Foongus,
    [SPECIES_AMOONGUSS]                      = sAnims_Amoonguss,
    [SPECIES_FRILLISH]                       = sAnims_Frillish,
    [SPECIES_JELLICENT]                      = sAnims_Jellicent,
    [SPECIES_ALOMOMOLA]                      = sAnims_Alomomola,
    [SPECIES_JOLTIK]                         = sAnims_Joltik,
    [SPECIES_GALVANTULA]                     = sAnims_Galvantula,
    [SPECIES_FERROSEED]                      = sAnims_Ferroseed,
    [SPECIES_FERROTHORN]                     = sAnims_Ferrothorn,
    [SPECIES_KLINK]                          = sAnims_Klink,
    [SPECIES_KLANG]                          = sAnims_Klang,
    [SPECIES_KLINKLANG]                      = sAnims_Klinklang,
    [SPECIES_TYNAMO]                         = sAnims_Tynamo,
    [SPECIES_EELEKTRIK]                      = sAnims_Eelektrik,
    [SPECIES_EELEKTROSS]                     = sAnims_Eelektross,
    [SPECIES_ELGYEM]                         = sAnims_Elgyem,
    [SPECIES_BEHEEYEM]                       = sAnims_Beheeyem,
    [SPECIES_LITWICK]                        = sAnims_Litwick,
    [SPECIES_LAMPENT]                        = sAnims_Lampent,
    [SPECIES_CHANDELURE]                     = sAnims_Chandelure,
    [SPECIES_AXEW]                           = sAnims_Axew,
    [SPECIES_FRAXURE]                        = sAnims_Fraxure,
    [SPECIES_HAXORUS]                        = sAnims_Haxorus,
    [SPECIES_CUBCHOO]                        = sAnims_Cubchoo,
    [SPECIES_BEARTIC]                        = sAnims_Beartic,
    [SPECIES_CRYOGONAL]                      = sAnims_Cryogonal,
    [SPECIES_SHELMET]                        = sAnims_Shelmet,
    [SPECIES_ACCELGOR]                       = sAnims_Accelgor,
    [SPECIES_STUNFISK]                       = sAnims_Stunfisk,
    [SPECIES_MIENFOO]                        = sAnims_Mienfoo,
    [SPECIES_MIENSHAO]                       = sAnims_Mienshao,
    [SPECIES_DRUDDIGON]                      = sAnims_Druddigon,
    [SPECIES_GOLETT]                         = sAnims_Golett,
    [SPECIES_GOLURK]                         = sAnims_Golurk,
    [SPECIES_PAWNIARD]                       = sAnims_Pawniard,
    [SPECIES_BISHARP]                        = sAnims_Bisharp,
    [SPECIES_BOUFFALANT]                     = sAnims_Bouffalant,
    [SPECIES_RUFFLET]                        = sAnims_Rufflet,
    [SPECIES_BRAVIARY]                       = sAnims_Braviary,
    [SPECIES_VULLABY]                        = sAnims_Vullaby,
    [SPECIES_MANDIBUZZ]                      = sAnims_Mandibuzz,
    [SPECIES_HEATMOR]                        = sAnims_Heatmor,
    [SPECIES_DURANT]                         = sAnims_Durant,
    [SPECIES_DEINO]                          = sAnims_Deino,
    [SPECIES_ZWEILOUS]                       = sAnims_Zweilous,
    [SPECIES_HYDREIGON]                      = sAnims_Hydreigon,
    [SPECIES_LARVESTA]                       = sAnims_Larvesta,
    [SPECIES_VOLCARONA]                      = sAnims_Volcarona,
    [SPECIES_COBALION]                       = sAnims_Cobalion,
    [SPECIES_TERRAKION]                      = sAnims_Terrakion,
    [SPECIES_VIRIZION]                       = sAnims_Virizion,
    [SPECIES_TORNADUS_INCARNATE]             = sAnims_TornadusIncarnate,
    [SPECIES_THUNDURUS_INCARNATE]            = sAnims_ThundurusIncarnate,
    [SPECIES_RESHIRAM]                       = sAnims_Reshiram,
    [SPECIES_ZEKROM]                         = sAnims_Zekrom,
    [SPECIES_LANDORUS_INCARNATE]             = sAnims_LandorusIncarnate,
    [SPECIES_KYUREM]                         = sAnims_Kyurem,
    [SPECIES_KELDEO_ORDINARY]                = sAnims_KeldeoOrdinary,
    [SPECIES_MELOETTA_ARIA]                  = sAnims_MeloettaAria,
    [SPECIES_GENESECT]                       = sAnims_Genesect,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_CHESPIN]                        = sAnims_Chespin,
    [SPECIES_QUILLADIN]                      = sAnims_Quilladin,
    [SPECIES_CHESNAUGHT]                     = sAnims_Chesnaught,
    [SPECIES_FENNEKIN]                       = sAnims_Fennekin,
    [SPECIES_BRAIXEN]                        = sAnims_Braixen,
    [SPECIES_DELPHOX]                        = sAnims_Delphox,
    [SPECIES_FROAKIE]                        = sAnims_Froakie,
    [SPECIES_FROGADIER]                      = sAnims_Frogadier,
    [SPECIES_GRENINJA]                       = sAnims_Greninja,
    [SPECIES_BUNNELBY]                       = sAnims_Bunnelby,
    [SPECIES_DIGGERSBY]                      = sAnims_Diggersby,
    [SPECIES_FLETCHLING]                     = sAnims_Fletchling,
    [SPECIES_FLETCHINDER]                    = sAnims_Fletchinder,
    [SPECIES_TALONFLAME]                     = sAnims_Talonflame,
    [SPECIES_SCATTERBUG]                     = sAnims_Scatterbug,
    [SPECIES_SPEWPA]                         = sAnims_Spewpa,
    [SPECIES_VIVILLON_ICY_SNOW]              = sAnims_Vivillon,
    [SPECIES_LITLEO]                         = sAnims_Litleo,
    [SPECIES_PYROAR]                         = sAnims_Pyroar,
    [SPECIES_FLABEBE_RED_FLOWER]             = sAnims_Flabebe,
    [SPECIES_FLOETTE_RED_FLOWER]             = sAnims_Floette,
    [SPECIES_FLORGES_RED_FLOWER]             = sAnims_Florges,
    [SPECIES_SKIDDO]                         = sAnims_Skiddo,
    [SPECIES_GOGOAT]                         = sAnims_Gogoat,
    [SPECIES_PANCHAM]                        = sAnims_Pancham,
    [SPECIES_PANGORO]                        = sAnims_Pangoro,
    [SPECIES_FURFROU_NATURAL]                = sAnims_Furfrou,
    [SPECIES_ESPURR]                         = sAnims_Espurr,
    [SPECIES_MEOWSTIC_MALE]                  = sAnims_Meowstic,
    [SPECIES_HONEDGE]                        = sAnims_Honedge,
    [SPECIES_DOUBLADE]                       = sAnims_Doublade,
    [SPECIES_AEGISLASH_SHIELD]               = sAnims_AegislashShield,
    [SPECIES_SPRITZEE]                       = sAnims_Spritzee,
    [SPECIES_AROMATISSE]                     = sAnims_Aromatisse,
    [SPECIES_SWIRLIX]                        = sAnims_Swirlix,
    [SPECIES_SLURPUFF]                       = sAnims_Slurpuff,
    [SPECIES_INKAY]                          = sAnims_Inkay,
    [SPECIES_MALAMAR]                        = sAnims_Malamar,
    [SPECIES_BINACLE]                        = sAnims_Binacle,
    [SPECIES_BARBARACLE]                     = sAnims_Barbaracle,
    [SPECIES_SKRELP]                         = sAnims_Skrelp,
    [SPECIES_DRAGALGE]                       = sAnims_Dragalge,
    [SPECIES_CLAUNCHER]                      = sAnims_Clauncher,
    [SPECIES_CLAWITZER]                      = sAnims_Clawitzer,
    [SPECIES_HELIOPTILE]                     = sAnims_Helioptile,
    [SPECIES_HELIOLISK]                      = sAnims_Heliolisk,
    [SPECIES_TYRUNT]                         = sAnims_Tyrunt,
    [SPECIES_TYRANTRUM]                      = sAnims_Tyrantrum,
    [SPECIES_AMAURA]                         = sAnims_Amaura,
    [SPECIES_AURORUS]                        = sAnims_Aurorus,
    [SPECIES_SYLVEON]                        = sAnims_Sylveon,
    [SPECIES_HAWLUCHA]                       = sAnims_Hawlucha,
    [SPECIES_DEDENNE]                        = sAnims_Dedenne,
    [SPECIES_CARBINK]                        = sAnims_Carbink,
    [SPECIES_GOOMY]                          = sAnims_Goomy,
    [SPECIES_SLIGGOO]                        = sAnims_Sliggoo,
    [SPECIES_GOODRA]                         = sAnims_Goodra,
    [SPECIES_KLEFKI]                         = sAnims_Klefki,
    [SPECIES_PHANTUMP]                       = sAnims_Phantump,
    [SPECIES_TREVENANT]                      = sAnims_Trevenant,
    [SPECIES_PUMPKABOO_AVERAGE]              = sAnims_Pumpkaboo,
    [SPECIES_GOURGEIST_AVERAGE]              = sAnims_Gourgeist,
    [SPECIES_BERGMITE]                       = sAnims_Bergmite,
    [SPECIES_AVALUGG]                        = sAnims_Avalugg,
    [SPECIES_NOIBAT]                         = sAnims_Noibat,
    [SPECIES_NOIVERN]                        = sAnims_Noivern,
    [SPECIES_XERNEAS_NEUTRAL]                = sAnims_Xerneas,
    [SPECIES_YVELTAL]                        = sAnims_Yveltal,
    [SPECIES_ZYGARDE_50_AURA_BREAK]          = sAnims_Zygarde50,
    [SPECIES_DIANCIE]                        = sAnims_Diancie,
    [SPECIES_HOOPA_CONFINED]                 = sAnims_Hoopa,
    [SPECIES_VOLCANION]                      = sAnims_Volcanion,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ROWLET]                         = sAnims_Rowlet,
    [SPECIES_DARTRIX]                        = sAnims_Dartrix,
    [SPECIES_DECIDUEYE]                      = sAnims_Decidueye,
    [SPECIES_LITTEN]                         = sAnims_Litten,
    [SPECIES_TORRACAT]                       = sAnims_Torracat,
    [SPECIES_INCINEROAR]                     = sAnims_Incineroar,
    [SPECIES_POPPLIO]                        = sAnims_Popplio,
    [SPECIES_BRIONNE]                        = sAnims_Brionne,
    [SPECIES_PRIMARINA]                      = sAnims_Primarina,
    [SPECIES_PIKIPEK]                        = sAnims_Pikipek,
    [SPECIES_TRUMBEAK]                       = sAnims_Trumbeak,
    [SPECIES_TOUCANNON]                      = sAnims_Toucannon,
    [SPECIES_YUNGOOS]                        = sAnims_Yungoos,
    [SPECIES_GUMSHOOS]                       = sAnims_Gumshoos,
    [SPECIES_GRUBBIN]                        = sAnims_Grubbin,
    [SPECIES_CHARJABUG]                      = sAnims_Charjabug,
    [SPECIES_VIKAVOLT]                       = sAnims_Vikavolt,
    [SPECIES_CRABRAWLER]                     = sAnims_Crabrawler,
    [SPECIES_CRABOMINABLE]                   = sAnims_Crabominable,
    [SPECIES_ORICORIO_BAILE]                 = sAnims_Oricorio,
    [SPECIES_CUTIEFLY]                       = sAnims_Cutiefly,
    [SPECIES_RIBOMBEE]                       = sAnims_Ribombee,
    [SPECIES_ROCKRUFF]                       = sAnims_Rockruff,
    [SPECIES_LYCANROC_MIDDAY]                = sAnims_LycanrocMidday,
    [SPECIES_WISHIWASHI_SOLO]                = sAnims_WishiwashiSolo,
    [SPECIES_MAREANIE]                       = sAnims_Mareanie,
    [SPECIES_TOXAPEX]                        = sAnims_Toxapex,
    [SPECIES_MUDBRAY]                        = sAnims_Mudbray,
    [SPECIES_MUDSDALE]                       = sAnims_Mudsdale,
    [SPECIES_DEWPIDER]                       = sAnims_Dewpider,
    [SPECIES_ARAQUANID]                      = sAnims_Araquanid,
    [SPECIES_FOMANTIS]                       = sAnims_Fomantis,
    [SPECIES_LURANTIS]                       = sAnims_Lurantis,
    [SPECIES_MORELULL]                       = sAnims_Morelull,
    [SPECIES_SHIINOTIC]                      = sAnims_Shiinotic,
    [SPECIES_SALANDIT]                       = sAnims_Salandit,
    [SPECIES_SALAZZLE]                       = sAnims_Salazzle,
    [SPECIES_STUFFUL]                        = sAnims_Stufful,
    [SPECIES_BEWEAR]                         = sAnims_Bewear,
    [SPECIES_BOUNSWEET]                      = sAnims_Bounsweet,
    [SPECIES_STEENEE]                        = sAnims_Steenee,
    [SPECIES_TSAREENA]                       = sAnims_Tsareena,
    [SPECIES_COMFEY]                         = sAnims_Comfey,
    [SPECIES_ORANGURU]                       = sAnims_Oranguru,
    [SPECIES_PASSIMIAN]                      = sAnims_Passimian,
    [SPECIES_WIMPOD]                         = sAnims_Wimpod,
    [SPECIES_GOLISOPOD]                      = sAnims_Golisopod,
    [SPECIES_SANDYGAST]                      = sAnims_Sandygast,
    [SPECIES_PALOSSAND]                      = sAnims_Palossand,
    [SPECIES_PYUKUMUKU]                      = sAnims_Pyukumuku,
    [SPECIES_TYPE_NULL]                      = sAnims_TypeNull,
    [SPECIES_SILVALLY_NORMAL]                = sAnims_Silvally,
    [SPECIES_MINIOR_METEOR_RED]              = sAnims_MiniorMeteor,
    [SPECIES_KOMALA]                         = sAnims_Komala,
    [SPECIES_TURTONATOR]                     = sAnims_Turtonator,
    [SPECIES_TOGEDEMARU]                     = sAnims_Togedemaru,
    [SPECIES_MIMIKYU_DISGUISED]              = sAnims_MimikyuDisguised,
    [SPECIES_BRUXISH]                        = sAnims_Bruxish,
    [SPECIES_DRAMPA]                         = sAnims_Drampa,
    [SPECIES_DHELMISE]                       = sAnims_Dhelmise,
    [SPECIES_JANGMO_O]                       = sAnims_JANGMO_O,
    [SPECIES_HAKAMO_O]                       = sAnims_HAKAMO_O,
    [SPECIES_KOMMO_O]                        = sAnims_KOMMO_O,
    [SPECIES_TAPU_KOKO]                      = sAnims_TapuKoko,
    [SPECIES_TAPU_LELE]                      = sAnims_TapuLele,
    [SPECIES_TAPU_BULU]                      = sAnims_TapuBulu,
    [SPECIES_TAPU_FINI]                      = sAnims_TapuFini,
    [SPECIES_COSMOG]                         = sAnims_Cosmog,
    [SPECIES_COSMOEM]                        = sAnims_Cosmoem,
    [SPECIES_SOLGALEO]                       = sAnims_Solgaleo,
    [SPECIES_LUNALA]                         = sAnims_Lunala,
    [SPECIES_NIHILEGO]                       = sAnims_Nihilego,
    [SPECIES_BUZZWOLE]                       = sAnims_Buzzwole,
    [SPECIES_PHEROMOSA]                      = sAnims_Pheromosa,
    [SPECIES_XURKITREE]                      = sAnims_Xurkitree,
    [SPECIES_CELESTEELA]                     = sAnims_Celesteela,
    [SPECIES_KARTANA]                        = sAnims_Kartana,
    [SPECIES_GUZZLORD]                       = sAnims_Guzzlord,
    [SPECIES_NECROZMA]                       = sAnims_Necrozma,
    [SPECIES_MAGEARNA]                       = sAnims_Magearna,
    [SPECIES_MARSHADOW]                      = sAnims_Marshadow,
    [SPECIES_POIPOLE]                        = sAnims_Poipole,
    [SPECIES_NAGANADEL]                      = sAnims_Naganadel,
    [SPECIES_STAKATAKA]                      = sAnims_Stakataka,
    [SPECIES_BLACEPHALON]                    = sAnims_Blacephalon,
    [SPECIES_ZERAORA]                        = sAnims_Zeraora,
    [SPECIES_MELTAN]                         = sAnims_Meltan,
    [SPECIES_MELMETAL]                       = sAnims_Melmetal,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_GROOKEY]                        = sAnims_Grookey,
    [SPECIES_THWACKEY]                       = sAnims_Thwackey,
    [SPECIES_RILLABOOM]                      = sAnims_Rillaboom,
    [SPECIES_SCORBUNNY]                      = sAnims_Scorbunny,
    [SPECIES_RABOOT]                         = sAnims_Raboot,
    [SPECIES_CINDERACE]                      = sAnims_Cinderace,
    [SPECIES_SOBBLE]                         = sAnims_Sobble,
    [SPECIES_DRIZZILE]                       = sAnims_Drizzile,
    [SPECIES_INTELEON]                       = sAnims_Inteleon,
    [SPECIES_SKWOVET]                        = sAnims_Skwovet,
    [SPECIES_GREEDENT]                       = sAnims_Greedent,
    [SPECIES_ROOKIDEE]                       = sAnims_Rookidee,
    [SPECIES_CORVISQUIRE]                    = sAnims_Corvisquire,
    [SPECIES_CORVIKNIGHT]                    = sAnims_Corviknight,
    [SPECIES_BLIPBUG]                        = sAnims_Blipbug,
    [SPECIES_DOTTLER]                        = sAnims_Dottler,
    [SPECIES_ORBEETLE]                       = sAnims_Orbeetle,
    [SPECIES_NICKIT]                         = sAnims_Nickit,
    [SPECIES_THIEVUL]                        = sAnims_Thievul,
    [SPECIES_GOSSIFLEUR]                     = sAnims_Gossifleur,
    [SPECIES_ELDEGOSS]                       = sAnims_Eldegoss,
    [SPECIES_WOOLOO]                         = sAnims_Wooloo,
    [SPECIES_DUBWOOL]                        = sAnims_Dubwool,
    [SPECIES_CHEWTLE]                        = sAnims_Chewtle,
    [SPECIES_DREDNAW]                        = sAnims_Drednaw,
    [SPECIES_YAMPER]                         = sAnims_Yamper,
    [SPECIES_BOLTUND]                        = sAnims_Boltund,
    [SPECIES_ROLYCOLY]                       = sAnims_Rolycoly,
    [SPECIES_CARKOL]                         = sAnims_Carkol,
    [SPECIES_COALOSSAL]                      = sAnims_Coalossal,
    [SPECIES_APPLIN]                         = sAnims_Applin,
    [SPECIES_FLAPPLE]                        = sAnims_Flapple,
    [SPECIES_APPLETUN]                       = sAnims_Appletun,
    [SPECIES_SILICOBRA]                      = sAnims_Silicobra,
    [SPECIES_SANDACONDA]                     = sAnims_Sandaconda,
    [SPECIES_CRAMORANT]                      = sAnims_Cramorant,
    [SPECIES_ARROKUDA]                       = sAnims_Arrokuda,
    [SPECIES_BARRASKEWDA]                    = sAnims_Barraskewda,
    [SPECIES_TOXEL]                          = sAnims_Toxel,
    [SPECIES_TOXTRICITY_AMPED]               = sAnims_Toxtricity,
    [SPECIES_SIZZLIPEDE]                     = sAnims_Sizzlipede,
    [SPECIES_CENTISKORCH]                    = sAnims_Centiskorch,
    [SPECIES_CLOBBOPUS]                      = sAnims_Clobbopus,
    [SPECIES_GRAPPLOCT]                      = sAnims_Grapploct,
    [SPECIES_SINISTEA_PHONY]                 = sAnims_Sinistea,
    [SPECIES_POLTEAGEIST_PHONY]              = sAnims_Polteageist,
    [SPECIES_HATENNA]                        = sAnims_Hatenna,
    [SPECIES_HATTREM]                        = sAnims_Hattrem,
    [SPECIES_HATTERENE]                      = sAnims_Hatterene,
    [SPECIES_IMPIDIMP]                       = sAnims_Impidimp,
    [SPECIES_MORGREM]                        = sAnims_Morgrem,
    [SPECIES_GRIMMSNARL]                     = sAnims_Grimmsnarl,
    [SPECIES_OBSTAGOON]                      = sAnims_Obstagoon,
    [SPECIES_PERRSERKER]                     = sAnims_Perrserker,
    [SPECIES_CURSOLA]                        = sAnims_Cursola,
    [SPECIES_SIRFETCHD]                      = sAnims_Sirfetchd,
    [SPECIES_MR_RIME]                        = sAnims_MrRime,
    [SPECIES_RUNERIGUS]                      = sAnims_Runerigus,
    [SPECIES_MILCERY]                        = sAnims_Milcery,
    [SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM] = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM]    = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM]  = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM]    = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM]   = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM]  = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL]    = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL] = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL] = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_VANILLA_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_RUBY_CREAM]         = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_MATCHA_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_MINT_CREAM]         = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_LEMON_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_SALTED_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_RUBY_SWIRL]         = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_VANILLA_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_RUBY_CREAM]          = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_MATCHA_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_MINT_CREAM]          = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_LEMON_CREAM]         = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_SALTED_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_RUBY_SWIRL]          = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_VANILLA_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_RUBY_CREAM]          = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_MATCHA_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_MINT_CREAM]          = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_LEMON_CREAM]         = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_SALTED_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_RUBY_SWIRL]          = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_RUBY_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_MINT_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_LEMON_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_SALTED_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_RUBY_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_MINT_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_LEMON_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_SALTED_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_RUBY_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_MINT_CREAM]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_LEMON_CREAM]       = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_SALTED_CREAM]      = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL]        = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL]     = sAnims_Alcremie,
    [SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL]     = sAnims_Alcremie,
    [SPECIES_FALINKS]                        = sAnims_Falinks,
    [SPECIES_PINCURCHIN]                     = sAnims_Pincurchin,
    [SPECIES_SNOM]                           = sAnims_Snom,
    [SPECIES_FROSMOTH]                       = sAnims_Frosmoth,
    [SPECIES_STONJOURNER]                    = sAnims_Stonjourner,
    [SPECIES_EISCUE_ICE_FACE]                = sAnims_Eiscue,
    [SPECIES_INDEEDEE_MALE]                  = sAnims_Indeedee,
    [SPECIES_MORPEKO_FULL_BELLY]             = sAnims_Morpeko,
    [SPECIES_CUFANT]                         = sAnims_Cufant,
    [SPECIES_COPPERAJAH]                     = sAnims_Copperajah,
    [SPECIES_DRACOZOLT]                      = sAnims_Dracozolt,
    [SPECIES_ARCTOZOLT]                      = sAnims_Arctozolt,
    [SPECIES_DRACOVISH]                      = sAnims_Dracovish,
    [SPECIES_ARCTOVISH]                      = sAnims_Arctovish,
    [SPECIES_DURALUDON]                      = sAnims_Duraludon,
    [SPECIES_DREEPY]                         = sAnims_Dreepy,
    [SPECIES_DRAKLOAK]                       = sAnims_Drakloak,
    [SPECIES_DRAGAPULT]                      = sAnims_Dragapult,
    [SPECIES_ZACIAN_HERO_OF_MANY_BATTLES]    = sAnims_Zacian,
    [SPECIES_ZAMAZENTA_HERO_OF_MANY_BATTLES] = sAnims_Zamazenta,
    [SPECIES_ETERNATUS]                      = sAnims_Eternatus,
    [SPECIES_KUBFU]                          = sAnims_Kubfu,
    [SPECIES_URSHIFU_SINGLE_STRIKE_STYLE]    = sAnims_Urshifu,
    [SPECIES_ZARUDE]                         = sAnims_Zarude,
    [SPECIES_REGIELEKI]                      = sAnims_Regieleki,
    [SPECIES_REGIDRAGO]                      = sAnims_Regidrago,
    [SPECIES_GLASTRIER]                      = sAnims_Glastrier,
    [SPECIES_SPECTRIER]                      = sAnims_Spectrier,
    [SPECIES_CALYREX]                        = sAnims_Calyrex,
    [SPECIES_WYRDEER]                        = sAnims_Wyrdeer,
    [SPECIES_KLEAVOR]                        = sAnims_Kleavor,
    [SPECIES_URSALUNA]                       = sAnims_Ursaluna,
    [SPECIES_BASCULEGION_MALE]               = sAnims_Basculegion,
    [SPECIES_SNEASLER]                       = sAnims_Sneasler,
    [SPECIES_OVERQWIL]                       = sAnims_Overqwil,
    [SPECIES_ENAMORUS_INCARNATE]             = sAnims_EnamorusIncarnate,
#endif
#if P_GEN_9_POKEMON == TRUE
    [SPECIES_SPRIGATITO]                        = sAnims_Sprigatito,
    [SPECIES_FLORAGATO]                         = sAnims_Floragato,
    [SPECIES_MEOWSCARADA]                       = sAnims_Meowscarada,
    [SPECIES_FUECOCO]                           = sAnims_Fuecoco,
    [SPECIES_CROCALOR]                          = sAnims_Crocalor,
    [SPECIES_SKELEDIRGE]                        = sAnims_Skeledirge,
    [SPECIES_QUAXLY]                            = sAnims_Quaxly,
    [SPECIES_QUAXWELL]                          = sAnims_Quaxwell,
    [SPECIES_QUAQUAVAL]                         = sAnims_Quaquaval,
    [SPECIES_LECHONK]                           = sAnims_Lechonk,
    [SPECIES_OINKOLOGNE_MALE]                   = sAnims_Oinkologne,
    [SPECIES_OINKOLOGNE_FEMALE]                 = sAnims_Oinkologne,
    [SPECIES_TAROUNTULA]                        = sAnims_Tarountula,
    [SPECIES_SPIDOPS]                           = sAnims_Spidops,
    [SPECIES_NYMBLE]                            = sAnims_Nymble,
    [SPECIES_LOKIX]                             = sAnims_Lokix,
    [SPECIES_PAWMI]                             = sAnims_Pawmi,
    [SPECIES_PAWMO]                             = sAnims_Pawmo,
    [SPECIES_PAWMOT]                            = sAnims_Pawmot,
    [SPECIES_TANDEMAUS]                         = sAnims_Tandemaus,
    [SPECIES_MAUSHOLD_FAMILY_OF_THREE]          = sAnims_Maushold,
    [SPECIES_MAUSHOLD_FAMILY_OF_FOUR]           = sAnims_Maushold,
    [SPECIES_FIDOUGH]                           = sAnims_Fidough,
    [SPECIES_DACHSBUN]                          = sAnims_Dachsbun,
    [SPECIES_SMOLIV]                            = sAnims_Smoliv,
    [SPECIES_DOLLIV]                            = sAnims_Dolliv,
    [SPECIES_ARBOLIVA]                          = sAnims_Arboliva,
    [SPECIES_SQUAWKABILLY_GREEN_PLUMAGE]        = sAnims_Squawkabilly,
    [SPECIES_SQUAWKABILLY_BLUE_PLUMAGE]         = sAnims_Squawkabilly,
    [SPECIES_SQUAWKABILLY_YELLOW_PLUMAGE]       = sAnims_Squawkabilly,
    [SPECIES_SQUAWKABILLY_WHITE_PLUMAGE]        = sAnims_Squawkabilly,
    [SPECIES_NACLI]                             = sAnims_Nacli,
    [SPECIES_NACLSTACK]                         = sAnims_Naclstack,
    [SPECIES_GARGANACL]                         = sAnims_Garganacl,
    [SPECIES_CHARCADET]                         = sAnims_Charcadet,
    [SPECIES_ARMAROUGE]                         = sAnims_Armarouge,
    [SPECIES_CERULEDGE]                         = sAnims_Ceruledge,
    [SPECIES_TADBULB]                           = sAnims_Tadbulb,
    [SPECIES_BELLIBOLT]                         = sAnims_Bellibolt,
    [SPECIES_WATTREL]                           = sAnims_Wattrel,
    [SPECIES_KILOWATTREL]                       = sAnims_Kilowattrel,
    [SPECIES_MASCHIFF]                          = sAnims_Maschiff,
    [SPECIES_MABOSSTIFF]                        = sAnims_Mabosstiff,
    [SPECIES_SHROODLE]                          = sAnims_Shroodle,
    [SPECIES_GRAFAIAI]                          = sAnims_Grafaiai,
    [SPECIES_BRAMBLIN]                          = sAnims_Bramblin,
    [SPECIES_BRAMBLEGHAST]                      = sAnims_Brambleghast,
    [SPECIES_TOEDSCOOL]                         = sAnims_Toedscool,
    [SPECIES_TOEDSCRUEL]                        = sAnims_Toedscruel,
    [SPECIES_KLAWF]                             = sAnims_Klawf,
    [SPECIES_CAPSAKID]                          = sAnims_Capsakid,
    [SPECIES_SCOVILLAIN]                        = sAnims_Scovillain,
    [SPECIES_RELLOR]                            = sAnims_Rellor,
    [SPECIES_RABSCA]                            = sAnims_Rabsca,
    [SPECIES_FLITTLE]                           = sAnims_Flittle,
    [SPECIES_ESPATHRA]                          = sAnims_Espathra,
    [SPECIES_TINKATINK]                         = sAnims_Tinkatink,
    [SPECIES_TINKATUFF]                         = sAnims_Tinkatuff,
    [SPECIES_TINKATON]                          = sAnims_Tinkaton,
    [SPECIES_WIGLETT]                           = sAnims_Wiglett,
    [SPECIES_WUGTRIO]                           = sAnims_Wugtrio,
    [SPECIES_BOMBIRDIER]                        = sAnims_Bombirdier,
    [SPECIES_FINIZEN]                           = sAnims_Finizen,
    [SPECIES_PALAFIN_ZERO]                      = sAnims_Palafin,
    [SPECIES_PALAFIN_HERO]                      = sAnims_Palafin,
    [SPECIES_VAROOM]                            = sAnims_Varoom,
    [SPECIES_REVAVROOM]                         = sAnims_Revavroom,
    [SPECIES_CYCLIZAR]                          = sAnims_Cyclizar,
    [SPECIES_ORTHWORM]                          = sAnims_Orthworm,
    [SPECIES_GLIMMET]                           = sAnims_Glimmet,
    [SPECIES_GLIMMORA]                          = sAnims_Glimmora,
    [SPECIES_GREAVARD]                          = sAnims_Greavard,
    [SPECIES_HOUNDSTONE]                        = sAnims_Houndstone,
    [SPECIES_FLAMIGO]                           = sAnims_Flamigo,
    [SPECIES_CETODDLE]                          = sAnims_Cetoddle,
    [SPECIES_CETITAN]                           = sAnims_Cetitan,
    [SPECIES_VELUZA]                            = sAnims_Veluza,
    [SPECIES_DONDOZO]                           = sAnims_Dondozo,
    [SPECIES_TATSUGIRI_CURLY]                   = sAnims_Tatsugiri,
    [SPECIES_TATSUGIRI_DROOPY]                  = sAnims_Tatsugiri,
    [SPECIES_TATSUGIRI_STRETCHY]                = sAnims_Tatsugiri,
    [SPECIES_ANNIHILAPE]                        = sAnims_Annihilape,
    [SPECIES_CLODSIRE]                          = sAnims_Clodsire,
    [SPECIES_FARIGIRAF]                         = sAnims_Farigiraf,
    [SPECIES_DUDUNSPARCE_TWO_SEGMENT]           = sAnims_Dudunsparce,
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT]         = sAnims_Dudunsparce,
    [SPECIES_KINGAMBIT]                         = sAnims_Kingambit,
    [SPECIES_GREAT_TUSK]                        = sAnims_GreatTusk,
    [SPECIES_SCREAM_TAIL]                       = sAnims_ScreamTail,
    [SPECIES_BRUTE_BONNET]                      = sAnims_BruteBonnet,
    [SPECIES_FLUTTER_MANE]                      = sAnims_FlutterMane,
    [SPECIES_SLITHER_WING]                      = sAnims_SlitherWing,
    [SPECIES_SANDY_SHOCKS]                      = sAnims_SandyShocks,
    [SPECIES_IRON_TREADS]                       = sAnims_IronTreads,
    [SPECIES_IRON_BUNDLE]                       = sAnims_IronBundle,
    [SPECIES_IRON_HANDS]                        = sAnims_IronHands,
    [SPECIES_IRON_JUGULIS]                      = sAnims_IronJugulis,
    [SPECIES_IRON_MOTH]                         = sAnims_IronMoth,
    [SPECIES_IRON_THORNS]                       = sAnims_IronThorns,
    [SPECIES_FRIGIBAX]                          = sAnims_Frigibax,
    [SPECIES_ARCTIBAX]                          = sAnims_Arctibax,
    [SPECIES_BAXCALIBUR]                        = sAnims_Baxcalibur,
    [SPECIES_GIMMIGHOUL_CHEST]                  = sAnims_Gimmighoul,
    [SPECIES_GIMMIGHOUL_ROAMING]                = sAnims_Gimmighoul,
    [SPECIES_GHOLDENGO]                         = sAnims_Gholdengo,
    [SPECIES_WO_CHIEN]                          = sAnims_WoChien,
    [SPECIES_CHIEN_PAO]                         = sAnims_ChienPao,
    [SPECIES_TING_LU]                           = sAnims_TingLu,
    [SPECIES_CHI_YU]                            = sAnims_ChiYu,
    [SPECIES_ROARING_MOON]                      = sAnims_RoaringMoon,
    [SPECIES_IRON_VALIANT]                      = sAnims_IronValiant,
    [SPECIES_KORAIDON]                          = sAnims_Koraidon,
    [SPECIES_MIRAIDON]                          = sAnims_Miraidon,
    [SPECIES_WALKING_WAKE]                      = sAnims_WalkingWake,
    [SPECIES_IRON_LEAVES]                       = sAnims_IronLeaves,
    [SPECIES_DIPPLIN]                           = sAnims_Dipplin,
    [SPECIES_POLTCHAGEIST_COUNTERFEIT]          = sAnims_Poltchageist,
    [SPECIES_POLTCHAGEIST_ARTISAN]              = sAnims_Poltchageist,
    [SPECIES_SINISTCHA_UNREMARKABLE]            = sAnims_Sinistcha,
    [SPECIES_SINISTCHA_MASTERPIECE]             = sAnims_Sinistcha,
    [SPECIES_OKIDOGI]                           = sAnims_Okidogi,
    [SPECIES_MUNKIDORI]                         = sAnims_Munkidori,
    [SPECIES_FEZANDIPITI]                       = sAnims_Fezandipiti,
    [SPECIES_OGERPON_TEAL_MASK]                      = sAnims_Ogerpon,
    [SPECIES_OGERPON_WELLSPRING_MASK]                = sAnims_Ogerpon,
    [SPECIES_OGERPON_HEARTHFLAME_MASK]               = sAnims_Ogerpon,
    [SPECIES_OGERPON_CORNERSTONE_MASK]               = sAnims_Ogerpon,
    [SPECIES_OGERPON_TEAL_MASK_TERA]                 = sAnims_Ogerpon,
    [SPECIES_OGERPON_WELLSPRING_MASK_TERA]           = sAnims_Ogerpon,
    [SPECIES_OGERPON_HEARTHFLAME_MASK_TERA]          = sAnims_Ogerpon,
    [SPECIES_OGERPON_CORNERSTONE_MASK_TERA]          = sAnims_Ogerpon,
#endif
    // Mega/Primal Forms
    [SPECIES_VENUSAUR_MEGA]                  = sAnims_VenusaurMega,
    [SPECIES_CHARIZARD_MEGA_X]               = sAnims_CHARIZARD_MEGA_X,
    [SPECIES_CHARIZARD_MEGA_Y]               = sAnims_CHARIZARD_MEGA_Y,
    [SPECIES_BLASTOISE_MEGA]                 = sAnims_BlastoiseMega,
    [SPECIES_BEEDRILL_MEGA]                  = sAnims_BeedrillMega,
    [SPECIES_PIDGEOT_MEGA]                   = sAnims_PidgeotMega,
    [SPECIES_ALAKAZAM_MEGA]                  = sAnims_AlakazamMega,
    [SPECIES_SLOWBRO_MEGA]                   = sAnims_SlowbroMega,
    [SPECIES_GENGAR_MEGA]                    = sAnims_GengarMega,
    [SPECIES_KANGASKHAN_MEGA]                = sAnims_KangaskhanMega,
    [SPECIES_PINSIR_MEGA]                    = sAnims_PinsirMega,
    [SPECIES_GYARADOS_MEGA]                  = sAnims_GyaradosMega,
    [SPECIES_AERODACTYL_MEGA]                = sAnims_AerodactylMega,
    [SPECIES_MEWTWO_MEGA_X]                  = sAnims_MEWTWO_MEGA_X,
    [SPECIES_MEWTWO_MEGA_Y]                  = sAnims_MEWTWO_MEGA_Y,
    [SPECIES_AMPHAROS_MEGA]                  = sAnims_AmpharosMega,
    [SPECIES_STEELIX_MEGA]                   = sAnims_SteelixMega,
    [SPECIES_SCIZOR_MEGA]                    = sAnims_ScizorMega,
    [SPECIES_HERACROSS_MEGA]                 = sAnims_HeracrossMega,
    [SPECIES_HOUNDOOM_MEGA]                  = sAnims_HoundoomMega,
    [SPECIES_TYRANITAR_MEGA]                 = sAnims_TyranitarMega,
    [SPECIES_SCEPTILE_MEGA]                  = sAnims_SceptileMega,
    [SPECIES_BLAZIKEN_MEGA]                  = sAnims_BlazikenMega,
    [SPECIES_SWAMPERT_MEGA]                  = sAnims_SwampertMega,
    [SPECIES_GARDEVOIR_MEGA]                 = sAnims_GardevoirMega,
    [SPECIES_SABLEYE_MEGA]                   = sAnims_SableyeMega,
    [SPECIES_MAWILE_MEGA]                    = sAnims_MawileMega,
    [SPECIES_AGGRON_MEGA]                    = sAnims_AggronMega,
    [SPECIES_MEDICHAM_MEGA]                  = sAnims_MedichamMega,
    [SPECIES_MANECTRIC_MEGA]                 = sAnims_ManectricMega,
    [SPECIES_SHARPEDO_MEGA]                  = sAnims_SharpedoMega,
    [SPECIES_CAMERUPT_MEGA]                  = sAnims_CameruptMega,
    [SPECIES_ALTARIA_MEGA]                   = sAnims_AltariaMega,
    [SPECIES_BANETTE_MEGA]                   = sAnims_BanetteMega,
    [SPECIES_ABSOL_MEGA]                     = sAnims_AbsolMega,
    [SPECIES_GLALIE_MEGA]                    = sAnims_GlalieMega,
    [SPECIES_SALAMENCE_MEGA]                 = sAnims_SalamenceMega,
    [SPECIES_METAGROSS_MEGA]                 = sAnims_MetagrossMega,
    [SPECIES_LATIAS_MEGA]                    = sAnims_LatiasMega,
    [SPECIES_LATIOS_MEGA]                    = sAnims_LatiosMega,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_LOPUNNY_MEGA]                   = sAnims_LopunnyMega,
    [SPECIES_GARCHOMP_MEGA]                  = sAnims_GarchompMega,
    [SPECIES_LUCARIO_MEGA]                   = sAnims_LucarioMega,
    [SPECIES_ABOMASNOW_MEGA]                 = sAnims_AbomasnowMega,
    [SPECIES_GALLADE_MEGA]                   = sAnims_GalladeMega,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_AUDINO_MEGA]                    = sAnims_AudinoMega,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_DIANCIE_MEGA]                   = sAnims_DiancieMega,
#endif
    [SPECIES_RAYQUAZA_MEGA]                  = sAnims_RayquazaMega,
    [SPECIES_KYOGRE_PRIMAL]                  = sAnims_KyogrePrimal,
    [SPECIES_GROUDON_PRIMAL]                 = sAnims_GroudonPrimal,
    // Alolan Forms
    [SPECIES_RATTATA_ALOLAN]                 = sAnims_RattataAlolan,
    [SPECIES_RATICATE_ALOLAN]                = sAnims_RaticateAlolan,
    [SPECIES_RAICHU_ALOLAN]                  = sAnims_RaichuAlolan,
    [SPECIES_SANDSHREW_ALOLAN]               = sAnims_SandshrewAlolan,
    [SPECIES_SANDSLASH_ALOLAN]               = sAnims_SandslashAlolan,
    [SPECIES_VULPIX_ALOLAN]                  = sAnims_VulpixAlolan,
    [SPECIES_NINETALES_ALOLAN]               = sAnims_NinetalesAlolan,
    [SPECIES_DIGLETT_ALOLAN]                 = sAnims_DiglettAlolan,
    [SPECIES_DUGTRIO_ALOLAN]                 = sAnims_DugtrioAlolan,
    [SPECIES_MEOWTH_ALOLAN]                  = sAnims_MeowthAlolan,
    [SPECIES_PERSIAN_ALOLAN]                 = sAnims_PersianAlolan,
    [SPECIES_GEODUDE_ALOLAN]                 = sAnims_GeodudeAlolan,
    [SPECIES_GRAVELER_ALOLAN]                = sAnims_GravelerAlolan,
    [SPECIES_GOLEM_ALOLAN]                   = sAnims_GolemAlolan,
    [SPECIES_GRIMER_ALOLAN]                  = sAnims_GrimerAlolan,
    [SPECIES_MUK_ALOLAN]                     = sAnims_MukAlolan,
    [SPECIES_EXEGGUTOR_ALOLAN]               = sAnims_ExeggutorAlolan,
    [SPECIES_MAROWAK_ALOLAN]                 = sAnims_MarowakAlolan,
    // Galarian Forms
    [SPECIES_MEOWTH_GALARIAN]                = sAnims_MeowthGalarian,
    [SPECIES_PONYTA_GALARIAN]                = sAnims_PonytaGalarian,
    [SPECIES_RAPIDASH_GALARIAN]              = sAnims_RapidashGalarian,
    [SPECIES_SLOWPOKE_GALARIAN]              = sAnims_SlowpokeGalarian,
    [SPECIES_SLOWBRO_GALARIAN]               = sAnims_SlowbroGalarian,
    [SPECIES_FARFETCHD_GALARIAN]             = sAnims_FarfetchdGalarian,
    [SPECIES_WEEZING_GALARIAN]               = sAnims_WeezingGalarian,
    [SPECIES_MR_MIME_GALARIAN]               = sAnims_MrMimeGalarian,
    [SPECIES_ARTICUNO_GALARIAN]              = sAnims_ArticunoGalarian,
    [SPECIES_ZAPDOS_GALARIAN]                = sAnims_ZapdosGalarian,
    [SPECIES_MOLTRES_GALARIAN]               = sAnims_MoltresGalarian,
    [SPECIES_SLOWKING_GALARIAN]              = sAnims_SlowkingGalarian,
    [SPECIES_CORSOLA_GALARIAN]               = sAnims_CorsolaGalarian,
    [SPECIES_ZIGZAGOON_GALARIAN]             = sAnims_ZigzagoonGalarian,
    [SPECIES_LINOONE_GALARIAN]               = sAnims_LinooneGalarian,
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_DARUMAKA_GALARIAN]              = sAnims_DarumakaGalarian,
    [SPECIES_DARMANITAN_GALARIAN_STANDARD_MODE] = sAnims_DarmanitanGalarianStandardMode,
    [SPECIES_YAMASK_GALARIAN]                = sAnims_YamaskGalarian,
    [SPECIES_STUNFISK_GALARIAN]              = sAnims_StunfiskGalarian,
#endif
    // Hisuian Forms
    [SPECIES_GROWLITHE_HISUIAN]              = sAnims_GrowlitheHisuian,
    [SPECIES_ARCANINE_HISUIAN]               = sAnims_ArcanineHisuian,
    [SPECIES_VOLTORB_HISUIAN]                = sAnims_VoltorbHisuian,
    [SPECIES_ELECTRODE_HISUIAN]              = sAnims_ElectrodeHisuian,
    [SPECIES_TYPHLOSION_HISUIAN]             = sAnims_TyphlosionHisuian,
    [SPECIES_QWILFISH_HISUIAN]               = sAnims_QwilfishHisuian,
    [SPECIES_SNEASEL_HISUIAN]                = sAnims_SneaselHisuian,
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_SAMUROTT_HISUIAN]               = sAnims_SamurottHisuian,
    [SPECIES_LILLIGANT_HISUIAN]              = sAnims_LilligantHisuian,
    [SPECIES_ZORUA_HISUIAN]                  = sAnims_ZoruaHisuian,
    [SPECIES_ZOROARK_HISUIAN]                = sAnims_ZoroarkHisuian,
    [SPECIES_BRAVIARY_HISUIAN]               = sAnims_BraviaryHisuian,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_SLIGGOO_HISUIAN]                = sAnims_SliggooHisuian,
    [SPECIES_GOODRA_HISUIAN]                 = sAnims_GoodraHisuian,
    [SPECIES_AVALUGG_HISUIAN]                = sAnims_AvaluggHisuian,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_DECIDUEYE_HISUIAN]              = sAnims_DecidueyeHisuian,
#endif
    // Ungrouped
    [SPECIES_PIKACHU_COSPLAY]                = sAnims_PikachuCosplay,
    [SPECIES_PIKACHU_ROCK_STAR]              = sAnims_PikachuRockStar,
    [SPECIES_PIKACHU_BELLE]                  = sAnims_PikachuBelle,
    [SPECIES_PIKACHU_POP_STAR]               = sAnims_PikachuPopStar,
    [SPECIES_PIKACHU_PH_D]                   = sAnims_PIKACHU_PH_D,
    [SPECIES_PIKACHU_LIBRE]                  = sAnims_PikachuLibre,
    [SPECIES_PIKACHU_ORIGINAL_CAP]           = sAnims_PikachuOriginalCap,
    [SPECIES_PIKACHU_HOENN_CAP]              = sAnims_PikachuHoennCap,
    [SPECIES_PIKACHU_SINNOH_CAP]             = sAnims_PikachuSinnohCap,
    [SPECIES_PIKACHU_UNOVA_CAP]              = sAnims_PikachuUnovaCap,
    [SPECIES_PIKACHU_KALOS_CAP]              = sAnims_PikachuKalosCap,
    [SPECIES_PIKACHU_ALOLA_CAP]              = sAnims_PikachuAlolaCap,
    [SPECIES_PIKACHU_PARTNER_CAP]            = sAnims_PikachuPartnerCap,
    [SPECIES_PIKACHU_WORLD_CAP]              = sAnims_PikachuWorldCap,
    [SPECIES_PICHU_SPIKY_EARED]              = sAnims_PichuSpikyEared,
    [SPECIES_UNOWN_B]                        = sAnims_UnownB,
    [SPECIES_UNOWN_C]                        = sAnims_UnownC,
    [SPECIES_UNOWN_D]                        = sAnims_UnownD,
    [SPECIES_UNOWN_E]                        = sAnims_UnownE,
    [SPECIES_UNOWN_F]                        = sAnims_UnownF,
    [SPECIES_UNOWN_G]                        = sAnims_UnownG,
    [SPECIES_UNOWN_H]                        = sAnims_UnownH,
    [SPECIES_UNOWN_I]                        = sAnims_UnownI,
    [SPECIES_UNOWN_J]                        = sAnims_UnownJ,
    [SPECIES_UNOWN_K]                        = sAnims_UnownK,
    [SPECIES_UNOWN_L]                        = sAnims_UnownL,
    [SPECIES_UNOWN_M]                        = sAnims_UnownM,
    [SPECIES_UNOWN_N]                        = sAnims_UnownN,
    [SPECIES_UNOWN_O]                        = sAnims_UnownO,
    [SPECIES_UNOWN_P]                        = sAnims_UnownP,
    [SPECIES_UNOWN_Q]                        = sAnims_UnownQ,
    [SPECIES_UNOWN_R]                        = sAnims_UnownR,
    [SPECIES_UNOWN_S]                        = sAnims_UnownS,
    [SPECIES_UNOWN_T]                        = sAnims_UnownT,
    [SPECIES_UNOWN_U]                        = sAnims_UnownU,
    [SPECIES_UNOWN_V]                        = sAnims_UnownV,
    [SPECIES_UNOWN_W]                        = sAnims_UnownW,
    [SPECIES_UNOWN_X]                        = sAnims_UnownX,
    [SPECIES_UNOWN_Y]                        = sAnims_UnownY,
    [SPECIES_UNOWN_Z]                        = sAnims_UnownZ,
    [SPECIES_UNOWN_EMARK]                    = sAnims_UnownEMark,
    [SPECIES_UNOWN_QMARK]                    = sAnims_UnownQMark,
    [SPECIES_CASTFORM_SUNNY]                 = sAnims_CastformSunny,
    [SPECIES_CASTFORM_RAINY]                 = sAnims_CastformRainy,
    [SPECIES_CASTFORM_SNOWY]                 = sAnims_CastformSnowy,
    [SPECIES_DEOXYS_ATTACK]                  = sAnims_DeoxysAttack,
    [SPECIES_DEOXYS_DEFENSE]                 = sAnims_DeoxysDefense,
    [SPECIES_DEOXYS_SPEED]                   = sAnims_DeoxysSpeed,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_BURMY_SANDY_CLOAK]              = sAnims_Burmy,
    [SPECIES_BURMY_TRASH_CLOAK]              = sAnims_Burmy,
    [SPECIES_WORMADAM_SANDY_CLOAK]           = sAnims_Wormadam,
    [SPECIES_WORMADAM_TRASH_CLOAK]           = sAnims_Wormadam,
    [SPECIES_CHERRIM_SUNSHINE]               = sAnims_CherrimSunshine,
    [SPECIES_SHELLOS_EAST_SEA]               = sAnims_Shellos,
    [SPECIES_GASTRODON_EAST_SEA]             = sAnims_Gastrodon,
    [SPECIES_ROTOM_HEAT]                     = sAnims_RotomHeat,
    [SPECIES_ROTOM_WASH]                     = sAnims_RotomWash,
    [SPECIES_ROTOM_FROST]                    = sAnims_RotomFrost,
    [SPECIES_ROTOM_FAN]                      = sAnims_RotomFan,
    [SPECIES_ROTOM_MOW]                      = sAnims_RotomMow,
    [SPECIES_DIALGA_ORIGIN]                  = sAnims_DialgaOrigin,
    [SPECIES_PALKIA_ORIGIN]                  = sAnims_PalkiaOrigin,
    [SPECIES_GIRATINA_ORIGIN]                = sAnims_GiratinaOrigin,
    [SPECIES_SHAYMIN_SKY]                    = sAnims_ShayminSky,
    [SPECIES_ARCEUS_FIGHTING]                = sAnims_Arceus,
    [SPECIES_ARCEUS_FLYING]                  = sAnims_Arceus,
    [SPECIES_ARCEUS_POISON]                  = sAnims_Arceus,
    [SPECIES_ARCEUS_GROUND]                  = sAnims_Arceus,
    [SPECIES_ARCEUS_ROCK]                    = sAnims_Arceus,
    [SPECIES_ARCEUS_BUG]                     = sAnims_Arceus,
    [SPECIES_ARCEUS_GHOST]                   = sAnims_Arceus,
    [SPECIES_ARCEUS_STEEL]                   = sAnims_Arceus,
    [SPECIES_ARCEUS_FIRE]                    = sAnims_Arceus,
    [SPECIES_ARCEUS_WATER]                   = sAnims_Arceus,
    [SPECIES_ARCEUS_GRASS]                   = sAnims_Arceus,
    [SPECIES_ARCEUS_ELECTRIC]                = sAnims_Arceus,
    [SPECIES_ARCEUS_PSYCHIC]                 = sAnims_Arceus,
    [SPECIES_ARCEUS_ICE]                     = sAnims_Arceus,
    [SPECIES_ARCEUS_DRAGON]                  = sAnims_Arceus,
    [SPECIES_ARCEUS_DARK]                    = sAnims_Arceus,
    [SPECIES_ARCEUS_FAIRY]                   = sAnims_Arceus,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_BASCULIN_BLUE_STRIPED]          = sAnims_Basculin,
    [SPECIES_BASCULIN_WHITE_STRIPED]         = sAnims_Basculin,
    [SPECIES_DARMANITAN_ZEN_MODE]            = sAnims_DarmanitanZenMode,
    [SPECIES_DARMANITAN_GALARIAN_ZEN_MODE] = sAnims_DarmanitanGalarianZenMode,
    [SPECIES_DEERLING_SUMMER]                = sAnims_Deerling,
    [SPECIES_DEERLING_AUTUMN]                = sAnims_Deerling,
    [SPECIES_DEERLING_WINTER]                = sAnims_Deerling,
    [SPECIES_SAWSBUCK_SUMMER]                = sAnims_Sawsbuck,
    [SPECIES_SAWSBUCK_AUTUMN]                = sAnims_Sawsbuck,
    [SPECIES_SAWSBUCK_WINTER]                = sAnims_Sawsbuck,
    [SPECIES_TORNADUS_THERIAN]               = sAnims_TornadusTherian,
    [SPECIES_THUNDURUS_THERIAN]              = sAnims_ThundurusTherian,
    [SPECIES_LANDORUS_THERIAN]               = sAnims_LandorusTherian,
    [SPECIES_KYUREM_WHITE]                   = sAnims_KyuremWhite,
    [SPECIES_KYUREM_BLACK]                   = sAnims_KyuremBlack,
    [SPECIES_KELDEO_RESOLUTE]                = sAnims_KeldeoResolute,
    [SPECIES_MELOETTA_PIROUETTE]             = sAnims_MeloettaPirouette,
    [SPECIES_GENESECT_DOUSE_DRIVE]           = sAnims_Genesect,
    [SPECIES_GENESECT_SHOCK_DRIVE]           = sAnims_Genesect,
    [SPECIES_GENESECT_BURN_DRIVE]            = sAnims_Genesect,
    [SPECIES_GENESECT_CHILL_DRIVE]           = sAnims_Genesect,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_GRENINJA_BATTLE_BOND]           = sAnims_Greninja,
    [SPECIES_GRENINJA_ASH]                   = sAnims_GreninjaAsh,
    [SPECIES_VIVILLON_POLAR]                 = sAnims_Vivillon,
    [SPECIES_VIVILLON_TUNDRA]                = sAnims_Vivillon,
    [SPECIES_VIVILLON_CONTINENTAL]           = sAnims_Vivillon,
    [SPECIES_VIVILLON_GARDEN]                = sAnims_Vivillon,
    [SPECIES_VIVILLON_ELEGANT]               = sAnims_Vivillon,
    [SPECIES_VIVILLON_MEADOW]                = sAnims_Vivillon,
    [SPECIES_VIVILLON_MODERN]                = sAnims_Vivillon,
    [SPECIES_VIVILLON_MARINE]                = sAnims_Vivillon,
    [SPECIES_VIVILLON_ARCHIPELAGO]           = sAnims_Vivillon,
    [SPECIES_VIVILLON_HIGH_PLAINS]           = sAnims_Vivillon,
    [SPECIES_VIVILLON_SANDSTORM]             = sAnims_Vivillon,
    [SPECIES_VIVILLON_RIVER]                 = sAnims_Vivillon,
    [SPECIES_VIVILLON_MONSOON]               = sAnims_Vivillon,
    [SPECIES_VIVILLON_SAVANNA]               = sAnims_Vivillon,
    [SPECIES_VIVILLON_SUN]                   = sAnims_Vivillon,
    [SPECIES_VIVILLON_OCEAN]                 = sAnims_Vivillon,
    [SPECIES_VIVILLON_JUNGLE]                = sAnims_Vivillon,
    [SPECIES_VIVILLON_FANCY]                 = sAnims_Vivillon,
    [SPECIES_VIVILLON_POKE_BALL]             = sAnims_Vivillon,
    [SPECIES_FLABEBE_YELLOW_FLOWER]          = sAnims_Flabebe,
    [SPECIES_FLABEBE_ORANGE_FLOWER]          = sAnims_Flabebe,
    [SPECIES_FLABEBE_BLUE_FLOWER]            = sAnims_Flabebe,
    [SPECIES_FLABEBE_WHITE_FLOWER]           = sAnims_Flabebe,
    [SPECIES_FLOETTE_YELLOW_FLOWER]          = sAnims_Floette,
    [SPECIES_FLOETTE_ORANGE_FLOWER]          = sAnims_Floette,
    [SPECIES_FLOETTE_BLUE_FLOWER]            = sAnims_Floette,
    [SPECIES_FLOETTE_WHITE_FLOWER]           = sAnims_Floette,
    [SPECIES_FLOETTE_ETERNAL_FLOWER]         = sAnims_Floette,
    [SPECIES_FLORGES_YELLOW_FLOWER]          = sAnims_Florges,
    [SPECIES_FLORGES_ORANGE_FLOWER]          = sAnims_Florges,
    [SPECIES_FLORGES_BLUE_FLOWER]            = sAnims_Florges,
    [SPECIES_FLORGES_WHITE_FLOWER]           = sAnims_Florges,
    [SPECIES_FURFROU_HEART_TRIM]             = sAnims_Furfrou,
    [SPECIES_FURFROU_STAR_TRIM]              = sAnims_Furfrou,
    [SPECIES_FURFROU_DIAMOND_TRIM]           = sAnims_Furfrou,
    [SPECIES_FURFROU_DEBUTANTE_TRIM]         = sAnims_Furfrou,
    [SPECIES_FURFROU_MATRON_TRIM]            = sAnims_Furfrou,
    [SPECIES_FURFROU_DANDY_TRIM]             = sAnims_Furfrou,
    [SPECIES_FURFROU_LA_REINE_TRIM]          = sAnims_Furfrou,
    [SPECIES_FURFROU_KABUKI_TRIM]            = sAnims_Furfrou,
    [SPECIES_FURFROU_PHARAOH_TRIM]           = sAnims_Furfrou,
    [SPECIES_MEOWSTIC_FEMALE]                = sAnims_Meowstic,
    [SPECIES_AEGISLASH_BLADE]                = sAnims_AegislashBlade,
    [SPECIES_PUMPKABOO_SMALL]                = sAnims_Pumpkaboo,
    [SPECIES_PUMPKABOO_LARGE]                = sAnims_Pumpkaboo,
    [SPECIES_PUMPKABOO_SUPER]                = sAnims_Pumpkaboo,
    [SPECIES_GOURGEIST_SMALL]                = sAnims_Gourgeist,
    [SPECIES_GOURGEIST_LARGE]                = sAnims_Gourgeist,
    [SPECIES_GOURGEIST_SUPER]                = sAnims_Gourgeist,
    [SPECIES_XERNEAS_ACTIVE]                 = sAnims_Xerneas,
    [SPECIES_ZYGARDE_10_AURA_BREAK]          = sAnims_Zygarde10,
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT]     = sAnims_Zygarde10,
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT]     = sAnims_Zygarde50,
    [SPECIES_ZYGARDE_COMPLETE]               = sAnims_ZygardeComplete,
    [SPECIES_HOOPA_UNBOUND]                  = sAnims_HoopaUnbound,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO_POM_POM]               = sAnims_Oricorio,
    [SPECIES_ORICORIO_PAU]                   = sAnims_Oricorio,
    [SPECIES_ORICORIO_SENSU]                 = sAnims_Oricorio,
    [SPECIES_ROCKRUFF_OWN_TEMPO]             = sAnims_Rockruff,
    [SPECIES_LYCANROC_MIDNIGHT]              = sAnims_LycanrocMidnight,
    [SPECIES_LYCANROC_DUSK]                  = sAnims_LycanrocDusk,
    [SPECIES_WISHIWASHI_SCHOOL]              = sAnims_WishiwashiSchool,
    [SPECIES_SILVALLY_FIGHTING]              = sAnims_Silvally,
    [SPECIES_SILVALLY_FLYING]                = sAnims_Silvally,
    [SPECIES_SILVALLY_POISON]                = sAnims_Silvally,
    [SPECIES_SILVALLY_GROUND]                = sAnims_Silvally,
    [SPECIES_SILVALLY_ROCK]                  = sAnims_Silvally,
    [SPECIES_SILVALLY_BUG]                   = sAnims_Silvally,
    [SPECIES_SILVALLY_GHOST]                 = sAnims_Silvally,
    [SPECIES_SILVALLY_STEEL]                 = sAnims_Silvally,
    [SPECIES_SILVALLY_FIRE]                  = sAnims_Silvally,
    [SPECIES_SILVALLY_WATER]                 = sAnims_Silvally,
    [SPECIES_SILVALLY_GRASS]                 = sAnims_Silvally,
    [SPECIES_SILVALLY_ELECTRIC]              = sAnims_Silvally,
    [SPECIES_SILVALLY_PSYCHIC]               = sAnims_Silvally,
    [SPECIES_SILVALLY_ICE]                   = sAnims_Silvally,
    [SPECIES_SILVALLY_DRAGON]                = sAnims_Silvally,
    [SPECIES_SILVALLY_DARK]                  = sAnims_Silvally,
    [SPECIES_SILVALLY_FAIRY]                 = sAnims_Silvally,
    [SPECIES_MINIOR_METEOR_ORANGE]           = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_METEOR_YELLOW]           = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_METEOR_GREEN]            = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_METEOR_BLUE]             = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_METEOR_INDIGO]           = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_METEOR_VIOLET]           = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_RED]                = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_ORANGE]             = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_YELLOW]             = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_GREEN]              = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_BLUE]               = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_INDIGO]             = sAnims_MiniorMeteor,
    [SPECIES_MINIOR_CORE_VIOLET]             = sAnims_MiniorMeteor,
    [SPECIES_MIMIKYU_BUSTED]                 = sAnims_MimikyuBusted,
    [SPECIES_NECROZMA_DUSK_MANE]             = sAnims_Necrozma,
    [SPECIES_NECROZMA_DAWN_WINGS]            = sAnims_Necrozma,
    [SPECIES_NECROZMA_ULTRA]                 = sAnims_Necrozma,
    [SPECIES_MAGEARNA_ORIGINAL_COLOR]        = sAnims_Magearna,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT_GULPING]              = sAnims_Cramorant,
    [SPECIES_CRAMORANT_GORGING]              = sAnims_Cramorant,
    [SPECIES_TOXTRICITY_LOW_KEY]             = sAnims_Toxtricity,
    [SPECIES_SINISTEA_ANTIQUE]               = sAnims_Sinistea,
    [SPECIES_POLTEAGEIST_ANTIQUE]            = sAnims_Polteageist,
    [SPECIES_EISCUE_NOICE_FACE]              = sAnims_Eiscue,
    [SPECIES_INDEEDEE_FEMALE]                = sAnims_Indeedee,
    [SPECIES_MORPEKO_HANGRY]                 = sAnims_Morpeko,
    [SPECIES_ZACIAN_CROWNED_SWORD]           = sAnims_Zacian,
    [SPECIES_ZAMAZENTA_CROWNED_SHIELD]       = sAnims_Zamazenta,
    [SPECIES_ETERNATUS_ETERNAMAX]            = sAnims_Eternatus,
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE]     = sAnims_Urshifu,
    [SPECIES_ZARUDE_DADA]                    = sAnims_Zarude,
    [SPECIES_CALYREX_ICE_RIDER]              = sAnims_Calyrex,
    [SPECIES_CALYREX_SHADOW_RIDER]           = sAnims_Calyrex,
    [SPECIES_ENAMORUS_THERIAN]               = sAnims_EnamorusTherian,
    [SPECIES_BASCULEGION_FEMALE]             = sAnims_Basculegion,
    [SPECIES_URSALUNA_BLOODMOON]             = sAnims_UrsalunaBloodmoon,
#endif
    [SPECIES_VENUSAUR_GIGANTAMAX]            = sAnims_VenusaurGigantamax,
    [SPECIES_CHARIZARD_GIGANTAMAX]           = sAnims_CharizardGigantamax,
    [SPECIES_BLASTOISE_GIGANTAMAX]           = sAnims_BlastoiseGigantamax,
    [SPECIES_BUTTERFREE_GIGANTAMAX]          = sAnims_ButterfreeGigantamax,
    [SPECIES_PIKACHU_GIGANTAMAX]             = sAnims_PikachuGigantamax,
    [SPECIES_MEOWTH_GIGANTAMAX]              = sAnims_MeowthGigantamax,
    [SPECIES_MACHAMP_GIGANTAMAX]             = sAnims_MachampGigantamax,
    [SPECIES_GENGAR_GIGANTAMAX]              = sAnims_GengarGigantamax,
    [SPECIES_KINGLER_GIGANTAMAX]             = sAnims_KinglerGigantamax,
    [SPECIES_LAPRAS_GIGANTAMAX]              = sAnims_LaprasGigantamax,
    [SPECIES_EEVEE_GIGANTAMAX]               = sAnims_EeveeGigantamax,
    [SPECIES_SNORLAX_GIGANTAMAX]             = sAnims_SnorlaxGigantamax,
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_GARBODOR_GIGANTAMAX]            = sAnims_GarbodorGigantamax,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_MELMETAL_GIGANTAMAX]            = sAnims_MelmetalGigantamax,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_RILLABOOM_GIGANTAMAX]           = sAnims_RillaboomGigantamax,
    [SPECIES_CINDERACE_GIGANTAMAX]           = sAnims_CinderaceGigantamax,
    [SPECIES_INTELEON_GIGANTAMAX]            = sAnims_InteleonGigantamax,
    [SPECIES_CORVIKNIGHT_GIGANTAMAX]         = sAnims_CorviknightGigantamax,
    [SPECIES_ORBEETLE_GIGANTAMAX]            = sAnims_OrbeetleGigantamax,
    [SPECIES_DREDNAW_GIGANTAMAX]             = sAnims_DrednawGigantamax,
    [SPECIES_COALOSSAL_GIGANTAMAX]           = sAnims_CoalossalGigantamax,
    [SPECIES_FLAPPLE_GIGANTAMAX]             = sAnims_FlappleGigantamax,
    [SPECIES_APPLETUN_GIGANTAMAX]            = sAnims_AppletunGigantamax,
    [SPECIES_SANDACONDA_GIGANTAMAX]          = sAnims_SandacondaGigantamax,
    [SPECIES_TOXTRICITY_AMPED_GIGANTAMAX]    = sAnims_ToxtricityGigantamax,
    [SPECIES_TOXTRICITY_LOW_KEY_GIGANTAMAX]  = sAnims_ToxtricityGigantamax,
    [SPECIES_CENTISKORCH_GIGANTAMAX]         = sAnims_CentiskorchGigantamax,
    [SPECIES_HATTERENE_GIGANTAMAX]           = sAnims_HattereneGigantamax,
    [SPECIES_GRIMMSNARL_GIGANTAMAX]          = sAnims_GrimmsnarlGigantamax,
    [SPECIES_ALCREMIE_GIGANTAMAX]            = sAnims_AlcremieGigantamax,
    [SPECIES_COPPERAJAH_GIGANTAMAX]          = sAnims_CopperajahGigantamax,
    [SPECIES_DURALUDON_GIGANTAMAX]           = sAnims_DuraludonGigantamax,
    [SPECIES_URSHIFU_SINGLE_STRIKE_STYLE_GIGANTAMAX] = sAnims_UrshifuSingleStrikeStyleGigantamax,
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE_GIGANTAMAX] = sAnims_UrshifuRapidStrikeStyleGigantamax,
#endif
    [SPECIES_EGG]                            = sAnims_Egg,
};
