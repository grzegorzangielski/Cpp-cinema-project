#include <set>
#include <cstdlib>
#include "Sala.h"
#include "Miasto.h"
#include "Film.h"
#include "Kino.h"
using namespace std;
Sala::Sala (int _liczba_miejsc, Miasto* _m, Kino* _k):  Moje_miasto(_m), Moje_kino(_k), liczba_miejsc(_liczba_miejsc){
    ilosc_wolnych= _liczba_miejsc;
    liczba_filmow=(Moje_miasto-> ile_filmow());
}

void Sala::set_ilosc_wolnych(int i){
    ilosc_wolnych = i;
}
int Sala::get_ilosc_wolnych(){
    return ilosc_wolnych;
}
Film* Sala::get_adres_f(){
    return adres_filmu;
}
void Sala::losuj_film(){
    int i= rand()%(liczba_filmow);//...losuje liczbe z przedzialu od 0 do liczby filmow
    adres_filmu=Moje_miasto->adres_f(i);
    set<Film*>& s=Moje_kino->get_filmy();
    s.insert(adres_filmu);
}

void Sala::uzupelnij_statystyke_filmu() {
    adres_filmu->dodaj_widzow(zapelnienie_sali());
    ilosc_widzow_ogolem+=zapelnienie_sali();
}

void Sala::wyczysc_sale() {
    ilosc_wolnych=liczba_miejsc;
}

int Sala::zapelnienie_sali() {
    return liczba_miejsc-ilosc_wolnych;
}


