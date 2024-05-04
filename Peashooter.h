#pragma once
#ifndef Peashooter_H
#define Peashooter_H
#include "Shooter.h"
#include "SFML/Graphics.hpp"
using namespace sf;
class Peashooter : public Shooter
{
	Texture texture;
public:
	Peashooter(int xPos, int yPos, int h, int w, int hit);
	~Peashooter();
	void takeDamage();
	void display();
	bool collisionCheck();
};
#endif