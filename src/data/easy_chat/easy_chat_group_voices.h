const u8 gEasyChatWord_Excl[] = _("!");
const u8 gEasyChatWord_ExclExcl[] = _("!!");
const u8 gEasyChatWord_QuesExcl[] = _("?!");
const u8 gEasyChatWord_Ques[] = _("?");
const u8 gEasyChatWord_Ellipsis[] = _("…");
const u8 gEasyChatWord_EllipsisExcl[] = _("…!");
const u8 gEasyChatWord_EllipsisEllipsisEllipsis[] = _("………");
const u8 gEasyChatWord_Dash[] = _("-");
const u8 gEasyChatWord_DashDashDash[] = _("- - -");
const u8 gEasyChatWord_UhOh[] = _("UH-OH");
const u8 gEasyChatWord_Waaah[] = _("WAAAH");
const u8 gEasyChatWord_Ahaha[] = _("AHAHA");
const u8 gEasyChatWord_OhQues[] = _("OH?");
const u8 gEasyChatWord_Nope[] = _("NOPE");
const u8 gEasyChatWord_Urgh[] = _("URGH");
const u8 gEasyChatWord_Hmm[] = _("HMM");
const u8 gEasyChatWord_Whoah[] = _("WHOAH");
const u8 gEasyChatWord_WroooaarExcl[] = _("WROOOAAR!");
const u8 gEasyChatWord_Wow[] = _("WOW");
const u8 gEasyChatWord_Giggle[] = _("GIGGLE");
const u8 gEasyChatWord_Sigh[] = _("SIGH");
const u8 gEasyChatWord_Unbelievable[] = _("UNBELIEVABLE");
const u8 gEasyChatWord_Cries[] = _("CRIES");
const u8 gEasyChatWord_Agree[] = _("AGREE");
const u8 gEasyChatWord_EhQues[] = _("EH?");
const u8 gEasyChatWord_Cry[] = _("CRY");
const u8 gEasyChatWord_Ehehe[] = _("EHEHE");
const u8 gEasyChatWord_OiOiOi[] = _("OI, OI, OI");
const u8 gEasyChatWord_OhYeah[] = _("OH, YEAH");
const u8 gEasyChatWord_Oh[] = _("OH");
const u8 gEasyChatWord_Oops[] = _("OOPS");
const u8 gEasyChatWord_Shocked[] = _("SHOCKED");
const u8 gEasyChatWord_Eek[] = _("EEK");
const u8 gEasyChatWord_Graaah[] = _("GRAAAH");
const u8 gEasyChatWord_Gwahahaha[] = _("GWAHAHAHA");
const u8 gEasyChatWord_Way[] = _("WAY");
const u8 gEasyChatWord_Tch[] = _("TCH");
const u8 gEasyChatWord_Hehe[] = _("HEHE");
const u8 gEasyChatWord_Hah[] = _("HAH");
const u8 gEasyChatWord_Yup[] = _("YUP");
const u8 gEasyChatWord_Hahaha[] = _("HAHAHA");
const u8 gEasyChatWord_Aiyeeh[] = _("AIYEEH");
const u8 gEasyChatWord_Hiyah[] = _("HIYAH");
const u8 gEasyChatWord_Fufufu[] = _("FUFUFU");
const u8 gEasyChatWord_Lol[] = _("LOL");
const u8 gEasyChatWord_Snort[] = _("SNORT");
const u8 gEasyChatWord_Humph[] = _("HUMPH");
const u8 gEasyChatWord_Hehehe[] = _("HEHEHE");
const u8 gEasyChatWord_Heh[] = _("HEH");
const u8 gEasyChatWord_Hohoho[] = _("HOHOHO");
const u8 gEasyChatWord_UhHuh[] = _("UH-HUH");
const u8 gEasyChatWord_OhDear[] = _("OH, DEAR");
const u8 gEasyChatWord_Arrgh[] = _("ARRGH");
const u8 gEasyChatWord_Mufufu[] = _("MUFUFU");
const u8 gEasyChatWord_Mmm[] = _("MMM");
const u8 gEasyChatWord_OhKay[] = _("OH-KAY");
const u8 gEasyChatWord_Okay[] = _("OKAY");
const u8 gEasyChatWord_Lalala[] = _("LALALA");
const u8 gEasyChatWord_Yay[] = _("YAY");
const u8 gEasyChatWord_Aww[] = _("AWW");
const u8 gEasyChatWord_Wowee[] = _("WOWEE");
const u8 gEasyChatWord_Gwah[] = _("GWAH");
const u8 gEasyChatWord_Wahahaha[] = _("WAHAHAHA");

