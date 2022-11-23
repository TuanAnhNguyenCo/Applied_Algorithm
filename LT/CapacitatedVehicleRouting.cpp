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
int numberOfClientsVisited;
int max_value;
int number_of_zeros = 0;
int load_sum = 0;
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
    }
}

void TryX(int i, int k)
{

    for (int v = 0; v <= n; v++)
    {
        if (checkX(v, k))
        {
            visited[v] = true;
            load[k] += d[v];
            x[i] = v;
            f += c[i][v];
            nbSegments++;

            if (v == 0)
            {
                if (k == K)
                {
                    if (nbSegments == n + K)
                        solution();
                }
                // Số đoạn tương ứng vs K xe đang chạy sẽ là n + K
                // Nếu 1 xe thì n + 1 , 2 xe thì n + 2 bạn đọc có thể tự nháp giấy
                else if (f_min > (f + min_distance * (n + K - nbSegments)))
                    TryX(y[k + 1], k + 1);
            }
            else if (f_min > (f + min_distance * (n + K - nbSegments)))
                TryX(v, k);

            visited[v] = false;
            load[k] -= d[v];
            f -= c[i][v];
            nbSegments--;
        }
    }
}

void TryY(int k)
{

    for (int v = y[k - 1] + 1; v <= n + k - K; v++)
    {
        if (checkY(v, k))
        {
            visited[v] = true;
            load[k] += d[v];
            y[k] = v;
            f += c[0][v];
            nbSegments++;

            if (k == K)
                TryX(y[1], 1);
            else
                TryY(k + 1);
            // Quay lui

            visited[v] = false;
            load[k] -= d[v];
            f -= c[0][v];
            nbSegments--;
        }
    }
}

void init()
{
    min_distance = 1e9;
    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
    {

        scanf("%d", &d[i]);
        visited[i] = false;
        load_sum += d[i];
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
            if (min_distance > c[i][j] && i != j)
                min_distance = c[i][j];
        }
    nbSegments = 0;
    f = 0;
    max_value = -1e9;
    f_min = 10e7;
    numberOfClientsVisited = 0;
}

int main()
{
    init();
    // Duyệt K = K -> K = 1.
    // Tức là số xe hiện thời đang chạy đi từ K về 1
    while (K != 0)
    {
        // Kiểm tra nếu với K xe chạy mà không đáp ứng đủ thì dừng luôn
        if (K * Q < load_sum)
            break;
        TryY(1);
        f = 0;
        nbSegments = 0;
        // Giảm số xe đang chạy
        K--;
    }
    cout << f_min;
    return 0;
}
