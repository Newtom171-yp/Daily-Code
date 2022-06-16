#include <iostream>
using namespace std;

class Hero{
    public:

    static int gameTime;

    static int returnTime(){
        return gameTime;
    }

    ~Hero(){
        cout<<"Destructor called"<<endl;
    }

};

int Hero :: gameTime = 100;

int main(){

    Hero h1;

    Hero* h2 = new Hero();
    delete h2;

    cout<<Hero :: gameTime << " " << Hero :: returnTime()<<endl;

    return 0;
}