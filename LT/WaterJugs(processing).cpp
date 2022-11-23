#include "bits/stdc++.h"
using namespace std;

int c;
int convert[3];
int full[3];
int jugs[3];
int f;
int results = -1;

void init()
{
    // số lit nước tối đa của 2 bình
    cin >> full[1] >> full[2] >> c;
    // dùng để hoán chuyển 2 bình
    convert[1] = 2;
    convert[2] = 1;
}

int Try(int k)
{
    int count = 0;
    int f;

    count++;
    if (jugs[k] == 0)
    {
        jugs[k] = full[k];
    }
    else
    {
        if (jugs[convert[k]] == full[convert[k]])
        {
            jugs[convert[k]] = 0;
            count++;
        }

        int old = jugs[convert[k]];
        jugs[convert[k]] = min(jugs[1] + jugs[2], full[convert[k]]);
        jugs[k] -= (jugs[convert[k]] - old);
    }
    if (jugs[1] == c || jugs[2] == c)
        f = 0;
    else
        f = Try(k);

    if (f != -1)
        return f + count;
    else
        return -1;
}

int main()
{
    init();

    cout << Try(1);
    return 0;
}