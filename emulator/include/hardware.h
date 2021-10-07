// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.h
//		Purpose:	Hardware Emulation Header
//		Created:	30th September 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _HARDWARE_H
#define _HARDWARE_H

void HWReset(void);
void HWSync(void);
BYTE8 HWReadPort(WORD16 addr);
void HWWritePort(WORD16 addr,BYTE8 data);
void HWWriteControlLatch(BYTE8 data);
BYTE8 HWGetVideoMode(void);
BYTE8 *HWGetPalette(BYTE8 colour);
BYTE8 HWReadKeyboardPort(WORD16 addr);
int HWGetKeyboardRow(int row);
void HWSyncImplementation(LONG32 iCount);
void HWLoadProgram(void);
WORD16 HWLoadFile(char * fileName,WORD16 *startLoad,WORD16 *endLoad,BYTE8 *type);

#ifdef LINUX
#define FILESEP '/'
#else
#define FILESEP '\\'
#endif

#endif
