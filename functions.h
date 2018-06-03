#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

float length(sf::Vector2f v)
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

void changeLength(sf::Vector2f& v, float l)
{
	float angle = asinf(v.y / length(v));
	v.x = v.x / abs(v.x) * cosf(angle) * l;
	v.y = sinf(angle) * l;
}

void normalize(sf::Vector2f& v)
{
	changeLength(v, 1);
}

void limit(sf::Vector2f& v, float max)
{
	if (length(v) > max)
	{
		changeLength(v, max);
	}
}

float getRotation(sf::Vector2f v)
{
	if (v.x == 0)
	{
		if (v.y > 0)
			return 90.0f;
		else
			return -90.0f;
	}
	else
	{
		return atan2f(v.y , v.x) * 180.0f / 3.1415926f;
	}
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
