#ifndef GUARD_MULTIBOOT_H
#define GUARD_MULTIBOOT_H

#define MULTIBOOT_MASTER_INFO            0x62
#define MULTIBOOT_CLIENT_INFO            0x72
#define MULTIBOOT_MASTER_START_PROBE     0x61
#define MULTIBOOT_MASTER_REQUEST_DLREADY 0x63
#define MULTIBOOT_CLIENT_DLREADY         0x73
#define MULTIBOOT_MASTER_START_DL        0x64
#define MULTIBOOT_MASTER_REQUEST_CRC     0x65
#define MULTIBOOT_CLIENT_CALC_CRC        0x74
#define MULTIBOOT_CLIENT_CRCREADY        0x75
#define MULTIBOOT_MASTER_VERIFY_CRC      0x66

void MultiBootInit(struct MultiBootParam *mp);
int MultiBootMain(struct MultiBootParam *mp);
void MultiBootStartProbe(struct MultiBootParam *mp);
void MultiBootStartMaster(struct MultiBootParam *mp, const u8 *srcp, int length, u8 palette_color, s8 palette_speed);
int MultiBootCheckComplete(struct MultiBootParam *mp);

#endif // GUARD_MULTIBOOT_H
