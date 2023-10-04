#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n, w;
ll s[17];

void INPUT()
{
    IAMFAST
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> s[i];
}

void solution()
{
    ll coin = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] < s[i + 1]) coin += w / s[i], w -= (w / s[i]) * s[i];
        else if (s[i] > s[i + 1] || i == n) w += coin * s[i], coin = 0;
    }
    cout << w;
}

int main()
{
    INPUT();
    solution();
}