#include <iostream>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib>
#include "Miasto.h"
#include "Kino.h"
#include "Mieszkaniec.h"
#include "Sala.h"
#include "Film.h"

using namespace std;
string nazwa_miasta = "Miasto";
int l_filmow = 10;
int l_malych_kin = 4;
int l_multipleksow = 2;
int l_koneserow = 20;
int l_kinomanow = 10;
int l_okazjonalnych = 400;

int liczba_dni = 7;
int main()
{
    srand(100);
    Miasto m(nazwa_miasta,l_filmow,l_malych_kin,l_multipleksow,l_koneserow,l_kinomanow,l_okazjonalnych);
    m.symulacja(liczba_dni);
    m.wypisz_statystyki();
    return 0;
}
