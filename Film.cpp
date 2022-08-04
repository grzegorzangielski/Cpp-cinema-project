#include "Film.h"
#include <iostream>
#include <iomanip>

double Film::srednia_ocen() {
    return (double)suma_ocen/ilosc_ocen;
}
void Film::dodaj_widzow(int l) {
    ilosc_widzow+=l;
}

void Film::dodaj_ocene(int ocena){
    suma_ocen+=ocena;
    ilosc_ocen++;
}

void Film::drukuj_ocene() {
    cout<<tytul<<"\nSrednia ocen: "<<setprecision(2)<<fixed<<srednia_ocen()<<"\nIlosc widzow: "<<ilosc_widzow<<"\n\n";
}

void Film::drukuj_tytul() {
    cout<<tytul<<"\n";
}


