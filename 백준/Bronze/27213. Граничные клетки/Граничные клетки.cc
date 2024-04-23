#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll m, n;

void INPUT()
{
    IAMFAST
    cin >> m >> n;
}

void solution()
{
    if (m == 1 || n == 1) cout << max(m, n);
    else cout << 2 * n + 2 * (m - 2);
}

int main()
{
    INPUT();
    solution();
}