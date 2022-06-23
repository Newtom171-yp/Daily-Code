/*********************************************************

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

************************************************************/

Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here. 
    if(!head || !head->next) return head;
    
    int cnt = k;
    
    Node* forward = NULL;
    Node* curr = head;
    Node* backward = NULL;
    
    while(cnt-- && curr)
    {
        forward = curr->next;
        curr->prev = curr->next;
        curr->next = backward;
        backward = curr;
        curr = forward;
    }
    
    if(forward)
    {
        head->next = reverseDLLInGroups(forward,k);
    }
    return backward;
}