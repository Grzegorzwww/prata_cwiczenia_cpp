#include <iostream>
#include <ctime>
#include <cstdlib>
#include "complex0.h" 		// to avoid confusion with complex.h
#include "mystring.h"
#include "queue.h"
#include "valarray"
#include "string"

using namespace std;


class Person
{

private:
    string first_name;
    string second_name;
public:

    Person();
    virtual ~Person() {}
    Person(string fn, string sn);
    virtual void Show();

};

Person::Person() : first_name("brak"), second_name("brak")
{
}
Person::Person(string fn, string sn) : first_name(fn), second_name(sn)
{
}

void  Person::Show()
{
    cout << "Imie = " << first_name << endl;
    cout << "Imie = " << second_name << endl;
}

class Gunslinger: public Person
{
private:

    double show_gun_time;
    int incisions;

public:
    Gunslinger(string fn, string sn, double x, int in);
    Gunslinger(Person per, double x, int in);
    Gunslinger(double x, int in);
    Gunslinger();
    virtual ~Gunslinger(){}
    virtual double Draw() {return show_gun_time;}
    virtual void Show();

};


Gunslinger::Gunslinger(string fn, string sn, double x = 0, int in = 0): Person(fn, sn), show_gun_time(x), incisions(in) {}
Gunslinger::Gunslinger(Person per, double x = 0, int in = 0): Person(per), show_gun_time(x), incisions(in) {}
Gunslinger::Gunslinger( double x = 0, int in = 0): Person("brak", "brak"), show_gun_time(x), incisions(in) {}

void  Gunslinger::Show(){
    Person::Show();
    cout << "Czas wyciagniecia rewolweru = "<< show_gun_time<< endl;
    cout << "Liczba naciec = "<< incisions<< endl;
}


class Card
{
private:
    int card_color;
    int rand_card_number;

public:
    Card(int kol = 0, int num = 0) {card_color = kol, rand_card_number = 0;}
    ~Card() {}
    void setKolor(int x) {card_color = x;}
    void setNumber(int  x) {rand_card_number= x;}

};


class PokerPlayer:  public virtual Person
{

private:
    Card karta;

public:
    PokerPlayer(Person per, Card &karta);
    PokerPlayer(string fn, string );
    PokerPlayer(Person &per);

    PokerPlayer( );
    virtual Card & Draw();
};

 PokerPlayer::PokerPlayer(string fn, string sn): Person(fn, sn), karta(0, 0)
 {
 }

PokerPlayer::PokerPlayer(Person per, Card &karta): Person(per), karta(karta)
{
}
PokerPlayer::PokerPlayer(Person &per): Person(per)
{
}


Card & PokerPlayer::Draw() {
     srand ( time(NULL) );
    karta.setNumber(rand() % 52 + 1);

    return karta;
}


class BadDude: public Gunslinger, public PokerPlayer
{

private:


public:

    BadDude(Person &per, double  show_gun, int insc );
    ~BadDude() {}

    void Graw();
    void Cdraw();
    void Show();


};

/*BadDude::BadDude(Gunslinger &gl, PokerPlayer &pp) : Gunslinger(Person("brak", "brak")), PokerPlayer(Person("brak", "brak"),Card()))
{

}*/

BadDude::BadDude(Person &per, double  show_gun, int insc ) : Gunslinger(per, show_gun, insc), PokerPlayer(per)
{


}

void BadDude::Graw(){
}
    void BadDude::Cdraw(){
    }
    void BadDude::Show() {
    }



int main ()
{
    Person x("Grzegorz", "Warchol");
    PokerPlayer poker_player(x);
    poker_player.Show();



}
