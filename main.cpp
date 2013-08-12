#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"

//TODO: Now that you've got tiles, make the tile array class, then adapt bloc and snake to inherit from them.

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(10);
    sf::Texture texture;
    if (!texture.loadFromFile("snake25.png"))
    {
        return -1;
    }
    Snake snake = Snake(sf::Vector2f(0, 0), d_right, &texture, sf::Color::Green);
    int frame = 0;
    int dir = d_right;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (frame % 7 == 0)
            snake.step(dir | 0x4);
        else
            snake.step(dir);
        if (frame % 4 == 3)
        {
            dir += 1;
            if (dir > 3)
                dir = 0;
        }
        if (frame % 10 == 0 && frame < 100)
            snake.grow(1);
        frame++;
        window.clear();
        window.draw(snake);
        window.display();
    }

    return 0;
}
