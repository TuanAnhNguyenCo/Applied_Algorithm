#include "bits/stdc++.h"
#define MAX 10000
using namespace std;

int n;
int c[MAX][MAX];
int visited[MAX];
int f_min = 99999999;
int load;
int f;
int startPoint[MAX];
int customers;
int min_distance = 9999999;

void init()
{
    scanf("%d", &n);
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            scanf("%d", &c[i][j]);
            if(i!==j)
                min_distance = min(min_distance, c[i][j]);
        }
    }
    startPoint[0] = 1;
}
bool check(int v)
{
    if (v == 0)
        return true;
    if (visited[v]) // tham roi thi tra ve false
        return false;
    if (load == 0) // k nhan dc tra ve false
    {
        if (v > n)
            return false;
    }
    else // k tra dc thi tra ve false
    {
        if (v <= n)
            return false;
        else if (!visited[v - n])
            return false;
    }

    return true;
}
void solution()
{
    f_min = min(f_min, f);
}
void Try(int k, int v)
{
    for (int i = startPoint[v]; i <= 2 * n; i++)
    {
        if (check(i))
        {
            f += c[v][i];
            visited[i] = true;
            if (i != 0)
            {
                customers++;
                if (load == 0)
                    load++;
                else
                {
                    load--;
                }
            }

            if (i == 0)
            {
                if (customers == 2 * n)
                {
                    f += c[i][0];
                    solution();
                    f -= c[i][0];
                }
                else
                    Try(k + 1, i);
            }
            else
                Try(k + 1, i);

            visited[i] = false;
            f -= c[v][i];
            if (i != 0)
            {
                customers--;
                if (load == 0)
                {
                    load++;
                }
                else
                    load--;
            }
        }
    }
}

int main()
{
    init();
    Try(1, 0);
    cout << f_min;
    return 0;
}