#pragma once
#include <iostream>

class Warrior
{
public:
	int mHealth;
	int mAttack;
};


//스마트 포인터
// 
void Unique_ptr()
{
	// C++11
	std::unique_ptr<int> p { new int };

	*p = 1;

	std::cout << *p << std::endl;


	// C++ 14
	std::unique_ptr<int>p2 = std::make_unique<int>();


	// make_unique에는 생성자를 그대로 사용할 수 있음.
	std::unique_ptr<Warrior>spWarrior = std::make_unique<Warrior>(100, 20);

	std::cout << spWarrior->mAttack << std::endl;

	spWarrior.release();	// delete p;					지우기만 하는 것
	spWarrior.reset();		// delete p; p = nullptr;		지우고나서 초기화까지 하는 것

	Warrior* ptr = spWarrior.get();		// 일반 포인터

}
	