    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

	.align 2

gText_EasyChatKeyboard_ABCDEFothers:: @ 862B810
	.string "{CLEAR 11}A{CLEAR 6}B{CLEAR 6}C{CLEAR 26}D{CLEAR 6}E{CLEAR 6}F{CLEAR 26}others$"

gText_EasyChatKeyboard_GHIJKL:: @ 862B832
	.string "{CLEAR 11}G{CLEAR 6}H{CLEAR 6}I{CLEAR 26}J{CLEAR 6}K{CLEAR 6}L$"

gText_EasyChatKeyboard_MNOPQRS:: @ 862B84B
	.string "{CLEAR 11}M{CLEAR 6}N{CLEAR 6}O{CLEAR 26}P{CLEAR 6}Q{CLEAR 6}R{CLEAR 6}S{CLEAR 26} $"

gText_EasyChatKeyboard_TUVWXYZ:: @ 862B86C
	.string "{CLEAR 11}T{CLEAR 6}U{CLEAR 6}V{CLEAR 26}W{CLEAR 6}X{CLEAR 6}Y{CLEAR 6}Z{CLEAR 26} $"

gText_NamingScreenKeyboard_abcdef:: @ 862B88D
	.string "{CLEAR 11}a{CLEAR 6}b{CLEAR 6}c{CLEAR 26}d{CLEAR 6}e{CLEAR 6}f{CLEAR 6} {CLEAR 30}.$"

gText_NamingScreenKeyboard_ghijkl:: @ 862B8AE
	.string "{CLEAR 11}g{CLEAR 6}h{CLEAR 7}i{CLEAR 27}j{CLEAR 7}k{CLEAR 7}l{CLEAR 7} {CLEAR 30},$"

gText_NamingScreenKeyboard_mnopqrs:: @ 862B8CF
	.string "{CLEAR 11}m{CLEAR 6}n{CLEAR 6}o{CLEAR 26}p{CLEAR 6}q{CLEAR 7}r{CLEAR 6}s{CLEAR 27} $"

gText_NamingScreenKeyboard_tuvwxyz:: @ 862B8F0
	.string "{CLEAR 11}t{CLEAR 6}u{CLEAR 6}v{CLEAR 26}w{CLEAR 6}x{CLEAR 6}y{CLEAR 6}z{CLEAR 26} $"

gText_NamingScreenKeyboard_ABCDEF:: @ 862B911
	.string "{CLEAR 11}A{CLEAR 6}B{CLEAR 6}C{CLEAR 26}D{CLEAR 6}E{CLEAR 6}F{CLEAR 6} {CLEAR 30}.$"

gText_NamingScreenKeyboard_GHIJKL:: @ 862B932
	.string "{CLEAR 11}G{CLEAR 6}H{CLEAR 6}I{CLEAR 26}J{CLEAR 6}K{CLEAR 6}L{CLEAR 6} {CLEAR 30},$"

gText_NamingScreenKeyboard_MNOPQRS:: @ 862B953
	.string "{CLEAR 11}M{CLEAR 6}N{CLEAR 6}O{CLEAR 26}P{CLEAR 6}Q{CLEAR 6}R{CLEAR 6}S{CLEAR 26} $"

gText_NamingScreenKeyboard_TUVWXYZ:: @ 862B974
	.string "{CLEAR 11}T{CLEAR 6}U{CLEAR 6}V{CLEAR 26}W{CLEAR 6}X{CLEAR 6}Y{CLEAR 6}Z{CLEAR 26} $"

gText_NamingScreenKeyboard_01234:: @ 862B995
	.string "{CLEAR 11}0{CLEAR 16}1{CLEAR 16}2{CLEAR 16}3{CLEAR 16}4{CLEAR 16} $"

gText_NamingScreenKeyboard_56789:: @ 862B9AE
	.string "{CLEAR 11}5{CLEAR 16}6{CLEAR 16}7{CLEAR 16}8{CLEAR 16}9{CLEAR 16} $"
 
gText_NamingScreenKeyboard_Symbols1:: @ 862B9C7
	.string "{CLEAR 12}!{CLEAR 17}?{CLEAR 16}♂{CLEAR 16}♀{CLEAR 16}/{CLEAR 17}-$"
	
gText_NamingScreenKeyboard_Symbols2:: @ 862B9E0
	.string "{CLEAR 11}…{CLEAR 16}“{CLEAR 16}”{CLEAR 18}‘{CLEAR 19}'{CLEAR 18} $"

gText_UnionRoomChatKeyboard_ABCDE:: @ 862B9F9
    .string "ABCDE$"

