#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n, x;
	    cin >> n >> x;
	    
	    if(x > n + n - 1 || x < n)
	    {
	        cout << -1 << endl;
	        continue;
	    }
	    
	    int firstNum = x - n + 1;
	    
	    cout << firstNum << " ";
	    
	    for(int i = 1; i <= n; i++)
	    {
	        if(i == firstNum) continue;
	        
	        cout << i << " ";
	    }
	    
	    cout << endl;
	    
	}
	
	
	return 0;
}
