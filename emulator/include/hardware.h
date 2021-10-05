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

BYTE8 HWReadKeyboardPort(WORD16 addr);
int HWGetKeyboardRow(int row);
void HWSyncImplementation(LONG32 iCount);
WORD16 HWLoadFile(char * fileName,BYTE8 *target);

#ifdef LINUX
#define FILESEP '/'
#else
#define FILESEP '\\'
#endif

#endif