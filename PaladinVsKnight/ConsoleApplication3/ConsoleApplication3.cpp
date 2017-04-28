// ConsoleApplication3.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include "Game.h"
#include "Paladin.h"
#include "Knight.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int perk = 0;
	int chooise = 0;
	Paladin g1(1);

	Knight  g2(2);
	for (int i = 4; i >0 ; i--)
	{ 
		cout << "Ulepsz atrybuty dla gracza 1, pozstalo = " << i << endl;
		g1.ShowStats();
		cin >> perk;
		g1.Perk(perk);
		system("CLS");
	}
	for (int i = 4; i > 0 ; i--)
	{
		cout << "Ulepsz atrybuty dla gracza 2, pozstalo = " << i << endl;
		g2.ShowStats();
		cin >> perk;
		g2.Perk(perk);
		system("CLS");
	}
	while(g1.CheckHP()==true)
	{
		cout << endl;
		cout << "Gracz 1 wykonuje ruch" << endl;
		g1.ListOfSpells();
		cin >> chooise;
		g1.Start(chooise);
		g1.CheckHP();
		system("CLS");
		
		if (g1.CheckHP() == false)break;
		cout << endl;
		cout << "Gracz 2 wykonuje ruch" << endl;
		g2.ListOfSpells();
		cin >> chooise;
		g2.Start(chooise);
		g2.CheckHP();
		system("CLS");
	}
	
	return 0;
}

