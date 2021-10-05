// ****************************************************************************
// ****************************************************************************
//
//		Name:		hardware_emu.c
//		Purpose:	Hardware Emulation (Emulator Specific)
//		Created:	1st October 2021
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
//
//							Key codes for the ports
//
// ****************************************************************************

static int keys[][8] = {
	{ 'R','Q','E',0,'W','T',0,0 },
	{ 'F','A','D',GFXKEY_CONTROL,'S','G',0,0 },
	{ 'V','Z','C',GFXKEY_SHIFT,'X','B',0,0 },
	{ '4','1','3',0,'2','5',0,0 },
	{ 'M',' ',',',0,'.','N',0,0 },
	{ '7','0','8','-','9','6',0,0 },
	{ 'U','P','I',GFXKEY_RETURN,'O','Y',0,0 },
	{ 'J',';','K','@','L','H',0,0 }
};

// ****************************************************************************
//								  Sync CPU
// ****************************************************************************

void HWSyncImplementation(LONG32 iCount) {
	if ((SDL_GetModState() & KMOD_LCTRL) != 0 && 
		 SDL_GetKeyboardState(NULL)[SDL_SCANCODE_ESCAPE] != 0) CPUReset();			/* Ctrl+ESC is Reset */
}

// ****************************************************************************
//					Get the keys pressed for a particular row
// ****************************************************************************

int HWGetKeyboardRow(int row) {
	int word = 0;
	for (int p = 0;p < 6;p++) {
		if (GFXIsKeyPressed(keys[row][p])) word |= (0x20 >> p);
	}
	return word;
}

// ****************************************************************************
//							  Check file exists
// ****************************************************************************

WORD16 HWFileInformation(char *fileName,WORD16 *loadAddress,WORD16 *size) {
	char fullName[128];
	if (fileName[0] == 0) return 0;
	MKSTORAGE();
	sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,fileName);
	FILE *f = fopen(fullName,"rb");
	if (f != NULL) {
		WORD16 addr = fgetc(f);
		addr += (fgetc(f) << 8);
		*loadAddress = addr;
		fseek(f, 0L, SEEK_END);
		*size = (WORD16)((ftell(f)-2)/2);
		fclose(f);
	}
	return (f != NULL);
}

// ****************************************************************************
//								Load file in
// ****************************************************************************

WORD16 HWLoadFile(char * fileName,BYTE8 *target) {
	char fullName[128];
	if (fileName[0] == 0) return 1;
	MKSTORAGE();
	sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,fileName);
	FILE *f = fopen(fullName,"rb");
	//printf("%s\n",fullName);
	if (f != NULL) {
		while (!feof(f)) {
			BYTE8 data = fgetc(f);
			*target++ = data;
		}
		fclose(f);
	}
	return (f != NULL) ? 0 : 1;
}

// ****************************************************************************
//								Save file out
// ****************************************************************************

WORD16 HWSaveFile(char *fileName,WORD16 start,WORD16 size) {
	char fullName[128];
	MKSTORAGE();
	sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,fileName);
	FILE *f = fopen(fullName,"wb");
	if (f != NULL) {
		fputc(start & 0xFF,f);
		fputc(start >> 8,f);
		while (size != 0) {
			size--;
			WORD16 d = CPUReadMemory(start++);
			fputc(d & 0xFF,f);
			fputc(d >> 8,f);
		}
		fclose(f);
	}
	return (f != NULL) ? 0 : 1;
}

// ****************************************************************************
//							  Load Directory In
// ****************************************************************************

void HWLoadDirectory(WORD16 target) {
	int count = 0;
	DIR *dp;
	struct dirent *ep;
	char fullName[128];
	MKSTORAGE();
	sprintf(fullName,"%sstorage",SDL_GetBasePath());
	dp = opendir(fullName);
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			if (ep->d_name[0] != '.') {
				if (count != 0) CPUWriteMemory(target++,32);
				char *p = ep->d_name;
				while (*p != '\0') CPUWriteMemory(target++,*p++);
				count++;
			}
		}
		closedir(dp);
	}
	CPUWriteMemory(target,0);
}

// ****************************************************************************
//								Transmit character
// ****************************************************************************

void HWTransmitCharacter(BYTE8 ch) {
	printf("%c",ch);
}

// ****************************************************************************
//							  Downloader (dummy at present)
// ****************************************************************************

WORD16 HWDownloadHandler(char *url,char *target,char *ssid,char *password) {
	char buffer[128],fullName[128];
	FILE *fIn,*fOut;
	printf("Download %s to %s using %s[%s]\n",url,target,ssid,password);
	sprintf(fullName,"%swww%c%s",SDL_GetBasePath(),FILESEP,target);
	fIn = fopen(fullName,"rb");
	if (fIn != NULL) {
		sprintf(fullName,"%sstorage%c%s",SDL_GetBasePath(),FILESEP,target);
		fOut = fopen(fullName,"wb");
		while (!feof(fIn)) {
			int n = fread(buffer,1,sizeof(buffer),fIn);
			if (n > 0) fwrite(buffer,1,n,fOut);
		}
		fclose(fOut);
		fclose(fIn);
	}
	return (fIn != NULL) ? 0 : 1;
}

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
