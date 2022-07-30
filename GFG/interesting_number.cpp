// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++



class Solution{
    public:
    bool divisibleByEight(string &num){
        //Code Here
        bool flag = true;
        
        for(int i = 0; i < num.length(); i++)
        {
            if(num[i] == '8' || num[i] == '0') return true;
            if((num[i] - '0')%2 == 0) flag = false;
        }
        
        if(flag == true) return false;
        
        unordered_map<int,int> m;
        m[1] = 6;
        m[2] = 4;
        m[3] = 2;
        m[4] = 0;
        m[5] = 6;
        m[6] = 4;
        m[7] = 2;
        m[9] = 6;
        
        vector<bool> mark(10,false);
        
        for(int i = num.length()-1; i >=0; i--)
        {
            if(mark[m[num[i] - '0']])
            {
                return true;
            }
            mark[num[i] - '0'] = true; 
        }
        
        return false;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string num;
        cin>>num;
        
        Solution obj;
        
        bool ans = obj.divisibleByEight(num);
        
        if(ans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}


  // } Driver Code Ends