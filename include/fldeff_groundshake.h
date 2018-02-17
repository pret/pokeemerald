#ifndef GUARD_FLDEFF_GROUNDSHAKE_H
#define GUARD_FLDEFF_GROUNDSHAKE_H

struct InnerStruct203CF18
{
    u8 filler[0xC4];
};


struct Struct203CF18 {
    u8 taskId;
    struct InnerStruct203CF18 unk4;
}; //size = 0xC8


void sub_8151B68(struct InnerStruct203CF18 *, const u8*);
void sub_8151B3C(struct InnerStruct203CF18 *);
void sub_8151CA8(struct InnerStruct203CF18 *, u8, u8);
void sub_8151C50(struct InnerStruct203CF18 *, u8, u8);
void sub_8151D28(struct InnerStruct203CF18 *, u8, u8);
void sub_8151E50(struct InnerStruct203CF18 *);

void sub_81BE6B8(void);
void sub_81BE72C(void);
void sub_81BE808(u8 taskId);
void sub_81BE900(u8 taskId);
void sub_81BE968(void);
void sub_81BE9C0(u8 taskId);
void sub_81BEA00(u8 taskId);
void sub_81BEA20(void);


extern struct Struct203CF18 *gUnknown_0203CF18;
extern const u16 gUnknown_08617D64[];
extern const u8 gUnknown_08617E18[];

#endif // GUARD_FLDEFF_GROUNDSHAKE_H
