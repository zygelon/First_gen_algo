#pragma once
#include <cstdlib>
#include "World.h"
//0 двигаться по направлению, 1,2 поворот, 3 - посмотреть, 4-31 - переходы
class Bot
{
	enum class dir{north,west,south,east};
public:
	Bot(int x,int y);
	Bot(const Bot& parent);//копирование
	~Bot();
	void Read_DNA();
	void Mutation(){ DNA[rand() % gen_size] = rand() % gen_size; }
	void Action();
	int Get_score() { return score; }
	bool Is_alive() { return (hp > 0); }
	void Regen() { hp = start_hp; score = 0; }
	void Write_DNA(std::ostream& os);

	int x, y;
private:
	const int gen_size = 32;
	const int moves_per_act=10;
	const int food_benefit = 10;
	const int start_hp = 20;

	int Pos_gen_math(int i) { return (pos_gen + i) % gen_size; }

	World *world_inf;

	int score;
	int moves_left;
	int *DNA;
	int hp;
	dir b_dir;
	int pos_gen;

	void Move();
	Items Look();
};

