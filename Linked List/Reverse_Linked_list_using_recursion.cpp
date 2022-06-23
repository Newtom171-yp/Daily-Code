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
void reverse(Node* &head, Node* &prev, Node* &curr)
{
    if(!curr)
    {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    curr->next = prev;
    reverse(head, curr, forward);
}
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node* prev = NULL;
    Node* curr = head;
    reverse(head, prev, curr);
    return head;
}