#include "stdafx.h"
#include "Game.h"
#include <cstdio>
#include <iostream>
using namespace std;

CGame::CGame()
{

}
int CGame:: Hp1 = 500;
int CGame:: Hp2 = 500;
int CGame:: Mana1 = 200;
int CGame:: Mana2 = 200;
int CGame:: Armor1 = 50;
int CGame:: Armor2 = 50;
int CGame:: Dmg1 = 50;
int CGame:: Dmg2 = 50;
CGame::~CGame()
{
}
void CGame::ShowStats()
{
	if (ID == 2)
	{
		cout << "1.Hp gracza 2 =  " << Hp2 << endl;
		cout << "2.Mana gracza 2 = " << Mana2 << endl;
		cout << "3.Dmg gracza 2 = " << Dmg2 << endl;

	}
	if (ID == 1)
	{
		cout << "1.Hp gracza 1 =  " << Hp1 << endl;
		cout << "2.Mana gracza 1 = " << Mana1 << endl;
		cout << "3.Dmg gracza 1= " << Dmg1 << endl;

	}
}
void CGame::Perk(int perk)
{
	if (ID == 1)
	{
		switch (perk)
		{
		case 1:
			Hp1 = Hp1 + 50;
			break;
		case 2:
			Mana1 = Mana1 + 100;
			break;
		case 3:
			Dmg1 = Dmg1 + 20;
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
			Mana2 = Mana2 + 100;
			break;
		case 3:
			Dmg2 = Dmg2 + 30;
			break;
		}
	}
	
	

}
void CGame::Start(int chooise)
{
		
}

void CGame::ListOfSpells()
{

}

/*istream& operator>> (istream &wejscie, Foo& game)
{

	wejscie >> game.Chooise;
	return wejscie;
}*/

bool CGame::CheckHP()
{
	
	
		if (Hp2 <= 0)
		{
			cout << "Player 1 wone the game" << endl;
			return false;
		}
		if (Hp1 <= 0)
		{
			cout << "Player 2 won the game" << endl;
			return false;
		}
		cout << "Hp gracza 1    = " << Hp1 <<    "     Hp gracza 2   = " << Hp2 << endl;
		cout << "Mana gracza 1  = " << Mana1 <<  "     Mana gracza 2 = " << Mana2 << endl;
		cout << "Armor gracza 1 = " << Armor1 << "     Armor gracza 2 = " << Armor2 << endl;
		cout << "Dmg gracza 1   = " << Dmg1 <<   "     Dmg gracza 2  = " << Dmg2 << endl;
		return true;

}
