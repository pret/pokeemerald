#include "global.h"

extern u8 gDma3ManagerLocked;
extern u8 gDma3RequestCursor;

struct DmaRequestsStruct
{
 /* 0x00 */ u8 *src;
 /* 0x04 */ u8 *dest;
 /* 0x08 */ u16 size;
 /* 0x0A */ u16 mode;
 /* 0x0C */ u8 fillerA[0x4];
}; // size is 0x20

extern struct DmaRequestsStruct gDma3Requests[];

void ClearDma3Requests(void)
{
	int i;

	gDma3ManagerLocked = TRUE;
	gDma3RequestCursor = FALSE;

	for(i = 0; i < 0x80; i++)
	{
		gDma3Requests[i].size = 0;
		gDma3Requests[i].src = 0;
		gDma3Requests[i].dest = 0;
	}
	
	gDma3ManagerLocked = FALSE;
}

/*void ProcessDma3Requests(void)
{
	if(!gDma3ManagerLocked && gDma3Requests[gDma3RequestCursor].size) // is the current DMA request unlocked and exists?
	{
		// _08000C1E
		do
		{
			// _08000C2E
			if(gDma3Requests[gDma3RequestCursor].size > 0xA000 || REG_VCOUNT > 0xE0)
				return;
			
			switch(gDma3Requests[gDma3RequestCursor].mode)
			{
				case 1: // _08000C8C
					if(gDma3Requests[gDma3RequestCursor].size < 0x1000)
					{
						
					}
				case 2: // _08000CD0
					
				case 3: // _08000D3C
					
				case 4: // _08000D88
					
			}
			// _08000DF0 (possible default case)
		}
		while(gDma3Requests[gDma3RequestCursor].size);
	}
}*/
