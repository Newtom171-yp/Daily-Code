class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int len1 = 0;
        int len2 = 0;
        
        Node* temp1 = head1;
        
        while(temp1)
        {
            temp1 = temp1->next;
            len1++;
        }
        
        Node* temp2 = head2;
        
        while(temp2)
        {
            temp2 = temp2->next;
            len2++;
        }
        
        int diff = abs(len1 - len2);
        
        temp1 = head1;
        temp2 = head2;
        
        if(len1 > len2)
        {
            for(int i = 0; i < diff; i++)
            {
                temp1 = temp1->next;
            }
        }
        else
        {
            for(int i = 0; i < diff; i++)
            {
                temp2 = temp2->next;
            }
        }
        
        while(temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return temp1->data;
    }
};