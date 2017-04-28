#pragma once
#include "BazaNosnik.h"
#include <string>
class cd :
	public BazaNosnik
{
public:
	void writeInfo();
	void showInfo();
	cd();
	cd(std::string, std::string, std::string);
	~cd(); 
};

