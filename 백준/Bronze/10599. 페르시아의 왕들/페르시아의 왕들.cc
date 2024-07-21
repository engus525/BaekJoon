#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c, d;

void INPUT()
{
    IAMFAST
}

void solution()
{
    while (cin >> a >> b >> c >> d)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        cout << c - b << " " << d - a << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}