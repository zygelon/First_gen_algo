#include <iostream>
#include <ctime>
#include "Bot.h"
#include <forward_list>
#include <fstream>


using namespace std;

ofstream out("genom.txt");

struct coor
{
	int x,  y;
	coor(int _x,int _y) { x = _x; y = _y; }
	coor() {};
};

World* my_world;
forward_list<Bot*>bots;
int bot_population;

coor Get_empty_pos() {
	coor t;
	do{
		t.x = rand() % my_world->length;
		t.y = rand() % my_world->height;
	} while (my_world->Get_inf(t.x, t.y) != Items::empty);
	return t;
}

void Bot_generation(int n, bool create_baby = false)
{
	if (create_baby)
	{
		forward_list<Bot*>::iterator t = bots.begin();
		for (int i = 0; i < 8; ++i, ++t)
			for (int j = 0; j < 7; ++j)
			{
				++bot_population;
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
				coor t_coor = Get_empty_pos();
				t_b->x = t_coor.x;
				t_b->y = t_coor.y;
				bots.push_front(t_b);
			}

	}
	else {
		bot_population = n;
		for (int i = 0; i < n; ++i)
		{
			coor t = Get_empty_pos();

			bots.push_front(new Bot(t.x, t.y));
			bots.front()->Mutation();
		}
	}
}
/*
void Selection_highest_score()
{

	while (changing && bot_population>8)
	{
		//bots.remove_if([](Bot* t) {if (!t->Is_alive() && bot_population > 8) { t->~Bot(); --bot_population; return true; } return false; });
		forward_list<Bot*>::iterator t = bots.begin();
		while (t != bots.end())
		{
			(*t)->Action();
			++t;
		}

}*/

void Selection_last_bots()
{
	static int num_generation = 0;
	++num_generation;

//	if (show && log(num_generation) / log(2) == int(log(num_generation) / log(2)))
//		cout << "GENERATION NUMBER " << num_generation << "\n";
	//bool changing = false;

	while (bot_population>8)
	{
		bots.remove_if([](Bot* t) {if (!t->Is_alive() && bot_population > 8) { t->~Bot(); --bot_population; return true; } return false; });
		forward_list<Bot*>::iterator t = bots.begin();
		while (t != bots.end())
		{
	//		changing = true;
			(*t)->Action();
			++t;
		}
		
		if (num_generation== 1024)
		{
			my_world->Show();
			cout << bot_population << endl;
			system("pause");
		}
	}
	//if (show && log(num_generation) / log(2) == int(log(num_generation) / log(2)))
	//{
		/*for (auto t = bots.begin(); t != bots.end(); ++t)
			(*t)->Show_DNA(out);*/
		//system("pause");
		//system("pause");
	//}
}

int main()
{
	srand(time(0));


	my_world = &World::Self();
	my_world->Create_world();
	Bot_generation(64);

	for (int i = 0; i < 2025; ++i)
	{
		Selection_last_bots();
		my_world->Create_world();
		Bot_generation(0,true);
	}
	bots.front()->Write_DNA(out);
	out.close();
	system("pause");
}