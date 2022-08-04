#ifndef FILM_H
#define FILM_H

#include <string>
using namespace std;

class Film {
    string tytul;
    int ilosc_widzow=0;
    int suma_ocen=5;//ZAKRES [1,10]
    int ilosc_ocen=1;
public:
    // techniczne
    Film() = default;
    Film(string _tytul): tytul(_tytul) {}
    Film(const Film& f) = delete;
    Film& operator=(const Film& f) = delete;
    ~Film()=default;

    void drukuj_tytul();
    void drukuj_ocene();
    void dodaj_widzow(int l);
    void dodaj_ocene(int ocena);
    double srednia_ocen();
    int get_ilosc_widzow(){ return ilosc_widzow;};
};


#endif //FILM_H
