#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c, d, e;

void INPUT()
{
    IAMFAST
}

void solution()
{
    cin >> a >> b >> c >> d >> e;
    cout << a * 6 + b * 3 + c * 2 + d + e * 2 << " ";
    cin >> a >> b >> c >> d >> e;
    cout << a * 6 + b * 3 + c * 2 + d + e * 2;
}

int main()
{
    INPUT();
    solution();
}