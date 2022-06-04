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
    return 0;
}