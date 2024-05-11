#pragma once
#ifndef DancingZombies_h
#define DancingZombies_h
#include "Zombie.h"

class DancingZombies : public Zombie {
public:
    DancingZombies(int xPos, int yPos, int h, int w, int hit, int s);
    ~DancingZombies();
    void movement();
    void takeDamage();
    void display(sf::RenderWindow& Window);
    bool collisionCheck();
};

#endif // !DancingZombies_h

