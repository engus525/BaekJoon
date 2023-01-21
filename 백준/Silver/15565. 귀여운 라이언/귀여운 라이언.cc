#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int doll[1000001];
int cnt = 0;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> doll[i];
}


void SOLVE()
{
    int ans = 2e9;
    int left = 0,right = 0;
    if(doll[left] == 1) cnt = 1;

    while(right < n)
    {
        if(cnt == k)
        {
            ans = min(ans,right-left+1);

            if(doll[left] == 1) cnt--;
            left++;
        }
        else if(cnt < k)
        {
            right++;
            if(doll[right] == 1) cnt++;
        }
    }
    if(ans==2e9) cout << -1;
    else cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}