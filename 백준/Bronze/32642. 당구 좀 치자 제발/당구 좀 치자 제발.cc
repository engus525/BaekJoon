#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    ll ans = 0;
    ll angry = 0;
    for (int i = 0; i < t; i++)
    {
        int rain; cin >> rain;
        if (rain) angry++;
        else angry--;

        ans += angry;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}