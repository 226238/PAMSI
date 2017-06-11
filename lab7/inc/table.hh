#ifndef TABLE_HH
#define TABLE_HH

#include <string>

#include "itable.hh"
#include "irunnable.hh"
#include "list.hh"

using namespace std;

// definicja klasy table

class table : public itable, public irunnable {//.............................

public:
	void run();
	int hash(string key);
	void add_elem(string key, int data);
	void find_elem(string key);

	table();

private:
	list *_table;
	int _size;
};//..........................................

#endif