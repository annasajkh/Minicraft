#pragma once
#include <SFML/Graphics.hpp>


class GameObject
{
protected:
    sf::Vector2f position;
public:
    GameObject(const sf::Vector2f& position);
    ~GameObject();

    
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);
};