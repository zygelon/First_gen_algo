#include "SFML_output.h"
#include <iostream>
#include <ctime>
#include "Simulation.h"
#include <forward_list>
#include <fstream>
//#include <SFML/Graphics.hpp>
//#include <Windows.h>
#include "SFML_output.h"
//using namespace std;
using namespace sf;
ofstream out("genom.txt");


World* my_world;
//int bot_population;

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);


int main()
{
	srand(time(0));

	
	Simulation gen_algo;
	gen_algo.Select_gener(6000);
	for (int i = 0; i < 6003; ++i)
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