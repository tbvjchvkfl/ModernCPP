#pragma once
#include <iostream>
#include <future>


void PlayMovie()
{
	for (int i = 0; i < 1000; i++)
	{
		std::cout << i << std::endl;
	}
}

void Download()
{
	for (char i = 33; i < 125; i++)
	{
		std::cout << i << std::endl;
	}
}

void Ex_1()
{
	std::future<void> job1 = std::async(PlayMovie);
	std::future<void> job2 = std::async(Download);
	std::cout << "모든 작업이 끝났습니다." << std::endl;
}


