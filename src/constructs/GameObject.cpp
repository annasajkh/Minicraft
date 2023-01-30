#include <constructs/GameObject.hpp>


GameObject::GameObject(const sf::Vector2f& position)
	: position(position)
{

}

sf::Vector2f GameObject::getPosition() const
{
	return position;
}

void GameObject::setPosition(const sf::Vector2f& position)
{
	this->position = position;
}

GameObject::~GameObject()
{

}