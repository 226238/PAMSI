#ifndef LIST_HH
#define LIST_HH

#include "ilist.hh"

#include <cstdlib>
#include <string>


using namespace std;
/*
	klasa list
*/

class list {
public:
	void add(int wartosc, string klucz);
	void remove();
	void size();
	void find(string klucz);

	list();

private:
	struct elem{  // struktura odpowiadajaca jednemu elementowi na liscie
		int w_elem;   // wartosc elementu
		string k_elem; // klucz elementu
		elem *next;   // wskaznik na nastepny element jezeli brak nastepenego to NULL

		elem()
		{
			next = NULL;
		}
	};

	elem *head;    // wskaznik na pierwszy element listy

	int SIZE;    // licznik do rozmiaru listy
};

#endif