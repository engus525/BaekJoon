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
    cout << fixed; cout.precision(6);
    cout << 3.141592 * b * 2 + 2 * a;
}

int main()
{
    INPUT();
    solution();
}