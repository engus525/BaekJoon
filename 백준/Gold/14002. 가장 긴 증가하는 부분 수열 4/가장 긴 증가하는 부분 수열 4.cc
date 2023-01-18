#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int A[1001];
int dp[1001];
int lastIdx = 0;

int ans = 1;
vector<int> seq;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
}


void SOLVE()
{
    dp[0] = 1;

    for(int i = 1; i < n; i++)
    {
        int temp = 1;
        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i])
            {
                temp = max(temp,dp[j] + 1);
            }
        }
        dp[i] = temp;
        if(ans < dp[i])
        {
            ans = dp[i];
            lastIdx = i;
        }

    }

    int cnt = ans;
    for(int i = lastIdx; i >= 0; i--)
    {
        if(dp[i] == cnt)
        {
            seq.push_back(A[i]);
            cnt--;
        }
    }

    cout << ans << '\n';
    for(int i = ans - 1; i >= 0; i--)
        cout << seq[i] << " ";
}

int main()
{
    INPUT();
    SOLVE();
}