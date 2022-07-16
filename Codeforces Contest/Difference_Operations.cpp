#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int a = arr[0];
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            if(arr[i]%a) flag = false;
        }

        (flag)?cout<<"YES"<<endl : cout <<"NO"<<endl;
    }
    return 0;
}