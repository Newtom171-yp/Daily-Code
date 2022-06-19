#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 100;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
};

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node();
    temp->data = data;
    tail->next = temp;
    tail = tail->next;
}

void InserAtPosition(Node *&head, int data, int p)
{
    if (!p)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *current = head;
    Node *after;
    while ((p--) > 1)
    {
        current = current->next;
    }
    after = current->next;
    
    if (!current->next)
    {
        InsertAtTail(current, data);
        return;
    }

    Node *temp = new Node(data);
    temp->next = after;
    current->next = temp;
}

void DeleteAtPosition(Node* &head, int position)
{
    Node* temp = head;
    Node* temp2 = temp;
    while(position--)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    delete temp;

}

int main()
{
    Node *node1 = new Node();
    cout << node1->data << " " << node1->next << endl;

    Node *node2 = new Node(50);
    cout << node2->data << " " << node2->next << endl;

    Node *head = node1;
    cout << "Printing before adding at head" << endl;
    print(head);

    InsertAtHead(head, 67);
    InsertAtHead(head, 87);
    InsertAtHead(head, 89);
    InsertAtHead(head, 65);
    cout << "Printing after addding at head" << endl;
    print(head);

    Node *tail = node1;
    cout << "Printing before adding at tail" << endl;
    print(node2);
    InsertAtTail(node2, 98);
    cout << "Printing after adding at tail" << endl;
    print(node2);

    InserAtPosition(head, 69, 5);
    cout << "Printing after adding at nth position" << endl;
    print(head);
    cout << tail->data << endl;


    print(head);
    DeleteAtPosition(head,3);
    cout<<"Printing after deletion"<<endl;
    print(head);

    return 0;
}