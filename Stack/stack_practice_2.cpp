#include <iostream>
using namespace std;

class stack
{

public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(top == size-1)
        {
            cout<<"Stack overflow!"<<endl;
            return;
        }
        arr[++top] = element;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack underflow!"<<endl;
            return;
        }
        cout<<"The element removed is: "<<arr[top--]<<endl;
    }

    int peek()
    {
        if(top == -1)
        {
            cout<<"The stack is empty!"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }
};

int main()
{
    stack s(3);
    s.push(1);
    s.push(3);
    s.push(8);
    s.push(80);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    (s.isEmpty()) ? cout<<"The stack is empty"<<endl : cout<<"The stack is not empty"<<endl;
    cout<<s.peek()<<endl;
    return 0;
}