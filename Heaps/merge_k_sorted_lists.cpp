/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include <bits/stdc++.h>
using namespace std;

class compare
{
    public:
    bool operator()(Node<int>*a, Node<int>* b)
    {
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    priority_queue<Node<int>* , vector<Node<int>*>, compare> minHeap;

    int k = listArray.size();

    if(!k) return NULL;

    for(int i = 0; i < k; i++)
    {
        if(listArray[i])
        {
             minHeap.push(listArray[i]);
        }
    }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    while(minHeap.size() > 0)
    {
        Node<int>* top = minHeap.top();
        minHeap.pop();

        if(top -> next)
        {
            minHeap.push(top->next);
        }

        if(!head)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}
