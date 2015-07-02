// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KCOLOR_H__
#define __KEIKAIN_KCOLOR_H__

#include "../Utilities/KTypes.h"
#include "../Math/KMath.h"

namespace keikain
{
	//! An enum for the color format of texture used by the keikain engine.
	enum KCOLOR_FORMAT
	{
		//! 16 bit color format used by the software driver.
		KCF_A1R5G5B5 = 0,
		//! Standard 16 bit color format.
		KCF_R5G6B5,
		//! 24 bit color, no alpha channel, but 8 bit for red, green and blue.
		KCF_R8G8B8,
		//! Default 32 bit color format, 8 bits are used for every component: red, green, blue and alpha.
		KCF_A8R8G8B8,
		//! 16 bit floating point format using 16 bits for red channel.
		KCF_R16F,
		//! 32 bit floating point format using 16 bits for the red channel and 16 bits for the green channel.
		KCF_G16R16F,
		//! 64 bit floating point format 16 bits are used for the red, green, blue and alpha channel.
		KCF_A16B16G16R16F,
		//! 32 bit floating point format using 32 bits for the red channel.
		KCF_R32F,
		//! 64 bit floating point format using 32 bits for the red channel and 32 bits for the green channel.
		KCF_G32R32F,
		//! 128 bit floating point format, 32 bits are used for the red, green, blue and alpha channels.
		KCF_A32B32G32R32F,
		//! Unknown color format.
		KCF_UNKNOW

	};

	//! Creates a 16 bit A1R5G5B5 color
	inline u16 RGBA16(u32 _r, u32 _g, u32 _b, u32 _a = 0xff)
	{
		return (u16)((_a & 0x80) << 8 | (_r & 0xf8) << 7 | (_g & 0xf8) << 2 | (_b & 0xf8) >> 3);
	}
	//! Creates a 16 bit A1R5G5B5 color.
	inline u16 RGB16(u32 _r, u32 _g, u32 _b)
	{
		return RGBA16(_r, _g, _b);
	}
	//! Creates a 16 bit A1R5G5B5 color, based on 16 bit input values.
	inline u16 RGB16from16(u16 _r, u16 _g, u16 _b)
	{
		return (0x8000 | (_r & 0x1f) << 10 | (_g & 0x1f) << 5 | (_b & 0x1f));
	}
	//! Converts a 32 bit color to a 16 bit A1R5G5B5 color.
	inline u16 X8R8G8B8toA1R5G5B5(u32 _color)
	{
		return (u16)(0x8000 | (_color & 0x00f80000) >> 9 | (_color & 0x0000f800) >> 6 | (_color & 0x000000f8) >> 3);
	}
	//! Converts a 32 bit color to a 16 bit A1R5G5B5 color.
	inline u16 A8R8G8B8toA1R5G5B5(u32 _color)
	{
		return (u16)((_color & 0x80000000) >> 16 | (_color & 0x00f80000) >> 9 | (_color & 0x0000f800) >> 6 | (_color & 0x000000f8) >> 3);
	}
	//! Converts a 32 bit color to a 16 bit R5G6B5 color.
	inline u16 A8R8G8B8toR5G6B5(u32 _color)
	{
		return (u16)((_color & 0x00f80000) >> 8 | (_color & 0x0000fc00) >> 5 | (_color & 0x000000f8) >> 3);
	}
	//! Convert A8R8G8B8 color from A1R5G5B5 color.
	inline u32 A1R5G5B5toA8R8G8B8(u16 _color)
	{
		return (((-((s32)_color & 0x00008000) >> (s32)31) & 0xff000000) | ((_color & 0x00007c00) << 9) | ((_color & 0x00007000) << 4) |
			((_color & 0x000003e0) << 6) | ((_color & 0x00000380) << 1) | ((_color & 0x0000001f) << 3) | ((_color & 0x0000001c) >> 2));
	}
	//! Returns A8R8G8B8 color from R5G6B5 color.
	inline u32 R5G6B5toA8R8G8B8(u16 _color)
	{
		return 0xff000000 | ((_color & 0xf800) << 8) | ((_color & 0x07e0) << 5) | ((_color & 0x001f) << 3);
	}
	//! Returns A1R5G5B5 color from R5G6B5 color.
	inline u16 R5G6B5toA1R5G5B5(u16 _color)
	{
		return 0x8000 | (((_color & 0xffc0) >> 1) | (_color & 0x1f));
	}
	//! Returns R5G6B5 color from R5G6B5 color.
	inline u16 A1R5G5B5toR5G6B5(u16 _color)
	{
		return (((_color & 0x7fe0) << 1) | (_color & 0x1f));
	}
	//! Returns the alpha component from A1R5G5B5 color.
	inline u32 getAlpha(u16 _color)
	{
		return ((_color >> 15) & 0x1);
	}
	//! Returns the red component from A1R5G5B5 color.
	inline u32 getRed(u16 _color)
	{
		return ((_color >> 10) & 0x1f);
	}
	//! Returns the green component from A1R5G5B5 color.
	inline u32 getGreen(u16 _color)
	{
		return ((_color >> 5) & 0x1f);
	}
	//! Returns the blue component from A1R5G5B5 color.
	inline u32 getBlue(u16 _color)
	{
		return (_color & 0x1f);
	}
	//! Returns the average from a 16 bit A1R5G5B5 color.
	inline s32 getAverage(s16 _color)
	{
		return ((getRed(_color) << 3) + (getGreen(_color) << 3) + (getBlue(_color) << 3)) / 3;
	}

