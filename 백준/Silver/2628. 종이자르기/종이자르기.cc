#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, k;
vector<int> a, b;

void INPUT()
{
    IAMFAST
    cin >> m >> n >> k;

    a.emplace_back(0);
    b.emplace_back(0);
    a.emplace_back(n);
    b.emplace_back(m);
    while (k--)
    {
        int d, i;
        cin >> d >> i;
        if (d == 0) a.emplace_back(i);
        else b.emplace_back(i);
    }
}


void solution()
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int maxA = 0, maxB = 0;
    for (int i = 1; i < a.size(); i++)
        if (maxA < a[i] - a[i - 1]) maxA = a[i] - a[i - 1];
    for (int i = 1; i < b.size(); i++)
        if (maxB < b[i] - b[i - 1]) maxB = b[i] - b[i - 1];

    cout << maxA * maxB;
}

int main()
{
    INPUT();
    solution();
}