int NumberGame(long long A) {
	// Write your code here.
    
    long long count = 0;
    
    for(long long i = 1; i*i <= A; i++) 
    {
        if(A%i == 0)
        {
            if(A/i == i) count++;
            else count += 2;
        }
    }
    
    return count;
}