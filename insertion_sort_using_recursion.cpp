#include <iostream>
using namespace std;

void sort(int *arr, int size, int i)
{
    if(i == size) return;

    int j = i - 1;
    int temp = arr[i];
    while (j >= 0)
    {
        if (temp < arr[j])
            arr[j + 1] = arr[j];
        else
            break;
        j--;
    }
    arr[j + 1] = temp;

    sort(arr, size, i + 1);
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, n, 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}