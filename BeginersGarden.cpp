#include"BeginersGarden.h"
BeginersGarden::BeginersGarden() : Levels(1) {
}
BeginersGarden::~BeginersGarden() {
}
void BeginersGarden::setNumZombies(int n) {
	Levels::setNumZombies(n);
}
void BeginersGarden::display(sf::RenderWindow& Window) {
	Levels::display(Window);
}
void BeginersGarden::update() {
	Levels::update();
}

void BeginersGarden::createBack(sf::RenderWindow& window) {
	(Levels::textureBackGround).loadFromFile("level1.png");
	(Levels::spriteBackGround).setTexture((Levels::textureBackGround));
	window.draw(spriteBackGround);
}