#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double a;

void INPUT()
{
    IAMFAST
    cin >> a;
}

void solution()
{
    double ans = 0.01 * a + 25;
    if (ans < 100) ans = 100;
    else if (ans > 2000) ans = 2000;
    cout << fixed; cout.precision(2);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}