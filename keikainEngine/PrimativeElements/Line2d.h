// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_LINE2D_H__
#define __KEIKAIN_LINE2D_H__

#include "../Math/KMath.h"
#include "Vector2d.h"

namespace keikain
{
	template <class T>
	class Line2d
	{
	public:
		Line2d(const Vector2d<T>& _s, const Vector2d<T>& _e) :
			start(_s), end(_e) {}
		Line2d(const Line2d<T>& _r2) :
			start(_r2.start), end(_r2.end) {}
		Line2d(const T& _sX = 0, const T& _sY = 0, const T& _eX = 1, const T& _eY = 1) :
			start(_sX, _sY), end(_eX, _eY) {}
		//! Detect two rays if equal.
		bool operator==(const Line2d<T>& _r2) const
		{
			return (start == _r2.start) && (end == _r2.end);
		}

		//! Detect two rays if not equal.
		bool operator!=(const Line2d<T>& _r2) const
		{
			return (start != _r2.start) && (end != _r2.end);
		}

		//! Get rays length.
		T getLength() const
		{
			return K_sqrt((end.X - start.X) * (end.X - start.X) + (end.Y - start.Y) * (end.Y - start.Y));
		}

		//! Get middle point.
		Vector2d<T> getMiddlePoint() const
		{
			return Vector2d<T>((end.X + start.X) / (T)2, (end.Y + start.Y) / (T)2);
		}

		//! Get the vector of ray.
		Vector2d<T> getDirection() const
		{
			return Vector2d<T>(end.X - start.X, end.Y -end.Y);
		}

		

		Vector2d<T> start;
		Vector2d<T> end;
	};

	typedef Line2d<f32> line2df;
	typedef Line2d<s32> line2di;
}

#endif