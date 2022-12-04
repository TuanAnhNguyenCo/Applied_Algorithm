#include "bits/stdc++.h"
#define MAX 1000000
using namespace std;

int n;
int a[MAX];
int cnt;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            cnt++;
            i++;
        }
    }
    cout << cnt;

    return 0;
}