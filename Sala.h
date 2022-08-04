#ifndef SALA_H
#define SALA_H

#include "Film.h"

class Miasto;
class Kino;
class Sala{
    Miasto* Moje_miasto;
    Kino* Moje_kino;
    int liczba_miejsc;
    int ilosc_wolnych;
    int liczba_filmow;
    int ilosc_widzow_ogolem=0;
    Film* adres_filmu;
public:
    // techniczne
    Sala(int _liczba_miejsc, Miasto* _m, Kino* _k);
    Sala(const Sala& s) = delete;
    Sala& operator=(const Sala& s) = delete;
    ~Sala() {};

    int get_ilosc_wolnych();
    void set_ilosc_wolnych(int);
    Film* get_adres_f();
    void losuj_film();
    void uzupelnij_statystyke_filmu();
    void wyczysc_sale();
    int zapelnienie_sali();
    int get_ilosc_widzow_ogolem(){return ilosc_widzow_ogolem;};
};


#endif //SALA_H
