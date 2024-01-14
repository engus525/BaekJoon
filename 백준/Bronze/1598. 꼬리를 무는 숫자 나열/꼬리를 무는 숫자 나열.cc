#include <bits/stdc++.h>

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
    int x1 = (a - 1) / 4;
    int y1 = a % 4;
    if (y1 % 4 == 0) y1 = 4;
    int x2 = (b - 1) / 4;
    int y2 = b % 4;
    if (y2 % 4 == 0) y2 = 4;

    cout << abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    INPUT();
    solution();
}