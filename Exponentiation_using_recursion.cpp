#include <iostream>
using namespace std;

int expo(int a, int b)
{
    int ans = 1;
    if (!b)
        return ans;
    int multi = expo(a, b >> 1);
    if (b & 1)
        ans = a * multi * multi;
    else
        ans = multi * multi;
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