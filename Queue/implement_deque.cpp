class Deque
{
public:
    int* arr;
    int front;
    int rear;
    int size;
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()) return false;
        
        if(front == -1) front = rear = 0;
        else if(!front && rear != size -1) front = size - 1;
        else front--;
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()) return false;
        if(rear == -1) front = rear = 0;
        else if (rear == size - 1 && front) rear = 0;
        else rear++;
        arr[rear] = x;
        return true;
        // Write your code here.
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        
        int top = arr[front];
        
        if(front == rear) front = rear = -1;
        
        else if (front == size - 1) front = 0;
        
        else front++;
        
        return top;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        
        int top = arr[rear];
        
        if(front == rear) front = rear = -1;
        
        else if (rear == 0) rear = size - 1;
        
        else rear--;
        
        return top;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return(front == -1);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        return ((front == 0 && rear == size -1) || (front && rear == (front -1) % (size -1)));

    }
};