#include "bits/stdc++.h"
#include "unordered_map"
using namespace std;

int total; // tổng số tiền
int cnt = 1;
int K;
int f = 0;
int number_transactions;
unordered_map<string, int> idx; // vị trí của các account
unordered_map<string, int> total_money_transaction_from;
unordered_map<string, bool> visited;
map<pair<string, string>, bool> exists;
vector<string> ds[100000];
vector<string> list_sorted_accounts;

void init()
{
    string a, b, c, d;
    int money;
    pair<string, string> exs;
    while (1)
    {
        cin >> a;
        if (a == "#")
            break;
        number_transactions++;
        cin >> b >> money >> c >> d;
        total += money;
        exs.first = a;
        exs.second = b;

        // gán idx add account to list
        if (idx[a] == 0)
        {
            list_sorted_accounts.push_back(a);
            idx[a] = cnt++;
        }
        if (idx[b] == 0)
        {
            list_sorted_accounts.push_back(b);
            idx[b] = cnt++;
        }
        // tính tổng tiền
        total_money_transaction_from[a] += money;

        if (!exists[exs] && a != b)
        {
            ds[idx[a]].push_back(b);
            exists[exs] = true;
        }
    }
    cout << endl;
}

void Try(int k, string v, string ori)
{
    string a;

    for (int i = 0; i < ds[idx[v]].size(); i++)
    {
        a = ds[idx[v]][i];
        if (a != ori && visited[a] == false)
        {
            visited[a] = true;
            if (k == K)
            {
                pair<string, string> exs;
                exs.first = a;
                exs.second = ori;
                if (exists[exs])
                {
                    f = 1;
                }
            }
            else
                Try(k + 1, a, ori);
            visited[a] = false;
        }
    }
}

void solution()
{
    string a, b;
    do
    {
        cin >> a;
        if (a == "?number_transactions")
            cout << number_transactions << endl;
        else if (a == "?total_money_transaction")
            cout << total << endl;
        else if (a == "?list_sorted_accounts")
        {
            sort(list_sorted_accounts.begin(), list_sorted_accounts.end());
            for (int i = 0; i < list_sorted_accounts.size(); i++)
                cout << list_sorted_accounts[i] << " ";
            cout << endl;
        }
        else if (a == "?total_money_transaction_from")
        {
            cin >> b;
            cout << total_money_transaction_from[b] << endl;
        }
        else if (a == "?inspect_cycle")
        {
            cin >> b >> K;
            f = 0;
            Try(2, b, b);
            cout << f << endl;
        }
    } while (a != "#");
}

int main()
{
    init();
    solution();
    return 0;
}