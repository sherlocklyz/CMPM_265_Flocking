#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class Vehicle {
public:
	Vehicle();
	Vehicle(sf::Vector2f pos);
	~Vehicle();

	void update();
	void render(sf::RenderWindow& window);

	void applyForce(sf::Vector2f target);

	sf::ConvexShape* shape;


private:

	sf::Vector2f acc;
	sf::Vector2f vel;
	sf::Vector2f target;


	
	float maxVel;
	float maxForce;
	
};