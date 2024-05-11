#pragma once
#ifndef SnowPea_h
#define SnowPea_h
#include "Shooter.h"
#include"WhitePea.h"
class SnowPea :public Shooter {
public:	
	bool present;

	SnowPea(int xPos, int yPos, int h, int w, int hp);
	~SnowPea();
	void display(sf::RenderWindow& Window);
	void takeDamage();
	void collisionCheck(Zombie**& zombieEntities, int, Tile**& grid);
	void magic(int& coins1);
	void generatePea();
};
#endif // !SnowPea_h

