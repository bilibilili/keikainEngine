// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in keikain.h

#ifndef __KEIKAIN_KVIDEODRIVER_H__
#define __KEIKAIN_KVIDEODRIVER_H__

#include "KReferenceCounted.h"
#include "../PrimativeElements/KColor.h"
#include "../Utilities/KDriverFeatures.h"
#include "KAttributes.h"

namespace keikain
{
	//! Interface to driver which is able to perform 2d and 3d graphics functions.
	class KVideoDriver : public KReferenceCounted
	{
	public:
		//! Applications must call this method before performing any rendering.
		/** this method can clear the back-buffer and z-buffer.
		*/
		virtual bool InitScene(bool backBuffer = true, bool zBuffer = true, KColor color = KColor(255, 0, 0, 0)) = 0;
		//! Presents the rendered image to the screen.
		/** Applications must call this method after performing any rendering.
		*/
		virtual bool endScene() = 0;

		//! Queries the features of the driver.
		/** Return true if a feature is available
		*/
		virtual bool queryFeature(K_VIDEO_DRIVER_FEATURE _feature) const = 0;

		//! Disable a feature of the driver.
		virtual void disableFeature(K_VIDEO_DRIVER_FEATURE _feature, bool flag = true) = 0;

		//! Get attributes of the actual video driver.
		virtual const KAttributes& getDriverAttributes() const = 0;
		//! Check if the driver was recently reset.
		virtual bool checkDriverReset() = 0;
		//! Sets transformation matrices.
		virtual void setTransform() = 0;
	};
}

#endif