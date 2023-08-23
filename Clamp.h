#pragma once
#include <iostream>
#include <algorithm>

void Ex_1()
{
	for (int i = -100; i < 100; i++)
	{
		std::cout << std::clamp(i, -10, 10) << std::endl;
	}
}

