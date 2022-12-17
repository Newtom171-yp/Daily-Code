class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;

        for(string x: tokens)
        {
            if(x == "+")
            {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(x == "*")
            {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(x == "-")
            {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(x == "/")
            {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b/a);
            }
            else s.push(stoi(x));
        }
        return s.top();
    }
};