#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int l, r;

void INPUT()
{
    IAMFAST
    cin >> l >> r;
}


void solution()
{
    string a = to_string(l);
    string b = to_string(r);

    int ans = 0;


    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '8' && b[i] == '8') ans++;
        else if (a[i] != b[i]) break;
    }

    if (a.length() != b.length()) cout << 0;
    else cout << ans;
}

int main()
{
    INPUT();
    solution();
}