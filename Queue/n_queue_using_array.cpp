class NQueue{
public:
    // Initialize your data structure.
    int *front;
    int *rear;
    int *next;
    int* arr;
    int freeSpot;
    NQueue(int n, int s){
        // Write your code here.
        front = new int[n];
        rear = new int[n];
        for(int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[s];
        next[s-1] = -1;
        for(int i = 0; i < s-1; i++)
        {
            next[i] = i+1;
        }
        arr = new int[s];
        freeSpot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
        if(freeSpot == -1) return false;
        int index = freeSpot;
        freeSpot = next[index];
        if(front[m-1] == -1)
        {
            front[m-1] = index;
        }
        else
        {
            next[rear[m-1]] = index;
        }
        next[index] = -1;
        rear[m-1] = index;
        arr[index] = x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        if(front[m-1] == -1) return -1;
        
        int index = front[m-1];
        
        front[m-1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};