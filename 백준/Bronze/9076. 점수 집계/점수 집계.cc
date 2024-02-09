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
        vector<int> v;
        for (int i = 0; i < 5; i++)
        {
            int num; cin >> num;
            v.emplace_back(num);
        }
        sort(v.begin(), v.end());

        if (v[3] - v[1] >= 4) cout << "KIN\n";
        else cout << accumulate(v.begin(), v.end(), -v[0]-v[4]) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}