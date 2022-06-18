#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node ()
    {
        this->data = 100;
        this->next = NULL;
    }

    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;

    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};

void InsertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data)
{
    Node* temp = new Node();
    temp->data = data;
    tail->next = temp;
    tail = tail->next;
}

int main()
{
    Node* node1 = new Node();
    cout << node1->data << " " << node1->next<<endl;
    
    Node* node2 = new Node(50);
    cout << node2->data << " " << node2->next<<endl;

    Node* head = node1;
    print(head);

    InsertAtHead(head,67);
    print(head);

    Node* tail = node2;
    print(node2);
    InsertAtTail(tail,98);
    print(node2);

    return 0;
}