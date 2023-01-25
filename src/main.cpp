#include <iostream>
#include <SFML/Graphics.hpp>
#include <entities/Player.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(860, 540), "Minicraft");
    sf::Vector2u windowSize = window.getSize();
    sf::Clock deltaClock;

    Player player(sf::Vector2f(100, 100), sf::Vector2f(100, 100));



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

        window.clear();
        player.draw(window);
        window.display();
    }

}
