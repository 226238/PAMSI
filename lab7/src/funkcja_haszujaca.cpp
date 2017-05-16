#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void *sortuj_slowa(string tab_slow[], int ile_liczb)
{
	int temp,i,zmiana;
	
	do
	{
		zmiana=0;
		i=ile_liczb-1;
		
		do
		{
			i--;

			if((tab_slow[i+1])[0] < (tab_slow[i])[0])
				{
					swap(tab_slow[i],tab_slow[i+1]);
					zmiana=1;
				}

		}while (i!=0);

	}while (zmiana!=0);
}

int hasz(string slowo, string tab[])
{
	for(int i=0;i<6;i++)
	{
		if(slowo == tab[i])
		{
			return i;
		}
	}
}

int main()
{
	string tab_klucz[6];

	tab_klucz[0] = "krowa";
	tab_klucz[1] = "arbuz";
	tab_klucz[2] = "draka";
	tab_klucz[3] = "wilk";
	tab_klucz[4] = "ognisko";
	tab_klucz[5] = "arbuz";

	sortuj_slowa(tab_klucz,6);

	for(int i=0;i<6;i++)
	{
		cout << tab_klucz[i] << " ";
	}
	
	cout << endl;
	
	int tab[6];

	for(int i=0;i<6;i++)
	{
		tab[i] = i ;
	}

	string slowo;
	cout << "Podaj slowo:";
	cin >> slowo;

	cout << slowo << " " << tab[hasz(slowo,tab_klucz)] << endl;

	return 0;
}