// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    private:
    Node* findMiddle(Node* &head)
    {
        Node* fast = head->next;
        Node* slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    } 
    
    Node* reverse(Node* &head)
    {
        if(!head || !head->next) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        
        while(curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        Node* middle = findMiddle(head);
        
        middle->next = reverse(middle->next);
        
        
        Node* first = head;
        Node* second = middle->next;
        while(second)
        {
            if(first->data != second->data) return false;
            first = first->next;
            second = second->next;
        }
        
        middle->next = reverse(middle->next);
        
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends