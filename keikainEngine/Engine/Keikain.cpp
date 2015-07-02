// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#include "../Core/Keikain.h"
#include "../Core/KCreateEngineParameters.h"
#include "../Core/KEngine.h"
#include <iostream>

namespace keikain
{
	extern "C" KEngine* KEIKAIN_CALL_CONV createEngine(const KCreateEngineParameters& _param)
	{
		KEngine* dev = 0;

		return dev;
	}
}