	//! Class represents 32 bit ARGB color.
	/** the color value for alpha, red, green, blue are
	store in a single u32
	*/
	class KColor
	{
	public:
		KColor(u32 _a, u32 _r, u32 _g, u32 _b) : color(((_a & 0xff) << 24) | ((_r & 0xff) << 16) | ((_g & 0xff) << 8) | (_b & 0xff)) {}
		KColor(u32 _color) : color(_color) {}

		//! Returns the alpha component of the color.
		u32 getAlpha() const { return color >> 24; }
		//! Returns the red component of the color.
		u32 getRed() const { return (color >> 16) & 0xff; }
		//! Returns the green component of the color.
		u32 getGreen() const { return (color >> 8) & 0xff; }
		//! Returns the blue component of the color.
		u32 getBlue() const { return color & 0xff; }
		//! Get lightness of the color in the range[0,255].
		f32 getLightness() const
		{
			return 0.5f * (kkmath::K_max(getRed(), getGreen(), getBlue()) + kkmath::K_min(kkmath::K_min(getRed(), getGreen()), getBlue()));
		}
		//! Get luminance of the color in the range[0,255].
		f32 getLuminance() const
		{
			return 0.3f * getRed() + 0.53f * getGreen() + 0.11f * getBlue();
		}
		//! Get average intensity of the color in the range[0,255].
		u32 getAverage() const
		{
			return (getRed() + getGreen() + getBlue()) / 3;
		}

		//! Set the alpha component of the color.
		void setAlpha(u32 _a)
		{
			color = ((_a & 0xff) << 24) | (color & 0x00ffffff);
		}
		//! Sets the red component of the color.
		void setRed(u32 _r)
		{
			color = ((_r & 0xff) << 16) | (color & 0xff00ffff);
		}
		//! Sets the green component of the color.
		void setGreen(u32 _g)
		{
			color = ((_g & 0xff) << 8) | (color & 0xffff00ff);
		}
		//! Sets the blue component of the color.
		void setBlue(u32 _b)
		{
			color = (_b & 0xff) | (color & 0xffffff00);
		}
		//! Calculates a 16 bit A1R5G5B5 value of this color.
		u16 toA1R5G5B5() const
		{
			return A8R8G8B8toA1R5G5B5(color);
		}
		//! Converts color to OpenGL color format.
		void toOpenGLColor(u8* _dest) const
		{
			*_dest = (u8)getRed();
			*++_dest = (u8)getGreen();
			*++_dest = (u8)getBlue();
			*++_dest = (u8)getAlpha();
		}
		//! Sets all four components of the color at once.
		void set(u32 _a, u32 _r, u32 _g, u32 _b)
		{
			color = (((_a & 0xff) << 24) | ((_r & 0xff) << 16) | ((_g & 0xff) << 8) | (_b & 0xff));
		}
		void set(u32 _col)
		{
			color = _col;
		}