const struct EasyChatWordInfo gEasyChatGroup_Voices[] = {
    [EC_INDEX(EC_WORD_EXCL)] =
    {
        .text = gEasyChatWord_Excl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCL_EXCL)] =
    {
        .text = gEasyChatWord_ExclExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES_EXCL)] =
    {
        .text = gEasyChatWord_QuesExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES)] =
    {
        .text = gEasyChatWord_Ques,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH_DASH_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS)] =
    {
        .text = gEasyChatWord_Ellipsis,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_EXCL)] =
    {
        .text = gEasyChatWord_EllipsisExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS)] =
    {
        .text = gEasyChatWord_EllipsisEllipsisEllipsis,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH)] =
    {
        .text = gEasyChatWord_Dash,
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH_DASH_DASH)] =
    {
        .text = gEasyChatWord_DashDashDash,
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_OH)] =
    {
        .text = gEasyChatWord_UhOh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AGREE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAAAH)] =
    {
        .text = gEasyChatWord_Waaah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AHAHA)] =
    {
        .text = gEasyChatWord_Ahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIYEEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_QUES)] =
    {
        .text = gEasyChatWord_OhQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARRGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOPE)] =
    {
        .text = gEasyChatWord_Nope,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_URGH)] =
    {
        .text = gEasyChatWord_Urgh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRIES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HMM)] =
    {
        .text = gEasyChatWord_Hmm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOAH)] =
    {
        .text = gEasyChatWord_Whoah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EEK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WROOOAAR_EXCL)] =
    {
        .text = gEasyChatWord_WroooaarExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOW)] =
    {
        .text = gEasyChatWord_Wow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EHEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIGGLE)] =
    {
        .text = gEasyChatWord_Giggle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUFUFU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIGH)] =
    {
        .text = gEasyChatWord_Sigh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIGGLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNBELIEVABLE)] =
    {
        .text = gEasyChatWord_Unbelievable,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRAAAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRIES)] =
    {
        .text = gEasyChatWord_Cries,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AGREE)] =
    {
        .text = gEasyChatWord_Agree,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAHAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EH_QUES)] =
    {
        .text = gEasyChatWord_EhQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRY)] =
    {
        .text = gEasyChatWord_Cry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EHEHE)] =
    {
        .text = gEasyChatWord_Ehehe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI_OI_OI)] =
    {
        .text = gEasyChatWord_OiOiOi,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_YEAH)] =
    {
        .text = gEasyChatWord_OhYeah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH)] =
    {
        .text = gEasyChatWord_Oh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIYAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OOPS)] =
    {
        .text = gEasyChatWord_Oops,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOCKED)] =
    {
        .text = gEasyChatWord_Shocked,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOHOHO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EEK)] =
    {
        .text = gEasyChatWord_Eek,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUMPH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRAAAH)] =
    {
        .text = gEasyChatWord_Graaah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LALALA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAHAHAHA)] =
    {
        .text = gEasyChatWord_Gwahahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAY)] =
    {
        .text = gEasyChatWord_Way,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TCH)] =
    {
        .text = gEasyChatWord_Tch,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUFUFU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHE)] =
    {
        .text = gEasyChatWord_Hehe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOPE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAH)] =
    {
        .text = gEasyChatWord_Hah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YUP)] =
    {
        .text = gEasyChatWord_Yup,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_DEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAHAHA)] =
    {
        .text = gEasyChatWord_Hahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIYEEH)] =
    {
        .text = gEasyChatWord_Aiyeeh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_KAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIYAH)] =
    {
        .text = gEasyChatWord_Hiyah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUFUFU)] =
    {
        .text = gEasyChatWord_Fufufu,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI_OI_OI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOL)] =
    {
        .text = gEasyChatWord_Lol,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OKAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SNORT)] =
    {
        .text = gEasyChatWord_Snort,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OOPS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUMPH)] =
    {
        .text = gEasyChatWord_Humph,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOCKED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHEHE)] =
    {
        .text = gEasyChatWord_Hehehe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEH)] =
    {
        .text = gEasyChatWord_Heh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SNORT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOHOHO)] =
    {
        .text = gEasyChatWord_Hohoho,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_HUH)] =
    {
        .text = gEasyChatWord_UhHuh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_HUH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_DEAR)] =
    {
        .text = gEasyChatWord_OhDear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_OH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARRGH)] =
    {
        .text = gEasyChatWord_Arrgh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNBELIEVABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUFUFU)] =
    {
        .text = gEasyChatWord_Mufufu,
        .alphabeticalOrder = EC_INDEX(EC_WORD_URGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MMM)] =
    {
        .text = gEasyChatWord_Mmm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAAAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_KAY)] =
    {
        .text = gEasyChatWord_OhKay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAHAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OKAY)] =
    {
        .text = gEasyChatWord_Okay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LALALA)] =
    {
        .text = gEasyChatWord_Lalala,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAY)] =
    {
        .text = gEasyChatWord_Yay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWW)] =
    {
        .text = gEasyChatWord_Aww,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOWEE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOWEE)] =
    {
        .text = gEasyChatWord_Wowee,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WROOOAAR_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAH)] =
    {
        .text = gEasyChatWord_Gwah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAHAHAHA)] =
    {
        .text = gEasyChatWord_Wahahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YUP),
        .enabled = TRUE,
    },
};
