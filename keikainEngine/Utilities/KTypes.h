// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KTYPES_H__
#define __KEIKAIN_KTYPES_H__

#include "KCompileConfig.h"

namespace keikain
{
// 8 bit unsigned variable
#if defined(_MSC_VER) || !defined(__STRICT_ANSI__)
	typedef unsigned __int8		u8;
#else
	typedef unsigned char		u8;
#endif

// 8 bit signed variable
#if defined(_MSC_VER) || !defined(__STRICT_ANSI__)
	typedef __int8				s8;
#else
	typedef signed char			s8;
#endif

// 8 bit character variable
	typedef char				c8;

// 16 bit unsigned variable
#if defined(_MSC_VAR) || !defined(__STRICT_ANSI__)
	typedef unsigned __int16	u16;
#else
	typedef unsigned short		u16;
#endif

// 16 bit signed variable
#if defined(_MSC_VAR) || !defined(__STRICT_ANSI__)
	typedef __int16				s16;
#else
	typedef signed short		s16;
#endif

// 32 bit unsigned variable
#if defined(_MSC_VAR) || !defined(__STRICT_ANSI__)
	typedef unsigned __int32	u32;
#else
	typedef unsigned int		u32;
#endif

// 32 bit signed variable
#if defined(_MSC_VAR) || !defined(__STRICT_ANSI__)
	typedef __int32				s32;
#else
	typedef int32				s32;
#endif

// 32 bit float point variable
	typedef float				f32;
// 64 bit float point variable
	typedef double				f64;
}

#endif