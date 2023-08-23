#pragma once
#include <iostream>
#include <functional>
#include <regex> // regular expression

// functional
using namespace std::placeholders;

void F(int a, char b)
{
	
}

void Ex_0()
{
	auto functor1 = std::bind(F, _1, _2);
	functor1(1, 'a');

	auto functor2 = std::bind(F, _2, _1);
	functor2('a', 1);

	auto functor3 = std::bind(F, 10, _1);
	functor3('a');
}

void Ex_1()
{
	std::cout << "이메일 : ";
	std::string email;
	std::cin >> email;
	
	
	// (\\w + [\\w\\.] *)@(\\w + [\\w\\.] *)\\.([A - Za - z] + )

	// 정규 표현식
	std::regex pattern("(\\w+[\\w\\.]*)@(\\w+[\\w\\.]*)\\.([A-Za-z]+)");

	// 로우 리터럴 버전
	std::regex pattern(R"(\w+[\w\.]*)@(\w+[\w\.]*)\.([A-Za-z]+)");
	if (std::regex_match(email, pattern))
	{
		std::cout << "올바른 메일 주소" << std::endl;
	}
	else
	{
		std::cout << "삑" << std::endl;
	}
}