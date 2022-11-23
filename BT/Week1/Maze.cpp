#include <bits/stdc++.h>
#define MAX 999
using namespace std;

int n, m, r, c;
int M[MAX][MAX] = {};
int A[MAX][MAX];
int d[MAX][MAX] = {};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
typedef pair<int, int> ii;

bool check(int x, int y)
{

    if (A[x][y] == 1)
        return false;
    if (M[x][y] == 1)
        return false;

    return true;
}

int solve()
{

    /*
    tạo queue
    lặp cho đế khi queue rỗng
    {
        - Kiểm tra nếu vị trí hiện tại là biên thì sẽ trả về kết quả
        - kiểm tra các phần tử kề nó nếu đi được hay là chưa đi vào điểm đó thì sẽ thêm vào queue
    }
    Nếu không có đương thoát thì sẽ trả về -1
    Vì là mê cung này không có trong số lên bfs sẽ tốt và nhanh nhất để tìm đường
    ngắn nhất
    */

    // create queue
    queue<ii> Q;
    Q.push(ii(r, c));
    M[r][c] = 1;
    d[r][c] = 0;
    ii u;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            // if (x < 1 || y < 1 || x > n || y > m)
            //     return d[u.first][u.second] + 1;
            if (check(x, y))
            {
                if (x == 1 || y == 1 || x == n || y == m)
                    return d[u.first][u.second] + 1 + 1;
                else
                {
                    Q.push(ii(x, y));
                    M[x][y] = 1;
                    d[x][y] = d[u.first][u.second] + 1;
                }
            }
        }
    }

    // return -1 if not exist
    return -1;
}
int main()
{
    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];
    int results = solve();
    cout << results;
    return 0;
}