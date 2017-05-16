#include <cstdlib>
#include <iostream>
#include <string>
#include "table.hh"

using namespace std;

table::table()
{
	cout << "Ile wyrazow chcesz wprowadzic?";
	cin >> ROZMIAR;

	tab_klucz = new string [ROZMIAR];

	for(int i=0 ; i < ROZMIAR ; i++)
	{
		cout << "Podaj wyraz nr " << i << " ";
		cin >> tab_klucz[i];
	}

	sortuj_slowa();

	_table = new int [ROZMIAR];

	for(int i=0 ; i < ROZMIAR ; i++)
	{
		_table[i] = i;
	}
}

table::~table()
{
	delete [] _table;
	delete [] tab_klucz;
}

void table::sortuj_slowa()
{
	int i, zmiana;
	string temp;

	do
	{
		zmiana = 0;
		i = ROZMIAR-1;
		
		do
		{
			i--;

			if((tab_klucz[i+1])[0] < (tab_klucz[i])[0])
				{
					temp = tab_klucz[i];
					tab_klucz[i] = tab_klucz[i+1];
					tab_klucz[i+1] = temp;
					zmiana = 1;
				}

		}while (i != 0);

	}while (zmiana != 0);
}

int table::hasz(string slowo)
{
	for(int i = 0 ; i < ROZMIAR ; i++)
	{
		if(slowo == tab_klucz[i])
		{
			return i;
		}
	}
}

void table::klucz()
{
	for(int i = 0 ; i < ROZMIAR ; i++)
	{
		cout << "Nr: " << i << " ; " << "Slowo: " << tab_klucz[i] << endl;
	}
}

void table::wyswietl()
{
	string slowo;

	while (slowo != "end")
	{	
		cout << "Podaj slowo (end aby zakonczyc): ";
		cin >> slowo;
		cout << slowo << " " << _table[hasz(slowo)] << endl;
	}
}

void table::run()
{
	klucz();

	wyswietl();	
}