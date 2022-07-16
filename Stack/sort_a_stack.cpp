void addSorted(stack<int> &s, int x)
{
    if((!s.empty() && s.top() <= x) || s.empty())
    {
        s.push(x);
        return;
    }
    
    int var = s.top();
    s.pop();
    addSorted(s,x);
    s.push(var);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()) return;
    
    int var = stack.top();
    stack.pop();
    sortStack(stack);
    addSorted(stack,var);
}