
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
			window.setKeyRepeatEnabled(false);
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Up)
				vs->isUpPressed = true;
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Down)
				vs->isDownPressed = true;
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Num1)
				vs->is1Pressed = true;
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Num2)
				vs->is2Pressed = true;
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Num3)
				vs->is3Pressed = true;
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Num4)
				vs->is4Pressed = true;
		}
		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;

		while (accumulatedTime >= 1.0f / 30.0f)
		{
			vs->update(window);
			accumulatedTime -= 1.0f / 30.0f;
		}
		vs->render(window);
		window.display();
	}

	delete vs;
	vs = nullptr;

	return 0;
}