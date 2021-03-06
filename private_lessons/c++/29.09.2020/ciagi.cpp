#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool check_ciag(int*tab, int r) //sprawdza czy ciag jest arytmetyczny
{
    int roznica = tab[1] - tab[0];
    for(int i=1; i<=r-2; i++){
        if(tab[i+1] - tab[i] != roznica) return false;
    }
    return true;
}

int check_szescian(int*tab, int r)
{
    for(int i=r-1; i>=0; i--){
        for(int j=1; j<=100; j++){
            if(j*j*j==tab[i])
            return tab[i];
        }
    }
    return 0;
}

int check_wrong(int*tab, int r)
{
	if(tab[r-1]-tab[r-2] != tab[r-2]-tab[r-3] && tab[r-2]-tab[r-3]==tab[r-3]-tab[r-4]){
		return tab[r-1];
	}
	if(tab[r-1]-tab[r-2] != tab[r-3]-tab[r-4] && tab[r-2]-tab[r-3] != tab[r-3]-tab[r-4] && tab[r-3]-tab[r-4] == tab[r-4]-tab[r-5]){
		return tab[r-2];
	}

	for(int i=r-1; i>=1; i--){
		if(tab[i]-tab[i-1] != tab[i-1]-tab[i-2]){
		return tab[i-2];}
	}
}

int main()
{
    fstream in,in3,out,out2,out3;
    in.open("ciagi.txt",ios::in);
    in3.open("bledne.txt",ios::in);
    out.open("wynik1.txt",ios::out);
    out2.open("wynik2.txt",ios::out);
    out3.open("wynik3.txt",ios::out);

    int r, licz=0, maxi=0;
    vector<int> v;

    if(in.good()){
        for(int i=0; i<100; i++){
            in>>r;
            int *tab = new int[r]; //tablica dynamiczna

            for(int j=0; j<r; j++){
                in>>tab[j];         //wczytujemy wartosci do tablicy
            }

            licz+=check_ciag(tab, r);
            if(check_ciag(tab, r)){ //sprawdzanie najwiekszej roznicy
                if(tab[1]-tab[0]>maxi)
                maxi=tab[1]-tab[0];
            }

            //-------------------------------------------------------------------------

            if(check_szescian(tab, r) != 0){
                v.push_back(check_szescian(tab, r));
            }

            delete []tab; //zwolnienie pamiĂŞci
        }
    } else cout<<"ERROR - BLAD ODCZYTU";

    out<<"Zadanie 1"<<endl;
    out<<"Liczba ciagow arytmetycznych: "<<licz<<endl;
    out<<"Najwieksza roznica: "<<maxi<<endl<<endl;

    out2<<"Zadanie 2"<<endl;
    for(int i=0; i<v.size(); i++) out2<<v[i]<<endl;

    //-------ZADANIE_3----------------------------------------------------------------

	 out3<<"Zadanie 3"<<endl;

        if(in3.good()){
        cout<<"OK"<<endl;
        for(int i=0; i<20; i++){
            in3>>r;
            int *tab = new int[r]; //tablica dynamiczna

            for(int j=0; j<r; j++){
                in3>>tab[j];        //wczytujemy wartosci do tablicy
            }

            out3<<check_wrong(tab, r)<<endl;

            delete []tab; //zwolnienie pamieci
        }
    } else cout<<"ERROR - BLAD ODCZYTU";

    return 0;
}
