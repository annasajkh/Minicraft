#pragma once
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include <constructs/GameObject.hpp>


class Rectangle : public GameObject
{
protected:
    sf::VertexArray vertices;

    sf::Vector2f size;
    sf::Vector2f origin;
    sf::Color color;
public:
    Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Vector2f& origin, const sf::Color& color);
    ~Rectangle();
    
    const sf::VertexArray& getVertices();

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;

    void setOrigin(const sf::Vector2f& origin);
    sf::Vector2f getOrigin() const;
    
    void setSize(const sf::Vector2f& size);
	sf::Vector2f getSize() const;

    void setColor(const sf::Color& color);
	sf::Color getColor() const;

};
