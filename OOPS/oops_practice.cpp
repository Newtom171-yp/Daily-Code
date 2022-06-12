#include <iostream>
using namespace std;

class Hero{
    public:
    int health;
    char level;
    char* name = new char[100];

    void print(){
        cout<<endl<<"[ "<<this->health<<" "<<this->level<<" "<<this->name<<" ]"<<endl;
    }

    Hero(int health, char level, char name[]){
        this->health = health;
        this->level = level;
        this->name = name;
    }
    
};

int main(){

    Hero h1(100,'A',"Heman");
    h1.print();

    Hero *h2(&h1);
    h2->print();

    h1.name[0] = 'L';
    cout<<endl<<h1.name<<endl;
    h2->print();

    return 0;
}