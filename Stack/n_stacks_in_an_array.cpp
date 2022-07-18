class NStack
{
    int* arr;
    int* top;
    int* next;
    
    int n,s,freeSpot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        this->n = N;
        this->s = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        
        for(int i = 0; i < n; i++)
        {   
            top[i] = -1;
        }
        
        for(int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }
        next[s-1] = -1;
        
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freeSpot == -1) return false;
        
        int index = freeSpot;
        
        freeSpot = next[index];
        
        arr[index] = x;
        
        next[index] = top[m-1];
        
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1] == -1) return -1;
        
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];       
    }
};