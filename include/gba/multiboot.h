#ifndef GUARD_GBA_MULTIBOOT_H
#define GUARD_GBA_MULTIBOOT_H

#define MULTIBOOT_NCHILD        3       // Maximum number of slaves
#define MULTIBOOT_HEADER_SIZE   0xc0    // Header size
#define MULTIBOOT_SEND_SIZE_MIN 0x100   // Minimum transmission size
#define MULTIBOOT_SEND_SIZE_MAX 0x40000 // Maximum transmission size

struct MultiBootParam
{
    u32 system_work[5]; // 00
    u8 handshake_data;  // 14
    //u8 padding;         // 15
    u16 handshake_timeout; // 16
    u8 probe_count; // 18
    u8 client_data[MULTIBOOT_NCHILD]; // 19
    u8 palette_data; // 1c
    u8 response_bit; // 1d
    u8 client_bit; // 1e
    u8 reserved1; // 1f
    const u8 *boot_srcp; // 20
    const u8 *boot_endp; // 24
    const u8 *masterp;
    u8 *reserved2[MULTIBOOT_NCHILD];
    u32 system_work2[4];
    u8 sendflag;
    u8 probe_target_bit;
    u8 check_wait;
    u8 server_type;
};

#define MULTIBOOT_ERROR_04                0x04
#define MULTIBOOT_ERROR_08                0x08
#define MULTIBOOT_ERROR_0c                0x0c
#define MULTIBOOT_ERROR_40                0x40
#define MULTIBOOT_ERROR_44                0x44
#define MULTIBOOT_ERROR_48                0x48
#define MULTIBOOT_ERROR_4c                0x4c
#define MULTIBOOT_ERROR_80                0x80
#define MULTIBOOT_ERROR_84                0x84
#define MULTIBOOT_ERROR_88                0x88
#define MULTIBOOT_ERROR_8c                0x8c
#define MULTIBOOT_ERROR_NO_PROBE_TARGET   0x50
#define MULTIBOOT_ERROR_NO_DLREADY        0x60
#define MULTIBOOT_ERROR_BOOT_FAILURE      0x70
#define MULTIBOOT_ERROR_HANDSHAKE_FAILURE 0x71

#define MULTIBOOT_CONNECTION_CHECK_WAIT 15

#define MULTIBOOT_SERVER_TYPE_NORMAL 0
#define MULTIBOOT_SERVER_TYPE_QUICK  1

#define MULTIBOOT_HANDSHAKE_TIMEOUT 400

#endif // GUARD_GBA_MULTIBOOT_H
