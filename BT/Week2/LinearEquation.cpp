#include "bits/stdc++.h"
#define MAX 99999
using namespace std;

int n;
int m;
int a[MAX];
int T[MAX];
int results;
int f;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        T[i] = T[i - 1] + a[i];
    }
}

void solution()
{
    if (f == m)
        results += 1;
}
bool check()
{
    return true;
}
void Try(int k)
{
    for (int i = 1; i <= (m - f - (T[n] - T[k])) / a[k]; i++)
    {
        if (check())
        {
            f += i*a[k];
            if (k == n)
                solution();
            else
                Try(k + 1);
            f -= i*a[k];
        }
    }
}

int main()
{
    init();
    Try(1);
    cout << results;
    return 0;
}