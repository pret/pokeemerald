const u8 gEasyChatWord_Listen[] = _("LISTEN");
const u8 gEasyChatWord_NotVery[] = _("NOT VERY");
const u8 gEasyChatWord_Mean[] = _("MEAN");
const u8 gEasyChatWord_Lie[] = _("LIE");
const u8 gEasyChatWord_Lay[] = _("LAY");
const u8 gEasyChatWord_Recommend[] = _("RECOMMEND");
const u8 gEasyChatWord_Nitwit[] = _("NITWIT");
const u8 gEasyChatWord_Quite[] = _("QUITE");
const u8 gEasyChatWord_From[] = _("FROM");
const u8 gEasyChatWord_Feeling[] = _("FEELING");
const u8 gEasyChatWord_But[] = _("BUT");
const u8 gEasyChatWord_However[] = _("HOWEVER");
const u8 gEasyChatWord_Case[] = _("CASE");
const u8 gEasyChatWord_The[] = _("THE");
const u8 gEasyChatWord_Miss[] = _("MISS");
const u8 gEasyChatWord_How[] = _("HOW");
const u8 gEasyChatWord_Hit[] = _("HIT");
const u8 gEasyChatWord_Enough[] = _("ENOUGH");
const u8 gEasyChatWord_ALot[] = _("A LOT");
const u8 gEasyChatWord_ALittle[] = _("A LITTLE");
const u8 gEasyChatWord_Absolutely[] = _("ABSOLUTELY");
const u8 gEasyChatWord_And[] = _("AND");
const u8 gEasyChatWord_Only[] = _("ONLY");
const u8 gEasyChatWord_Around[] = _("AROUND");
const u8 gEasyChatWord_Probably[] = _("PROBABLY");
const u8 gEasyChatWord_If[] = _("IF");
const u8 gEasyChatWord_Very[] = _("VERY");
const u8 gEasyChatWord_ATinyBit[] = _("A TINY BIT");
const u8 gEasyChatWord_Wild[] = _("WILD");
const u8 gEasyChatWord_Thats[] = _("THAT'S");
const u8 gEasyChatWord_Just[] = _("JUST");
const u8 gEasyChatWord_EvenSo[] = _("EVEN SO,");
const u8 gEasyChatWord_MustBe[] = _("MUST BE");
const u8 gEasyChatWord_Naturally[] = _("NATURALLY");
const u8 gEasyChatWord_ForNow[] = _("FOR NOW,");
const u8 gEasyChatWord_Understood[] = _("UNDERSTOOD");
const u8 gEasyChatWord_Joking[] = _("JOKING");
const u8 gEasyChatWord_Ready[] = _("READY");
const u8 gEasyChatWord_Something[] = _("SOMETHING");
const u8 gEasyChatWord_Somehow[] = _("SOMEHOW");
const u8 gEasyChatWord_Although[] = _("ALTHOUGH");
const u8 gEasyChatWord_Also[] = _("ALSO");
const u8 gEasyChatWord_Perfect[] = _("PERFECT");
const u8 gEasyChatWord_AsMuchAs[] = _("AS MUCH AS");
const u8 gEasyChatWord_Really[] = _("REALLY");
const u8 gEasyChatWord_Truly[] = _("TRULY");
const u8 gEasyChatWord_Seriously[] = _("SERIOUSLY");
const u8 gEasyChatWord_Totally[] = _("TOTALLY");
const u8 gEasyChatWord_Until[] = _("UNTIL");
const u8 gEasyChatWord_AsIf[] = _("AS IF");
const u8 gEasyChatWord_Mood[] = _("MOOD");
const u8 gEasyChatWord_Rather[] = _("RATHER");
const u8 gEasyChatWord_Awfully[] = _("AWFULLY");
const u8 gEasyChatWord_Mode[] = _("MODE");
const u8 gEasyChatWord_More[] = _("MORE");
const u8 gEasyChatWord_TooLate[] = _("TOO LATE");
const u8 gEasyChatWord_Finally[] = _("FINALLY");
const u8 gEasyChatWord_Any[] = _("ANY");
const u8 gEasyChatWord_Instead[] = _("INSTEAD");
const u8 gEasyChatWord_Fantastic[] = _("FANTASTIC");

