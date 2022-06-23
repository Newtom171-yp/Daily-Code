/****************************************************************
    Following is the Linked List node structure

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

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(!head || !head->next) return head;
    
    int cnt = k;
    
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    while(curr && cnt--)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    if(forward)
    {
        head->next = kReverse(forward,k);
    }
    return prev;
}