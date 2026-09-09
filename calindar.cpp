//Implementação de calendário com data e hora, usando como base os exemplos de herança múltipla discutidos na aula. O programa deverá 
//ficar em laço infinito, atualizando a data e hora.
//Implémentation d'un calendrier avec date et heure, en s'appuyant sur les exemples d'héritage multiple abordés en cours. Le programme doit 
//rester dans une boucle infinie, en mettant à jour la date et l'heure.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Hour{ //namespace serait utile pour creer une fonction bissextile et override l'operateur == potentiellement meme 2 fois si on créait 2 namespaces
    private:
        int h; int m; int s; //ou? struct ClockTime { int hr; int min; int sec;};
    public:
        Hour(int _hour, int _min, int _sec): h(_hour), m(_min), s(_sec) {}; //pas de void devant le constructeur   //pas self.hour = _hour mais hour(_hour)
        int hour(){ return h;}
        int min(){ return m;}
        int sec(){ return s;}
        bool advanceH(); //void advance(){}; est faux
        void getTime() const{
            std::cout << "It`s: " << h << ":" << m << ":" << s << std::endl; //ou? ostream& operator<<(ostream& os, ClockTime t) { os << t.hr << ":" << t.min << ":" << t.sec; return os;} 
            //qui permet d utiliser std::cout << "Heure actuelle : " << now;
        }
};

bool Hour::advanceH(){
    s += 1;
    if (s==60){ m += 1, s = 0;}
    if (m==60){ h += 1, m = 0;}
    if (h==24){ h = 0; return false;}
    return true;
}


//________________________________________________________
class Day{
    private:
        int d; int m; int y;
    public:
        Day(int _day, int _month, int _year): d(_day), m(_month), y(_year) {};
        int day(){ return d;}
        int month(){ return m;}
        int year(){ return y;}
        void advanceD();
        void getDay() const{
            std::cout << "It`s: " << d << "/" << m << "/" << y << std::endl; 
        };
};

void Day::advanceD(){
    d += 1;
    if (d==30){ m += 1, d = 1;}
    if (m==12){ y += 1, m = 1;}
}


//________________________________________________________
class Calendar: public Hour, public Day{ //sans "public" getTime et getDay sont inacessibles
    public:
        //Calendar(Hour& _hour, Day& _day);
        Calendar(int h, int m, int s, int d, int mo, int y): Hour(h, m, s), Day(d, mo, y) {}
        void getCalendar() const{
            getTime();
            getDay();
        }
        void advance(){
            if (!advanceH()) {
                advanceD();
                getDay();
            }
            getTime();
        }
};

int main(){
    //Hour heureJ(18, 4, 5); //Day jourJ(8, 9, 2026); //Calendar now(heureJ, jourJ); // Le '&' ici est l'opérateur "Adresse-de". // '&heureJ' produit un POINTEUR (Hour*), pas une référence."""
    Calendar now(18, 4, 56, 8, 9, 2026);
    while (1){
        now.advance();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}

