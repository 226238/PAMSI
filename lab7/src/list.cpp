#include "list.hh"
#include <iostream>
#include <cstdlib>


using namespace std;

/*
	metody klasy list
*/

list::list()  // konstruktor listy (domyslnie brak elementow)
{
	head = NULL;
	SIZE = 0;
}

void list::add(int wartosc, string klucz)  // dodawanie elementu do listy
{
	SIZE++;   // zwiekszenie licznika rozmiaru

	elem *n_elem = new elem;   // tworzenie nowego elementu listy

	n_elem -> w_elem = wartosc;  // wypelnianie elementu wartoscia
	n_elem -> k_elem = klucz;

	if(head == NULL)  // warunek na bycie pierwszym elementem listy
	{
		head = n_elem;  // jezeli pierwszy to element poczatkiem listy
	}

	else
	{
		elem *temp = head;

		while(temp -> next)  // poszukiwanie ostatniego elementu
		{
			temp = temp -> next;
		}

		temp -> next = n_elem;    // ostatni wskazuje na nowy element
		n_elem -> next = NULL;    // nowy element wskazuje na NULL
	}
}

void list::remove()  // usuwanie elemenetu z listy z dowolnego miejsca
{
	SIZE --;  // pomniejszenie licznika elementow

	int value;    // nr indeksu ktory chcemy usunac

	cout << "Podaj ktore miejsce na liscie chcesz usunac: ";
	cin >> value;

	if(SIZE == 0)  // jezeli lista pusta to error
	{
		cout << "Brak elementu do usuniecia !" << endl;
	}
	else
	{
		if(value == 1)    // jezeli to 1 element
		{
			elem *temp = head;   
			head = temp -> next;   // to nastepny element staje sie "glowa" listy
		}
		else if (value >= 2)    // jezeli to kolejny element
		{
			int i = 1;
			elem *temp = head;  // wskaznik na poczatek zeby przeszukiwac od poczatku

			while(temp)    // dopoki temp != NULL to petla trwa
			{
				if( (i+1) == value )  // sprawdzanie czy wskaznik jest na elemencie wczesniej niz usuwany
				{
					break;
				}
				else   // jezeli nie to idziemy dalej
				{
					temp = temp -> next;
					i++;
				}
			}
			
			if(temp -> next -> next == NULL)  // jezeli usuwany element byl ostatnim to wskaznik elementu wczesniej idzie na NULL
			{
				temp -> next = NULL;
			}
			else
			{
				temp -> next = temp -> next -> next; // wskaznik z elementu wczesniej dajemy na element po elemencie usuwanym i w efekcie tracimy wskaznik na usuwany element wiec go usuwamy
			}
		}
	}
}

void list::size() // pokazywanie rozmiaru i elementow
{
	cout << "Aktualna ilosc elementow na liscie to " << SIZE << endl;

	elem *temp = head;   // ustawienie wskaznika temp na poczatek listy

	while(temp)    // przeszukiwanie listy i wyswietlanie kazdego elementu
	{
		cout << temp -> w_elem << " " << temp -> k_elem << " ";
		temp = temp -> next;    // przekazwyanie wskaznika dalej
	}

	cout << endl;
}

void list::find(string klucz)  // szukanie elementu
{
	elem *temp = head;   // wskaznik na pierwszy element

	int f = 0;

	while(temp)   // przeszukwanie listy
	{
		if(temp -> k_elem == klucz)     // warunek na znalezienie elementu
		{
			cout << "Znaleziono warosc !" << temp -> w_elem << endl;
			temp = NULL;    // zerwoanie wskaznika zeby zakonczyl petle
			f = 1;    // takia 0 - 1 zmienna jak 1 to znaleziono to czego szukalismy
		}
		else if(temp -> k_elem != klucz)    // jezeli nie znalezlismy to szukamy dalej
		{
			temp = temp -> next;
		}
	}

	if(f == 0)   // jezeli dojechalismy na koniec listy i nie znalezlismy to nie ma
	{
		cout << "Nie znaleziono szukanej wartosci !" << endl;
	}
}