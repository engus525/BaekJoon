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
    for (int i = 1; i <= t; i++)
    {
        string str; cin >> str;
        cout << "String #" << i << '\n';
        for (auto s : str)
        {
            if (s == 'Z') cout << 'A';
            else cout << char(s + 1);
        }
        cout << "\n\n";
    }
}

int main()
{
    INPUT();
    solution();
}