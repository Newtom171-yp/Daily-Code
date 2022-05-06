#include <iostream>
using namespace std;

int expo(int a, int b)
{
    int ans = 1;
    if (!b)
        return ans;
    if (b & 1)
        ans = a * expo(a, b >> 1) * expo(a, b >> 1);
    else
        ans = expo(a, b >> 1) * expo(a, b >> 1);
    return ans;
}

int main()
{
    int a, b;
    cout << "Enter the base value" << endl;
    cin >> a;
    cout << "Enter the exponent value" << endl;
    cin >> b;
    cout << "Your result is : " << expo(a, b) << endl;
    return 0;
}