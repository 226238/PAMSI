#ifndef TABLE_HH
#define TABLE_HH

#include <string>

#include "itable.hh"
#include "irunnable.hh"

using namespace std;

// definicja klasy table

class table : public itable, public irunnable {//.............................

public:
	void run();
	int hasz(string slowo);
	void wyswietl();
	void dodaj_element();
	void znajdz();
	
	table();
	~table();

private:
	string *tab_klucz;
	int *tab_wartosc;
	int ROZMIAR;

};//..........................................

#endif