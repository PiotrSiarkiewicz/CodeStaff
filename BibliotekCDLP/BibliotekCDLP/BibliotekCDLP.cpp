// BibliotekCDLP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cd.h"
#include "BazaNosnik.h"
#include "Biblioteka.h"
#include<iostream>
int _tmain(int argc, _TCHAR* argv[])
{
	Biblioteka Bib1;
	int odp=0;
	Bib1.ReadFile();
	while (odp != 4)
	{

		
		
		cout << "Wybierz opcje: " << endl;
		cout << "1.Wyswietl  biblioteka " << endl;
		cout << "2.Dodaj plyte" << endl;
		cout << "3.Usun plyte " << endl;
		cout << "4.Zapisz do pliku i  zamknij program" << endl;
		cin >> odp;

		switch (odp)
		{
		case 1:
			Bib1.showAll();
			break;
		case 2:
			Bib1.AddCd();
			break;
		case 3:
			Bib1.RemoveCd();
			break;
		case 4:
			Bib1.SaveToFile();
		default:
			break;

		}
		system("PAUSE");
		system("CLS");

	}

	
	
	return 0;

}

