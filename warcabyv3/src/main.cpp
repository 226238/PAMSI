#include "warcaby.hh"
#include <iostream>

using namespace std;


int main()
{

  warcaby gra;
  int poziom_trudnosci, czyja_kolej=1; // 1-GRACZ / -1-KOMPUTER

  cout << "\t!!! WARCABY !!! \nWYBIERZ POZIOM TRUDNOSCI" << endl;
  cout << "1. LATWY" << endl <<"2. SREDNI" << endl << "3. TRUDNY" << endl;

  do
  {
    cin >> poziom_trudnosci;
    
    switch(poziom_trudnosci)
    {
      case 1: cout  <<  "Wybrano poziom latwy!" <<  endl;  poziom_trudnosci = 1; break;
      case 2: cout  <<  "Wybrano poziom sredni!"  <<  endl; poziom_trudnosci  = 3; break;
      case 3: cout  <<  "Wybrano poziom trudny!"<<  endl; poziom_trudnosci  = 6; break;
      default: cout <<  "Bledny wybor!" <<  endl; break;
    }
  }while(poziom_trudnosci != 1 && poziom_trudnosci != 3 && poziom_trudnosci != 6);

  while(!gra.koniec_gry(gra)){
      warcaby::ruch r;
      system("clear");
      if(czyja_kolej==1){
	       gra.rysuj_plansze();
	       r=gra.ruch_gracza(gra);
	       gra=gra.wykonaj_ruch(gra,1,r.i,r.j,r.k,r.l);
	       system("clear");
	    }
      if(czyja_kolej==-1){
			cout << "///////////////////////////////////////////////\nRuch komputera! Prosze czekac!\n///////////////////////////////////////////////" << endl;
	       r=gra.ruch_komputera(gra,poziom_trudnosci);
	       gra=gra.wykonaj_ruch(gra,-1,r.i,r.j,r.k,r.l);
	    }
      czyja_kolej=-czyja_kolej;
  }
}
