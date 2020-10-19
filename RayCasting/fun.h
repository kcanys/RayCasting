#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

float toRadian(float degree);
float dCos(float degree);
float dSin(float degree);
sf::Vector2f check(sf::Vertex wall[], sf::Vertex ray[]);
void drawWalls(std::vector<sf::Vertex*> walls, sf::RenderWindow* window);
void spawnWalls(sf::Vertex walls[][2]);
void displayWalls(sf::Vertex walls[][2], sf::RenderWindow *window);

