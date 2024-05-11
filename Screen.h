#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "SFML/Graphics.hpp"
class Screen
{
protected:
	sf::Texture screenTexture;
	sf::Sprite screenSprite;
public:
	Screen();
	Screen(const std::string& backgroundImagePath);
	~Screen() {}
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual bool update(sf::RenderWindow& window, sf::Event& event) = 0;
};
#endif