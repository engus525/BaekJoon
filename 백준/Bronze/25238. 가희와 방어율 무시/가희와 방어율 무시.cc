#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    double criteria = a - a * b / 100;
    (criteria < 100) ? cout << 1 : cout << 0;
}

int main()
{
    INPUT();
    solution();
}