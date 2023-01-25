#include <constructs/Entity.hpp>
#include <iostream>

Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& velocity)
	: GameObject(position), velocity(velocity)
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