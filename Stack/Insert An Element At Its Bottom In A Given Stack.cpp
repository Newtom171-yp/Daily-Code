void solve(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int var = s.top();
    s.pop();
    solve(s,x);
    s.push(var);
    return;
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}