#pragma once
#include "fun.h"
#include "Ray.h"
class Pt : sf::CircleShape 
{
private:
    float x;
    float y;
public:
    Ray rays[720];
    //Constructor
    Pt(int size, sf::RenderWindow* window);

    void posUpdate(sf::RenderWindow* window);

    void drawRay(sf::RenderWindow* window, sf::Vertex walls[][2], float size);
};

