#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int A[200001];
int cnt[200001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> A[i];
}


void SOLVE()
{
    int left = 0, right = 0;
    int ans = 1;
    cnt[A[left]]++;

    while(right < n)
    {
        if(cnt[A[right]] <= k)
        {
            ans = max(ans,right-left+1);
            right++; cnt[A[right]]++;

            if(cnt[A[right]] > k)
            {
                while(cnt[A[right]] > k && left <= right)
                {
                    cnt[A[left]]--;
                    left++;
                }
                if(left == right)
                {
                    cnt[A[left]] = 0;
                    left++; right++;
                    cnt[A[left]] = 1;
                }
            }
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}