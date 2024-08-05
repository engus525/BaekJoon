#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    int x = (a + b) / 2, y = (a - b) / 2;
    if (x + y == a && x - y == b && a >= b) cout << x << " " << y;
    else cout << - 1;
}

int main()
{
    INPUT();
    solution();
}