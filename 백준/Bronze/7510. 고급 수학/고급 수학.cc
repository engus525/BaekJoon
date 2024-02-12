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
    for (int i = 1; i <= n; i++)
    {
        vector<double> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());

        cout << "Scenario #" << i << ":" << '\n';
        if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) cout << "yes\n\n";
        else cout << "no\n\n";
    }
}

int main()
{
    INPUT();
    solution();
}