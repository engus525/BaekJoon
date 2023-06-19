#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long ll;
ll n;
vector<ll> v(6);
vector<int> comb;
bool visited[6];
ll ans = 2e18;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < 6; i++) cin >> v[i];
}

void setAns()
{
    ans = min(ans,((5 * n * n - 8 * n + 4) * v[comb[0]]
             + (8 * n - 8) * v[comb[1]]
             + 4 * v[comb[2]]));
}

void setComb(int depth)
{
    if(n == 1)
    {
        ans = accumulate(v.begin(), v.end(), 0)
              - *max_element(v.begin(), v.end());
        return;
    }
    if(depth == 3)
    {
        if(visited[0] && visited[5]) return;
        if(visited[1] && visited[4]) return;
        if(visited[2] && visited[3]) return;
        setAns();
        return;
    }

    for(int i = 0; i < 6; i++)
    {
        if(visited[i]) continue;

        visited[i] = true;
        comb.push_back(i);
        setComb(depth+1);
        visited[i] = false;
        comb.pop_back();
    }
}

void SOLVE()
{
    setComb(0);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}