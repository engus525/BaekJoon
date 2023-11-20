#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int k;

void INPUT()
{
    IAMFAST
    cin >> k;
}


void solution()
{
    int ansSize;
    for (int i = 1; ; i *= 2)
        if (i >= k)
        {
            ansSize = i;
            break;
        }

    int ansCnt = 0;
    for (int i = ansSize; ; i /= 2)
    {
        if (i <= k) k -= i;
        if (k == 0) break;

        ansCnt++;
    }

    cout << ansSize << " " << ansCnt;
}

int main()
{
    INPUT();
    solution();
}