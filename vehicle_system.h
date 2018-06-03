#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

const float BUCKET_WIDTH = 40;
const float BUCKET_HEIGHT = 40;
const int COLUMNS = 32;
const int ROWS = 18;

class Vehicle;

class VehicleSystem {
public:
	VehicleSystem();
	~VehicleSystem();

	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);

	bool isUpPressed;
	bool isDownPressed;

private:
	std::vector<Vehicle*> v;

	std::vector<Vehicle*> grid[COLUMNS][ROWS];
	sf::Vector2i getBucket(sf::Vector2f pos);
	void bucket_add(sf::Vector2i b, Vehicle* vehicle);
	void bucket_remove(sf::Vector2i b, Vehicle* vehicle);

	sf::Vector2f separation(Vehicle* vehicle, sf::Vector2i b);

	void createVehicle();
	void removeVehicle();



};