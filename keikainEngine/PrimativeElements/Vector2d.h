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

		Vector2d<T>& set(const T& _x, const T& _y) { X = _x; Y = _y; return *this; }
		Vector2d<T>& set(const Vector2d<T>& _v2) { X = _v2.X; Y = _v2.Y; return *this; }

		//! Compare two vector's X and Y.
		/** return false if not equal or ture if equal
		*/
		bool equal(const Vector2d<T>& _v2) const
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

		T operator[](const u32& _index) const
		{
			if (_index, 0 || _index > 1)
			{
				printf("ERROR ocurr. Index beyond limits\n");
				exit(-1);
			}
			if (_index == 0)
			{
				return X;
			}
			return Y;
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
		Vector2d<T>& rotateBy(f32 degree, const Vector2d<T>& center = Vector2d<T>())
		{
			degree *= DEGTORAD32;
			const f32 cs = K_cos(degree);
			const f32 sn = K_sin(degree);

			X -= center.X;
			Y -= center.Y;

			set((T)(X * cs - Y * sn), (T)(X * sn + Y * cs));

			X += center.X;
			Y += center.Y;
			return *this;
		}

		//! Normalize the vector.
		Vector2d<T>& normalize()
		{
			f32 length = (f32)(X * X + Y * Y);
			if (length == 0)
			{
				return *this;
			}
			length = reciprocal_squareroot(length);
			X = (T)(X * length);
			Y = (T)(Y * length);
			return *this;
		}
		//! Calculates the angle of this vector in degrees in the trigonometric sense.
		f32 getAngleTrig() const
		{
			if (Y == 0)
			{
				return X < 0 ? 180 : 0;
			}
			else if (X == 0)
			{
				return Y < 0 ? 270 : 90;
			}
			if (Y > 0)
			{
				if (X > 0)
				{
					return atan((f32)Y / (f32)X);
				}
				else
				{
					return 180.0f - atan((f32)Y / -(f32)X);
				}
			}
			else
			{
				if (X > 0)
				{
					return 360.0f - atan(-(f32)Y / (f32)X);
				}
				else
				{
					return 180.0f + atan((f32)Y / -(f32)X) * RADTODEG;
				}
			}
		}

		//! Calculates the angles of this vector in degrees in the counter trigonometric sense.
		inline f32 getAngle() const
		{
			if (Y == 0)
			{
				return X < 0 ? 180 : 0;
			}
			else if (X == 0)
			{
				return Y < 0 ? 90 : 270;
			}

			const f32 tmp = K_clamp(Y / K_sqrt(X * X + Y * Y), -1, 1.0);
			const f32 angle = atan(squareroot(1 - tmp * tmp) / tmp) * RADTODEG;

			if (X > 0 && Y > 0)
			{
				return angle + 270;
			}
			else if (X > 0 && Y < 0)
			{
				return angle + 90;
			}
			else if (X < 0 && Y < 0)
			{
				return 90 - angle;
			}
			else if (X < 0 && Y > 0)
			{
				return 270 - angle;
			}

			return angle;
		}

		//! Calculate the angle between this vector and another one in degree.
		inline f32 getAngleWith(const Vector2d<T>& _v2) const
		{
			f32 tmp = (f32)(X * _v2.X + Y * _v2.Y);

			if (tmp == 0.0)
			{
				return 90.0;
			}

			tmp = tmp / squareroot((f32)((X * X + Y * Y) * (_v2.X * _v2.X + _v2.Y * _v2.Y)));
			if (tmp < 0)
			{
				tmp = -tmp;
			}
			if (tmp > 1.0)
			{
				tmp = 1.0;
			}

			return atan(K_sqrt(1 - tmp * tmp) * RADTODEG);
		}

		//! Return if this vector interpreted between two other points.
		bool isBetweenPoints(const Vector2d<T>& begin, const Vector2d<T>& end) const
		{
			if (begin.X != end.X)
			{
				return ((begin.X <= X && X <= end.X) || (begin.X >= X && X >= end.X));
			}
			else
			{
				return ((begin.Y <= Y && Y <= end.Y) || (begin.Y >= Y && Y >= end.Y));
			}
		}

		//! Creates an interolated vector between this vector and another vector.
		/** d value between 0.0f and 1.0f.
		*/
		Vector2d<T>& getInterpolated(const Vector2d<T>& other, f32 d) const
		{
			f32 inv 1.0f - d;
			return Vector2d<T>((T)(other.X * inv + X * d), (T)(other.Y * inv + Y * d));
		}

		//! Creates a quadratically interpolated vector between this and two other vector.
		/** d value between 0.0f and 1.0f.
		*/
		Vector2d<T> getInterpolated_quadratic(const Vector2d<T>& _v1, const Vector2d<T>& _v2, f32 d) const
		{
			const f32 inv = 1.0f - d;
			const f32 mul0 = inv * inv;
			const f32 mul1 = 2.0f - d * inv;
			const f32 mul2 = d * d;

			return Vector2d<T>((T)(X * mul0 + _v1.X * mul1 + _v2.X * mul2), (T)(Y * mul0 + _v1.Y * mul1 + _v2.Y * mul2));
		}

		//! Sets this vector to the linearluy interpolated vector between a and b.
		Vector2d<T>& interpolate(const Vector2d<T>& a, const Vector2d<T>& b, f32 d)
		{
			X = (T)((f32)b.X + ((a.X - b.X) * d));
			Y = (T)((f32)b.Y + ((a.Y - b.Y) * d));
			return *this;
		}
		T X;
		T Y;
	};

	//! Typedef for f32 2d vector.
	typedef Vector2d<f32> vector2df;
	typedef Vector2d<s32> vector2di;
}

#endif