// Copyright (C) 2002-2015 lidenghui.
// This file is part of the "keikainEngine".
// It is inspired by irrlicht.
// For conditions of distribution and use, see copyright notice in Keikain.h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../Core/Keikain.h"

int main()
{
	keikain::s16 aa = 12;
	keikain::u8 a = 2;
	keikain::s32 i;
	printf("%d\n", a);
	printf("%d\n", (i >> 31) != 0);
	std::cout << a << " : " << "keikain" << std::endl;
	return 0;
}