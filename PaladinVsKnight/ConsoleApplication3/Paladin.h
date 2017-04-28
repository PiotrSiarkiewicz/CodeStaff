#pragma once
#include "Game.h"
class Paladin :
	public CGame
{
public:
	void ListOfSpells();
	void Start(int chooise);
	void HolyLight();
	void DivineStorm();
	Paladin(int);
	Paladin();
	~Paladin();
};

