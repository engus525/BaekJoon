#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

ll n;
vector<int> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll rank; cin >> rank;
        v.emplace_back(rank);
    }
}

void solution()
{
    sort(v.begin(), v.end());

    ll ans = 0;
    for(int rank = 1; rank <= n; rank++)
        ans += abs(rank - v[rank - 1]);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}