#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, s, m;
int vol[51];
bool mem[51][1001];

void INPUT()
{
    IAMFAST
    cin >> n >> s >> m;
    for (int i = 1; i <= n; ++i) cin >> vol[i];
}

void solution()
{
    mem[0][s] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (j - vol[i] >= 0 && mem[i - 1][j - vol[i]])
                mem[i][j] = true;
            else if (j + vol[i] <= m && mem[i - 1][j + vol[i]])
                mem[i][j] = true;
        }
    }

    for (int i = m; i >= 0; i--)
    {
        if (mem[n][i])
        {
            cout << i;
            return;
        }
    }
    cout << -1;
}

int main()
{
    INPUT();
    solution();
}