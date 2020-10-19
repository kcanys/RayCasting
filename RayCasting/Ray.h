#pragma once
#include "fun.h"

class Ray
{
private:
    float angle;
    sf::Transform T;
    sf::Vector2f newPos;

public:
    sf::Vertex line[2];
    Ray();
    Ray(float x, float y, float angle);
    void drawRay(sf::RenderWindow* window);

    void updateRay(float x, float y, float angle);
};

