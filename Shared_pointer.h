#pragma once
#include <iostream>

class Image
{

};

class Demon
{
public:
	int mHealth;
	int mAttack;

	std::shared_ptr<Image> mspImage;

	Demon(int h, int a, std::shared_ptr<Image> spImage) : mHealth{ h }, mAttack{ a }, mspImage{ spImage }
	{

	}
};

int SharedPointer()
{
	std::shared_ptr<Image> spImage = std::make_shared<Image>();
	{
		std::unique_ptr<Demon> spDemon = std::make_unique<Demon>(100, 10, spImage);
		{
			std::unique_ptr<Demon> spDemon2 = std::make_unique<Demon>(100, 10, spImage);
		}
	}
}