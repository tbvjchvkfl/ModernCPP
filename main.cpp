#include <iostream>

template<class T>
void swap(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = a;
}


// Perfectforwarding
// 완전한 전달
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

	//람다 (lambda)
	// [](){};


	// 캡쳐절 '=' , '&', []
	// = 복사
	// & 참조
	[]

	// 매개변수
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



	//스마트 포인터
	// C++11
	std::unique_ptr<int> p { new int };

	*p = 1;

	std::cout << *p << std::endl;


	// C++ 14
	std::unique_ptr<int>p2 = std::make_unique<int>();


	// make_unique에는 생성자를 그대로 사용할 수 있음.
	std::unique_ptr<Warrior>spWarrior = std::make_unique<Warrior>(100,20);

	std::cout << spWarrior->mAttack << std::endl;
	
	spWarrior.release();	// delete p;					지우기만 하는 것
	spWarrior.reset();		// delete p; p = nullptr;		지우고나서 초기화까지 하는 것

	Warrior* ptr = spWarrior.get();		// 일반 포인터
	
	return 0;
}


// decltype : 타입이 뭔지 모를 때 사용 


// Class

// MyClass (const MyClass&)   : 복사 생성자
// MyClass (MyClass&&)		  : 이동 생성자

// MyClass& operator= (const MyClass&) // 복사 대입 연산자
// MyClass& operator= (MyClass&&)	   // 이동 대입 연산자

// 대리 생성자 (delegating constructor)
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



