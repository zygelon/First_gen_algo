#include <iostream>
#include <ctime>
#include "Simulation.h"
#include <forward_list>
#include <fstream>


using namespace std;

ofstream out("genom.txt");


World* my_world;
//int bot_population;



int main()
{
	srand(time(0));

	Simulation gen_algo;
	/*
	for (int i = 0; i < 2025; ++i)
	{
		Selection_last_bots();
		my_world->Create_world();
		Bot_generation(0,true);
	}*/
	//bots.front()->Write_DNA(out);
	//out.close();
	system("pause");
}