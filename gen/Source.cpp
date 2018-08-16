#include "SFML_output.h"
#include <iostream>
#include <ctime>
#include "Simulation.h"
#include <forward_list>
#include <fstream>
//#include <SFML/Graphics.hpp>
//#include <Windows.h>
//#include "SFML_output.h"
//using namespace std;
using namespace sf;
ofstream out("genom.txt");


World* my_world;
//int bot_population;



int main()
{
	srand(time(0));

	/*
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
	out.close();*/
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);
	/*
	RenderWindow window(VideoMode(200, 200), "Genetic algo");
	CircleShape shape(100.0f);
	shape.setFillColor(Color::Yellow);
	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}*/
	SFML_output a;
	a.Draw();
	system("pause");
}