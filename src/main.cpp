#include <iostream>
#include <SFML/Graphics.hpp>
#include <entities/Player.hpp>
#include <shapes/Rectangle.hpp>
#include <world_generation/Chunk.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(860, 540), "Minicraft");
    sf::Vector2u windowSize = window.getSize();
    sf::Clock deltaClock;

    Player player(sf::Vector2f(0, 0), sf::Vector2f(100, 100), window);
    

    // PerlinNoise perlinNoise(1);


    // for (size_t i = 0; i < rectangles.size(); i++)
    // {
    //     for (size_t j = 0; j < rectangles[0].size(); j++)
    //     {
    //         sf::Uint8 noiseValue = static_cast<sf::Uint8>(perlinNoise.noise2d(i * size, j * size) * 255.0f);

    //         rectangles[i][j] = std::make_unique<sf::RectangleShape>(sf::Vector2f(blockSize, blockSize));
    //         rectangles[i][j]->setPosition(static_cast<float>(i * 10), static_cast<float>(j * 10));
    //         rectangles[i][j].setFillColor(sf::Color(noiseValue, noiseValue, noiseValue));
    //     }
    // }

    Chunk chunk(sf::Vector2f(0, 0));
    
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
        
        player.getInput(deltaTime.asSeconds());
        player.update(deltaTime.asSeconds());
        chunk.update(deltaTime.asSeconds());

        window.setView(player.view);
        window.clear();
        
        chunk.draw(window);
        player.draw(window);
        window.display();
    }

}
