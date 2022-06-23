/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(!head) return NULL;
    if(head->next == head) 
    {
        head->next = NULL;
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    do
    {
        if(!fast || !fast->next) return head;
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node* temp = slow;
    while(temp->next != slow)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}