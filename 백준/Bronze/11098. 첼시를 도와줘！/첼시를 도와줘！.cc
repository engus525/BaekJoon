#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, p, value;
string name;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    while (n--)
    {
        int max = 0;
        string ans;

        cin >> p;
        while (p--)
        {
            cin >> value >> name;
            if (max < value) max = value, ans = name;
        }
        cout << ans << '\n';
    }
}


int main()
{
    INPUT();
    solution();
}