// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in keikain.h

#ifndef __KEIKAIN_KSCRIPT_H__
#define __KEIKAIN_KSCRIPT_H__

#include "KReferenceCounted.h"
#include "../Utilities/KTypes.h"

#include <stdio.h>

//! KScript's main function is read or write script file.
/** in the keikain engine,all the settig we put it into config file
with surfix ".kscript".
*/
namespace keikain
{
	class KScript : public virtual KReferenceCounted
	{
	public:
		//! Get the script files list from specific directory.
		/** store script file name into list, return file count
		*/
		virtual s16 getScriptFileList() = 0;

		//! Open the script file from list.
		/** return a FILE handle to the file
		*/
		virtual FILE openScriptFile() = 0;
	private:

	};
}

#endif