#ifndef MIESZKANIEC_H
#define MIESZKANIEC_H

#include "Sala.h"
#include <vector>
#include "Kino.h"
#include "Miasto.h"
using namespace std;
class Mieszkaniec{
protected:
    Miasto* moje_miasto;
    int tab[3]={0,0,0};//ilosc kupionych biletow: koneser - tab[0], kinoman - tab[1], okazjonalny - tab[2]
public:
    // techniczne
    Mieszkaniec() = delete;
    Mieszkaniec(Miasto* _m): moje_miasto(_m){}
    Mieszkaniec(const Mieszkaniec& m) = delete;
    Mieszkaniec& operator=(const Mieszkaniec& m) = delete;
    virtual ~Mieszkaniec(){};

    int* get_tab();
    virtual int ocena() = 0;
    virtual bool czy_ide() = 0;
    virtual pair<Sala*, Kino*> seans_w_kinie()=0;
    virtual void zajmij_miejsce(Sala& s);
};
class Koneser: public Mieszkaniec {
public:
    //techniczne
    Koneser() = delete;
    Koneser(Miasto* _m): Mieszkaniec(_m) {};
    Koneser(const Koneser& k) = delete;
    Koneser& operator=(const Koneser& k) = delete;
    ~Koneser()=default;

    int ocena() override;
    Film* znajdz_najlepszy();
    bool czy_ide() override;
    pair <Sala*, Kino*> seans_w_kinie() override;
};
class Kinoman: public Mieszkaniec {
    int dzien_rozpoczecia=rand()%3 + 1;
    int liczba_osob=1;
public:
    //techniczne
    Kinoman() = delete;
    Kinoman(Miasto* _m): Mieszkaniec(_m) {}
    Kinoman(const Kinoman& k) = delete;
    Kinoman& operator=(const Kinoman& k) = delete;
    ~Kinoman()=default;

    int ocena() override;
    bool czy_ide() override;
    void zajmij_miejsce(Sala& s) override;
    pair <Sala*, Kino*> seans_w_kinie() override;
};
class Okazjonalny: public Mieszkaniec {
public:
    //techniczne
    Okazjonalny() = delete;
    Okazjonalny(Miasto* _m): Mieszkaniec(_m) {};
    Okazjonalny(const Okazjonalny& m) = delete;
    Okazjonalny& operator=(const Okazjonalny& m) = delete;
    ~Okazjonalny()=default;

    int ocena() override;
    bool czy_ide() override;
    pair <Sala*, Kino*> seans_w_kinie() override;
};

#endif //MIESZKANIEC_H
