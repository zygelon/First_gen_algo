#pragma once
#include "Bot.h"
#include <forward_list>
#include "SFML_output.h"

using namespace std;
class Simulation
{
public:
	Simulation();
	~Simulation();
	void Last_bots_selection();
	void Bot_generation();

	int Get_gener() { return generation; }
	void Select_gener(int generation) { selected_gener = generation; };
	void Write_DNA(ostream& os);
	int sum_score = 0;
private:
	void Show_curr_gener();
	
	const int min_bots = 8;
	const int max_bots = 64;
	World* map;

	forward_list<Bot*>bots;
	
	int selected_gener;
	int bots_alive;
	int generation;
	//int max_generation;

	SFML_output graphics;
};

