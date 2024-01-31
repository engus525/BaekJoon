#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a ,b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    cout << min(a / 2, b);
}

int main()
{
    INPUT();
    solution();
}