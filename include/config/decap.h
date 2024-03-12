#ifndef GUARD_CONFIG_DECAP_H
#define GUARD_CONFIG_DECAP_H

/*
Enable automatic decapitalization of *all* text
Exceptions:
- Several bigrams: TV, TM, HP, HM, PC, PP, PM
- Player names, nicknames, box names
- Strings beginning with {FIXED_CASE}
- C strings that use `_C` or `__C`
- ASM strings that use `.fixstr`
- If mirroring enabled, string addresses passed through MirrorPtr
*/
#define DECAP_ENABLED FALSE
// Enables signaling that a string's case should be preserved
// by *mirroring* its address: i.e 08xxxxxx to 0Axxxxxx
// Unless you are targeting a different platform than the GBA,
// there aren't many reasons to disable this
#define DECAP_MIRRORING TRUE

// If TRUE, *all* Pokemon nicknames and player names will be decapitalized.
// Otherwise, their case will be preserved. Default FALSE
#define DECAP_NICKNAMES     FALSE

#define DECAP_MAIN_MENU     TRUE // Main menu text.
#define DECAP_OPTION_MENU   TRUE // Option menu text.
#define DECAP_START_MENU    TRUE // Start menu options & Save menu text.
#define DECAP_PARTY_MENU    TRUE // Party menu text.
#define DECAP_MAP_NAMES     TRUE // Map and location names.
#define DECAP_EASY_CHAT     TRUE // Easy Chat words and interface.
#define DECAP_FIELD_MSG     TRUE // Field messages (including scripts!).
#define DECAP_SUMMARY       TRUE // Summary interface text.
#define DECAP_ITEM_NAMES    TRUE // Item names (obtained via ItemId_GetName).

#endif // GUARD_CONFIG_DECAP_H
