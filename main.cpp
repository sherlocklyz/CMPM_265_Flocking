
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <time.h>

#include "vehicle_system.h"

int main()
{
	srand((unsigned)time(0));
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Flocking System");
	float accumulatedTime = 0.0f;
	VehicleSystem* vs = new VehicleSystem();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;

		while (accumulatedTime >= 1.0f / 60.0f)
		{
			vs->update();
			accumulatedTime -= 1.0f / 60.0f;
		}
		vs->render(window);
		window.display();
	}

	delete vs;
	vs = nullptr;

	return 0;
}