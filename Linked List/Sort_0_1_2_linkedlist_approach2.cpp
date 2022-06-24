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

void insert(Node* temp, Node* &tail)
{
    tail->next = temp;
    tail = tail->next;
}

Node* sortList(Node *head)
{
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    //dividing into sublists
    Node* temp = head;
    while(temp)
    {
        int val = temp->data;
        if(!val)
        {
            insert(temp,zeroTail);
        }
        else if(val&1)
        {
            insert(temp,oneTail);
        }
        else
        {
            insert(temp,twoTail);
        }
        temp = temp->next;
    }
    
    //merging the lists
    if(oneHead->next)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    
    head = zeroHead->next;
    
    zeroHead->next = NULL;
    delete zeroHead;
    oneHead->next = NULL;
    delete oneHead;
    twoHead->next = NULL;
    delete twoHead;
    
    return head;
}
