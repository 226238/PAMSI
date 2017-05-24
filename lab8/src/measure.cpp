#include "measure.hh"

#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

/*
	metody klasy measure
*/

void measure::start() // start stopera
{
	czas = clock();
}

void measure::stop() // zatrzymanie stopera
{
	double ile_czasu = ((clock() - czas)) / (double) CLOCKS_PER_SEC;  // jednostki to sekundy

	cout << "Czas trwania programu to " << ile_czasu << " s." << endl;

	fstream plik;                                              // zapisywanie wynikow do pliku
	plik.open( "pomiary.txt" ,  ios::out | ios::app );    // dopisywanie danych a nie ich nadpisywanie

	if(plik.good() == true)
	{
		plik << ile_czasu << endl;

		plik.close();
	}

	else
	{
		cout << "Brak dostepu do pliku! Dane nie beda zapisane!" << endl;
	}

}

void measure::gauge(irunnable & test_obj)   // pomiar czasu dzialania algorytmu
{
	start();
	test_obj.run();
	stop();
}