#include <stack>
int findMinimumCost(string str) {
  // Write your code here
    if(str.length()&1) return -1;
    stack<char> s;
    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if(ch == '{') s.push(ch);
        else
        {
            if(!s.empty() && s.top() == '{') s.pop();
            else s.push(ch);
        }
    }
    
    int openCount = 0, closeCount = 0;
    while(!s.empty())
    {
        if(s.top() == '{') openCount++;
        else closeCount++;
        s.pop();
    }
    return ((openCount+1)/2 + (closeCount+1)/2);
}