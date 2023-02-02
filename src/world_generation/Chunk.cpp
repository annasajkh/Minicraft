#include <world_generation/Chunk.hpp>
#include <SFML/Graphics.hpp>
#include <utils/constants.hpp>
#include <iostream>
#include <utils/PerlinNoise.hpp>

extern PerlinNoise perlinNoise;


Chunk::Chunk(const sf::Vector2f& position)
    : GameObject(position), vertices(sf::VertexArray(sf::Quads, chunkSize * chunkSize * 4))
{
    for(size_t i = 0; i < blocks.size(); i++)
    {
        for(size_t j = 0; j < blocks[0].size(); j++)
        {
                                                        
            sf::Uint8 noiseValue = static_cast<sf::Uint8>(perlinNoise.noise2d((position.x + static_cast<float>(j * blockSize)) * 0.005f,
                                                                               (position.y + static_cast<float>(i * blockSize)) * 0.005f) * 255);

            blocks[i][j] = std::make_shared<Block>(sf::Vector2f(position.x + static_cast<float>(j * blockSize),
                                                                position.y + static_cast<float>(i * blockSize)),
                                                                sf::Vector2f(blockSize, blockSize),
                                                                sf::Color(noiseValue, noiseValue, noiseValue));

            
            const sf::VertexArray& blockVertices = blocks[i][j]->getVertices();
            sf::Vertex* quad = &vertices[(i + j * chunkSize) * 4];

            quad[0] = blockVertices[0];
            quad[1] = blockVertices[1];
            quad[2] = blockVertices[2];
            quad[3] = blockVertices[3];
        }        
    }
    
}

const sf::VertexArray& Chunk::getVertices()
{
    return vertices;
}

void Chunk::update(float delta)
{
    for(size_t i = 0; i < blocks.size(); i++)
    {
        for(size_t j = 0; j < blocks[0].size(); j++)
        {
            blocks[i][j]->update(delta);


            const sf::VertexArray& blockVertices = blocks[i][j]->getVertices();
            sf::Vertex* quad = &vertices[(i + j * chunkSize) * 4];

            quad[0] = blockVertices[0];
            quad[1] = blockVertices[1];
            quad[2] = blockVertices[2];
            quad[3] = blockVertices[3];
        }
        
    }
}

Chunk::~Chunk()
{

}
