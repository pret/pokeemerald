#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

extern EWRAM_DATA struct ItemSlot gUnknown_02039F80[3];

enum
{
    MART_TYPE_0, // normal mart
    MART_TYPE_1,
    MART_TYPE_2,
};

struct MartInfo
{
    /*0x0*/ void (* callback) (void);
    /*0x4*/ const struct MenuAction *menuActions;
    /*0x8*/ const u16 *itemList;
    /*0xC*/ u16 itemCount;
    /*0xE*/ u8 windowId;
    /*0xF*/ u8 martType;
};

struct BuyMenuLabel
{
	u8 label[16];
};

struct ShopData
{
	/*0x0000*/ u8 tilemapBuffers[4][0x800];
	/*0x2000*/ u8 filler2000[0x4];
	/*0x2004*/ u16 unk2004;
	/*0x2006*/ u8 filler2006[0x2];
	/*0x2008*/ u16 unk2008;
	/*0x200A*/ u8 filler200A;
	/*0x200B*/ u8 scrollIndicatorsTaskId;
	/*0x200C*/ u8 unk200C;
	/*0x200D*/ u8 unk200D[2];
	/*0x200F*/ u8 filler200F[0xA1];
};

void CreatePokemartMenu(const u16 *);
void CreateDecorationShop1Menu(const u16 *);
void CreateDecorationShop2Menu(const u16 *);
void CB2_ExitSellMenu(void);

#endif // GUARD_SHOP_H
