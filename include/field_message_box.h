#ifndef GUARD_FIELD_MESSAGE_BOX_H
#define GUARD_FIELD_MESSAGE_BOX_H

bool8 ShowFieldMessage(const u8 *message);
bool8 sub_8098238(const u8 *message);
bool8 ShowFieldAutoScrollMessage(const u8 *message);
void HideFieldMessageBox(void);
bool8 IsFieldMessageBoxHidden(void);

#endif // GUARD_FIELD_MESSAGE_BOX_H
