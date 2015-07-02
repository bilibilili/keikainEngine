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

int main()
{
	keikain::line2df ray;
	printf("X: %f-----Y: %f\n", ray.start.X, ray.end.Y);
	printf("X: %f-----Y: %f\n", ray.getMiddlePoint().X, ray.getMiddlePoint().Y);
	printf("%f\n", ray.getLength());

	keikain::line3df ray3;
	printf("Length:%f\n", ray3.getLength());

	printf("X: %f---Y: %f---Z: %f\n", ray3.getMiddlePoint().X, ray3.getMiddlePoint().Y, ray3.getMiddlePoint().Z);
	return 0;
}