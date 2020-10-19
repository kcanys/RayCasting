#include <iostream>
#include <SFML/Graphics.hpp>
#include "fun.h"
#include "Pt.h"
#include "Ray.h"
#include "fps.h"
#include <stdio.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ray Casting");
    sf::Event ev;

    Pt point(20, &window);
    
    sf::Vertex walls[10][2];
    spawnWalls(walls);

    fps f;
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        point.posUpdate(&window);
        point.drawRay(&window, walls);
        displayWalls(walls, &window);
        f.drawFps(&window);
        window.display();   
    }
    return 0;
}