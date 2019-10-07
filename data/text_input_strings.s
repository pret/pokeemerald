    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

	.align 2

gText_EasyChatKeyboard_ABCDEFothers::
	.string "{CLEAR 11}A{CLEAR 6}B{CLEAR 6}C{CLEAR 26}D{CLEAR 6}E{CLEAR 6}F{CLEAR 26}others$"

gText_EasyChatKeyboard_GHIJKL::
	.string "{CLEAR 11}G{CLEAR 6}H{CLEAR 6}I{CLEAR 26}J{CLEAR 6}K{CLEAR 6}L$"

gText_EasyChatKeyboard_MNOPQRS::
	.string "{CLEAR 11}M{CLEAR 6}N{CLEAR 6}O{CLEAR 26}P{CLEAR 6}Q{CLEAR 6}R{CLEAR 6}S{CLEAR 26} $"

gText_EasyChatKeyboard_TUVWXYZ::
	.string "{CLEAR 11}T{CLEAR 6}U{CLEAR 6}V{CLEAR 26}W{CLEAR 6}X{CLEAR 6}Y{CLEAR 6}Z{CLEAR 26} $"

gText_NamingScreenKeyboard_abcdef::
	.string "1{CLEAR_TO 16}2{CLEAR_TO 32}3{CLEAR_TO 48}4{CLEAR_TO 64}5{CLEAR_TO 80}6{CLEAR_TO 96}7{CLEAR_TO 112}8{CLEAR_TO 128}9{CLEAR_TO 144}0$"

gText_NamingScreenKeyboard_ghijkl::
	.string "A{CLEAR_TO 16}B{CLEAR_TO 32}C{CLEAR_TO 48}D{CLEAR_TO 64}E{CLEAR_TO 80}F{CLEAR_TO 96}G{CLEAR_TO 112}H{CLEAR_TO 128}I{CLEAR_TO 144}J$"

gText_NamingScreenKeyboard_mnopqrs::
	.string "K{CLEAR_TO 16}L{CLEAR_TO 32}M{CLEAR_TO 48}N{CLEAR_TO 64}O{CLEAR_TO 80}P{CLEAR_TO 96}Q{CLEAR_TO 112}R{CLEAR_TO 128}S{CLEAR_TO 144}T$"

gText_NamingScreenKeyboard_tuvwxyz::
	.string "U{CLEAR_TO 16}V{CLEAR_TO 32}W{CLEAR_TO 48}X{CLEAR_TO 64}Y{CLEAR_TO 80}Z{CLEAR_TO 96}‘{CLEAR_TO 112}'{CLEAR_TO 128}“{CLEAR_TO 144}”$"

gText_NamingScreenKeyboard_ABCDEF::
	.string "ㅃ{CLEAR_TO 16}ㅉ{CLEAR_TO 32}ㄸ{CLEAR_TO 48}ㄲ{CLEAR_TO 64}ㅆ{CLEAR_TO 80}!{CLEAR_TO 96}?{CLEAR_TO 112}-{CLEAR_TO 128}ㅒ{CLEAR_TO 144}ㅖ$"

gText_NamingScreenKeyboard_GHIJKL::
	.string "ㅂ{CLEAR_TO 16}ㅈ{CLEAR_TO 32}ㄷ{CLEAR_TO 48}ㄱ{CLEAR_TO 64}ㅅ{CLEAR_TO 80}ㅛ{CLEAR_TO 96}ㅕ{CLEAR_TO 112}ㅑ{CLEAR_TO 128}ㅐ{CLEAR_TO 144}ㅔ$"

gText_NamingScreenKeyboard_MNOPQRS::
	.string "ㅁ{CLEAR_TO 16}ㄴ{CLEAR_TO 32}ㅇ{CLEAR_TO 48}ㄹ{CLEAR_TO 64}ㅎ{CLEAR_TO 80}ㅗ{CLEAR_TO 96}ㅓ{CLEAR_TO 112}ㅏ{CLEAR_TO 128}ㅣ{CLEAR_TO 144}/$"

gText_NamingScreenKeyboard_TUVWXYZ::
	.string "ㅋ{CLEAR_TO 16}ㅌ{CLEAR_TO 32}ㅊ{CLEAR_TO 48}ㅍ{CLEAR_TO 64}{CLEAR_TO 80}ㅠ{CLEAR_TO 96}ㅜ{CLEAR_TO 112}ㅡ{CLEAR_TO 128},{CLEAR_TO 144}.$"

gText_NamingScreenKeyboard_01234::
	.string "1{CLEAR_TO 16}2{CLEAR_TO 32}3{CLEAR_TO 48}4{CLEAR_TO 64}5{CLEAR_TO 80}6{CLEAR_TO 96}7{CLEAR_TO 112}8{CLEAR_TO 128}9{CLEAR_TO 144}0$"

gText_NamingScreenKeyboard_56789::
	.string "a{CLEAR_TO 16}b{CLEAR_TO 32}c{CLEAR_TO 48}d{CLEAR_TO 64}e{CLEAR_TO 80}f{CLEAR_TO 96}g{CLEAR_TO 112}h{CLEAR_TO 128}i{CLEAR_TO 144}j$"
 
