#include <iostream>

template<class T>
void swap(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = a;
}


// Perfectforwarding
// ������ ����
void f(int&& x)
{
	std::cout << x << std::endl;
}

template<typename T>
void MyTemplate(T&& x)
{
	f(std::forward(x));
}

enum Flags
{
	none = 0,
	slow = 1, 
	poison = 2,
	bleed = 3,
	paralyse = 4
};

constexpr int operator| (Flags f1, Flags f2)
{
	return Flags(int(f1) | int(f2));
}


class Warrior
{
public:
	int mHealth;
	int mAttack;

public:
	Warrior(int h, int a) : mHealth{ h }, mAttack{ a }
	{
		
	}
};

int main()
{

	//���� (lambda)
	// [](){};


	// ĸ���� '=' , '&', []
	// = ����
	// & ����
	[]

	// �Ű�����
	() 
	
	// body
	{};

	int x = 100;
	f(std::move(x));
	f(0);
	
	std::cout << x << std::endl;
	x = 1;




	//////////////////////////////////////////
	// constexpr


	Flags myStatus{};

	switch (myStatus)
	{
	case slow:
		break;

	case slow | paralyse:
		break;
	}

	// int a = 1;
	// const int a1 = a;				// Compile & run-time constant
	// constexpr int a2 = a;			// Compile-time constant



	//����Ʈ ������
	// C++11
	std::unique_ptr<int> p { new int };

	*p = 1;

	std::cout << *p << std::endl;


	// C++ 14
	std::unique_ptr<int>p2 = std::make_unique<int>();


	// make_unique���� �����ڸ� �״�� ����� �� ����.
	std::unique_ptr<Warrior>spWarrior = std::make_unique<Warrior>(100,20);

	std::cout << spWarrior->mAttack << std::endl;
	
	spWarrior.release();	// delete p;					����⸸ �ϴ� ��
	spWarrior.reset();		// delete p; p = nullptr;		������� �ʱ�ȭ���� �ϴ� ��

	Warrior* ptr = spWarrior.get();		// �Ϲ� ������
	
	return 0;
}


// decltype : Ÿ���� ���� �� �� ��� 


// Class

// MyClass (const MyClass&)   : ���� ������
// MyClass (MyClass&&)		  : �̵� ������

// MyClass& operator= (const MyClass&) // ���� ���� ������
// MyClass& operator= (MyClass&&)	   // �̵� ���� ������

// �븮 ������ (delegating constructor)
// MyClass : MyClass(1,1)


// enumclass
enum class Flags
{
	slow,
	poison
};

int Fumain()
{
	Flags f;
	
	f = Flags::slow;

	switch (f)
	{
	case Flags::slow:
		break;
	case Flags::poison:
		break;
	}
}


template<typename T>
T Sum(T first)
{
	return first;
}

template<typename T, typename ... Args>
T sum(T first, Args... args)
{
	return first + sum(args...);
}


// c++11

template<typename ... Args>
auto Sum(Args...args)
{
	return args + ...;
}



