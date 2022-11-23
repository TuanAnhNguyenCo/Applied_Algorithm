#include "bits/stdc++.h"
#include <unordered_map>
#define MAX 1000005
using namespace std;

int a[MAX];
// tốc độ truy vấn O(1)
unordered_map<int, int> b; // b[i] là số vàng đào được lớn nhất tại i
// tốc độ truy vấn O(logn)
map<pair<int, int>, int> maxOfSubSeq; // maxOfSubSeq[i,j] thì là max b trong đoạn i -> j
int n, L1, L2;                        // các thông số đầu vào

int Try2(int k);

void init()
{
    // đọc dữ liệu đầu vào
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}
// dùng cho chạy code trên máy mình
void init2()
{
    ifstream ifs("data.txt");
    ifs >> n;
    ifs >> L1;
    ifs >> L2;
    // Khai báo biến kiểu char để lưu ký tự đọc được

    //Đọc và in lần lượt các ký tự trong file
    for (int i = 1; i <= n; i++)
    {
        ifs >> a[i];
    }

    //Đóng file
    ifs.close();
}
// Lấy giá trị lớn nhất trong đoạn start -> end của b
int getMaxOfSubSeq(int start, int end)
{
    pair<int, int> c;
    c.first = start + 1;
    c.second = end + 1;
    // Lấy cái giá trị max ở đoạn trước đó(start+1,end+1) do nó được tính trước đó rồi
    int local_max = maxOfSubSeq[c];
    // Kiểm tra xem nếu thực sự có thì sẽ chạy do giá trị đầu tiên khi try thì chưa có max sub seq
    if (local_max != 0)
    {
        // (start,end) (start+1,end+1)
        // Kiểm tra nếu b[start] chưa có thì Try nhưng cx sẽ rất nhanh bỏi các giá trị b tại vị trí start + L1,start+L2
        // đã tính hết ở phía trước đó r
        if (b[start] == 0)
            b[start] = Try2(start);
        // hầu như thằng b[c.second] đã được tính hết r làm thế này cho chắc thôi
        if (b[c.second] == 0)
            b[c.second] = Try2(c.second);
        // Kiểm tra xem nếu giá trị max của sub seq mà ở vị trí b[c.second] thì ta k dùng được đoạn ý
        // bỏi vì ta k b max của c.first -> c.second là bn nên ta phải tính đoạn start -> end -> return 0;
        if (local_max == b[c.second])
        {
            return 0;
        }
        // Nếu max k phải thì ta chỉ cần so sánh với b[start] để tìm max thôi vì b[end] thuộc doạn ý rồi
        return max(local_max, b[start]);
    }

    return 0;
}

int Try2(int k)
{
    // nếu mà lơn hẳn hơn thì dừng và trả về dữ liệu thôi
    if (k + L1 > n)
        return a[k];
    // Nếu mà bằng hẳn thì ta sẽ trả về để tránh nó phải lặp vô ích tốn lệnh
    else if (k + L1 == n)
        return a[k] + a[k + L1];
    else
    {
        pair<int, int> c;
        c.first = k + L1;
        c.second = k + L2;
        // gọi ra giá trị max của đoạn c
        int local_max = getMaxOfSubSeq(k + L1, k + L2);
        // nếu không có thì ta phải tính thôi
        if (local_max == 0)
        {
            for (int i = k + L2; i >= k + L1; i--)
            {
                // lặp để tính
                if (i <= n)
                {
                    if (b[i] == 0)
                    {
                        b[i] = Try2(i);
                    }
                    local_max = max(local_max, b[i]);
                }
            }
        }
        // gắn max của đoạn này bằng local max
        maxOfSubSeq[c] = local_max;
        // local max là của đoạn i+ L1 -> i+L2 nhé nên phải + a[k] để ra được b[k]
        return local_max + a[k];
    }
}

int main()
{
    init();
    // init2();
    int local_max = 0;
    // duyệt từ n - L2 về thôi
    for (int i = n - L2; i >= 1; i--)
    {
        //gọi thôi
        b[i] = Try2(i);
        local_max = max(local_max, b[i]);
    }

    cout << local_max;

    return 0;
}
