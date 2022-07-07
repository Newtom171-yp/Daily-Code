bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack <char> s;
    for(int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if(ch == '{' || ch == '(' || ch == '[')
        {
            s.push(ch);
            continue;
        }
        
        if(s.empty()) return false;
        char top = s.top();
        switch(ch)
        {
            case '}':
                {
                    if(top != '{') return false;
                    s.pop();
                    break;
                }
            case ')':
                {
                    if(top != '(') return false;
                    s.pop();
                    break;
                }
            case ']':
                {
                    if(top != '[') return false;
                    s.pop();
                    break;
                }
        }
    }
    return s.empty();
}