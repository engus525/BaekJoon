#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n,u,l;

void INPUT()
{
    IAMFAST
    cin >> n >> u >> l;
}

void solution()
{
    if (n >= 1000 && (u >= 8000 || l >= 260)) cout << "Very Good";
    else if (n >= 1000) cout << "Good";
    else cout << "Bad";
}

int main()
{
    INPUT();
    solution();
}