#include "stdafx.h"
#include "Knight.h"
#include <cstdio>
#include <iostream>


using namespace std;

Knight::Knight(int id)
{
	ID = id;
	if (id == 1)
	{
		Mana1 = 0;
		Hp1 = Hp1 + 150;
		Armor1 = Armor1 + 20;
	}
	if (id == 2)
	{
		Mana2 = 0;
		Hp2 = Hp2 + 150;
		Armor2 = Armor2 + 20;
	}
}

Knight::Knight()
{

}
void Knight::Start(int chooise)
{
	
	switch (chooise)
	{
	case 1:
		MortalStrike();
		break;
	case 2:
		DecreaseArmor();
		break;

	}
}
void Knight::ListOfSpells()
{
	cout << "Wybierz umiejêtnosc:" << endl;
	cout << "1.Mortal Strike" << endl;
	cout << "2.DecreaseArmor" << endl;
}
Knight::~Knight()
{
}

void Knight::ShowStats()
{
	
	if (ID == 2)
	{
		cout << "1.Hp gracza 2  =  " << Hp2 << endl;
		
		cout << "2.Dmg gracza 2 = " << Dmg2 << endl;

	}
	if (ID == 1)
	{
		cout << "1.Hp gracza 1  =  " << Hp1 << endl;
		
		cout << "2.Dmg gracza 1 = " << Dmg1 << endl;

	}
}
void Knight::Perk(int perk)
{
	if (ID == 1)
	{
		switch (perk)
		{
		case 1:
			Hp1 = Hp1 + 50;
			break;
		
		case 2:
			Dmg1 = Dmg1 + 30;
			break;
		}
	}
	if (ID == 2)
	{
		switch (perk)
		{
		case 1:
			Hp2 = Hp2 + 50;
			break;
		
		case 2:
			Dmg2 = Dmg2 + 30;
			break;
		}
	}
}
void Knight::DecreaseArmor()
{
	
	if (ID == 1)
	{
		if (Armor2 > 0)
		{
			Armor2 = Armor2 - (5 + 0.1 * Dmg2);
		}
		else
		{
			cout << "Nie mozna bardziej obnizyc armoru przeciwnika, tracisz kolejke" << endl;
			system("PAUSE");
		}
		
		
	}
	if (ID==2)
	{

		if (Armor1 > 0)
		{
			Armor1 = Armor1 - (5 + 0.1 * Dmg2);
		}
		else
		{
			
			cout << "Nie mozna bardziej obnizyc armoru przeciwnika, tracisz kolejke" << endl;
			system("PAUSE");
		}
			
	}
	if (Armor1 < 0)
	{
		Armor1 = 0;
	}
	if (Armor2 < 0)
	{
		Armor2 = 0;
	}
}
void Knight::MortalStrike()
{
	if (ID == 1)
	{
		Hp2 = Hp2 - ((50 +  Dmg1)-Armor2);
	}
	else
	{
		Hp1 = Hp1 - ((50 +  Dmg2) - Armor1);
			
	}

}