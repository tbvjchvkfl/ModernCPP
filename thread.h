#pragma once
#include <iostream>
#include <thread>
#include <mutex>

std::mutex gMutex;

void PlayMovie()
{
	for (int i = 0; i < 1000; i++)
	{
		gMutex.lock();
		std::cout << i << std::endl;
		gMutex.unlock();
	}
}

void Download()
{
	for (char i = 33; i < 125; i++)
	{
		gMutex.lock();
		std::cout << i << std::endl;
		gMutex.unlock();
	}
}

void Ex_1()
{
	std::thread job1(PlayMovie);
	std::thread job2(Download);

	job1.join();
	job2.join();

	std::cout << "모든 작업이 끝났습니다." << std::endl;
}

