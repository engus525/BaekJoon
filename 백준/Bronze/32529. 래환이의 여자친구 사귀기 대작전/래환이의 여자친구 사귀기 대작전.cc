#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<int> v;
int ps = 0;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.emplace_back(val);
    }
}


void solution()
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ps += v[i];
        if (ps >= m)
        {
            ans = i + 1;
            break;
        }
    }
    if (ans) cout << ans;
    else cout << -1;
}

int main()
{
    INPUT();
    solution();
}