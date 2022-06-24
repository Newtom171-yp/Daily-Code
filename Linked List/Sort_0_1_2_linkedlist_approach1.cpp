/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
    // Write your code here.
    int zero = 0;
    int one = 0;
    int two = 0;
    
    Node* temp = head;
    while(temp)
    {
        if(!temp->data) zero++;
        else if (temp->data&1) one++;
        else two++;
        temp=temp->next;
    }
    temp =  head;
    while(temp)
    {
        if(zero)
        {
            temp->data = 0;
            zero--;
        }
        else if(one)
        {
            temp->data = 1;
            one--;
        }
        else
        {
            temp->data = 2;
            two--;
        }
        temp=temp->next;
    }
    return head;
}