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
	void Create_world();
	Items Get_inf(int x, int y);
	void Show();
private:
	const int poison_chance = 20, food_chance = 10;

	Items **map;
	bool is_world_old;
	~World();
	World() {is_world_old = false;};

};

