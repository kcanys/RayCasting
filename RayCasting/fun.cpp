#include "fun.h"

float toRadian(float degree) { return (3.14 / 180) * degree; }
float dCos(float degree) { return cos(toRadian(degree)); }
float dSin(float degree) { return sin(toRadian(degree)); }
sf::Vector2f check(sf::Vertex wall[], sf::Vertex ray[])
{
    float x1 = wall[0].position.x;
    float x2 = wall[1].position.x;
    float x3 = ray[0].position.x;
    float x4 = ray[1].position.x;
    float y1 = wall[0].position.y;
    float y2 = wall[1].position.y;
    float y3 = ray[0].position.y;
    float y4 = ray[1].position.y;

    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    float u = -(((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)));
    sf::Vector2f ret;
    if (t > 0.0 && t < 1.0 && u > 0.0 && u < 1.0)
    {
        ret.x = x1 + t * (x2 - x1);
        ret.y = y1 + t * (y2 - y1);
        return ret;
    }
    return sf::Vector2f(-1,-1);
}

void drawWalls(std::vector<sf::Vertex*> walls, sf::RenderWindow* window)
{
    for (int i = 0; i < walls.size(); i++)
    {
        window->draw(walls[i], 2, sf::Lines);
    }
}

void spawnWalls(sf::Vertex walls[][2])
{
    for (int i = 0; i < 10; i++)
    {
        walls[i][0].position = sf::Vector2f(rand() % 800, rand() % 800);
        walls[i][1].position = sf::Vector2f(rand() % 800, rand() % 800);
    }
    printf("Randomizing walls done.\n");
}

void displayWalls(sf::Vertex walls[][2], sf::RenderWindow *window)
{
    for (int i = 0; i < 10; i++)
        window->draw(walls[i], 2, sf::Lines);
    
}
