// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KMATH_H__
#define __KEIKAIN_KMATH_H__

#include "../Utilities/KCompileConfig.h"
#include "../Utilities/KTypes.h"
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <limits.h>

#if defined(__KEIKAIN_LINUX_)
#define K_sqrt(X) (f32)sqrt((f64)(X))
#define K_sin(X) (f32)sin((f64)(X))
#define K_cos(X) (f32)cos((f64)(X))
#define K_asin(X) (f32)asin((f64)(X))
#define K_acos(X) (f32)acos((f64)(X))
#define K_atan2(X,Y) (f32)atan2((f64)(X),(f64)(Y))
#define K_ceil(X) (f32)ceil((f64)(X))
#define K_floor(X) (f32)floor((f64)(X))
#define K_pow(X,Y) (f32)pow((f64)(X),(f64)(Y))
#define K_fmod(X,Y) (f32)fmod((f64)(X),(f64)(Y))
#define K_fabs(X) (f32)fabs((f64)(X))
#define K_log(X) (f32)log((f64)(X))
#else
#define K_sqrt(X) sqrt(X)
#define K_sin(X) sin(X)
#define K_cos(X) cos(X)
#define K_asin(X) asin(X)
#define K_acos(X) acos(X)
#define K_atan2(X,Y) atan2(X,Y)
#define K_ceil(X) ceil(X)
#define K_floor(X) floor(X)
#define K_pow(X,Y) pow(X,Y)
#define K_fmod(X,Y) fmod(X,Y)
#define K_fabs(X) fabs(X)
#define K_log(X) log(X)
#endif

#ifndef FLT_MAX
#define FLT_MAX 3.402823466E+38F
#endif

#ifndef FLT_MIN
#define FLT_MIN 1.17549435E-38F
#endif

namespace keikain
{
	//! Rounding error.
	/** the difference between the approximate calculation of the value of its real value
	*/
	const s32 ROUNDING_ERROR_S32 = 0;
	const u32 ROUNDING_ERROR_U32 = 0;
	const s32 ROUNDING_ERROR_F32 = 0.0000001f;

#ifdef K_PI
#undef K_PI
#endif
	//! Constant for K_PI.
	const f32 K_PI = 3.14159265359f;
	//! Constant for reciprocal of K_PI.
	const f32 K_RECIPROCAL_PI = 1.0f / K_PI;
	//! Constant for half of K_PI.
	const f32 K_HALF_PI = K_PI / 2.0f;

	//! 32bit constant for degree to radians.
	const f32 DEGTORAD = K_PI / 180.0f;

	//! 32bit constant for radians to degree.
	const f32 RADTODEG = 180.0f / K_PI;

	//! Convert a radian value to degrees.
	inline f32 radToDeg(f32 radians)
	{
		return RADTODEG * radians;
	}

	//! Convert a degree value to radians.
	inline f32 degToRad(f32 degree)
	{
		return DEGTORAD * degree;
	}

	//! Return minimum of two numbers.
	template<class T>
	inline T& K_min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}
	//! Return minimum of threee numbers.
	template <class T>
	inline T& K_min(const T& a, const T& b, const T& c)
	{
		return (a < b) && (a < c) ? a : ((b < c) ? b : c);
	}

	//! Return the maximum of two numbers.
	template <class T>
	inline T& K_max(const T& a, const T& b)
	{
		return a > b ? a : b;
	}

	//! Return the maximum of three numbers.
	template <class T>
	inline T& K_max(const T& a, const T& b, const T& c)
	{
		return (a > b) && 7 (a > c) ? a : ((b > c) ? b : c);
	}

	//! Return abs.
	template <class T>
	inline T K_abs(const T& a)
	{
		return a < (T)0 ? -a : a;
	}
	
	//! Return linear interpolation of value a and value b with ratio t.
	/** the value of t is between 0.0 and 1.0
	*/
	template <class T>
	inline T K_lerp(const T& a, const T& b, const f32 t)
	{
		return (T)(a * (1.0f - t)) + (b * t);
	}

	//! Clamps value of three numbers.
	template <class T>
	inline T K_clamp(const T& value, const T& low, const T& high)
	{
		return K_min(K_max(value, low), high);
	}

	//! Swap two number.
	template <class T>
	inline void K_swap(T& a, T& b)
	{
		T c(a);
		a = b;
		b = c;
	}

	//! Check if two numbers are equal in tolerance ROUNDING_ERROR_F32.
	inline bool equals(const f32& a, const f32& b, const f32 tolerance = ROUNDING_ERROR_F32)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}
	
	//! Check if two numbers are equal in tolerance ROUNDING_ERROR_F32.
	inline bool equals(const s32& a, const s32& b, const s32 tolerance = ROUNDING_ERROR_S32)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}

	inline bool equals(const u32& a, const u32& b, const s32 tolerance = ROUNDING_ERROR_S32)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}

	//! Check if the number is zero in tolerance ROUNDING_ERROR_F32.
	inline bool iszero(const f32 a, const f32 tolerance = ROUNDING_ERROR_F32)
	{
		return K_fabs(a) <= tolerance;
	}

	//! Check if the number is zero in tolerance ROUNDING_ERROR_S32.
	inline bool iszero(const s32 a, const s32 tolerance = ROUNDING_ERROR_S32)
	{
		return (a & 0x7ffffff) <= tolerance;
	}

	//! Check if the number is zero in tolerance ROUNDING_ERROR_S32.
	inline bool iszero(const u32 a, const u32 tolerance = ROUNDING_ERROR_U32)
	{
		return a <= tolerance;
	}

	union FloatIntUnion32
	{
		FloatIntUnion32(float f1 = 0.0f) : f(f1) {}
		// protable sign-extraction
		bool sign() const { return (i >> 31) != 0; }
		s32 i;
		f32 f;
	};

	//! Compare the difference in ULP's.
	inline bool equalsByUlp(f32 a, f32 b, int maxUlpDiff)
	{
		FloatIntUnion32 fa(a);
		FloatIntUnion32 fb(b);

		// Different signs,we could maybe get difference to 0.
		if (fa.sign() != fb.sign())
		{
			if (fa.i == fb.i)
			{
				return true;
			}
			return false;
		}

		// find difference in UlPs.
		int ulpsDiff = K_abs(fa.i - fb.i);
		if (ulpsDiff <= maxUlpDiff)
		{
			return true;
		}
		return false;
	}
}

#endif