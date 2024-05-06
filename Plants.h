#pragma once
#ifndef Plants_H
#define Plants_H
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Plants : public Entity
{
protected:
public:
	Plants(int xPos, int yPos, int h, int w, int);
	~Plants();
	void takeDamage() = 0;
	void display(sf::RenderWindow& Window);
	bool collisionCheck();
	virtual void magic() = 0;
	//virtual void magic() = 0;
};
#endif