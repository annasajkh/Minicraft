#pragma once

#include <constructs/Entity.hpp>
#include <SFML/Graphics.hpp>

class Player : public Entity
{
public:
    Player(const sf::Vector2f& position, const sf::Vector2f& size, const sf::RenderWindow& window);
    ~Player();

    void getInput(float delta);
    void update(float delta) override;
	void draw(sf::RenderWindow& window) override;

    sf::View view;
};