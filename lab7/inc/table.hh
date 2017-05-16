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
	void sortuj_slowa();
	int hasz(string slowo);
	void klucz();
	void wyswietl();

	table();
	~table();

private:
	string *tab_klucz;
	int *_table;
	int ROZMIAR;

};//..........................................

#endif