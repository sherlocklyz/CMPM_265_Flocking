#include "vehicle_system.h"
#include "vehicle.h"
#include <iostream>


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
	if (isUpPressed)
	{
		createVehicle();
		isUpPressed = false;
		std::cout << v.size();
	}
	if (isDownPressed)
	{
		removeVehicle();
		isDownPressed = false;
		std::cout << v.size();
	}

	for (int i = 0; i < v.size(); i++)
	{
		Vehicle * vehicle = v[i];
		sf::Vector2i curBucket = getBucket(vehicle->shape->getPosition());

		vehicle->applyForce(mousePos);
		vehicle->update();

		sf::Vector2i newBucket = getBucket(vehicle->shape->getPosition());
		if (curBucket != newBucket)
		{
			bucket_remove(curBucket, vehicle);
			bucket_add(newBucket, vehicle);
		}
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

sf::Vector2i VehicleSystem::getBucket(sf::Vector2f pos)
{
	int col = int(pos.x / BUCKET_WIDTH);
	if (col < 0)
		col = 0;
	else if (col >= COLUMNS)
		col = COLUMNS - 1;

	int row = int(pos.y / BUCKET_HEIGHT);
	if (row < 0)
		row = 0;
	else if (row >= ROWS)
		row = ROWS - 1;

	return sf::Vector2i(col, row);
}

void VehicleSystem::bucket_add(sf::Vector2i b, Vehicle* v)
{
	std::vector <Vehicle*> &vec = grid[b.x][b.y];
	vec.push_back(v);
}

void VehicleSystem::bucket_remove(sf::Vector2i b, Vehicle* v)
{
	std::vector <Vehicle*> &vec = grid[b.x][b.y];

	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == v)
		{
			vec.erase(vec.begin() + i);
			break;
		}
	}
}

void VehicleSystem::createVehicle()
{
	Vehicle* vehicle = new Vehicle();
	v.push_back(vehicle);
}

void VehicleSystem::removeVehicle()
{
	if (!v.empty())
	{
		Vehicle* temp = v[v.size() - 1];
		v.pop_back();
		delete temp;
		temp = nullptr;
	}
}