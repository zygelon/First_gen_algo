#include "Simulation.h"



Simulation::Simulation(int max_gen)
{
	max_generation = max_gen;
	map = &World::Self();
	generation = 0;
	bots_alive = max_bots;
	map->Create_world();
	for (int i = 0; i < max_bots; ++i)
	{
		int x, y;
		map->Set_empty_pos(x, y);

		bots.push_front(new Bot(x, y));
		bots.front()->Mutation();
	}
}


Simulation::~Simulation()
{
	bots.~forward_list();
}

void Simulation::Bot_generation() {
	bots_alive = max_bots;
	forward_list<Bot*>::iterator t = bots.begin();
	for (int i = 0; i < 8; ++i, ++t)
		for (int j = 0; j < 7; ++j)
		{
			(*t)->Regen();
			Bot* t_b = new Bot(**t);
			if (j < 4)
			{
				t_b->Mutation();
				t_b->Mutation();
				t_b->Mutation();
				t_b->Mutation();
				t_b->Mutation();
				t_b->Mutation();
			}
			map->Set_empty_pos(t_b->x, t_b->y);
			bots.push_front(t_b);
		}
}

void Simulation::Last_bots_selection() {
	generation++;
	map->Create_world();
	while (bots_alive > min_bots)
	{
		int &bots_alive = this->bots_alive, int min_bots = this->min_bots;
		bots.remove_if([](Bot* t)
		{if (!t->Is_alive() && bots_alive > min_bots) { t->~Bot(); --bots_alive; return true; } return false; });

		forward_list<Bot*>::iterator t = bots.begin();
		while (t != bots.end())
		{
			(*t)->Action();
			++t;
		}
	}
}