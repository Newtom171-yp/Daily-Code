/****************************************************************

    Following is the class structure of the Node class:

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
Node* reverse(Node* &head)
{
    if(!head || !head->next) return head;
    
    Node* head1 = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return head1;
}
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    return reverse(head);
}

