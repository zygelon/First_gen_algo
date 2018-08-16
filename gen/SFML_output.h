#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "World.h"

class SFML_output
{
public:
	SFML_output();
	~SFML_output();
	void Draw();
private:
	const int h = 1000, l = 1000;
	sf::Vector2f cell_size;
	sf::RectangleShape empty_cell;
	sf::Texture empty_cell_texture;
	World *map;
	sf::RenderWindow *window;
};

