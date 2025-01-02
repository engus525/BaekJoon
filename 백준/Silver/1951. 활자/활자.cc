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

string n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    ll ans = 0;
    for (int i = 0; i < n.length(); i++)
    {
        string nine = "9";
        for (int j = 1; j <= i; j++) nine += "0";

        if (i == n.length() - 1)
        {
            ans += (stoll(n) - ll(pow(10, i)) + 1) * n.length();
        } else ans += (i + 1) * stoll(nine);

        ans %= 1234567;
    }
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}