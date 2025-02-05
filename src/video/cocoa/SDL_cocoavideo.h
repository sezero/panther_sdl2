/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#ifndef _SDL_cocoavideo_h
#define _SDL_cocoavideo_h

#include "SDL_opengl.h"

#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
/* to cricumvent a bug in Mac OS X 10.4 SDK */
#define vector __vector
#include <CoreServices/CoreServices.h>
#undef vector
#endif
#include <ApplicationServices/ApplicationServices.h>
#include <Cocoa/Cocoa.h>

#include "SDL_keycode.h"
#include "../SDL_sysvideo.h"

#include "SDL_cocoaclipboard.h"
#include "SDL_cocoaevents.h"
#include "SDL_cocoakeyboard.h"
#include "SDL_cocoamodes.h"
#include "SDL_cocoamouse.h"
#include "SDL_cocoaopengl.h"
#include "SDL_cocoawindow.h"

#if !defined(MAC_OS_X_VERSION_10_6) && !defined(NSINTEGER_DEFINED)
/* This is for compatibility with 10.4 and older Mac OS X SDKs.  Otherwise,
 * conflicting type errors for  -(long int)conversationIdentifier  and
 * -(unsigned int)characterIndexForPoint:(NSPoint)thePoint  will happen. */
typedef long int NSInteger;
typedef unsigned int NSUInteger;
#ifdef __LP64__
#error Bad SDK for __LP64__ build
#endif
/*
#if __LP64__ || NS_BUILD_32_LIKE_64
typedef long NSInteger;
typedef unsigned long NSUInteger;
#else
typedef int NSInteger;
typedef unsigned int NSUInteger;
#endif
*/
#endif

/* Private display data */

@class SDLTranslatorResponder;

typedef struct SDL_VideoData
{
    SInt32 osversion;
    int allow_spaces;
    unsigned int modifierFlags;
    void *key_layout;
    SDLTranslatorResponder *fieldEdit;
    NSInteger clipboard_count;
    Uint32 screensaver_activity;
} SDL_VideoData;

/* Utility functions */
extern NSImage * Cocoa_CreateImage(SDL_Surface * surface);

#endif /* _SDL_cocoavideo_h */

/* vi: set ts=4 sw=4 expandtab: */
