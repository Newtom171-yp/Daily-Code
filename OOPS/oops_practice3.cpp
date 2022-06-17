#include <iostream>
#include <cstring>
using namespace std;

class Human
{
    int age = 100;

public:
    string name = "Hakunamatata";

    void charateristics()
    {
        cout << age << " " << name << endl;
    }
};

class Male : public Human
{

public:
    Male()
    {
        cout << endl << "I have a beard";
    }
};

class Female : public Human 
{
    public:
    Female()
    {
        cout << endl << "I have long hair";
    }
};

class Boy : public Male
{
public:
    Boy()
    {
        cout << endl << "I am also very young" << endl;
    }
};

class Trans : public Male, public Female
{
    public:
    Trans()
    {
        cout<< endl << "Hence, I am a trans" << endl;
    }
};

int main()
{

    Human h;
    h.charateristics();

    Male m;

    Boy b;

    Trans t;
}