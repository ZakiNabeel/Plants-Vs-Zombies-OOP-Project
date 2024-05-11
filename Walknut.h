#pragma once
#ifndef Walknut_H
#define Walknut_H
#include "NonShooter.h"
class Walknut : public NonShooter
{
public:
	bool present;

	Walknut(int xPos, int yPos, int h, int w, int hp);
	~Walknut();
	void display(sf::RenderWindow & Window);
	void takeDamage();
	void collisionCheck(Zombie**& zombieEntities, int, Tile**& grid);
	void magic(int& coins1);
};
#endif