// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_RAY3D_H__
#define __KEIKAIN_RAY3D_H__

#include "../Math/KMath.h"
#include "Vector3d.h"

namespace keikain
{
	template <class T>
	class Ray3d
	{
	public:
		Ray3d(const Ray3d<T>& _r3) :
			start(_r3.start), end(_r3.end) {}
		Ray3d(const Vector3d<T>& _s, const Vector3d<T>& _e) :
			start(_s), end(_e) {}
		Ray3d(const T& _sX = 0, const T& _sY = 0, const T& _sZ = 0, const T& _eX = 1, const T& _eY = 1, const T& _eZ = 1) :
			start(_sX, _sY, _sZ), end(_eX, _eY, _eZ) {}

		//! Get the length.
		T getLength() const
		{
			return K_sqrt((end.X - start.X) * (end.X - start.X) + (end.Y - start.Y) * (end.Y - start.Y) + (end.Z - start.Z) * (end.Z - start.Z));
		}

		//! Get the middle point.
		Vector3d<T> getMiddlePoint() const
		{
			return Vector3d<T>((start.X + end.X) / (T)2, (start.Y + end.Y) / (T)2, (start.Z + end.Z) / (T)2);
		}

		Vector3d<T> start;
		Vector3d<T> end;
	};

	typedef Ray3d<f32> ray3df;
	typedef Ray3d<s32> ray3di;
}

#endif