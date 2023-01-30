#pragma once

#include <SFML/Graphics.hpp>
#include <constructs/GameObject.hpp>
#include <interfaces/IDrawable.hpp>
#include <interfaces/IUpdateable.hpp>
#include <shapes/Rectangle.hpp>


class Entity : public Rectangle, public IUpdateable, public IDrawable
{
public:
	Entity(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Vector2f& velocity, const sf::Color& color);
	~Entity();

	sf::Vector2f velocity;

	void update(float delta) override;
	void draw(sf::RenderWindow& window) override;
};