gText_UnionRoomChatKeyboard_FGHIJ:: @ 862B9FF
    .string "FGHIJ$"

gText_UnionRoomChatKeyboard_KLMNO:: @ 862BA05
    .string "KLMNO$"

gText_UnionRoomChatKeyboard_PQRST:: @ 862BA0B
    .string "PQRST$"

gText_UnionRoomChatKeyboard_UVWXY:: @ 862BA11
    .string "UVWXY$"

gText_UnionRoomChatKeyboard_Z:: @ 862BA17
    .string "Z    $"

gText_UnionRoomChatKeyboard_01234Upper:: @ 862BA1D
    .string "01234$"

gText_UnionRoomChatKeyboard_56789Upper:: @ 862BA23
    .string "56789$"

gText_UnionRoomChatKeyboard_PunctuationUpper:: @ 862BA29
    .string ".,!? $"

gText_UnionRoomChatKeyboard_SymbolsUpper:: @ 862BA2F
    .string "-/&… $"

gText_UnionRoomChatKeyboard_abcde:: @ 862BA35
    .string "abcde$"

gText_UnionRoomChatKeyboard_fghij:: @ 862BA3B
    .string "fghij$"

gText_UnionRoomChatKeyboard_klmno:: @ 862BA41
    .string "klmno$"

gText_UnionRoomChatKeyboard_pqrst:: @ 862BA47
    .string "pqrst$"

gText_UnionRoomChatKeyboard_uvwxy:: @ 862BA4D
    .string "uvwxy$"

gText_UnionRoomChatKeyboard_z:: @ 862BA53
    .string "z    $"

gText_UnionRoomChatKeyboard_01234Lower:: @ 862BA59
    .string "01234$"

gText_UnionRoomChatKeyboard_56789Lower:: @ 862BA5F
    .string "56789$"

gText_UnionRoomChatKeyboard_PunctuationLower:: @ 862BA65
    .string ".,!? $"

gText_UnionRoomChatKeyboard_SymbolsLower:: @ 862BA6B
    .string "-/&… $"

    .string "$$$$$$$$"

gText_UnionRoomChatKeyboard_Emoji1:: @ 862BA79
    .string "{EMOJI_MISCHIEVOUS}{EMOJI_HAPPY}{EMOJI_ANGRY}{EMOJI_SURPRISED}{EMOJI_BIGANGER}$"

gText_UnionRoomChatKeyboard_Emoji2:: @ 862BA84
    .string "{EMOJI_BIGSMILE}{EMOJI_EVIL}{EMOJI_NEUTRAL}{EMOJI_TIRED}{EMOJI_SHOCKED}$"

gText_UnionRoomChatKeyboard_Emoji3:: @ 862BA8F
    .string "{EMOJI_LEAF}{EMOJI_FIRE}{EMOJI_WATER}{EMOJI_BOLT}{EMOJI_BALL}$"

gText_UnionRoomChatKeyboard_Emoji4:: @ 862BA9A
    .string "♂♀{EMOJI_LEFT_PAREN}{EMOJI_RIGHT_PAREN}{EMOJI_TILDE}$"

gText_UnionRoomChatKeyboard_Emoji5:: @ 862BAA3
    .string "{EMOJI_LEFT_EYE}{EMOJI_RIGHT_EYE}{EMOJI_SMALLWHEEL}{EMOJI_SPHERE}{EMOJI_IRRITATED}$"

gText_UnionRoomChatKeyboard_Emoji6:: @ 862BAAE
    .string "{EMOJI_AT}{EMOJI_BIGWHEEL}{EMOJI_TONGUE}{EMOJI_ACUTE}{EMOJI_GRAVE}$"

gText_UnionRoomChatKeyboard_Emoji7:: @ 862BAB9
    .string "{EMOJI_RIGHT_FIST}{EMOJI_LEFT_FIST}{EMOJI_TRIANGLE_OUTLINE}{EMOJI_UNION}{EMOJI_GREATER_THAN}$"

gText_UnionRoomChatKeyboard_Emoji8:: @ 862BAC4
    .string "{EMOJI_CIRCLE}{EMOJI_TRIANGLE}{EMOJI_SQUARE}{EMOJI_HEART}{EMOJI_MOON}$"

gText_UnionRoomChatKeyboard_Emoji9:: @ 862BACF
    .string "{EMOJI_NOTE}{EMOJI_PLUS}{EMOJI_MINUS}{EMOJI_EQUALS}{EMOJI_PIPE}$"

gText_UnionRoomChatKeyboard_Emoji10:: @ 862BADA
    .string "{EMOJI_HIGHBAR}{EMOJI_UNDERSCORE};: $"
