#pragma once
#include <SFML/Graphics.hpp>
#include <constructs/GameObject.hpp>



class Entity : public GameObject
{
public:
	Entity(const sf::Vector2f& position, const sf::Vector2f& velocity);
	~Entity();

	sf::Vector2f velocity;

	void update(float delta) override;
	void draw(sf::RenderWindow& window) override;
};