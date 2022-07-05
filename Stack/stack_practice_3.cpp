#include <iostream>
using namespace std;

class stack
{
    int data;
    stack* next;
    
    public:

    stack(){};
    stack(int data)
    {
        this->data = data;
        next = NULL;
    }

    void push(int data, stack* &top)
    {
        stack* newNode = new stack(data);

        if(!top)
        {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    void pop(stack* &top)
    {
        if(!top)
        {
            cout<<"Stack Underflow!"<<endl;
            return;
        }

        stack* temp = top;
        top = top->next;
        cout<<"The poped element is : "<< temp->data << endl;
        temp->next = NULL;
        delete temp;
    }

    int peek(stack* &top)
    {
        if(!top)
        {
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(stack* &top)
    {
        return !top;
    }
};

int main()
{
    stack* top = NULL;
    stack s;
    s.push(10 , top);
    s.push(20, top);
    s.push(30, top);
    cout <<s.peek(top) << endl;

    s.pop(top);
    s.pop(top);
    s.pop(top);

    cout << s.peek(top) << endl;

    cout << s.isEmpty(top) << endl;
    return 0;
}