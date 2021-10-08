// ****************************************************************************
// ****************************************************************************
//
//		Name:		espaudio.cpp
//		Purpose:	Sound Hardware Interface
//		Created:	27th April 2020
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// ****************************************************************************
// ****************************************************************************

#include "espinclude.h"

static SoundGenerator soundGen;
static SquareWaveformGenerator square1;

// ****************************************************************************
//
//						Initialise sound hardware
//
// ****************************************************************************

void HWESPSoundInitialise(void) {
	soundGen.attach(&square1);
	square1.enable(false);
}

// ****************************************************************************
//
//							  Set channel pitches
//
// ****************************************************************************

void HWESPSetFrequency(int freq) {
	square1.enable(freq != 0);
	if (freq != 0) square1.setFrequency(freq);
}
