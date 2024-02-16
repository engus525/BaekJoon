#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int cnt[10];

void INPUT()
{
    IAMFAST
    for (int i = 0; i < 5; i++)
    {
        int n; cin >> n;
        cnt[n]++;
    }
}

void solution()
{
    for (int i = 0; i < 10; i++)
        if (cnt[i] % 2)
        {
            cout << i;
            return;
        }
}

int main()
{
    INPUT();
    solution();
}