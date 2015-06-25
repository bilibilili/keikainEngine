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
	keikain::vector3df v3(2, 2, 1);
	printf("%d-------%d\n", vi.X, vi.Y);
	vi.normalize();
	printf("%f-------%f\n", vi.X, vi.Y);
	printf("%f\n", vi[1]);

	printf("%f\n",  v3.getLength());
	return 0;
}