/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* getMid(node* head)
{
    node* slow = head;
    node* fast = head->next;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node*right)
{
    if(!left) return right;
    if(!right) return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    while(left && right)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }
    while(left)
    {
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }
    while(right)
    {
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }
    
    temp = ans;
    ans = ans->next;
    temp->next = NULL;
    delete temp;
    return ans;
}

node* mergeSort(node *head) {
    // Write your code here.
    if(!head || !head->next) return head;
    
    node* mid = getMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    node* result = merge(left,right);
    
    return result;
}
