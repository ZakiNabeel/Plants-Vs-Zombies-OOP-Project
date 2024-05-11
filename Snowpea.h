#pragma once
#ifndef SnowPea_h
#define SnowPea_h
#include "Shooter.h"
#include"WhitePea.h"
class SnowPea :public Shooter {
public:	
	SnowPea(int xPos, int yPos, int h, int w, int hp);
	~SnowPea();
	void display(sf::RenderWindow& Window);
	void takeDamage();
	bool collisionCheck();
	void magic();
	void generatePea();
};
#endif // !SnowPea_h

