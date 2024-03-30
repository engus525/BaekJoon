#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        set<int> S;
        int n; cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num; cin >> num;
            S.emplace(num);
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++)
        {
            int num; cin >> num;
            if (S.find(num) == S.end()) cout << 0;
            else cout << 1;
            cout << '\n';
        }
    }
}

int main()
{
    INPUT();
    solution();
}