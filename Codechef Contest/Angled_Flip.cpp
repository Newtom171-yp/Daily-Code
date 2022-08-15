#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n,m;
	    cin >> n >> m;
	    
	    int elementA, elementB;
	    //if either n or m == 1;
	    vector<int> a1, b1;
	    
	    //vectors for similar elements
	    vector<int> simA, simB;
	    
	    //vectors for odd/different elements
	    vector<int> diffA, diffB;
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            cin >> elementA;
	            if(n == 1||m == 1)a1.push_back(elementA);
	            else
	            {
	                if((i^j)&1)diffA.push_back(elementA);
	                else simA.push_back(elementA);
	            }
	        }
	    }
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            cin >> elementB;
	            if(n == 1||m == 1)b1.push_back(elementB);
	            else
	            {
	                if((i^j)&1)diffB.push_back(elementB);
	                else simB.push_back(elementB);
	            }
	        }
	    }
	    if(n == 1 || m == 1)
	    {
	        cout << ((a1 == b1)?"YES":"NO") << endl;
	        continue;
	    }
	    
	    sort(simA.begin(),simA.end());
	    sort(simB.begin(),simB.end());
	    sort(diffB.begin(),diffB.end());
	    sort(diffA.begin(),diffA.end());
	    
	    cout << ((simA == simB && diffA == diffB)?"YES":"NO") << endl;
	}

	return 0;
}