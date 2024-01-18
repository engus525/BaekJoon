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
    while (n--)
    {
        string a, b;
        cin >> a >> b;

        cout << "Distances: ";
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] <= b[i]) cout << b[i] - a[i];
            else cout << b[i] + 26 - a[i];
            cout << " ";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}