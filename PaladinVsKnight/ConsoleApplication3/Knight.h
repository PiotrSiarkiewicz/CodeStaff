#pragma once
#include "Game.h"
class Knight : public CGame
{
public:
	Knight(int);
	Knight();
	void ListOfSpells();
	~Knight();
	 void MortalStrike();
	 void DecreaseArmor();
	 void Start(int chooise);
	 void ShowStats();
	 
	 void Perk(int perk);
	
};

