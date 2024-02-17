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
        int n; cin >> n;
        for (int i = 0; i < n / 5; i++) cout << "++++ ";
        for (int i = 0; i < n % 5; i++) cout << "|";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}