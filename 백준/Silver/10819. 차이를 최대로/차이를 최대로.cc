#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<int> v(9);
vector<int> comb;
bool visited[9];
int ans = -2e9;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
}

void setAns()
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
        temp += abs(comb[i] - comb[i + 1]);
    ans = max(ans, temp);
}

void setComb(int depth)
{
    if (depth == n)
    {
        setAns();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        comb.emplace_back(v[i]);
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
