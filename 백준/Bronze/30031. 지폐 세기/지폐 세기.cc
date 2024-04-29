#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int ans = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 136) ans += 1000;
        else if (a == 142) ans += 5000;
        else if (a == 148) ans += 10000;
        else if (a == 154) ans += 50000;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}