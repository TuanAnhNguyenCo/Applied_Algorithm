// https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/CVRP
#include "bits/stdc++.h"
#define MAX 50
using namespace std;

// variable
int c[MAX][MAX];  // khoảng cách giữa 2 vị trí
int d[MAX];       // Khối lượng mà khách hàng tại vị trí đó yêu cầu
int n, K, Q;      // số khách hàng, số xe, trọng tải tối đa của xe
int y[MAX];       // điểm suất phát của mỗi chiếc xe tải
int x[MAX];       // điểm tiếp theo của điểm bắt đầu y
int load[MAX];    // trọng tại mà chiếc xe đang trở
int f, f_min;     // độ dài quãng đường hiện tại, độ dài quãng đường nhỏ nhất
int visited[MAX]; // trạng thái được thăm của các khách hàng
int nbSegments;   // số đoạn đường mà tất cả các xe đã đi qua. Tổng = n + K là đủ
int min_distance; // Đoạn đường ngắn nhất dùng cho nhánh và cận tăng tốc độ

/*
Xe1: điểm xuất phát 1
Xe2: điểm xuất phát 2

giống với

Xe1: điểm xuất phát 2
Xe2: điểm xuất phát 1
=> Bài này sẽ duyệt theo kiểu xuất phát xe sau phải lớn hơn xe trước
*/
bool checkY(int v, int k)
{
    if (load[k] + d[v] > Q)
        return false;

    return true;
}
bool checkX(int v, int k)
{
    if (v == 0)
        return true;
    if (visited[v] == true)
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}
void PrintRouting()
{
    for (int i = 1; i <= K; i++)
    {
        cout << "Xe " << i << " : ";
        int a = y[i];
        while (a != 0)
        {
            cout << a << " -> ";
            a = x[a];
        }

        cout << "0" << endl;
    }
}
void solution()
{
    if (f < f_min)
    {
        f_min = f;
        cout << "F " << f << endl;
        PrintRouting();
    }
}

void TryX(int i, int k)
{
    
    for (int v = 0; v <= n; v++)
    {
        if (checkX(v, k))
        {
            x[i] = v;
            visited[v] = true;
            load[k] += d[v];
            f += c[i][v];
            nbSegments += 1;
          

            if (v == 0)
            {
                if (k == K)
                {
                    if (nbSegments == n + K)
                        solution();
                }
                else if (f_min > (f + (n + K - nbSegments) * min_distance))
                    TryX(y[k + 1], k + 1);
            }
            else if (f_min > (f + (n + K - nbSegments) * min_distance))
                TryX(v, k);

            // Quay
            
            visited[v] = false;
            load[k] -= d[v];
            f -= c[i][v];
            nbSegments -= 1;
        }
    }
}
// 4 +
void TryY(int k)
{
    for (int v = y[k - 1] + 1; v <= n - K + k; v++)
    {
        if (checkY(v, k))
        {
            y[k] = v;
            visited[v] = true;
            load[k] += d[v];
            f += c[0][v];
            nbSegments += 1;
            if (k == K)
                TryX(y[1], 1);
            else
                TryY(k + 1);
            // Quay lui
            visited[v] = false;
            load[k] -= d[v];
            f -= c[0][v];
            nbSegments -= 1;
        }
    }
}

void init()
{
    min_distance = 1e9;
    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        visited[i] = false;
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (min_distance > c[i][j] && i != j)
                min_distance = c[i][j];
        }

    nbSegments = 0;
    f = 0;
    f_min = 10e7;
}

int main()
{
    init();
    TryY(1);
    cout << f_min;
    return 0;
}