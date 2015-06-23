// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in keikain.h

#ifndef __KEIKAIN_KERFERENCECOUNTED_H__
#define __KEIKAIN_KERFERENCECOUNTED_H__

#include "../Utilities/KType.h"

namespace keikain
{
	// base class of most objects.
	// This class provides references counting through the methods grab() and drop().
	class KReferenceCounted
	{
	public:
		// Constructor
		KReferenceCounted()
			: ReferenceCounter(1) {}
		// Destructor
		virtual ~KReferenceCounted() {}
		// Grab the object. Increments the reference counter by one.
		void grab() const { ++ReferenceCounter; }
		// Drop the objects. First decrements the reference counter by one.
		// Delete the pointer when the ReferenceCounter became zero
		bool drop() const
		{
			--ReferenceCounter;
			if (!ReferenceCounter)
			{
				delete this;
				return true;
			}
			return false;
		}

		// Get the reference count.
		s32 getReferenceCount() const
		{
			return ReferenceCounter;
		}
	private:
		mutable s32 ReferenceCounter;
	};
}

#endif