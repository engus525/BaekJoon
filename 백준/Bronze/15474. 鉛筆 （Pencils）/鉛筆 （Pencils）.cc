#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a, b, c, d;

void INPUT()
{
    IAMFAST
    cin >> n >> a >> b >> c >> d;
}

void solution()
{
    int aCnt = ceil(n / a), bCnt = ceil(n / c);
    if (n % a) aCnt++;
    if (n % c) bCnt++;
    
    cout << int(min(aCnt * b, bCnt * d));
}

int main()
{
    INPUT();
    solution();
}