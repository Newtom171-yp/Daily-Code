class Solution{
public:

    void swap ( int* a, int* b ) 
    { int t = *a; *a = *b; *b = t; }
    
    Node* partition(Node *l, Node *h){
        //Your code goes here
        int x = h->data; 
      
        // similar to i = l-1 for array implementation 
        Node *i = l->prev; 
      
        // Similar to "for (int j = l; j <= h- 1; j++)" 
        for (Node *j = l; j != h; j = j->next) 
        { 
            if (j->data <= x) 
            { 
                // Similar to i++ for array 
                i = (i == NULL)? l : i->next; 
      
                swap(&(i->data), &(j->data)); 
            } 
        } 
        i = (i == NULL)? l : i->next; // Similar to i++ 
        swap(&(i->data), &(h->data)); 
        return i; 
    }
};