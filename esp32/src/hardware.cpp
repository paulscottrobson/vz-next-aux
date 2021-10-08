// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.c
//		Purpose:	Hardware Emulation
//		Created:	8th October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include "sys_processor.h"
#include "hardware.h"
#include "gfxkeys.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int lastControlWrite = 0;
static int lastToggleCycleTime = 0;
static int cycleToggleCount = 0;
static int cycleToggleTotal = 0;

//	Control 
//		20 Speaker B
// 		10 VDC Background colour (0=green,1 = orange/buff)
//		08 VDC Display Mode (0=text,1 = graphics)
//		04 Cassette out MSB
// 		02 Cassette out LSB
// 		01 Speaker A

// *******************************************************************************************************************************
//												Reset Hardware
// *******************************************************************************************************************************

void HWReset(void) {	
	HWXSetFrequency(0);
	lastToggleCycleTime = 0;
	lastControlWrite = 0;
}

// *******************************************************************************************************************************
//												  Reset CPU
// *******************************************************************************************************************************

void HWSync(void) {
	HWXSyncImplementation(0);
	if (lastToggleCycleTime != 0 && cycleToggleCount > 1) {
		int frequency = CYCLE_RATE /2*cycleToggleCount/cycleToggleTotal; 	// Counting both transitions
		HWXSetFrequency(frequency);
	} else {
		HWXSetFrequency(0);
	}
	lastToggleCycleTime = 0;
}

// *******************************************************************************************************************************
// 												 Program Loader
// *******************************************************************************************************************************

void HWLoadProgram(void) {
	char fileName[32];
	int ptr = 0x7A9D;
	int offset = 0;
	WORD16 startAddress,endAddress;
	BYTE8 fileType;

	while (CPUReadMemory(ptr+offset) != 0) {
		fileName[offset] = tolower(CPUReadMemory(ptr+offset));
		offset++;
	}
	if (offset == 0) {
		// Load directory into BASIC
		fileName[offset++] = 'a';
	}
	strcpy(fileName+offset,".vz");
	int err = HWXLoadFile(fileName,&startAddress,&endAddress,&fileType);
	if (fileType == 0xF1) CPUSetPC(startAddress);
	if (err) CPUSetPC(0x1E4A);

	CPUWriteMemory(0x78F9,endAddress & 0xFF);
	CPUWriteMemory(0x78FA,endAddress >> 8);
}

// *******************************************************************************************************************************
//													Latch write
// *******************************************************************************************************************************

void HWWriteControlLatch(BYTE8 data) {
	//
	// 		Check mode change or background change.
	//
	if ((data & 0x18) != (lastControlWrite & 0x18)) {
		// TODO: Refresh screen entirely on mode change.
	}
	//
	// 		Assume pushing and pulling :)
	//
	if ((data & 0x01) != (lastControlWrite & 0x01)) {
		if (lastToggleCycleTime == 0) {
			cycleToggleCount = 0;
			cycleToggleTotal = 0;
		} else {
			cycleToggleCount++;
			cycleToggleTotal += abs(lastToggleCycleTime - CPUGetCycles());
		}
		lastToggleCycleTime = CPUGetCycles();
	}
	lastControlWrite = data;
}

// *******************************************************************************************************************************
//												Port Read/Write
// *******************************************************************************************************************************

BYTE8 HWReadPort(WORD16 addr) {
	BYTE8 v = 0xFF;
	return v;
}

void HWWritePort(WORD16 addr,BYTE8 data) {
	BYTE8 port = addr & 0xFF;
}

// *******************************************************************************************************************************
//														Read Keyboard lines
// *******************************************************************************************************************************

static BYTE8 HWForceKey(WORD16 addr,BYTE8 v,int unshifted,int shifted,int controlled);
static BYTE8 _HWUpdateKey(WORD16 addr,BYTE8 v,int keyInfo);

BYTE8 HWReadKeyboardPort(WORD16 addr) {
	BYTE8 v = 0;
	for (int i = 0;i < 8;i++) {
		if ((addr & (0x01 << i)) == 0) v |= HWXGetKeyboardRow(i);
	}
	#include "_keyboard_fix.h"
	return v ^ 0xFF;
}

static BYTE8 HWForceKey(WORD16 addr,BYTE8 v,int unshifted,int shifted,int controlled) {
	if (HWXIsKeyPressed(GFXKEY_SHIFT)) {
		if (shifted != 0) v = _HWUpdateKey(addr,0,shifted);
	} else if (HWXIsKeyPressed(GFXKEY_CONTROL)) {
		if (controlled != 0) v = _HWUpdateKey(addr,0,controlled);
	} else {
		if (unshifted != 0) v = _HWUpdateKey(addr,0,unshifted);		
	}
	return v;
}

static BYTE8 _HWUpdateKey(WORD16 addr,BYTE8 v,int keyInfo) {
	if ((addr & ((keyInfo & 0xFF00) >> 8)) == 0) { 						// If required row being scanned.
		v = v | (keyInfo & 0xFF); 										// Set the bits required.
	}
	int modifier = keyInfo >> 16;
	if (modifier == 1) { 												// Shift.
		if ((addr & 0x04) == 0) v |= 0x04;
	}
	if (modifier == 2) { 												// Ctrl
		if ((addr & 0x02) == 0) v |= 0x04;
	}
	return v;
}

// *******************************************************************************************************************************
// 													6847 Palette Data as RGB
// *******************************************************************************************************************************

static BYTE8 _6847_palette[][3] = {
    { 0x30, 0xd2, 0x00 }, /* 0 GREEN */
    { 0xc1, 0xe5, 0x00 }, /* YELLOW */
    { 0x4c, 0x3a, 0xb4 }, /* BLUE */
    { 0x9a, 0x32, 0x36 }, /* RED */
    { 0xbf, 0xc8, 0xad }, /* BUFF */
    { 0x41, 0xaf, 0x71 }, /* CYAN */
    { 0xc8, 0x4e, 0xf0 }, /* MAGENTA */
    { 0xd4, 0x7f, 0x00 }, /* ORANGE */

    { 0x26, 0x30, 0x16 }, /* 8 BLACK */
    { 0x30, 0xd2, 0x00 }, /* 9 GREEN */
    { 0x26, 0x30, 0x16 }, /* 10 BLACK */
    { 0xbf, 0xc8, 0xad }, /* 11 BUFF */

    { 0x00, 0x4c, 0x00 }, /* 12 ALPHANUMERIC DARK GREEN */
    { 0x30, 0xd2, 0x00 }, /* 13 ALPHANUMERIC BRIGHT GREEN */
    { 0x6b, 0x27, 0x00 }, /* 14 ALPHANUMERIC DARK ORANGE */
    { 0xf7, 0xb7, 0x00 }  /* 15 ALPHANUMERIC BRIGHT ORANGE */
};

// Downgraded dark colours 6C->4C green

BYTE8 *HWGetPalette(BYTE8 colour) {
	return _6847_palette[colour];
}

// *******************************************************************************************************************************
// 													6847 Video Mode Access
// *******************************************************************************************************************************

BYTE8 HWGetVideoMode(void) {
	return lastControlWrite & 0x18;
}

// *******************************************************************************************************************************
//												Get Background Palette Colour ID
// *******************************************************************************************************************************

BYTE8 HWGetBackgroundPalette(void) {
	int background;
	if (HWISTEXTMODE()) {
		background = HWISGREENBACKGROUND() ? 12:14;
	} else {
		background = HWISGREENBACKGROUND() ? 9:11;
	}
	return background;
}
