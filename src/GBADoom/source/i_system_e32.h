// PsionDoomApp.h
//
// Copyright 17/02/2019 
//

#ifndef HEADER_ISYSTEME32
#define HEADER_ISYSTEME32


#ifdef __cplusplus
extern "C" {
#endif


void I_InitScreen_e32();

void I_CreateBackBuffer_e32();

int I_GetVideoWidth_e32();

int I_GetVideoHeight_e32();

void I_FinishUpdate_e32(const byte* srcBuffer, const byte* pallete, const unsigned int width, const unsigned int height);

void I_SetPallete_e32(const byte* pallete);

void I_ProcessKeyEvents();

int I_GetTime_e32(void);

void I_Error (const char *error, ...);

void I_Quit_e32();

unsigned short* I_GetBackBuffer();

#ifdef __cplusplus
}
#endif


#endif
