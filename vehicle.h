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
	~Vehicle();

	void update();
	void render(sf::RenderWindow& window);

	sf::Vector2f createForce(sf::Vector2f t);
	void applyForce(sf::Vector2f f);

	sf::ConvexShape* shape;


private:

	sf::Vector2f acc;
	sf::Vector2f vel;
	sf::Vector2f target;


	
	float maxVel;
	float maxForce;
	
};