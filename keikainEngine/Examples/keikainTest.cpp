// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../Core/Keikain.h"
#include "../Math/KMath.h"
#include "../PrimativeElements/Vector2d.h"
#include "../PrimativeElements/Vector3d.h"
#include "../PrimativeElements/Line2d.h"
#include "../PrimativeElements/Line3d.h"
#include "../PrimativeElements/Plane3d.h"
#include "../PrimativeElements/Matrix4.h"
#include "../PrimativeElements/Dimension2d.h"

int main()
{
	keikain::dimension2df d2d(2.324f, 9.43f);
	keikain::dimension2df d2d1(keikain::vector2df(34.12f, 432.2f));
	printf("%f -- %f\n", d2d.Width, d2d.Height);

	return 0;
}