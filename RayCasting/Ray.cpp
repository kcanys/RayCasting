#include "Ray.h"

sf::Vertex line[2];
Ray::Ray()
{
    this->angle = 0;
    this->line[0].position = sf::Vector2f(0, 0);
    this->line[1].position = sf::Vector2f(0, 0);
}
Ray::Ray(float x, float y, float angle)
{
    this->line[0].position = sf::Vector2f(x, y);
    this->line[1].position = sf::Vector2f(x + 200, y + 200);

}
void Ray::drawRay(sf::RenderWindow* window)
{
    window->draw(this->line, 2, sf::Lines);
}

void Ray::updateRay(float x, float y, float angle, float size)
{
    this->line[0].position = sf::Vector2f(x, y);
    this->line[1].position = sf::Vector2f(x + size * dCos(angle), y + size * dSin(angle));
    this->line[0].color = sf::Color(255,255,255,100);
    this->line[1].color = sf::Color(255,255,255,100);
}
