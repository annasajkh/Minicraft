#pragma once
#include <constructs/Block.hpp>




class Dirt : public Block
{
public:
    Dirt(const sf::Vector2f& position, const sf::Vector2f& size);
    ~Dirt();
};