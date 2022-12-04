#include "bits/stdc++.h"
#define MAX 10000
using namespace std;

int n;
int c[MAX][MAX];
int visited[MAX];
int f_min = 99999999;
int load;
int f;
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
            if (i != j)
                min_distance = min(min_distance, c[i][j]);
        }
    }
}
bool check(int v)
{
    if (visited[v]) // tham roi thi tra ve false
        return false;
    // if (load == 0) // k nhan dc tra ve false
    // {
    //     if (v > n)
    //         return false;
    // }
    // else // k tra dc thi tra ve false
    // {
    //     if (v <= n)
    //         return false;
    //     else if (!visited[v - n])
    //         return false;
    // }
    return true;
}
void solution(int v)
{
    f_min = min(f_min, f + c[v][0]);
}
void Try(int k, int v)
{

    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {

            f += c[v][i];
            f += c[i][i + n];
            visited[i] = true;

            if (k == n)
            {
                solution(i + n);
            }
            else if (f + ((n - k) * 2 + 1) * min_distance < f_min)
                Try(k + 1, i + n);

            visited[i] = false;
            f -= c[v][i];
            f -= c[i][i + n];
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