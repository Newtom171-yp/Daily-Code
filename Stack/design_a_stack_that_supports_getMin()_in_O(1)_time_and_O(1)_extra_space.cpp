#include <stack>

class SpecialStack {
    // Define the data members.
    stack<int> s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty())
        {
            s.push(data);
            mini = data;
            return;
        }
        
        if(data < mini)
        {
            s.push((2*data) - mini);
            mini = data;
        }
        else s.push(data);
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()) return -1;
        if(s.top() > mini)
        {
            int top = s.top();
            s.pop();
            return top;
        }
        else
        {
            int prevMini = mini;
            int top = (2*mini) - s.top();
            s.pop();
            mini = top;
            return prevMini;
        }
    }

    int top() {
        // Implement the top() function.
        
        if(s.empty()) return -1;
        if(s.top() < mini)
        {
            return mini;
        }
        else
        {
            return s.top();
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()) return -1;
        return mini;
    }  
};