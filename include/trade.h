#ifndef GUARD_TRADE_H
#define GUARD_TRADE_H

#include "link_rfu.h"

// Exported type declarations

// Exported RAM declarations
extern struct MailStruct gUnknown_020321C0[PARTY_SIZE];
extern u8 gUnknown_02032298[2];

// Exported ROM declarations
extern const struct WindowTemplate gUnknown_0833900C;

s32 sub_807A728(void);
void sub_80773AC(void);
void sub_807AE50(void);
int sub_807A8D0(struct UnkLinkRfuStruct_02022B14Substruct a0, u16, u16, u8);
int sub_807A7E0(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 a2, u16 a3, u8 a4, u16 a5, u8 a6);
int sub_807A918(struct Pokemon*, u16);
void sub_807B140(void);
void sub_807B154(void);
void sub_807F19C(void);
void sub_807F1A8(u8, const u8 *, u8);

#endif //GUARD_TRADE_H
