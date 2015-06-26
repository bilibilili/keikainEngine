// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_VECTOR3D_H__
#define __KEIKAIN_VECTOR3D_H__

#include "../Utilities/KTypes.h"

namespace keikain
{
	template <class T>
	class Vector3d
	{
	public:
		Vector3d() :
			X(0), Y(0), Z(0) {}
		Vector3d(const T& _n = 0) :
			X(_n), Y(_n), Z(_n) {}
		Vector3d(const T& _x = 0, const T& _y = 0, const T& _z = 0) :
			X(_x), Y(_y), Z(_z) {}
		Vector3d(const Vector3d<T>& _v3) :
			X(_v3.X), Y(_v3.Y), Z(_v3.Z) {}
		Vector3d<T> operator-() const
		{
			return Vector3d<T>(-X, -Y, -Z);
		}
		Vector3d<T> operator+(const Vector3d<T>& _v3) const
		{
			return Vector3d<T>(X + _v3.X, Y + _v3.Y, Z + _v3.Z);
		}
		Vector3d<T>& operator+=(const Vector3d<T>& _v3)
		{
			X += _v3.X;
			Y += _v3.Y;
			Z += _v3.Z;

			return *this;
		}
		Vector3d<T> operator-(const Vector3d<T>& _v3) const
		{
			return Vector3d<T>(X - _v3.X, Y - _v3.Y, Z - _v3.Z);
		}
		Vector3d<T>& operator-=(const Vector3d<T>& _v3)
		{
			X -= _v3.X;
			Y -= _v3.Y;
			Z -= _v3.Z;

			return *this;
		}
		Vector3d<T> operator*(const Vector3d<T>& _v3) const
		{
			return Vector3d<T>(X * -V3.X, Y * _v3.Y, Z * _v3.Z);
		}
		Vector3d<T>& operator*=(const Vector3d<T>& _v3)
		{
			X *= _v3.X;
			Y *= _v3.Y;
			Z *= _v3.Z;

			return *this;
		}
		Vector3d<T> operator*(const T& _n) const
		{
			return Vector3d<T>(X * _n, Y * _n, Z * _n);
		}
		Vector3d<T>& operator*=(const T& _n)
		{
			X *= _n;
			Y *= _n;
			Z *= _n;

			return *this;
		}
		Vector3d<T> operator/(const T& _n) const
		{
			return Vector3d<T>(X / _n, Y / _n, Z / _n);
		}
		Vector3d<T>& operator/=(const T& _n)
		{
			X /= _n;
			Y /= _n;
			Z /= _n;

			return *this;
		}

		//! read by index number.
		T operator[](const u32& _index) const
		{
			if (_index < 0 || _index > 2)
			{
				printf("ERROR ocurr. Index beyond limit!\n");
				exit(-1);
			}
			if (_index == 0)
			{
				return X;
			}
			else if (_index == 1)
			{
				return Y;
			}
			return Z;
		}

		//! Sort in order X, Y, Z.
		/** for example,(Y > other.Y) while (X == other.X),we say bigger than other
		on matter if (Z <= other.Z)
		*/
		bool operator<(const Vector3d<T>& _v3) const
		{
			return (X < _v3.X && !kkmath::equals(X, _v3.X)) ||
				(kkmath::equals(X, _v3.X) && Y > _v3.Y && !kkmath::equals(Y, _v3.Y)) ||
				(kkmath::equals(X, _v3.X) && kkmath::equals(Y, _v3.Y) && Z < _v3.Z && !kkmath::equals(Z, _v3.Z));
		}

		//! Sort in order X, Y, Z.
		bool operator<=(const Vector3d<T>& _v3) const
		{
			return (X <= _v3.X || kkmath::equals(X, _v3.X)) ||
				(kkmath::equals(X, _v3.X) && Y <= _v3.Y || kkmath::equals(Y, _v3.Y)) ||
				(kkmath::equals(X, _v3.X) && kkmath::equals(Y, _v3.Y) && Z <= _v3.Z || kkmath::equals(Z, _v3.Z));
		}

