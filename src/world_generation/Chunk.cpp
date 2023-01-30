#include <world_generation/Chunk.hpp>
#include <SFML/Graphics.hpp>
#include <utils/constants.hpp>
#include <iostream>



Chunk::Chunk(const sf::Vector2f& position)
    : GameObject(position), vertices(sf::VertexArray(sf::Quads, chunkSize * chunkSize * 4))
{
    for(size_t i = 0; i < blocks.size(); i++)
    {
        for(size_t j = 0; j < blocks[0].size(); j++)
        {
            blocks[i][j] = std::make_shared<Block>(sf::Vector2f(static_cast<float>(j * blockSize),
                                                                static_cast<float>(i * blockSize)),
                                                                sf::Vector2f(blockSize, blockSize),
                                                                sf::Color(rand() % 255, rand() % 255, rand() % 255));

            
            const sf::VertexArray& blockVertices = blocks[i][j]->getVertices();

            vertices.append(blockVertices[0]);
            vertices.append(blockVertices[1]);
            vertices.append(blockVertices[2]);
            vertices.append(blockVertices[3]);
        }
        
    }

    std::cout << "Vertex Count: " << vertices.getVertexCount() << std::endl;
    std::cout << "Block Count: " << chunkSize * chunkSize << std::endl;
    
}

void Chunk::update(float delta)
{
    for(size_t i = 0; i < blocks.size(); i++)
    {
        for(size_t j = 0; j < blocks[0].size(); j++)
        {
            blocks[i][j]->update(delta);
        }
        
    }
}

void Chunk::draw(sf::RenderWindow& window)
{
    window.draw(vertices);
}

Chunk::~Chunk()
{

}
