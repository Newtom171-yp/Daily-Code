#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;

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
        if(prev)
        {
            delete prev;
            prev = NULL;
        }
        cout<<"The value which got deleted was : "<<val<<endl;
    }
};

int getListLength(Node *&head)
{
    int count = 0;

    Node *temp = head;

    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    if(position<0 || position > getListLength(head)-1)
    {
        cout<<"Invalid Position!"<<endl;
    }
    if(!position)
    {
        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if(position+1 == getListLength(head))
    {
        Node*temp = tail;
        tail = tail->prev;
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    while(position--)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


void InsertAtHead(Node *&head, Node* & tail, int data)
{
    if(!head)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node* &head, Node *&tail, int data)
{
    if(!tail)
    {
        Node* newNode = new Node (data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtPosition(Node* &head, Node* &tail, int data, int pos)
{
    if(pos < 0)
    {
        cout<<"Invalid Index! "<<endl;
        return;
    }
    if (!pos)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;

    while (pos > 1)
    {
        temp = temp->next;
        if (!temp)
        {
            cout << "Position out of the Linkedlist length, can't add the element! " << endl;
            return;
        }
        pos--;
    }

    if (!temp->next)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 55);
    InsertAtHead(head, tail, 88);
    InsertAtHead(head, tail, 59);
    InsertAtHead(head, tail, 9);
    InsertAtTail(head, tail, 69);
    InsertAtTail(head, tail, 987);
    InsertAtTail(head, tail, 76);
    InsertAtPosition(head, tail, 101, 5);
    print(head);
    deleteNode(head,tail,6);
    print(head);

    return 0;
}