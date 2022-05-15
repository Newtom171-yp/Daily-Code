#include <iostream>
using namespace std;

int partition(int *arr, int l, int r)
{

    int pivot = *(arr+l);
    int count = 0;

    for (int i = l+1; i <= r; i++)
        if (*(arr + i) < pivot)
            count++;

    swap(*(arr + l), *(arr + l + count));

    int pivotIndex = count + l;
    int i = l, j = r;
    while (i <pivotIndex && j > pivotIndex)
    {
        while(arr[i] < arr[pivotIndex]) i++;
        while(arr[j] > arr[pivotIndex]) j--;
        if(i <pivotIndex && j > pivotIndex) swap(arr[i++],arr[j--]);

    }
    return pivotIndex;
}

void sort(int *arr, int l, int r)
{

    if (l >= r)
        return;

    int p = partition(arr, l, r);

    sort(arr, l, p - 1);
    sort(arr, p + 1, r);
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

    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}