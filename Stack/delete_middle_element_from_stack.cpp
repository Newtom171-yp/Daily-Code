void solve (stack<int> &s, int N, int count)
{
    if(count == N/2)
    {
        s.pop();
        return;
    }
    
    int temp = s.top();
    s.pop();
    solve(s,N,count+1);
    
    s.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   solve(inputStack, N, 0);

}