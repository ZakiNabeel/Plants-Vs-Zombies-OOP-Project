#pragma once
#ifndef Level_h
#define Level_h
#include"ZombieFactory.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include"Tile.h"
#include<iostream>
#include"PlantFactory.h"
using namespace std;
class PlantFactory;
class ZombieFactory;
class Levels {
protected:	
	int numZombies;
	ZombieFactory zombieFactory;
	PlantFactory plantFactory;
	int levelNumber;
	Tile** grid;
	sf::Texture textureBackGround;
	sf::Sprite spriteBackGround;
	sf::Texture textureAvailablePlants;
	sf::Sprite spriteAvailablePlants;
	//Sun** sunPtr;
	Pea* peaPtr;
	int sizePea;
public:
	Levels(int);
	virtual void createBack(sf::RenderWindow& window) = 0;
	void setNumZombies(int n);
	~Levels();
	void display(sf::RenderWindow & Window);
	void update();
	void availablePlants(int);
	void drawAvailablePlants(int, sf::RenderWindow& Window);
	bool checkMouseClick(sf::RenderWindow& Window, int, int);
	PlantFactory& getPlantFactory();
	void collisionRumble();
	void updatePlantFactory(int, int, int, int, int);
	//Tile** getGrid();
};

#endif // !Level.h

