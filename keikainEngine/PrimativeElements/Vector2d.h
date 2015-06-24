// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_VECTOR2D_H__
#define __KEIKAIN_VECTOR2D_H__

#include "../Utilities/KTypes.h"
#include "../Math/KMath.h"

//! Vector2d describ a point in 2d graph.
/** 
*/
namespace keikain
{
	template <class T>
	class Vector2d
	{
	public:
		Vector2d(const T& _x = 0, const T& _y = 0) :
			X(_x), Y(_y) {}
		Vector2d(const Vector2d& _v2) :
			X(_v2.X), Y(_v2.Y) {}


		T X;
		T Y;
	};
}

#endif