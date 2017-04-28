#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class CGame
{
public:
	
    static bool CheckHP();
	virtual void Start(int chooise);
	virtual void Perk(int perk);
	//int Chooise;
	//virtual void MortalStrike();
	//friend istream& operator>> (istream&, Foo&);
	virtual void ListOfSpells();
	virtual void ShowStats();
protected:
	static int Hp1, Hp2, Mana1, Mana2, Armor1, Armor2,Dmg1,Dmg2;
	int ID;
	int Dmg;
	CGame();
	~CGame();
};

