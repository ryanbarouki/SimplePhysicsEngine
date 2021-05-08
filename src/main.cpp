#include <iostream>
#include <SFML/Graphics.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SoftBody");
    sf::Clock Clock;
    sf::CircleShape shape(70.f);
    shape.setFillColor(sf::Color::Green);
    double vel = 0;
    double g = 1000; // pixels / sec^2
    while (window.isOpen())
    {
        sf::Time dt = Clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (shape.getPosition().y > 700)
        {
            vel = -vel;
        }
        else
        {
            vel += g * dt.asSeconds();
        }
        shape.move(0.0f, vel * dt.asSeconds());
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}