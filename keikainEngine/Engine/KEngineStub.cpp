// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#include "KEngineStub.h"
#include "../Core/KCreateEngineParameters.h"

namespace keikain
{
	KEngineStub::KEngineStub(const KCreateEngineParameters& _param)
	{

	}

	KEngineStub::~KEngineStub()
	{

	}

	bool KEngineStub::runEngine()
	{
		return false;
	}

	KRenderManager* KEngineStub::getRenderingSystem()
	{
		return NULL;
	}

	KFileManager* KEngineStub::getFileSystem()
	{
		return NULL;
	}

	KSceneManager* KEngineStub::getSceneManager()
	{
		return NULL;
	}

	KCursorManager* KEngineStub::getCursorManager()
	{
		return NULL;
	}

	KTimer* KEngineStub::getTimer()
	{
		return NULL;
	}

	KRandomManager* KEngineStub::getRadomManager()
	{
		return NULL;
	}

	bool KEngineStub::isFullScreen() const
	{
		return false;
	}

	void KEngineStub::closeEngine()
	{

	}

	c8* KEngineStub::getVersion()
	{
		return NULL;
	}
}