// ****************************************************************************
// ****************************************************************************
//
//		Name:		hardware_emu.c
//		Purpose:	Hardware Emulation (Emulator Specific)
//		Created:	8th October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// ****************************************************************************
// ****************************************************************************

#include "sys_processor.h"
#include "hardware.h"
#include "gfxkeys.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <stdlib.h>
#include "gfx.h"

//
//		Really annoying.
//
#ifdef LINUX
#define MKSTORAGE()	mkdir("storage", S_IRWXU)
#else
#define MKSTORAGE()	mkdir("storage")
#endif

// ****************************************************************************
//					Dummy screen handlers (all done by debugger)
// ****************************************************************************

void HWXClearScreen(int colour) { }
void HWXPlotCharacter(int x,int y,int colour,int bgr,BYTE8 ch) { }

// ****************************************************************************
//								Debug logger
// ****************************************************************************

void HWXLog(char *logText) {
	fprintf(stderr,"%s\n",logText);
}

// ****************************************************************************
//								  Sync CPU
// ****************************************************************************

void HWXSyncImplementation(LONG32 iCount) {
	if ((SDL_GetModState() & KMOD_LCTRL) != 0 && 
		 SDL_GetKeyboardState(NULL)[SDL_SCANCODE_ESCAPE] != 0) CPUReset();			/* Ctrl+ESC is Reset */
}

// ****************************************************************************
//			Generic key check for extra functions on PC keyboard
// ****************************************************************************

int HWXIsKeyPressed(int code) {
	return GFXIsKeyPressed(code);
}

// ****************************************************************************
//	 						Set sound pitch, 0 = off
// ****************************************************************************

void HWXSetFrequency(int frequency) {
	GFXSetFrequency(frequency);
}

// ****************************************************************************
//								Load file in
// ****************************************************************************

WORD16 HWXLoadFile(char * fileName,WORD16 *startLoad,WORD16 *endLoad,BYTE8 *type) {
	char fullName[128];
	if (fileName[0] == 0) return 1;
	MKSTORAGE();
	sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,fileName);
	FILE *f = fopen(fullName,"rb");
//	printf("%s\n",fullName);
	if (f != NULL) {
		for (int i = 0;i < 21;i++) fgetc(f); 	// Don't care (21 bytes)
		int fType = fgetc(f); 					// File type (1 byte)
		int start = fgetc(f); 					// Load Address (2 bytes)
		start = start + (fgetc(f) << 8);
		*startLoad = start; 					// Return start address
//		printf("Loading to %x\n",start);
		while (!feof(f)) { 						// Rest is data
			BYTE8 data = fgetc(f);
			CPUWriteMemory(start++,data);
		}
		fclose(f);
		*type = fType & 0xFF; 					// Return type
		*endLoad = start & 0xFFFF; 				// And location
	}
	return (f != NULL) ? 0 : 1;
}

// ****************************************************************************
//								Save file out
// ****************************************************************************

// WORD16 HWSaveFile(char *fileName,WORD16 start,WORD16 size) {
// 	char fullName[128];
// 	MKSTORAGE();
// 	sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,fileName);
// 	FILE *f = fopen(fullName,"wb");
// 	if (f != NULL) {
// 		fputc(start & 0xFF,f);
// 		fputc(start >> 8,f);
// 		while (size != 0) {
// 			size--;
// 			WORD16 d = CPUReadMemory(start++);
// 			fputc(d & 0xFF,f);
// 			fputc(d >> 8,f);
// 		}
// 		fclose(f);
// 	}
// 	return (f != NULL) ? 0 : 1;
// }

// ****************************************************************************
//							  Load Directory In
// ****************************************************************************

// void HWLoadDirectory(WORD16 target) {
// 	int count = 0;
// 	DIR *dp;
// 	struct dirent *ep;
// 	char fullName[128];
// 	MKSTORAGE();
// 	sprintf(fullName,"%sstorage",SDL_GetBasePath());
// 	dp = opendir(fullName);
// 	if (dp != NULL) {
// 		while (ep = readdir(dp)) {
// 			if (ep->d_name[0] != '.') {
// 				if (count != 0) CPUWriteMemory(target++,32);
// 				char *p = ep->d_name;
// 				while (*p != '\0') CPUWriteMemory(target++,*p++);
// 				count++;
// 			}
// 		}
// 		closedir(dp);
// 	}
// 	CPUWriteMemory(target,0);
// }

// ****************************************************************************
//								Transmit character
// ****************************************************************************

// void HWTransmitCharacter(BYTE8 ch) {
// 	printf("%c",ch);
// }

// ****************************************************************************
//							  Downloader (dummy at present)
// ****************************************************************************

// WORD16 HWDownloadHandler(char *url,char *target,char *ssid,char *password) {
// 	char buffer[128],fullName[128];
// 	FILE *fIn,*fOut;
// 	printf("Download %s to %s using %s[%s]\n",url,target,ssid,password);
// 	sprintf(fullName,"%swww%c%s",SDL_GetBasePath(),FILESEP,target);
// 	fIn = fopen(fullName,"rb");
// 	if (fIn != NULL) {
// 		sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,target);
// 		fOut = fopen(fullName,"wb");
// 		while (!feof(fIn)) {
// 			int n = fread(buffer,1,sizeof(buffer),fIn);
// 			if (n > 0) fwrite(buffer,1,n,fOut);
// 		}
// 		fclose(fOut);
// 		fclose(fIn);
// 	}
// 	return (fIn != NULL) ? 0 : 1;
// }

// ****************************************************************************
//								Delete file
// ****************************************************************************

WORD16 HWDeleteFile(char *fileName) {
	char fullName[128];
	printf("Deleting %s\n",fileName);
	sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,fileName);
	remove(fullName);
	return 0;
}
