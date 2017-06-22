#include "warcaby.hh"
#include <iostream>
#include <climits>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
warcaby::warcaby(){
  // rysowanie tablicy
 int tablica[8][8]=
  {{ 0,-1, 0,-1, 0,-1, 0,-1},
   {-1, 0,-1, 0,-1, 0,-1, 0},
   { 0,-1, 0,-1, 0,-1, 0,-1},
   { 0, 0, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0 ,0},
   { 1, 0, 1, 0, 1, 0, 1, 0},
   { 0, 1, 0, 1, 0, 1, 0, 1},
   { 1, 0, 1, 0, 1, 0, 1, 0}};
  // przepisanie tablicy do planszy
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      plansza[i][j]=tablica[i][j];
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
void warcaby::rysuj_plansze(){
  cout<<"   0   1   2   3   4   5   6   7 "<<endl<<" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
  for(int i=0;i<8;i++){
    cout<<i;
    for(int j=0;j<8;j++){
	     cout<<"|";
	      switch(plansza[i][j]){
          case  0: cout<<"   ";break;
	        case -1: cout  <<" C "; break;
	        case  1: cout  <<" B "; break;
	        case -2: cout  <<" CD"; break;
	        case  2: cout  <<" BD"; break;
	      }
	  }
      cout<<"|" << i << endl;
      cout<<" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
  }
  cout<<"   0   1   2   3   4   5   6   7 "<<endl;
}
////////////////////////////////////////////////////////////////////////////////
bool warcaby::czy_mozna(warcaby p, int gracz, int x, int y, int k, int l){
    if(x>=0 && y>=0 && k>=0 && l>=0 && x<=7 && y<=7 && k<=7 && l<=7){
      //////////////////DAMKA GRACZA//////////////////////////
       if(gracz==1 && p.plansza[y][x]==2){
	        //ruch w lewo do tylu
          if(k>x && l<y){
                if( (k==x+1 && l==y-1) || (k==x+2 && l==y-2) ||
                    (k==x+3 && l==y-3) || (k==x+4 && l==y-4) || (k==x+5 && l==y-5) ||
                    (k==x+6 && l==y-6) || (k==x+7 && l==y-7) ){
                    int temp=y-1;
                    for(int i=x+1; i<=k; i++){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2){
                                if(temp!=0 || i!=7){
                                    if(p.plansza[temp-1][i+1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
          }
	        //ruch w prawo do tylu
          if (k>x && l>y){
                if( (k==x+1 && l==y+1) || (k==x+2 && l==y+2) ||
                    (k==x+3 && l==y+3) || (k==x+4 && l==y+4) || (k==x+5 && l==y+5) ||
                    (k==x+6 && l==y+6) || (k==x+7 && l==y+7) ){
                    int temp=y+1;
                    for(int i=x+1; i<=k; i++){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2){
                                if(temp!=7 || i!=7){
                                    if(p.plansza[temp+1][i+1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }
	          //ruch w lewo do przodu
            if(k<x && l<y){
                if( (k==x-1 && l==y-1) || (k==x-2 && l==y-2) ||
                    (k==x-3 && l==y-3) || (k==x-4 && l==y-4) || (k==x-5 && l==y-5) ||
                    (k==x-6 && l==y-6) || (k==x-7 && l==y-7) ){
                    int temp=y-1;
                    for(int i=x-1; i>=k; i--){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2){
                                if(temp!=0 || i!=0){
                                    if(p.plansza[temp-1][i-1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	          //ruch w prawo do przodu
            if (k<x && l>y){
                if( (k==x-1 && l==y+1) || (k==x-2 && l==y+2) ||
                    (k==x-3 && l==y+3) || (k==x-4 && l==y+4) || (k==x-5 && l==y+5) ||
                    (k==x-6 && l==y+6) || (k==x-7 && l==y+7) ){
                    int temp=y+1;
                    for(int i=x-1; i>=k; i--){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2){
                                if(temp!=7 || i!=0){
                                    if(p.plansza[temp+1][i-1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }
        }
        //////////////////DAMKA KOMPUTERA//////////////////////////////
        if(gracz==-1 && p.plansza[y][x]==-2){
	         //ruch do przodu w lewo
            if(k>x && l<y){
                if( (k==x+1 && l==y-1) || (k==x+2 && l==y-2) ||
                    (k==x+3 && l==y-3) || (k==x+4 && l==y-4) || (k==x+5 && l==y-5) ||
                    (k==x+6 && l==y-6) || (k==x+7 && l==y-7) ){
                    int temp=y-1;
                    for(int i=x+1; i<=k; i++){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2){
                                if(temp!=0 || i!=7){
                                    if(p.plansza[temp-1][i+1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	          //ruch w prawo do przodu
            if (k>x && l>y){
                if( (k==x+1 && l==y+1) || (k==x+2 && l==y+2) ||
                    (k==x+3 && l==y+3) || (k==x+4 && l==y+4) || (k==x+5 && l==y+5) ||
                    (k==x+6 && l==y+6) || (k==x+7 && l==y+7) ){
                    int temp=y+1;
                    for(int i=x+1; i<=k; i++){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2){
                                if(temp!=7 || i!=7){
                                    if(p.plansza[temp+1][i+1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }
	          //ruch w lewo do tylu
            if(k<x && l<y){
                if( (k==x-1 && l==y-1) || (k==x-2 && l==y-2) ||
                    (k==x-3 && l==y-3) || (k==x-4 && l==y-4) || (k==x-5 && l==y-5) ||
                    (k==x-6 && l==y-6) || (k==x-7 && l==y-7) ){
                    int temp=y-1;
                    for(int i=x-1; i>=k; i--){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2 ){
                                if(temp!=0 || i!=0){
                                    if(p.plansza[temp-1][i-1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	          //ruch do tylu w prawo
            if (k<x && l>y){
                if( (k==x-1 && l==y+1) || (k==x-2 && l==y+2) ||
                    (k==x-3 && l==y+3) || (k==x-4 && l==y+4) || (k==x-5 && l==y+5) ||
                    (k==x-6 && l==y+6) || (k==x-7 && l==y+7) ){
                    int temp=y+1;
                    for(int i=x-1; i>=k; i--){
                        if(p.plansza[temp][i]!=0){
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2){
                                if(temp!=7 || i!=0){
                                    if(p.plansza[temp+1][i-1]!=0){
                                        return false;
                                    }
                                }
                                else{
                                    return false;
                                }
                            }
                            else{
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
          }
        }
	      //ruch komputera
        if(gracz==-1){
	      //zwykly pionek komputera
           if(p.plansza[y][x]==-1){
	         //jezeli pole jest wolne
                if(p.plansza[l][k]==0){
		             //ruch w przod
                    if(l==y+1){
		                    //lewo lub prawo
                        if(k==x+1||k==x-1){
                            return true;
                        }
                    }
                }
		            //ruch z biciem
                if(l==y+2){
		                //bicie w prawo
                    if(k==x+2){
		                    //miejsce za pionkiem wolne
                        if(p.plansza[l][k]==0){
			                       //bity pionek jest gracza
                            if(p.plansza[y+1][x+1]>0){
                                return true;
                            }
                        }
                    }
		                //bicie w lewo
                    if(k==x-2){
		                    //miejsce za bitym pionkiem wolne
                        if(p.plansza[l][k]==0){
			                       //bity jest pionek gracza
                            if(p.plansza[y+1][x-1]>0){
                                return true;
                            }
                        }
                    }
                }
            }
        }

	//analogicznie jak wyzej, tylko z perspektywy dolu planszy
        else if(gracz==1){
            if(p.plansza[y][x]==1){
                if(p.plansza[l][k]==0){
                    if(l==y-1){
                        if(k==x+1||k==x-1){
                            return true;
                        }
                    }
                    if(l==y-2){
                        if(k==x+2){
                            if(p.plansza[y-1][x+1]<0){
                                return true;
                            }
                        }
                        if(k==x-2){
                            if(p.plansza[y-1][x-1]<0){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////
bool warcaby::koniec_gry(warcaby p)
{
    int r = 0;
    int b = 0;
    for(int x = 0 ; x < 8 ; x++)
    {
        for(int y = 0 ; y < 8 ; y++)
        {
            if(p.plansza[y][x] > 0)
                r++;
            if(p.plansza[y][x] < 0)
                b++;
        }
    }
    if(r == 0 || b == 0)
    {
        if(r == 0)
        {
            cout << "Komputer wygral!" << endl;
        }
        else if(b == 0)
        {
            cout << "Gracz wygral!" << endl;
        }

        return true;
    }
    else
    {
        return false;
    }
}
////////////////////////////////////////////////////////////////////////////////
warcaby warcaby::wykonaj_ruch(const warcaby p, int gracz, int x, int y, int k, int l){

    warcaby ruch1;
    ruch1=p;
    /////////////RUCHY DAMKI ////////////////
    if(ruch1.plansza[y][x]==2 || ruch1.plansza[y][x]==-2){
      /////////// TURA GRASZA //////////////////////
        if(gracz==1){
            if(k>x && l<y){
                int temp=y-1;
                for(int i=x+1; i<=k; i++){
                    if(p.plansza[temp][i]!=0){
                        ruch1.plansza[temp][i]=0;
                    }
                    temp--;
                }
                ruch1.plansza[l][k]=2;
                ruch1.plansza[y][x]=0;
            }
            if(k>x && l>y){
                int temp=y+1;
                for(int i=x+1; i<=k; i++){
                    if(p.plansza[temp][i]!=0){
                        ruch1.plansza[temp][i]=0;
                    }
                    temp++;
                }
                ruch1.plansza[l][k]=2;
                ruch1.plansza[y][x]=0;
            }
            if(k<x && l<y){
                int temp=y-1;
                for(int i=x-1; i>=k; i--) {
                    if(p.plansza[temp][i]!=0){
                        ruch1.plansza[temp][i]=0;
                    }
                    temp--;
                }
                ruch1.plansza[l][k]=2;
                ruch1.plansza[y][x]=0;
            }
            if(k<x && l>y){
                int temp=y+1;
                for(int i=x-1; i>=k; i--){
                    if(p.plansza[temp][i]!=0){
                        ruch1.plansza[temp][i]=0;
                    }
                    temp++;
                }
                ruch1.plansza[l][k]=2;
                ruch1.plansza[y][x]=0;
            }
        }
        ///////////////////TURA KOMPUTERA ///////////////////
        if(gracz==-1){
            if(k>x && l<y){
                int temp=y-1;
                for(int i=x+1; i<=k; i++){
                    if(p.plansza[temp][i]!=0){
                        ruch1.plansza[temp][i]=0;
                    }
                    temp--;
                }
                ruch1.plansza[l][k]=-2;
                ruch1.plansza[y][x]=0;
            }
            if(k>x && l>y){
                int temp=y+1;
                for(int i=x+1; i<=k; i++){
                    if(p.plansza[temp][i]!=0){
		                    ruch1.plansza[temp][i]=0;
                    }
                    temp++;
                }
                ruch1.plansza[l][k]=-2;
                ruch1.plansza[y][x]=0;
            }
            if(k<x && l<y){
                int temp=y-1;
                for(int i=x-1; i>=k; i--){
                    if(p.plansza[temp][i]!=0){
		                    ruch1.plansza[temp][i]=0;
                    }
                    temp--;
                }
                ruch1.plansza[l][k]=-2;
                ruch1.plansza[y][x]=0;
            }
            if(k<x && l>y){
                int temp=y+1;
                for(int i=x-1; i>=k; i--)
                {
                    if(p.plansza[temp][i]!=0){
		                    ruch1.plansza[temp][i]=0;
                    }
                    temp++;
                }
                ruch1.plansza[l][k]=-2;
                ruch1.plansza[y][x]=0;
            }
        }
    }
    /////////////////// RUCHY PIONKA ////////////////////
    if(gracz==1 &&( (l==0) || (l==2) || (l==4) || (l==6))){
      ruch1.plansza[l][k]=2;
    }
    if(gracz==-1){
        if(p.plansza[y][x]==-1){
            if(l==y+1){
                if(k==x+1||k==x-1){
                    ruch1.plansza[l][k]=ruch1.plansza[y][x];
                    ruch1.plansza[y][x]=0;
                }
            }
            if(l==y+2){
                if(k==x+2){
                    if(ruch1.plansza[y+1][x+1]>0){
                        ruch1.plansza[y+1][x+1]=0;
                        ruch1.plansza[l][k]=ruch1.plansza[y][x];
                        ruch1.plansza[y][x]=0;
                    }
                }
                if(k==x-2){
                    if(p.plansza[y+1][x-1]>0){
                        ruch1.plansza[y+1][x-1]=0;
                        ruch1.plansza[l][k]=ruch1.plansza[y][x];
                        ruch1.plansza[y][x]=0;
                    }
                }
            }
        }
    }
    else if(gracz==1){
        if(p.plansza[y][x]==1){
            if(l==y-1){
                if(k==x+1||k==x-1){
                    ruch1.plansza[l][k]=ruch1.plansza[y][x];
                    ruch1.plansza[y][x]=0;
                }
            }
            if(l==y-2){
                if(k==x+2){
                    if(p.plansza[y-1][x+1]<0){
                        ruch1.plansza[y-1][x+1]=0;
                        ruch1.plansza[l][k]=p.plansza[y][x];
                        ruch1.plansza[y][x]=0;
                    }
                }
                if(k==x-2){
                    if(p.plansza[y-1][x-1]<0){
                        ruch1.plansza[y-1][x-1]=0;
                        ruch1.plansza[l][k]=ruch1.plansza[y][x];
                        ruch1.plansza[y][x]=0;
                    }
                }
            }
        }
    }
    if((l==0 || l==7)){
        if (gracz ==1){
            ruch1.plansza[l][k]=2;
        }
        else{
            ruch1.plansza[l][k]=-2;
        }
    }
    return ruch1;
}
////////////////////////////////////////////////////////////////////////////////
int warcaby::oplacalnosc_ruchu(warcaby p)
{
    int AI = 0,G = 0,x = 0;

    for(int i = 0 ; i < 8 ; i++)
    {
         switch(p.plansza[i][x])
         {
            case  0: break;
            case  1: G += 4;   break;
            case  2: G += 15;  break;
            case -1: AI += 4;  break;
            case -2: AI += 15; break;
          }
          if(i == 7 && x == 0)
          {
             i = 0;
             x = 7;
          }
    }
    x = 0;
    for(int i = 0 ; i < 8 ; i++)
    {
         switch(p.plansza[x][i])
         {
            case  0: break;
            case  1: G += 4;   break;
            case  2: G += 15;  break;
            case -1: AI += 4;  break;
            case -2: AI += 15; break;
         }
         if(i == 7 && x == 0)
         {
            i = 0;
            x = 7;
         }
    }
////////////////////////////////////////////////////////////
    x = 1;
    for(int i = 1 ; i < 7 ; i++)
    {
         switch(p.plansza[i][x])
         {
            case  0: break;
            case  1: G += 2;   break;
            case  2: G += 7;  break;
            case -1: AI += 2;  break;
            case -2: AI += 7; break;
          }
          if(i == 7 && x == 1)
          {
             i = 1;
             x = 6;
          }
    }
    x = 1;
    for(int i = 1 ; i < 7 ; i++)
    {
         switch(p.plansza[x][i])
         {
            case  0: break;
            case  1: G += 2;   break;
            case  2: G += 7;  break;
            case -1: AI += 2;  break;
            case -2: AI += 7; break;
         }
         if(i == 7 && x == 1)
         {
            i = 1;
            x = 6;
         }
    }
//////////////////////////////////////////////////////// 
    for(int i = 2 ; i < 6 ; i++)
    {
      for(int j = 2 ; j < 6 ; j++)
      {
           switch(p.plansza[j][i])
           {
              case  0: break;
              case  1: G += 1;  break;
              case  2: G += 3;  break;
              case -1: AI += 1; break;
              case -2: AI += 3; break;
           }
        }
    }

      AI = AI-G;
      return AI;
}
////////////////////////////////////////////////////////////////////////////////
int warcaby::minimax(warcaby w, int gracz, int glebokosc, ruch &wybor){
    if (glebokosc == 0){
      return oplacalnosc_ruchu(w);
    }

    int najlepszy;

    if (gracz == -1){
      najlepszy = INT_MIN;
    }
    else{
      najlepszy = INT_MAX;
    }

    ruch zestaw;

    for (int a = 0; a < 8; a++)
        for (int b = 0; b < 8; b++)
            for (int c = 0; c < 8; c++)
                for (int d = 0; d < 8; d++){
                    if (czy_mozna(w, gracz, a, b, c, d)){
                        warcaby temp;
                        temp=wykonaj_ruch(w, gracz, a,b,c,d);
                        int ocena = minimax(temp, -gracz, glebokosc-1, wybor);
                        if (gracz == -1){
                            if (ocena > najlepszy){
                                najlepszy = ocena;
                                zestaw.i=a;
                                zestaw.j=b;
                                zestaw.k=c;
                                zestaw.l=d;
                            }
                        }
                        else{
                            if (ocena < najlepszy){
                                najlepszy = ocena;
                                zestaw.i=a;
                                zestaw.j=b;
                                zestaw.k=c;
                                zestaw.l=d;
                            }
                        }
                    }
                }
    wybor=zestaw;
    return najlepszy;
}
////////////////////////////////////////////////////////////////////////////////
warcaby::ruch warcaby::ruch_komputera(warcaby w, int trudnosc){
    ruch x;
    minimax(w, -1, trudnosc, x);
    return x;
}
////////////////////////////////////////////////////////////////////////////////
warcaby::ruch warcaby::ruch_gracza(warcaby w){
  ruch r;
  cout<<"TWOJA KOLEJ ! "<<endl;
  int a=0,b=0,c=0,d=0;
  while(!czy_mozna(w,1,a,b,c,d)){
      cout<<"KTORYM PIONKIEM CHCESZ SIE RUSZYC (kolumna [space] wiersz)"<<endl;
      cin>>a;
      cin>>b;
      cout<<"GDZIE CHCESZ SIE NIM RUSZYC (kolumna [space] wiersz)"<<endl;
      cin>>c;
      cin>>d;

      if(a>=0 && a<=7){
	     if(b>=0 && b<=7){
	      if(c>=0 && c<=7){
	       if(d>=0 && d<=7){
	        if(czy_mozna(w,1,a,b,c,d)){
		          r.i=a;r.j=b;r.k=c;r.l=d;
		      }
          else{
		          cout<<"NIEPOPRAWNY RUCH, SPROBUJ PONOWNIE"<<endl;
		          continue;
		      }
        }
       }
      }
     }
  }
  return r;
}
////////////////////////////////////////////////////////////////////////////////
