// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KDRIVERTYPE_H__
#define __KEIKAIN_KDRIVERTYPE_H__

namespace keikain
{
	enum KDRIVER_TYPE
	{
		//! Direct3DX device,only available on win platforms.
		/** performs hardware accelerated rendering of 3D and 2D
		primitives
		*/
		K_DIRECT3DX,

		//! OPENGL device,available on most platforms.
		/** performs hardware accelerated rendering of 3D and 2D
		primitives
		*/
		K_OPENGL
	};
}

#endif