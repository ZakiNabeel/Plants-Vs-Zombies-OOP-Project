#pragma once
#ifndef Level_h
#define Level_h
#include"ZombieFactory.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
using namespace std;
class Levels {
protected:	
	int numZombies;
	ZombieFactory zombieFactory;
	sf::Texture textureBackGround;
	sf::Sprite spriteBackGround;
public:
	Levels(int);
	virtual void createBack(sf::RenderWindow& window) = 0;
	void setNumZombies(int n);
	~Levels();
	void display(sf::RenderWindow & Window);
	void update();
};

#endif // !Level.h

