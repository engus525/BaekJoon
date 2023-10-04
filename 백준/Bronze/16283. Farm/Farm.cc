#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, n, w;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> n >> w;
}

void solution()
{
    int ansX = -1, cnt = 0;
    for (int x = 1; x < n; x++)
        if ((a - b) * x == w - b * n) ansX = x, cnt++;
    (cnt == 1) ? cout << ansX << " " << n - ansX : cout << -1;
}

int main()
{
    INPUT();
    solution();
}