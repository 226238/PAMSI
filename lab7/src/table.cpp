#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "table.hh"
#include "measure.hh"

using namespace std;

table::table()
{
	_size = 1000;
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
	int suma = 0;
	for (unsigned int i = 0 ; i < key.length() ; i++)
	{
		suma +=(int)key[i];
	}

	//return suma%_size;               // haszowanie 1

	float A = (sqrt(5) - 1) / 2;                   // haszowanie 2

	return (int) (_size * fmod(suma * A,1));       // 

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

