#include <iostream>
#include <cstring>
using namespace std;

class Hero
{
public:
    int health;
    char *name;
    Hero()
    {
        name = new char[100];
    }

    Hero(Hero &copy)
    {
        char *ch = new char[strlen(copy.name) + 1];
        strcpy(ch, copy.name);
        this->name = ch;
        this->health = copy.health;
    }

    void print()
    {
        cout << endl
             << "[ " << this->name << " " << this->health << " ]" << endl;
    }
};

int main()
{

    Hero h1;
    h1.health = 100;
    char name[7] = "Babbar";
    h1.name = name;
    h1.print();
    Hero h2(h1);
    h1.name[0] = 'G';
    h1.print();
    h2.print();

    h1 = h2;
    h1.print();
    h2.print();

    return 0;
}