gText_NamingScreenKeyboard_Symbols1::
	.string "k{CLEAR_TO 16}l{CLEAR_TO 32}m{CLEAR_TO 48}n{CLEAR_TO 64}o{CLEAR_TO 80}p{CLEAR_TO 96}q{CLEAR_TO 112}r{CLEAR_TO 128}s{CLEAR_TO 144}t$"
	
gText_NamingScreenKeyboard_Symbols2::
	.string "u{CLEAR_TO 16}v{CLEAR_TO 32}w{CLEAR_TO 48}x{CLEAR_TO 64}y{CLEAR_TO 80}z{CLEAR_TO 96}♂{CLEAR_TO 112}♀{CLEAR_TO 128}-{CLEAR_TO 144}·$"

gText_UnionRoomChatKeyboard_ABCDE::
    .string "ABCDE$"

gText_UnionRoomChatKeyboard_FGHIJ::
    .string "FGHIJ$"

gText_UnionRoomChatKeyboard_KLMNO::
    .string "KLMNO$"

gText_UnionRoomChatKeyboard_PQRST::
    .string "PQRST$"

gText_UnionRoomChatKeyboard_UVWXY::
    .string "UVWXY$"

gText_UnionRoomChatKeyboard_Z::
    .string "Z    $"

gText_UnionRoomChatKeyboard_01234Upper::
    .string "01234$"

gText_UnionRoomChatKeyboard_56789Upper::
    .string "56789$"

gText_UnionRoomChatKeyboard_PunctuationUpper::
    .string ".,!? $"

gText_UnionRoomChatKeyboard_SymbolsUpper::
    .string "-/&… $"

gText_UnionRoomChatKeyboard_abcde::
    .string "abcde$"

gText_UnionRoomChatKeyboard_fghij::
    .string "fghij$"

gText_UnionRoomChatKeyboard_klmno::
    .string "klmno$"

gText_UnionRoomChatKeyboard_pqrst::
    .string "pqrst$"

gText_UnionRoomChatKeyboard_uvwxy::
    .string "uvwxy$"

gText_UnionRoomChatKeyboard_z::
    .string "z    $"

gText_UnionRoomChatKeyboard_01234Lower::
    .string "01234$"

gText_UnionRoomChatKeyboard_56789Lower::
    .string "56789$"

gText_UnionRoomChatKeyboard_PunctuationLower::
    .string ".,!? $"

gText_UnionRoomChatKeyboard_SymbolsLower::
    .string "-/&… $"

    .string "$$$$$$$$"

gText_UnionRoomChatKeyboard_Emoji1::
    .string "{EMOJI_MISCHIEVOUS}{EMOJI_HAPPY}{EMOJI_ANGRY}{EMOJI_SURPRISED}{EMOJI_BIGANGER}$"

gText_UnionRoomChatKeyboard_Emoji2::
    .string "{EMOJI_BIGSMILE}{EMOJI_EVIL}{EMOJI_NEUTRAL}{EMOJI_TIRED}{EMOJI_SHOCKED}$"

gText_UnionRoomChatKeyboard_Emoji3::
    .string "{EMOJI_LEAF}{EMOJI_FIRE}{EMOJI_WATER}{EMOJI_BOLT}{EMOJI_BALL}$"

gText_UnionRoomChatKeyboard_Emoji4::
    .string "♂♀{EMOJI_LEFT_PAREN}{EMOJI_RIGHT_PAREN}{EMOJI_TILDE}$"

gText_UnionRoomChatKeyboard_Emoji5::
    .string "{EMOJI_LEFT_EYE}{EMOJI_RIGHT_EYE}{EMOJI_SMALLWHEEL}{EMOJI_SPHERE}{EMOJI_IRRITATED}$"

gText_UnionRoomChatKeyboard_Emoji6::
    .string "{EMOJI_AT}{EMOJI_BIGWHEEL}{EMOJI_TONGUE}{EMOJI_ACUTE}{EMOJI_GRAVE}$"

gText_UnionRoomChatKeyboard_Emoji7::
    .string "{EMOJI_RIGHT_FIST}{EMOJI_LEFT_FIST}{EMOJI_TRIANGLE_OUTLINE}{EMOJI_UNION}{EMOJI_GREATER_THAN}$"

gText_UnionRoomChatKeyboard_Emoji8::
    .string "{EMOJI_CIRCLE}{EMOJI_TRIANGLE}{EMOJI_SQUARE}{EMOJI_HEART}{EMOJI_MOON}$"

gText_UnionRoomChatKeyboard_Emoji9::
    .string "{EMOJI_NOTE}{EMOJI_PLUS}{EMOJI_MINUS}{EMOJI_EQUALS}{EMOJI_PIPE}$"

gText_UnionRoomChatKeyboard_Emoji10::
    .string "{EMOJI_HIGHBAR}{EMOJI_UNDERSCORE};: $"
