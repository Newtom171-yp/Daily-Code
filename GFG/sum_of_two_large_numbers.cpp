//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int carry = 0;
        int sum  = 0;
        int index1 = X.length() - 1;
        int index2 = Y.length() - 1;
        string s = "";
        
        while(index1 >= 0 && index2 >= 0)
        {
            sum = X[index1--] - '0' + Y[index2--] - '0' + carry;
            int new_digit = sum % 10;
            s.push_back(new_digit + '0');
            carry = sum / 10;
        }
        while(index1 >= 0)
        {
            sum = X[index1--] - '0' + carry;
            int new_digit = sum % 10;
            s.push_back(new_digit + '0');
            carry = sum / 10;
        }
        
        while(index2 >= 0)
        {
            sum = Y[index2--] - '0' + carry;
            int new_digit = sum % 10;
            s.push_back(new_digit + '0');
            carry = sum / 10;
        }
        if(carry)
        {
            s.push_back(carry + '0');
        }
        
        for(int i = s.length() - 1; i > 0 && s[i] == '0'; i--)
        {
            s.pop_back();
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends