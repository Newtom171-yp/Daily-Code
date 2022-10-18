#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		for(int gap = 0; gap <N; gap++)
		{
		    for(int i = 0, j = gap; j >=0; j--,i++)
		    {
		        ans.push_back(A[i][j]);
		    }
		}
		
		for(int gap = 1; gap <N; gap++)
		{
		    for(int i = gap, j = N - 1; i < N; j--,i++)
		    {
		        ans.push_back(A[i][j]);
		    }
		}
		
		return ans;
	}

};