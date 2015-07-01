// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#ifndef __KEIKAIN_KENGINE_H__
#define __KEIKAIN_KENIGNE_H__

#include "KReferenceCounted.h"
#include "KRenderManager.h" 
#include "KFileManager.h"
#include "KSceneManager.h"
#include "KCursorManager.h"
#include "KTimer.h"
#include "KRandomManager.h"

// An important class.
// We can access other objects by this class.
// It is created by createEngine() in Keikain.h.
namespace keikain
{
	class KEngine : public virtual KReferenceCounted
	{
	public:
		//! Runs the engine
		/** It also represented the engine status.
		usually we put it input while loop.
		while(engine->runEngine())
		{
			// draw everything
		}
		*/
		virtual bool runEngine() = 0;

		//! Provides access to the render system for drawing geometory.
		/** return the pointer to the render system.
		*/
		virtual KRenderManager* getRenderingSystem() = 0;
		
		//! Provides access to the file system.
		/** return pointer to the file system.
		*/
		virtual KFileManager* getFileSystem() = 0;

		//! Provides access to the scene manager.
		/** return pointer to the scene manager
		*/
		virtual KSceneManager* getSceneManager() = 0;

		//! Provides access to the cursor control.
		/** return Pointer to the cursor control
		*/
		virtual KCursorManager* getCursorManager() = 0;

		//! Provides access to the engine's time.
		/** return pointer to the KTimer
		*/
		virtual KTimer* getTimer() = 0;

		//! Provides access to the Randomizer.
		/** return pointer to the KRandomManager
		*/
		virtual KRandomManager* getRadomManager() = 0;

		//! Check if the keikain engine is running in fullscreen mode.
		/** return true if window is fullscreen
		*/
		virtual bool isFullScreen() const = 0;

		//! Close itself,close the engine.
		/** when the engine is close,the run() alaways return false
		*/
		virtual void closeEngine() = 0;
		
		//! Get the engine version.
		/** return the version string about engine
		*/
		virtual const c8* getVersion() const = 0;
	private:

	};
}

#endif