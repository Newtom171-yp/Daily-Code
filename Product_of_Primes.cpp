// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long > sieve(long long root){
        bool a[root+1] = {0};
        vector <long long > v;
        for(long long  i = 2; i*i < root+1; i++){
            if(a[i]) continue;
            for(long long  j = i*i; j <root+1; j += i){
                a[j] = true;
            }
        }
        
        for(long long i = 2; i < root+1; i++){
            if(!a[i]) v.push_back(i);
        }

        return v;
    }
    long long primeProduct(long long L, long long R){
        long long root = sqrt(R);
        bool ans[R - L + 1] = {0};
        long long finalAns = 1;
        vector<long long > primes(sieve(root));
        
        for(auto prime : primes){
            
            long long multiple = ceil((L*1.0)/prime);
            
            if (multiple == 1) multiple++;
            
            long long startIndex = multiple*prime - L;
            
            for(long long i = startIndex; i < (R - L + 1); i+=prime){
                ans[i] = true;
            }
        }
        for(long long i = 0; i < (R - L + 1); i++){
            if(!ans[i] && i+L != 1) {
                //cout<<i+L<<endl;
                finalAns =(finalAns*(i+L))%1000000007;
            }
        }
        long long final = finalAns%1000000007;
        return final;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends