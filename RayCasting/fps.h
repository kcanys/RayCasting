#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class fps
{
private:
	sf::Clock *clock;
	float currentTime = 0;
	float FPS = 0;
	sf::Font font;
public:
	fps();
	std::string returnFps();
	void drawFps(sf::RenderWindow *window);
};

