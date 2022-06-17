#include <iostream>
using namespace std;

class Overload{

    public:
    int variable;

    int operator+(Overload &obj)
    {
        return this->variable - obj.variable;
    }

    int operator+(int b)
    {
        return this->variable - b;
    }
};

int main(){
    Overload a;
    a.variable = 10;

    Overload b;
    b.variable = 5;

    cout<< endl << a+b << endl;
    cout << endl << a+6 << endl;
}