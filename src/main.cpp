#include <iostream>
#include <SFML/Graphics.hpp>
#include <entities/Player.hpp>
#include <shapes/Rectangle.hpp>
#include <world_generation/Chunk.hpp>
#include <utils/PerlinNoise.hpp>
#include <memory>


PerlinNoise perlinNoise(1);

std::array<std::array<std::shared_ptr<Chunk>, renderDistance>, renderDistance> chunks;
std::shared_ptr<sf::VertexArray> vertices = std::make_shared<sf::VertexArray>(sf::Quads, 4 * chunkSize * chunkSize * renderDistance * renderDistance);


int main()
{
    sf::RenderWindow window(sf::VideoMode(852, 480), "Minicraft");
    sf::Vector2u windowSize = window.getSize();
    sf::Clock deltaClock;

    Player player(sf::Vector2f(0, 0), sf::Vector2f(100, 100), window);

    float halfRenderSize = blockSize * chunkSize * renderDistance / 2.0f;

    for (size_t i = 0; i < chunks.size(); i++)
    {
        for (size_t j = 0; j < chunks[0].size(); j++)
        {
            chunks[i][j] = std::make_shared<Chunk>(sf::Vector2f(static_cast<float>(j) * blockSize * chunkSize,
                                                                static_cast<float>(i) * blockSize * chunkSize));
        }
    }

    size_t vertexCounter = 0;
    
    for (size_t i = 0; i < chunks.size(); i++)
    {
        for (size_t j = 0; j < chunks[0].size(); j++)
        {
            const sf::VertexArray& chunkVertices = chunks[i][j]->getVertices();

            for (size_t k = 0; k < chunkVertices.getVertexCount(); k++)
            {
                (*vertices)[vertexCounter] = chunkVertices[k];
                vertexCounter++;
            }
            
        }
    }

    
    while(window.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = deltaClock.restart();

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        size_t vertexCounter = 0;
        
        player.getInput(deltaTime.asSeconds());
        player.update(deltaTime.asSeconds());
        
        // for (size_t i = 0; i < chunks.size(); i++)
        // {
        //     for (size_t j = 0; j < chunks[0].size(); j++)
        //     {
        //         chunks[i][j]->update(deltaTime.asSeconds());

        //         const sf::VertexArray& chunkVertices = chunks[i][j]->getVertices();

        //         for (size_t k = 0; k < chunkVertices.getVertexCount(); k++)
        //         {
        //             (*vertices)[vertexCounter] = chunkVertices[k];
        //             vertexCounter++;
        //         }
                
        //     }
        // }

        

        window.setView(player.view);
        window.clear();
        window.draw(*vertices);
        player.draw(window);
        window.display();
    }

}