		//! Compares the color to another color.
		bool operator==(const KColor& _other) const
		{
			return _other.color == color;
		}

		//! Compares the color to another color.
		bool operator!=(const KColor& _other) const
		{
			return _other != color;
		}

		//! Comparison operator.
		bool operator<(const KColor& _other) const
		{
			return (color < _other.color);
		}

		//! Adds two colors, result is clamped to 0.255 values.
		KColor operator+(const KColor& _other) const
		{
			return KColor(kkmath::K_min(getAlpha() + _other.getAlpha(), 255u),
				kkmath::K_min(getRed() + _other.getRed(), 255u),
				kkmath::K_min(getGreen() + _other.getGreen(), 255u),
				kkmath::K_min(getBlue() + _other.getBlue(), 255u));
		}
		//! Interpolates the color with a f32 value to another color.
		KColor getInterpolated(const KColor& _other, f32 _d) const
		{
			_d = kkmath::K_clamp(_d, 0.f, 1.f);
			const f32 inv = 1.f - _d;
			return KColor((u32)kkmath::round32(_other.getAlpha() * inv + getAlpha() * _d),
				(u32)kkmath::round32(_other.getRed() * inv + getRed() * _d),
				(u32)kkmath::round32(_other.getGreen() * inv + getGreen() * _d),
				(u32)kkmath::round32(_other.getBlue() * inv + getBlue() * _d));
		}
		//! Returns interpolated color.
		KColor getInterpolated_quadratic(const KColor& _c1, const KColor& _c2, f32 _d) const
		{
			_d = kkmath::K_clamp(_d, 0.f, 1.f);
			const f32 inv = 1.f - _d;
			const f32 mul0 = inv * inv;
			const f32 mul1 = 2.f * _d * inv;
			const f32 mul2 = _d * _d;

			return KColor(kkmath::K_clamp(kkmath::floor32(getAlpha() * mul0 + _c1.getAlpha() * mul1 + _c2.getAlpha() * mul2), 0, 255),
				kkmath::K_clamp(kkmath::floor32(getRed() * mul0 + _c1.getRed() * mul1 + _c2.getRed() * mul2), 0, 255),
				kkmath::K_clamp(kkmath::floor32(getGreen() * mul0 + _c1.getGreen() * mul1 + _c2.getGreen() * mul2), 0, 255),
				kkmath::K_clamp(kkmath::floor32(getBlue() * mul0 + _c1.getBlue() + mul1 + _c2.getBlue() * mul2), 0, 255));
		}

		//! Set the color by expecting data in the given format.
		void setData(const void* _data, KCOLOR_FORMAT _format)
		{
			switch (_format)
			{
			case KCF_A1R5G5B5:
				color = A1R5G5B5toA8R8G8B8(*(u16*)_data);
				break;
			case KCF_R5G6B5:
				color = R5G6B5toA8R8G8B8(*(u16*)_data);
				break;
			case KCF_A8R8G8B8:
				color = *(u32*)_data;
				break;
			case KCF_R8G8B8:
				{
					u8* p = (u8*)_data;
					set(255, p[0], p[1], p[2]);
				}
				break;
			default:
				color = 0xffffffff;
				break;
			}
		}
		//! Write the color to data in the defined format.
		void getData(void* _data, KCOLOR_FORMAT _format)
		{
			switch (_format)
			{
			case KCF_A1R5G5B5:
			{
				u16* dest = (u16*)_data;
				*dest = A8R8G8B8toA1R5G5B5(color);
			}
				break;
			case KCF_R5G6B5:
			{
				u16* dest = (u16*)_data;
				*dest = A8R8G8B8toR5G6B5(color);
			}
				break;
			case KCF_R8G8B8:
			{
				u8* dest = (u8*)_data;
				dest[0] = (u8)getRed();
				dest[1] = (u8)getGreen();
				dest[2] = (u8)getBlue();
			}
				break;
			case KCF_A8R8G8B8:
			{
				u32* dest = (u32*)_data;
				*dest = color;
			}
				break;
			default:
				break;
			}
		}

		//! Color in A8R8G8B8 format.
		u32 color;
	};
}

#endif