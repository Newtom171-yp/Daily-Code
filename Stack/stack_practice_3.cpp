#include <iostream>
using namespace std;

class stack
{
    int data;
    stack* next;
    stack* top = NULL;

    public:

    stack(){};

    stack(int data)
    {
        this->data = data;
        next = NULL;
    }

    ~stack()
    {

        if(next)
        {
            delete next;
            next = NULL;
        }

        if(top)
        {
            delete top;
            top = NULL;
        }
    }

    void push(int data)
    {
        stack* newNode = new stack(data);

        if(!top)
        {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
        return;
    }

    void pop()
    {
        if(!top)
        {
            cout<<"Stack Underflow!"<<endl;
            return;
        }

        stack* temp = top;

        top = top->next;

        cout << "The poped element is : "<< temp->data<<endl;

        delete temp;
    }

    int peek()
    {
        return top->data;
    }
};

int main()
{
    stack s;
    s.push(8);
    s.pop();
    printf("The top element is : ", s.peek());

    return 0;
}