#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(const sf::Vector2f& position);
	~GameObject();

	sf::Vector2f position;

	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};
