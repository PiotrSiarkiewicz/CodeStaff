#include "stdafx.h"
#include "Biblioteka.h"
#include <list>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
Biblioteka::Biblioteka()
{

}

void Biblioteka::showAll()
{
	int id = 1;
	for (list<cd>::iterator it = cdLista.begin(); it != cdLista.end(); it++)
	{
		
		
		it->showInfo();
		cout << id<<". ";
		id++;
	}
}


Biblioteka::~Biblioteka()
{

}
void Biblioteka::ReadFile()
{
	
	string tmp; 
	fstream file;
	file.open("Biblioteka.csv", fstream::in | fstream::out);
	string x[3];
	string x0;
	string linia;
	int tab_counter = 0;
	
	
	while (file.good())
	{
		
		getline(file, tmp);
		
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] != ',')
			{
				x0 +=tmp[i];
			}
			else
			{
				x[tab_counter++] = x0;
				x0= "";
			}

		}
		
		x[tab_counter++] = x0;
		x0 = "";
		tab_counter = 0;
		
		
		cdLista.push_back(cd(x[0], x[1], x[2]));
	
	}
	cdLista.pop_back();
	file.close();
}

void Biblioteka::SaveToFile()
{
	fstream file;
	file.open("Biblioteka.csv",std::ios::out|std::ios::trunc);
	file.clear();
	file.close();

	for (list<cd>::iterator it = cdLista.begin(); it != cdLista.end(); it++)

	{


		it->writeInfo();
		
	}
		
	
	



}
void Biblioteka::RemoveCd()
{
	list<cd>::iterator it1;
	int rem;
	it1 = cdLista.begin();
	cout << "Wpisz id plyty do usuniecia:" << endl;
	
	cin >> rem;
	advance(it1, rem);
	cdLista.erase(it1);
	cout << "Usunieto " << endl;
}
void Biblioteka::AddCd()
{
	
	cout << "Wprowadz imie autora, nazwe albumu i rok wydania:  " << endl;
	string autor;;
	string album;
	string rok;
	
	cin >> autor;
	cin >> album;
	cin >> rok;

	cdLista.push_back(cd(autor, album, rok));
	cout << "Dodadno " << endl;
}