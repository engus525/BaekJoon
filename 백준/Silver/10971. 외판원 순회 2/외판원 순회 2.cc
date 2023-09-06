#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int dist[11][11];
vector<int> comb;
bool visited[11];
int ans = 2e9;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dist[i][j];
}

void setAns()
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (dist[comb[i]][comb[i + 1]] == 0) return;
        temp += dist[comb[i]][comb[i + 1]];
    }

    if (dist[comb[n - 1]][comb[0]])
    {
        temp += dist[comb[n - 1]][comb[0]];
        ans = min(ans, temp);
    }
}


void setComb(int depth)
{
    if (depth == n)
    {
        setAns();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        comb.emplace_back(i);
        setComb(depth + 1);
        visited[i] = false;
        comb.pop_back();
    }
}

void solution()
{
    setComb(0);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}
