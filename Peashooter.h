#pragma once
#ifndef Peashooter_H
#define Peashooter_H
#include "Shooter.h"
#include "SFML/Graphics.hpp"
#include "NormalPea.h"
class Peashooter : public Shooter
{
	bool peaGenerated;
public:
	Peashooter(int xPos, int yPos, int h, int w, int hit);
	~Peashooter();
	void takeDamage();
	void display(sf::RenderWindow & Window);
	bool collisionCheck();
	void magic();
	void generatePea();
};
#endif