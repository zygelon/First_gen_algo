#pragma once
#include <cstdlib>
#include "World.h"
//0 ��������� �� �����������, 1,2 �������, 3 - ����������, 4-31 - ��������
class Bot
{
	enum class dir{north,west,south,east};
public:
	Bot(int x,int y);
	Bot(const Bot& parent);//�����������
	~Bot();
	void Read_DNA();
	void Mutation(){ DNA[rand() % gen_size] = rand() % max_jump; }
	void Action();
	bool Is_alive() { return (hp > 0); }
	void Regen() { hp = start_hp; score = 0; }
	void Write_DNA(std::ostream& os);

	int x, y;
private:
	const int gen_size = 64;
	const int max_jump = 64;
	const int moves_per_act=10;
	const int food_benefit = 20;
	const int start_hp = 50;

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
