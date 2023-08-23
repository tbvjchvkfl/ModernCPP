#pragma once
#include <iostream>

class Warrior
{
public:
	int mHealth;
	int mAttack;
};


//����Ʈ ������
// 
void Unique_ptr()
{
	// C++11
	std::unique_ptr<int> p { new int };

	*p = 1;

	std::cout << *p << std::endl;


	// C++ 14
	std::unique_ptr<int>p2 = std::make_unique<int>();


	// make_unique���� �����ڸ� �״�� ����� �� ����.
	std::unique_ptr<Warrior>spWarrior = std::make_unique<Warrior>(100, 20);

	std::cout << spWarrior->mAttack << std::endl;

	spWarrior.release();	// delete p;					����⸸ �ϴ� ��
	spWarrior.reset();		// delete p; p = nullptr;		������� �ʱ�ȭ���� �ϴ� ��

	Warrior* ptr = spWarrior.get();		// �Ϲ� ������

}
	