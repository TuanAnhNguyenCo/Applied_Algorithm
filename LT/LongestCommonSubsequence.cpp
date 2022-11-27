#include "bits/stdc++.h"
#define MAX 10001
using namespace std;

int n, m;
int X[MAX], Y[MAX];
int LCS[MAX][MAX];
void init()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &X[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &Y[i]);
}
void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    cout << LCS[n][m];
}
int main()
{
    init();
    Solution();
    return 0;
}