const struct EasyChatWordInfo gEasyChatGroup_Speech[] = {
    [EC_INDEX(EC_WORD_LISTEN)] =
    {
        .text = gEasyChatWord_Listen,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LITTLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOT_VERY)] =
    {
        .text = gEasyChatWord_NotVery,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEAN)] =
    {
        .text = gEasyChatWord_Mean,
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_TINY_BIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIE)] =
    {
        .text = gEasyChatWord_Lie,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSOLUTELY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAY)] =
    {
        .text = gEasyChatWord_Lay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALSO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RECOMMEND)] =
    {
        .text = gEasyChatWord_Recommend,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALTHOUGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NITWIT)] =
    {
        .text = gEasyChatWord_Nitwit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUITE)] =
    {
        .text = gEasyChatWord_Quite,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FROM)] =
    {
        .text = gEasyChatWord_From,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AROUND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEELING)] =
    {
        .text = gEasyChatWord_Feeling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_IF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUT)] =
    {
        .text = gEasyChatWord_But,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_MUCH_AS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOWEVER)] =
    {
        .text = gEasyChatWord_However,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFULLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CASE)] =
    {
        .text = gEasyChatWord_Case,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THE)] =
    {
        .text = gEasyChatWord_The,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISS)] =
    {
        .text = gEasyChatWord_Miss,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENOUGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW)] =
    {
        .text = gEasyChatWord_How,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVEN_SO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIT)] =
    {
        .text = gEasyChatWord_Hit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FANTASTIC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENOUGH)] =
    {
        .text = gEasyChatWord_Enough,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEELING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_LOT)] =
    {
        .text = gEasyChatWord_ALot,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_LITTLE)] =
    {
        .text = gEasyChatWord_ALittle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR_NOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSOLUTELY)] =
    {
        .text = gEasyChatWord_Absolutely,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FROM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AND)] =
    {
        .text = gEasyChatWord_And,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ONLY)] =
    {
        .text = gEasyChatWord_Only,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AROUND)] =
    {
        .text = gEasyChatWord_Around,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOWEVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROBABLY)] =
    {
        .text = gEasyChatWord_Probably,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF)] =
    {
        .text = gEasyChatWord_If,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSTEAD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERY)] =
    {
        .text = gEasyChatWord_Very,
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_TINY_BIT)] =
    {
        .text = gEasyChatWord_ATinyBit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WILD)] =
    {
        .text = gEasyChatWord_Wild,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S)] =
    {
        .text = gEasyChatWord_Thats,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUST)] =
    {
        .text = gEasyChatWord_Just,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVEN_SO)] =
    {
        .text = gEasyChatWord_EvenSo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUST_BE)] =
    {
        .text = gEasyChatWord_MustBe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURALLY)] =
    {
        .text = gEasyChatWord_Naturally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOR_NOW)] =
    {
        .text = gEasyChatWord_ForNow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTOOD)] =
    {
        .text = gEasyChatWord_Understood,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JOKING)] =
    {
        .text = gEasyChatWord_Joking,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUST_BE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_READY)] =
    {
        .text = gEasyChatWord_Ready,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMETHING)] =
    {
        .text = gEasyChatWord_Something,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NITWIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMEHOW)] =
    {
        .text = gEasyChatWord_Somehow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT_VERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALTHOUGH)] =
    {
        .text = gEasyChatWord_Although,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALSO)] =
    {
        .text = gEasyChatWord_Also,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECT)] =
    {
        .text = gEasyChatWord_Perfect,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROBABLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS_MUCH_AS)] =
    {
        .text = gEasyChatWord_AsMuchAs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REALLY)] =
    {
        .text = gEasyChatWord_Really,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RATHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRULY)] =
    {
        .text = gEasyChatWord_Truly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_READY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERIOUSLY)] =
    {
        .text = gEasyChatWord_Seriously,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOTALLY)] =
    {
        .text = gEasyChatWord_Totally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECOMMEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNTIL)] =
    {
        .text = gEasyChatWord_Until,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUSLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS_IF)] =
    {
        .text = gEasyChatWord_AsIf,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEHOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOOD)] =
    {
        .text = gEasyChatWord_Mood,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMETHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RATHER)] =
    {
        .text = gEasyChatWord_Rather,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFULLY)] =
    {
        .text = gEasyChatWord_Awfully,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODE)] =
    {
        .text = gEasyChatWord_Mode,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_LATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MORE)] =
    {
        .text = gEasyChatWord_More,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOTALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_LATE)] =
    {
        .text = gEasyChatWord_TooLate,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRULY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINALLY)] =
    {
        .text = gEasyChatWord_Finally,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANY)] =
    {
        .text = gEasyChatWord_Any,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNTIL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSTEAD)] =
    {
        .text = gEasyChatWord_Instead,
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FANTASTIC)] =
    {
        .text = gEasyChatWord_Fantastic,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILD),
        .enabled = TRUE,
    },
};
