#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double t, a, b, c, d, e;


void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    cout << fixed; cout.precision(2);
    while (t--)
    {
        cin >> a >> b >> c >> d >> e;
        cout << "$" << 350.34 * a + 230.90 * b + 190.55 * c + 125.30 * d + 180.90 * e << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}