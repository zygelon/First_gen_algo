#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

enum class Items{wall=int('#'),food=int('*'),poison=int('w'),bot=int('O'),empty=int('.')};
class Bot;
class World
{
	friend class Bot;
public:
	const int height=50, length=50;

	static World& Self();
	void Set_empty_pos(int&, int&);
	void Create_world();
	Items Get_inf(int x, int y);
	void Show();
	int Bots_population() { return bots_alive; }
private:
	const int poison_chance = 0, food_chance = 10, wall_chance = 50;

	Items **map;
	bool is_world_old;
	~World();
	World() { is_world_old = false; bots_alive = 0; };

	int bots_alive;
};

