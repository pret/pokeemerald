#include "global.h"

#include "main.h"

enum
{
   RFU_RESET = 0x10,
   RFU_LINK_STATUS,
   RFU_VERSION_STATUS,
   RFU_SYSTEM_STATUS,
   RFU_SLOT_STATUS,
   RFU_CONFIG_STATUS,
   RFU_GAME_CONFIG,
   RFU_SYSTEM_CONFIG,
   RFU_UNK18,
   RFU_SC_START,
   RFU_SC_POLLING,
   RFU_SC_END,
   RFU_SP_START,
   RFU_SP_POLLING,
   RFU_SP_END,
   RFU_CP_START,
   RFU_CP_POLLING,
   RFU_CP_END
};

typedef struct RfuStruct
{
   s32 unk_0;
   u8 unk_4;
   u8 unk_5;
   u8 unk_6;
   u8 unk_7;
   u8 unk_8;
   u8 unk_9;
   u8 timerSelect;
   u8 unk_b;
   u32 unk_c;
   vu8 unk_10;
   u8 unk_11;
   vu16 unk_12;
   vu8 msMode;
   u8 unk_15;
   u8 unk_16;
   u8 unk_17;
   void * callbackM;
   void * callbackS;
   u32 callbackID;
   u8 * unk_24;
   void * unk_28;
   vu8 unk_2c;
   u8 padding[3];
} RfuStruct;

typedef struct RfuIntrStruct
{
   u8 unk28Data[0x74];
   u8 unk24Data[0x74];
   u8 block1[0x960];
   u8 block2[0x30];
} RfuIntrStruct;

typedef struct RfuState
{
   RfuStruct *rfuStruct;
} RfuState;

extern IntrFunc IntrSIO32();
extern struct RfuState gRfuState;
void STWI_init_Callback_M();
void STWI_init_Callback_S();
void STWI_set_Callback_M(void * callback);
void STWI_set_Callback_S(void * callback);
u16 STWI_init(u8 request);
int STWI_start_Command();
extern void STWI_intr_timer();

void STWI_init_all(RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam)
{
   struct RfuStruct *rfuStructTemp;
   struct RfuStruct **rfuStructPtr;
   u16 ime_temp;
   int ret;
   
   // If we're copying our interrupt into RAM, DMA it to block1 and use
   // block2 for our RfuStruct, otherwise block1 holds the RfuStruct.
   // interrupt usually is a pointer to gIntrTable[1]
   if (copyInterruptToRam == TRUE)
   {
      *interrupt = (IntrFunc)(&interruptStruct->block1);
      DmaCopy16(3, &IntrSIO32, (void*)(&interruptStruct->block1), 0x960);
      
      gRfuState.rfuStruct = (struct RfuStruct*)(&interruptStruct->block2);
   }
   else
   {
      *interrupt = (IntrFunc)&IntrSIO32;
      gRfuState.rfuStruct = (struct RfuStruct*)(&interruptStruct->block1);
   }
   
   rfuStructPtr = (struct RfuStruct**)&gRfuState.rfuStruct;
   (*rfuStructPtr)->unk_28 = (void*)&interruptStruct->unk28Data;
   (*rfuStructPtr)->unk_24 = (u8*)(&interruptStruct->unk24Data);
   (*rfuStructPtr)->msMode = 1;
   
   (*rfuStructPtr)->unk_0 = 0;
   (*rfuStructPtr)->unk_4 = 0;
   (*rfuStructPtr)->unk_5 = 0;
   (*rfuStructPtr)->unk_7 = 0;
   (*rfuStructPtr)->unk_8 = 0;
   (*rfuStructPtr)->unk_9 = 0;
   (*rfuStructPtr)->unk_c = 0;
   (*rfuStructPtr)->unk_10 = 0;
   
   // Don't @ me
   rfuStructTemp = *rfuStructPtr;
   rfuStructTemp->unk_12 = 0;
   rfuStructTemp->unk_15 = 0;

   (*rfuStructPtr)->unk_2c = 0;
   
   REG_RCNT = 0x100; //TODO: mystery bit?
   REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
   STWI_init_Callback_M();
   STWI_init_Callback_S();
   
   IntrEnable(INTR_FLAG_SERIAL);
}

void STWI_init_timer(IntrFunc *interrupt, int timerSelect)
{
   *interrupt = &STWI_intr_timer;
   gRfuState.rfuStruct->timerSelect = timerSelect;
   
   IntrEnable(INTR_FLAG_TIMER0 << gRfuState.rfuStruct->timerSelect); 
}

