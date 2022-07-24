class CircularQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        front = -1;
        rear = -1;
        size = n;
        arr = new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front == 0 && rear == size-1)||(rear == (front-1)%(size-1))) return false;
        
        if(front == -1) front = rear = 0;
        
        else if(rear == size-1 && front) rear = 0;
        
        else rear++;
        
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front == -1) return -1;
        
        int top = arr[front];
        
        if(front == rear) front = rear = -1;
        
        else if(front == size - 1) front = 0;
        
        else front++;
        
        return top;
    }
};