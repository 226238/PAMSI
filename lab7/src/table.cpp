#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "table.hh"

using namespace std;

table::table()  // konstruktor definiujacy ile elementow bedzie w tablicy
{
	cout << "Ile elementow chcesz wprowadzic ? ";
	cin >> ROZMIAR;

	tab_klucz = new string [ROZMIAR];

	tab_wartosc = new int [ROZMIAR];
}

table::~table()
{
	delete [] tab_klucz;
	delete [] tab_wartosc;
}

void table::dodaj_element()  // dodawanie elementu i jego wartosci pojedynczo z klawiatury lub generowanie losowych elementow i wartosci
{
	srand(time(NULL));
	int wartosc, ile_liter_ma_miec_slowo = 4;

	for(int i=0 ; i < ROZMIAR ; i++)
	{
/*
		cout << "Podaj slowo: ";
		cin >> slowo;
		cout << "Podaj wartosc dla slowa " << slowo << " ";
		cin >> wartosc;
*/

		string slowo = "";

		for(int n = 0 ; n < ile_liter_ma_miec_slowo ; n++)
		{
			slowo += ((rand() % 25) + 97);
		}

		wartosc = (rand() % 9000) + 1000;

		tab_klucz[i] = slowo;
		tab_wartosc[i] = wartosc;
	}
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

void table::wyswietl() // funkcja wyswietla wartosc podanego slowa z tablicy lub wszystkie slowa wraz z wartosciami
{
/*
	string slowo;

	while (slowo != "end")
	{	
		cout << "Podaj slowo (end aby zakonczyc): ";
		cin >> slowo;
		cout << "Wartosc slowa " << slowo << " to " << tab_wartosc[hasz(slowo)] << "." << endl;
	}
*/
	for(int i = 0 ; i < ROZMIAR ; i++)
	{
		cout << tab_klucz[i] << "_" << tab_wartosc[hasz(tab_klucz[i])] << " ";
	}

	cout << endl;
}

void table::znajdz() // funkcja znajduje slowo po indeksie w tablicy
{
	int co;

	//co = 0;           // szukanie wartosci znajdujacej sie na poczatku
	//co = (ROZMIAR-1);     // szukanie wartosci znajdujacej sie na koncu
	co = (ROZMIAR/2);  // szukanie wartosci znajdujacej sie po srodku

	cout << tab_klucz[co] << "_" << tab_wartosc[hasz(tab_klucz[co])] << endl;
}

void table::run()
{
	dodaj_element();

	//wyswietl();	

	znajdz();
}

