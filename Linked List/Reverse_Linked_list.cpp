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

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node* prev = NULL;
    Node* curr;
    while(head)
    {
        curr = head;
        head = head->next;
        curr->next = prev;
        prev = curr;
    }
    return curr;
}

