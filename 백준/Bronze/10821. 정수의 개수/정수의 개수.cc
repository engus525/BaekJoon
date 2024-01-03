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
    int ans = 1;
    for (auto c : n)
        if (c == ',') ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}