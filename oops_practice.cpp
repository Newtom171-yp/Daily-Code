#include <iostream>
using namespace std;

class HERO
{
    // properties
    int health = 100;
    char level = 3;

public:
    HERO(){
        cout <<"Constructor Called"<<endl;
    }

    HERO(int health){
        cout<<"Value preset at this : "<<this<<endl;
        this->health = health;
    }

    void print(){
        cout<< this->health << " "<< this->level;
    }

    int gethealth()
    {
        return health;
    }

    int getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(int l)
    {
        level = l;
    }
};

int main()
{
    HERO Shaktiman;
    cout << "Health before setting: " << Shaktiman.gethealth() << endl;
    Shaktiman.sethealth(10);
    cout << "Health after setting: " << Shaktiman.gethealth() << endl;

    HERO *Nagraj = new HERO;
    cout << "Health before setting: " << Nagraj->gethealth() << endl;
    Nagraj->sethealth(101);
    cout << "Health after setting: " << (*Nagraj).gethealth() << endl;

    HERO Heman(11);
    cout<<"Address of Heman : "<<&Heman<<endl;
    cout<<"Health of Paramterized Heman : "<<Heman.gethealth()<<endl;
    Heman.print();


    HERO CopyHero(Heman);
    CopyHero.print();

    return 0;
}