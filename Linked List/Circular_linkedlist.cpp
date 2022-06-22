#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next = NULL;

    Node(int data)
    {
        this->data = data;
    }

    ~Node()
    {
        int val = this->data;
        if(next)
        {
            delete next;
            next = NULL;
        }
        cout<<"The value which got deleted was : "<<val<<endl;
    }
};

void print(Node* &tail)
{
    if(!tail)
    {
        cout<<"The list is empty: "<<endl;
    }
    Node* temp = tail;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != tail);
    cout<<endl;
    
}

void InsertNode(int data, int element, Node* &tail)
{
    if(!tail)
    {
        Node* temp = new Node(data);
        tail = temp;
        tail->next = tail;
        return;
    }

    Node* temp = tail;
    while(temp->data!=element)
    {
        temp = temp->next;
        if(temp == tail)
        {
            cout<<"The element is not present!"<<endl;
            return;
        }
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    
}

void DeleteNode(int element, Node* &tail)
{
    if(!tail)
    {
        cout<<"The list is already empty"<<endl;
        return;
    }

    Node* temp = tail;
    Node* prev;
    while(temp->data !=element)
    {
        temp = temp->next;
        if(temp==tail)
        {
            cout<<"The element is not present!"<<endl;
            return;
        }
    }

    if(temp == temp->next)
    {
        temp->next = NULL;
        tail=NULL;
        delete temp;
        return;
    }
    do
    {
        prev = temp;
        temp=temp->next;
    } while (temp->data != element);
    prev->next = temp->next;
    temp->next = NULL;
    if(temp == tail)tail = prev;
    delete temp;
    return;
    
}

int main()
{
    Node* tail = NULL;
    InsertNode(5,3,tail);
    InsertNode(6,5,tail);
    InsertNode(3,5,tail);
    InsertNode(9,3,tail);
    InsertNode(100,6,tail);
    InsertNode(7,5,tail);
    print(tail);
    DeleteNode(5,tail);
    print(tail);

    return 0;
}