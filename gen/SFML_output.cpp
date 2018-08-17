#include "SFML_output.h"


SFML_output::SFML_output()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Gen Algo", sf::Style::Close);
	map = &World::Self();
	cell_size = sf::Vector2f(window->getSize().x / (float)map->length,
		window->getSize().y / (float)map->height);

	empty_cell_texture.loadFromFile("empty_cell.jpg");
	empty_cell.setTexture(&empty_cell_texture);
	empty_cell.setSize(cell_size);

	food.setSize(cell_size);
	food.setFillColor(sf::Color::Green);

	bot.setSize(cell_size);
	bot.setFillColor(sf::Color::Yellow);

	wall.setSize(cell_size);
	wall.setFillColor(sf::Color::Black);

	poison.setSize(cell_size);
	poison.setFillColor(sf::Color::Magenta);
}


SFML_output::~SFML_output()
{
	window->~RenderWindow();
	delete window;
}

void SFML_output::Draw()
{
	auto start=clock();
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
				switch (map->Get_inf(j, i))
				{
				case Items::bot:
					bot.setPosition(draw_place);
					window->draw(bot);
					break;
				case Items::empty:
					empty_cell.setPosition(draw_place);
					window->draw(empty_cell);
					break;
				case Items::food:
					food.setPosition(draw_place);
					window->draw(food);
					break;
				case Items::poison:
					poison.setPosition(draw_place);
					window->draw(poison);
					break;
				case Items::wall:
					wall.setPosition(draw_place);
					window->draw(wall);
					break;
				}
			}
		}
		window->display();
		if (clock()-start > 500) return;
	}
}