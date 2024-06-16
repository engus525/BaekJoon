#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c, d, t;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d >> t;
}

void solution()
{
    cout << a + 21 * max(0, t - 30) * b << " " << c + 21 * max(0, t - 45) * d;
}

int main()
{
    INPUT();
    solution();
}