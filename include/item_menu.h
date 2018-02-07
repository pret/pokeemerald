#ifndef GUARD_item_menu_H
#define GUARD_item_menu_H

// Exported type declarations
struct BagStruct
{
    void *func;
    u8 unk4;
    u8 pocket;
    u8 unk6[2];
    u16 unk8[5];
    u16 unk12[5];
    void *unk1C;
};

extern struct BagStruct gUnknown_0203CE58;

// Exported RAM declarations

// Exported ROM declarations
void sub_81AAC50(void);
void sub_81AAC70(void);
void bag_menu_mail_related(void);

#endif //GUARD_item_menu_H
