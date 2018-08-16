#include "SFML_output.h"



SFML_output::SFML_output()
{

	map = &World::Self();
	window = new sf::RenderWindow(sf::VideoMode(l , h), "Genetic Algorithm", sf::Style::Close);

	cell_size.x = l / (float)map->length;
	cell_size.y = h / (float)map->height;
	empty_cell_texture.loadFromFile("empty_cell.jpg");
	empty_cell.setTexture(&empty_cell_texture);
	empty_cell.setSize(cell_size);
}


SFML_output::~SFML_output()
{
	window->~RenderWindow();
	delete window;
}

void SFML_output::Draw()
{
	while (window->isOpen())
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window->close();
		}
		window->clear(sf::Color::Blue);
		sf::Vector2f draw_place(0, 0);
		for (int i = 0; i < map->height; ++i, draw_place.y += cell_size.y)
		{
			draw_place.x = 0;
			for (int j = 0; j < map->length; ++j, draw_place.x += cell_size.x)
			{
				empty_cell.setPosition(draw_place);
				window->draw(empty_cell);
			}
		}
		window->display();
	}
}