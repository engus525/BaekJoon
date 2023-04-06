#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}

void SOLVE()
{
    int ans = 0;
    for(int i = 1,cnt = 1; i <= n; i++)
    {
        if(n%i == 0)
        {
            if(cnt == k)
            {
                ans = i;
                break;
            }
            cnt++;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}