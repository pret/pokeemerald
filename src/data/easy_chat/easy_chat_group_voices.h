const struct EasyChatWordInfo gEasyChatGroup_Voices[] = {
    [EC_INDEX(EC_WORD_EXCL)] =
    {
        .text = COMPOUND_STRING("!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCL_EXCL)] =
    {
        .text = COMPOUND_STRING("!!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES_EXCL)] =
    {
        .text = COMPOUND_STRING("?!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES)] =
    {
        .text = COMPOUND_STRING("?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH_DASH_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS)] =
    {
        .text = COMPOUND_STRING("…"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_EXCL)] =
    {
        .text = COMPOUND_STRING("…!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS)] =
    {
        .text = COMPOUND_STRING("………"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH)] =
    {
        .text = COMPOUND_STRING("-"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH_DASH_DASH)] =
    {
        .text = COMPOUND_STRING("- - -"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_OH)] =
    {
        .text = COMPOUND_STRING("UH-OH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AGREE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAAAH)] =
    {
        .text = COMPOUND_STRING("WAAAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AHAHA)] =
    {
        .text = COMPOUND_STRING("AHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIYEEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_QUES)] =
    {
        .text = COMPOUND_STRING("OH?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARRGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOPE)] =
    {
        .text = COMPOUND_STRING("NOPE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_URGH)] =
    {
        .text = COMPOUND_STRING("URGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRIES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HMM)] =
    {
        .text = COMPOUND_STRING("HMM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOAH)] =
    {
        .text = COMPOUND_STRING("WHOAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EEK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WROOOAAR_EXCL)] =
    {
        .text = COMPOUND_STRING("WROOOAAR!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOW)] =
    {
        .text = COMPOUND_STRING("WOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EHEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIGGLE)] =
    {
        .text = COMPOUND_STRING("GIGGLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUFUFU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIGH)] =
    {
        .text = COMPOUND_STRING("SIGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIGGLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNBELIEVABLE)] =
    {
        .text = COMPOUND_STRING("UNBELIEVABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRAAAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRIES)] =
    {
        .text = COMPOUND_STRING("CRIES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AGREE)] =
    {
        .text = COMPOUND_STRING("AGREE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAHAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EH_QUES)] =
    {
        .text = COMPOUND_STRING("EH?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRY)] =
    {
        .text = COMPOUND_STRING("CRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EHEHE)] =
    {
        .text = COMPOUND_STRING("EHEHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI_OI_OI)] =
    {
        .text = COMPOUND_STRING("OI, OI, OI"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_YEAH)] =
    {
        .text = COMPOUND_STRING("OH, YEAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH)] =
    {
        .text = COMPOUND_STRING("OH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIYAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OOPS)] =
    {
        .text = COMPOUND_STRING("OOPS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOCKED)] =
    {
        .text = COMPOUND_STRING("SHOCKED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOHOHO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EEK)] =
    {
        .text = COMPOUND_STRING("EEK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUMPH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRAAAH)] =
    {
        .text = COMPOUND_STRING("GRAAAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LALALA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAHAHAHA)] =
    {
        .text = COMPOUND_STRING("GWAHAHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAY)] =
    {
        .text = COMPOUND_STRING("WAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TCH)] =
    {
        .text = COMPOUND_STRING("TCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUFUFU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHE)] =
    {
        .text = COMPOUND_STRING("HEHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOPE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAH)] =
    {
        .text = COMPOUND_STRING("HAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YUP)] =
    {
        .text = COMPOUND_STRING("YUP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_DEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAHAHA)] =
    {
        .text = COMPOUND_STRING("HAHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIYEEH)] =
    {
        .text = COMPOUND_STRING("AIYEEH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_KAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIYAH)] =
    {
        .text = COMPOUND_STRING("HIYAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUFUFU)] =
    {
        .text = COMPOUND_STRING("FUFUFU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI_OI_OI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOL)] =
    {
        .text = COMPOUND_STRING("LOL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OKAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SNORT)] =
    {
        .text = COMPOUND_STRING("SNORT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OOPS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUMPH)] =
    {
        .text = COMPOUND_STRING("HUMPH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOCKED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHEHE)] =
    {
        .text = COMPOUND_STRING("HEHEHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEH)] =
    {
        .text = COMPOUND_STRING("HEH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SNORT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOHOHO)] =
    {
        .text = COMPOUND_STRING("HOHOHO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_HUH)] =
    {
        .text = COMPOUND_STRING("UH-HUH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_HUH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_DEAR)] =
    {
        .text = COMPOUND_STRING("OH, DEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_OH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARRGH)] =
    {
        .text = COMPOUND_STRING("ARRGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNBELIEVABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUFUFU)] =
    {
        .text = COMPOUND_STRING("MUFUFU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_URGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MMM)] =
    {
        .text = COMPOUND_STRING("MMM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAAAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_KAY)] =
    {
        .text = COMPOUND_STRING("OH-KAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAHAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OKAY)] =
    {
        .text = COMPOUND_STRING("OKAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LALALA)] =
    {
        .text = COMPOUND_STRING("LALALA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAY)] =
    {
        .text = COMPOUND_STRING("YAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWW)] =
    {
        .text = COMPOUND_STRING("AWW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOWEE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOWEE)] =
    {
        .text = COMPOUND_STRING("WOWEE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WROOOAAR_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAH)] =
    {
        .text = COMPOUND_STRING("GWAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAHAHAHA)] =
    {
        .text = COMPOUND_STRING("WAHAHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YUP),
        .enabled = TRUE,
    },
};
