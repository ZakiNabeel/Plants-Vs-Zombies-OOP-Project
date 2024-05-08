#pragma once
#ifndef Plants_H
#define Plants_H
#include"Entity.h"
#include"Zombie.h"
#include <SFML/Graphics.hpp>
class Zombie;	
class Plants : public Entity{
public:
	Plants(int xPos, int yPos, int h, int w, int);
	~Plants();
	void takeDamage();
	void display(sf::RenderWindow& Window);
	virtual void collisionCheck(Zombie** &zombieEntities,int)=0;
	virtual void magic() = 0;
};
#endif