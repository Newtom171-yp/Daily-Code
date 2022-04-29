// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int > sieve(int root){
        bool a[root+1] = {0};
        vector <int > v;
        for(int  i = 2; i*i < root+1; i++){
            if(a[i]) continue;
            for(int  j = i*i; j <root+1; j += i){
                a[j] = true;
            }
        }
        
        for(int i = 2; i < root+1; i++){
            if(!a[i]) v.push_back(i);
        }

        return v;
    }
    
    vector<int> primeRange(int M, int N) {
        int root = sqrt(N);
        bool ans[N - M + 1] = {0};
        vector<int> finalAns;
        vector<int > primes(sieve(root));
        
        for(auto prime : primes){
            
            int multiple = ceil((M*1.0)/prime);
            
            if (multiple == 1) multiple++;
            
            int startIndex = multiple*prime - M;
            
            for(int i = startIndex; i < (N - M + 1); i+=prime){
                ans[i] = true;
            }
        }
        for(int i = 0; i < (N - M + 1); i++){
            if(!ans[i] && i+M != 1) {
                finalAns.push_back(i+M);
            };
        }
        return finalAns;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends