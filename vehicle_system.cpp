#include "vehicle_system.h"
#include "vehicle.h"

VehicleSystem::VehicleSystem()
{
	
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

void VehicleSystem::update()
{

}

void VehicleSystem::render(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->render(window);
	}
}