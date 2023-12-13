#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c, d;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d;
}


void solution()
{
    cout << 56*a + 24*b + 14*c + 6*d;
}

int main()
{
    INPUT();
    solution();
}