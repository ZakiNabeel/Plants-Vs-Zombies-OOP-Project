#pragma once
#ifndef Cherrybomb_H
#define Cherrybomb_H
#include "NonShooter.h"
class Cherrybomb : public NonShooter
{
	sf::IntRect rectSourceSprite;
public:
	Cherrybomb(int xPos, int yPos, int h, int w, int hp);
	~Cherrybomb();
	void display(sf::RenderWindow & Window);
	void takeDamage();
	void collisionCheck(Zombie**& zombieEntities, int);
	void magic();
};
#endif