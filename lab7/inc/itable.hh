#ifndef ITABLE_HH
#define ITABLE_HH

#include <string>

using namespace std;

// definicja klasy table

class itable{//.............................

public:
	virtual void dodaj_element() = 0;
	virtual int hasz(string slowo) = 0;
	virtual void wyswietl() = 0;
	virtual void znajdz() = 0;
};//..........................................

#endif