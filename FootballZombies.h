#pragma once
#ifndef FootballZombies_h
#define FootballZombies_h
#include "Zombie.h"

class FootballZombies : public Zombie {
public:
    FootballZombies(int xPos, int yPos, int h, int w, int hit, int s);
    ~FootballZombies();
    void movement();
    void takeDamage();
    void display(sf::RenderWindow& Window);
    bool collisionCheck();
};

#endif // !FootballZombies_h

