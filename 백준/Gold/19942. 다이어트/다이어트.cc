#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, mp, mf, ms, mv;
int graph[16][5];
vector<int> comb, ans;
int minMoney = 2e9;

void INPUT()
{
    IAMFAST
    cin >> n >> mp >> mf >> ms >> mv;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++)
            cin >> graph[i][j];
}

bool isGood()
{
    int p = 0, f = 0, s = 0, v = 0, money = 0;
    for (auto c : comb)
    {
        p += graph[c][0];
        f += graph[c][1];
        s += graph[c][2];
        v += graph[c][3];
        money += graph[c][4];
    }
    //cout << "(p, f, s, v, money) : " << p << " " << f << " " << s << " " << v << " " << money << '\n';

    if (p >= mp && f >= mf && s >= ms && v >= mv && money < minMoney)
    {
        minMoney = money;
        return true;
    }
    else return false;
}

void setComb(int cnt, int start)
{
    if (cnt == n + 1) return;

    if (isGood())
    {
        ans = comb;
    }

    for (int i = start; i <= n; i++)
    {
        comb.emplace_back(i);
        setComb(cnt + 1, i + 1);
        comb.pop_back();
    }
}

void solution()
{
    setComb(0, 1);

    if (minMoney == 2e9)
    {
        cout << -1;
        return;
    }
    cout << minMoney << '\n';
    for (auto a : ans) cout << a << " ";
}

int main()
{
    INPUT();
    solution();
}