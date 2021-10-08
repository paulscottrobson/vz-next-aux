// ****************************************************************************
// ****************************************************************************
//
//		Name:		hardware_esp.c
//		Purpose:	Hardware Emulation (ESP32 Specific)
//		Created:	8th March 2020
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// ****************************************************************************
// ****************************************************************************

#include <Arduino.h>
#include "sys_processor.h"
#include "gfxkeys.h"
#include "hardware.h"

int HWESPGetScanCode(void);
void HWESPSetFrequency(int freq);

static int scan_to_gfx[256] = {
	#include "_scan_to_gfx.h"
};

// ****************************************************************************
//							  Sync Hardware
// ****************************************************************************

static BYTE8 keyStatus[256] = {0};
static int shift = 0;
static int release = 0;
static int lastKey = 0;

void HWXSyncImplementation(LONG32 iCount) {
	int scanCode = HWESPGetScanCode();
	while (scanCode > 0) {
		if (scanCode == 0xE0) {
			shift = 0x80;
		} 
		else if (scanCode == 0xF0) {
			release = 1;
		}
		else {
			int isDown = (release == 0);
			scanCode = (scanCode & 0x7F) | shift;
			Serial.println(scanCode);
			scanCode = scan_to_gfx[scanCode];
			//writeCharacter(scanCode & 0x0F,(scanCode >> 4)+2,isDown ? '*' : '.');
			keyStatus[scanCode] = isDown;
			lastKey = isDown ? scanCode : -scanCode;
			shift = 0x00;
			release = 0x00;
		}
		scanCode = HWESPGetScanCode();
		keyStatus[GFXKEY_SHIFT] = keyStatus[GFXKEY_LSHIFT]|keyStatus[GFXKEY_RSHIFT];
		keyStatus[GFXKEY_CONTROL] = keyStatus[GFXKEY_LCTRL]|keyStatus[GFXKEY_RCTRL];
	}
	if (keyStatus[GFXKEY_CONTROL] && keyStatus[GFXKEY_ESCAPE]) CPUReset();			/* Ctrl+ESC is Reset */
}

void HWXLog(char *logText) {
	Serial.println(logText);
}

// ****************************************************************************
//					Check if key pressed (GFXKEY values)
// ****************************************************************************

int  HWXIsKeyPressed(int key) {
	return keyStatus[key] != 0;
}

// ****************************************************************************
//						Get System time in 1/100s
// ****************************************************************************

WORD16 HWGetSystemClock(void) {
	return (millis() / 10) & 0xFFFF;
}

// ****************************************************************************
//	 						Set sound pitch, 0 = off
// ****************************************************************************

void HWXSetFrequency(int frequency) {
	HWESPSetFrequency(frequency);
}
