#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
bool blackList[201][201];
bool visited[201];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        blackList[a][b] = blackList[b][a] = true;
    }
}


void solution()
{
    for (int i = 1; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            for (int k = j + 1; k <= n; k++)
            {
                if (blackList[i][j] || blackList[j][k] || blackList[i][k]) continue;
                ans++;
            }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}