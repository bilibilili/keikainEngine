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
			driverType(K_OPENGL),
			screenSize(800, 450),
			colorDepth(16),
			ZBuffer(16),
			fullScreen(false),
			stencilBuffer(false),
			doubleBuffer(true) {}

		KCreateEngineParameters(const KCreateEngineParameters& _param)
		{
			*this = _param;
		}

		KCreateEngineParameters& operator=(const KCreateEngineParameters& _param)
		{
			driverType = _param.driverType;
			screenSize = _param.screenSize;
			colorDepth = _param.colorDepth;
			ZBuffer = _param.ZBuffer;
			fullScreen = _param.fullScreen;
			stencilBuffer = _param.stencilBuffer;
			doubleBuffer = _param.doubleBuffer;
			return *this;
		}

		//! Type of video driver.
		KDRIVER_TYPE driverType;
		//! Size of screen.
		vector2di screenSize;
		//! Minimum per pixel of the color buffer.
		u8 colorDepth;
		//! Minimum per pixel of the depth buffer.
		u8 ZBuffer;
		//! if the engine run in fullscreen.
		bool fullScreen;
		//! if stencil buffer should be enable.
		bool stencilBuffer;
		//! whether use double buffer.
		bool doubleBuffer;
	};
}

#endif