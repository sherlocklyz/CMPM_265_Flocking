#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

const float BUCKET_WIDTH = 80;
const float BUCKET_HEIGHT = 80;
const int COLUMNS = 16;
const int ROWS = 9;

class Vehicle;

class VehicleSystem {
public:
	VehicleSystem();
	~VehicleSystem();

	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);

	bool isUpPressed;
	bool isDownPressed;
	bool is1Pressed;
	bool is2Pressed;
	bool is3Pressed;
	bool is4Pressed;

private:
	std::vector<Vehicle*> v;

	std::vector<Vehicle*> grid[COLUMNS][ROWS];
	sf::Vector2i getBucket(sf::Vector2f pos);
	void bucket_add(sf::Vector2i b, Vehicle* vehicle);
	void bucket_remove(sf::Vector2i b, Vehicle* vehicle);

	sf::Vector2f flock(Vehicle* vehicle, sf::Vector2i b, sf::Vector2f mousePos);

	void createVehicle();
	void removeVehicle();

	bool canTarget;
	void targetSwitch();
	bool canSeparate;
	void separationSwitch();
	bool canAlignment;
	void alignmentSwitch();

	float paraTarget;
	float paraSeparation;
	float paraAlignment;
	float paraCohesion;

	sf::Text text;
	sf::Font font;
	
};