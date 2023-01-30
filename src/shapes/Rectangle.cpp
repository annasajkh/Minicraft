#include <shapes/Rectangle.hpp>
#include <iostream>



Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Vector2f& origin, const sf::Color& color)
    : GameObject(position), vertices(sf::VertexArray(sf::Quads, 4)), size(size), origin(origin), color(color)
{

}

const sf::VertexArray& Rectangle::getVertices()
{
    vertices[0] = sf::Vertex(sf::Vector2f(position.x - origin.x, position.y + size.y - origin.y), color);
    vertices[1] = sf::Vertex(sf::Vector2f(position.x - origin.x, position.y - origin.y), color);
    vertices[2] = sf::Vertex(sf::Vector2f(position.x + size.x - origin.x, position.y - origin.y), color);
    vertices[3] = sf::Vertex(sf::Vector2f(position.x + size.x - origin.x, position.y + size.y - origin.y), color);
    
    
    return vertices;
}

void Rectangle::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}

sf::Vector2f Rectangle::getPosition() const
{
    return position;
}

void Rectangle::setSize(const sf::Vector2f& size)
{
    this->size = size;
}

sf::Vector2f Rectangle::getSize() const
{
    return size;
}

void Rectangle::setOrigin(const sf::Vector2f& origin)
{
    this->origin = origin;
}

sf::Vector2f Rectangle::getOrigin() const
{
    return origin;
}

void Rectangle::setColor(const sf::Color& color)
{
    this->color = color;
}

sf::Color Rectangle::getColor() const
{
    return color;
}

Rectangle::~Rectangle()
{
    
}