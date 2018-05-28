#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class VehicleSystem {
public:
	VehicleSystem();
	~VehicleSystem();

	void update();
	void render(sf::RenderWindow& window);
};