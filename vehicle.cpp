#include "vehicle.h"
#include "functions.h"
#include <iostream>

void inScreen(sf::Vector2f& v, float x, float y);

Vehicle::Vehicle()
{
	shape = new sf::ConvexShape;
	shape->setPointCount(3);
	shape->setPoint(0, sf::Vector2f(30, 0));
	shape->setPoint(1, sf::Vector2f(0, 10));
	shape->setPoint(2, sf::Vector2f(0, -10));
	shape->setFillColor(sf::Color::White);
	shape->setPosition(rand() % 1280, rand() % 720);
	acc = sf::Vector2f(0, 0);
	vel = sf::Vector2f(0, 0);

	maxVel = 6.0f;
	maxForce = 0.1f;
}

Vehicle::~Vehicle()
{
	delete shape;
	shape = nullptr;
}

void Vehicle::update()
{
	sf::Vector2f pos = shape->getPosition();
	sf::Vector2f desired = target - pos;
	changeLength(desired, maxVel);

	sf::Vector2f steer = desired - vel;
	limit(steer, maxForce);
	acc = steer;

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

void Vehicle::setTarget(sf::Vector2f t)
{
	this->target = t;
}

void inScreen(sf::Vector2f& v, float x, float y)
{
	if (v.x < 0)
		v.x += x;
	if (v.x > x)
		v.x -= x;
	if (v.y < 0)
		v.y += y;
	if (v.y > y)
		v.y -= y;
}