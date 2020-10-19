#include "fps.h"

fps::fps()
{
    this->clock = new sf::Clock();
    this->font.loadFromFile("BRLNSR.TTF");
}

std::string fps::returnFps()
{
    std::string framesPerSecond;
    this->currentTime = this->clock->restart().asSeconds();
    this->FPS = 1.f / (this->currentTime);
    return std::to_string((int)this->FPS);
}

void fps::drawFps(sf::RenderWindow *window) 
{
    std::string retString = "FPS: " + this->returnFps();
    sf::Text t;
    t.setFont(this->font);
    t.setCharacterSize(25);
    t.setPosition(0, 0);
    t.setString(retString);
    window->draw(t);
}
