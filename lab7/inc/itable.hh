#ifndef ITABLE_HH
#define ITABLE_HH

#include <string>

using namespace std;

// definicja klasy table

class itable{//.............................

public:
	virtual int hash(string key) = 0;
	virtual void add_elem(string key, int data) = 0;
	virtual void find_elem(string key) = 0;
};//..........................................

#endif