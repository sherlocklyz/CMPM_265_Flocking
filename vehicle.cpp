#include "vehicle.h"
#include "functions.h"
#include <iostream>

Vehicle::Vehicle()
{
	maxVel = 12.0f;
	maxForce = 0.5f;

	shape = new sf::ConvexShape;
	shape->setPointCount(3);
	shape->setPoint(0, sf::Vector2f(30, 0));
	shape->setPoint(1, sf::Vector2f(0, 10));
	shape->setPoint(2, sf::Vector2f(0, -10));
	shape->setFillColor(sf::Color::White);
	shape->setPosition(rand() % 1280, rand() % 720);
	acc = sf::Vector2f(0, 0);
	vel = sf::Vector2f((rand() % 101 - 50) / 10, (rand() % 101 - 50) / 10);
	changeLength(vel, rand() % 100 / 20 + 3);

	SeparationR = 40;
	AlignmentR = 10;
	CohesionR = 15;

	countSeparation = 0;
	countAlignment = 0;
	countCohesion = 0;
}

Vehicle::~Vehicle()
{
	delete shape;
	shape = nullptr;
}

void Vehicle::update()
{
	sf::Vector2f pos = shape->getPosition();

	vel += acc;
	limit(vel, maxVel);
	
	pos += vel;
	inScreen(pos, 1280.0f, 720.0f);

	shape->setPosition(pos);
	shape->setRotation(getRotation(vel));
}

void Vehicle::render(sf::RenderWindow& window)
{
	window.draw(*shape);
}

sf::Vector2f Vehicle::createForce(sf::Vector2f t)
{
	sf::Vector2f pos = shape->getPosition();
	sf::Vector2f desired = t - pos;
	changeLength(desired, maxVel);

	sf::Vector2f steer = desired - vel;
	limit(steer, maxForce);
	return steer;
}

void Vehicle::applyForce(sf::Vector2f f)
{
	acc = f;
}

void Vehicle::separation(Vehicle* v)
{
	sf::Vector2f diff = this->shape->getPosition() - v->shape->getPosition();
	if (length(diff) < SeparationR)
	{
		changeLength(diff, 1 / length(diff));
		sumSeparation += diff;
		countSeparation++;
	}
}

sf::Vector2f Vehicle::createSeparationForce()
{
	if (countSeparation > 0)
	{
		changeLength(sumSeparation, maxVel);
		sf::Vector2f steerSeparation = sumSeparation - vel;
		limit(steerSeparation, maxForce);
		return steerSeparation;
	}
	else
		return sf::Vector2f(0, 0);
}

void Vehicle::refresh()
{
	sumSeparation = sf::Vector2f(0, 0);
	sumAlignment = sf::Vector2f(0, 0);
	sumCohesion = sf::Vector2f(0, 0);
	countSeparation = 0;
	countAlignment = 0;
	countCohesion = 0;
}