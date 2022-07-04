#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <int> s;
    s.push(8);
    s.push(109);
    s.push(10);
    s.pop();
    cout<<"The top element of the stack is : "<<s.top()<<endl;
    (s.empty()) ? cout<<"The stack is empty"<<endl : cout<<"The stack is not empty"<<endl;
    cout<<"The size of the stack is: "<<s.size()<<endl;
    return 0;
}