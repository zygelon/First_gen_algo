#include "Simulation.h"



Simulation::Simulation()
{
	//max_generation = max_gen;
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
		bots.front()->Mutation();
		bots.front()->Mutation();
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
	for (int i = 0; i < min_bots; ++i, ++t)
		for (int j = 0; j < max_bots/min_bots-1; ++j)
		{
			if(generation>900 && i==0) sum_score += (*t)->Get_score();
			(*t)->Regen();
			Bot* t_b = new Bot(**t);
			if (j < (max_bots/min_bots)/2+1)
			{
				t_b->Mutation();
				t_b->Mutation();
				t_b->Mutation();
				t_b->Mutation();
			}
			map->Set_empty_pos(t_b->x, t_b->y);
			bots.push_front(t_b);
		}
	;
}

void Simulation::Last_bots_selection() {
	generation++;
	map->Create_world();
	while (bots_alive > min_bots)
	{
		bots.remove_if( [this](Bot* t)
		{if (!t->Is_alive() && bots_alive > min_bots) { t->~Bot(); --bots_alive; return true; } return false; });

		forward_list<Bot*>::iterator t = bots.begin();
		while (t != bots.end())
		{
			(*t)->Action();
			++t;
		}
		if (selected_gener == generation) {
			graphics.Draw();
		}
	}
	
}

void Simulation::Show_curr_gener()
{
//	static char skip = 'a';
//	map->Show();
//	skip = _getch();
//	if (skip == 's' && bots_alive!=min_bots) return;
	cout << "Bot allive " << bots_alive << '\n';
	if (bots_alive == min_bots)
	{
		cout << "------------------------------\nDNA and Score:\n";
		for (auto i = bots.begin(); i != bots.end(); ++i)
		{
			cout << "Score = " << (*i)->Get_score() << '\n';
			(*i)->Write_DNA(cout);
		}
		cout << "------------------------------\n";
	}
	//system("pause");
}

void Simulation::Write_DNA(ostream& os)
{
	auto iter = bots.begin();
	for (int i = 0; i < max_bots - 2; ++i, ++iter);
	(*iter)->Write_DNA(os);
}