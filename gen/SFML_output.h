#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "World.h"
#include <ctime>

class SFML_output
{
public:
	SFML_output();
	~SFML_output();
	void Draw();
private:

	sf::Vector2f cell_size;

	sf::RectangleShape empty_cell;
	sf::Texture empty_cell_texture;
	sf::RectangleShape bot;
	sf::RectangleShape wall;
	sf::RectangleShape food;
	sf::RectangleShape poison;

	World *map;
	sf::RenderWindow *window;
};

