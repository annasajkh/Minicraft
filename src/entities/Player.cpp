#include <entities/Player.hpp>
#include <math.h>
#include <iostream>


Player::Player(const sf::Vector2f& position, const sf::Vector2f& size)
    : Entity(position, sf::Vector2f(0, 0)), rectangle(size)
{
    rectangle.setPosition(position);
    rectangle.setOrigin(size / 2.0f);
}

void Player::getInput(float delta)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x += -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x += 1;
    }
    else
    {
        velocity.x = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity.y += -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity.y += 1;
    }
    else
    {
        velocity.y = 0;
    }

    float length = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);


    if(length != 0)
    {
        velocity.x /= length;
        velocity.y /= length;
        velocity.x *= 500;
        velocity.y *= 500;
    }

}

void Player::update(float delta)
{
    Entity::update(delta);
    rectangle.rotate(0.1f);

    rectangle.setPosition(position);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}


Player::~Player()
{

}
