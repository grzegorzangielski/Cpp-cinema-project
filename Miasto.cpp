#include "Sala.h"
#include <vector>
#include "Mieszkaniec.h"
#include "Kino.h"
#include "Film.h"
#include <iostream>
#include <random>
#include <algorithm>
#include "Miasto.h"

using namespace std;

Miasto::Miasto(string _nazwa,int l_filmow, int l_malych_kin, int l_multipleksow, int l_koneserow, int l_kinomanow, int l_okazjonalnych) {
    nazwa = _nazwa;
    //tworze filmy
    for (int i = 1; i <= l_filmow; i++)
        wektor_filmow.push_back(new Film("Tytul " + to_string(i)));
    //tworze Kina
    for (int i = 1; i <= l_malych_kin; i++) {
        wektor_kin.push_back(new Male_kino("Ulica " + to_string(i), "Male kino " + to_string(i), rand() % 20 + 20, this));
    }
    for (int i = 1; i <= l_multipleksow; i++) {
        vector<int> wektor;
        int k=rand()%5 +2;//losuje ilosc sal w kinie (max 6)
        wektor.reserve(k);//Jesli z gory wiadomo, ze wektor bedzie mial k elementow to dobrze jest zarezerwowac k miejsc, gdyz jest to mniej kosztowne przy k*operacja"push_back"
        for(int i=0; i<k; i++){
            wektor.push_back(rand()%20 +40); //losuje ilosc miejsc w salach
        }
        wektor_kin.push_back(new Multipleks("Ulica " + to_string(i), "Multipleks " + to_string(i), wektor, this));
    }
    //tworze mieszkancow
    for (int i = 0; i < l_koneserow; i++) {
        wektor_mieszkancow.push_back(new Koneser(this));
    }
    for (int i = 0; i < l_kinomanow; i++) {
        wektor_mieszkancow.push_back(new Kinoman(this));
    }
    for (int i = 0; i < l_okazjonalnych; i++) {
        wektor_mieszkancow.push_back(new Okazjonalny(this));
    }
}

Miasto::~Miasto() {
    for (Film *f: wektor_filmow)
        delete f;
    for (Kino *k: wektor_kin)
        delete k;
    for (Mieszkaniec *c: wektor_mieszkancow)
        delete c;

}

Film* Miasto::adres_f(int i){
    return wektor_filmow[i];
}

int Miasto::ile_filmow(){
    return wektor_filmow.size();
}

void Miasto::dzien(int nr_dnia) {
    //Kazdy dzien zaczynam od mieszania wektorow mieszkancow, kin, filmow zeby bylo bardziej realistycznie

    shuffle(begin(wektor_mieszkancow), end(wektor_mieszkancow), default_random_engine());
    shuffle(begin(wektor_kin), end(wektor_kin), default_random_engine());
    shuffle(begin(wektor_filmow), end(wektor_filmow), default_random_engine());

    cout << "Dzien " << nr_dnia << "\n\n";
    for (Kino *k: wektor_kin) {
        k->losuj_film();
    }
    for (Mieszkaniec *m: wektor_mieszkancow) {
        m->seans_w_kinie();
    }
    for (Kino *k: wektor_kin) {
        k->uzupelnij_statystyki_sal();
        k->drukuj_statystyki_kin();
        k->oczysc_sale();
    }
}

void Miasto::symulacja(int liczba_dni) {
    for (int k = 1; k <= liczba_dni; k++)
        dzien(k);

}

void Miasto::wypisz_statystyki() {
    cout << "\n########## PODSUMOWANIE ##########\n\n";
    for (Film *f: wektor_filmow) {
        f->drukuj_ocene();
    }
    for (Kino *k: wektor_kin) {
        k->drukuj_koncowe_statystyki();
    }
    int koneserzy = 0;
    int kinomani = 0;
    int okazjonalni = 0;
    for (Mieszkaniec *m: wektor_mieszkancow) {
        koneserzy += (m->get_tab())[0];
        kinomani += (m->get_tab())[1];
        okazjonalni += (m->get_tab())[2];
    }
    cout <<"\nPodczas symulacji:\nKoneserzy kupili "<< koneserzy << " biletow\nKinomani kupili " << kinomani << " biletow\nWidzowie okazjonalni kupili " << okazjonalni<<" biletow\n";
}


