#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> q;

    q.push_front(12);
    q.push_back(14);
    cout << q.front() << " " << q.back() <<endl;
    q.pop_front();
    cout << q.front() << " " << q.back() <<endl;
    q.pop_back();
    cout << ((q.empty()?"The Queue is empty!":"The Queue is not empty")) << endl;
    
    return 0;
}