#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(11);
    q.push(7);
    q.push(9);
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    q.empty() ? (cout << "Queue is empty" << endl ): (cout << "Queue is not empty" << endl);
}