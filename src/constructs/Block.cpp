#include <constructs/Block.hpp>
#include <iostream>



Block::Block(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
    : Rectangle(position, size, size / 2.0f, color)
{
    
}

void Block::update(float delta) 
{
    // setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

Block::~Block()
{

}