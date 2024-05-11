#pragma once
#ifndef Entity_h
#define Entity_h
#include"Size.h"
#include"Position.h"
#include"Sprite.h"
#include <SFML/Graphics.hpp>

class Entity {
protected:
	Position position;
	Size size;
	int hitPoints;
	Sprite spriteEntity;
public:
	Entity(int xPos, int yPos, int h, int w, int);
	~Entity();
	virtual bool collisionCheck() = 0;
	bool collisionViaZombie();
	bool collisionViaPlant();
	bool collisionViaCherryBomb(); // Newly Added
	bool collisionViaPea();
	bool collisionViaLawnMover();
	virtual void takeDamage()=0;
	virtual void display(sf::RenderWindow& Window)=0;
	void healthCheck();

};
#endif // !Entity_h
