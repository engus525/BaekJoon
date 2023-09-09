#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
int taste[11][11];
vector<int> comb;
int ans = -1e9;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; ++j)
            cin >> taste[i][j];
}

void setAns()
{
    int score = 0;
    for (int i = 0; i < k - 1; ++i)
        for (int j = i + 1; j < k; ++j)
            score += taste[comb[i]][comb[j]];
    ans = max(ans, score);
}

void setComb(int depth, int start)
{
    if (depth == k)
    {
        setAns();
        return;
    }

    for (int i = start; i <= n; i++)
    {
        comb.emplace_back(i);
        setComb(depth + 1, i + 1);
        comb.pop_back();
    }
}

void solution()
{
    setComb(0, 1);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}