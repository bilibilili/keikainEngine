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
		Vector2d() :
			X(0), Y(0) {}
		Vector2d(const T& _x = 0, const T& _y = 0) :
			X(_x), Y(_y) {}
		Vector2d(const Vector2d& _v2) :
			X(_v2.X), Y(_v2.Y) {}
		Vector2d<T> operator-() const { return Vector2d<T>(-X, -Y); }
		Vector2d<T>& operator=(const Vector2d<T>& _v2) { X = _v2.X; Y = _v2.Y; return *this; }
		Vector2d<T> operator+(const Vector2d<T>& _v2) const { return Vector2d<T>(X + _v2.X, Y + _v2.Y); }
		Vector2d<T> operator+(const T& _n) const { return Vector2d<T>(X + _n, Y + _n); }
		Vector2d<T>& operator+=(const Vector2d<T>& _v2) { X += _v2.X; Y += _v2.Y; return *this; }
		Vector2d<T>& operator+=(const T& _n) { X += _n; Y += _n; return *this; }
		Vector2d<T> operator-(const Vector2d<T>& _v2) const { return Vector2d<T>(X - _v2.X, Y - _v2.Y); }
		Vector2d<T> operator-(const T& _n) const { return Vector2d<T>(X - _n, Y - _n); }
		Vector2d<T>& operator-=(const Vector2d<T>& _v2) { X -= _v2.X; Y -= _v2.Y; return *this; }
		Vector2d<T>& operator-=(const T& _n) { X -= _n; Y -= _n; return *this; }
		Vector2d<T> operator*(const Vector2d<T>& _v2) const { return Vector2d<T>(X * _v2.X, Y * _v2.Y); }
		Vector2d<T> operator*(const T& _n) const { return Vector2d<T>(X * _n, Y * _n); }
		Vector2d<T>& operator*=(const Vector2d<T>& _v2) { X *= _v2.X; Y *= _v2.Y; return *this; }
		Vector2d<T>& operator*=(const T& _n) { X *= _n; Y *= _n; return *this; }
		Vector2d<T> operator/(const T& _n) const { return Vector2d<T>(X / _n, Y / _n); }
		Vector2d<T>& operator/=(const T& _n) { X /= _n; Y /= _n; return *this; }

		//! Compare two vector's X and Y.
		/** return false if not equal or ture if equal
		*/
		bool equal(const Vector<T>& _v2) const
		{
			return (X == _v2.X) && (Y == _v2.Y);
		}

		bool operator==(const Vector2d<T>& _v2) const
		{
			return equal(_v2);
		}
		bool operator!=(const Vector2d<T>& _v2) const
		{
			return !equal(_v2);
		}

		//! Get the dotProduct.
		T dotProduct(const Vector2d<T>& _v2) const
		{
			return X * _v2.X + Y * _v2.Y;
		}

		//! Get the distance from vector2d )v2.
		T getDistanceFrom(const Vector2d<T>& _v2) const
		{
			return K_sqrt((X - _v2.X) * (X - _v2.X), (Y - _v2.Y) * (Y - _v2.Y));
		}

		//! Get the square distance from the origin of the coordinate. 
		T getSquareDistanceFromOrigin() const
		{
			return X * X + Y * Y;
		}

		//! Get the distance from the origin of the coordinate.
		T getDistanceFromOrigin() const
		{
			return K_fabs(getSquareDistanceFromOrigin());
		}

		//! Rotate the point anticlockwise around a center by an amount of degrees.
		vector2d<T>& rotateBy(f32 degree, const Vector2d<T>& center = Vector2d<T>())
		{

		}

		T X;
		T Y;
	};
}

#endif