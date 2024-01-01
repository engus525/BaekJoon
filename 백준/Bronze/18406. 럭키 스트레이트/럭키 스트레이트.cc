#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int l = 0;
    for (int i = 0; i < n.length() / 2; i++) l += n[i] - '0';
    int r = 0;
    for (int i = n.length() / 2; i < n.length(); i++) r += n[i] - '0';

    if (l == r) cout << "LUCKY";
    else cout << "READY";
}

int main()
{
    INPUT();
    solution();
}