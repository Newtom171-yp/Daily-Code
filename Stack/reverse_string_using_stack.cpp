#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "My name is Yash Patil";
    stack<char>s;
    for(int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    str = "";
    while(!s.empty())
    {
        str.push_back(s.top());
        s.pop();
    }

    cout<<str<<endl;
    return 0;
}