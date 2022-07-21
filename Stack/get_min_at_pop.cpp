//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

// } Driver Code Ends
//User function Template for C++

int minStack(stack <int> &s, int mini)
{
    if(s.empty()) return mini;
    
    int top =  s.top();
    
    mini = min (top , mini);
    
    s.pop();
    
    int minx = minStack(s, mini);
    
    s.push(top);
    return min(mini, minx);
}
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
   // your code here
   stack<int> s;
   
   for(int i = 0; i < n; i++)
   {
       s.push(arr[i]);
   }
   return s;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    // your code here
    
    while(!s.empty())
    {
        
        cout << minStack(s , INT_MAX) << " ";
        
        s.pop();

    }
}

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    cout<<endl;
	    
	}
	return 0;
}


// } Driver Code Ends