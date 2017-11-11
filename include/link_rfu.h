#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
u32 sub_800BEC0(void);
void sub_800E700(void);
void sub_800EDD4(void);
bool32 sub_800F7E4(void);
void sub_800F804(void);
void sub_800F850(void);
void Rfu_set_zero(void);
u8 sub_80104F4(void);
u8 rfu_get_multiplayer_id(void);
bool32 sub_800FE84(const void *src, size_t size);
bool8 sub_8010100(u8 a0);
bool8 sub_8010500(void);
u8 sub_800FCD8(void);
void sub_800F6FC(u8 who);

#endif //GUARD_LINK_RFU_H
