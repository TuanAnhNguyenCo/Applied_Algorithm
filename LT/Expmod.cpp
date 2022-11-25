#include "bits/stdc++.h"
using namespace std;

long Try(unsigned long long a, unsigned long long  b)
{
    if (b == 1)
        return a % 1000000007;
    else
    {
        long c1 = Try(a, (b >> 1));
        cout << c1 << endl;
        if (b % 2 == 1)
            return ((c1 * c1) % 1000000007 * a) % 1000000007;
        else
            return (c1 * c1) % 1000000007;
    }
}

int main()
{
    long a, b;
    cin >> a >> b;
    cout << Try(a, b);
    return 0;
}