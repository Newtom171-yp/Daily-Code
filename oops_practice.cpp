#include <iostream>
#include <cstring>
using namespace std;

class HERO
{
    // properties
    int health = 100;
    char level = 'A';

public:
    char* name;
    HERO(){
        cout <<"Constructor Called"<<endl;
        name = new char[100];
    }

    HERO(HERO& copy){
        cout << "Copy constructor called: "<<endl;
        char *temp = new char[strlen(copy.name)+1];
        strcpy(this->name, temp);
        this->health = copy.health;
        this->level = copy.level;
    }

    HERO(int health){
        cout<<"Value preset at this : "<<this<<endl;
        this->health = health;
    }

    void print(){
        cout<< this->health << " "<< this->level <<" "<<this->name<<endl;
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
    void setName(char name[]){
        strcpy(this->name, name);
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
    char name[6]="Heman";
    Heman.setName(name);
    HERO CopyHero(Heman);
    Heman.name[0]='G';
    Heman.print();
    CopyHero.print();
    return 0;
}