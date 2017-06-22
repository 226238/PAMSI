#ifndef WARCABY_HH
#define WARCABY_HH


class warcaby{
  int plansza[8][8];

public:

  struct ruch{
    //aktualne wspolrzedne pionka
    int i , j ;
    //wspolrzedne celu pionka
    int k , l ;
  };

  warcaby(); // konstruktor

  void rysuj_plansze(); //rysowanie planszy

  int oplacalnosc_ruchu(warcaby); //funkcja krawedziowa

  int minimax(warcaby,int gracz,int glebokosc,ruch&);

  bool koniec_gry(warcaby); //sprawdzanie czy gra sie skonczyla

  bool czy_mozna(warcaby w,int kolej,int z_k1,int z_w1,int do_k2,int do_w2); // sprawdzanie czy mozna wykonac ruch

  ruch ruch_komputera(warcaby,int);//funkcja zwracajaca ruch komputera

  ruch ruch_gracza(warcaby); //funkcja zwracajaca ruch gracza

  warcaby wykonaj_ruch(warcaby,int, int i,int j,int k,int l); //funkcja wykonujaca ruch 
};

#endif
