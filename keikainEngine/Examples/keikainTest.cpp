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

int main()
{
	keikain::vector2df vi(461, 89);
	keikain::vector3df v3(21, 32, 13);
	keikain::vector3df v3i(2, 2, 2);
	keikain::vector3df v3f(12, 71, 20);
	printf("%f\n", (v3.getInterpolatedQuadratic(v3i, v3f, 0.25f)).X);
	return 0;
}