void AgbRFU_SoftReset()
{
   struct RfuStruct **rfuStructPtr;
   struct RfuStruct *rfuStructTemp;

   REG_RCNT = 0x8000;
   REG_RCNT = 0x80A0; // all these bits are undocumented
   
   {
      vu16 *timerL = &REG_TMCNT_L(gRfuState.rfuStruct->timerSelect);
      vu16 *timerH = &REG_TMCNT_H(gRfuState.rfuStruct->timerSelect);

      *timerH = 0;
      *timerL = 0;
      *timerH = 0x83;
      
      while (*timerL <= 0x11)
      {
         REG_RCNT = 0x80A2;
      }
      
      *timerH = 3;
   }
   REG_RCNT = 0x80A0;
   REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
   
   rfuStructPtr = (struct RfuStruct**)&gRfuState.rfuStruct;
   
   (*rfuStructPtr)->unk_0 = 0;
   (*rfuStructPtr)->unk_4 = 0;
   (*rfuStructPtr)->unk_5 = 0;
   (*rfuStructPtr)->unk_6 = 0;
   (*rfuStructPtr)->unk_7 = 0;
   (*rfuStructPtr)->unk_8 = 0;
   (*rfuStructPtr)->unk_9 = 0;
   (*rfuStructPtr)->unk_c = 0;
   (*rfuStructPtr)->unk_10 = 0;
   
   // Yeah this is the second time, there's probably something in the struct that I'm missing
   rfuStructTemp = *rfuStructPtr;
   rfuStructTemp->unk_12 = 0;
   rfuStructTemp->msMode = 1;
   (*rfuStructPtr)->unk_15 = 0;

   (*rfuStructPtr)->unk_2c = 0;
}

void STWI_set_MS_mode(u8 mode)
{
   gRfuState.rfuStruct->msMode = mode;
}

u32 STWI_read_status(u8 index)
{
   int result;
   switch(index)
   {
      case 0:
         return gRfuState.rfuStruct->unk_12;
      case 1:
         return gRfuState.rfuStruct->msMode;
      case 2:
         // something got inlined here?
         //TODO: figure this one out
         result = (gRfuState.rfuStruct->unk_0);
         __asm__("lsl r0, r0, #16");
         __asm__("lsr r0, r0, #16");
         break;
         
      case 3:
         return gRfuState.rfuStruct->unk_6;
         break;
      default:
         return 0xFFFF;
         break;
   }
   return result;
}

void STWI_init_Callback_M()
{
   STWI_set_Callback_M(0);
}

void STWI_init_Callback_S()
{
   STWI_set_Callback_S(0);
}

void STWI_set_Callback_M(void * callback)
{
   gRfuState.rfuStruct->callbackM = callback;
}

void STWI_set_Callback_S(void * callback)
{
   gRfuState.rfuStruct->callbackS = callback;
}

void STWI_set_Callback_ID(u32 id)
{
   gRfuState.rfuStruct->callbackID = id;
}

u16 STWI_poll_CommandEnd()
{
   while ( gRfuState.rfuStruct->unk_2c == TRUE );

   return gRfuState.rfuStruct->unk_12;
}

void STWI_send_ResetREQ()
{
   if (!STWI_init(RFU_RESET))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_LinkStatusREQ()
{
   if (!STWI_init(RFU_LINK_STATUS))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_VersionStatusREQ()
{
   if (!STWI_init(RFU_VERSION_STATUS))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SystemStatusREQ()
{
   if (!STWI_init(RFU_SYSTEM_STATUS))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SlotStatusREQ()
{
   if (!STWI_init(RFU_SLOT_STATUS))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_ConfigStatusREQ()
{
   if (!STWI_init(RFU_CONFIG_STATUS))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_GameConfigREQ(u8 * unk1, u8 *data)
{
   u8 *v5;
   int i;

   if (!STWI_init(RFU_GAME_CONFIG))
   {
      gRfuState.rfuStruct->unk_4 = 6; //TODO: what is 6

      //TODO: kinda gross but idk what's going on here
      v5 = (u8*)gRfuState.rfuStruct->unk_24;
      v5 += 4;
      *(u16*)v5 = *(u16*)unk1;

      v5 += 2;
      unk1 += 2;
      i = 13;
      do
      {
         *v5 = *unk1;
         v5++;
         unk1++;
         i--;
      }
      while(i >= 0);

      i = 7;
      do
      {
         *v5 = *data;
         v5++;
         data++;
         i--;
      }
      while(i >= 0);

      STWI_start_Command();
   }
}

void STWI_send_SystemConfigREQ(u16 unk1, u8 unk2, u8 unk3)
{
   u8 *v5;

   if (!STWI_init(RFU_SYSTEM_CONFIG))
   {
      gRfuState.rfuStruct->unk_4 = 1; //TODO: what is 1

      //TODO: kinda weird but idk what's going on here
      v5 = (u8*)gRfuState.rfuStruct->unk_24;
      v5 += 4;

      *v5++ = unk3;
      *v5++ = unk2;
      *(u16*)v5 = unk1;
      STWI_start_Command();
   }
}

void STWI_send_SC_StartREQ()
{
   if (!STWI_init(RFU_SC_START))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SC_PollingREQ()
{
   if (!STWI_init(RFU_SC_POLLING))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SC_EndREQ()
{
   if (!STWI_init(RFU_SC_END))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SP_StartREQ()
{
   if (!STWI_init(RFU_SP_START))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SP_PollingREQ()
{
   if (!STWI_init(RFU_SP_POLLING))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_SP_EndREQ()
{
   if (!STWI_init(RFU_SP_END))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_CP_StartREQ(u16 unk1)
{
   if (!STWI_init(RFU_CP_START))
   {
      gRfuState.rfuStruct->unk_4 = 1;
      *(u32*)(gRfuState.rfuStruct->unk_24 + 4) = unk1;
      STWI_start_Command();
   }
}

void STWI_send_CP_PollingREQ()
{
   if (!STWI_init(RFU_CP_POLLING))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

void STWI_send_CP_EndREQ()
{
   if (!STWI_init(RFU_CP_END))
   {
      gRfuState.rfuStruct->unk_4 = 0;
      STWI_start_Command();
   }
}

