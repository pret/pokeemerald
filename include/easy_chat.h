#ifndef GUARD_EASYCHAT_H
#define GUARD_EASYCHAT_H

void InitEasyChatPhrases(void);
void easy_chat_input_maybe(void);
u8 * CopyEasyChatWord(u8 *dest, u16 word);
bool32 sub_811F8D8(u16 word);
void InitializeEasyChatWordArray(u16 *words, u16 length);
void ConvertEasyChatWordsToString(u8 *dest, const u16 *src, u16 length1, u16 length2);
bool8 ECWord_CheckIfOutsideOfValidRange(u16 word);
u16 sub_811EE38(u16 group);
u16 sub_811F01C(void);
bool16 EasyChat_GetNumWordsInGroup(u8);
u16 sub_811EE90(u16);

#endif // GUARD_EASYCHAT_H
