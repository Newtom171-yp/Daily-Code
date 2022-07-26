//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include <bits/stdc++.h>
int maxPalindrome(Node *head)
{
    //Your code here
    vector<int> v;
    
    Node* temp = head;
    
    while(temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    
    int n = v.size();
    
    bool valid[n][n];
    
    int maxLength = INT_MIN;
    
    for(int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; j++,i++)
        {
            if(!g)
            {
                valid[i][j] = true;
            }
            else if(g == 1)
            {
                valid[i][j] = (v[i] == v[j]);
            }
            else
            {
                valid[i][j] = (v[i] == v[j] && valid[i+1][j-1]);
            }
            if(valid[i][j]) maxLength = g + 1;
        }
    }
    return maxLength;
}