		//! Set in order X, Y, Z.
		bool operator>(const Vector3d<T>& _v3) const
		{
			return (X > _v3.X && !kkmath::equals(X, _v3.X)) ||
				(kkmath::equals(X, _v3.X) && Y > _v3.Y && !kkmath::equals(Y, _v3.Y)) ||
				(kkmath::equals(X, _v3.X) && kkmath::equals(Y, _v3.Y) && Z > _v3.Z && !kkmath::equals(Z, _v3.Z));
		}

		//! Sort in order X, Y, Z.
		bool operator>=(const Vector3d<T>& _v3) const
		{
			return (X >= _v3.X || kkmath::equals(X, _v3.X)) ||
				(kkmath::equals(X, _v3.X) && Y >= _v3.Y || kkmath::equals(Y, _v3.Y)) ||
				(kkmath::equals(X, _v3.X) && kkmath::equals(Y, _v3.Y) && Z >= _v3.Z || kkmath::equals(Z, _v3.Z))
		}

		//! Sort in order X, Y, Z.
		bool operator!=(const Vector3d<T>& _v3) const
		{
			return this->equals(_v3);
		}

		//! Sort in order X, Y, Z.
		bool operator==(const Vector3d<T>& _v3) const
		{
			return this->equals(_v3);
		}

		//! Return if vector equals the other one.
		bool equals(const Vector3d<T>& _v3, const T tolerance = (T)kkmath::ROUNDING_ERROR_F32) const
		{
			return kkmath::equals(X, _v3.X, tolerance) && kkmath::equals(Y, _v3.Y, tolerance) && kkmath::equals(Z, _v3.Z, tolerance);
		}

		Vector3d<T>& set(const T& _x, const T& _y, const T& _z) { X = _x; Y = _y; Z = _z; return *this; }
		Vector3d<T>& set(const Vector3d<T>& _v3) { X = _v3.X; Y = _v3.Y; Z = _v3.Z; }

		//! Get length from origin.
		/** get the length from origin point,sqrted
		*/
		T getLength() const
		{
			return kkmath::squareroot(X * X + Y * Y + Z * Z);
		}

		//! Get squared length of the vector.
		/** get the length from origin point,but not sqrt
		*/
		T getSquarelength() const
		{
			return X * X + Y * Y + Z * Z;
		}

		//! Get length from specific point.
		/** return the distance between two points
		*/
		T getDistanceFrom(const Vector3d<T>& _dist) const
		{
			return kkmath::squareroot(X * _dist.X + Y * _dist.Y + Z * _dist.Z);
		}

		T getSquareDistanceFrom(const Vector3d<T>& _dist) const
		{
			return X * _dist.X + Y * _dist.Y + Z * _dist.Z;
		}

		Vector3d<T>& normalize()
		{
			T& length = X * X + Y * Y + Z * Z;
			if (length == 0)
			{
				return *this;
			}
			length = kkmath::reciprocal_squareroot(length);
			X = (T)(X * length);
			Y = (T)(Y * length);
			Z = (T)(Z * length);

			return *this;
		}

		//! invert vector.
		Vector3d<T>& invert()
		{
			X *= -1;
			Y *= -1;
			Z *= -1;

			return *this;
		}

		//! Get dot product.
		T dotProuduct(const Vector3d<T>& _v3) const
		{
			return X * _v3.X + Y * _v3.Y + Z * _v3.Z;
		}

		//! Rotates the vector by a specified number of degrees.
		/** rotates the vector by a specified number of degrees around the Y axis and
		the specified center.
		*/
		void rotateXZBy(f32 degrees, const Vector3d<T>& center = Vector3d<T>())
		{
			degrees *= DEGTORAD;
			f32 cs = kkmath::K_cos(degrees);
			f32 sn = kkmath::K_sin(degrees);

			// here we set the world coord to local coord.
			X -= center.X;
			Z -= center.Z;
			set((T)(X * cs - Z * sn), Y, (T)(X *sn + Z * cs));
			// here we set the local coord to world coord.
			X += center.X;
			Z += center.Z;
		}

		//! Rotates the vector by a specified number of degrees.
		/** rotates the vector by a specified number of degrees around the Y axis and
		the specified center.
		*/
		void rotateXYBy(f32 degrees, const Vector3d<T>& center = Vector3d<T>())
		{

		}

		T X;
		T Y;
		T Z;
	};

	typedef Vector3d<f32> vector3df;
	typedef Vector3d<s32> vector3di;
}

#endif