#include "stdafx.h"
#include "Paladin.h"
#include <cstdio>
#include <iostream>


Paladin::Paladin()
{
}
void Paladin::ListOfSpells()
{
	cout << "Wybierz umiejêtnosc:" << endl;
	cout << "1.Divine Storm (+40 many)" << endl;
	cout << "2.Holy Light (-100many) " << endl;
}

Paladin::~Paladin()
{
}
Paladin::Paladin(int id)
{
	ID = id;
}
void Paladin::Start(int chooise)
{
	

	switch (chooise)
	{
	case 1:
		DivineStorm();
		break;
	case 2:
		HolyLight();
		break;

	}
	
}
void Paladin::DivineStorm()
{
	if (ID == 1)
	{
		Mana1 = Mana1 + 40;
		Hp2 = Hp2 - (80 + (0.7*Dmg1)-Armor2);
	}
	if (ID == 2)
	{
		Mana2 = Mana2 + 40;
		Hp1 = Hp1 - (80 +  (0.7*Dmg2)-Armor1);
	}
}
void Paladin:: HolyLight()
{
	if (ID == 1)
	{
		if (Mana1 >= 100)
		{
			Hp1 = Hp1 + 200;
			Mana1 = Mana1 - 100;
		}
		else
		{
			cout << "za ma³o many" << endl;
			system("PAUSE");
		}

	}
	if (ID == 2)
	{
		if (Mana2 >= 100)
		{
			Hp2 = Hp2 + 200;
			Mana1 = Mana1 - 100;
		}
		else
		{
			cout << "za ma³o many" << endl;
			system("PAUSE");
		}
	}
}