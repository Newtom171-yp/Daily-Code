#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    deque<int> q;
	    
	    for(int i = 1; i <= n; i++)
	    {
	        if(i&1) q.push_front(i);
	        else q.push_back(i);
	    }
	    
	    while(!q.empty())
	    {
	        cout << q.front() << " ";
	        q.pop_front();
	    }
	    cout << endl;
	}
	
	
	return 0;
}
