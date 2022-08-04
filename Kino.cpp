#include "Sala.h"
#include <vector>
#include "Kino.h"
#include <iostream>
using namespace std;
Sala* Male_kino::czy_graja(Film* f, int miejsca){
    Sala* sal;
    if(s.get_adres_f()==f  &&  s.get_ilosc_wolnych()>=miejsca) {sal=&s;} //sprawdzamy czy to sala z naszym filmem i odpowiednia iloscia miejsc
    else{
       sal=nullptr;
    }
    return sal;

}

void Male_kino::losuj_film() {
    s.losuj_film();
}

void Male_kino::uzupelnij_statystyki_sal() {
    s.uzupelnij_statystyke_filmu();
}

void Male_kino::drukuj_statystyki_kin() {
    cout<<this->nazwa<<"\n W tym kinie bylo: "<<s.zapelnienie_sali()<<" osob \n Grany byl film: ";
    (s.get_adres_f())->drukuj_tytul();
}

void Male_kino::oczysc_sale() {
    s.wyczysc_sale();
    jaki_dzis.clear();
}

void Male_kino::drukuj_koncowe_statystyki() {
     cout<<"\nPodczas symulacji w kinie "<<this->nazwa<< " bylo "<< s.get_ilosc_widzow_ogolem()<<" widzow\n";
}

Sala* Multipleks::czy_graja(Film* f, int miejsca){
    Sala* sal;
    for(Sala* s:wektor_sal){
        if(s->get_adres_f()==f && s->get_ilosc_wolnych()>=miejsca) {
            sal=s;
            return sal;
        }
    }
    sal=nullptr;
    return sal;
}

void Multipleks::losuj_film() {
    for(Sala*s: wektor_sal){
        s->losuj_film();
    }
}

void Multipleks::uzupelnij_statystyki_sal() {
    for(Sala*s: wektor_sal){
        s->uzupelnij_statystyke_filmu();
    }
}

void Multipleks::drukuj_statystyki_kin() {
    int i=0;
    int n=0;
    for(Sala*s: wektor_sal){
        cout<<this->nazwa<<"\n Liczba osob w sali nr "<<i<<": "<<s->zapelnienie_sali()<<"\n Film pod tytulem: ";
        (s->get_adres_f())->drukuj_tytul();
        n+=s->zapelnienie_sali();
        i++;
    }
    cout<<"\nW sumie w tym kinie bylo "<<n<<" osob. \nOdbyly sie seanse filmow: \n";
    for (Film* f: jaki_dzis){
        f->drukuj_tytul();

    }
    cout<<"\n";
}

void Multipleks::oczysc_sale() {
    for(Sala*s: wektor_sal){
        s->wyczysc_sale();
    }
    jaki_dzis.clear();
}

void Multipleks::drukuj_koncowe_statystyki() {
    int lacznie=0;
    int i=1;
    cout<<"\n"<<this->nazwa<<"\n";
    for(Sala* s: wektor_sal){
        lacznie+=s->get_ilosc_widzow_ogolem();
        cout<< "Podczas symulacji w sali nr "<<i<<" bylo "<<s->get_ilosc_widzow_ogolem()<<" osob\n";
        i++;
    }
    cout<<"\nPodczas symulacji w kinie "<<this->nazwa<< " bylo lacznie "<< lacznie<<" widzow\n";
}
