#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
}

void solution()
{
    int maxV = max(max(a, b), c);
    cout << 3 * maxV - a - b - c;
}

int main()
{
    INPUT();
    solution();
}