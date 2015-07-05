// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_DIMENSION2D_H__
#define __KEIKAIN_DIMENSION2D_H__

#include "Vector2d.h"
#include "../Math/KMath.h"

namespace keikain
{
	//! Forward declare.
	template <class T>
	class Vector2d;

	template <class T>
	class Dimension2d
	{
	public:
		Dimension2d() : Width(0), Height(0) {}
		Dimension2d(const T& _width, const T& _height) : Width(_width), Height(_height) {}
		Dimension2d(const Vector2d<T>& _vect);

		template <class U>
		explicit Dimension2d(const Dimension2d<U>& _other) : Width((T)_other.Width), Height((T)_other.Height) {}

		template <class U>
		Dimension2d<T>& operator=(const Dimension2d<U>& _other)
		{
			Width = (T)_other.Width;
			Height = (T)_other.Height;

			return *this;
		}

		//! Equality operator.
		bool operator==(const Vector2d<T>& _vect) const;

		//! Equality operator.
		bool operator==(const Dimension2d<T>& _other) const
		{
			return kkmath::equals(Width, _other.Height) && kkmath::equals(Height, _other.Height);
		}

		//! Inequality operator.
		bool operator!=(const Dimension2d<T>& _other) const
		{
			return !(*this == _other);
		}

		//! Set to new values.
		Dimension2d<T>& set(const T& _width, const T& _height)
		{
			Width = _width;
			Height = _height;

			return *this;
		}

		//! Divide width and height by scalar.
		Dimension2d<T>& operator/=(const T& _scalar)
		{
			Width /= _scalar;
			Height /= _scalar;

			return *this;
		}

		//! Divide width and height by scalar.
		Dimension2d<T> operator/(const T& _scalar) const
		{
			return Dimension2d<T>(Width / _scalar, Height / _scalar);
		}

		//! Multiply width and height by scalar.
		Dimension2d<T>& operator*=(const T& _scalar)
		{
			Width *= _scalar;
			Height *= _scalar;

			return *this;
		}

		//! Multiply width and height by scalar.
		Dimension2d<T> operator*(const T& _scalar) const
		{
			return Dimension2d<T>(Width * _scalar, Height * _scalar);
		}

		//! Add another dimension to this one.
		Dimension2d<T>& operator+=(const Dimension2d<T>& _other)
		{
			Width += _other.Width;
			Height += _other.Height;

			return *this;
		}

		//! Add two dimensions.
		Dimension2d<T> operator+(const Dimension2d<T>& _other) const
		{
			return Dimension2d<T>(Width + _other.Width, Height + _other.Height);
		}

		//! Subtract a dimension from this one.
		Dimension2d<T>& operator-=(const Dimension2d<T>& _other)
		{
			Width -= _other.Width;
			Height -= _other.Height;

			return *this;
		}

		//! Subtract one dimension from another.
		Dimension2d<T> operator-(const Dimension2d<T>& _other) const
		{
			return Dimension2d<T>(Width - _other.Width, Height - _other.Height);
		}

		//! Get area.
		T getArea() const
		{
			return Width * Height;
		}

		//! Get the optimal size according to some properties.
		Dimension2d<T> getOptimalSize(
			bool requirePowerOfTwo = true,
			bool requireSquare = false,
			bool larger = true,
			u32 maxValue = 0) const
		{
			u32 i = 1;
			u32 j = 1;
			if (requirePowerOfTwo)
			{
				while (i < (u32)Width)
				{
					i <<= 1;
				}
				if (!larger && i != (u32)Width)
				{
					i >>= 1;
				}
				while (j < (u32)Height)
				{
					j <<= 1;
				}
				if (!larger && j != 1 && j != (u32)Height)
				{
					j >>= 1;
				}
			}
			else
			{
				i = (u32)Width;
				j = (u32)Height;
			}

			if (requireSquare)
			{
				if ((larger && (i > j)) || (!larger && (i < j)))
				{
					j = i;
				}
				else
				{
					i = j;
				}
			}

			if (maxValue > 0 && i > maxValue)
			{
				i = maxValue;
			}
			if (maxValue > 0 && j > maxValue)
			{
				j = maxValue;
			}

			return Dimension2d<T>((T)i, (T)j);
		}

		//! Get the interpolated dimension.
		Dimension2d<T> getInterpolated(const Dimension2d<T>& _other, f32 _d) const
		{
			f32 inv = (1.0f - _d);
			return Dimension2d<T>((T)(_other.Width * inv + Width * _d), (T)(_other.Height * inv + Height * _d));
		}

		T Width;
		T Height;
	};

	typedef Dimension2d<f32> dimension2df;
	typedef Dimension2d<u32> dimension2du;
	typedef Dimension2d<s32> dimension2di;
}

#endif