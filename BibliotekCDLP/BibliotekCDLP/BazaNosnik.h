#pragma once
#include <string>
using namespace std;
class BazaNosnik
	 
{
public:
	virtual void showInfo();
	virtual void writeInfo();

protected:
	string Autor;
	string Album;
	string RokWydania;
	BazaNosnik();
	~BazaNosnik();
};

