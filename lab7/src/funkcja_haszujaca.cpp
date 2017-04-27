#include <iostream>
#include <string>

using namespace std;

int haszuj(string hasz)
{
	return (int)hasz[0]-97;
}

int main()
{
	string klucz;
	cout << "Podaj klucz: ";
	cin >> klucz;

	//cout << haszuj(klucz) << endl;

	int ROZMIAR = 26;

	int *tablica = new int [ROZMIAR];
	
	for (int i=0; i < ROZMIAR ; i++) tablica[i] = i;

	cout << tablica[haszuj(klucz)] << endl;

	return 0;
}