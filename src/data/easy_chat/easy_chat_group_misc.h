const u8 gEasyChatWord_Highs[] = _("HIGHS");
const u8 gEasyChatWord_Lows[] = _("LOWS");
const u8 gEasyChatWord_Um[] = _("UM");
const u8 gEasyChatWord_Rear[] = _("REAR");
const u8 gEasyChatWord_Things[] = _("THINGS");
const u8 gEasyChatWord_Thing[] = _("THING");
const u8 gEasyChatWord_Below[] = _("BELOW");
const u8 gEasyChatWord_Above[] = _("ABOVE");
const u8 gEasyChatWord_Back[] = _("BACK");
const u8 gEasyChatWord_High[] = _("HIGH");
const u8 gEasyChatWord_Here[] = _("HERE");
const u8 gEasyChatWord_Inside[] = _("INSIDE");
const u8 gEasyChatWord_Outside[] = _("OUTSIDE");
const u8 gEasyChatWord_Beside[] = _("BESIDE");
const u8 gEasyChatWord_ThisIsItExcl[] = _("THIS IS IT!");
const u8 gEasyChatWord_This[] = _("THIS");
const u8 gEasyChatWord_Every[] = _("EVERY");
const u8 gEasyChatWord_These[] = _("THESE");
const u8 gEasyChatWord_TheseWere[] = _("THESE WERE");
const u8 gEasyChatWord_Down[] = _("DOWN");
const u8 gEasyChatWord_That[] = _("THAT");
const u8 gEasyChatWord_ThoseAre[] = _("THOSE ARE");
const u8 gEasyChatWord_ThoseWere[] = _("THOSE WERE");
const u8 gEasyChatWord_ThatsItExcl[] = _("THAT'S IT!");
const u8 gEasyChatWord_Am[] = _("AM");
const u8 gEasyChatWord_ThatWas[] = _("THAT WAS");
const u8 gEasyChatWord_Front[] = _("FRONT");
const u8 gEasyChatWord_Up[] = _("UP");
const u8 gEasyChatWord_Choice[] = _("CHOICE");
const u8 gEasyChatWord_Far[] = _("FAR");
const u8 gEasyChatWord_Away[] = _("AWAY");
const u8 gEasyChatWord_Near[] = _("NEAR");
const u8 gEasyChatWord_Where[] = _("WHERE");
const u8 gEasyChatWord_When[] = _("WHEN");
const u8 gEasyChatWord_What[] = _("WHAT");
const u8 gEasyChatWord_Deep[] = _("DEEP");
const u8 gEasyChatWord_Shallow[] = _("SHALLOW");
const u8 gEasyChatWord_Why[] = _("WHY");
const u8 gEasyChatWord_Confused[] = _("CONFUSED");
const u8 gEasyChatWord_Opposite[] = _("OPPOSITE");
const u8 gEasyChatWord_Left[] = _("LEFT");
const u8 gEasyChatWord_Right[] = _("RIGHT");

const struct EasyChatWordInfo gEasyChatGroup_Misc[] = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
        .text = gEasyChatWord_Highs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
        .text = gEasyChatWord_Lows,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
        .text = gEasyChatWord_Um,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
        .text = gEasyChatWord_Rear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
        .text = gEasyChatWord_Things,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
        .text = gEasyChatWord_Thing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BESIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
        .text = gEasyChatWord_Below,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
        .text = gEasyChatWord_Above,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONFUSED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
        .text = gEasyChatWord_Back,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEEP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
        .text = gEasyChatWord_High,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
        .text = gEasyChatWord_Here,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
        .text = gEasyChatWord_Inside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
        .text = gEasyChatWord_Outside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
        .text = gEasyChatWord_Beside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThisIsItExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
        .text = gEasyChatWord_This,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGHS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
        .text = gEasyChatWord_Every,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
        .text = gEasyChatWord_These,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEFT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
        .text = gEasyChatWord_TheseWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
        .text = gEasyChatWord_Down,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
        .text = gEasyChatWord_That,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPOSITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
        .text = gEasyChatWord_ThoseAre,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUTSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
        .text = gEasyChatWord_ThoseWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThatsItExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
        .text = gEasyChatWord_Am,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHALLOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
        .text = gEasyChatWord_ThatWas,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
        .text = gEasyChatWord_Front,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
        .text = gEasyChatWord_Up,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
        .text = gEasyChatWord_Choice,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
        .text = gEasyChatWord_Far,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
        .text = gEasyChatWord_Away,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
        .text = gEasyChatWord_Near,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
        .text = gEasyChatWord_Where,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
        .text = gEasyChatWord_When,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS_IS_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
        .text = gEasyChatWord_What,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_ARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
        .text = gEasyChatWord_Deep,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
        .text = gEasyChatWord_Shallow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
        .text = gEasyChatWord_Why,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
        .text = gEasyChatWord_Confused,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
        .text = gEasyChatWord_Opposite,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
        .text = gEasyChatWord_Left,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
        .text = gEasyChatWord_Right,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHY),
        .enabled = TRUE,
    },
};
