/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(!head || !head->next) return head;
    Node* itr = head;
    while(itr->next)
    {
        if(itr->data == itr->next->data)
        {
            itr->next = itr->next->next;
        }
        else itr  = itr->next;
    }
    return head;
}