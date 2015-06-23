// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in keikain.h

#ifndef __KEIKAIN_KCOMPILECONFIG_H__
#define __KEIKAIN_KCOMPILECONFIG_H__

namespace keikain
{
// about the version
#define KEIKAIN_ENGINE_VERSION_MAJOR 0
#define KEIKAIN_ENGINE_VERSION_MINOR 0
// define the keikain engine version
#define KEIKAIN_SDK_VERSION "0.1"

// WIN32 for Windows32 system
// WIN64 for Windows64 system
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define _KEIKAIN_WINDOWS_
#endif

// __APPLE__ or MACOS for mac os x
#if defined(__APPLE__) || defined(MACOSX)
#if !defined(MACOSX)
#define MACOSX
#endif
#define _KEIKAIN_OSX_
#endif

#if !defined(_KEIKAIN_WINDOWS_) || !defined(_KEIKAIN_OSX_)
#define _KEIKAIN_LINUX_
#endif

// maximum number of texture an material can have
#define _KEIKAIN_MATERIAL_MAX_TEXTURES_ 4

// define _KEIKAIN_COMPILE_WITH_DIRECT3D_9_ or _KEIKAIN_COMPILE_WITH_OPENGL_
// to comiple the keikain engine
#define _KEIKAIN_COMPILE_WITH_DIRECT3D_9_
#define _KEIKAIN_COMPILE_WITH_OPENGL_

// compile with X11 support. only in linux
#define _KEIKAIN_COMPILE_WITH_X11_

#ifdef _KEIKAIN_WINDOWS_

#ifndef _KEIKAIN_STATIC_LIB_
#ifdef KEIKAIN_EXPORTS
#define KEIKAIN_API __declspec(dllexport)
#else
#define KEIKAIN_API __declspec(dllimport)
#endif // end KEIKAIN_EXPORTS
#else
#define KEIKAIN_API
#endif // end _KEIKAIN_STATIC_LIB_

#if defined(_STDCALL_SUPPORTED_)
#define KEIKAIN_CALL_CONV __stdcall
#else
#define KEIKAIN_CALL_CONV __cdecl
#endif

#else

// Force symbol export in shared libraries built with gcc
#if (__GNUC__ >= 4) && !defined(_KEIKAIN_STATIC_LIB_) && defined(KEIKAIN_EXPORTS)
#define KEIKAIN_API __attribute__ (visibility("default"))
#else
#define KEIKAIN_API
#endif
#define KEIKAIN_CALL_CONV

#endif // end _KEIKAIN_WINDOWS_
}

#endif