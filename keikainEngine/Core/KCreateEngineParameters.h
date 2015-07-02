// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in keikain.h

#ifndef __KEIKAIN_KCREATEENGINEPARAMETERS_H__
#define __KEIKAIN_KCREATEENGINEPARAMETERS_H__

#include "../Utilities/KDriverType.h"
#include "../PrimativeElements/Vector2d.h"

namespace keikain
{
	class KCreateEngineParameters
	{
	public:
		KCreateEngineParameters() :
			DriverType(K_OPENGL),
			WindowSize(800, 450),
			Bits(16),
			ZBufferBits(16),
			FullScreen(false),
			StencilBuffer(false),
			DoubleBuffer(true) {}

		KCreateEngineParameters(const KCreateEngineParameters& _params)
		{
			*this = _params;
		}

		//! Type of the video device.
		/** this setting decides the engine used by the device
		K_DIRECT3DX is only available on win32 platform
		K_OPENGL available on linux, bsd
		*/
		KDRIVER_TYPE DriverType;

		//! Size of the window.
		vector2di WindowSize;

		//! Minimum Bits per pixel of the color buffer.
		u8 Bits;
		
		//! Minimum Bits per pixel of the depth buffer.
		u8 ZBufferBits;

		//! Set the screen full screen or windowed screen.
		bool FullScreen;

		//! Specifies if the stencil buffer should be enabled.
		bool StencilBuffer;

		//! whether use double buffer.
		bool DoubleBuffer;

		//! 

	};
}

#endif