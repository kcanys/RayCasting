#include <iostream>
#include <SFML/Graphics.hpp>
#include "fun.h"
#include "Pt.h"
#include "Ray.h"
#include "fps.h"
#include <stdio.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Ray Casting");
    sf::Event ev;

    Pt point(20, &window);
    
    sf::Vertex walls[10][2];
    spawnWalls(walls);
    float size = 400;
    fps f;
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Space)
                {
                    spawnWalls(walls);
                    std::cout << "Walls rearranged.\n";
                }
                if (ev.key.code == sf::Keyboard::Up)
                {
                    size += 5.0;
                    printf("Ray size inrcreased: %f\n", size);
                }

                if (ev.key.code == sf::Keyboard::Down)
                {
                    if (size > 0)
                    {
                        size -= 5.0;
                        printf("Ray size decreased: %f\n", size);
                    }
                    else
                        printf("Ray size is already 0\n");
                }
            }
        }
        window.clear(sf::Color::Black);
        point.posUpdate(&window);
        point.drawRay(&window, walls, size);
        displayWalls(walls, &window);
        f.drawFps(&window);
        window.display();   
    }
    return 0;
}