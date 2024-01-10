#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}


void solution()
{
    if (m <= 2) cout << "NEWBIE!";
    else if (m <= n) cout << "OLDBIE!";
    else cout << "TLE!";
}

int main()
{
    INPUT();
    solution();
}