#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int x;
	    cin >> x;
	    
	    if(x < 5)
	    {
	        cout << "NO" << endl;
	        continue;
	    }
	    
	    bool flag = false;
	    
	    for(int i = 1; i*i <= x; ++i)
	    {
	        if((x-(2*i))%(i+2)==0 && x != 2*i)
	        {
	            flag = true;
	            break;
	        }
	    }
	    
	    cout << ((flag)?"YES":"NO") << endl;
	}
	
	
	return 0;
}