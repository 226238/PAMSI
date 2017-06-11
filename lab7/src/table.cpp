#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "table.hh"
#include "measure.hh"

using namespace std;

table::table()
{
	_size = 25;
	_table = new list[_size];
}

void table::add_elem(string key, int data)
{
	int hasz = hash(key);
	_table[hasz].add(data,key);
}

void table::find_elem(string key)
{
	int hasz = hash(key);
	_table[hasz].find(key);
}

int table::hash(string key)
{	
	return 97-(int)key[0];
}

void table::run()
{	
	table t;
	measure m;
	srand(time(NULL));

	int ile,wartosc;
	cout << "Ile slow wprowadzic ?";
	cin >> ile;

	string slowo1,slowo2;
	string slowo = "";

	for(int i=0 ; i < ile ; i++)
	{
		slowo += ((rand() % 25) + 97);
		if(i == 0) slowo1 = slowo;
		else if(i == (ile/2)) slowo2 = slowo;
		wartosc = (rand() % 9000) + 1000;
		t.add_elem(slowo,wartosc);
	}

	m.start();
	t.find_elem(slowo);
	m.stop();
}

