// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KENGINESTUB_H__
#define __KEIKAIN_KENGINESTUB_H__

#include "../Core/KEngine.h"
#include "../Core/KCreateEngineParameters.h"
#include "../Core/KVideoDriver.h"
#include "../Core/KFileManager.h"
#include "../Core/KSceneManager.h"
#include "../Core/KTimer.h"

namespace keikain
{
	class KEngineStub : public KEngine
	{
		KEngineStub(const KCreateEngineParameters&);
		virtual ~KEngineStub();

		//! Runs the engine
		/** It also represented the engine status.
		usually we put it input while loop.
		while(engine->runEngine())
		{
		// draw everything
		}
		*/
		virtual bool runEngine();

		//! Provides access to the render system for drawing geometory.
		/** return the pointer to the render system.
		*/
		virtual KRenderManager* getRenderingSystem();

		//! Provides access to the file system.
		/** return pointer to the file system.
		*/
		virtual KFileManager* getFileSystem();

		//! Provides access to the scene manager.
		/** return pointer to the scene manager
		*/
		virtual KSceneManager* getSceneManager();

		//! Provides access to the cursor control.
		/** return Pointer to the cursor control
		*/
		virtual KCursorManager* getCursorManager();

		//! Provides access to the engine's time.
		/** return pointer to the KTimer
		*/
		virtual KTimer* getTimer();

		//! Provides access to the Randomizer.
		/** return pointer to the KRandomManager
		*/
		virtual KRandomManager* getRadomManager();

		//! Check if the keikain engine is running in fullscreen mode.
		/** return true if window is fullscreen
		*/
		virtual bool isFullScreen() const;

		//! Close itself,close the engine.
		/** when the engine is close,the run() alaways return false
		*/
		virtual void closeEngine();

		//! Get the engine version.
		/** return the version string about engine
		*/
		virtual c8* getVersion();

	protected:
		KVideoDriver* videoDriver;
		KSceneManager* sceneManager;
		KRandomManager* randomManager;
		KTimer* timer;
		KFileManager* fileManager;
		KCreateEngineParameters* creationParams;
	};
}

#endif