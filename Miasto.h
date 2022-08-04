#ifndef MIASTO_H
#define MIASTO_H

#include "Sala.h"
#include <vector>
#include "Mieszkaniec.h"
#include "Kino.h"
using namespace std;
class Mieszkaniec;
class Miasto {
        string nazwa;
        vector<Kino*> wektor_kin;
        vector<Mieszkaniec*> wektor_mieszkancow;
        vector<Film*> wektor_filmow;
    public:
        // techniczne
        Miasto() = delete;
        Miasto(string _nazwa,int l_filmow,int l_malych_kin,int l_multipleksow,int l_koneserow,int l_kinomanow,int l_okazjonalnych);
        Miasto(const Miasto& m) = delete;
        Miasto& operator=(const Miasto& m) = delete;
        ~Miasto();

        int ile_filmow();
        Film* adres_f(int);
        void symulacja(int liczba_dni);
        void wypisz_statystyki();
        void dzien(int nr_dnia);
        const vector<Kino*>& get_kina() const{
            return wektor_kin;
        };
};
#endif //MIASTO_H
