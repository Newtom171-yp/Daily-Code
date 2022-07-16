void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int var = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(var);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()) return;
    
    int var = stack.top();
    stack.pop();
    
    reverseStack(stack);
    
    insertAtBottom(stack,var);
}