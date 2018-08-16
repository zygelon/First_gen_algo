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
	gen_algo.Select_gener(1000);
	for (int i = 0; i < 1003; ++i)
	{
		gen_algo.Last_bots_selection();
		gen_algo.Bot_generation();
	}
	//bots.front()->Write_DNA(out);
	cout << gen_algo.sum_score << '\n';
	gen_algo.Write_DNA(out);
	out.close();
	system("pause");
}