#include "World.h"


World& World::Self()
{
	static World self;
	return self;
}

void World::Create_world()
{
	if (!is_world_old)
	{
		map = new Items*[height];
		for (int i = 0; i < height; ++i)
			map[i] = new Items[length];
	}
	else for (int i = 0; i < height; ++i)
		for (int j = 0; j < length; ++j)
			map[i][j] = Items::empty;


	for (int i = 0; i < height; ++i)
		for (int j = 0; j < length; ++j)
		{
			int r = rand() % 100 + 1;
			if (r > poison_chance + food_chance + wall_chance) map[i][j] = Items::empty;
			else if (r > poison_chance + wall_chance) map[i][j] = Items::food;
			else if (r > poison_chance) map[i][j] = Items::wall;
			else map[i][j] = Items::poison;
		}
	is_world_old = true;
}

void World::Show()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
			cout << (char)map[i][j] << "  ";
		cout << '\n';
	}
}

World::~World()
{
	for (int i = 0; i < height; ++i)
		delete[] map[i];
	delete[] map;
}

Items World::Get_inf(int x,int y)
{
	if (x < 0 || x >= length || y < 0 || y >= height) return Items::wall;
	return map[y][x];
}
void World::Set_empty_pos(int& x,int &y) {
	do{
		x = rand() % length;
		y = rand() % height;
	} while (Get_inf(x, y) != Items::empty);
}

