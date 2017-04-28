#pragma once
#include<list>
#include "cd.h"
class Biblioteka
{
public:
	list<cd> cdLista;
	void showAll();
	void ReadFile();
	void AddCd();
	void RemoveCd();
	void SaveToFile();
	
	Biblioteka();
	~Biblioteka();
};

