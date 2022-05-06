#include <iostream>
#include <string>
using namespace std;

string Reverse(string& s, int l, int r){
    if(l > r) return s;
    swap(s[l],s[r]);
    return Reverse(s, l, s.length()-1-(++l));
}

int main(){

    string str;
    getline(cin, str);
    cout << Reverse(str, 0, str.length()-1);

    return 0;
}