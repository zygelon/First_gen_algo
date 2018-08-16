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
	const int height=40, length=40;

	static World& Self();
	void Set_empty_pos(int&, int&);
	void Create_world();
	Items Get_inf(int x, int y);
	void Show();
private:
	const int poison_chance = 10, food_chance = 30, wall_chance = 10;

	Items **map;
	bool is_world_old;
	~World();
	World();

};

