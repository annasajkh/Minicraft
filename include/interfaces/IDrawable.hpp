#pragma once
#include <SFML/Graphics.hpp>


class IDrawable
{
public:
    IDrawable() { }
    ~IDrawable() { }
    
    virtual void draw(sf::RenderWindow& window) = 0;
};