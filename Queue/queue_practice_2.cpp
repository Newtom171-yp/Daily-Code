#include <iostream>
using namespace std;

class Queue
{
    public:
    //attributes
    Queue* next;
    Queue* front = NULL;
    Queue* rear = NULL;
    int data;

    //methods
    Queue(){};

    Queue(int data)
    {
        this->data = data;
        next = NULL;
    }

    void enqueue(int data)
    {
        Queue*  newNode = new Queue(data);
        if(!front && !rear)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = rear->next;
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout<<"The Queue is Empty!"<<endl;
            return;
        }
        
        Queue* temp = front;
        front = front->next;
        if(!front) rear = NULL;
        temp->next = NULL;
        delete temp;
    }

    bool empty()
    {
        return (!front && !rear);
    }

    void display()
    {
        Queue* temp = front;
        while(temp)
        {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(15);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(100);
    cout<<(q.empty() ? "Empty" : "Not Empty")<<endl;
    cout << q.front->data <<" "<<q.rear->data<< endl;
    q.display();
    q.dequeue();
    q.display();
    return 0;
}