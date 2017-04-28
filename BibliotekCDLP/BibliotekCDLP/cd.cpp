#include "stdafx.h"
#include "cd.h"
#include<iostream>
#include<fstream>
using namespace std;

cd::cd()
{
}

cd::cd(string autor, string album, string rok)
{
	Autor = autor;
	Album = album;
	RokWydania = rok;
}

void cd::writeInfo()
{
	ofstream file;
	file.open("Biblioteka.csv" , std::ios::in | std::ios::out | std::ios::ate);
	
	file << Autor << "," << Album << "," << RokWydania << endl;
	
	
	file.close();
}

void cd::showInfo()
{
	
	cout << Autor;
	for (int i = Autor.length(); i < 20; i++)
	{
		cout << " ";
	}

	cout << Album;
	for (int j = Album.length(); j < 20; j++)
	{
		cout << " ";
	}




	cout << RokWydania << endl;;

	//cout << Autor << "        |       " << Album << "        |      " << RokWydania << endl;
}

cd::~cd()
{
}
