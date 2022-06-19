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
};

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

int getListLength(Node* &head)
{
    int count = 0;

    Node* temp = head;

    while(temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void InsertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node* &tail, int data)
{
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

int main()
{
    Node* node = new Node(100);
    Node* head = node;
    Node* tail = node;

    cout << getListLength(head) << endl;
    print(head);

    InsertAtHead(head, 55);
    InsertAtHead(head, 88);
    InsertAtHead(head, 59);
    InsertAtHead(head, 9);
    InsertAtTail(tail, 69);
    InsertAtTail(tail, 987);
    InsertAtTail(tail, 76);
    print(head);

    return 0;
}