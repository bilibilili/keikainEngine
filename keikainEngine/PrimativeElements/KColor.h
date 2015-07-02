// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KCOLOR_H__
#define __KEIKAIN_KCOLOR_H__

#include "../Utilities/KTypes.h"

namespace keikain
{
	//! Class represents 32 bit ARGB color.
	/** the color value for alpha, red, green, blue are
	store in a single u32
	*/
	class KColor
	{
	public:
		KColor(u32 _a, u32 _r, u32 _g, u32 _b) : color(((_a & 0xff) << 24) | ((_r & 0x))) {}

		u32 color;
	};
}

#endif