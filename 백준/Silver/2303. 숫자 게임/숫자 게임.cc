#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int value[1001][6];
int maxSum[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++)
            cin >> value[i][j];
}


void solution()
{
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 4; j++)
            for (int k = j + 1; k < 5; k++)
            {
                for (int num = 1; num <= n; num++)
                {
                    int rest = (value[num][i] + value[num][j] + value[num][k]) % 10;
                    //cout << rest << " ";
                    maxSum[num] = max(maxSum[num], rest);
                }
                //cout << '\n';
            }

    int maxV = maxSum[1], ans = 1;
    for (int i = 2; i <= n; i++)
        if (maxSum[i] >= maxV) maxV = maxSum[i], ans = i;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}