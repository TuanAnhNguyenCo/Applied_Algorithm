#include "bits/stdc++.h"
#define MAX 100001
using namespace std;

typedef struct
{
    int start;
    int finish;
} TIME;

int n;
TIME c[MAX];

void init()
{
    // ios_base.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i].start >> c[i].finish;
}
bool cmp(TIME A, TIME B)
{
    if (A.finish < B.finish)
        return true;
    else if (A.finish == B.finish)
    {
        if (A.start <= B.start)
            return true;
    }
    return false;
}

void proc()
{
    int res = 1;
    int idx = 1;
    sort(c + 1, c + n + 1, cmp);
    for (int i = 2; i <= n; i++)
    {

        if (c[i].start > c[idx].finish)
        {
            res++;
            idx = i;
        }
    }
    cout << res << end;
}

int main()
{
    init();
    proc();
    return 0;
}