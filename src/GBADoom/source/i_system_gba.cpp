#include <stdarg.h>
#include <stdio.h>
#include <cstring>

//#define __arm__

#ifdef __arm__

extern "C"
{
    #include "doomdef.h"
    #include "doomtype.h"
    #include "d_main.h"
    #include "d_event.h"

    #include "global_data.h"

    #include "tables.h"
}

#include "i_system_e32.h"

#include "lprintf.h"

#include <gba.h>
#include <gba_input.h>
#include <gba_timers.h>

#include <maxmod.h>

#define DCNT_PAGE 0x0010

#define VID_PAGE1 VRAM
#define VID_PAGE2 0x600A000

#define TM_FREQ_1024 0x0003
#define TM_ENABLE 0x0080
#define TM_CASCADE 0x0004
#define TM_FREQ_1024 0x0003
#define TM_FREQ_256 0x0002

#define REG_WAITCNT	*((vu16 *)(0x4000204))


//**************************************************************************************


//*******************************************************************************
//VBlank handler.
//*******************************************************************************

void VBlankCallback()
{
    mmVBlank();
    mmFrame();
}


void I_InitScreen_e32()
{
    irqInit();

    irqSet( IRQ_VBLANK, VBlankCallback );
    irqEnable(IRQ_VBLANK);


    //Set gamepak wait states and prefetch.
    REG_WAITCNT = 0x46DA;

    consoleDemoInit();

    REG_TM2CNT_L= 65535-1872;     // 1872 ticks = 1/35 secs
    REG_TM2CNT_H = TM_FREQ_256 | TM_ENABLE;       // we're using the 256 cycle timer

    // cascade into tm3
    REG_TM3CNT_H = TM_CASCADE | TM_ENABLE;
}

//**************************************************************************************

void I_BlitScreenBmp_e32()
{

}

//**************************************************************************************

void I_StartWServEvents_e32()
{

}

//**************************************************************************************

void I_PollWServEvents_e32()
{
    scanKeys();

    u16 key_down = keysDown();

    event_t ev;

    if(key_down)
    {
        ev.type = ev_keydown;

        if(key_down & KEY_UP)
        {
            ev.data1 = KEYD_UP;
            D_PostEvent(&ev);
        }
        else if(key_down & KEY_DOWN)
        {
            ev.data1 = KEYD_DOWN;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_LEFT)
        {
            ev.data1 = KEYD_LEFT;
            D_PostEvent(&ev);
        }
        else if(key_down & KEY_RIGHT)
        {
            ev.data1 = KEYD_RIGHT;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_SELECT)
        {
            ev.data1 = KEYD_SELECT;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_START)
        {
            ev.data1 = KEYD_START;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_A)
        {
            ev.data1 = KEYD_A;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_B)
        {
            ev.data1 = KEYD_B;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_L)
        {
            ev.data1 = KEYD_L;
            D_PostEvent(&ev);
        }

        if(key_down & KEY_R)
        {
            ev.data1 = KEYD_R;
            D_PostEvent(&ev);
        }
    }

    u16 key_up = keysUp();

    if(key_up)
    {
        ev.type = ev_keyup;

        if(key_up & KEY_UP)
        {
            ev.data1 = KEYD_UP;
            D_PostEvent(&ev);
        }
        else if(key_up & KEY_DOWN)
        {
            ev.data1 = KEYD_DOWN;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_LEFT)
        {
            ev.data1 = KEYD_LEFT;
            D_PostEvent(&ev);
        }
        else if(key_up & KEY_RIGHT)
        {
            ev.data1 = KEYD_RIGHT;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_SELECT)
        {
            ev.data1 = KEYD_SELECT;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_START)
        {
            ev.data1 = KEYD_START;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_A)
        {
            ev.data1 = KEYD_A;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_B)
        {
            ev.data1 = KEYD_B;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_L)
        {
            ev.data1 = KEYD_L;
            D_PostEvent(&ev);
        }

        if(key_up & KEY_R)
        {
            ev.data1 = KEYD_R;
            D_PostEvent(&ev);
        }
    }
}

//**************************************************************************************

void I_ClearWindow_e32()
{

}

//**************************************************************************************

unsigned short* I_GetBackBuffer()
{
    if(REG_DISPCNT & DCNT_PAGE)
        return (unsigned short*)VID_PAGE1;

    return (unsigned short*)VID_PAGE2;
}

//**************************************************************************************

void I_CreateWindow_e32()
{

    //Bit5 = unlocked vram at h-blank.
    SetMode(MODE_4 | BG2_ENABLE | BIT(5));

    unsigned short* bb = I_GetBackBuffer();

    memset(bb, 0, 240*160);

    I_FinishUpdate_e32(NULL, NULL, 0, 0);

    bb = I_GetBackBuffer();

    memset(bb, 0, 240*160);

    I_FinishUpdate_e32(NULL, NULL, 0, 0);

}

//**************************************************************************************

void I_CreateBackBuffer_e32()
{
    I_CreateWindow_e32();
}

//**************************************************************************************

void I_FinishUpdate_e32(const byte* srcBuffer, const byte* pallete, const unsigned int width, const unsigned int height)
{
    REG_DISPCNT ^= DCNT_PAGE;
}

//**************************************************************************************

void I_SetPallete_e32(const byte* pallete)
{
    unsigned short* pal_ram = (unsigned short*)0x5000000;

    for(int i = 0; i< 256; i++)
    {
        unsigned int r = *pallete++;
        unsigned int g = *pallete++;
        unsigned int b = *pallete++;

        pal_ram[i] = RGB5(r >> 3, g >> 3, b >> 3);
    }
}

//**************************************************************************************

int I_GetVideoWidth_e32()
{
    return 120;
}

//**************************************************************************************

int I_GetVideoHeight_e32()
{
    return 160;
}



//**************************************************************************************

void I_ProcessKeyEvents()
{
    I_PollWServEvents_e32();
}

//**************************************************************************************

#define MAX_MESSAGE_SIZE 1024

void I_Error (const char *error, ...)
{
    consoleDemoInit();

    char msg[MAX_MESSAGE_SIZE];

    va_list v;
    va_start(v, error);

    vsprintf(msg, error, v);

    va_end(v);

    printf("%s", msg);

    while(true)
    {
        VBlankIntrWait();
    }
}

//**************************************************************************************

void I_Quit_e32()
{

}

//**************************************************************************************

#endif
