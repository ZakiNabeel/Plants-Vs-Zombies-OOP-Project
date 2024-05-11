#include "Button.h"

Button::Button(const std::string& label, float width, float height, float posX, float posY) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(posX, posY));

    font.loadFromFile("D:\\Visual Studio\\ProjectPVZ\\ProjectPVZ\\SFUIText-Bold.ttf");  // Ensure the font file path is correct
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);  // Adjust size as needed
    text.setFillColor(sf::Color::Black);

    // Center text on button
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(posX + width / 2.0f, posY + height / 2.0f);
}

void Button::setFont(const std::string& fontPath) {
    font.loadFromFile(fontPath);
    text.setFont(font);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::wasClicked(sf::RenderWindow& window, sf::Event& event) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Get the mouse position relative to the window

    // Check if the mouse is within the button's bounds
    bool isOver = mousePos.x >= shape.getPosition().x &&
        mousePos.x <= (shape.getPosition().x + shape.getSize().x) &&
        mousePos.y >= shape.getPosition().y &&
        mousePos.y <= (shape.getPosition().y + shape.getSize().y);

    // Check if the button was clicked
    return isOver && event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left;
}
