#include <constructs/Entity.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>


Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Vector2f& velocity, const sf::Color& color)
	: Rectangle(position, size, size / 2.0f, color), velocity(velocity)
{

}

void Entity::update(float delta)
{
	position += velocity * delta;

}

void Entity::draw(sf::RenderWindow& window)
{

}

Entity::~Entity()
{

}