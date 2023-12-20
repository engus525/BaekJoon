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
        int num[7];

        int sum = 0, minV = 101;
        for (int i = 0; i < 7; i++)
        {
            cin >> num[i];
            if (num[i] % 2 == 0)
            {
                sum += num[i];
                minV = min(minV, num[i]);
            }
        }

        cout << sum << " " << minV << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}