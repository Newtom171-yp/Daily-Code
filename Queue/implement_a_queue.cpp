class Queue {
    
    int* arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size = 100000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (qfront == rear);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size)
        {
            cout << "Queue is Full"<<endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(isEmpty())
        {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return arr[qfront];
    }
};