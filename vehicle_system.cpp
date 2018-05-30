#include "vehicle_system.h"
#include "vehicle.h"

VehicleSystem::VehicleSystem()
{
	Vehicle* vehicle = new Vehicle;
	v.push_back(vehicle);
}

VehicleSystem::~VehicleSystem()
{
	for (int i = 0; i < v.size(); i++)
	{
		Vehicle* temp = v[i];
		v.erase(v.begin() + i);
		delete temp;
		temp = nullptr;
	}
}

void VehicleSystem::update(sf::RenderWindow& window)
{
	sf::Vector2i mousePosI = sf::Mouse::getPosition(window);
	sf::Vector2f mousePos = sf::Vector2f(float(mousePosI.x), float(mousePosI.y));
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->setTarget(mousePos);
		v[i]->update();
	}
}

void VehicleSystem::render(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->render(window);
	}
}