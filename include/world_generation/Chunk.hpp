#pragma once
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include <constructs/Block.hpp>
#include <utils/constants.hpp>
#include <constructs/GameObject.hpp>
#include <interfaces/IDrawable.hpp>


class Chunk : public GameObject, public IUpdateable
{
private:
    std::array<std::array<std::shared_ptr<Block>, chunkSize>, chunkSize> blocks;

    sf::VertexArray vertices;
public:
    Chunk(const sf::Vector2f& position);
    ~Chunk();

    const sf::VertexArray& getVertices();

    void update(float delta) override;
};