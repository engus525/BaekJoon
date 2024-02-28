#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, x;
int limit[101];

void INPUT()
{
    IAMFAST
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> limit[i];
}

void solution()
{
    int idx = 0;
    while (true)
    {
        if (limit[idx] < x)
        {
            cout << idx + 1;
            return;
        }
        x++;
        idx++;
        idx %= n;
    }
}

int main()
{
    INPUT();
    solution();
}