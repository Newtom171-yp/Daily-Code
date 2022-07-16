class Solution {
public:
    
    vector<int> nextSmallest(vector<int> &heights, int n)
    {
        vector<int> ans(n);
        
        stack<int> s;
        s.push(-1);
        
        for(int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> prevSmallest(vector<int> &heights, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
       
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallest(heights , n);
        
        vector<int> prev(n);
        prev = prevSmallest(heights , n);
        
        int maxArea = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            int length = heights[i];
            
            if(next[i] == -1) next[i] = n;
            
            int breadth = next[i] - prev[i] - 1;
            
            int newArea = length * breadth;
            
            maxArea = max(maxArea, newArea);
            
        }
        
        return maxArea;
        
    }
};