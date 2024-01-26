#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int e = 0, o = 0;
    while (n--)
    {
        int v; cin >> v;
        if (v % 2) o++;
        else e++;
    }
    if (e > o) cout << "Happy";
    else cout << "Sad";
}

int main()
{
    INPUT();
    solution();
}