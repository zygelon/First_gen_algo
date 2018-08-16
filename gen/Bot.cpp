#include "Bot.h"

Bot::Bot(const Bot& parent)
{
	world_inf = &World::Self();
	score = 0;
	hp = start_hp;
	b_dir = parent.b_dir;
	pos_gen = parent.pos_gen;
	moves_left = moves_per_act;
	DNA = new int[gen_size];
	for (int i = 0; i < gen_size; ++i)
		DNA[i] = parent.DNA[i];
}

Bot::Bot(int x, int y)
{
	this->x = x; this->y = y;

	world_inf = &World::Self();

	score = 0;
	moves_left = moves_per_act;
	hp = start_hp;
	b_dir = dir::north;
	pos_gen = 0;
	DNA = new int[gen_size];
	DNA[0] = 0;
	DNA[1] = 1;
	DNA[2] = 3;
	for (int i = 3; i < gen_size; ++i)
		DNA[i] = rand() % gen_size;
	//DNA[i] = 3;
}

void Bot::Action() {
	--hp;
	moves_left = moves_per_act;

	for(;moves_left>0;--moves_left)
	{

		switch (DNA[pos_gen])
		{
		case 0:
			Move();
			/*
			switch (Look())
			{
			case Items::wall:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 1)]);
				break;
			case Items::food:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 2)]);
				break;
			case Items::poison:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 3)]);
				break;
			case Items::bot:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 4)]);
				break;
			default:
				pos_gen = Pos_gen_math(pos_gen + 5);
				break;
			}*/
			moves_left = 0;
			break;
		case 1:
			b_dir = (dir)(((int)b_dir + 3) % 4);
			/*
			switch (Look())
			{
			case Items::wall:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 1)]);
				break;
			case Items::food:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 2)]);
				break;
			case Items::poison:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 3)]);
				break;
			case Items::bot:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 4)]);
				break;
			default:
				pos_gen = Pos_gen_math(pos_gen + 5);
				break;
			}*/
			break;
		case 2:
			b_dir = (dir)(((int)b_dir + 1) % 4);
			/*
			switch (Look())
			{
			case Items::wall:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 1)]);
				break;
			case Items::food:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 2)]);
				break;
			case Items::poison:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 3)]);
				break;
			case Items::bot:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 4)]);
				break;
			default:
				pos_gen = Pos_gen_math(pos_gen + 5);
				break;
			}*/
			break;
		case 3:
			switch (Look())
			{
			case Items::wall:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 1)]);
				break;
			case Items::food:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 2)]);
				break;
			case Items::poison:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 3)]);
				break;
			case Items::bot:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 4)]);
				break;
			default:
				pos_gen = Pos_gen_math(DNA[Pos_gen_math(pos_gen + 5)]);
				break;
			}
			continue;
			break;
		default:
			pos_gen = (pos_gen + DNA[pos_gen]) % gen_size;
			continue;
			break;
		}
		pos_gen = Pos_gen_math(1);
	}
}

Bot::~Bot()
{
	world_inf->map[y][x] = Items::empty;
	delete[] DNA;
}

void Bot::Move()
{
	bool change_pos=false;
	int new_x=x, new_y=y;
	switch (b_dir)
	{
	case Bot::dir::north:
		new_y--;
		break;
	case Bot::dir::west:
		new_x++;
		break;
	case Bot::dir::south:
		new_y++;
		break;
	case Bot::dir::east:
		new_x--;
		break;
	}
	
	switch (world_inf->Get_inf(new_x, new_y))
	{
	case Items::wall:
		return;
		break;
	case Items::empty:
		change_pos = true;
		break;
	case Items::poison:
		hp = -200;
		return;
		break;
	case Items::food:
		hp += food_benefit;
		score++;
		change_pos = true;
		break;
	case Items::bot:
		return;
		break;
	}
	if (change_pos)
	{
		world_inf->map[y][x]=Items::empty;
		x = new_x;
		y = new_y;
		world_inf->map[y][x]=Items::bot;
	}

}

Items Bot::Look()
{
	switch (b_dir)
	{
	case Bot::dir::north:
		return world_inf->Get_inf(x, y - 1);
	case Bot::dir::west:
		return world_inf->Get_inf(x + 1, y);
	case Bot::dir::south:
		return world_inf->Get_inf(x, y + 1);
	case Bot::dir::east:
		return world_inf->Get_inf(x - 1, y);
	}
}

void Bot::Write_DNA(std::ostream &os)
{
	/*for (int i = 0; i < gen_size; ++i)
	{
		if (i < 10) cout << " ";
		cout << i << " ";
	}
	cout << '\n';*/
	os << gen_size << '\n';
	for (int i = 0; i < gen_size; ++i)
	{
		if (DNA[i] < 10) os << " ";
		os << DNA[i] << " ";
	}
	if (typeid(os) == typeid(cout))
	{
		cout << '\n';
		for (int i = 0; i < gen_size; ++i)
		{
			if (i < 10) os << " ";
			os << i << " ";
		}
	}
	os << '\n'<<'\n';
}