#pragma once
#ifndef BeginersGarden_h
#define BeginersGarden_h
#include"Level.h"
class BeginersGarden: public Levels {
public:
	void createBack(sf::RenderWindow& window);
	BeginersGarden();
	~BeginersGarden();
	void setNumZombies(int n);
	void display(sf::RenderWindow& Window);
	void update();

};
#endif // !BeginersGarden_h

