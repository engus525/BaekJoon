#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll k, n;

void INPUT()
{
    IAMFAST
    cin >> k >> n;
}

void solution()
{
    if (n == 1) cout << -1;
    else if (k * n % (n - 1)) cout << k * n / (n - 1) + 1;
    else cout << k * n / (n - 1);
}

int main()
{
    INPUT();
    solution();
}