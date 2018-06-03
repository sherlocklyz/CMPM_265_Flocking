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

	sf::Vector2f sumSeparation;
	sf::Vector2f sumAlignment;
	sf::Vector2f sumCohesion;
	float countSeparation;
	float countAlignment;
	float countCohesion;
	void separation(Vehicle* v);
	sf::Vector2f createSeparationForce();
	void alignment(Vehicle* v, float r);
	void cohesion(Vehicle* v, float r);

	void refresh();

private:

	sf::Vector2f acc;
	sf::Vector2f vel;
	sf::Vector2f target;

	float maxVel;
	float maxForce;
	
	float SeparationR;
	float AlignmentR;
	float CohesionR;
};