#include "Pt.h"

Pt::Pt(int size, sf::RenderWindow* window) {
    this->x = 0.f;
    this->y = 0.f;
    setRadius(size);
    setFillColor(sf::Color(255, 255, 255, 127));
    for (int i = 0; i < 720; i++)
    {
        rays[i] = Ray(this->x, this->y, (float)i);
    }
}

//Updating pos every frame
void Pt::posUpdate(sf::RenderWindow* window)
{
    this->x = window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x;
    this->y = window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y;
    setPosition(sf::Vector2f(x - getRadius() / 2 - 8, y - getRadius() / 2 - 8));
    window->draw(*this);
}

void Pt::drawRay(sf::RenderWindow* window, sf::Vertex walls[][2], float size) {
    int xVal = this->x, yVal = this->y;
    for (int i = 0; i < 720; i++)
    {
        rays[i].updateRay(xVal, yVal, i/2.0, size);
        for (int j = 0; j < 10; j++)
        {
            if (check(walls[j], rays[i].line) != sf::Vector2f(-1, -1))
            {
                rays[i].line[1].position = check(walls[j], rays[i].line);
            }
        }
        rays[i].drawRay(window);
    }
}
