/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
        
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

Node* reverse(Node* &head)
{
    if(!head || !head->next) return head;
    Node* head1 = reverse(head->next);
    head->next->prev = head->next->next;
    head->next->next = head;
    head->next = NULL;
    head->prev = NULL;
    return head1;
}

Node* reverseDLL(Node* head)
{   
    // Write your code here   
    reverse(head);
}