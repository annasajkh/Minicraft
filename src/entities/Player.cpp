#include <entities/Player.hpp>
#include <math.h>
#include <iostream>


Player::Player(const sf::Vector2f& position, const sf::Vector2f& size, const sf::RenderWindow& window)
    : Entity(position, size, sf::Vector2f(0, 0), sf::Color::Blue),
      view(position, sf::Vector2f(window.getSize()))
{

}

void Player::getInput(float delta)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x = -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x = 1;
    }
    else
    {
        velocity.x = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity.y = -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity.y = 1;
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

        view.move(velocity * delta);
    }
}

void Player::update(float delta)
{
    Entity::update(delta);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(getVertices());
}


Player::~Player()
{

}
