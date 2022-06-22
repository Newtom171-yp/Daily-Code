#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(!head || !head->next) return head;
    LinkedListNode<int>* i = NULL;
    LinkedListNode<int>* j = NULL;
    
    while(head)
    {
        j = head->next;
        head->next = i;
        i = head;
        head = j;
    }
    return i;
}