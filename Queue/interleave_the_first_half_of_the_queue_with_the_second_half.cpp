void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    int n = q.size()/2;
    queue<int> q2;
    for(int i = 0; i < n; i++)
    {
        q2.push(q.front());
        q.pop();
    }
    for(int i = 0; i < n; i++)
    {
        q.push(q2.front());
        q2.pop();
        q.push(q.front());
        q.pop();
    }
}