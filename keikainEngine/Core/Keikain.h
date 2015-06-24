// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KEIKAIN_H__
#define __KEIKAIN_KEIKAIN_H__

#include "KCursorManager.h"
#include "KEngine.h"
#include "KFileManager.h"
#include "KReferenceCounted.h"
#include "KRenderManager.h"
#include "KSceneManager.h"
#include "../Utilities/KCompileConfig.h"
#include "../Utilities/KTypes.h"
#include "KCreateEngineParameters.h"

namespace keikain
{
	//! We can get an engine from this function.
	/** return a pointer to KEngine
	*/
	extern "C" KEIKAIN_API KEngine* KEIKAIN_CALL_CONV createEngine(const KCreateEngineParameters&);
}

#endif