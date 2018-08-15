#pragma once
#include "Bot.h"
#include <forward_list>
class Simulation
{
public:
	Simulation(int max_gen = 1024);
	~Simulation();
	void Last_bots_selection();
	void Bot_generation();

private:
	const int min_bots = 8;
	const int max_bots = 64;
	World* map;

	forward_list<Bot*>bots;

	int bots_alive;
	int generation;
	int max_generation;

};

