#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, g, c, e;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> g >> c >> e;
        int mul;
        if (g == 1) mul = 1;
        else if (g == 2) mul = 3;
        else mul = 5;
        cout << max(0, mul * (e - c)) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}