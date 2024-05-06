#pragma once
#ifndef Sunflower_H
#define Sunflower_H
#include "Sun.h"
#include "NonShooter.h"
class Sunflower : public NonShooter{
	Sun* sunPtr;
	bool sunGenerated;
public:
	Sunflower(int xPos, int yPos, int h, int w, int hit);
	~Sunflower();
	void display(sf::RenderWindow& Window);
	void takeDamage();
	bool collisionCheck();
	void generateSun();
	void magic();
};
#endif