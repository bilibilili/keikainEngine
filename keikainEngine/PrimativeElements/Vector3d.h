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

		//! Return if this vector interpreted as a point is on a line between two other points.
		bool isBetweenPoints(const Vector3d<T>& _begin, const Vector3d<T>& _end) const
		{
			const T f = (_end - _begin).getSquareLength();
			return getSquareDistanceFrom(_begin) <= f && getSquareDistanceFrom(_end) <= f;
		}

		Vector3d<T>& normalize()
		{
			f32 length = X * X + Y * Y + Z * Z;
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
		T dotProduct(const Vector3d<T>& _v3) const
		{
			return X * _v3.X + Y * _v3.Y + Z * _v3.Z;
		}

		//! Get cross product.
		Vector3d<T> crossProduct(const Vector3d<T>& _p) const
		{
			return Vector3d<T>(Y * _p.Z - Z * _p.Y, Z * _p.X - X * _p.Z, X * _p.Y - Y * _p.X);
		}

		//! Rotates the vector by a specified number of degrees.
		/** rotates the vector by a specified number of degrees around the Y axis and
		the specified center.
		*/
		void rotateXZBy(f32 degrees, const Vector3d<T>& center = Vector3d<T>())
		{
			degrees *= kkmath::DEGTORAD;
			const f32 cs = kkmath::K_cos(degrees);
			const f32 sn = kkmath::K_sin(degrees);

			// here we set the world coord to local coord.
			X -= center.X;
			Z -= center.Z;
			set((T)(X * cs - Z * sn), Y, (T)(X * sn + Z * cs));
			// here we set the local coord to world coord.
			X += center.X;
			Z += center.Z;
		}

		//! Rotates the vector by a specified number of degrees.
		/** rotates the vector by a specified number of degrees around the Z axis and
		the specified center.
		*/
		void rotateXYBy(f32 degrees, const Vector3d<T>& center = Vector3d<T>())
		{
			degrees *= kkmath::DEGTORAD;
			const f32 cs = kkmath::K_cos(degrees);
			const f32 sn = kkmath::K_sin(degrees);

			// here we set the world coord to local coord.
			X -= center.X;
			Y -= center.Y;
			set((T)(X * cs - Y * sn), (T)(X * sn + Y * cs), Z);
			// here we set the local coord to world coord.
			X += center.X;
			Y += center.Y;
		}

		//! Rotate the vector by a specified number of degrees.
		/** rotates the vector by a specified number of degrees around the X axis and
		the specified center.
		*/
		void rotateYZBy(f32 degrees, const Vector3d<T>& center = Vector3d<T>())
		{
			degrees *= kkmath::DEGTORAD;
			const f32 cs = kkmath::K_cos(degrees);
			const f32 sn = kkmath::K_sin(degrees);

			// here we set the world coord to local coord.
			Y -= center.Y;
			Z -= center.Z;
			set(X, (T)(Y * cs - Z * sn), (T)(Y * sn + Z * cs));
			// here we set the local coord to world coord.
			Y += center.Y;
			Z += center.Z;
		}

		//! Create an interpolated vector between this vector and another vector.
		/** the d value between 0.0f and 1.0f.
		*/
		Vector3d<T> getInterpolated(const Vector3d<T>& _v3, f32 d) const
		{
			const f32 inv = 1.0f - d;
			return Vector3d<T>((T)(_v3.X * inv + X * d), (T)(_v3.Y * inv + Y * d), (T)(_v3.Z * inv + Z * d));
		}

		//! Create an interpolated vector between this and other two vector.
		/** the d value between 0.0f and 1.0f.
		*/
		Vector3d<T> getInterpolatedQuadratic(const Vector3d<T>& _v1, const Vector3d<T>& _v2, f32 d) const
		{
			const f32 inv = 1.0f - d;
			const f32 mul0 = inv * inv;
			const f32 mul1 = 2.0f - d * inv;
			const f32 mul2 = d * d;

			return Vector3d<T>((T)(X * mul0 + _v1.X * mul1 + _v2.X * mul2),
								(T)(Y * mul0 + _v1.Y * mul1 + _v2.Y * mul2),
								(T)(Z * mul0 + _v1.Z * mul1 + _v2.Z * mul2));
		}

		//! Get the vector linearly between this and other vector.
		/** d value between 0.0f and 1.0f.
		*/
		Vector3d<T>& interpolate(const Vector3d<T>& _v3a, const Vector3d<T>& _v3b, f32 d)
		{
			X = (T)((T)_v3b.X + (_v3a.X - _v3b.X) * d);
			Y = (T)((T)_v3b.Y + (_v3a.Y - _v3b.Y) * d);
			Z = (T)((T)_v3b.Z + (_v3a.Z - _v3b.Z) * d);
			return *this;
		}

		//! Get the rotations
		Vector3d<T> getHorizontalAngle() const
		{
			Vector3d<T> angle;

			const f32 tmp = (kkmath::K_atan2((f32)X, (f32)Z) * kkmath::RADRODEG);
			angle.Y = (T)tmp;

			if (angle.Y < 0)
			{
				angle.Y += 360;
			}
			if (angle.Y >= 360)
			{
				angle.Y -= 360;
			}

			const f32 z1 = kkmath::squareroot(X *X + Z * Z);
			angle.X = (T)(kkmath::K_atan2() * RADTODEG - 90.0);

			if (angle.X < 0)
			{
				angles.X += 360;
			}
			if (angles.X >= 360)
			{
				angle.X -= 360;
			}

			return angle;
		}

		//! Get the spherical coordinate angles.
		Vector3d<T> getSphericalCoordinateAngles() const
		{
			Vector3d<T> angle;
			const f32 length = X * X + Y * Y + Z * Z;

			if (length)
			{
				if (X != 0)
				{
					angle.Y = (T)(kkmath::K_atan2((f32)Z, (f32)X) * RADTOREG);
				}
				else if (Z < 0)
				{
					angle.Y = 180;
				}

				angle.X = (T)(kkmath::K_acos(Y * kkmath::reciprocal_squareroot(length)) * RADTODEG);
			}
			return angle;
		}

		//! Fill an array of 4 values with the vector.
		void getAs4Values(T* array) const
		{
			array[0] = X;
			array[1] = Y;
			array[2] = Z;
			array[3] = 0;
		}

		//! Fill an array of 3 values with the vector.
		void getAs3Values(T* array) const
		{
			array[0] = X;
			array[1] = Y;
			array[2] = Z;
		}

		T X;
		T Y;
		T Z;
	};

	typedef Vector3d<f32> vector3df;
	typedef Vector3d<s32> vector3di;
}

#endif