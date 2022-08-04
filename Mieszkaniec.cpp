
#include "Mieszkaniec.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void Mieszkaniec::zajmij_miejsce(Sala& s) {
    if (s.get_ilosc_wolnych() == 0)
        cout << "Brak wolnych miejsc \n";
    else {
        s.set_ilosc_wolnych(s.get_ilosc_wolnych()-1);
    }
}

int *Mieszkaniec::get_tab() {
    return tab;
}


int Koneser::ocena() {
    //koneser ocenia od 1 do 7
    return (int) rand() % 7 + 1;
}

bool Koneser::czy_ide() {
    return true;//przyjmujemy, ze koneser chodzi do kina codziennie
}

Film *Koneser::znajdz_najlepszy() {
    set<Film*> filmy_w_miescie;
    for(Kino *k: moje_miasto->get_kina()){
        filmy_w_miescie.insert(k->get_filmy().begin(),k->get_filmy().end());
    }//robimy caly zbior filmow granych w miescie
    Film* naj= *(filmy_w_miescie.begin());
    for (Film *z: filmy_w_miescie) {
        if (naj->srednia_ocen() < z->srednia_ocen()) {
            naj = z;
        };
    }
    return naj;
}

pair<Sala *, Kino *> Koneser::seans_w_kinie() {
    //koneser najpierw wybiera film z najwyższa ocena
    pair<Sala *, Kino *> gdzie;
    Film *naj = znajdz_najlepszy();
    const vector<Kino *> &a = moje_miasto->get_kina();
    //chodzimy po wektorze kin
    for (Kino *k: a) {
        if (k->czy_graja(naj,1) != nullptr) {
            gdzie.second = k;
            gdzie.first = k->czy_graja(naj,1);
            zajmij_miejsce(*(gdzie.first));
            tab[0]++;
            naj->dodaj_ocene(ocena());
            return gdzie;
        }
    }
    gdzie.first = nullptr;
    gdzie.second = nullptr;
    return gdzie;
}


int Kinoman::ocena() {
    //kinoman ocenia od 5 do 10
    return rand() % 6 + 5;
}

bool Kinoman::czy_ide() {
    if (dzien_rozpoczecia%3 == 1) {
        dzien_rozpoczecia++;
        return true;
    } else {
        dzien_rozpoczecia++;
        return false;
    }
}

void Kinoman::zajmij_miejsce(Sala& s) {
    if (s.get_ilosc_wolnych() >= liczba_osob) {
        s.set_ilosc_wolnych(s.get_ilosc_wolnych()-liczba_osob);
    }
}


pair<Sala *, Kino *> Kinoman::seans_w_kinie() {
    pair<Sala *, Kino *> gdzie;
    if (czy_ide()) {
        liczba_osob =1+ rand()% 7;//kinoman losuje liczbe znajomych, z ktorymi pojdzie do kiena
        //kinoman najpierw losuje kino
        const vector<Kino *> &a = moje_miasto->get_kina();
        gdzie.second = a.at(rand() % (a.size()));
        //teraz losujemy film z tego kina
        Film *fil;
        Sala *sal;
        int n = rand() % (gdzie.second->get_filmy().size());
        int i = 0;
        for (Film *z: gdzie.second->get_filmy()) {
            if (i == n) {
                fil = z;
                break;
            } else i++;
        };
        //teraz mamy film i trzeba zobaczyc w ktorej sali jest grany
        sal = gdzie.second->czy_graja(fil, liczba_osob);
        if (sal != nullptr) {
            gdzie.first = sal;
            zajmij_miejsce(*(gdzie.first));
            tab[1]+=liczba_osob;
            fil->dodaj_ocene(ocena());
            return gdzie;
        } else {
            return {nullptr, nullptr};
        }
    } else {
        return {nullptr, nullptr};
    }
}

int Okazjonalny::ocena(){
    return rand()%10 + 1;
}
bool Okazjonalny::czy_ide(){
    if(rand()%50==37)
        return true;
    else return false;
}

pair<Sala *, Kino *> Okazjonalny::seans_w_kinie() {
    pair<Sala *, Kino *> gdzie;
    if (czy_ide()) {
        const vector<Kino *> &a = moje_miasto->get_kina();
        gdzie.second=a.at(rand()%(a.size()));//losujemy kino
        Film *b;
        int n = rand() % (gdzie.second->get_filmy().size());
        int i = 0;
        for (Film *z: gdzie.second->get_filmy()) {
            if (i == n) {
                b = z;
                break;
            } else i++;
        }
        Sala *p = gdzie.second->czy_graja(b,1);
        gdzie.first = p;
        if(p!= nullptr) {
            zajmij_miejsce(*(gdzie.first));
            tab[2]++;
            b->dodaj_ocene(ocena());
            return gdzie;
        }
        else{
            return{nullptr, nullptr};
        }
    }
    else{
        return {nullptr, nullptr};
    }
}
