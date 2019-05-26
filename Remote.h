/**
 * Remote.cpp
 *
 * Author: Mark Furland <mtfurlan@mtu.edu>
 * 2016-07-10
 *
 * Adapted code from Stefan Jones at
 *	http://stefanjones.ca/blog/arduino-leonardo-remote-multimedia-keys/
 *
 * Refactored given code intended for modifying the android libraries to
 *  a stand alone library for arduino 1.6.9
*/

#ifndef REMOTE_h
#define REMOTE_h

#include "HID.h"

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Remote

//DUnno what these do, don't *appear* used?
#define REMOTE_CLEAR 0
#define VOLUME_UP 1
#define VOLUME_DOWN 2
#define VOLUME_MUTE 4
#define REMOTE_PLAY 8
#define REMOTE_PAUSE 16
#define REMOTE_STOP 32
#define REMOTE_NEXT 64
#define REMOTE_PREVIOUS 128
#define REMOTE_FAST_FORWARD 256
#define REMOTE_REWIND 512
#define REMOTE_SLEEP 1024
#define REMOTE_POWER 2048

class Remote_
{
private:
public:
	Remote_(void);
	void begin(void);
	void end(void);

	// Volume
	void increase(void);
	void decrease(void);
	void mute(void);

	// Playback
	void play(void);
	void pause(void);
	void stop(void);

	// Track Controls
	void next(void);
	void previous(void);
	void forward(void);
	void rewind(void);

	// Power
	void sleep(void);
	void power(void);
  
	// Send an empty report to prevent repeated actions
	void clear(void);
};
extern Remote_ Remote;

#endif
#endif
