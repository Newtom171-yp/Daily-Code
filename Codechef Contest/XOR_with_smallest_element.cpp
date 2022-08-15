#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n,x,y;
	    cin >> n >> x >> y;
	    int number;
	    
	    priority_queue <int, vector<int>, greater<int>> q;
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> number;
	        q.push(number);
	    }
	    
	    while(y)
	    {
	        int mini = q.top();
	        if((mini ^ x) > mini)
	        {
	            q.pop();
	            q.push(mini ^ x);
	            y--;
	        }
	        else
	        {
	            if(y%2 == 0) break;
	            else
	            {
	                q.pop();
	                q.push(mini^x);
	                break;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        cout << q.top() << " ";
	        q.pop();
	    }
	    cout << endl;
	}

	return 0;
}