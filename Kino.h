#ifndef KINO_H
#define KINO_H

#include <string>
#include "Miasto.h"
#include "Film.h"
#include "Sala.h"
#include <set>
using namespace std;
class Kino {
protected:
    Miasto* moje_miasto;
    string adres;
    string nazwa;
    set<Film*> jaki_dzis;
public:
    // techniczne
    Kino(Miasto*_m, string _adres, string _nazwa): moje_miasto(_m),  adres(_adres), nazwa(_nazwa){};
    Kino(const Kino& k) = delete;
    Kino& operator=(const Kino& k) = delete;
    virtual ~Kino(){};

    virtual Sala* czy_graja(Film* f, int miejsca)=0;
    set<Film*>& get_filmy(){
        return jaki_dzis;
    };
    virtual void drukuj_koncowe_statystyki()=0;
    virtual void oczysc_sale()=0;
    virtual void drukuj_statystyki_kin()=0;
    virtual void losuj_film()=0;
    virtual void uzupelnij_statystyki_sal()=0;
};

class Male_kino: public Kino{
    Sala s;
    int ilosc_miejsc_w_sali;

public:
    // techniczne
    Male_kino(string _adres, string _nazwa, int _ilosc_miejsc_w_sali, Miasto* _m): Kino( _m, _adres, _nazwa), s(_ilosc_miejsc_w_sali,_m,this), ilosc_miejsc_w_sali(_ilosc_miejsc_w_sali)  {}
    Male_kino(const Male_kino& k) = delete;
    Male_kino& operator=(const Male_kino& k) = delete;
    ~Male_kino()=default;

    void drukuj_koncowe_statystyki() override;
    void oczysc_sale() override;
    void drukuj_statystyki_kin() override;
    void uzupelnij_statystyki_sal() override;
    void losuj_film() override;
    Sala* czy_graja(Film* f, int miejsca) override;
};
class Multipleks: public Kino{
    int ilosc_sal;
    vector<Sala*> wektor_sal;
public:
    // techniczne
    Multipleks(string _adres, string _nazwa,const vector<int>& _wektor_miejsc_w_salach, Miasto* _m): Kino( _m, _adres, _nazwa) {
        ilosc_sal=_wektor_miejsc_w_salach.size();
        //wektor_sal
        for (int i=0; i< ilosc_sal; i++)
            wektor_sal.push_back(new Sala(_wektor_miejsc_w_salach[i],_m, this));
    };
    Multipleks(const Multipleks& m) = delete;
    Multipleks& operator=(const Multipleks& m) = delete;
    ~Multipleks(){
        for(Sala*s: wektor_sal)
            delete s;
    };

    Sala* czy_graja(Film* f, int miejsca) override;
    void losuj_film() override;
    void drukuj_koncowe_statystyki() override;
    void oczysc_sale() override;
    void drukuj_statystyki_kin() override;
    void uzupelnij_statystyki_sal() override;

    const vector<Sala*>& get_wektor_sal() {
        return wektor_sal;
    }
};


#endif //KINO_H
