#pragma once
#include <SFML/Graphics.hpp>
#include <shapes/Rectangle.hpp>
#include <constructs/GameObject.hpp>
#include <interfaces/IUpdateable.hpp>



class Block : public Rectangle, public IUpdateable 
{
public:
    Block(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color = sf::Color::White);
    ~Block();

    void update(float delta) override;
};
